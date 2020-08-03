#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace PropertyTokenNamespace {
struct PropertyToken : public valueType<PropertyToken> {
  public: Int32 get_Token() { return Token; }
  public: explicit PropertyToken(Int32 propertyToken);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(PropertyToken obj);
  public: static Boolean op_Equality(PropertyToken a, PropertyToken b);
  public: static Boolean op_Inequality(PropertyToken a, PropertyToken b);
  public: explicit PropertyToken() {}
  public: static PropertyToken Empty;
  private: Int32 Token;
};
} // namespace PropertyTokenNamespace
using PropertyToken = PropertyTokenNamespace::PropertyToken;
} // namespace System::Private::CoreLib::System::Reflection::Emit
