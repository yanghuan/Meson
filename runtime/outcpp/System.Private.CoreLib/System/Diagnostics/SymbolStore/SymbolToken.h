#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
namespace SymbolTokenNamespace {
struct SymbolToken : public valueType<SymbolToken> {
  public: explicit SymbolToken(Int32 val);
  public: Int32 GetToken();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(SymbolToken obj);
  public: explicit SymbolToken() {}
  public: Int32 m_token;
};
} // namespace SymbolTokenNamespace
using SymbolToken = SymbolTokenNamespace::SymbolToken;
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
