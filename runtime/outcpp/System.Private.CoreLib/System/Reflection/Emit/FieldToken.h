#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace FieldTokenNamespace {
struct FieldToken : public valueType<FieldToken> {
  public: Int32 get_Token() { return Token; }
  public: explicit FieldToken(Int32 fieldToken, Type fieldClass);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(FieldToken obj);
  public: static Boolean op_Equality(FieldToken a, FieldToken b);
  public: static Boolean op_Inequality(FieldToken a, FieldToken b);
  public: explicit FieldToken() {}
  public: static FieldToken Empty;
  private: Object _class;
  private: Int32 Token;
};
} // namespace FieldTokenNamespace
using FieldToken = FieldTokenNamespace::FieldToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
