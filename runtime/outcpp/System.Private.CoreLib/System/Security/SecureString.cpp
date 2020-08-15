#include "SecureString-dep.h"

#include <System.Private.CoreLib/Interop-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Security/Cryptography/CryptographicException-dep.h>
#include <System.Private.CoreLib/System/Security/SecureString-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Security::SecureStringNamespace {
using namespace System::Runtime::InteropServices;
using namespace System::Security::Cryptography;
using namespace System::Threading;

void SecureString___::UnmanagedBuffer___::ctor() {
}

SecureString::in::UnmanagedBuffer SecureString___::UnmanagedBuffer___::Allocate(Int32 byteLength) {
  UnmanagedBuffer unmanagedBuffer = rt::newobj<UnmanagedBuffer>();
  unmanagedBuffer->SetHandle(Marshal::AllocHGlobal(byteLength));
  unmanagedBuffer->Initialize((UInt64)byteLength);
  unmanagedBuffer->_byteLength = byteLength;
  return unmanagedBuffer;
}

void SecureString___::UnmanagedBuffer___::Copy(UnmanagedBuffer source, UnmanagedBuffer destination, UInt64 bytesLength) {
  if (bytesLength == 0) {
    return;
  }
  Byte* pointer = nullptr;
  Byte* pointer2 = nullptr;
  try{
    source->AcquirePointer(pointer);
    destination->AcquirePointer(pointer2);
    Buffer::MemoryCopy(pointer, pointer2, destination->get_ByteLength(), bytesLength);
  } finally: {
    if (pointer2 != nullptr) {
      destination->ReleasePointer();
    }
    if (pointer != nullptr) {
      source->ReleasePointer();
    }
  }
}

Boolean SecureString___::UnmanagedBuffer___::ReleaseHandle() {
  Span<Byte>((void*)handle, _byteLength).Clear();
  Marshal::FreeHGlobal(handle);
  return true;
}

Int32 SecureString___::get_Length() {
  EnsureNotDisposed();
  return Volatile::Read(_decryptedLength);
}

void SecureString___::ctor() {
  _methodLock = rt::newobj<Object>();
  Object::in::ctor();
  Initialize(ReadOnlySpan<Char>::get_Empty());
}

void SecureString___::ctor(Char* value, Int32 length) {
  _methodLock = rt::newobj<Object>();
  Object::in::ctor();
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (length > 65536) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_Length());
  }
  Initialize(ReadOnlySpan<Char>(value, length));
}

void SecureString___::Initialize(ReadOnlySpan<Char> value) {
  _buffer = UnmanagedBuffer::in::Allocate(GetAlignedByteSize(value.get_Length()));
  _decryptedLength = value.get_Length();
  SafeBuffer bufferToRelease = nullptr;
  try{
    Span<Char> destination = AcquireSpan(bufferToRelease);
    value.CopyTo(destination);
  } finally: {
    ProtectMemory();
    auto& default = bufferToRelease;
    default == nullptr ? nullptr : default->DangerousRelease();
  }
}

void SecureString___::ctor(SecureString str) {
  _methodLock = rt::newobj<Object>();
  Object::in::ctor();
  _buffer = UnmanagedBuffer::in::Allocate((Int32)str->_buffer->get_ByteLength());
  UnmanagedBuffer::in::Copy(str->_buffer, _buffer, str->_buffer->get_ByteLength());
  _decryptedLength = str->_decryptedLength;
  _encrypted = str->_encrypted;
}

void SecureString___::EnsureCapacity(Int32 capacity) {
  if (capacity > 65536) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::get_ArgumentOutOfRange_Capacity());
  }
  if ((UInt32)(capacity * 2) > _buffer->get_ByteLength()) {
    UnmanagedBuffer buffer = _buffer;
    UnmanagedBuffer unmanagedBuffer = UnmanagedBuffer::in::Allocate(GetAlignedByteSize(capacity));
    UnmanagedBuffer::in::Copy(buffer, unmanagedBuffer, (UInt32)(_decryptedLength * 2));
    _buffer = unmanagedBuffer;
    buffer->Dispose();
  }
}

void SecureString___::AppendChar(Char c) {
  {
    rt::lock(_methodLock);
    EnsureNotDisposed();
    EnsureNotReadOnly();
    SafeBuffer bufferToRelease = nullptr;
    try{
      UnprotectMemory();
      EnsureCapacity(_decryptedLength + 1);
      AcquireSpan(bufferToRelease)[_decryptedLength] = c;
      _decryptedLength++;
    } finally: {
      ProtectMemory();
      auto& default = bufferToRelease;
      default == nullptr ? nullptr : default->DangerousRelease();
    }
  }
}

void SecureString___::Clear() {
  {
    rt::lock(_methodLock);
    EnsureNotDisposed();
    EnsureNotReadOnly();
    _decryptedLength = 0;
    SafeBuffer bufferToRelease = nullptr;
    try{
      AcquireSpan(bufferToRelease).Clear();
    } finally: {
      auto& default = bufferToRelease;
      default == nullptr ? nullptr : default->DangerousRelease();
    }
  }
}

SecureString SecureString___::Copy() {
  {
    rt::lock(_methodLock);
    EnsureNotDisposed();
    return rt::newobj<SecureString>((SecureString)this);
  }
}

void SecureString___::Dispose() {
  {
    rt::lock(_methodLock);
    if (_buffer != nullptr) {
      _buffer->Dispose();
      _buffer = nullptr;
    }
  }
}

void SecureString___::InsertAt(Int32 index, Char c) {
  {
    rt::lock(_methodLock);
    if (index < 0 || index > _decryptedLength) {
      rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_IndexString());
    }
    EnsureNotDisposed();
    EnsureNotReadOnly();
    SafeBuffer bufferToRelease = nullptr;
    try{
      UnprotectMemory();
      EnsureCapacity(_decryptedLength + 1);
      Span<Char> span = AcquireSpan(bufferToRelease);
      span.Slice(index, _decryptedLength - index).CopyTo(span.Slice(index + 1));
      span[index] = c;
      _decryptedLength++;
    } finally: {
      ProtectMemory();
      auto& default = bufferToRelease;
      default == nullptr ? nullptr : default->DangerousRelease();
    }
  }
}

Boolean SecureString___::IsReadOnly() {
  EnsureNotDisposed();
  return Volatile::Read(_readOnly);
}

void SecureString___::MakeReadOnly() {
  EnsureNotDisposed();
  Volatile::Write(_readOnly, true);
}

void SecureString___::RemoveAt(Int32 index) {
  {
    rt::lock(_methodLock);
    if (index < 0 || index >= _decryptedLength) {
      rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_IndexString());
    }
    EnsureNotDisposed();
    EnsureNotReadOnly();
    SafeBuffer bufferToRelease = nullptr;
    try{
      UnprotectMemory();
      Span<Char> span = AcquireSpan(bufferToRelease);
      span.Slice(index + 1, _decryptedLength - (index + 1)).CopyTo(span.Slice(index));
      _decryptedLength--;
    } finally: {
      ProtectMemory();
      auto& default = bufferToRelease;
      default == nullptr ? nullptr : default->DangerousRelease();
    }
  }
}

void SecureString___::SetAt(Int32 index, Char c) {
  {
    rt::lock(_methodLock);
    if (index < 0 || index >= _decryptedLength) {
      rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_IndexString());
    }
    EnsureNotDisposed();
    EnsureNotReadOnly();
    SafeBuffer bufferToRelease = nullptr;
    try{
      UnprotectMemory();
      AcquireSpan(bufferToRelease)[index] = c;
    } finally: {
      ProtectMemory();
      auto& default = bufferToRelease;
      default == nullptr ? nullptr : default->DangerousRelease();
    }
  }
}

Span<Char> SecureString___::AcquireSpan(SafeBuffer& bufferToRelease) {
  SafeBuffer buffer = _buffer;
  Boolean success = false;
  buffer->DangerousAddRef(success);
  bufferToRelease = buffer;
  return Span<Char>((void*)buffer->DangerousGetHandle(), (Int32)(buffer->get_ByteLength() / 2));
}

void SecureString___::EnsureNotReadOnly() {
  if (_readOnly) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ReadOnly());
  }
}

void SecureString___::EnsureNotDisposed() {
  if (_buffer == nullptr) {
    rt::throw_exception<ObjectDisposedException>(GetType()->get_Name());
  }
}

IntPtr SecureString___::MarshalToBSTR() {
  {
    rt::lock(_methodLock);
    EnsureNotDisposed();
    UnprotectMemory();
    SafeBuffer bufferToRelease = nullptr;
    IntPtr intPtr = IntPtr::Zero;
    Int32 length = 0;
    try{
      Span<Char> span = AcquireSpan(bufferToRelease);
      length = _decryptedLength;
      intPtr = Marshal::AllocBSTR(length);
      span.Slice(0, length).CopyTo(Span<Char>((void*)intPtr, length));
      IntPtr result = intPtr;
      intPtr = IntPtr::Zero;
      return result;
    } finally: {
      if (intPtr != IntPtr::Zero) {
        Span<Char>((void*)intPtr, length).Clear();
        Marshal::FreeBSTR(intPtr);
      }
      ProtectMemory();
      auto& default = bufferToRelease;
      default == nullptr ? nullptr : default->DangerousRelease();
    }
  }
}

IntPtr SecureString___::MarshalToString(Boolean globalAlloc, Boolean unicode) {
  {
    rt::lock(_methodLock);
    EnsureNotDisposed();
    UnprotectMemory();
    SafeBuffer bufferToRelease = nullptr;
    IntPtr intPtr = IntPtr::Zero;
    Int32 num = 0;
    try{
      Span<Char> span = AcquireSpan(bufferToRelease).Slice(0, _decryptedLength);
      num = ((!unicode) ? Marshal::GetAnsiStringByteCount(span) : ((span.get_Length() + 1) * 2));
      intPtr = ((!globalAlloc) ? Marshal::AllocCoTaskMem(num) : Marshal::AllocHGlobal(num));
      if (unicode) {
        Span<Char> destination = Span<Char>((void*)intPtr, num / 2);
        span.CopyTo(destination);
        destination[destination.get_Length() - 1] = 0;
      } else {
        Marshal::GetAnsiStringBytes(span, Span<Byte>((void*)intPtr, num));
      }
      IntPtr result = intPtr;
      intPtr = IntPtr::Zero;
      return result;
    } finally: {
      if (intPtr != IntPtr::Zero) {
        Span<Byte>((void*)intPtr, num).Clear();
        if (globalAlloc) {
          Marshal::FreeHGlobal(intPtr);
        } else {
          Marshal::FreeCoTaskMem(intPtr);
        }
      }
      ProtectMemory();
      auto& default = bufferToRelease;
      default == nullptr ? nullptr : default->DangerousRelease();
    }
  }
}

Int32 SecureString___::GetAlignedByteSize(Int32 length) {
  Int32 num = Math::Max(length, 1) * 2;
  return (num + 15) / 16 * 16;
}

void SecureString___::ProtectMemory() {
  if (_decryptedLength != 0 && !_encrypted && !Interop::Crypt32::CryptProtectMemory(_buffer, (UInt32)_buffer->get_ByteLength(), 0u)) {
    rt::throw_exception<CryptographicException>(Marshal::GetLastWin32Error());
  }
  _encrypted = true;
}

void SecureString___::UnprotectMemory() {
  if (_decryptedLength != 0 && _encrypted && !Interop::Crypt32::CryptUnprotectMemory(_buffer, (UInt32)_buffer->get_ByteLength(), 0u)) {
    rt::throw_exception<CryptographicException>(Marshal::GetLastWin32Error());
  }
  _encrypted = false;
}

} // namespace System::Private::CoreLib::System::Security::SecureStringNamespace
