#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeBuffer)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Security {
namespace SecureStringNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
CLASS(SecureString) {
  private: CLASS(UnmanagedBuffer) {
    public: static UnmanagedBuffer Allocate(Int32 byteLength);
    public: static void Copy(UnmanagedBuffer source, UnmanagedBuffer destination, UInt64 bytesLength);
    protected: Boolean ReleaseHandle();
    private: Int32 _byteLength;
  };
  public: Int32 get_Length();
  private: void Initialize(ReadOnlySpan<Char> value);
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
