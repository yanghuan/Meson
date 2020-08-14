#include "FieldToken-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/FieldToken-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::FieldTokenNamespace {
FieldToken::FieldToken(Int32 fieldToken, Type fieldClass) {
  Token = fieldToken;
  _class = fieldClass;
}

Int32 FieldToken::GetHashCode() {
  return Token;
}

Boolean FieldToken::Equals(Object obj) {
  if (rt::is<FieldToken>(obj)) {
    FieldToken obj2 = (FieldToken)obj;
    return Equals(obj2);
  }
  return false;
}

Boolean FieldToken::Equals(FieldToken obj) {
  if (obj.get_Token() == Token) {
    return obj._class == _class;
  }
  return false;
}

Boolean FieldToken::op_Equality(FieldToken a, FieldToken b) {
  return a.Equals(b);
}

Boolean FieldToken::op_Inequality(FieldToken a, FieldToken b) {
  return !(a == b);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::FieldTokenNamespace
