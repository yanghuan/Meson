#include "SymWrapperCore-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/SymWrapperCore-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::SymWrapperCoreNamespace {
void SymWrapperCore___::SymDocumentWriter___::ctor(PunkSafeHandle pDocumentWriterSafeHandle) {
  m_pDocumentWriterSafeHandle = pDocumentWriterSafeHandle;
  m_pDocWriter = (ISymUnmanagedDocumentWriter*)(void*)m_pDocumentWriterSafeHandle->DangerousGetHandle();
}

PunkSafeHandle SymWrapperCore___::SymDocumentWriter___::GetUnmanaged() {
  return m_pDocumentWriterSafeHandle;
}

ISymbolWriter SymWrapperCore___::SymWriter___::CreateSymWriter() {
  return rt::newobj<SymWriter>();
}

void SymWrapperCore___::SymWriter___::ctor() {
}

void SymWrapperCore___::SymWriter___::InternalSetUnderlyingWriter(IntPtr ppUnderlyingWriter) {
  m_pWriter = (ISymUnmanagedWriter*)(IntPtr)(*(IntPtr*)(void*)ppUnderlyingWriter);
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::SymWrapperCoreNamespace
