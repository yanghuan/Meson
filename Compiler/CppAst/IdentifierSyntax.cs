using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Meson.Compiler.CppAst {
  internal abstract class IdentifierSyntax : ExpressionSyntax {
    public static implicit operator IdentifierSyntax(string valueText) {
      return new ValueTextIdentifierSyntax(valueText);
    }

    public static readonly IdentifierSyntax Meson = "rt";
    public static readonly IdentifierSyntax code = "code";
    public static readonly IdentifierSyntax TypeCode = "rt::TypeCode";
    public static readonly IdentifierSyntax TypeList = "rt::TypeList";
    public static readonly IdentifierSyntax Void = "void";
    public static readonly IdentifierSyntax Object = "Object";
    public static readonly IdentifierSyntax T = "T";
    public static readonly IdentifierSyntax VariadicT = "...T";
    public static readonly IdentifierSyntax TVariadic = "T...";

    public static readonly IdentifierSyntax N = "N";
    public static readonly IdentifierSyntax In = "in";
    public static readonly IdentifierSyntax Class = "class";
    public static readonly IdentifierSyntax Is = "rt::is";
    public static readonly IdentifierSyntax As = "rt::as";
    public static readonly IdentifierSyntax Cast = "rt::cast";
    public static readonly IdentifierSyntax Throw = "rt::throw_exception";
    public static readonly IdentifierSyntax Rethrow = "throw";
    public static readonly IdentifierSyntax NewObj = "rt::newobj";
    public static readonly IdentifierSyntax NewString = "rt::newstr";
    public static readonly IdentifierSyntax NewArray = "rt::newarr";
    public static readonly IdentifierSyntax Lock = "rt::lock";
    public static readonly IdentifierSyntax Typeof = "typeof";
    public static readonly IdentifierSyntax Using = "rt::Using";
    public static readonly IdentifierSyntax Default = "rt::default__";
    public static readonly IdentifierSyntax TypeVoid = "rt::Void";
    public static readonly IdentifierSyntax IsEnumType = "std::is_enum_v";
    public static readonly IdentifierSyntax IsPointerType = "std::is_pointer_v";
    public static readonly IdentifierSyntax IsBoolType = "rt::IsBool";
    public static readonly IdentifierSyntax GetAllocSize = "rt::string::GetAllocSize";
    public static readonly IdentifierSyntax FunctionPointer = "rt::fp";
    public static readonly IdentifierSyntax Fixed = "rt::fixed";
    public static readonly IdentifierSyntax EmptyArray = "Array<>::in::Empty";
    public static readonly IdentifierSyntax Out = "out";
    public static readonly IdentifierSyntax Value = "value";
    public static readonly IdentifierSyntax Get = "get";
    public static readonly IdentifierSyntax This = "this";
    public static readonly IdentifierSyntax Auto = "auto";
    public static readonly IdentifierSyntax VoidPointer = "void*";
    public static readonly IdentifierSyntax VariableArguments = "...";
    public static readonly IdentifierSyntax Interface = "interface";
    public static readonly IdentifierSyntax Invoke = "Invoke";
    public static readonly IdentifierSyntax Nullptr = Tokens.Nullptr;
    public static readonly IdentifierSyntax Sizeof = Tokens.Sizeof;
  }

  internal class ValueTextIdentifierSyntax : IdentifierSyntax {
    public string ValueText { get; }

    public ValueTextIdentifierSyntax(string valueText) {
      ValueText = valueText;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal class GenericIdentifierSyntax : IdentifierSyntax {
    public ExpressionSyntax Name { get; set; }
    public readonly List<ExpressionSyntax> GenericArguments = new List<ExpressionSyntax>();

    public GenericIdentifierSyntax(ExpressionSyntax name) {
      Name = name;
    }

    public GenericIdentifierSyntax(ExpressionSyntax name, IEnumerable<ExpressionSyntax> args) {
      Name = name;
      GenericArguments.AddRange(args);
    }

    public GenericIdentifierSyntax(ExpressionSyntax name, params ExpressionSyntax[] args) {
      Name = name;
      GenericArguments.AddRange(args);
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal class PostfixUnaryExpression : ExpressionSyntax {
    public ExpressionSyntax Expression { get; }
    public string OperatorToken { get; }

    public PostfixUnaryExpression(ExpressionSyntax expression, string operatorToken) {
      Expression = expression;
      OperatorToken = operatorToken;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class PointerIdentifierSyntax : PostfixUnaryExpression {
    public PointerIdentifierSyntax(ExpressionSyntax name) : base(name, Tokens.Asterisk) {
    }
  }

  internal sealed class RefExpressionSyntax : PostfixUnaryExpression {
    public RefExpressionSyntax(ExpressionSyntax name) : base(name, Tokens.Ampersand) {
    }
  }

  internal sealed class RightRefExpressionSyntax : PostfixUnaryExpression {
    public RightRefExpressionSyntax(ExpressionSyntax name) : base(name, Tokens.LogicAnd) {
    }
  }

  internal class PrefixUnaryExpressionSyntax : ExpressionSyntax {
    public string OperatorToken { get; }
    public ExpressionSyntax Expression { get; }

    public PrefixUnaryExpressionSyntax(string operatorToken, ExpressionSyntax expression) {
      OperatorToken = operatorToken;
      Expression = expression;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }
 
  internal sealed class AddressExpressionSyntax : PrefixUnaryExpressionSyntax {
    public AddressExpressionSyntax(ExpressionSyntax expression) : base(Tokens.Ampersand, expression) {
    }
  }

  internal sealed class IndirectionExpressionSyntax : PrefixUnaryExpressionSyntax {
    public IndirectionExpressionSyntax(ExpressionSyntax expression) : base(Tokens.Asterisk, expression) {
    }
  }

  internal sealed class ArrayIdentifierSyntax : IdentifierSyntax {
    public IdentifierSyntax Name { get; }
    public int Count { get; }

    public ArrayIdentifierSyntax(IdentifierSyntax name, int count) {
      Name = name;
      Count = count;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class NestedCycleRefTypeNameSyntax : IdentifierSyntax {
    public IdentifierSyntax Type { get; }
    public string FullName { get; }

    public NestedCycleRefTypeNameSyntax(string fullName) : this(fullName, Object) {
    }

    public NestedCycleRefTypeNameSyntax(string fullName, IdentifierSyntax type) {
      FullName = fullName;
      Type = type;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }

  internal sealed class ExpressionIdentifierSyntax : IdentifierSyntax {
    public ExpressionSyntax Expression { get; private set; }

    public ExpressionIdentifierSyntax(ExpressionSyntax expression) {
      Expression = expression;
    }

    internal override void Render(CppRenderer renderer) {
      Expression.Render(renderer);
    }
  }

  internal sealed class SymbolNameSyntax : IdentifierSyntax {
    public IdentifierSyntax NameExpression { get; private set; }

    public SymbolNameSyntax(IdentifierSyntax identifierName) {
      NameExpression = identifierName;
    }

    public void Update(IdentifierSyntax newName) {
      NameExpression = newName;
    }

    internal override void Render(CppRenderer renderer) {
      NameExpression.Render(renderer);
    }
  }

  internal sealed class FunctionPointerExpressionSyntax : ExpressionSyntax {
    public ExpressionSyntax RetuenType { get; }
    public IdentifierSyntax Name { get; set; }
    public readonly List<ExpressionSyntax> ParameterTypes = new List<ExpressionSyntax>();

    public FunctionPointerExpressionSyntax(ExpressionSyntax retuenType, IEnumerable<ExpressionSyntax> parameterTypes, IdentifierSyntax name = null) {
      RetuenType = retuenType;
      ParameterTypes.AddRange(parameterTypes);
      Name = name;
    }

    internal override void Render(CppRenderer renderer) {
      renderer.Render(this);
    }
  }
}
