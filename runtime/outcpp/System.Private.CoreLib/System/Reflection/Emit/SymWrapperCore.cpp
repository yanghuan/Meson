#include "SymWrapperCore-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/SymWrapperCore-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::SymWrapperCoreNamespace {
using namespace System::Runtime::InteropServices;

void SymWrapperCore___::SymDocumentWriter___::ctor(PunkSafeHandle pDocumentWriterSafeHandle) {
  m_pDocumentWriterSafeHandle = pDocumentWriterSafeHandle;
  m_pDocWriter = (ISymUnmanagedDocumentWriter*)(void*)m_pDocumentWriterSafeHandle->DangerousGetHandle();
  m_vtable = (ISymUnmanagedDocumentWriterVTable)Marshal::PtrToStructure(m_pDocWriter->m_unmanagedVTable, rt::typeof<ISymUnmanagedDocumentWriterVTable>());
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
  m_vtable = (ISymUnmanagedWriterVTable)Marshal::PtrToStructure(m_pWriter->m_unmanagedVTable, rt::typeof<ISymUnmanagedWriterVTable>());
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::SymWrapperCoreNamespace
