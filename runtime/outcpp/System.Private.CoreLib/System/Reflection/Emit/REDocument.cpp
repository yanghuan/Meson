#include "REDocument-dep.h"

#include <System.Private.CoreLib/System/Array-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::REDocumentNamespace {
void REDocument___::ctor(ISymbolDocumentWriter document) {
  m_iLineNumberCount = 0;
  m_document = document;
}

void REDocument___::AddLineNumberInfo(ISymbolDocumentWriter document, Int32 iOffset, Int32 iStartLine, Int32 iStartColumn, Int32 iEndLine, Int32 iEndColumn) {
  EnsureCapacity();
  m_iOffsets[m_iLineNumberCount] = iOffset;
  m_iLines[m_iLineNumberCount] = iStartLine;
  m_iColumns[m_iLineNumberCount] = iStartColumn;
  m_iEndLines[m_iLineNumberCount] = iEndLine;
  m_iEndColumns[m_iLineNumberCount] = iEndColumn;
}

void REDocument___::EnsureCapacity() {
  if (m_iLineNumberCount == 0) {
    m_iOffsets = rt::newarr<Array<Int32>>(16);
    m_iLines = rt::newarr<Array<Int32>>(16);
    m_iColumns = rt::newarr<Array<Int32>>(16);
    m_iEndLines = rt::newarr<Array<Int32>>(16);
    m_iEndColumns = rt::newarr<Array<Int32>>(16);
  } else if (m_iLineNumberCount == m_iOffsets->get_Length()) {
    Int32 num = m_iLineNumberCount * 2;
    Array<Int32> array = rt::newarr<Array<Int32>>(num);
    Array<>::in::Copy(m_iOffsets, array, m_iLineNumberCount);
    m_iOffsets = array;
    array = rt::newarr<Array<Int32>>(num);
    Array<>::in::Copy(m_iLines, array, m_iLineNumberCount);
    m_iLines = array;
    array = rt::newarr<Array<Int32>>(num);
    Array<>::in::Copy(m_iColumns, array, m_iLineNumberCount);
    m_iColumns = array;
    array = rt::newarr<Array<Int32>>(num);
    Array<>::in::Copy(m_iEndLines, array, m_iLineNumberCount);
    m_iEndLines = array;
    array = rt::newarr<Array<Int32>>(num);
    Array<>::in::Copy(m_iEndColumns, array, m_iLineNumberCount);
    m_iEndColumns = array;
  }

}

void REDocument___::EmitLineNumberInfo(ISymbolWriter symWriter) {
  if (m_iLineNumberCount != 0) {
    Array<Int32> array = rt::newarr<Array<Int32>>(m_iLineNumberCount);
    Array<>::in::Copy(m_iOffsets, array, m_iLineNumberCount);
    Array<Int32> array2 = rt::newarr<Array<Int32>>(m_iLineNumberCount);
    Array<>::in::Copy(m_iLines, array2, m_iLineNumberCount);
    Array<Int32> array3 = rt::newarr<Array<Int32>>(m_iLineNumberCount);
    Array<>::in::Copy(m_iColumns, array3, m_iLineNumberCount);
    Array<Int32> array4 = rt::newarr<Array<Int32>>(m_iLineNumberCount);
    Array<>::in::Copy(m_iEndLines, array4, m_iLineNumberCount);
    Array<Int32> array5 = rt::newarr<Array<Int32>>(m_iLineNumberCount);
    Array<>::in::Copy(m_iEndColumns, array5, m_iLineNumberCount);
    symWriter->DefineSequencePoints(m_document, array, array2, array3, array4, array5);
  }
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::REDocumentNamespace
