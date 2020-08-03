#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace StringTokenNamespace {
struct StringToken : public valueType<StringToken> {
  public: Int32 get_Token() { return Token; }
  public: explicit StringToken(Int32 str);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(StringToken obj);
  public: static Boolean op_Equality(StringToken a, StringToken b);
  public: static Boolean op_Inequality(StringToken a, StringToken b);
  public: explicit StringToken() {}
  private: Int32 Token;
};
} // namespace StringTokenNamespace
using StringToken = StringTokenNamespace::StringToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
