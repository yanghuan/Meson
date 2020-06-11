using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using ICSharpCode.Decompiler.CSharp.Syntax;
using ICSharpCode.Decompiler.CSharp.Syntax.PatternMatching;
using ICSharpCode.Decompiler.TypeSystem;
using Meson.Compiler.CppAst;

namespace Meson.Compiler {
  internal sealed class MethodTransform : IAstVisitor<SyntaxNode> {
    private TypeDefinitionTransform typeDefinition_;
    private Stack<IMethod> methodSymbols_ = new Stack<IMethod>();
    private readonly Stack<BlockSyntax> blocks_ = new Stack<BlockSyntax>();

    public MethodTransform(TypeDefinitionTransform typeDefinition, IMethod methodSymbol) {
      typeDefinition_ = typeDefinition;
      Visit(methodSymbol);
    }

    private SyntaxGenerator Generator => typeDefinition_.Generator;
    private CompilationUnitSyntax CompilationUnit => typeDefinition_.CompilationUnit.CompilationUnit;
    private IMethod MethodSymbol => methodSymbols_.Peek();
    private BlockSyntax Block => blocks_.Peek();
    private IdentifierSyntax GetMemberName(ISymbol symbol) => Generator.GetMemberName(symbol);
    private ExpressionSyntax GetTypeName(IType type, ITypeDefinition typeDefinition) => typeDefinition_.GetTypeName(type, typeDefinition);

    private void Visit(IMethod methodSymbol) {
      if (methodSymbol.HasBody) {
        var m = Generator.GetMethodDeclaration(methodSymbol);
        if (m != null) {
          methodSymbols_.Push(methodSymbol);
          var node = m.Accept<MethodImplementationSyntax>(this);
          methodSymbols_.Pop();
          CompilationUnit.AddSrcStatement(node);
        }
      }
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitCastExpression(CastExpression castExpression) {
      throw new NotImplementedException();
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitIndexerExpression(IndexerExpression indexerExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitInterpolatedStringExpression(InterpolatedStringExpression interpolatedStringExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitInvocationExpression(InvocationExpression invocationExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitIsExpression(IsExpression isExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitLambdaExpression(LambdaExpression lambdaExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitMemberReferenceExpression(MemberReferenceExpression memberReferenceExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitNamedArgumentExpression(NamedArgumentExpression namedArgumentExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitNamedExpression(NamedExpression namedExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitNullReferenceExpression(NullReferenceExpression nullReferenceExpression) {
      throw new NotImplementedException();
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

    public SyntaxNode VisitPrimitiveExpression(PrimitiveExpression primitiveExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitSizeOfExpression(SizeOfExpression sizeOfExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitStackAllocExpression(StackAllocExpression stackAllocExpression) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitThisReferenceExpression(ThisReferenceExpression thisReferenceExpression) {
      throw new NotImplementedException();
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitUnaryOperatorExpression(UnaryOperatorExpression unaryOperatorExpression) {
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
      throw new NotImplementedException();
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
      throw new NotImplementedException();
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitLabelStatement(LabelStatement labelStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitLockStatement(LockStatement lockStatement) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitReturnStatement(ReturnStatement returnStatement) {
      throw new NotImplementedException();
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
      throw new NotImplementedException();
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

    private ParameterSyntax GetParameterSyntax(IParameter parameter, IMethod method) {
      var type = GetTypeName(parameter.Type, method.DeclaringTypeDefinition);
      var name = GetMemberName(parameter);
      return new ParameterSyntax(type, name);
    }

    private ExpressionSyntax GetDeclaringType(ITypeDefinition type) {
      ExpressionSyntax name = type.IsRefType() ? $"{type.Name}___" : type.Name;
      if (type.DeclaringType != null) {
        var outTypeName = GetDeclaringType(type.DeclaringType.GetDefinition());
        return outTypeName.TwoColon(name);
      }
      return name;
    }

    public SyntaxNode VisitMethodDeclaration(MethodDeclaration methodDeclaration) {
      var method = MethodSymbol;
      var parameters = method.Parameters.Select(i => GetParameterSyntax(i, method));
      var name = GetMemberName(MethodSymbol);
      var declaringType = GetDeclaringType(method.DeclaringTypeDefinition);
      var returnType = GetTypeName(method.ReturnType, method.DeclaringTypeDefinition);
      MethodImplementationSyntax node = new MethodImplementationSyntax(name, returnType, parameters, declaringType);
      node.Add(new ReturnStatementSyntax(new InvationExpressionSyntax(returnType)));
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
      throw new NotImplementedException();
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
      throw new NotImplementedException();
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
      throw new NotImplementedException();
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
      throw new NotImplementedException();
    }

    public SyntaxNode VisitInterpolation(Interpolation interpolation) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitInterpolatedStringText(InterpolatedStringText interpolatedStringText) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitNullNode(AstNode nullNode) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitErrorNode(AstNode errorNode) {
      throw new NotImplementedException();
    }

    public SyntaxNode VisitPatternPlaceholder(AstNode placeholder, Pattern pattern) {
      throw new NotImplementedException();
    }
  }
}
