#include "SymbolToken-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/SymbolStore/SymbolToken-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::SymbolStore::SymbolTokenNamespace {
SymbolToken::SymbolToken(Int32 val) {
  m_token = val;
}

Int32 SymbolToken::GetToken() {
  return m_token;
}

Int32 SymbolToken::GetHashCode() {
  return m_token;
}

Boolean SymbolToken::Equals(Object obj) {
  if (rt::is<SymbolToken>(obj)) {
    return Equals((SymbolToken)obj);
  }
  return false;
}

Boolean SymbolToken::Equals(SymbolToken obj) {
  return obj.m_token == m_token;
}

} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore::SymbolTokenNamespace
