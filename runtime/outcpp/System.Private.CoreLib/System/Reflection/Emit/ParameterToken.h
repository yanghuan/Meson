#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace ParameterTokenNamespace {
struct ParameterToken : public valueType<ParameterToken> {
  public: Int32 get_Token() { return Token; }
  public: explicit ParameterToken(Int32 parameterToken);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ParameterToken obj);
  public: static Boolean op_Equality(ParameterToken a, ParameterToken b);
  public: static Boolean op_Inequality(ParameterToken a, ParameterToken b);
  public: explicit ParameterToken() {}
  public: static ParameterToken Empty;
  private: Int32 Token;
};
} // namespace ParameterTokenNamespace
using ParameterToken = ParameterTokenNamespace::ParameterToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
