#include "SymWrapperCore-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SymWrapperCore-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::SymWrapperCoreNamespace {
using namespace System::Runtime::InteropServices;

void SymWrapperCore___::SymDocumentWriter___::ctor(PunkSafeHandle pDocumentWriterSafeHandle) {
  m_pDocumentWriterSafeHandle = pDocumentWriterSafeHandle;
  m_pDocWriter = (ISymUnmanagedDocumentWriter*)(void*)m_pDocumentWriterSafeHandle->DangerousGetHandle();
  m_vtable = (ISymUnmanagedDocumentWriterVTable)Marshal::PtrToStructure(m_pDocWriter->m_unmanagedVTable, typeof<ISymUnmanagedDocumentWriterVTable>());
}

PunkSafeHandle SymWrapperCore___::SymDocumentWriter___::GetUnmanaged() {
  return m_pDocumentWriterSafeHandle;
}

void SymWrapperCore___::SymDocumentWriter___::SetSourceOfISymbolDocumentWriter(Array<Byte> source) {
  rt::throw_exception<NotSupportedException>();
}

void SymWrapperCore___::SymDocumentWriter___::SetCheckSumOfISymbolDocumentWriter(Guid algorithmId, Array<Byte> checkSum) {
  Int32 num = m_vtable.SetCheckSum(m_pDocWriter, algorithmId, (UInt32)checkSum->get_Length(), checkSum);
  if (num < 0) {
    rt::throw_exception(Marshal::GetExceptionForHR(num));
  }
}

ISymbolWriter SymWrapperCore___::SymWriter___::CreateSymWriter() {
  return rt::newobj<SymWriter>();
}

void SymWrapperCore___::SymWriter___::ctor() {
}

ISymbolDocumentWriter SymWrapperCore___::SymWriter___::DefineDocumentOfISymbolWriter(String url, Guid language, Guid languageVendor, Guid documentType) {
  PunkSafeHandle ppsymUnmanagedDocumentWriter;
  Int32 num = m_vtable.DefineDocument(m_pWriter, url, language, languageVendor, documentType, ppsymUnmanagedDocumentWriter);
  if (num < 0) {
    rt::throw_exception(Marshal::GetExceptionForHR(num));
  }
  if (ppsymUnmanagedDocumentWriter->get_IsInvalid()) {
    return nullptr;
  }
  return rt::newobj<SymDocumentWriter>(ppsymUnmanagedDocumentWriter);
}

void SymWrapperCore___::SymWriter___::OpenMethodOfISymbolWriter(SymbolToken method) {
  Int32 num = m_vtable.OpenMethod(m_pWriter, method.GetToken());
  if (num < 0) {
    rt::throw_exception(Marshal::GetExceptionForHR(num));
  }
}

void SymWrapperCore___::SymWriter___::CloseMethodOfISymbolWriter() {
  Int32 num = m_vtable.CloseMethod(m_pWriter);
  if (num < 0) {
    rt::throw_exception(Marshal::GetExceptionForHR(num));
  }
}

void SymWrapperCore___::SymWriter___::DefineSequencePointsOfISymbolWriter(ISymbolDocumentWriter document, Array<Int32> offsets, Array<Int32> lines, Array<Int32> columns, Array<Int32> endLines, Array<Int32> endColumns) {
  Int32 num = 0;
  if (offsets != nullptr) {
    num = offsets->get_Length();
  } else if (lines != nullptr) {
    num = lines->get_Length();
  } else if (columns != nullptr) {
    num = columns->get_Length();
  } else if (endLines != nullptr) {
    num = endLines->get_Length();
  } else if (endColumns != nullptr) {
    num = endColumns->get_Length();
  }




  if (num != 0) {
    if ((offsets != nullptr && offsets->get_Length() != num) || (lines != nullptr && lines->get_Length() != num) || (columns != nullptr && columns->get_Length() != num) || (endLines != nullptr && endLines->get_Length() != num) || (endColumns != nullptr && endColumns->get_Length() != num)) {
      rt::throw_exception<ArgumentException>();
    }
    SymDocumentWriter symDocumentWriter = (SymDocumentWriter)document;
    Int32 num2 = m_vtable.DefineSequencePoints(m_pWriter, symDocumentWriter->GetUnmanaged(), num, offsets, lines, columns, endLines, endColumns);
    if (num2 < 0) {
      rt::throw_exception(Marshal::GetExceptionForHR(num2));
    }
  }
}

Int32 SymWrapperCore___::SymWriter___::OpenScopeOfISymbolWriter(Int32 startOffset) {
  Int32 pretval;
  Int32 num = m_vtable.OpenScope(m_pWriter, startOffset, pretval);
  if (num < 0) {
    rt::throw_exception(Marshal::GetExceptionForHR(num));
  }
  return pretval;
}

void SymWrapperCore___::SymWriter___::CloseScopeOfISymbolWriter(Int32 endOffset) {
  Int32 num = m_vtable.CloseScope(m_pWriter, endOffset);
  if (num < 0) {
    rt::throw_exception(Marshal::GetExceptionForHR(num));
  }
}

void SymWrapperCore___::SymWriter___::DefineLocalVariableOfISymbolWriter(String name, FieldAttributes attributes, Array<Byte> signature, SymAddressKind addrKind, Int32 addr1, Int32 addr2, Int32 addr3, Int32 startOffset, Int32 endOffset) {
  Int32 num = m_vtable.DefineLocalVariable(m_pWriter, name, (Int32)attributes, signature->get_Length(), signature, (Int32)addrKind, addr1, addr2, addr3, startOffset, endOffset);
  if (num < 0) {
    rt::throw_exception(Marshal::GetExceptionForHR(num));
  }
}

void SymWrapperCore___::SymWriter___::UsingNamespaceOfISymbolWriter(String name) {
  Int32 num = m_vtable.UsingNamespace(m_pWriter, name);
  if (num < 0) {
    rt::throw_exception(Marshal::GetExceptionForHR(num));
  }
}

void SymWrapperCore___::SymWriter___::InternalSetUnderlyingWriter(IntPtr ppUnderlyingWriter) {
  m_pWriter = (ISymUnmanagedWriter*)(*(IntPtr*)(void*)ppUnderlyingWriter);
  m_vtable = (ISymUnmanagedWriterVTable)Marshal::PtrToStructure(m_pWriter->m_unmanagedVTable, typeof<ISymUnmanagedWriterVTable>());
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::SymWrapperCoreNamespace
