#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/SafeBuffer.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
FORWARD(IDisposable)
FORWARDS(IntPtr)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security {
namespace SecureStringNamespace {
using namespace System::Runtime::InteropServices;
CLASS(SecureString) : public object {
  public: using interface = rt::TypeList<IDisposable>;
  private: CLASS(UnmanagedBuffer) : public SafeBuffer::in {
    public: void ctor();
    public: static UnmanagedBuffer Allocate(Int32 byteLength);
    public: static void Copy(UnmanagedBuffer source, UnmanagedBuffer destination, UInt64 bytesLength);
    protected: Boolean ReleaseHandle();
    private: Int32 _byteLength;
  };
  public: Int32 get_Length();
  public: void ctor();
  public: void ctor(Char* value, Int32 length);
  private: void Initialize(ReadOnlySpan<Char> value);
  public: void ctor(SecureString str);
  private: void EnsureCapacity(Int32 capacity);
  public: void AppendChar(Char c);
  public: void Clear();
  public: SecureString Copy();
  public: void Dispose();
  public: void InsertAt(Int32 index, Char c);
  public: Boolean IsReadOnly();
  public: void MakeReadOnly();
  public: void RemoveAt(Int32 index);
  public: void SetAt(Int32 index, Char c);
  private: Span<Char> AcquireSpan(SafeBuffer& bufferToRelease);
  private: void EnsureNotReadOnly();
  private: void EnsureNotDisposed();
  public: IntPtr MarshalToBSTR();
  public: IntPtr MarshalToString(Boolean globalAlloc, Boolean unicode);
  private: static Int32 GetAlignedByteSize(Int32 length);
  private: void ProtectMemory();
  private: void UnprotectMemory();
  private: Object _methodLock;
  private: UnmanagedBuffer _buffer;
  private: Int32 _decryptedLength;
  private: Boolean _encrypted;
  private: Boolean _readOnly;
};
} // namespace SecureStringNamespace
using SecureString = SecureStringNamespace::SecureString;
} // namespace System::Private::CoreLib::System::Security
