#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
FORWARD(ISymbolWriter)
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
namespace System::Private::CoreLib::System::Reflection::Emit {
enum class ScopeAction : int8_t;
FORWARD(LocalSymInfo)
namespace ScopeTreeNamespace {
using namespace System::Diagnostics::SymbolStore;
CLASS(ScopeTree) : public Object::in {
  public: void ctor();
  public: Int32 GetCurrentActiveScopeIndex();
  public: void AddLocalSymInfoToCurrentScope(String strName, Array<Byte> signature, Int32 slot, Int32 startOffset, Int32 endOffset);
  public: void AddUsingNamespaceToCurrentScope(String strNamespace);
  public: void AddScopeInfo(ScopeAction sa, Int32 iOffset);
  public: void EnsureCapacity();
  public: void EmitScopeTree(ISymbolWriter symWriter);
  public: Array<Int32> m_iOffsets;
  public: Array<ScopeAction> m_ScopeActions;
  public: Int32 m_iCount;
  public: Int32 m_iOpenScopeCount;
  public: Array<LocalSymInfo> m_localSymInfos;
};
} // namespace ScopeTreeNamespace
using ScopeTree = ScopeTreeNamespace::ScopeTree;
} // namespace System::Private::CoreLib::System::Reflection::Emit
