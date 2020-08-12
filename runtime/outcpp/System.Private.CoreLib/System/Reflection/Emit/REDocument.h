#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
FORWARD(ISymbolDocumentWriter)
FORWARD(ISymbolWriter)
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace REDocumentNamespace {
using namespace System::Diagnostics::SymbolStore;
CLASS(REDocument) : public Object::in {
  public: void ctor(ISymbolDocumentWriter document);
  public: void AddLineNumberInfo(ISymbolDocumentWriter document, Int32 iOffset, Int32 iStartLine, Int32 iStartColumn, Int32 iEndLine, Int32 iEndColumn);
  private: void EnsureCapacity();
  public: void EmitLineNumberInfo(ISymbolWriter symWriter);
  private: Array<Int32> m_iOffsets;
  private: Array<Int32> m_iLines;
  private: Array<Int32> m_iColumns;
  private: Array<Int32> m_iEndLines;
  private: Array<Int32> m_iEndColumns;
  public: ISymbolDocumentWriter m_document;
  private: Int32 m_iLineNumberCount;
};
} // namespace REDocumentNamespace
using REDocument = REDocumentNamespace::REDocument;
} // namespace System::Private::CoreLib::System::Reflection::Emit
