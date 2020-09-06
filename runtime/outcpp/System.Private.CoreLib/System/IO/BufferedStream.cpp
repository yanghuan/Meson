#include "BufferedStream-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/IO/BufferedStream-dep.h>
#include <System.Private.CoreLib/System/IO/SeekOrigin.h>
#include <System.Private.CoreLib/System/IO/StreamHelpers-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Memory-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncValueTaskMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskToApm-dep.h>

namespace System::Private::CoreLib::System::IO::BufferedStreamNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Threading::Tasks;

Stream BufferedStream___::get_UnderlyingStream() {
  return _stream;
}

Int32 BufferedStream___::get_BufferSize() {
  return _bufferSize;
}

Boolean BufferedStream___::get_CanRead() {
  if (_stream != nullptr) {
    return _stream->get_CanRead();
  }
  return false;
}

Boolean BufferedStream___::get_CanWrite() {
  if (_stream != nullptr) {
    return _stream->get_CanWrite();
  }
  return false;
}

Boolean BufferedStream___::get_CanSeek() {
  if (_stream != nullptr) {
    return _stream->get_CanSeek();
  }
  return false;
}

Int64 BufferedStream___::get_Length() {
  EnsureNotClosed();
  if (_writePos > 0) {
    FlushWrite();
  }
  return _stream->get_Length();
}

Int64 BufferedStream___::get_Position() {
  EnsureNotClosed();
  EnsureCanSeek();
  return _stream->get_Position() + (_readPos - _readLen + _writePos);
}

void BufferedStream___::set_Position(Int64 value) {
  if (value < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  EnsureNotClosed();
  EnsureCanSeek();
  if (_writePos > 0) {
    FlushWrite();
  }
  _readPos = 0;
  _readLen = 0;
  _stream->Seek(value, SeekOrigin::Begin);
}

SemaphoreSlim BufferedStream___::LazyEnsureAsyncActiveSemaphoreInitialized() {
}

void BufferedStream___::ctor(Stream stream) {
}

void BufferedStream___::ctor(Stream stream, Int32 bufferSize) {
  if (stream == nullptr) {
    rt::throw_exception<ArgumentNullException>("stream");
  }
  if (bufferSize <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", SR::Format(SR::get_ArgumentOutOfRange_MustBePositive(), "bufferSize"));
  }
  _stream = stream;
  _bufferSize = bufferSize;
  if (!_stream->get_CanRead() && !_stream->get_CanWrite()) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_StreamClosed());
  }
}

void BufferedStream___::EnsureNotClosed() {
  if (_stream == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_StreamClosed());
  }
}

void BufferedStream___::EnsureCanSeek() {
  if (!_stream->get_CanSeek()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnseekableStream());
  }
}

void BufferedStream___::EnsureCanRead() {
  if (!_stream->get_CanRead()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnreadableStream());
  }
}

void BufferedStream___::EnsureCanWrite() {
  if (!_stream->get_CanWrite()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnwritableStream());
  }
}

void BufferedStream___::EnsureShadowBufferAllocated() {
  if (_buffer->get_Length() == _bufferSize && _bufferSize < 81920) {
    Array<Byte> array = rt::newarr<Array<Byte>>(Math::Min(_bufferSize + _bufferSize, 81920));
    Buffer::BlockCopy(_buffer, 0, array, 0, _writePos);
    _buffer = array;
  }
}

void BufferedStream___::EnsureBufferAllocated() {
  if (_buffer == nullptr) {
    _buffer = rt::newarr<Array<Byte>>(_bufferSize);
  }
}

void BufferedStream___::Dispose(Boolean disposing) {
  try {
    if (disposing && _stream != nullptr) {
      try {
        Flush();
      } catch (...) {
      } finally: {
        _stream->Dispose();
      }
    }
  } catch (...) {
  } finally: {
    _stream = nullptr;
    _buffer = nullptr;
    Stream::in::Dispose(disposing);
  }
}

ValueTask<> BufferedStream___::DisposeAsync() {
  一DisposeAsync一d__35 stateMachine;
  stateMachine.一一t__builder = AsyncValueTaskMethodBuilder<>::Create();
  stateMachine.一一4__this = (BufferedStream)this;
  stateMachine.一一1__state = -1;
  stateMachine.一一t__builder.Start(stateMachine);
  return stateMachine.一一t__builder.get_Task();
}

void BufferedStream___::Flush() {
  EnsureNotClosed();
  if (_writePos > 0) {
    FlushWrite();
  } else if (_readPos < _readLen) {
    if (_stream->get_CanSeek()) {
      FlushRead();
    }
    if (_stream->get_CanWrite()) {
      _stream->Flush();
    }
  } else {
    if (_stream->get_CanWrite()) {
      _stream->Flush();
    }
    _writePos = (_readPos = (_readLen = 0));
  }

}

Task<> BufferedStream___::FlushAsync(CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled<Int32>(cancellationToken);
  }
  EnsureNotClosed();
  return FlushAsyncInternal(cancellationToken);
}

Task<> BufferedStream___::FlushAsyncInternal(CancellationToken cancellationToken) {
  一FlushAsyncInternal一d__38 stateMachine;
  stateMachine.一一t__builder = AsyncTaskMethodBuilder<>::Create();
  stateMachine.一一4__this = (BufferedStream)this;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.一一1__state = -1;
  stateMachine.一一t__builder.Start(stateMachine);
  return stateMachine.一一t__builder.get_Task();
}

void BufferedStream___::FlushRead() {
  if (_readPos - _readLen != 0) {
    _stream->Seek(_readPos - _readLen, SeekOrigin::Current);
  }
  _readPos = 0;
  _readLen = 0;
}

void BufferedStream___::ClearReadBufferBeforeWrite() {
  if (_readPos == _readLen) {
    _readPos = (_readLen = 0);
    return;
  }
  if (!_stream->get_CanSeek()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_CannotWriteToBufferedStreamIfReadBufferCannotBeFlushed());
  }
  FlushRead();
}

void BufferedStream___::FlushWrite() {
  _stream->Write(_buffer, 0, _writePos);
  _writePos = 0;
  _stream->Flush();
}

ValueTask<> BufferedStream___::FlushWriteAsync(CancellationToken cancellationToken) {
  一FlushWriteAsync一d__42 stateMachine;
  stateMachine.一一t__builder = AsyncValueTaskMethodBuilder<>::Create();
  stateMachine.一一4__this = (BufferedStream)this;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.一一1__state = -1;
  stateMachine.一一t__builder.Start(stateMachine);
  return stateMachine.一一t__builder.get_Task();
}

Int32 BufferedStream___::ReadFromBuffer(Array<Byte> array, Int32 offset, Int32 count) {
  Int32 num = _readLen - _readPos;
  if (num == 0) {
    return 0;
  }
  if (num > count) {
    num = count;
  }
  Buffer::BlockCopy(_buffer, _readPos, array, offset, num);
  _readPos += num;
  return num;
}

Int32 BufferedStream___::ReadFromBuffer(Span<Byte> destination) {
  Int32 num = Math::Min(_readLen - _readPos, destination.get_Length());
  if (num > 0) {
    ReadOnlySpan<Byte>(_buffer, _readPos, num).CopyTo(destination);
    _readPos += num;
  }
  return num;
}

Int32 BufferedStream___::ReadFromBuffer(Array<Byte> array, Int32 offset, Int32 count, Exception& error) {
  try {
    error = nullptr;
    return ReadFromBuffer(array, offset, count);
  } catch (Exception ex) {
    Exception ex2 = error = ex;
    return 0;
  }
}

Int32 BufferedStream___::Read(Array<Byte> array, Int32 offset, Int32 count) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  EnsureNotClosed();
  EnsureCanRead();
  Int32 num = ReadFromBuffer(array, offset, count);
  if (num == count) {
    return num;
  }
  Int32 num2 = num;
  if (num > 0) {
    count -= num;
    offset += num;
  }
  _readPos = (_readLen = 0);
  if (_writePos > 0) {
    FlushWrite();
  }
  if (count >= _bufferSize) {
    return _stream->Read(array, offset, count) + num2;
  }
  EnsureBufferAllocated();
  _readLen = _stream->Read(_buffer, 0, _bufferSize);
  num = ReadFromBuffer(array, offset, count);
  return num + num2;
}

Int32 BufferedStream___::Read(Span<Byte> destination) {
  EnsureNotClosed();
  EnsureCanRead();
  Int32 num = ReadFromBuffer(destination);
  if (num == destination.get_Length()) {
    return num;
  }
  if (num > 0) {
    destination = destination.Slice(num);
  }
  _readPos = (_readLen = 0);
  if (_writePos > 0) {
    FlushWrite();
  }
  if (destination.get_Length() >= _bufferSize) {
    return _stream->Read(destination) + num;
  }
  EnsureBufferAllocated();
  _readLen = _stream->Read(_buffer, 0, _bufferSize);
  return ReadFromBuffer(destination) + num;
}

Task<Int32> BufferedStream___::LastSyncCompletedReadTask(Int32 val) {
  Task<Int32> lastSyncCompletedReadTask = _lastSyncCompletedReadTask;
  if (lastSyncCompletedReadTask != nullptr && lastSyncCompletedReadTask->get_Result() == val) {
    return lastSyncCompletedReadTask;
  }
  return _lastSyncCompletedReadTask = Task<>::in::FromResult(val);
}

Task<Int32> BufferedStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
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
  EnsureNotClosed();
  EnsureCanRead();
  Int32 num = 0;
  SemaphoreSlim semaphoreSlim = LazyEnsureAsyncActiveSemaphoreInitialized();
  Task<> task = semaphoreSlim->WaitAsync(cancellationToken);
  if (task->get_IsCompletedSuccessfully()) {
    Boolean flag = true;
    try {
      Exception error;
      num = ReadFromBuffer(buffer, offset, count, error);
      flag = (num == count || error != nullptr);
      if (flag) {
        return (error == nullptr) ? LastSyncCompletedReadTask(num) : Task<>::in::FromException<Int32>(error);
      }
    } catch (...) {
    } finally: {
      if (flag) {
        semaphoreSlim->Release();
      }
    }
  }
  return ReadFromUnderlyingStreamAsync(Memory<Byte>(buffer, offset + num, count - num), cancellationToken, num, task).AsTask();
}

template <>
ValueTask<Int32> BufferedStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>::FromCanceled<Int32>(cancellationToken);
  }
  EnsureNotClosed();
  EnsureCanRead();
  Int32 num = 0;
  SemaphoreSlim semaphoreSlim = LazyEnsureAsyncActiveSemaphoreInitialized();
  Task<> task = semaphoreSlim->WaitAsync(cancellationToken);
  if (task->get_IsCompletedSuccessfully()) {
    Boolean flag = true;
    try {
      num = ReadFromBuffer(buffer.get_Span());
      flag = (num == buffer.get_Length());
      if (flag) {
        return ValueTask<Int32>(num);
      }
    } catch (...) {
    } finally: {
      if (flag) {
        semaphoreSlim->Release();
      }
    }
  }
  return ReadFromUnderlyingStreamAsync(buffer.Slice(num), cancellationToken, num, task);
}

ValueTask<Int32> BufferedStream___::ReadFromUnderlyingStreamAsync(Memory<Byte> buffer, CancellationToken cancellationToken, Int32 bytesAlreadySatisfied, Task<> semaphoreLockTask) {
  一ReadFromUnderlyingStreamAsync一d__51 stateMachine;
  stateMachine.一一t__builder = AsyncValueTaskMethodBuilder<Int32>::Create();
  stateMachine.一一4__this = (BufferedStream)this;
  stateMachine.buffer = buffer;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.bytesAlreadySatisfied = bytesAlreadySatisfied;
  stateMachine.semaphoreLockTask = semaphoreLockTask;
  stateMachine.一一1__state = -1;
  stateMachine.一一t__builder.Start(stateMachine);
  return stateMachine.一一t__builder.get_Task();
}

IAsyncResult BufferedStream___::BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return TaskToApm::Begin(ReadAsync(buffer, offset, count, CancellationToken::get_None()), callback, state);
}

Int32 BufferedStream___::EndRead(IAsyncResult asyncResult) {
  return TaskToApm::End<Int32>(asyncResult);
}

Int32 BufferedStream___::ReadByte() {
  if (_readPos == _readLen) {
    return ReadByteSlow();
  }
  return _buffer[_readPos++];
}

Int32 BufferedStream___::ReadByteSlow() {
  EnsureNotClosed();
  EnsureCanRead();
  if (_writePos > 0) {
    FlushWrite();
  }
  EnsureBufferAllocated();
  _readLen = _stream->Read(_buffer, 0, _bufferSize);
  _readPos = 0;
  if (_readLen == 0) {
    return -1;
  }
  return _buffer[_readPos++];
}

void BufferedStream___::WriteToBuffer(Array<Byte> array, Int32& offset, Int32& count) {
  Int32 num = Math::Min(_bufferSize - _writePos, count);
  if (num > 0) {
    EnsureBufferAllocated();
    Buffer::BlockCopy(array, offset, _buffer, _writePos, num);
    _writePos += num;
    count -= num;
    offset += num;
  }
}

Int32 BufferedStream___::WriteToBuffer(ReadOnlySpan<Byte> buffer) {
  Int32 num = Math::Min(_bufferSize - _writePos, buffer.get_Length());
  if (num > 0) {
    EnsureBufferAllocated();
    buffer.Slice(0, num).CopyTo(Span<Byte>(_buffer, _writePos, num));
    _writePos += num;
  }
  return num;
}

void BufferedStream___::Write(Array<Byte> array, Int32 offset, Int32 count) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array", SR::get_ArgumentNull_Buffer());
  }
  if (offset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("offset", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (array->get_Length() - offset < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  EnsureNotClosed();
  EnsureCanWrite();
  if (_writePos == 0) {
    ClearReadBufferBeforeWrite();
  }
  Int32 num;
  {
    num = _writePos + count;
    if (num + count < _bufferSize + _bufferSize) {
      WriteToBuffer(array, offset, count);
      if (_writePos >= _bufferSize) {
        _stream->Write(_buffer, 0, _writePos);
        _writePos = 0;
        WriteToBuffer(array, offset, count);
      }
      return;
    }
  }
  if (_writePos > 0) {
    if (num <= _bufferSize + _bufferSize && num <= 81920) {
      EnsureShadowBufferAllocated();
      Buffer::BlockCopy(array, offset, _buffer, _writePos, count);
      _stream->Write(_buffer, 0, num);
      _writePos = 0;
      return;
    }
    _stream->Write(_buffer, 0, _writePos);
    _writePos = 0;
  }
  _stream->Write(array, offset, count);
}

void BufferedStream___::Write(ReadOnlySpan<Byte> buffer) {
  EnsureNotClosed();
  EnsureCanWrite();
  if (_writePos == 0) {
    ClearReadBufferBeforeWrite();
  }
  Int32 num;
  {
    num = _writePos + buffer.get_Length();
    if (num + buffer.get_Length() < _bufferSize + _bufferSize) {
      Int32 start = WriteToBuffer(buffer);
      if (_writePos >= _bufferSize) {
        buffer = buffer.Slice(start);
        _stream->Write(_buffer, 0, _writePos);
        _writePos = 0;
        start = WriteToBuffer(buffer);
      }
      return;
    }
  }
  if (_writePos > 0) {
    if (num <= _bufferSize + _bufferSize && num <= 81920) {
      EnsureShadowBufferAllocated();
      buffer.CopyTo(Span<Byte>(_buffer, _writePos, buffer.get_Length()));
      _stream->Write(_buffer, 0, num);
      _writePos = 0;
      return;
    }
    _stream->Write(_buffer, 0, _writePos);
    _writePos = 0;
  }
  _stream->Write(buffer);
}

Task<> BufferedStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
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
  return WriteAsync(ReadOnlyMemory<Byte>(buffer, offset, count), cancellationToken).AsTask();
}

template <>
ValueTask<> BufferedStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>::FromCanceled(cancellationToken);
  }
  EnsureNotClosed();
  EnsureCanWrite();
  SemaphoreSlim semaphoreSlim = LazyEnsureAsyncActiveSemaphoreInitialized();
  Task<> task = semaphoreSlim->WaitAsync(cancellationToken);
  if (task->get_IsCompletedSuccessfully()) {
    Boolean flag = true;
    try {
      if (_writePos == 0) {
        ClearReadBufferBeforeWrite();
      }
      flag = (buffer.get_Length() < _bufferSize - _writePos);
      if (flag) {
        Int32 num = WriteToBuffer(buffer.get_Span());
        return rt::default__;
      }
    } catch (...) {
    } finally: {
      if (flag) {
        semaphoreSlim->Release();
      }
    }
  }
  return WriteToUnderlyingStreamAsync(buffer, cancellationToken, task);
}

ValueTask<> BufferedStream___::WriteToUnderlyingStreamAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken, Task<> semaphoreLockTask) {
  一WriteToUnderlyingStreamAsync一d__62 stateMachine;
  stateMachine.一一t__builder = AsyncValueTaskMethodBuilder<>::Create();
  stateMachine.一一4__this = (BufferedStream)this;
  stateMachine.buffer = buffer;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.semaphoreLockTask = semaphoreLockTask;
  stateMachine.一一1__state = -1;
  stateMachine.一一t__builder.Start(stateMachine);
  return stateMachine.一一t__builder.get_Task();
}

IAsyncResult BufferedStream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return TaskToApm::Begin(WriteAsync(buffer, offset, count, CancellationToken::get_None()), callback, state);
}

void BufferedStream___::EndWrite(IAsyncResult asyncResult) {
  TaskToApm::End(asyncResult);
}

void BufferedStream___::WriteByte(Byte value) {
  EnsureNotClosed();
  if (_writePos == 0) {
    EnsureCanWrite();
    ClearReadBufferBeforeWrite();
    EnsureBufferAllocated();
  }
  if (_writePos >= _bufferSize - 1) {
    FlushWrite();
  }
  _buffer[_writePos++] = value;
}

Int64 BufferedStream___::Seek(Int64 offset, SeekOrigin origin) {
  EnsureNotClosed();
  EnsureCanSeek();
  if (_writePos > 0) {
    FlushWrite();
    return _stream->Seek(offset, origin);
  }
  if (_readLen - _readPos > 0 && origin == SeekOrigin::Current) {
    offset -= _readLen - _readPos;
  }
  Int64 position = get_Position();
  Int64 num = _stream->Seek(offset, origin);
  _readPos = (Int32)(num - (position - _readPos));
  if (0 <= _readPos && _readPos < _readLen) {
    _stream->Seek(_readLen - _readPos, SeekOrigin::Current);
  } else {
    _readPos = (_readLen = 0);
  }
  return num;
}

void BufferedStream___::SetLength(Int64 value) {
  if (value < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("value", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  EnsureNotClosed();
  EnsureCanSeek();
  EnsureCanWrite();
  Flush();
  _stream->SetLength(value);
}

void BufferedStream___::CopyTo(Stream destination, Int32 bufferSize) {
  StreamHelpers::ValidateCopyToArgs((BufferedStream)this, destination, bufferSize);
  Int32 num = _readLen - _readPos;
  if (num > 0) {
    destination->Write(_buffer, _readPos, num);
    _readPos = (_readLen = 0);
  } else if (_writePos > 0) {
    FlushWrite();
  }

  _stream->CopyTo(destination, bufferSize);
}

Task<> BufferedStream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  StreamHelpers::ValidateCopyToArgs((BufferedStream)this, destination, bufferSize);
  if (!cancellationToken.get_IsCancellationRequested()) {
    return CopyToAsyncCore(destination, bufferSize, cancellationToken);
  }
  return Task<>::in::FromCanceled<Int32>(cancellationToken);
}

Task<> BufferedStream___::CopyToAsyncCore(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  一CopyToAsyncCore一d__70 stateMachine;
  stateMachine.一一t__builder = AsyncTaskMethodBuilder<>::Create();
  stateMachine.一一4__this = (BufferedStream)this;
  stateMachine.destination = destination;
  stateMachine.bufferSize = bufferSize;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.一一1__state = -1;
  stateMachine.一一t__builder.Start(stateMachine);
  return stateMachine.一一t__builder.get_Task();
}

} // namespace System::Private::CoreLib::System::IO::BufferedStreamNamespace
