#include "MethodToken-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/MethodToken-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::MethodTokenNamespace {
MethodToken::MethodToken(Int32 methodToken) {
  Token = methodToken;
}

Int32 MethodToken::GetHashCode() {
  return Token;
}

Boolean MethodToken::Equals(Object obj) {
  if (rt::is<MethodToken>(obj)) {
    MethodToken obj2 = (MethodToken)obj;
    return Equals(obj2);
  }
  return false;
}

Boolean MethodToken::Equals(MethodToken obj) {
  return obj.get_Token() == Token;
}

Boolean MethodToken::op_Equality(MethodToken a, MethodToken b) {
  return a.Equals(b);
}

Boolean MethodToken::op_Inequality(MethodToken a, MethodToken b) {
  return !(a == b);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::MethodTokenNamespace
