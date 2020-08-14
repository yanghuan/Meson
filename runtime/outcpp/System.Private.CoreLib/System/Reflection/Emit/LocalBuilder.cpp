#include "LocalBuilder-dep.h"

#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/MethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/ModuleBuilder-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SignatureHelper-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::LocalBuilderNamespace {
Boolean LocalBuilder___::get_IsPinned() {
  return m_isPinned;
}

Type LocalBuilder___::get_LocalType() {
  return m_localType;
}

Int32 LocalBuilder___::get_LocalIndex() {
  return m_localIndex;
}

void LocalBuilder___::ctor(Int32 localIndex, Type localType, MethodInfo methodBuilder) {
}

void LocalBuilder___::ctor(Int32 localIndex, Type localType, MethodInfo methodBuilder, Boolean isPinned) {
  m_isPinned = isPinned;
  m_localIndex = localIndex;
  m_localType = localType;
  m_methodBuilder = methodBuilder;
}

Int32 LocalBuilder___::GetLocalIndex() {
  return m_localIndex;
}

MethodInfo LocalBuilder___::GetMethodBuilder() {
  return m_methodBuilder;
}

void LocalBuilder___::SetLocalSymInfo(String name) {
  SetLocalSymInfo(name, 0, 0);
}

void LocalBuilder___::SetLocalSymInfo(String name, Int32 startOffset, Int32 endOffset) {
  MethodBuilder methodBuilder = rt::as<MethodBuilder>(m_methodBuilder);
  if (methodBuilder == nullptr) {
    rt::throw_exception<NotSupportedException>();
  }
  ModuleBuilder moduleBuilder = (ModuleBuilder)methodBuilder->get_Module();
  if (methodBuilder->IsTypeCreated()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_TypeHasBeenCreated());
  }
  if (moduleBuilder->GetSymWriter() == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotADebugModule());
  }
  SignatureHelper fieldSigHelper = SignatureHelper::in::GetFieldSigHelper(moduleBuilder);
  fieldSigHelper->AddArgument(m_localType);
  Int32 length;
  Array<Byte> src = fieldSigHelper->InternalGetSignature(length);
  Array<Byte> array = rt::newarr<Array<Byte>>(length - 1);
  Buffer::BlockCopy(src, 1, array, 0, length - 1);
  Int32 currentActiveScopeIndex = methodBuilder->GetILGenerator()->m_ScopeTree->GetCurrentActiveScopeIndex();
  if (currentActiveScopeIndex == -1) {
    methodBuilder->m_localSymInfo->AddLocalSymInfo(name, array, m_localIndex, startOffset, endOffset);
  } else {
    methodBuilder->GetILGenerator()->m_ScopeTree->AddLocalSymInfoToCurrentScope(name, array, m_localIndex, startOffset, endOffset);
  }
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::LocalBuilderNamespace
