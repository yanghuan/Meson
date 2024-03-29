#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/MulticastDelegate.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System::Diagnostics::SymbolStore {
enum class SymAddressKind : int32_t;
FORWARD(ISymbolDocumentWriter)
FORWARD(ISymbolWriter)
FORWARDS(SymbolToken)
} // namespace System::Private::CoreLib::System::Diagnostics::SymbolStore
namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARD(String)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class FieldAttributes : int32_t;
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
FORWARD(PunkSafeHandle)
namespace SymWrapperCoreNamespace {
using namespace System::Diagnostics::SymbolStore;
CLASS(SymWrapperCore) : public object {
  private: CLASS(SymDocumentWriter) : public object {
    public: using interface = rt::TypeList<ISymbolDocumentWriter>;
    private: struct ISymUnmanagedDocumentWriter : public valueType<ISymUnmanagedDocumentWriter> {
      public: IntPtr m_unmanagedVTable;
    };
    private: CLASS(DSetCheckSum) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedDocumentWriter* pThis, Guid algorithmId, UInt32 checkSumSize, Array<Byte> checkSum);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: struct ISymUnmanagedDocumentWriterVTable : public valueType<ISymUnmanagedDocumentWriterVTable> {
      public: IntPtr QueryInterface;
      public: IntPtr AddRef;
      public: IntPtr Release;
      public: IntPtr SetSource;
      public: DSetCheckSum SetCheckSum;
    };
    public: void ctor(PunkSafeHandle pDocumentWriterSafeHandle);
    public: PunkSafeHandle GetUnmanaged();
    private: void SetSourceOfISymbolDocumentWriter(Array<Byte> source);
    private: void SetCheckSumOfISymbolDocumentWriter(Guid algorithmId, Array<Byte> checkSum);
    private: PunkSafeHandle m_pDocumentWriterSafeHandle;
    private: ISymUnmanagedDocumentWriter* m_pDocWriter;
    private: ISymUnmanagedDocumentWriterVTable m_vtable;
  };
  public: CLASS(SymWriter) : public object {
    public: using interface = rt::TypeList<ISymbolWriter>;
    private: struct ISymUnmanagedWriter : public valueType<ISymUnmanagedWriter> {
      public: IntPtr m_unmanagedVTable;
    };
    private: CLASS(DInitialize) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, IntPtr emitter, String filename, IntPtr pIStream, Boolean fFullBuild);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DDefineDocument) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, String url, Guid& language, Guid& languageVender, Guid& documentType, PunkSafeHandle& ppsymUnmanagedDocumentWriter);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DSetUserEntryPoint) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 entryMethod);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DOpenMethod) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 entryMethod);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DCloseMethod) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DDefineSequencePoints) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, PunkSafeHandle document, Int32 spCount, Array<Int32> offsets, Array<Int32> lines, Array<Int32> columns, Array<Int32> endLines, Array<Int32> endColumns);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DOpenScope) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 startOffset, Int32& pretval);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DCloseScope) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 endOffset);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DSetScopeRange) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 scopeID, Int32 startOffset, Int32 endOffset);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DDefineLocalVariable) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, String name, Int32 attributes, Int32 cSig, Array<Byte> signature, Int32 addrKind, Int32 addr1, Int32 addr2, Int32 addr3, Int32 startOffset, Int32 endOffset);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DClose) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DSetSymAttribute) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, Int32 parent, String name, Int32 cData, Array<Byte> data);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DOpenNamespace) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, String name);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DCloseNamespace) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: CLASS(DUsingNamespace) : public MulticastDelegate::in {
      public: void ctor(Object object, IntPtr method);
      public: Int32 Invoke(ISymUnmanagedWriter* pthis, String name);
      public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
    };
    private: struct ISymUnmanagedWriterVTable : public valueType<ISymUnmanagedWriterVTable> {
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
    public: void ctor();
    private: ISymbolDocumentWriter DefineDocumentOfISymbolWriter(String url, Guid language, Guid languageVendor, Guid documentType);
    private: void OpenMethodOfISymbolWriter(SymbolToken method);
    private: void CloseMethodOfISymbolWriter();
    private: void DefineSequencePointsOfISymbolWriter(ISymbolDocumentWriter document, Array<Int32> offsets, Array<Int32> lines, Array<Int32> columns, Array<Int32> endLines, Array<Int32> endColumns);
    private: Int32 OpenScopeOfISymbolWriter(Int32 startOffset);
    private: void CloseScopeOfISymbolWriter(Int32 endOffset);
    private: void DefineLocalVariableOfISymbolWriter(String name, FieldAttributes attributes, Array<Byte> signature, SymAddressKind addrKind, Int32 addr1, Int32 addr2, Int32 addr3, Int32 startOffset, Int32 endOffset);
    private: void UsingNamespaceOfISymbolWriter(String name);
    public: void InternalSetUnderlyingWriter(IntPtr ppUnderlyingWriter);
    private: ISymUnmanagedWriter* m_pWriter;
    private: ISymUnmanagedWriterVTable m_vtable;
  };
};
} // namespace SymWrapperCoreNamespace
using SymWrapperCore = SymWrapperCoreNamespace::SymWrapperCore;
} // namespace System::Private::CoreLib::System::Reflection::Emit
