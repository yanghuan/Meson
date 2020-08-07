using System;
using System.Collections.Generic;
using System.Diagnostics.Contracts;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;

using ICSharpCode.Decompiler.CSharp;
using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.CSharp.Syntax.PatternMatching;
using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal sealed class MethodTransform : IAstVisitor<SyntaxNode> {
    private static readonly HashSet<string> exportFunctions_ = new HashSet<string>() {
      "Test.Program.Main",
      "System.Console.WriteLine",
    };

    private static readonly HashSet<string> exportTypes_ = new HashSet<string>() {
      "System.Int32",
      "System.Array"
    };

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
        if (IsMethodExport(methodSymbol)) {
          var methodDeclaration = Generator.GetMethodDeclaration(methodSymbol);
          node = methodDeclaration?.Accept<MethodDefinitionSyntax>(this);
        } else {
          node = (MethodDefinitionSyntax)VisitMethodDeclaration(null);
        }
        methodSymbols_.Pop();
        if (node != null) {
          CompilationUnit.AddSrcStatement(node);
          CompilationUnit.AddSrcStatement(BlankLinesStatement.One);
          if (methodSymbol.IsMainEntryPoint()) {
            InsetMainFuntion(methodSymbol, node);
          }
        }
      }
    }

    private bool IsMethodExport(IMethod method) {
      if (exportFunctions_.Contains(method.FullName)) {
        return true;
      }
      if (exportTypes_.Contains(method.DeclaringType.FullName)) {
        return true;
      }
      return false;
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

    private static string GetAssignmentOperator(AssignmentOperatorType operatorToken) {
      switch (operatorToken) {
        case AssignmentOperatorType.Assign:
          return Tokens.Equals;

        case AssignmentOperatorType.Add:
          return Tokens.PlusEquals;

        case AssignmentOperatorType.Subtract:
          return Tokens.SubEquals;
      }
      throw new NotImplementedException();
    }

    public SyntaxNode VisitAssignmentExpression(AssignmentExpression assignmentExpression) {
      var left = assignmentExpression.Left.AcceptExpression(this);
      var operatorToken = GetAssignmentOperator(assignmentExpression.Operator);
      var right = assignmentExpression.Right.AcceptExpression(this);
      return left.Binary(operatorToken, right);
    }

    public SyntaxNode VisitBaseReferenceExpression(BaseReferenceExpression baseReferenceExpression) {
      throw new NotImplementedException();
    }

    public static string GetBinaryOperatorToken(BinaryOperatorType type) {
      switch (type) {
        case BinaryOperatorType.Equality:
          return Tokens.EqualsEquals;

        case BinaryOperatorType.InEquality:
          return Tokens.NotEquals;

        case BinaryOperatorType.LessThan:
          return Tokens.Less;

        case BinaryOperatorType.LessThanOrEqual:
          return Tokens.LessEquals;

        case BinaryOperatorType.GreaterThan:
          return Tokens.Greater;

        case BinaryOperatorType.GreaterThanOrEqual:
          return Tokens.GreaterEquals;

        case BinaryOperatorType.ConditionalAnd:
          return Tokens.LogicAnd;

        case BinaryOperatorType.ConditionalOr:
          return Tokens.LogicOr;

        case BinaryOperatorType.Add:
          return Tokens.Plus;

        case BinaryOperatorType.Subtract:
          return Tokens.Sub;

        case BinaryOperatorType.Multiply:
          return Tokens.Asterisk;

        case BinaryOperatorType.Divide:
          return Tokens.Div;

        case BinaryOperatorType.Modulus:
          return Tokens.Mod;

        case BinaryOperatorType.ShiftRight:
          return Tokens.GreaterGreater;

        case BinaryOperatorType.ShiftLeft:
          return Tokens.LessLess;

        default:
          throw new NotImplementedException();
      }
    }

    public SyntaxNode VisitBinaryOperatorExpression(BinaryOperatorExpression binaryOperatorExpression) {
      var left = binaryOperatorExpression.Left.AcceptExpression(this);
      string operatorToken = GetBinaryOperatorToken(binaryOperatorExpression.Operator);
      var right = binaryOperatorExpression.Right.AcceptExpression(this);
      return left.Binary(operatorToken, right);
    }

    public SyntaxNode VisitCastExpression(CastExpression castExpression) {
      var targetType = castExpression.Type.AcceptExpression(this);
      var expression = castExpression.Expression.AcceptExpression(this);
      return new CastExpressionSyntax(expression, targetType);
    }

    public SyntaxNode VisitCheckedExpression(CheckedExpression checkedExpression) {
      throw new NotImplementedException();
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

    public SyntaxNode VisitIdentifierExpression(IdentifierExpression identifierExpression) {
      var symbol = identifierExpression.GetSymbol();
      if (symbol != null) {
        switch (symbol.SymbolKind) {
          case SymbolKind.Property: {
              var property = (IProperty)symbol;
              if (!property.IsPropertyField()) {
                return GetMemberName(property.Getter).Invation();
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
      throw new NotImplementedException();
    }

    private void CheckArrayConflict(IMethod symbol, IParameter parameter, int index, IType type, ref ExpressionSyntax expression) {
      if (type.Kind == TypeKind.Array && parameter.Type.Kind == TypeKind.Array && parameter.Type.FullName != type.FullName) {
        bool exists = symbol.DeclaringTypeDefinition.Methods.Any(i => i != symbol
          && i.Name == symbol.Name
          && i.Parameters.Count == symbol.Parameters.Count
          && type.Is(i.Parameters[index].Type.Original()));
        if (exists) {
          var targetType = GetTypeName(parameter.Type, parameter);
          expression = expression.CastTo(targetType);
        }
      }
    }

    private List<ExpressionSyntax> BuildArguments(IMethod symbol, ICollection<Expression> argumentExpressions) {
      List<ExpressionSyntax> arguments = new List<ExpressionSyntax>();
      int i = 0;
      foreach (var argument in argumentExpressions) {
        var parameter = symbol.Parameters[i];
        var resolveResult = argument.GetResolveResult();
        var expression = argument.AcceptExpression(this);
        CheckArrayConflict(symbol, parameter, i, resolveResult.Type, ref expression);
        if (argument is NamedArgumentExpression namedArgument) {
          string name = namedArgument.Name;
          int index = symbol.Parameters.IndexOf(i => i.Name == name);
          if (index == -1) {
            throw new InvalidOperationException();
          }
          arguments.AddAt(index, expression);
        } else {
          arguments.Add(expression);
        }
        ++i;
      }

      i = 0;
      foreach (var argument in arguments) {
        if (argument == null) {
          var defaultValue = GetDefaultParameterValue(symbol.Parameters[i]);
          arguments[i] = defaultValue;
        }
        ++i;
      }
      return arguments;
    }

    private ExpressionSyntax GetDefaultParameterValue(IParameter parameter) {
      Contract.Assert(parameter.HasConstantValueInSignature);
      var constValue = parameter.GetConstantValue();
      ExpressionSyntax defaultValue;
      if (constValue == null) {
        defaultValue = IdentifierSyntax.Nullptr;
      } else {
        defaultValue = Utils.GetPrimitiveExpression(constValue);
      }
      return defaultValue;
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

    private MemberAccessExpressionSyntax BuildMemberAccessExpression(ExpressionSyntax target, ISymbol symbol, AstNode node, IReadOnlyCollection<AstType> typeArguments, bool isPointer = false) {
      switch (symbol.SymbolKind) {
        case SymbolKind.Field:
        case SymbolKind.Property:
        case SymbolKind.Method: {
            var member = (IEntity)symbol;
            ExpressionSyntax name;
            switch (symbol.SymbolKind) {
              case SymbolKind.Property: {
                  var property = (IProperty)symbol;
                  bool isGetter = !(node.Parent is AssignmentExpression);
                  member = isGetter ? property.Getter : property.Setter;
                  name = GetMemberName(member);
                  if (isGetter) {
                    name = name.Invation();
                  }
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
            if (member.IsStatic) {
              if (member.DeclaringTypeDefinition.IsRefType()) {
                target = target.WithIn();
              }
              return target.TwoColon(name);
            } else {
              return (isPointer || member.DeclaringTypeDefinition.IsRefType()) ? target.Arrow(name) : target.Dot(name);
            }
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
      return BuildMemberAccessExpression(target, symbol, memberReferenceExpression, memberReferenceExpression.TypeArguments);
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

    private ExpressionSyntax BuildObjectCreateExpression(ObjectCreateExpression objectCreateExpression, out List<ExpressionSyntax> arguments) {
      var method = (IMethod)objectCreateExpression.GetSymbol();
      var typeName = objectCreateExpression.Type.AcceptExpression(this);
      arguments = BuildArguments(method, objectCreateExpression.Arguments);
      return typeName;
    }

    public SyntaxNode VisitObjectCreateExpression(ObjectCreateExpression objectCreateExpression) {
      var typeName = BuildObjectCreateExpression(objectCreateExpression, out var arguments);
      return IdentifierSyntax.NewObj.Generic(typeName).Invation(arguments);
    }

    public SyntaxNode VisitOutVarDeclarationExpression(OutVarDeclarationExpression outVarDeclarationExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitParenthesizedExpression(ParenthesizedExpression parenthesizedExpression) {
      var expression = parenthesizedExpression.Expression.AcceptExpression(this);
      if (parenthesizedExpression.Expression is IsExpression) {
        return expression;
      }
      return expression.Parenthesized();
    }

    public SyntaxNode VisitPointerReferenceExpression(PointerReferenceExpression pointerReferenceExpression) {
      var target = pointerReferenceExpression.Target.AcceptExpression(this);
      var symbol = pointerReferenceExpression.GetSymbol();
      return BuildMemberAccessExpression(target, symbol, pointerReferenceExpression, pointerReferenceExpression.TypeArguments, true);
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitTypeReferenceExpression(TypeReferenceExpression typeReferenceExpression) {
      return typeReferenceExpression.Type.AcceptVisitor(this);
    }

    private static string GetUnaryOperator(UnaryOperatorType type) {
      switch (type) {
        case UnaryOperatorType.BitNot:
          return Tokens.Tilde;

        case UnaryOperatorType.AddressOf:
          return Tokens.Ampersand;

        case UnaryOperatorType.Not:
          return Tokens.Exclamation;

        case UnaryOperatorType.Increment:
        case UnaryOperatorType.PostIncrement:
          return Tokens.PlusPlus;

        case UnaryOperatorType.Decrement:
        case UnaryOperatorType.PostDecrement:
          return Tokens.SubSub;

        case UnaryOperatorType.Dereference:
          return Tokens.Asterisk;

        case UnaryOperatorType.SuppressNullableWarning:
          return string.Empty;
      }
      
      throw new NotImplementedException();
    }

    public SyntaxNode VisitUnaryOperatorExpression(UnaryOperatorExpression unaryOperatorExpression) {
      string operatorToken = GetUnaryOperator(unaryOperatorExpression.Operator);
      var expression = unaryOperatorExpression.Expression.AcceptExpression(this);
      bool isPosOperator = unaryOperatorExpression.Operator == UnaryOperatorType.PostIncrement || unaryOperatorExpression.Operator == UnaryOperatorType.PostDecrement;
      if (isPosOperator) {
        return new PostfixUnaryExpression(expression, operatorToken);
      }
      return new PrefixUnaryExpressionSyntax(operatorToken, expression);
    }

    public SyntaxNode VisitUncheckedExpression(UncheckedExpression uncheckedExpression) {
      throw new NotImplementedException();
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
      return BreakStatementSyntax.Ins;
    }

    public SyntaxNode VisitCheckedStatement(CheckedStatement checkedStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitContinueStatement(ContinueStatement continueStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitDoWhileStatement(DoWhileStatement doWhileStatement) {
      throw new NotImplementedException();
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitIfElseStatement(IfElseStatement ifElseStatement) {
      var condition = ifElseStatement.Condition.AcceptExpression(this);
      var trueStatement = ifElseStatement.TrueStatement.AcceptStatement(this);
      return new IfElseStatementSyntax(condition, trueStatement) {
        FalseStatement = ifElseStatement.FalseStatement?.AcceptStatement(this)
      };
    }

    public SyntaxNode VisitLabelStatement(LabelStatement labelStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitLockStatement(LockStatement lockStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitReturnStatement(ReturnStatement returnStatement) {
      if (returnStatement.Expression.IsNull()) {
        return new ReturnStatementSyntax();
      }
      return returnStatement.Expression.AcceptExpression(this).Return();
    }

    public SyntaxNode VisitSwitchStatement(SwitchStatement switchStatement) {
      var expression = switchStatement.Expression.AcceptExpression(this);
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
      if (throwStatement.Expression is ObjectCreateExpression objectCreateExpression) {
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
      var type = catchClause.Type.AcceptExpression(this);
      var name = catchClause.VariableNameToken.Accept<IdentifierSyntax>(this);
      return new CatchClauseSyntax(type, name);
    }

    public SyntaxNode VisitUncheckedStatement(UncheckedStatement uncheckedStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitUnsafeStatement(UnsafeStatement unsafeStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitUsingStatement(UsingStatement usingStatement) {
      throw new NotImplementedException();
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
      var name = localFunctionDeclarationStatement.NameToken.Accept<IdentifierSyntax>(this);
      var parameters = method.Parameters.Select(GetParameterSyntax);
      var retuenType = GetTypeName(method.ReturnType);
      if (method.IsStatic) {
        var function = new MethodDefinitionSyntax(name, parameters, retuenType) {
          IsStatic = true,
          Template = method.GetTemplateSyntax()
        };
        PushFunction(function);
        var body = localFunctionDeclarationStatement.Body.Accept<BlockSyntax>(this);
        function.AddStatements(body.Statements);
        PopFunction();
        CompilationUnit.AddSrcStatement(function);
        return StatementSyntax.Empty;
      } else {
        var body = localFunctionDeclarationStatement.Body.Accept<BlockSyntax>(this);
        var lambdaExpressionSyntax = new LambdaExpressionSyntax(parameters, retuenType, body);
        return new VariableDeclarationStatementSyntax(IdentifierSyntax.Auto, name, lambdaExpressionSyntax);
      }
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitConstructorDeclaration(ConstructorDeclaration constructorDeclaration) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitConstructorInitializer(ConstructorInitializer constructorInitializer) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitDestructorDeclaration(DestructorDeclaration destructorDeclaration) {
      throw new NotImplementedException();
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

    public static void CheckParameterTypeConflict(ref ExpressionSyntax type, IParameter parameter, ITypeDefinition typeDefinition) {
      foreach (var m in typeDefinition.Methods) {
        if (m.Name == parameter.Type.Name) {
          type = type.WithFullName(parameter.Type, typeDefinition);
          break;
        }
      }
      foreach (var f in typeDefinition.Fields) {
        if (f.GetFieldName() == parameter.Type.Name) {
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

    public SyntaxNode VisitMethodDeclaration(MethodDeclaration methodDeclaration) {
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
      PushFunction(node);
      if (methodDeclaration != null) {
        var block = methodDeclaration.Body.Accept<BlockSyntax>(this);
        node.AddStatements(block.Statements);
      }
      if (!IsMethodExport(method)) {
        InsertDefaultReturnValue(node, method, returnType);
      }
      PopFunction();
      return node;
    }

    public SyntaxNode VisitOperatorDeclaration(OperatorDeclaration operatorDeclaration) {
      throw new NotImplementedException();
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
      var type = (ITypeDefinition)primitiveType.GetSymbol();
      return GetTypeName(type);
    }

    public SyntaxNode VisitComment(Comment comment) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitWhitespace(WhitespaceNode whitespaceNode) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitText(TextNode textNode) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitNewLine(NewLineNode newLineNode) {
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
      throw new NotImplementedException();
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
  }
}
