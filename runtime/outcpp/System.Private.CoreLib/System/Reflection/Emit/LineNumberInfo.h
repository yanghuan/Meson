#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
FORWARD(ISymbolDocumentWriter)
FORWARD(ISymbolWriter)
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
namespace System::Private::CoreLib::System {
FORWARD_(Array)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(REDocument)
namespace LineNumberInfoNamespace {
using namespace System::Diagnostics::SymbolStore;
CLASS(LineNumberInfo) : public object {
  public: void ctor();
  public: void AddLineNumberInfo(ISymbolDocumentWriter document, Int32 iOffset, Int32 iStartLine, Int32 iStartColumn, Int32 iEndLine, Int32 iEndColumn);
  private: Int32 FindDocument(ISymbolDocumentWriter document);
  private: void EnsureCapacity();
  public: void EmitLineNumberInfo(ISymbolWriter symWriter);
  private: Int32 m_DocumentCount;
  private: Array<REDocument> m_Documents;
  private: Int32 m_iLastFound;
};
} // namespace LineNumberInfoNamespace
using LineNumberInfo = LineNumberInfoNamespace::LineNumberInfo;
} // namespace System::Private::CoreLib::System::Reflection::Emit
