#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARDS(Char)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Security {
FORWARD(SafeBSTRHandle)
namespace SecureStringNamespace {
CLASS(SecureString) {
  public: Int32 get_Length();
  public: void AppendChar(Char c);
  public: void Clear();
  public: SecureString Copy();
  public: void Dispose();
  public: void InsertAt(Int32 index, Char c);
  public: Boolean IsReadOnly();
  public: void MakeReadOnly();
  public: void RemoveAt(Int32 index);
  public: void SetAt(Int32 index, Char c);
  private: void EnsureNotReadOnly();
  private: void EnsureNotDisposed();
  public: IntPtr MarshalToBSTR();
  public: IntPtr MarshalToString(Boolean globalAlloc, Boolean unicode);
  private: static void MarshalFree(IntPtr ptr, Boolean globalAlloc);
  private: void InitializeSecureString(Char* value, Int32 length);
  private: void AppendCharCore(Char c);
  private: void ClearCore();
  private: void DisposeCore();
  private: void InsertAtCore(Int32 index, Char c);
  private: void RemoveAtCore(Int32 index);
  private: void SetAtCore(Int32 index, Char c);
  public: IntPtr MarshalToBSTRCore();
  public: IntPtr MarshalToStringCore(Boolean globalAlloc, Boolean unicode);
  private: void AllocateBuffer(UInt32 size);
  private: static UInt32 GetAlignedSize(UInt32 size);
  private: void EnsureCapacity(Int32 capacity);
  private: void ProtectMemory();
  private: void UnprotectMemory();
  private: Object _methodLock;
  private: Boolean _readOnly;
  private: Int32 _decryptedLength;
  private: SafeBSTRHandle _buffer;
  private: Boolean _encrypted;
};
} // namespace SecureStringNamespace
using SecureString = SecureStringNamespace::SecureString;
} // namespace System::Private::CoreLib::System::Security
