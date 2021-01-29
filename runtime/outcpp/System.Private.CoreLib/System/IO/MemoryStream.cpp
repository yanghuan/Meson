#include "MemoryStream-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/IO/Error-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/MemoryStream-dep.h>
#include <System.Private.CoreLib/System/IO/StreamHelpers-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/OperationCanceledException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UnauthorizedAccessException-dep.h>

namespace System::Private::CoreLib::System::IO::MemoryStreamNamespace {
using namespace System::Runtime::InteropServices;

Boolean MemoryStream___::get_CanRead() {
  return _isOpen;
}

Boolean MemoryStream___::get_CanSeek() {
  return _isOpen;
}

Boolean MemoryStream___::get_CanWrite() {
  return _writable;
}

Int32 MemoryStream___::get_Capacity() {
  EnsureNotClosed();
  return _capacity - _origin;
}

void MemoryStream___::set_Capacity(Int32 value) {
  if (value < get_Length()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_SmallCapacity());
  }
  EnsureNotClosed();
  if (!_expandable && value != get_Capacity()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_MemStreamNotExpandable());
  }
  if (!_expandable || value == _capacity) {
    return;
  }
  if (value > 0) {
    Array<Byte> array = rt::newarr<Array<Byte>>(value);
    if (_length > 0) {
      Buffer::BlockCopy(_buffer, 0, array, 0, _length);
    }
    _buffer = array;
  } else {
    _buffer = Array<>::in::Empty<Byte>();
  }
  _capacity = value;
}

Int64 MemoryStream___::get_Length() {
  EnsureNotClosed();
  return _length - _origin;
}

Int64 MemoryStream___::get_Position() {
  EnsureNotClosed();
  return _position - _origin;
}

void MemoryStream___::set_Position(Int64 value) {
  if (value < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  EnsureNotClosed();
  if (value > Int32::MaxValue()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_StreamLength());
  }
  _position = _origin + (Int32)value;
}

void MemoryStream___::ctor() {
}

void MemoryStream___::ctor(Int32 capacity) {
  if (capacity < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("capacity", SR::get_ArgumentOutOfRange_NegativeCapacity());
  }
  _buffer = (Array<Byte>)((capacity != 0) ? ((Object)rt::newarr<Array<Byte>>(capacity)) : ((Object)Array<>::in::Empty<Byte>()));
  _capacity = capacity;
  _expandable = true;
  _writable = true;
  _exposable = true;
  _origin = 0;
  _isOpen = true;
}

void MemoryStream___::ctor(Array<Byte> buffer) {
}

void MemoryStream___::ctor(Array<Byte> buffer, Boolean writable) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  _buffer = buffer;
  _length = (_capacity = buffer->get_Length());
  _writable = writable;
  _exposable = false;
  _origin = 0;
  _isOpen = true;
}

void MemoryStream___::ctor(Array<Byte> buffer, Int32 index, Int32 count) {
}

void MemoryStream___::ctor(Array<Byte> buffer, Int32 index, Int32 count, Boolean writable) {
}

void MemoryStream___::ctor(Array<Byte> buffer, Int32 index, Int32 count, Boolean writable, Boolean publiclyVisible) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("index", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  _buffer = buffer;
  _origin = (_position = index);
  _length = (_capacity = index + count);
  _writable = writable;
  _exposable = publiclyVisible;
  _expandable = false;
  _isOpen = true;
}

void MemoryStream___::EnsureNotClosed() {
  if (!_isOpen) {
    rt::throw_exception(Error::GetStreamIsClosed());
  }
}

void MemoryStream___::EnsureWriteable() {
  if (!get_CanWrite()) {
    rt::throw_exception(Error::GetWriteNotSupported());
  }
}

void MemoryStream___::Dispose(Boolean disposing) {
  try {
    if (disposing) {
      _isOpen = false;
      _writable = false;
      _expandable = false;
      _lastReadTask = nullptr;
    }
  } catch (...) {
  } finally: {
    Stream::in::Dispose(disposing);
  }
}

Boolean MemoryStream___::EnsureCapacity(Int32 value) {
  if (value < 0) {
    rt::throw_exception<IOException>(SR::get_IO_StreamTooLong());
  }
  if (value > _capacity) {
    Int32 num = Math::Max(value, 256);
    if (num < _capacity * 2) {
      num = _capacity * 2;
    }
    if ((UInt32)(_capacity * 2) > 2147483591u) {
      num = Math::Max(value, 2147483591);
    }
    set_Capacity(num);
    return true;
  }
  return false;
}

void MemoryStream___::Flush() {
}

Task<> MemoryStream___::FlushAsync(CancellationToken cancellationToken) {
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

Array<Byte> MemoryStream___::GetBuffer() {
  if (!_exposable) {
    rt::throw_exception<UnauthorizedAccessException>(SR::get_UnauthorizedAccess_MemStreamBuffer());
  }
  return _buffer;
}

Boolean MemoryStream___::TryGetBuffer(ArraySegment<Byte>& buffer) {
  if (!_exposable) {
    buffer = rt::default__;
    return false;
  }
  buffer = ArraySegment<Byte>(_buffer, _origin, _length - _origin);
  return true;
}

Array<Byte> MemoryStream___::InternalGetBuffer() {
  return _buffer;
}

Int32 MemoryStream___::InternalGetPosition() {
  return _position;
}

ReadOnlySpan<Byte> MemoryStream___::InternalReadSpan(Int32 count) {
  EnsureNotClosed();
  Int32 position = _position;
  Int32 num = position + count;
  if ((UInt32)num > (UInt32)_length) {
    _position = _length;
    rt::throw_exception(Error::GetEndOfFile());
  }
  ReadOnlySpan<Byte> result = ReadOnlySpan<Byte>(_buffer, position, count);
  _position = num;
  return result;
}

Int32 MemoryStream___::InternalEmulateRead(Int32 count) {
  EnsureNotClosed();
  Int32 num = _length - _position;
  if (num > count) {
    num = count;
  }
  if (num < 0) {
    num = 0;
  }
  _position += num;
  return num;
}

Int32 MemoryStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
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
  EnsureNotClosed();
  Int32 num = _length - _position;
  if (num > count) {
    num = count;
  }
  if (num <= 0) {
    return 0;
  }
  if (num <= 8) {
    Int32 num2 = num;
    while (--num2 >= 0) {
      buffer[offset + num2] = _buffer[_position + num2];
    }
  } else {
    Buffer::BlockCopy(_buffer, _position, buffer, offset, num);
  }
  _position += num;
  return num;
}

Int32 MemoryStream___::Read(Span<Byte> buffer) {
  if (GetType() != typeof<MemoryStream>()) {
    return Stream::in::Read(buffer);
  }
  EnsureNotClosed();
  Int32 num = Math::Min(_length - _position, buffer.get_Length());
  if (num <= 0) {
    return 0;
  }
  Span<Byte>(_buffer, _position, num).CopyTo(buffer);
  _position += num;
  return num;
}

Task<Int32> MemoryStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
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
  } catch (OperationCanceledException exception) {
    return Task<>::in::FromCanceled<Int32>(exception);
  } catch (Exception exception2) {
    return Task<>::in::FromException<Int32>(exception2);
  }
}

template <>
ValueTask<Int32> MemoryStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<Int32>(Task<>::in::FromCanceled<Int32>(cancellationToken));
  }
  try {
    ArraySegment<Byte> segment;
    return ValueTask<Int32>(MemoryMarshal::TryGetArray((ReadOnlyMemory<Byte>)buffer, segment) ? Read(segment.get_Array(), segment.get_Offset(), segment.get_Count()) : Read(buffer.get_Span()));
  } catch (OperationCanceledException exception) {
    return ValueTask<Int32>(Task<>::in::FromCanceled<Int32>(exception));
  } catch (Exception exception2) {
    return ValueTask<Int32>(Task<>::in::FromException<Int32>(exception2));
  }
}

Int32 MemoryStream___::ReadByte() {
  EnsureNotClosed();
  if (_position >= _length) {
    return -1;
  }
  return _buffer[_position++];
}

void MemoryStream___::CopyTo(Stream destination, Int32 bufferSize) {
  StreamHelpers::ValidateCopyToArgs((MemoryStream)this, destination, bufferSize);
  if (GetType() != typeof<MemoryStream>()) {
    Stream::in::CopyTo(destination, bufferSize);
    return;
  }
  Int32 position = _position;
  Int32 num = InternalEmulateRead(_length - position);
  if (num > 0) {
    destination->Write(_buffer, position, num);
  }
}

Task<> MemoryStream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  StreamHelpers::ValidateCopyToArgs((MemoryStream)this, destination, bufferSize);
  if (GetType() != typeof<MemoryStream>()) {
    return Stream::in::CopyToAsync(destination, bufferSize, cancellationToken);
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  Int32 position = _position;
  Int32 num = InternalEmulateRead(_length - _position);
  if (num == 0) {
    return Task<>::in::get_CompletedTask();
  }
  MemoryStream memoryStream = rt::as<MemoryStream>(destination);
  if (memoryStream == nullptr) {
    return destination->WriteAsync(_buffer, position, num, cancellationToken);
  }
  try {
    memoryStream->Write(_buffer, position, num);
    return Task<>::in::get_CompletedTask();
  } catch (Exception exception) {
    return Task<>::in::FromException(exception);
  }
}

void MemoryStream___::CopyTo(ReadOnlySpanAction<Byte, Object> callback, Object state, Int32 bufferSize) {
  if (GetType() != typeof<MemoryStream>()) {
    Stream::in::CopyTo(callback, state, bufferSize);
    return;
  }
  StreamHelpers::ValidateCopyToArgs((MemoryStream)this, callback, bufferSize);
  ReadOnlySpan<Byte> span = ReadOnlySpan<Byte>(_buffer, _position, _length - _position);
  _position = _length;
  callback(span, state);
}

Task<> MemoryStream___::CopyToAsync(Func<ReadOnlyMemory<Byte>, Object, CancellationToken, ValueTask<>> callback, Object state, Int32 bufferSize, CancellationToken cancellationToken) {
  if (GetType() != typeof<MemoryStream>()) {
    return Stream::in::CopyToAsync(callback, state, bufferSize, cancellationToken);
  }
  StreamHelpers::ValidateCopyToArgs((MemoryStream)this, callback, bufferSize);
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  ReadOnlyMemory<Byte> arg = ReadOnlyMemory<Byte>(_buffer, _position, _length - _position);
  _position = _length;
  return callback(arg, state, cancellationToken).AsTask();
}

Int64 MemoryStream___::Seek(Int64 offset, SeekOrigin loc) {
  EnsureNotClosed();
  if (offset > Int32::MaxValue()) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_StreamLength());
  }
  switch (loc) {
    case SeekOrigin::Begin:
      {
        Int32 num3 = _origin + (Int32)offset;
        if (offset < 0 || num3 < _origin) {
          rt::throw_exception<IOException>(SR::get_IO_SeekBeforeBegin());
        }
        _position = num3;
        break;
      }case SeekOrigin::Current:
      {
        Int32 num2 = _position + (Int32)offset;
        if (_position + offset < _origin || num2 < _origin) {
          rt::throw_exception<IOException>(SR::get_IO_SeekBeforeBegin());
        }
        _position = num2;
        break;
      }case SeekOrigin::End:
      {
        Int32 num = _length + (Int32)offset;
        if (_length + offset < _origin || num < _origin) {
          rt::throw_exception<IOException>(SR::get_IO_SeekBeforeBegin());
        }
        _position = num;
        break;
      }default:
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidSeekOrigin());
  }
  return _position;
}

void MemoryStream___::SetLength(Int64 value) {
  if (value < 0 || value > Int32::MaxValue()) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_StreamLength());
  }
  EnsureWriteable();
  if (value > Int32::MaxValue() - _origin) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_StreamLength());
  }
  Int32 num = _origin + (Int32)value;
  if (!EnsureCapacity(num) && num > _length) {
    Array<>::in::Clear(_buffer, _length, num - _length);
  }
  _length = num;
  if (_position > num) {
    _position = num;
  }
}

Array<Byte> MemoryStream___::ToArray() {
  Int32 num = _length - _origin;
  if (num == 0) {
    return Array<>::in::Empty<Byte>();
  }
  Array<Byte> array = rt::newarr<Array<Byte>>(num);
  Buffer::BlockCopy(_buffer, _origin, array, 0, num);
  return array;
}

void MemoryStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
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
  EnsureNotClosed();
  EnsureWriteable();
  Int32 num = _position + count;
  if (num < 0) {
    rt::throw_exception<IOException>(SR::get_IO_StreamTooLong());
  }
  if (num > _length) {
    Boolean flag = _position > _length;
    if (num > _capacity && EnsureCapacity(num)) {
      flag = false;
    }
    if (flag) {
      Array<>::in::Clear(_buffer, _length, num - _length);
    }
    _length = num;
  }
  if (count <= 8 && buffer != _buffer) {
    Int32 num2 = count;
    while (--num2 >= 0) {
      _buffer[_position + num2] = buffer[offset + num2];
    }
  } else {
    Buffer::BlockCopy(buffer, offset, _buffer, _position, count);
  }
  _position = num;
}

void MemoryStream___::Write(ReadOnlySpan<Byte> buffer) {
  if (GetType() != typeof<MemoryStream>()) {
    Stream::in::Write(buffer);
    return;
  }
  EnsureNotClosed();
  EnsureWriteable();
  Int32 num = _position + buffer.get_Length();
  if (num < 0) {
    rt::throw_exception<IOException>(SR::get_IO_StreamTooLong());
  }
  if (num > _length) {
    Boolean flag = _position > _length;
    if (num > _capacity && EnsureCapacity(num)) {
      flag = false;
    }
    if (flag) {
      Array<>::in::Clear(_buffer, _length, num - _length);
    }
    _length = num;
  }
  buffer.CopyTo(Span<Byte>(_buffer, _position, buffer.get_Length()));
  _position = num;
}

Task<> MemoryStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
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
  } catch (OperationCanceledException exception) {
    return Task<>::in::FromCanceled(exception);
  } catch (Exception exception2) {
    return Task<>::in::FromException(exception2);
  }
}

template <>
ValueTask<> MemoryStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>(Task<>::in::FromCanceled(cancellationToken));
  }
  try {
    ArraySegment<Byte> segment;
    if (MemoryMarshal::TryGetArray(buffer, segment)) {
      Write(segment.get_Array(), segment.get_Offset(), segment.get_Count());
    } else {
      Write(buffer.get_Span());
    }
    return rt::default__;
  } catch (OperationCanceledException exception) {
    return ValueTask<>(Task<>::in::FromCanceled(exception));
  } catch (Exception exception2) {
    return ValueTask<>(Task<>::in::FromException(exception2));
  }
}

void MemoryStream___::WriteByte(Byte value) {
  EnsureNotClosed();
  EnsureWriteable();
  if (_position >= _length) {
    Int32 num = _position + 1;
    Boolean flag = _position > _length;
    if (num >= _capacity && EnsureCapacity(num)) {
      flag = false;
    }
    if (flag) {
      Array<>::in::Clear(_buffer, _length, _position - _length);
    }
    _length = num;
  }
  _buffer[_position++] = value;
}

void MemoryStream___::WriteTo(Stream stream) {
  if (stream == nullptr) {
    rt::throw_exception<ArgumentNullException>("stream", SR::get_ArgumentNull_Stream());
  }
  EnsureNotClosed();
  stream->Write(_buffer, _origin, _length - _origin);
}

} // namespace System::Private::CoreLib::System::IO::MemoryStreamNamespace
