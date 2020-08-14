#include "PropertyToken-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/PropertyToken-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::PropertyTokenNamespace {
PropertyToken::PropertyToken(Int32 propertyToken) {
  Token = propertyToken;
}

Int32 PropertyToken::GetHashCode() {
  return Token;
}

Boolean PropertyToken::Equals(Object obj) {
  if (rt::is<PropertyToken>(obj)) {
    PropertyToken obj2 = (PropertyToken)obj;
    return Equals(obj2);
  }
  return false;
}

Boolean PropertyToken::Equals(PropertyToken obj) {
  return obj.get_Token() == Token;
}

Boolean PropertyToken::op_Equality(PropertyToken a, PropertyToken b) {
  return a.Equals(b);
}

Boolean PropertyToken::op_Inequality(PropertyToken a, PropertyToken b) {
  return !(a == b);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::PropertyTokenNamespace
