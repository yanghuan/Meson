#include "StringToken-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/StringToken-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::StringTokenNamespace {
StringToken::StringToken(Int32 str) {
  Token = str;
}

Int32 StringToken::GetHashCode() {
  return Token;
}

Boolean StringToken::Equals(Object obj) {
  if (rt::is<StringToken>(obj)) {
    StringToken obj2 = (StringToken)obj;
    return Equals(obj2);
  }
  return false;
}

Boolean StringToken::Equals(StringToken obj) {
  return obj.get_Token() == Token;
}

Boolean StringToken::op_Equality(StringToken a, StringToken b) {
  return a.Equals(b);
}

Boolean StringToken::op_Inequality(StringToken a, StringToken b) {
  return !(a == b);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::StringTokenNamespace
