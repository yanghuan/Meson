#include "LineNumberInfo-dep.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/REDocument-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::LineNumberInfoNamespace {
void LineNumberInfo___::ctor() {
  m_DocumentCount = 0;
  m_iLastFound = 0;
}

void LineNumberInfo___::AddLineNumberInfo(ISymbolDocumentWriter document, Int32 iOffset, Int32 iStartLine, Int32 iStartColumn, Int32 iEndLine, Int32 iEndColumn) {
  Int32 num = FindDocument(document);
  m_Documents[num]->AddLineNumberInfo(document, iOffset, iStartLine, iStartColumn, iEndLine, iEndColumn);
}

Int32 LineNumberInfo___::FindDocument(ISymbolDocumentWriter document) {
  if (m_iLastFound < m_DocumentCount && m_Documents[m_iLastFound]->m_document == document) {
    return m_iLastFound;
  }
  for (Int32 i = 0; i < m_DocumentCount; i++) {
    if (m_Documents[i]->m_document == document) {
      m_iLastFound = i;
      return m_iLastFound;
    }
  }
  EnsureCapacity();
  m_iLastFound = m_DocumentCount;
  m_Documents[m_iLastFound] = rt::newobj<REDocument>(document);
}

void LineNumberInfo___::EnsureCapacity() {
  if (m_DocumentCount == 0) {
    m_Documents = rt::newarr<Array<REDocument>>(16);
  } else if (m_DocumentCount == m_Documents->get_Length()) {
    Array<REDocument> array = rt::newarr<Array<REDocument>>(m_DocumentCount * 2);
    Array<>::in::Copy(m_Documents, array, m_DocumentCount);
    m_Documents = array;
  }

}

void LineNumberInfo___::EmitLineNumberInfo(ISymbolWriter symWriter) {
  for (Int32 i = 0; i < m_DocumentCount; i++) {
    m_Documents[i]->EmitLineNumberInfo(symWriter);
  }
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::LineNumberInfoNamespace
