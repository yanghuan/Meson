#include "SignatureToken-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/SignatureToken-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::SignatureTokenNamespace {
SignatureToken::SignatureToken(Int32 signatureToken) {
  Token = signatureToken;
}

Int32 SignatureToken::GetHashCode() {
  return Token;
}

Boolean SignatureToken::Equals(Object obj) {
  if (rt::is<SignatureToken>(obj)) {
    SignatureToken obj2 = (SignatureToken)obj;
    return Equals(obj2);
  }
  return false;
}

Boolean SignatureToken::Equals(SignatureToken obj) {
  return obj.get_Token() == Token;
}

Boolean SignatureToken::op_Equality(SignatureToken a, SignatureToken b) {
  return a.Equals(b);
}

Boolean SignatureToken::op_Inequality(SignatureToken a, SignatureToken b) {
  return !(a == b);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::SignatureTokenNamespace
