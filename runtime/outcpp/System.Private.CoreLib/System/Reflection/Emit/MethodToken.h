#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace MethodTokenNamespace {
struct MethodToken : public valueType<MethodToken> {
  public: Int32 get_Token() { return Token; }
  public: explicit MethodToken(Int32 methodToken);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(MethodToken obj);
  public: static Boolean op_Equality(MethodToken a, MethodToken b);
  public: static Boolean op_Inequality(MethodToken a, MethodToken b);
  public: explicit MethodToken() {}
  public: static MethodToken Empty;
  private: Int32 Token;
};
} // namespace MethodTokenNamespace
using MethodToken = MethodTokenNamespace::MethodToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
