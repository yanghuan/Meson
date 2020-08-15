#include "LocalSymInfo-dep.h"

#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/SymbolStore/SymAddressKind.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Reflection/FieldAttributes.h>
#include <System.Private.CoreLib/System/String-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::LocalSymInfoNamespace {
using namespace System::Diagnostics::SymbolStore;

void LocalSymInfo___::ctor() {
  m_iLocalSymCount = 0;
  m_iNameSpaceCount = 0;
}

void LocalSymInfo___::EnsureCapacityNamespace() {
  if (m_iNameSpaceCount == 0) {
    m_namespace = rt::newarr<Array<String>>(16);
  } else if (m_iNameSpaceCount == m_namespace->get_Length()) {
    Array<String> array = rt::newarr<Array<String>>(m_iNameSpaceCount * 2);
    Array<>::in::Copy(m_namespace, array, m_iNameSpaceCount);
    m_namespace = array;
  }

}

void LocalSymInfo___::EnsureCapacity() {
  if (m_iLocalSymCount == 0) {
    m_strName = rt::newarr<Array<String>>(16);
    m_ubSignature = rt::newarr<Array<Array<Byte>>>(16);
    m_iLocalSlot = rt::newarr<Array<Int32>>(16);
    m_iStartOffset = rt::newarr<Array<Int32>>(16);
    m_iEndOffset = rt::newarr<Array<Int32>>(16);
  } else if (m_iLocalSymCount == m_strName->get_Length()) {
    Int32 num = m_iLocalSymCount * 2;
    Array<Int32> array = rt::newarr<Array<Int32>>(num);
    Array<>::in::Copy(m_iLocalSlot, array, m_iLocalSymCount);
    m_iLocalSlot = array;
    array = rt::newarr<Array<Int32>>(num);
    Array<>::in::Copy(m_iStartOffset, array, m_iLocalSymCount);
    m_iStartOffset = array;
    array = rt::newarr<Array<Int32>>(num);
    Array<>::in::Copy(m_iEndOffset, array, m_iLocalSymCount);
    m_iEndOffset = array;
    Array<String> array2 = rt::newarr<Array<String>>(num);
    Array<>::in::Copy(m_strName, array2, m_iLocalSymCount);
    m_strName = array2;
    Array<Byte> array3 = rt::newarr<Array<Array<Byte>>>(num);
    Array<>::in::Copy(m_ubSignature, array3, m_iLocalSymCount);
    m_ubSignature = array3;
  }

}

void LocalSymInfo___::AddLocalSymInfo(String strName, Array<Byte> signature, Int32 slot, Int32 startOffset, Int32 endOffset) {
  EnsureCapacity();
  m_iStartOffset[m_iLocalSymCount] = startOffset;
  m_iEndOffset[m_iLocalSymCount] = endOffset;
  m_iLocalSlot[m_iLocalSymCount] = slot;
  m_strName[m_iLocalSymCount] = strName;
  m_ubSignature[m_iLocalSymCount] = signature;
  {
    m_iLocalSymCount++;
  }
}

void LocalSymInfo___::AddUsingNamespace(String strNamespace) {
  EnsureCapacityNamespace();
  m_namespace[m_iNameSpaceCount] = strNamespace;
  {
    m_iNameSpaceCount++;
  }
}

void LocalSymInfo___::EmitLocalSymInfo(ISymbolWriter symWriter) {
  for (Int32 i = 0; i < m_iLocalSymCount; i++) {
    symWriter->DefineLocalVariable(m_strName[i], FieldAttributes::PrivateScope, m_ubSignature[i], SymAddressKind::ILOffset, m_iLocalSlot[i], 0, 0, m_iStartOffset[i], m_iEndOffset[i]);
  }
  for (Int32 i = 0; i < m_iNameSpaceCount; i++) {
    symWriter->UsingNamespace(m_namespace[i]);
  }
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::LocalSymInfoNamespace
