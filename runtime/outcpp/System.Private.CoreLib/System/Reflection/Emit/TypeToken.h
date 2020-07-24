#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace TypeTokenNamespace {
struct TypeToken : public rt::ValueType<TypeToken> {
  public: Int32 get_Token() { return Token; }
  public: explicit TypeToken(Int32 typeToken);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(TypeToken obj);
  public: static Boolean op_Equality(TypeToken a, TypeToken b);
  public: static Boolean op_Inequality(TypeToken a, TypeToken b);
  public: explicit TypeToken() {}
  public: static TypeToken Empty;
  private: Int32 Token;
};
} // namespace TypeTokenNamespace
using TypeToken = TypeTokenNamespace::TypeToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
