#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
FORWARD(ISymbolWriter)
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace LocalSymInfoNamespace {
using namespace ::System::Private::CoreLib::System::Diagnostics::SymbolStore;
CLASS(LocalSymInfo) {
  private: void EnsureCapacityNamespace();
  private: void EnsureCapacity();
  public: void AddLocalSymInfo(String strName, Array<Byte> signature, Int32 slot, Int32 startOffset, Int32 endOffset);
  public: void AddUsingNamespace(String strNamespace);
  public: void EmitLocalSymInfo(ISymbolWriter symWriter);
  public: Array<String> m_strName;
  public: Array<Array<Byte>> m_ubSignature;
  public: Array<Int32> m_iLocalSlot;
  public: Array<Int32> m_iStartOffset;
  public: Array<Int32> m_iEndOffset;
  public: Int32 m_iLocalSymCount;
  public: Array<String> m_namespace;
  public: Int32 m_iNameSpaceCount;
};
} // namespace LocalSymInfoNamespace
using LocalSymInfo = LocalSymInfoNamespace::LocalSymInfo;
} // namespace System::Private::CoreLib::System::Reflection::Emit
