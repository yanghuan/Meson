using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Reflection;
using System.Text;
using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Resolver;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.CSharp.Syntax.PatternMatching;
using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal sealed class MethodTransform : IAstVisitor<SyntaxNode> {
    private enum MemberAccessKind {
      None,
      Pointer,
      Base,
    }

    private readonly TypeDefinitionTransform typeDefinition_;
    private readonly ClassSyntax classNode_;
    private readonly Stack<IMethod> methodSymbols_ = new Stack<IMethod>();
    private readonly Stack<MethodDefinitionSyntax> functions_ = new Stack<MethodDefinitionSyntax>();
    private readonly Stack<BlockSyntax> blocks_ = new Stack<BlockSyntax>();

    public MethodTransform(TypeDefinitionTransform typeDefinition, IMethod methodSymbol, ClassSyntax classNode) {
      typeDefinition_ = typeDefinition;
      classNode_ = classNode;
      Visit(methodSymbol);
    }

    private SyntaxGenerator Generator => typeDefinition_.Generator;
    private CompilationUnitSyntax CompilationUnit => typeDefinition_.CompilationUnit.CompilationUnit;
    private AssemblyTransform AssemblyTransform => typeDefinition_.AssemblyTransform;
    private IMethod MethodSymbol => methodSymbols_.Peek();
    private BlockSyntax Block => blocks_.Peek();
    private MethodDefinitionSyntax Function => functions_.Peek();
    private IdentifierSyntax GetMemberName(ISymbol symbol) => Generator.GetMemberName(symbol);
    private ExpressionSyntax GetTypeName(IType type, ISymbol symbol = null, bool isInDelaring = true) => typeDefinition_.GetTypeName(type, isInDelaring ? MethodSymbol.DeclaringTypeDefinition : null, symbol);

    private IdentifierSyntax GetTempIdentifier() {
      int index = Function.TotalTempCount++;
      string name = SyntaxNode.TempIdentifiers.GetOrDefault(index);
      if (name == null) {
        throw new CompilationErrorException($"Your code is startling,{SyntaxNode.TempIdentifiers.Length} temporary variables is not enough");
      }
      ++Block.TempCount;
      return name;
    }

    private void PushFunction(MethodDefinitionSyntax function) {
      functions_.Push(function);
    }

    private void PopFunction() {
      var fucntion = functions_.Pop();
      Contract.Assert(fucntion.TotalTempCount == 0);
    }

    public void PushBlock(BlockSyntax block) {
      blocks_.Push(block);
    }

    public void PopBlock() {
      var block = blocks_.Pop();
      if (block.TempCount > 0) {
        Contract.Assert(Function.TotalTempCount >= block.TempCount);
        Function.TotalTempCount -= block.TempCount;
      }
    }

    private void Visit(IMethod methodSymbol) {
      if (methodSymbol.HasBody) {
        methodSymbols_.Push(methodSymbol);
        MethodDefinitionSyntax node;
        var declaration = Generator.GetMethodDeclaration(methodSymbol);
        if (declaration != null) {
          node = declaration.Accept<MethodDefinitionSyntax>(this);
        } else {
          node = BuildMethodDeclaration(null);
        }
        methodSymbols_.Pop();
        if (node != null) {
          if (node.IsInline) {
            CompilationUnit.AddInlineMethodDefinition(node);
          } else {
            CompilationUnit.AddSrcStatement(node);
            CompilationUnit.AddSrcStatement(BlankLinesStatement.One);
            if (methodSymbol.IsMainEntryPoint()) {
              InsetMainFuntion(methodSymbol, node);
            }
          }
        }
      }
    }

    private void InsetMainFuntion(IMethod methodSymbol, MethodDefinitionSyntax method) {
      var typeDefinition = methodSymbol.DeclaringTypeDefinition;
      IdentifierSyntax ns = typeDefinition.GetFullNamespace();
      var typeName = GetTypeName(typeDefinition, typeDefinition, false);
      if (typeDefinition.IsRefType()) {
        typeName = typeName.WithIn();
      }
      var node = new MethodDefinitionSyntax("main", new ParameterSyntax[] {
        new ParameterSyntax("int", "argc"),
        new ParameterSyntax("char*", "argv[]"),
      }, "int");
      var invation = new InvationExpressionSyntax("rt::init", "argc", "argv", ns.TwoColon(typeName).TwoColon(method.Name).Address());
      node.AddStatement(invation.Return());
      CompilationUnit.SrcStatements.Add(node);
    }

    public SyntaxNode VisitAnonymousMethodExpression(AnonymousMethodExpression anonymousMethodExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitAnonymousTypeCreateExpression(AnonymousTypeCreateExpression anonymousTypeCreateExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitArrayCreateExpression(ArrayCreateExpression arrayCreateExpression) {
      var type = arrayCreateExpression.GetResolveResult().Type;
      var typeName = GetTypeName(type);
      var size = arrayCreateExpression.Arguments.First().AcceptExpression(this);
      return IdentifierSyntax.NewArray.Generic(typeName).Invation(size);
    }

    public SyntaxNode VisitArrayInitializerExpression(ArrayInitializerExpression arrayInitializerExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitAsExpression(AsExpression asExpression) {
      var type = asExpression.Type.AcceptExpression(this);
      var expression = asExpression.Expression.AcceptExpression(this);
      return IdentifierSyntax.As.Generic(type).Invation(expression);
    }

    private static readonly string[] assignmentOperators_ = new string[] {
      "=", "+=", "-=", "*=", "/=",
      "%=", "<<=", ">>=", "&=", "|=",
      "^="
    };

    private static string GetAssignmentOperator(AssignmentOperatorType operatorToken) {
      int index = (int)operatorToken;
      return assignmentOperators_[index];
    }

    private InvationExpressionSyntax GetPropertyInvationExpression(ExpressionSyntax propertyExpression) {
      if (propertyExpression is MemberAccessExpressionSyntax memberAccess) {
        return GetPropertyInvationExpression(memberAccess.Name);
      }
      return propertyExpression as InvationExpressionSyntax;
    }

    public SyntaxNode VisitAssignmentExpression(AssignmentExpression assignmentExpression) {
      var left = assignmentExpression.Left.AcceptExpression(this);
      var right = assignmentExpression.Right.AcceptExpression(this);
      var leftSymbol = assignmentExpression.Left.GetSymbol();
      if (leftSymbol != null && leftSymbol.SymbolKind == SymbolKind.Property) {
        var invation = GetPropertyInvationExpression(left);
        if (invation != null) {
          invation.Arguments.Add(right);
          return left;
        }
      }
      var operatorToken = GetAssignmentOperator(assignmentExpression.Operator);
      return left.Binary(operatorToken, right);
    }

    public SyntaxNode VisitBaseReferenceExpression(BaseReferenceExpression baseReferenceExpression) {
      var baseType = baseReferenceExpression.GetResolveResult().Type;
      return GetTypeName(baseType).WithIn();
    }

    private static readonly string[] binaryOperatorTokens_ = new string[] {
      null, "&", "|", "&&", "||",
      "^", ">", ">=", "==", "!=",
      "<", "<=", "+", "-", "*",
      "/", "%", "<<", ">>", null,
      null,
    };

    public static string GetBinaryOperatorToken(BinaryOperatorType type) {
      string token = binaryOperatorTokens_[(int)type];
      if (token == null) {
        throw new NotImplementedException();
      }
      return token;
    }

    public SyntaxNode VisitBinaryOperatorExpression(BinaryOperatorExpression binaryOperatorExpression) {
      var left = binaryOperatorExpression.Left.AcceptExpression(this);
      var right = binaryOperatorExpression.Right.AcceptExpression(this);
      if (binaryOperatorExpression.Operator == BinaryOperatorType.NullCoalescing) {
        var temp = GetTempIdentifier();
        var local = new VariableDeclarationStatementSyntax(new RefExpressionSyntax(IdentifierSyntax.Auto), temp, left);
        Block.Add(local);
        if (binaryOperatorExpression.Right is ThrowExpression) {
          Block.Add(new IfElseStatementSyntax(temp.Binary(Tokens.EqualsEquals, IdentifierSyntax.Nullptr), right));
          return temp;
        } else {
          return new ConditionalExpressionSyntax(temp.Binary(Tokens.NotEquals, IdentifierSyntax.Nullptr), temp, right);
        }
      }
      string operatorToken = GetBinaryOperatorToken(binaryOperatorExpression.Operator);
      return left.Binary(operatorToken, right);
    }

    public SyntaxNode VisitCastExpression(CastExpression castExpression) {
      var targetType = castExpression.Type.AcceptExpression(this);
      var expression = castExpression.Expression.AcceptExpression(this);
      return new CastExpressionSyntax(expression, targetType);
    }

    public SyntaxNode VisitCheckedExpression(CheckedExpression checkedExpression) {
      return checkedExpression.Expression.AcceptExpression(this);
    }

    public SyntaxNode VisitConditionalExpression(ConditionalExpression conditionalExpression) {
      var condition = conditionalExpression.Condition.AcceptExpression(this);
      var trueExpression = conditionalExpression.TrueExpression.AcceptExpression(this);
      var falseExpression = conditionalExpression.FalseExpression.AcceptExpression(this);
      return new ConditionalExpressionSyntax(condition, trueExpression, falseExpression);
    }

    public SyntaxNode VisitDefaultValueExpression(DefaultValueExpression defaultValueExpression) {
      var type = (IType)defaultValueExpression.Type.GetSymbol();
      if (type == null) {
        type = defaultValueExpression.GetResolveResult().Type;
      }
      if (type.IsReferenceType == true) {
        return IdentifierSyntax.Nullptr;
      }
      return GetTypeName(type).Invation();
    }

    public SyntaxNode VisitDirectionExpression(DirectionExpression directionExpression) {
      return directionExpression.Expression.AcceptExpression(this);
    }

    private static bool IsGetIdentifier(IdentifierExpression identifierExpression) {
      return true;
    }

    public SyntaxNode VisitIdentifierExpression(IdentifierExpression identifierExpression) {
      var symbol = identifierExpression.GetSymbol();
      if (symbol != null) {
        switch (symbol.SymbolKind) {
          case SymbolKind.Property: {
              var property = (IProperty)symbol;
              if (!property.IsPropertyField()) {
                IMethod method;
                if (property.Getter != null) {
                  if (property.Setter == null) {
                    method = property.Getter;
                  } else {
                    method = IsGetIdentifier(identifierExpression) ? property.Getter : property.Setter;
                  }
                } else {
                  if (property.Setter != null) {
                    method = property.Setter;
                  } else {
                    method = IsGetIdentifier(identifierExpression) ? property.Getter : property.Setter;
                  }
                }
                return GetMemberName(method).Invation();
              }
              break;
            }
        }
      }

      var identifier = identifierExpression.IdentifierToken.AcceptExpression(this);
      if (identifierExpression.TypeArguments.Count > 0) {
        identifier = new GenericIdentifierSyntax(identifier, identifierExpression.TypeArguments.Select(i => i.AcceptExpression(this)));
      }
      return identifier;
    }

    public SyntaxNode VisitIndexerExpression(IndexerExpression indexerExpression) {
      var target = indexerExpression.Target.AcceptExpression(this);
      var arguments = indexerExpression.Arguments.Select(i => i.AcceptExpression(this));
      return new IndexerExpressionSyntax(target, arguments);
    }

    public SyntaxNode VisitInterpolatedStringExpression(InterpolatedStringExpression interpolatedStringExpression) {
      var sb = new StringBuilder();
      List<ExpressionSyntax> expressions = new List<ExpressionSyntax>();
      foreach (var content in interpolatedStringExpression.Content) {
        if (content is InterpolatedStringText) {
          var identifier = content.Accept<ValueTextIdentifierSyntax>(this);
          sb.Append(identifier.ValueText);
        } else {
          var interpolation = (Interpolation)content;
          if (string.IsNullOrEmpty(interpolation.Suffix)) {
            sb.AppendFormat("{{{0}}}", expressions.Count);
          } else {
            sb.AppendFormat("{{{0}:{1}}}", expressions.Count, interpolation.Suffix);
          }
          var expression = interpolation.Expression.AcceptExpression(this);
          expressions.Add(expression);
        }
      }
      var stringTypeName = GetTypeName(Generator.StringTypeDefinition);
      return stringTypeName.WithIn().TwoColon("Format").Invation(new ExpressionSyntax[] { new StringLiteralExpressionSyntax(sb.ToString()) }.Concat(expressions));
    }

    private void CheckParameterType(IMethod symbol, IParameter parameter, int index, IType type, ref ExpressionSyntax expression) {
      if (type.Kind == TypeKind.Array && parameter.Type.Kind == TypeKind.Array && parameter.Type.FullName != type.FullName) {
        bool exists = symbol.DeclaringTypeDefinition.Methods.Any(i => i != symbol
          && i.Name == symbol.Name
          && i.Parameters.Count == symbol.Parameters.Count
          && type.Is(i.Parameters[index].Type.Original()));
        if (exists) {
          goto Cast;
        }
      }

      if (type.Kind == TypeKind.Null) {
        var original = (IMethod)symbol.MemberDefinition;
        var originalParameterType = original.Parameters[index].Type;
        if (originalParameterType.Kind == TypeKind.TypeParameter && original.TypeParameters.Any(i => i.Name == originalParameterType.Name)) {
          goto Cast;
        }
      }
      return;
    
     Cast:
      var targetType = GetTypeName(parameter.Type, parameter);
      expression = expression.CastTo(targetType);
    }

    private List<ExpressionSyntax> BuildArguments(IMethod symbol, ICollection<Expression> argumentExpressions) {
      Contract.Assert(symbol != null);
      List<ExpressionSyntax> arguments = new List<ExpressionSyntax>();
      int i = 0;
      foreach (var argument in argumentExpressions) {
        var resolveResult = argument.GetResolveResult();
        var parameter = symbol.Parameters[i];
        if (parameter.IsParams) {
          bool isMatchParamArray = parameter.Type.Kind == TypeKind.Array && i == symbol.Parameters.Count - 1 && i == argumentExpressions.Count - 1;
          if (!isMatchParamArray) {
            var typeName = GetTypeName(parameter.Type);
            var expressions = argumentExpressions.Skip(i).Select(i => i.AcceptExpression(this)).ToArray();
            var invation = IdentifierSyntax.NewArray.Generic(typeName).Invation(expressions.Length.ToString());
            invation.Arguments.AddRange(expressions);
            arguments.Add(invation);
            break;
          }
        }
        var expression = argument.AcceptExpression(this);
        CheckParameterType(symbol, parameter, i, resolveResult.Type, ref expression);
        arguments.Add(expression);
        ++i;
      }
      return arguments;
    }

    private List<ExpressionSyntax> BuildInvocationArguments(IMethod symbol, InvocationExpression invocationExpression) {
      return BuildArguments(symbol, invocationExpression.Arguments);
    }

    public SyntaxNode VisitInvocationExpression(InvocationExpression invocationExpression) {
      var symbol = (IMethod)invocationExpression.GetSymbol();
      var arguments = BuildInvocationArguments(symbol, invocationExpression);
      if (invocationExpression.Target is MemberReferenceExpression memberReference) {
        if (symbol.IsExtensionMethod) {
          var memberReferenceTarget = memberReference.Target.AcceptExpression(this);
          arguments.Insert(0, memberReferenceTarget);
          return GetTypeName(symbol.DeclaringTypeDefinition).TwoColon(GetMemberName(symbol)).Invation(arguments);
        }
      }
      var target = invocationExpression.Target.AcceptExpression(this);
      CheckNoVisibleMethod(symbol, invocationExpression, ref target, arguments);
      return target.Invation(arguments);
    }

    private static bool IsParameterTypeSame(IReadOnlyList<IParameter> parameters, AstNodeCollection<Expression> arguments) {
      if (parameters.Count == arguments.Count) {
        int i = 0;
        foreach (var argument in arguments) {
          var parameter = parameters[i];
          var resolveResult = argument.GetResolveResult();
          if (resolveResult.Type.FullName != parameter.Type.FullName) {
            return false;
          }
          ++i;
        }
        return true;
      }
      return false;
    }

    private void CheckNoVisibleMethod(IMethod symbol, InvocationExpression invocationExpression, ref ExpressionSyntax target, List<ExpressionSyntax> arguments) {
      if (symbol.IsLocalFunction) {
        if (symbol.IsStatic && target is GenericIdentifierSyntax generic) {
          generic.Name = generic.Name.Dot("operator()");
        }
        return;
      }

      var methods = symbol.DeclaringTypeDefinition.Methods.Where(i => i != symbol.MemberDefinition && i.Name == symbol.Name && i.Accessibility != Accessibility.Public);
      var method = methods.FirstOrDefault(i => IsParameterTypeSame(i.Parameters, invocationExpression.Arguments));
      if (method != null) {
        if (symbol.TypeParameters.Count == 0) {
          int i = 0;
          foreach (var argument in invocationExpression.Arguments) {
            var parameter = symbol.Parameters[i];
            var resolveResult = argument.GetResolveResult();
            if (resolveResult.Type.FullName != parameter.Type.FullName) {
              var argumentExpression = arguments[i];
              var parameterTypeExpression = GetTypeName(parameter.Type);
              arguments[i] = argumentExpression.CastTo(parameterTypeExpression);
            }
            ++i;
          }
        } else {
          if (target is MemberAccessExpressionSyntax memberAccess && !(memberAccess.Name is GenericIdentifierSyntax)) {
            var typeArguments = symbol.TypeArguments.Select(i => GetTypeName(i));
            memberAccess.Name = memberAccess.Name.Generic(typeArguments);
          }
        }
      }
    }

    public SyntaxNode VisitIsExpression(IsExpression isExpression) {
      var type = isExpression.Type.AcceptExpression(this);
      var expression = isExpression.Expression.AcceptExpression(this);
      return IdentifierSyntax.Is.Generic(type).Invation(expression);
    }

    public SyntaxNode VisitLambdaExpression(LambdaExpression lambdaExpression) {
      throw new NotImplementedException();
    }

    private MemberAccessExpressionSyntax BuildMemberAccessExpression(ExpressionSyntax target, ISymbol symbol, AstNode node, IReadOnlyCollection<AstType> typeArguments, MemberAccessKind kind = MemberAccessKind.None) {
      switch (symbol.SymbolKind) {
        case SymbolKind.Field:
        case SymbolKind.Property:
        case SymbolKind.Constructor:
        case SymbolKind.Method: {
            var member = (IEntity)symbol;
            ExpressionSyntax name;
            switch (symbol.SymbolKind) {
              case SymbolKind.Property: {
                  var property = (IProperty)symbol;
                  bool isGetter = (property.Getter != null && property.Setter == null) || !(node.Parent is AssignmentExpression);
                  member = isGetter ? property.Getter : property.Setter;
                  Contract.Assert(member != null);
                  name = GetMemberName(member);
                  name = name.Invation();
                  break;
                }
              case SymbolKind.Method: {
                  name = GetMemberName(member);
                  if (typeArguments.Count > 0) {
                    var types = typeArguments.Select(i => i.AcceptExpression(this));
                    name = name.Generic(types);
                  }
                  break;
                }
              default: {
                  name = GetMemberName(member);
                  break;
                }
            }
            if (kind == MemberAccessKind.Base) {
              return target.TwoColon(name);
            }
            if (member.IsStatic) {
              if (member.DeclaringTypeDefinition.IsRefType()) {
                target = target.WithIn();
              }
              return target.TwoColon(name);
            }
            return (kind == MemberAccessKind.Pointer || member.DeclaringTypeDefinition.IsRefType()) ? target.Arrow(name) : target.Dot(name);
          }
      }
      throw new NotImplementedException();
    }

    public SyntaxNode VisitMemberReferenceExpression(MemberReferenceExpression memberReferenceExpression) {
      var target = memberReferenceExpression.Target.Accept<ExpressionSyntax>(this);
      var symbol = memberReferenceExpression.GetSymbol() ?? memberReferenceExpression.Parent.GetSymbol();
      if (symbol == null) {
        if (memberReferenceExpression.Target is TypeReferenceExpression typeReferenceExpression) {
          var typeSymbol = (ITypeDefinition)typeReferenceExpression.Type.GetSymbol();
          symbol = typeSymbol.Members.First(i => i.Name == memberReferenceExpression.MemberName);
        }
      }
      MemberAccessKind kind;
      if (memberReferenceExpression.Target is ThisReferenceExpression) {
        kind = MemberAccessKind.Pointer;
        target = IdentifierSyntax.This;
      } else if (memberReferenceExpression.Target is BaseReferenceExpression) {
        kind = MemberAccessKind.Base;
      } else {
        kind = MemberAccessKind.None;
      }
      return BuildMemberAccessExpression(target, symbol, memberReferenceExpression, memberReferenceExpression.TypeArguments, kind);
    }

    public SyntaxNode VisitNamedArgumentExpression(NamedArgumentExpression namedArgumentExpression) {
      return namedArgumentExpression.Expression.AcceptExpression(this);
    }

    public SyntaxNode VisitNamedExpression(NamedExpression namedExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitNullReferenceExpression(NullReferenceExpression nullReferenceExpression) {
      return IdentifierSyntax.Nullptr;
    }

    private ExpressionSyntax BuildObjectCreateExpression(ObjectCreateExpression objectCreateExpression, out List<ExpressionSyntax> arguments, out IMethod method) {
      var typeName = objectCreateExpression.Type.AcceptExpression(this);
      var symbol = objectCreateExpression.GetSymbol();
      if (symbol != null) {
        if (symbol is IMethod m) {
          method = m;
          arguments = BuildArguments(method, objectCreateExpression.Arguments);
        } else if (symbol is ITypeDefinition typeDefinition) {
          Contract.Assert(typeDefinition.Kind == TypeKind.Struct);
          method = typeDefinition.Methods.First();
          arguments = BuildArguments(method, objectCreateExpression.Arguments);
        } else {
          throw new NotImplementedException();
        }
      } else {
        var typeDefinition = (ITypeDefinition)objectCreateExpression.Type.GetSymbol();
        Contract.Assert(typeDefinition.Kind == TypeKind.Delegate);
        method = typeDefinition.GetMethods().First();
        Contract.Assert(objectCreateExpression.Arguments.Count == 1);
        var rs = (MethodGroupResolveResult)objectCreateExpression.Arguments.First().GetResolveResult();
        var argument = (IMethod)rs.MethodsGroupedByDeclaringType.First().First();
        var name = GetMemberName(argument);
        arguments = new List<ExpressionSyntax>() { name.Address() };
      }
      return typeName;
    }

    private ExpressionSyntax BuildObjectCreateExpression(ObjectCreateExpression objectCreateExpression, out List<ExpressionSyntax> arguments) {
      return BuildObjectCreateExpression(objectCreateExpression, out arguments, out _);
    }

    public SyntaxNode VisitObjectCreateExpression(ObjectCreateExpression objectCreateExpression) {
      var typeName = BuildObjectCreateExpression(objectCreateExpression, out var arguments, out IMethod method);
      if (method.DeclaringType.Kind == TypeKind.Struct) {
        return typeName.Invation(arguments);
      }
      return IdentifierSyntax.NewObj.Generic(typeName).Invation(arguments);
    }

    public SyntaxNode VisitOutVarDeclarationExpression(OutVarDeclarationExpression outVarDeclarationExpression) {
      var typeName = outVarDeclarationExpression.Type.AcceptExpression(this);
      var variable = outVarDeclarationExpression.Variable.Accept<VariableInitializerSyntax>(this);
      Block.Add(new VariableDeclarationStatementSyntax(typeName, variable.Name));
      return variable.Name;
    }

    public SyntaxNode VisitParenthesizedExpression(ParenthesizedExpression parenthesizedExpression) {
      var expression = parenthesizedExpression.Expression.AcceptExpression(this);
      if (parenthesizedExpression.Expression is IsExpression) {
        return expression;
      }
      return expression.Parenthesized();
    }

    private ISymbol GetPointerTargetMember(PointerReferenceExpression pointerReferenceExpression) {
      var target = pointerReferenceExpression.Target.UnParenthesized();
      var targetType = target.GetResolveResult().Type;
      Contract.Assert(targetType.Kind == TypeKind.Pointer);
      var definition = targetType.GetReferenceTypeDefinition();
      var symbol = definition.Members.Single(i => i.Name == pointerReferenceExpression.MemberName);
      return symbol;
    }

    public SyntaxNode VisitPointerReferenceExpression(PointerReferenceExpression pointerReferenceExpression) {
      var target = pointerReferenceExpression.Target.AcceptExpression(this);
      var symbol = pointerReferenceExpression.GetSymbol() ?? GetPointerTargetMember(pointerReferenceExpression);
      return BuildMemberAccessExpression(target, symbol, pointerReferenceExpression, pointerReferenceExpression.TypeArguments, MemberAccessKind.Pointer);
    }

    public SyntaxNode VisitPrimitiveExpression(PrimitiveExpression primitiveExpression) {
      return Utils.GetPrimitiveExpression(primitiveExpression.Value);
    }

    public SyntaxNode VisitSizeOfExpression(SizeOfExpression sizeOfExpression) {
      var type = sizeOfExpression.Type.AcceptExpression(this);
      return IdentifierSyntax.Sizeof.Invation(type);
    }

    public SyntaxNode VisitStackAllocExpression(StackAllocExpression stackAllocExpression) {
      var type = stackAllocExpression.Type.AcceptExpression(this);
      var count = stackAllocExpression.CountExpression.AcceptExpression(this);
      var temp = GetTempIdentifier();
      var newName = new ExpressionIdentifierSyntax(new CodeTemplateExpressionSyntax(temp, "[", count, "]"));
      var variableDeclaration = new VariableDeclarationStatementSyntax(type, newName, "{}");
      Block.Add(variableDeclaration);
      return temp;
    }

    public SyntaxNode VisitThisReferenceExpression(ThisReferenceExpression thisReferenceExpression) {
      var type = thisReferenceExpression.GetResolveResult().Type;
      if (type.IsRefType()) {
        var typeName = GetTypeName(type);
        return IdentifierSyntax.This.CastTo(typeName);
      }
      return new IndirectionExpressionSyntax(IdentifierSyntax.This);
    }

    public SyntaxNode VisitThrowExpression(ThrowExpression throwExpression) {
      var expression = throwExpression.Expression.AcceptExpression(this);
      return IdentifierSyntax.Throw.Invation(expression);
    }

    public SyntaxNode VisitTupleExpression(TupleExpression tupleExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitTypeOfExpression(TypeOfExpression typeOfExpression) {
      var typeName = typeOfExpression.Type.AcceptExpression(this);
      return IdentifierSyntax.Typeof.Generic(typeName).Invation();
    }

    public SyntaxNode VisitTypeReferenceExpression(TypeReferenceExpression typeReferenceExpression) {
      return typeReferenceExpression.Type.AcceptVisitor(this);
    }

    private static readonly string[] unaryOperatorToknes_ = new string[] {
      null, "!", "~", "-", "+",
      "++", "--", "++", "--", "*",
      "&", null, null, null, null, 
      string.Empty, null,
    };

    public SyntaxNode VisitUnaryOperatorExpression(UnaryOperatorExpression unaryOperatorExpression) {
      var expression = unaryOperatorExpression.Expression.AcceptExpression(this);
      if (unaryOperatorExpression.Operator == UnaryOperatorType.NullConditionalRewrap) {
        return expression;
      }

      if (unaryOperatorExpression.Operator == UnaryOperatorType.NullConditional) {
        var temp = GetTempIdentifier();
        Block.Add(new VariableDeclarationStatementSyntax(new RefExpressionSyntax(IdentifierSyntax.Auto), temp, expression));
        return new ConditionalExpressionSyntax(temp.Binary(Tokens.EqualsEquals, IdentifierSyntax.Nullptr), IdentifierSyntax.Nullptr, temp);
      }

      string operatorToken = unaryOperatorToknes_[(int)unaryOperatorExpression.Operator];
      if (operatorToken == null) {
        throw new NotImplementedException();
      }
      bool isPosOperator = unaryOperatorExpression.Operator == UnaryOperatorType.PostIncrement || unaryOperatorExpression.Operator == UnaryOperatorType.PostDecrement;
      if (isPosOperator) {
        return new PostfixUnaryExpression(expression, operatorToken);
      }
      return new PrefixUnaryExpressionSyntax(operatorToken, expression);
    }

    public SyntaxNode VisitUncheckedExpression(UncheckedExpression uncheckedExpression) {
      return uncheckedExpression.Expression.AcceptExpression(this);
    }

    public SyntaxNode VisitUndocumentedExpression(UndocumentedExpression undocumentedExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitQueryExpression(QueryExpression queryExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitQueryContinuationClause(QueryContinuationClause queryContinuationClause) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitQueryFromClause(QueryFromClause queryFromClause) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitQueryLetClause(QueryLetClause queryLetClause) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitQueryWhereClause(QueryWhereClause queryWhereClause) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitQueryJoinClause(QueryJoinClause queryJoinClause) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitQueryOrderClause(QueryOrderClause queryOrderClause) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitQueryOrdering(QueryOrdering queryOrdering) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitQuerySelectClause(QuerySelectClause querySelectClause) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitQueryGroupClause(QueryGroupClause queryGroupClause) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitAttribute(ICSharpCode.Decompiler.CSharp.Syntax.Attribute attribute) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitAttributeSection(AttributeSection attributeSection) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitDelegateDeclaration(DelegateDeclaration delegateDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitNamespaceDeclaration(NamespaceDeclaration namespaceDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitTypeDeclaration(TypeDeclaration typeDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitUsingAliasDeclaration(UsingAliasDeclaration usingAliasDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitUsingDeclaration(UsingDeclaration usingDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitExternAliasDeclaration(ExternAliasDeclaration externAliasDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitBlockStatement(BlockStatement blockStatement) {
      BlockSyntax node = new BlockSyntax();
      PushBlock(node);
      foreach (var statement in blockStatement.Statements) {
        try {
          var s = statement.AcceptStatement(this);
          node.Statements.Add(s);
        } catch (NotImplementedException) {
          break;
        }
      }
      PopBlock();
      return node;
    }

    public SyntaxNode VisitBreakStatement(BreakStatement breakStatement) {
      return BreakStatementSyntax.Default;
    }

    public SyntaxNode VisitCheckedStatement(CheckedStatement checkedStatement) {
      var block = checkedStatement.Body.Accept<BlockSyntax>(this);
      return new BlockStatementSyntax(block.Statements);
    }

    public SyntaxNode VisitContinueStatement(ContinueStatement continueStatement) {
      return ContinueStatementSyntax.Default;
    }

    public SyntaxNode VisitDoWhileStatement(DoWhileStatement doWhileStatement) {
      var embeddedStatement = doWhileStatement.EmbeddedStatement.AcceptStatement(this);
      var condition = doWhileStatement.Condition.AcceptExpression(this);
      return new DoWhileStatementSyntax(embeddedStatement, condition);
    }

    public SyntaxNode VisitEmptyStatement(EmptyStatement emptyStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitExpressionStatement(ExpressionStatement expressionStatement) {
      var expression = expressionStatement.Expression.Accept<ExpressionSyntax>(this);
      return (StatementSyntax)expression;
    }

    public SyntaxNode VisitFixedStatement(FixedStatement fixedStatement) {
      var type = fixedStatement.Type.AcceptExpression(this);
      var variables = fixedStatement.Variables.Select(i => i.Accept<VariableInitializerSyntax>(this));
      var declaration = new VariableDeclarationStatementSyntax(type, variables);
      var embeddedStatement = fixedStatement.EmbeddedStatement.AcceptStatement(this);
      var block = new BlockStatementSyntax();
      block.Add(declaration);
      if (embeddedStatement is BlockSyntax blockSyntax) {
        block.AddRange(blockSyntax.Statements);
      } else {
        block.Add(embeddedStatement);
      }
      return block;
    }

    public SyntaxNode VisitForeachStatement(ForeachStatement foreachStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitForStatement(ForStatement forStatement) {
      var initializers = forStatement.Initializers.Select(i => i.AcceptStatement(this));
      var condition = forStatement.Condition.AcceptExpression(this);
      var iterators = forStatement.Iterators.Select(i => i.AcceptStatement(this));
      var embeddedStatement = forStatement.EmbeddedStatement.AcceptStatement(this);
      return new ForStatementSyntax(initializers, condition, iterators, embeddedStatement);
    }

    public SyntaxNode VisitGotoCaseStatement(GotoCaseStatement gotoCaseStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitGotoDefaultStatement(GotoDefaultStatement gotoDefaultStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitGotoStatement(GotoStatement gotoStatement) {
      return new GotoStatementSyntax(gotoStatement.Label);
    }

    public SyntaxNode VisitIfElseStatement(IfElseStatement ifElseStatement) {
      var condition = ifElseStatement.Condition.AcceptExpression(this);
      var trueStatement = ifElseStatement.TrueStatement.AcceptStatement(this);
      return new IfElseStatementSyntax(condition, trueStatement) {
        FalseStatement = ifElseStatement.FalseStatement?.AcceptStatement(this)
      };
    }

    public SyntaxNode VisitLabelStatement(LabelStatement labelStatement) {
      return new LabelStatementSyntax(labelStatement.Label);
    }

    public SyntaxNode VisitLockStatement(LockStatement lockStatement) {
      var expression = lockStatement.Expression.AcceptExpression(this);
      var statement = lockStatement.EmbeddedStatement.AcceptStatement(this);
      BlockStatementSyntax block = new BlockStatementSyntax();
      block.Add(IdentifierSyntax.Lock.Invation(expression));
      if (statement is BlockSyntax blockStatement) {
        block.AddRange(blockStatement.Statements);
      } else {
        block.Add(statement);
      }
      return block;
    }

    public SyntaxNode VisitReturnStatement(ReturnStatement returnStatement) {
      if (returnStatement.Expression.IsNull()) {
        return new ReturnStatementSyntax();
      }
      return returnStatement.Expression.AcceptExpression(this).Return();
    }

    public SyntaxNode VisitSwitchStatement(SwitchStatement switchStatement) {
      var expression = switchStatement.Expression.AcceptExpression(this);
      var type = switchStatement.Expression.GetResolveResult().Type;
      if (type.Kind != TypeKind.Enum) {
        expression = expression.Dot(IdentifierSyntax.Get).Invation();
      }
      var switchSections = switchStatement.SwitchSections.Select(i => i.Accept<SwitchSectionSyntax>(this));
      return new SwitchStatementSyntax(expression, switchSections);
    }

    public SyntaxNode VisitSwitchSection(SwitchSection switchSection) {
      var caseLabels = switchSection.CaseLabels.Select(i => i.Accept<CaseLabelSyntax>(this));
      var statements = switchSection.Statements.Select(i => i.AcceptStatement(this));
      return new SwitchSectionSyntax(caseLabels, statements);
    }

    public SyntaxNode VisitCaseLabel(CaseLabel caseLabel) {
      var expression = caseLabel.Expression.IsNull ? null : caseLabel.Expression.AcceptExpression(this);
      return new CaseLabelSyntax(expression);
    }

    public SyntaxNode VisitThrowStatement(ThrowStatement throwStatement) {
      if (throwStatement.Expression is ObjectCreateExpression objectCreateExpression && objectCreateExpression.Initializer.IsNull) {
        var typeName = BuildObjectCreateExpression(objectCreateExpression, out var arguments);
        return (StatementSyntax)IdentifierSyntax.Throw.Generic(typeName).Invation(arguments);
      }

      var expression = throwStatement.Expression.AcceptExpression(this);
      return (StatementSyntax)IdentifierSyntax.Throw.Invation(expression);
    }

    public SyntaxNode VisitTryCatchStatement(TryCatchStatement tryCatchStatement) {
      var tryBlock = tryCatchStatement.TryBlock.Accept<BlockSyntax>(this);
      var catchClauses = tryCatchStatement.CatchClauses.Select(i => i.Accept<CatchClauseSyntax>(this));
      var finallyBlock = !tryCatchStatement.FinallyBlock.IsNull ? tryCatchStatement.FinallyBlock.Accept<BlockSyntax>(this) : null;
      return new TryStatementSyntax(tryBlock, catchClauses, finallyBlock);
    }

    public SyntaxNode VisitCatchClause(CatchClause catchClause) {
      var type = !catchClause.Type.IsNull ? catchClause.Type.AcceptExpression(this) : IdentifierSyntax.VariableArguments;
      var name = catchClause.VariableNameToken.Accept<IdentifierSyntax>(this);
      return new CatchClauseSyntax(type, name);
    }

    public SyntaxNode VisitUncheckedStatement(UncheckedStatement uncheckedStatement) {
       var block = uncheckedStatement.Body.Accept<BlockSyntax>(this);
      return new BlockStatementSyntax(block.Statements);
    }

    public SyntaxNode VisitUnsafeStatement(UnsafeStatement unsafeStatement) {
      var block = unsafeStatement.Body.Accept<BlockSyntax>(this);
      return new BlockStatementSyntax(block.Statements);
    }

    public SyntaxNode VisitUsingStatement(UsingStatement usingStatement) {
      BlockStatementSyntax blockStatement = new BlockStatementSyntax();
      var resourceAcquisition = usingStatement.ResourceAcquisition.Accept<SyntaxNode>(this);
      if (resourceAcquisition is VariableDeclarationStatementSyntax variableDeclaration) {
        blockStatement.Add(variableDeclaration);
        blockStatement.Add(IdentifierSyntax.Using.Invation(variableDeclaration.Variables.Select(i => i.Name)));
      } else {
        blockStatement.Add((ExpressionSyntax)resourceAcquisition);
      }
      var embeddedStatement = usingStatement.EmbeddedStatement.AcceptStatement(this);
      if (embeddedStatement is BlockSyntax blockSyntax) {
        blockStatement.AddRange(blockSyntax.Statements);
      } else {
        blockStatement.Add(embeddedStatement);
      }
      return blockStatement;
    }

    public SyntaxNode VisitVariableDeclarationStatement(VariableDeclarationStatement variableDeclarationStatement) {
      var type = variableDeclarationStatement.Type.AcceptExpression(this);
      var variables = variableDeclarationStatement.Variables.Select(i => i.Accept<VariableInitializerSyntax>(this));
      return new VariableDeclarationStatementSyntax(type, variables);
    }

    private ParameterSyntax GetParameterSyntax(IParameter parameter) {
      var type = GetTypeName(parameter.Type);
      var name = GetMemberName(parameter);
      return new ParameterSyntax(type, name);
    }

    public SyntaxNode VisitLocalFunctionDeclarationStatement(LocalFunctionDeclarationStatement localFunctionDeclarationStatement) {
      var method = (IMethod)localFunctionDeclarationStatement.GetSymbol();
      Contract.Assert(method != null);
      var name = method.Name;
      var parameters = method.Parameters.Select(GetParameterSyntax);
      var retuenType = GetTypeName(method.ReturnType);
      var body = localFunctionDeclarationStatement.Declaration.Body.Accept<BlockSyntax>(this);
      var lambdaExpressionSyntax = new LambdaExpressionSyntax(parameters, retuenType, body) { TypeParameters = method.GetTemplateSyntax()?.Arguments };
      var declaration = new VariableDeclarationStatementSyntax(IdentifierSyntax.Auto, name, lambdaExpressionSyntax);
      if (method.IsStatic) {
        Function.Body.Statements.Insert(0, declaration);
        return StatementSyntax.Empty;
      }
      return declaration;
    }

    public SyntaxNode VisitWhileStatement(WhileStatement whileStatement) {
      var condition = whileStatement.Condition.AcceptExpression(this);
      var embeddedStatement = whileStatement.EmbeddedStatement.AcceptStatement(this);
      return new WhileStatementSyntax(condition, embeddedStatement);
    }

    public SyntaxNode VisitYieldBreakStatement(YieldBreakStatement yieldBreakStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitYieldReturnStatement(YieldReturnStatement yieldReturnStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitAccessor(Accessor accessor) {
      return BuildMethodDeclaration(accessor.Body);
    }

    public SyntaxNode VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration) {
      return BuildMethodDeclaration(constructorDeclaration.Body);
    }

    public SyntaxNode VisitConstructorInitializer(ConstructorInitializer constructorInitializer) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitDestructorDeclaration(DestructorDeclaration destructorDeclaration) {
      return BuildMethodDeclaration(destructorDeclaration.Body);
    }

    public SyntaxNode VisitEnumMemberDeclaration(EnumMemberDeclaration enumMemberDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitEventDeclaration(EventDeclaration eventDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitCustomEventDeclaration(CustomEventDeclaration customEventDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitFieldDeclaration(FieldDeclaration fieldDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitIndexerDeclaration(IndexerDeclaration indexerDeclaration) {
      throw new NotImplementedException();
    }

    private void CheckParameterTypeConflict(ref ExpressionSyntax type, IParameter parameter, ITypeDefinition typeDefinition) {
      var members = typeDefinition_.GetTypeMembersFromCache(typeDefinition);
      foreach (var m in members) {
        if (parameter.Type.Name == m.GetMemberName()) {
          type = type.WithFullName(parameter.Type, typeDefinition);
          break;
        }
      }
    }

    private ParameterSyntax GetParameterSyntax(IParameter parameter, IMethod method) {
      var typeDefinition = method.DeclaringTypeDefinition;
      ExpressionSyntax type = typeDefinition_.GetNestedCycleRefTypeName(parameter);
      if (type != null) {
        if (parameter.Type.Kind == TypeKind.Pointer) {
          type = new PointerIdentifierSyntax(type);
        }
      } else {
        type = GetTypeName(parameter.Type, parameter);
        CheckParameterTypeConflict(ref type, parameter, typeDefinition);
      }
      var name = GetMemberName(parameter);
      return new ParameterSyntax(type, name);
    }

    private ExpressionSyntax GetDeclaringType(ITypeDefinition type) {
      ExpressionSyntax name = type.IsRefType() ? type.Name.Wrap() : type.Name;
      if (Generator.IsVoidGenericType(type)) {
        name = name.Generic();
      }
      var declaringType = AssemblyTransform.GetDeclaringType(type);
      if (declaringType != null) {
        var outTypeName = GetDeclaringType(declaringType.GetDefinition());
        return outTypeName.TwoColon(name);
      }
      return name;
    }

    private void InsertDefaultReturnValue(MethodDefinitionSyntax node, IMethod method, ExpressionSyntax returnType) {
      switch (method.ReturnType.Kind) {
        case TypeKind.Pointer:
        case TypeKind.Class:
        case TypeKind.Interface:
        case TypeKind.Delegate: {
            node.AddStatement(IdentifierSyntax.Nullptr.Return());
            break;
          }
        case TypeKind.ByReference: {
            var refIdentifier = (RefExpressionSyntax)returnType;
            node.AddStatement(refIdentifier.Expression.Invation().Return());
            break;
          }
        case TypeKind.Enum: {
            var field = method.ReturnType.GetDefinition().Fields.Last();
            var name = GetMemberName(field);
            node.AddStatement(returnType.TwoColon(name).Return());
            break;
          }
        case TypeKind.Void: {
            break;
          }
        default: {
            node.AddStatement(returnType.Invation().Return());
            break;
          }
      }
    }

    private static bool IsStructDefaultParameterExists(IMethod method) {
      return method.Parameters.Any(i => i.HasConstantValueInSignature && i.GetConstantValue() == null && i.Type.Kind == TypeKind.Struct);
    }

    private MethodDefinitionSyntax BuildMethodDeclaration(BlockStatement body) {
      var method = MethodSymbol;
      var parameters = method.Parameters.Select(i => GetParameterSyntax(i, method)).ToList();
      var declaringType = GetDeclaringType(method.DeclaringTypeDefinition);
      bool isCtor = method.IsCtor();
      IdentifierSyntax name;
      ExpressionSyntax returnType;
      if (isCtor) {
        name = classNode_.Name;
        returnType = null;
      } else {
        name = GetMemberName(MethodSymbol);
        returnType = GetTypeName(method.ReturnType, method, false);
        typeDefinition_.CheckOperatorParameters(method, parameters, returnType);
      }
      MethodDefinitionSyntax node = new MethodDefinitionSyntax(name, parameters, returnType) {
        DeclaringType = declaringType,
        Body = new BlockSyntax(),
      };
      if (IsStructDefaultParameterExists(method)) {
        node.Template = TemplateSyntax.Empty;
      }
      PushFunction(node);
      if (body != null) {
        var block = body.Accept<BlockSyntax>(this);
        node.AddStatements(block.Statements);
      } else if (method.AccessorOwner is IProperty property) {
        if (property.IsPropertyField()) {
          node.IsInline = true;
          var fieldName = typeDefinition_.GetPropertyFieldName(method.DeclaringTypeDefinition, property);
          if (method.AccessorKind == MethodSemanticsAttributes.Getter) {
            node.Body.Add(new ReturnStatementSyntax(fieldName));
          } else {
            node.Body.Add(new BinaryExpressionSyntax(fieldName, Tokens.Equals, IdentifierSyntax.Value));
          }
        } else {
          InsertDefaultReturnValue(node, method, returnType);
        }
      }
      PopFunction();
      return node;
    }

    public SyntaxNode VisitMethodDeclaration(MethodDeclaration methodDeclaration) {
      return BuildMethodDeclaration(methodDeclaration.Body);
    }

    public SyntaxNode VisitOperatorDeclaration(OperatorDeclaration operatorDeclaration) {
      return BuildMethodDeclaration(operatorDeclaration.Body);
    }

    public SyntaxNode VisitParameterDeclaration(ParameterDeclaration parameterDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitPropertyDeclaration(PropertyDeclaration propertyDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitVariableInitializer(VariableInitializer variableInitializer) {
      var name = variableInitializer.NameToken.Accept<IdentifierSyntax>(this);
      var initializer = variableInitializer.Initializer.AcceptExpression(this);
      return new VariableInitializerSyntax(name, initializer);
    }

    public SyntaxNode VisitFixedFieldDeclaration(FixedFieldDeclaration fixedFieldDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitFixedVariableInitializer(FixedVariableInitializer fixedVariableInitializer) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitSyntaxTree(SyntaxTree syntaxTree) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitSimpleType(SimpleType simpleType) {
      var type = simpleType.GetResolveResult().Type;
      return GetTypeName(type);
    }

    public SyntaxNode VisitMemberType(MemberType memberType) {
      var type = (IType)memberType.GetSymbol();
      return GetTypeName(type);
    }

    public SyntaxNode VisitTupleType(TupleAstType tupleType) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitTupleTypeElement(TupleTypeElement tupleTypeElement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitComposedType(ComposedType composedType) {
      var type = composedType.GetResolveResult().Type;
      return GetTypeName(type);
    }

    public SyntaxNode VisitArraySpecifier(ArraySpecifier arraySpecifier) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitPrimitiveType(PrimitiveType primitiveType) {
      var type = primitiveType.GetResolveResult().Type;
      return GetTypeName(type);
    }

    public SyntaxNode VisitComment(Comment comment) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitPreProcessorDirective(PreProcessorDirective preProcessorDirective) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitDocumentationReference(DocumentationReference documentationReference) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitTypeParameterDeclaration(TypeParameterDeclaration typeParameterDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitConstraint(Constraint constraint) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitCSharpTokenNode(CSharpTokenNode cSharpTokenNode) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitIdentifier(Identifier identifier) {
      return (IdentifierSyntax)identifier.Name;
    }

    public SyntaxNode VisitInterpolation(Interpolation interpolation) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitInterpolatedStringText(InterpolatedStringText interpolatedStringText) {
      return (IdentifierSyntax)interpolatedStringText.Text;
    }

    public SyntaxNode VisitNullNode(AstNode nullNode) {
      return null;
    }

    public SyntaxNode VisitErrorNode(AstNode errorNode) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitPatternPlaceholder(AstNode placeholder, Pattern pattern) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitFunctionPointerType(FunctionPointerType functionPointerType) {
      throw new System.NotImplementedException();
    }
  }
}
