using System;
using System.Collections.Generic;
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
      //"System.Array"
    };

    private readonly TypeDefinitionTransform typeDefinition_;
    private readonly ClassSyntax classNode_;
    private readonly Stack<IMethod> methodSymbols_ = new Stack<IMethod>();
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
    private IdentifierSyntax GetMemberName(ISymbol symbol) => Generator.GetMemberName(symbol);
    private ExpressionSyntax GetTypeName(IType type, ISymbol symbol = null, bool isInDelaring = true) => typeDefinition_.GetTypeName(type, isInDelaring ? MethodSymbol.DeclaringTypeDefinition : null, symbol);

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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitArrayInitializerExpression(ArrayInitializerExpression arrayInitializerExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitAsExpression(AsExpression asExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitAssignmentExpression(AssignmentExpression assignmentExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitBaseReferenceExpression(BaseReferenceExpression baseReferenceExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitBinaryOperatorExpression(BinaryOperatorExpression binaryOperatorExpression) {
      var left = binaryOperatorExpression.Left.AcceptExpression(this);
      var right = binaryOperatorExpression.Right.AcceptExpression(this);
      return new BinaryExpressionSyntax(left, binaryOperatorExpression.Operator.ToOperatorToken(), right);
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitDirectionExpression(DirectionExpression directionExpression) {
      throw new NotImplementedException();
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
      throw new NotImplementedException();
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

    private List<ExpressionSyntax> BuildInvocationArguments(InvocationExpression invocationExpression) {
      var symbol = (IMethod)invocationExpression.GetSymbol();
      List<ExpressionSyntax> arguments = new List<ExpressionSyntax>();
      int i = 0;
      foreach (var argument in invocationExpression.Arguments) {
        var parameter = symbol.Parameters[i];
        var resolveResult = argument.GetResolveResult();
        var expression = argument.AcceptExpression(this);
        CheckArrayConflict(symbol, parameter, i, resolveResult.Type, ref expression);
        arguments.Add(expression);
        ++i;
      }
      return arguments;
    }

    public SyntaxNode VisitInvocationExpression(InvocationExpression invocationExpression) {
      var target = invocationExpression.Target.AcceptExpression(this);
      return target.Invation(BuildInvocationArguments(invocationExpression));
    }

    public SyntaxNode VisitIsExpression(IsExpression isExpression) {
      var type = isExpression.Type.AcceptExpression(this);
      var expression = isExpression.Expression.AcceptExpression(this);
      return IdentifierSyntax.Is.Generic(type).Invation(expression);
    }

    public SyntaxNode VisitLambdaExpression(LambdaExpression lambdaExpression) {
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

      switch (symbol.SymbolKind) {
        case SymbolKind.Field: {
            var field = (IField)symbol;
            var name = GetMemberName(field);
            if (field.IsStatic) {
              if (field.DeclaringTypeDefinition.IsRefType()) {
                target = target.TwoColon(IdentifierSyntax.In);
              }
              return target.TwoColon(name);
            } else {
              return target.Arrow(name);
            }
          }
        case SymbolKind.Method: {
            var method = (IMethod)symbol;
            var name = GetMemberName(method);
            if (method.IsStatic) {
              if (method.DeclaringTypeDefinition.IsRefType()) {
                target = target.TwoColon(IdentifierSyntax.In);
              }
              return target.TwoColon(name);
            } else {
              return target.Arrow(name);
            }
          }
      }
      throw new NotImplementedException();
    }

    public SyntaxNode VisitNamedArgumentExpression(NamedArgumentExpression namedArgumentExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitNamedExpression(NamedExpression namedExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitNullReferenceExpression(NullReferenceExpression nullReferenceExpression) {
      return IdentifierSyntax.Nullptr;
    }

    public SyntaxNode VisitObjectCreateExpression(ObjectCreateExpression objectCreateExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitOutVarDeclarationExpression(OutVarDeclarationExpression outVarDeclarationExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitParenthesizedExpression(ParenthesizedExpression parenthesizedExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitPointerReferenceExpression(PointerReferenceExpression pointerReferenceExpression) {
      throw new NotImplementedException();
    }

    internal static LiteralExpressionSyntax GetPrimitiveExpression(object value) {
      var code = Type.GetTypeCode(value.GetType());
      switch (code) {
        case TypeCode.String: {
            return new StringLiteralExpressionSyntax((string)value);
          }
        case TypeCode.Int32: {
            return new NumberLiteralExpressionSyntax(value.ToString());
          }
        case TypeCode.UInt32: {
            return new NumberLiteralExpressionSyntax($"{value}u");
          }
        default: {
            throw new NotImplementedException();
          }
      }
    }

    public SyntaxNode VisitPrimitiveExpression(PrimitiveExpression primitiveExpression) {
      return GetPrimitiveExpression(primitiveExpression.Value);
    }

    public SyntaxNode VisitSizeOfExpression(SizeOfExpression sizeOfExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitStackAllocExpression(StackAllocExpression stackAllocExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitThisReferenceExpression(ThisReferenceExpression thisReferenceExpression) {
      var type = thisReferenceExpression.GetResolveResult().Type;
      if (type.IsRefType()) {
        var typeName = GetTypeName(type);
        return IdentifierSyntax.This.CastTo(typeName);
      }
      return new IndirectionIdentifierSyntax(IdentifierSyntax.This);
    }

    public SyntaxNode VisitThrowExpression(ThrowExpression throwExpression) {
      throw new NotImplementedException();
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

    public SyntaxNode VisitUnaryOperatorExpression(UnaryOperatorExpression unaryOperatorExpression) {
      switch (unaryOperatorExpression.Operator) {
        case UnaryOperatorType.AddressOf: {
            return new AddressIdentifierSyntax(unaryOperatorExpression.Expression.AcceptExpression(this));
          }
      }
      throw new NotImplementedException();
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
      blocks_.Push(node);
      foreach (var statement in blockStatement.Statements) {
        try {
          var s = statement.AcceptStatement(this);
          node.Statements.Add(s);
        } catch (NotImplementedException) {
          break;
        }
      }
      blocks_.Pop();
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitForeachStatement(ForeachStatement foreachStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitForStatement(ForStatement forStatement) {
      throw new NotImplementedException();
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
      throw new NotImplementedException();
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
            var refIdentifier = (RefIdentifierSyntax)returnType;
            node.Add(refIdentifier.Name.Invation().Return());
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
      var parameters = method.Parameters.Select(i => GetParameterSyntax(i, method));
      var name = GetMemberName(MethodSymbol);
      var declaringType = GetDeclaringType(method.DeclaringTypeDefinition);
      var returnType = GetTypeName(method.ReturnType, method, false);
      MethodImplementationSyntax node = new MethodImplementationSyntax(name, returnType, parameters, declaringType);
      if (methodDeclaration != null) {
        var block = methodDeclaration.Body.Accept<BlockSyntax>(this);
        node.AddRange(block.Statements);
      }
      if (!IsMethodExport(method)) {
        InsertDefaultReturnValue(node, method, returnType);
      }
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitTupleType(TupleAstType tupleType) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitTupleTypeElement(TupleTypeElement tupleTypeElement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitComposedType(ComposedType composedType) {
      throw new NotImplementedException();
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
