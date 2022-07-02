#include "UnmanagedMemoryStream-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ArraySegment-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/Error-dep.h>
#include <System.Private.CoreLib/System/IO/FileAccess.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/UnmanagedMemoryStream-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::IO::UnmanagedMemoryStreamNamespace {
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

Boolean UnmanagedMemoryStream___::get_CanRead() {
  if (_isOpen) {
    return (_access & FileAccess::Read) != 0;
  }
  return false;
}

Boolean UnmanagedMemoryStream___::get_CanSeek() {
  return _isOpen;
}

Boolean UnmanagedMemoryStream___::get_CanWrite() {
  if (_isOpen) {
    return (_access & FileAccess::Write) != 0;
  }
  return false;
}

Int64 UnmanagedMemoryStream___::get_Length() {
  EnsureNotClosed();
  return Interlocked::Read(_length);
}

Int64 UnmanagedMemoryStream___::get_Capacity() {
  EnsureNotClosed();
  return _capacity;
}

Int64 UnmanagedMemoryStream___::get_Position() {
  if (!get_CanSeek()) {
    rt::throw_exception(Error::GetStreamIsClosed());
  }
  return Interlocked::Read(_position);
}

void UnmanagedMemoryStream___::set_Position(Int64 value) {
  if (value < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (!get_CanSeek()) {
    rt::throw_exception(Error::GetStreamIsClosed());
  }
  Interlocked::Exchange(_position, value);
}

Byte* UnmanagedMemoryStream___::get_PositionPointer() {
  if (_buffer != nullptr) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UmsSafeBuffer());
  }
  EnsureNotClosed();
  Int64 num = Interlocked::Read(_position);
  if (num > _capacity) {
    rt::throw_exception<IndexOutOfRangeException>(SR::get_IndexOutOfRange_UMSPosition());
  }
  return _mem + num;
}

void UnmanagedMemoryStream___::set_PositionPointer(Byte* value) {
  if (_buffer != nullptr) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UmsSafeBuffer());
  }
  EnsureNotClosed();
  if (value < _mem) {
    rt::throw_exception<IOException>(SR::get_IO_SeekBeforeBegin());
  }
  Int64 num = (Int64)value - (Int64)_mem;
  if (num < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_UnmanagedMemStreamLength());
  }
  Interlocked::Exchange(_position, num);
}

void UnmanagedMemoryStream___::ctor() {
}

void UnmanagedMemoryStream___::ctor(SafeBuffer buffer, Int64 offset, Int64 length) {
  Initialize(buffer, offset, length, FileAccess::Read);
}

void UnmanagedMemoryStream___::ctor(SafeBuffer buffer, Int64 offset, Int64 length, FileAccess access) {
  Initialize(buffer, offset, length, access);
}

void UnmanagedMemoryStream___::Initialize(SafeBuffer buffer, Int64 offset, Int64 length, FileAccess access) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer");
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (length < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_ByteLength() < (UInt64)(offset + length)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidSafeBufferOffLen());
  }
  if (access < FileAccess::Read || access > FileAccess::ReadWrite) {
    rt::throw_exception<ArgumentOutOfRangeException>("access");
  }
  if (_isOpen) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CalledTwice());
  }
  Byte* pointer = nullptr;
  try {
    buffer->AcquirePointer(pointer);
    if (pointer + offset + length < pointer) {
      rt::throw_exception<ArgumentException>(SR::get_ArgumentOutOfRange_UnmanagedMemStreamWrapAround());
    }
  } catch (...) {
  } finally: {
    if (pointer != nullptr) {
      buffer->ReleasePointer();
    }
  }
  _offset = offset;
  _buffer = buffer;
  _length = length;
  _capacity = length;
  _access = access;
  _isOpen = true;
}

void UnmanagedMemoryStream___::ctor(Byte* pointer, Int64 length) {
  Initialize(pointer, length, length, FileAccess::Read);
}

void UnmanagedMemoryStream___::ctor(Byte* pointer, Int64 length, Int64 capacity, FileAccess access) {
  Initialize(pointer, length, capacity, access);
}

void UnmanagedMemoryStream___::Initialize(Byte* pointer, Int64 length, Int64 capacity, FileAccess access) {
  if (pointer == nullptr) {
    rt::throw_exception<ArgumentNullException>("pointer");
  }
  if (length < 0 || capacity < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((length < 0) ? "length" : "capacity", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (length > capacity) {
    rt::throw_exception<ArgumentOutOfRangeException>("length", SR::get_ArgumentOutOfRange_LengthGreaterThanCapacity());
  }
  if ((UInt64)(UIntPtr)(void*)((Int64)pointer + capacity) < (UInt64)pointer) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::get_ArgumentOutOfRange_UnmanagedMemStreamWrapAround());
  }
  if (access < FileAccess::Read || access > FileAccess::ReadWrite) {
    rt::throw_exception<ArgumentOutOfRangeException>("access", SR::get_ArgumentOutOfRange_Enum());
  }
  if (_isOpen) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_CalledTwice());
  }
  _mem = pointer;
  _offset = 0;
  _length = length;
  _capacity = capacity;
  _access = access;
  _isOpen = true;
}

void UnmanagedMemoryStream___::Dispose(Boolean disposing) {
  _isOpen = false;
  _mem = nullptr;
  Stream::in::Dispose(disposing);
}

void UnmanagedMemoryStream___::EnsureNotClosed() {
  if (!_isOpen) {
    rt::throw_exception(Error::GetStreamIsClosed());
  }
}

void UnmanagedMemoryStream___::EnsureReadable() {
  if (!get_CanRead()) {
    rt::throw_exception(Error::GetReadNotSupported());
  }
}

void UnmanagedMemoryStream___::EnsureWriteable() {
  if (!get_CanWrite()) {
    rt::throw_exception(Error::GetWriteNotSupported());
  }
}

void UnmanagedMemoryStream___::Flush() {
  EnsureNotClosed();
}

Task<> UnmanagedMemoryStream___::FlushAsync(CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  try {
    Flush();
    return Task<>::in::get_CompletedTask();
  } catch (Exception exception) {
    return Task<>::in::FromException(exception);
  }
}

Int32 UnmanagedMemoryStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return ReadCore(Span<Byte>(buffer, offset, count));
}

Int32 UnmanagedMemoryStream___::Read(Span<Byte> buffer) {
  if (GetType() == typeof<UnmanagedMemoryStream>()) {
    return ReadCore(buffer);
  }
  return Stream::in::Read(buffer);
}

Int32 UnmanagedMemoryStream___::ReadCore(Span<Byte> buffer) {
  EnsureNotClosed();
  EnsureReadable();
  Int64 num = Interlocked::Read(_position);
  Int64 num2 = Interlocked::Read(_length);
  Int64 num3 = Math::Min(num2 - num, buffer.get_Length());
  if (num3 <= 0) {
    return 0;
  }
  Int32 num4 = (Int32)num3;
  if (num4 < 0) {
    return 0;
  }
  {
    Byte* dest = rt::fixed(&MemoryMarshal::GetReference(buffer));
    if (_buffer != nullptr) {
      Byte* pointer = nullptr;
      try {
        _buffer->AcquirePointer(pointer);
        Buffer::Memcpy(dest, pointer + num + _offset, num4);
      } catch (...) {
      } finally: {
        if (pointer != nullptr) {
          _buffer->ReleasePointer();
        }
      }
    } else {
      Buffer::Memcpy(dest, _mem + num, num4);
    }
  }
  Interlocked::Exchange(_position, num + num3);
  return num4;
}

Task<Int32> UnmanagedMemoryStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled<Int32>(cancellationToken);
  }
  try {
    Int32 num = Read(buffer, offset, count);
    Task<Int32> lastReadTask = _lastReadTask;
    return (lastReadTask != nullptr && lastReadTask->get_Result() == num) ? lastReadTask : (_lastReadTask = Task<>::in::FromResult(num));
  } catch (Exception exception) {
    return Task<>::in::FromException<Int32>(exception);
  }
}

template <>
ValueTask<Int32> UnmanagedMemoryStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>::FromCanceled<Int32>(cancellationToken);
  }
  try {
    ArraySegment<Byte> segment;
    return ValueTask<Int32>(MemoryMarshal::TryGetArray((ReadOnlyMemory<Byte>)buffer, segment) ? Read(segment.get_Array(), segment.get_Offset(), segment.get_Count()) : Read(buffer.get_Span()));
  } catch (Exception exception) {
    return ValueTask<>::FromException<Int32>(exception);
  }
}

Int32 UnmanagedMemoryStream___::ReadByte() {
  EnsureNotClosed();
  EnsureReadable();
  Int64 num = Interlocked::Read(_position);
  Int64 num2 = Interlocked::Read(_length);
  if (num >= num2) {
    return -1;
  }
  Interlocked::Exchange(_position, num + 1);
  if (_buffer != nullptr) {
    Byte* pointer = nullptr;
    try {
      _buffer->AcquirePointer(pointer);
      return (pointer + num)[_offset];
    } catch (...) {
    } finally: {
      if (pointer != nullptr) {
        _buffer->ReleasePointer();
      }
    }
  }
  return *(_mem + num);
}

Int64 UnmanagedMemoryStream___::Seek(Int64 offset, SeekOrigin loc) {
  EnsureNotClosed();
  switch (loc) {
    case SeekOrigin::Begin:
      if (offset < 0) {
        rt::throw_exception<IOException>(SR::get_IO_SeekBeforeBegin());
      }
      Interlocked::Exchange(_position, offset);
      break;
    case SeekOrigin::Current:
      {
        Int64 num2 = Interlocked::Read(_position);
        if (offset + num2 < 0) {
          rt::throw_exception<IOException>(SR::get_IO_SeekBeforeBegin());
        }
        Interlocked::Exchange(_position, offset + num2);
        break;
      }case SeekOrigin::End:
      {
        Int64 num = Interlocked::Read(_length);
        if (num + offset < 0) {
          rt::throw_exception<IOException>(SR::get_IO_SeekBeforeBegin());
        }
        Interlocked::Exchange(_position, num + offset);
        break;
      }default:
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidSeekOrigin());
  }
  return Interlocked::Read(_position);
}

void UnmanagedMemoryStream___::SetLength(Int64 value) {
  if (value < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (_buffer != nullptr) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UmsSafeBuffer());
  }
  EnsureNotClosed();
  EnsureWriteable();
  if (value > _capacity) {
    rt::throw_exception<IOException>(SR::get_IO_FixedCapacity());
  }
  Int64 num = Interlocked::Read(_position);
  Int64 num2 = Interlocked::Read(_length);
  if (value > num2) {
    Buffer::ZeroMemory(_mem + num2, (UIntPtr)(value - num2));
  }
  Interlocked::Exchange(_length, value);
  if (num > value) {
    Interlocked::Exchange(_position, value);
  }
}

void UnmanagedMemoryStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  WriteCore(ReadOnlySpan<Byte>(buffer, offset, count));
}

void UnmanagedMemoryStream___::Write(ReadOnlySpan<Byte> buffer) {
  if (GetType() == typeof<UnmanagedMemoryStream>()) {
    WriteCore(buffer);
  } else {
    Stream::in::Write(buffer);
  }
}

void UnmanagedMemoryStream___::WriteCore(ReadOnlySpan<Byte> buffer) {
  EnsureNotClosed();
  EnsureWriteable();
  Int64 num = Interlocked::Read(_position);
  Int64 num2 = Interlocked::Read(_length);
  Int64 num3 = num + buffer.get_Length();
  if (num3 < 0) {
    rt::throw_exception<IOException>(SR::get_IO_StreamTooLong());
  }
  if (num3 > _capacity) {
    rt::throw_exception<NotSupportedException>(SR::get_IO_FixedCapacity());
  }
  if (_buffer == nullptr) {
    if (num > num2) {
      Buffer::ZeroMemory(_mem + num2, (UIntPtr)(num - num2));
    }
    if (num3 > num2) {
      Interlocked::Exchange(_length, num3);
    }
  }
  {
    Byte* src = rt::fixed(&MemoryMarshal::GetReference(buffer));
    if (_buffer != nullptr) {
      Int64 num4 = _capacity - num;
      if (num4 < buffer.get_Length()) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_BufferTooSmall());
      }
      Byte* pointer = nullptr;
      try {
        _buffer->AcquirePointer(pointer);
        Buffer::Memcpy(pointer + num + _offset, src, buffer.get_Length());
      } catch (...) {
      } finally: {
        if (pointer != nullptr) {
          _buffer->ReleasePointer();
        }
      }
    } else {
      Buffer::Memcpy(_mem + num, src, buffer.get_Length());
    }
  }
  Interlocked::Exchange(_position, num3);
}

Task<> UnmanagedMemoryStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  try {
    Write(buffer, offset, count);
    return Task<>::in::get_CompletedTask();
  } catch (Exception exception) {
    return Task<>::in::FromException(exception);
  }
}

template <>
ValueTask<> UnmanagedMemoryStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>::FromCanceled(cancellationToken);
  }
  try {
    ArraySegment<Byte> segment;
    if (MemoryMarshal::TryGetArray(buffer, segment)) {
      Write(segment.get_Array(), segment.get_Offset(), segment.get_Count());
    } else {
      Write(buffer.get_Span());
    }
    return rt::default__;
  } catch (Exception exception) {
    return ValueTask<>::FromException(exception);
  }
}

void UnmanagedMemoryStream___::WriteByte(Byte value) {
  EnsureNotClosed();
  EnsureWriteable();
  Int64 num = Interlocked::Read(_position);
  Int64 num2 = Interlocked::Read(_length);
  Int64 num3 = num + 1;
  if (num >= num2) {
    if (num3 < 0) {
      rt::throw_exception<IOException>(SR::get_IO_StreamTooLong());
    }
    if (num3 > _capacity) {
      rt::throw_exception<NotSupportedException>(SR::get_IO_FixedCapacity());
    }
    if (_buffer == nullptr) {
      if (num > num2) {
        Buffer::ZeroMemory(_mem + num2, (UIntPtr)(num - num2));
      }
      Interlocked::Exchange(_length, num3);
    }
  }
  if (_buffer != nullptr) {
    Byte* pointer = nullptr;
    try {
      _buffer->AcquirePointer(pointer);
      (pointer + num)[_offset] = value;
    } catch (...) {
    } finally: {
      if (pointer != nullptr) {
        _buffer->ReleasePointer();
      }
    }
  } else {
    *(_mem + num) = value;
  }
  Interlocked::Exchange(_position, num3);
}

} // namespace System::Private::CoreLib::System::IO::UnmanagedMemoryStreamNamespace
