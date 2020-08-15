#include "ScopeTree-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/LocalSymInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ScopeAction.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::ScopeTreeNamespace {
void ScopeTree___::ctor() {
  m_iOpenScopeCount = 0;
  m_iCount = 0;
}

Int32 ScopeTree___::GetCurrentActiveScopeIndex() {
  if (m_iCount == 0) {
    return -1;
  }
  Int32 num = m_iCount - 1;
  Int32 num2 = 0;
  while (num2 > 0 || m_ScopeActions[num] == ScopeAction::Close) {
    num2 += (Int32)m_ScopeActions[num];
    num--;
  }
  return num;
}

void ScopeTree___::AddLocalSymInfoToCurrentScope(String strName, Array<Byte> signature, Int32 slot, Int32 startOffset, Int32 endOffset) {
  Int32 currentActiveScopeIndex = GetCurrentActiveScopeIndex();
  Array<LocalSymInfo> localSymInfos = m_localSymInfos;
  Int32 num = currentActiveScopeIndex;
  if (localSymInfos[num] == nullptr) {
    localSymInfos[num] = rt::newobj<LocalSymInfo>();
  }
  m_localSymInfos[currentActiveScopeIndex]->AddLocalSymInfo(strName, signature, slot, startOffset, endOffset);
}

void ScopeTree___::AddUsingNamespaceToCurrentScope(String strNamespace) {
  Int32 currentActiveScopeIndex = GetCurrentActiveScopeIndex();
  Array<LocalSymInfo> localSymInfos = m_localSymInfos;
  Int32 num = currentActiveScopeIndex;
  if (localSymInfos[num] == nullptr) {
    localSymInfos[num] = rt::newobj<LocalSymInfo>();
  }
  m_localSymInfos[currentActiveScopeIndex]->AddUsingNamespace(strNamespace);
}

void ScopeTree___::AddScopeInfo(ScopeAction sa, Int32 iOffset) {
  if (sa == ScopeAction::Close && m_iOpenScopeCount <= 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_UnmatchingSymScope());
  }
  EnsureCapacity();
  m_ScopeActions[m_iCount] = sa;
  m_iOffsets[m_iCount] = iOffset;
  m_localSymInfos[m_iCount] = nullptr;
  {
    m_iCount++;
  }
  m_iOpenScopeCount += 0 - sa;
}

void ScopeTree___::EnsureCapacity() {
  if (m_iCount == 0) {
    m_iOffsets = rt::newarr<Array<Int32>>(16);
    m_ScopeActions = rt::newarr<Array<ScopeAction>>(16);
    m_localSymInfos = rt::newarr<Array<LocalSymInfo>>(16);
  } else if (m_iCount == m_iOffsets->get_Length()) {
    Int32 num = m_iCount * 2;
    Array<Int32> array = rt::newarr<Array<Int32>>(num);
    Array<>::in::Copy(m_iOffsets, array, m_iCount);
    m_iOffsets = array;
    Array<ScopeAction> array2 = rt::newarr<Array<ScopeAction>>(num);
    Array<>::in::Copy(m_ScopeActions, array2, m_iCount);
    m_ScopeActions = array2;
    Array<LocalSymInfo> array3 = rt::newarr<Array<LocalSymInfo>>(num);
    Array<>::in::Copy(m_localSymInfos, array3, m_iCount);
    m_localSymInfos = array3;
  }

}

void ScopeTree___::EmitScopeTree(ISymbolWriter symWriter) {
  for (Int32 i = 0; i < m_iCount; i++) {
    if (m_ScopeActions[i] == ScopeAction::Open) {
      symWriter->OpenScope(m_iOffsets[i]);
    } else {
      symWriter->CloseScope(m_iOffsets[i]);
    }
    if (m_localSymInfos[i] != nullptr) {
      m_localSymInfos[i]->EmitLocalSymInfo(symWriter);
    }
  }
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::ScopeTreeNamespace
