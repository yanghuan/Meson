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
    private readonly Stack<MethodImplementationSyntax> functions_ = new Stack<MethodImplementationSyntax>();
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
    private MethodImplementationSyntax Function => functions_.Peek();
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

    private void PushFunction(MethodImplementationSyntax function) {
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
        MethodImplementationSyntax node;
        if (IsMethodExport(methodSymbol)) {
          var methodDeclaration = Generator.GetMethodDeclaration(methodSymbol);
          node = methodDeclaration?.Accept<MethodImplementationSyntax>(this);
        } else {
          node = (MethodImplementationSyntax)VisitMethodDeclaration(null);
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

    private void InsetMainFuntion(IMethod methodSymbol, MethodImplementationSyntax method) {
      var typeDefinition = methodSymbol.DeclaringTypeDefinition;
      IdentifierSyntax ns = typeDefinition.GetFullNamespace();
      var typeName = GetTypeName(typeDefinition, typeDefinition, false);
      if (typeDefinition.IsRefType()) {
        typeName = typeName.TwoColon(IdentifierSyntax.In);
      }
      var node = new MethodImplementationSyntax("main", "int", new ParameterSyntax[] {
        new ParameterSyntax("int", "argc"),
        new ParameterSyntax("char*", "argv[]"),
      });
      var invation = new InvationExpressionSyntax("rt::init", "argc", "argv", ns.TwoColon(typeName).TwoColon(method.Name).Address());
      node.Add(invation.Return());
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitDefaultValueExpression(DefaultValueExpression defaultValueExpression) {
      var type = (ITypeDefinition)defaultValueExpression.Type.GetSymbol();
      if (type.IsRefType()) {
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

    private List<ExpressionSyntax> BuildInvocationArguments(InvocationExpression invocationExpression) {
      var symbol = (IMethod)invocationExpression.GetSymbol();
      return BuildArguments(symbol, invocationExpression.Arguments);
    }

    public SyntaxNode VisitInvocationExpression(InvocationExpression invocationExpression) {
      var arguments = BuildInvocationArguments(invocationExpression);
      if (invocationExpression.Target is MemberReferenceExpression memberReference) {
        var method = (IMethod)invocationExpression.GetSymbol();
        if (method.IsExtensionMethod) {
          var memberReferenceTarget = memberReference.Target.AcceptExpression(this);
          arguments.Insert(0, memberReferenceTarget);
          return GetTypeName(method.DeclaringTypeDefinition).TwoColon(GetMemberName(method)).Invation(arguments);
        }
      }

      var target = invocationExpression.Target.AcceptExpression(this);
      return target.Invation(arguments);
    }

    public SyntaxNode VisitIsExpression(IsExpression isExpression) {
      var type = isExpression.Type.AcceptExpression(this);
      var expression = isExpression.Expression.AcceptExpression(this);
      return IdentifierSyntax.Is.Generic(type).Invation(expression);
    }

    public SyntaxNode VisitLambdaExpression(LambdaExpression lambdaExpression) {
      throw new NotImplementedException();
    }

    private MemberAccessExpressionSyntax BuildMemberAccessExpression(ExpressionSyntax target, ISymbol symbol, AstNode node, bool isPointer = false) {
      switch (symbol.SymbolKind) {
        case SymbolKind.Field:
        case SymbolKind.Property:
        case SymbolKind.Method: {
            var member = (IEntity)symbol;
            bool isGetter = false;
            switch (symbol.SymbolKind) {
              case SymbolKind.Property: {
                  var property = (IProperty)symbol;
                  isGetter = !(node.Parent is AssignmentExpression);
                  member = isGetter ? property.Getter : property.Setter;
                  break;
                }
              case SymbolKind.Method: {
                  var method = (IMethod)symbol;
                  if (method.IsExtensionMethod) {

                  }
                  break;
                }
            }
            ExpressionSyntax name = GetMemberName(member);
            if (isGetter) {
              name = name.Invation();
            }
            if (member.IsStatic) {
              if (member.DeclaringTypeDefinition.IsRefType()) {
                target = target.TwoColon(IdentifierSyntax.In);
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
      return BuildMemberAccessExpression(target, symbol, memberReferenceExpression);
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
      return BuildMemberAccessExpression(target, symbol, pointerReferenceExpression, true);
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
        case UnaryOperatorType.AddressOf:
          return Tokens.Ampersand;

        case UnaryOperatorType.Not:
          return Tokens.Exclamation;

        case UnaryOperatorType.Dereference:
          return Tokens.Asterisk;

        case UnaryOperatorType.PostIncrement:
          return Tokens.PlusPlus;
      }

      throw new NotImplementedException();
    }

    public SyntaxNode VisitUnaryOperatorExpression(UnaryOperatorExpression unaryOperatorExpression) {
      string operatorToken = GetUnaryOperator(unaryOperatorExpression.Operator);
      var expression = unaryOperatorExpression.Expression.AcceptExpression(this);
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
      throw new NotImplementedException();
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitSwitchSection(SwitchSection switchSection) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitCaseLabel(CaseLabel caseLabel) {
      throw new NotImplementedException();
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitCatchClause(CatchClause catchClause) {
      throw new NotImplementedException();
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

    public SyntaxNode VisitLocalFunctionDeclarationStatement(LocalFunctionDeclarationStatement localFunctionDeclarationStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitWhileStatement(WhileStatement whileStatement) {
      throw new NotImplementedException();
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
      ExpressionSyntax name = type.IsRefType() ? $"{type.Name}___" : type.Name;
      if (Generator.IsVoidGenericType(type)) {
        name = new GenericIdentifierSyntax(name);
      }
      var declaringType = AssemblyTransform.GetDeclaringType(type);
      if (declaringType != null) {
        var outTypeName = GetDeclaringType(declaringType.GetDefinition());
        return outTypeName.TwoColon(name);
      }
      return name;
    }

    private void InsertDefaultReturnValue(MethodImplementationSyntax node, IMethod method, ExpressionSyntax returnType) {
      switch (method.ReturnType.Kind) {
        case TypeKind.Pointer:
        case TypeKind.Class:
        case TypeKind.Interface:
        case TypeKind.Delegate: {
            node.Add(IdentifierSyntax.Nullptr.Return());
            break;
          }
        case TypeKind.ByReference: {
            var refIdentifier = (RefExpressionSyntax)returnType;
            node.Add(refIdentifier.Expression.Invation().Return());
            break;
          }
        case TypeKind.Enum: {
            var field = method.ReturnType.GetDefinition().Fields.Last();
            var name = GetMemberName(field);
            node.Add(returnType.TwoColon(name).Return());
            break;
          }
        case TypeKind.Void: {
            break;
          }
        default: {
            node.Add(returnType.Invation().Return());
            break;
          }
      }
    }

    public SyntaxNode VisitMethodDeclaration(MethodDeclaration methodDeclaration) {
      var method = MethodSymbol;
      var parameters = method.Parameters.Select(i => GetParameterSyntax(i, method)).ToList();
      var name = GetMemberName(MethodSymbol);
      var declaringType = GetDeclaringType(method.DeclaringTypeDefinition);
      var returnType = GetTypeName(method.ReturnType, method, false);
      typeDefinition_.CheckOperatorParameters(method, parameters, returnType);
      MethodImplementationSyntax node = new MethodImplementationSyntax(name, returnType, parameters, declaringType);
      PushFunction(node);
      if (methodDeclaration != null) {
        var block = methodDeclaration.Body.Accept<BlockSyntax>(this);
        node.AddRange(block.Statements);
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
      var expression = composedType.BaseType.AcceptExpression(this);
      return new PostfixUnaryExpression(expression, new string(Tokens.Asterisk[0], composedType.PointerRank));
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
