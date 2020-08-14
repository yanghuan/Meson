#include "ParameterToken-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/ParameterToken-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::ParameterTokenNamespace {
ParameterToken::ParameterToken(Int32 parameterToken) {
  Token = parameterToken;
}

Int32 ParameterToken::GetHashCode() {
  return Token;
}

Boolean ParameterToken::Equals(Object obj) {
  if (rt::is<ParameterToken>(obj)) {
    ParameterToken obj2 = (ParameterToken)obj;
    return Equals(obj2);
  }
  return false;
}

Boolean ParameterToken::Equals(ParameterToken obj) {
  return obj.get_Token() == Token;
}

Boolean ParameterToken::op_Equality(ParameterToken a, ParameterToken b) {
  return a.Equals(b);
}

Boolean ParameterToken::op_Inequality(ParameterToken a, ParameterToken b) {
  return !(a == b);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::ParameterTokenNamespace
