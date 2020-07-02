#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
namespace SymbolTokenNamespace {
struct SymbolToken {
  public: Int32 GetToken();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(SymbolToken obj);
  public: Int32 m_token;
};
} // namespace SymbolTokenNamespace
using SymbolToken = SymbolTokenNamespace::SymbolToken;
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
