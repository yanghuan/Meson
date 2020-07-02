#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARDS(Guid)
FORWARDS(UInt32)
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(AsyncCallback)
FORWARD(Object)
FORWARD(IAsyncResult)
FORWARD(String)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
FORWARD(ISymbolWriter)
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(PunkSafeHandle)
namespace SymWrapperCoreNamespace {
using namespace ::System::Private::CoreLib::System::Diagnostics::SymbolStore;
CLASS(SymWrapperCore) {
  private: CLASS(SymDocumentWriter) {
    private: struct ISymUnmanagedDocumentWriter {
      public: IntPtr m_unmanagedVTable;
    };
    private: CLASS(DSetCheckSum) {
      public: Int32 Invoke(ISymUnmanagedDocumentWriter* pThis, Guid algorithmId, UInt32 checkSumSize, Array<Byte> checkSum);
      public: IAsyncResult BeginInvoke(ISymUnmanagedDocumentWriter* pThis, Guid algorithmId, UInt32 checkSumSize, Array<Byte> checkSum, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: struct ISymUnmanagedDocumentWriterVTable {
      public: IntPtr QueryInterface;
      public: IntPtr AddRef;
      public: IntPtr Release;
      public: IntPtr SetSource;
      public: DSetCheckSum SetCheckSum;
    };
    public: PunkSafeHandle GetUnmanaged();
    private: PunkSafeHandle m_pDocumentWriterSafeHandle;
    private: ISymUnmanagedDocumentWriter* m_pDocWriter;
    private: ISymUnmanagedDocumentWriterVTable m_vtable;
  };
  public: CLASS(SymWriter) {
    private: struct ISymUnmanagedWriter {
      public: IntPtr m_unmanagedVTable;
    };
    private: CLASS(DInitialize) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, IntPtr emitter, String filename, IntPtr pIStream, Boolean fFullBuild);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, IntPtr emitter, String filename, IntPtr pIStream, Boolean fFullBuild, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DDefineDocument) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, String url, Guid& language, Guid& languageVender, Guid& documentType, PunkSafeHandle& ppsymUnmanagedDocumentWriter);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, String url, Guid& language, Guid& languageVender, Guid& documentType, PunkSafeHandle& ppsymUnmanagedDocumentWriter, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(Guid& language, Guid& languageVender, Guid& documentType, PunkSafeHandle& ppsymUnmanagedDocumentWriter, IAsyncResult result);
    };
    private: CLASS(DSetUserEntryPoint) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 entryMethod);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, Int32 entryMethod, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DOpenMethod) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 entryMethod);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, Int32 entryMethod, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DCloseMethod) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DDefineSequencePoints) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, PunkSafeHandle document, Int32 spCount, Array<Int32> offsets, Array<Int32> lines, Array<Int32> columns, Array<Int32> endLines, Array<Int32> endColumns);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, PunkSafeHandle document, Int32 spCount, Array<Int32> offsets, Array<Int32> lines, Array<Int32> columns, Array<Int32> endLines, Array<Int32> endColumns, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DOpenScope) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 startOffset, Int32& pretval);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, Int32 startOffset, Int32& pretval, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(Int32& pretval, IAsyncResult result);
    };
    private: CLASS(DCloseScope) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 endOffset);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, Int32 endOffset, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DSetScopeRange) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 scopeID, Int32 startOffset, Int32 endOffset);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, Int32 scopeID, Int32 startOffset, Int32 endOffset, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DDefineLocalVariable) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, String name, Int32 attributes, Int32 cSig, Array<Byte> signature, Int32 addrKind, Int32 addr1, Int32 addr2, Int32 addr3, Int32 startOffset, Int32 endOffset);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, String name, Int32 attributes, Int32 cSig, Array<Byte> signature, Int32 addrKind, Int32 addr1, Int32 addr2, Int32 addr3, Int32 startOffset, Int32 endOffset, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DClose) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DSetSymAttribute) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 parent, String name, Int32 cData, Array<Byte> data);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, Int32 parent, String name, Int32 cData, Array<Byte> data, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DOpenNamespace) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, String name);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, String name, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DCloseNamespace) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: CLASS(DUsingNamespace) {
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, String name);
      public: IAsyncResult BeginInvoke(ISymUnmanagedWriter* pthis, String name, AsyncCallback callback, Object object);
      public: Int32 EndInvoke(IAsyncResult result);
    };
    private: struct ISymUnmanagedWriterVTable {
      public: IntPtr QueryInterface;
      public: IntPtr AddRef;
      public: IntPtr Release;
      public: DDefineDocument DefineDocument;
      public: DSetUserEntryPoint SetUserEntryPoint;
      public: DOpenMethod OpenMethod;
      public: DCloseMethod CloseMethod;
      public: DOpenScope OpenScope;
      public: DCloseScope CloseScope;
      public: DSetScopeRange SetScopeRange;
      public: DDefineLocalVariable DefineLocalVariable;
      public: IntPtr DefineParameter;
      public: IntPtr DefineField;
      public: IntPtr DefineGlobalVariable;
      public: DClose Close;
      public: DSetSymAttribute SetSymAttribute;
      public: DOpenNamespace OpenNamespace;
      public: DCloseNamespace CloseNamespace;
      public: DUsingNamespace UsingNamespace;
      public: IntPtr SetMethodSourceRange;
      public: DInitialize Initialize;
      public: IntPtr GetDebugInfo;
      public: DDefineSequencePoints DefineSequencePoints;
    };
    public: static ISymbolWriter CreateSymWriter();
    public: void InternalSetUnderlyingWriter(IntPtr ppUnderlyingWriter);
    private: ISymUnmanagedWriter* m_pWriter;
    private: ISymUnmanagedWriterVTable m_vtable;
  };
};
} // namespace SymWrapperCoreNamespace
using SymWrapperCore = SymWrapperCoreNamespace::SymWrapperCore;
} // namespace System::Private::CoreLib::System::Reflection::Emit
