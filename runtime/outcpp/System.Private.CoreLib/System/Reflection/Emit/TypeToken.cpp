#include "TypeToken-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/TypeToken-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::TypeTokenNamespace {
TypeToken::TypeToken(Int32 typeToken) {
  Token = typeToken;
}

Int32 TypeToken::GetHashCode() {
  return Token;
}

Boolean TypeToken::Equals(Object obj) {
  if (rt::is<TypeToken>(obj)) {
    TypeToken obj2 = (TypeToken)obj;
    return Equals(obj2);
  }
  return false;
}

Boolean TypeToken::Equals(TypeToken obj) {
  return obj.get_Token() == Token;
}

Boolean TypeToken::op_Equality(TypeToken a, TypeToken b) {
  return a.Equals(b);
}

Boolean TypeToken::op_Inequality(TypeToken a, TypeToken b) {
  return !(a == b);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::TypeTokenNamespace
