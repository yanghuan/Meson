#include "TranscodingStream-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/IO/Error-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/Range-dep.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/TranscodingStream-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskToApm-dep.h>

namespace System::Private::CoreLib::System::Text::TranscodingStreamNamespace {
using namespace System::Buffers;
using namespace System::IO;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Threading::Tasks;

void TranscodingStream___::__DisposeAsync_g__DisposeAsyncCore30_0_d::MoveNext() {
  Int32 num = __1__state;
  TranscodingStream transcodingStream = __4__this;
  try {
    ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter;
    ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter2;
    if (num != 0) {
      if (num == 1) {
        awaiter = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_0121;
      }
      _innerStream_5__2 = transcodingStream->_innerStream;
      transcodingStream->_innerStream = nullptr;
      awaiter2 = _innerStream_5__2->WriteAsync(MemoryExtensions::AsMemory(pendingData)).ConfigureAwait(false).GetAwaiter();
      if (!awaiter2.get_IsCompleted()) {
        num = (__1__state = 0);
        __u__1 = awaiter2;
        __t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
        return;
      }
    } else {
      awaiter2 = __u__1;
      __u__1 = rt::default__;
      num = (__1__state = -1);
    }
    awaiter2.GetResult();
    if (!transcodingStream->_leaveOpen) {
      awaiter = _innerStream_5__2->DisposeAsync().ConfigureAwait(false).GetAwaiter();
      if (!awaiter.get_IsCompleted()) {
        num = (__1__state = 1);
        __u__1 = awaiter;
        __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
        return;
      }
      goto IL_0121;
    }
    goto end_IL_000e;

  IL_0121:
    awaiter.GetResult();

  end_IL_000e:
  } catch (Exception exception) {
    __1__state = -2;
    _innerStream_5__2 = nullptr;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  _innerStream_5__2 = nullptr;
  __t__builder.SetResult();
}

void TranscodingStream___::__DisposeAsync_g__DisposeAsyncCore30_0_d::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

void TranscodingStream___::__ReadAsync_g__ReadAsyncCore41_0_d::MoveNext() {
  Int32 num = __1__state;
  TranscodingStream transcodingStream = __4__this;
  Int32 result2;
  try {
    if (num != 0) {
      if (transcodingStream->_readBufferCount != 0) {
        goto IL_0164;
      }
      _rentedBytes_5__2 = ArrayPool<Byte>::in::get_Shared()->Rent(4096);
      _rentedChars_5__3 = ArrayPool<Char>::in::get_Shared()->Rent(transcodingStream->_readCharBufferMaxSize);
    }
    try {
      ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter;
      if (num != 0) {
        awaiter = transcodingStream->_innerStream->ReadAsync(MemoryExtensions::AsMemory(_rentedBytes_5__2, 0, 4096), cancellationToken).ConfigureAwait(false).GetAwaiter();
        if (!awaiter.get_IsCompleted()) {
          num = (__1__state = 0);
          __u__1 = awaiter;
          __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
          return;
        }
      } else {
        awaiter = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
      }
      Int32 result = awaiter.GetResult();
      Int32 num2 = result;
      Boolean flush = num2 == 0;
      Int32 chars = transcodingStream->_innerDecoder->GetChars(_rentedBytes_5__2, 0, num2, _rentedChars_5__3, 0, flush);
      Int32 bytes = transcodingStream->_thisEncoder->GetBytes(_rentedChars_5__3, 0, chars, transcodingStream->_readBuffer, 0, flush);
      transcodingStream->_readBufferOffset = 0;
      transcodingStream->_readBufferCount = bytes;
    } catch (...) {
    } finally: {
      if (num < 0) {
        ArrayPool<Byte>::in::get_Shared()->Return(_rentedBytes_5__2);
        ArrayPool<Char>::in::get_Shared()->Return(_rentedChars_5__3);
      }
    }
    _rentedBytes_5__2 = nullptr;
    _rentedChars_5__3 = nullptr;
    goto IL_0164;

  IL_0164:
    Int32 num3 = Math::Min(transcodingStream->_readBufferCount, buffer.get_Length());
    MemoryExtensions::AsSpan(transcodingStream->_readBuffer, transcodingStream->_readBufferOffset, num3).CopyTo(buffer.get_Span());
    transcodingStream->_readBufferOffset += num3;
    transcodingStream->_readBufferCount -= num3;
    result2 = num3;
  } catch (Exception exception) {
    __1__state = -2;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  __t__builder.SetResult(result2);
}

void TranscodingStream___::__ReadAsync_g__ReadAsyncCore41_0_d::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

void TranscodingStream___::__WriteAsync_g__WriteAsyncCore50_0_d::MoveNext() {
  Int32 num = __1__state;
  TranscodingStream transcodingStream = __4__this;
  try {
    if (num != 0) {
      Int32 minimumLength = Math::Clamp(remainingOuterEncodedBytes.get_Length(), 4096, 1048576);
      _scratchChars_5__2 = ArrayPool<Char>::in::get_Shared()->Rent(minimumLength);
      _scratchBytes_5__3 = ArrayPool<Byte>::in::get_Shared()->Rent(minimumLength);
    }
    try {
      if (num != 0) {
        goto IL_0055;
      }
      ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter = __u__1;
      __u__1 = rt::default__;
      num = (__1__state = -1);
      goto IL_0190;

    IL_0055:
      Int32 bytesUsed;
      Int32 charsUsed;
      transcodingStream->_thisDecoder->Convert(remainingOuterEncodedBytes.get_Span(), _scratchChars_5__2, false, bytesUsed, charsUsed, _decoderFinished_5__4);
      ReadOnlyMemory<Byte> readOnlyMemory = remainingOuterEncodedBytes;
      Int32 length = readOnlyMemory.get_Length();
      Int32 num2 = bytesUsed;
      Int32 length2 = length - num2;
      remainingOuterEncodedBytes = readOnlyMemory.Slice(num2, length2);
      _decodedChars_5__6 = ArraySegment<Char>(_scratchChars_5__2, 0, charsUsed);
      goto IL_00bd;

    IL_0190:
      awaiter.GetResult();
      if (!_encoderFinished_5__5) {
        goto IL_00bd;
      }
      _decodedChars_5__6 = rt::default__;
      if (!_decoderFinished_5__4) {
        goto IL_0055;
      }
      goto end_IL_004f;

    IL_00bd:
      Int32 charsUsed2;
      Int32 bytesUsed2;
      transcodingStream->_innerEncoder->Convert(_decodedChars_5__6, _scratchBytes_5__3, false, charsUsed2, bytesUsed2, _encoderFinished_5__5);
      ArraySegment<Char> arraySegment = _decodedChars_5__6;
      Int32 count = arraySegment.get_Count();
      length2 = charsUsed2;
      num2 = count - length2;
      _decodedChars_5__6 = arraySegment.Slice(length2, num2);
      awaiter = transcodingStream->_innerStream->WriteAsync(ReadOnlyMemory<Byte>(_scratchBytes_5__3, 0, bytesUsed2), cancellationToken).ConfigureAwait(false).GetAwaiter();
      if (!awaiter.get_IsCompleted()) {
        num = (__1__state = 0);
        __u__1 = awaiter;
        __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
        return;
      }
      goto IL_0190;

    end_IL_004f:
    } catch (...) {
    } finally: {
      if (num < 0) {
        ArrayPool<Char>::in::get_Shared()->Return(_scratchChars_5__2);
        ArrayPool<Byte>::in::get_Shared()->Return(_scratchBytes_5__3);
      }
    }
  } catch (Exception exception) {
    __1__state = -2;
    _scratchChars_5__2 = nullptr;
    _scratchBytes_5__3 = nullptr;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  _scratchChars_5__2 = nullptr;
  _scratchBytes_5__3 = nullptr;
  __t__builder.SetResult();
}

void TranscodingStream___::__WriteAsync_g__WriteAsyncCore50_0_d::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

Boolean TranscodingStream___::get_CanRead() {
  Stream innerStream = _innerStream;
  if (innerStream == nullptr) {
    return false;
  }
  return innerStream->get_CanRead();
}

Boolean TranscodingStream___::get_CanSeek() {
  return false;
}

Boolean TranscodingStream___::get_CanWrite() {
  Stream innerStream = _innerStream;
  if (innerStream == nullptr) {
    return false;
  }
  return innerStream->get_CanWrite();
}

Int64 TranscodingStream___::get_Length() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnseekableStream());
}

Int64 TranscodingStream___::get_Position() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnseekableStream());
}

void TranscodingStream___::set_Position(Int64 value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnseekableStream());
}

void TranscodingStream___::ctor(Stream innerStream, Encoding innerEncoding, Encoding thisEncoding, Boolean leaveOpen) {
  _innerStream = innerStream;
  _leaveOpen = leaveOpen;
  _innerEncoding = innerEncoding;
  _thisEncoding = thisEncoding;
}

IAsyncResult TranscodingStream___::BeginRead(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return TaskToApm::Begin(ReadAsync(buffer, offset, count, CancellationToken::get_None()), callback, state);
}

IAsyncResult TranscodingStream___::BeginWrite(Array<Byte> buffer, Int32 offset, Int32 count, AsyncCallback callback, Object state) {
  return TaskToApm::Begin(WriteAsync(buffer, offset, count, CancellationToken::get_None()), callback, state);
}

void TranscodingStream___::Dispose(Boolean disposing) {
  if (_innerStream != nullptr) {
    ArraySegment<Byte> segment = FinalFlushWriteBuffers();
    if (segment.get_Count() != 0) {
      _innerStream->Write(segment);
    }
    Stream innerStream = _innerStream;
    _innerStream = nullptr;
    if (!_leaveOpen) {
      innerStream->Dispose();
    }
  }
}

ValueTask<> TranscodingStream___::DisposeAsync() {
  auto DisposeAsyncCore = [](ArraySegment<Byte> pendingData) -> ValueTask<> {
    __DisposeAsync_g__DisposeAsyncCore30_0_d stateMachine;
    stateMachine.__t__builder = AsyncValueTaskMethodBuilder<>::Create();
    stateMachine.__4__this = (TranscodingStream)this;
    stateMachine.pendingData = pendingData;
    stateMachine.__1__state = -1;
    stateMachine.__t__builder.Start(stateMachine);
    return stateMachine.__t__builder.get_Task();
  };
  if (_innerStream == nullptr) {
    return rt::default__;
  }
  ArraySegment<Byte> pendingData2 = FinalFlushWriteBuffers();
  if (pendingData2.get_Count() == 0) {
    Stream innerStream = _innerStream;
    _innerStream = nullptr;
    if (!_leaveOpen) {
      return innerStream->DisposeAsync();
    }
    return rt::default__;
  }
  return DisposeAsyncCore(pendingData2);
}

Int32 TranscodingStream___::EndRead(IAsyncResult asyncResult) {
  return TaskToApm::End<Int32>(asyncResult);
}

void TranscodingStream___::EndWrite(IAsyncResult asyncResult) {
  TaskToApm::End(asyncResult);
}

void TranscodingStream___::EnsurePreReadConditions() {
  auto InitializeReadDataStructures = []() -> void {
    if (!get_CanRead()) {
      rt::throw_exception(Error::GetReadNotSupported());
    }
    _innerDecoder = _innerEncoding->GetDecoder();
    _thisEncoder = _thisEncoding->GetEncoder();
    _readCharBufferMaxSize = _innerEncoding->GetMaxCharCount(4096);
    _readBuffer = GC::AllocateUninitializedArray<Byte>(_thisEncoding->GetMaxByteCount(_readCharBufferMaxSize));
  };
  ThrowIfDisposed();
  if (_innerDecoder == nullptr) {
    InitializeReadDataStructures();
  }
}

void TranscodingStream___::EnsurePreWriteConditions() {
  auto InitializeReadDataStructures = []() -> void {
    if (!get_CanWrite()) {
      rt::throw_exception(Error::GetWriteNotSupported());
    }
    _innerEncoder = _innerEncoding->GetEncoder();
    _thisDecoder = _thisEncoding->GetDecoder();
  };
  ThrowIfDisposed();
  if (_innerEncoder == nullptr) {
    InitializeReadDataStructures();
  }
}

ArraySegment<Byte> TranscodingStream___::FinalFlushWriteBuffers() {
  if (_thisDecoder == nullptr || _innerEncoder == nullptr) {
    return rt::default__;
  }
  Array<Char> chars = Array<>::in::Empty<Char>();
  Int32 num = _thisDecoder->GetCharCount(Array<>::in::Empty<Byte>(), 0, 0, true);
  if (num > 0) {
    chars = rt::newarr<Array<Char>>(num);
    num = _thisDecoder->GetChars(Array<>::in::Empty<Byte>(), 0, 0, chars, 0, true);
  }
  Array<Byte> array = Array<>::in::Empty<Byte>();
  Int32 num2 = _innerEncoder->GetByteCount(chars, 0, num, true);
  if (num2 > 0) {
    array = rt::newarr<Array<Byte>>(num2);
    num2 = _innerEncoder->GetBytes(chars, 0, num, array, 0, true);
  }
  return ArraySegment<Byte>(array, 0, num2);
}

void TranscodingStream___::Flush() {
  ThrowIfDisposed();
  _innerStream->Flush();
}

Task<> TranscodingStream___::FlushAsync(CancellationToken cancellationToken) {
  ThrowIfDisposed();
  return _innerStream->FlushAsync(cancellationToken);
}

Int32 TranscodingStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer");
  }
  return Read(Span<Byte>(buffer, offset, count));
}

Int32 TranscodingStream___::Read(Span<Byte> buffer) {
  EnsurePreReadConditions();
  if (_readBufferCount == 0) {
    Array<Byte> array = ArrayPool<Byte>::in::get_Shared()->Rent(4096);
    Array<Char> array2 = ArrayPool<Char>::in::get_Shared()->Rent(_readCharBufferMaxSize);
    try {
      Int32 num = _innerStream->Read(array, 0, 4096);
      Boolean flush = num == 0;
      Int32 chars = _innerDecoder->GetChars(array, 0, num, array2, 0, flush);
      Int32 bytes = _thisEncoder->GetBytes(array2, 0, chars, _readBuffer, 0, flush);
      _readBufferOffset = 0;
      _readBufferCount = bytes;
    } catch (...) {
    } finally: {
      ArrayPool<Byte>::in::get_Shared()->Return(array);
      ArrayPool<Char>::in::get_Shared()->Return(array2);
    }
  }
  Int32 num2 = Math::Min(_readBufferCount, buffer.get_Length());
  MemoryExtensions::AsSpan(_readBuffer, _readBufferOffset, num2).CopyTo(buffer);
  _readBufferOffset += num2;
  _readBufferCount -= num2;
  return num2;
}

Task<Int32> TranscodingStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer");
  }
  return ReadAsync(Memory<Byte>(buffer, offset, count), cancellationToken).AsTask();
}

ValueTask<Int32> TranscodingStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  auto ReadAsyncCore = [](Memory<Byte> buffer, CancellationToken cancellationToken) -> ValueTask<Int32> {
    __ReadAsync_g__ReadAsyncCore41_0_d stateMachine;
    stateMachine.__t__builder = AsyncValueTaskMethodBuilder<Int32>::Create();
    stateMachine.__4__this = (TranscodingStream)this;
    stateMachine.buffer = buffer;
    stateMachine.cancellationToken = cancellationToken;
    stateMachine.__1__state = -1;
    stateMachine.__t__builder.Start(stateMachine);
    return stateMachine.__t__builder.get_Task();
  };
  EnsurePreReadConditions();
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>::FromCanceled<Int32>(cancellationToken);
  }
  return ReadAsyncCore(buffer, cancellationToken);
}

Int32 TranscodingStream___::ReadByte() {
  Byte as[1] = {};
  Span<Byte> span = Span<Byte>(as, 1);
  Span<Byte> buffer = span;
  if (Read(buffer) != 0) {
    return buffer[0];
  }
  return -1;
}

Int64 TranscodingStream___::Seek(Int64 offset, SeekOrigin origin) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnseekableStream());
}

void TranscodingStream___::SetLength(Int64 value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_UnseekableStream());
}

void TranscodingStream___::ThrowIfDisposed() {
  if (_innerStream == nullptr) {
    ThrowObjectDisposedException();
  }
}

void TranscodingStream___::ThrowObjectDisposedException() {
  rt::throw_exception<ObjectDisposedException>(GetType()->get_Name(), SR::get_ObjectDisposed_StreamClosed());
}

void TranscodingStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer");
  }
  Write(ReadOnlySpan<Byte>(buffer, offset, count));
}

void TranscodingStream___::Write(ReadOnlySpan<Byte> buffer) {
  EnsurePreWriteConditions();
  Int32 minimumLength = Math::Clamp(buffer.get_Length(), 4096, 1048576);
  Array<Char> array = ArrayPool<Char>::in::get_Shared()->Rent(minimumLength);
  Array<Byte> array2 = ArrayPool<Byte>::in::get_Shared()->Rent(minimumLength);
  try {
    Boolean completed;
    do {
      Int32 bytesUsed;
      Int32 charsUsed;
      _thisDecoder->Convert(buffer, array, false, bytesUsed, charsUsed, completed);
      ReadOnlySpan<Byte> readOnlySpan = buffer;
      Int32 length = readOnlySpan.get_Length();
      Int32 num = bytesUsed;
      Int32 length2 = length - num;
      buffer = readOnlySpan.Slice(num, length2);
      Span<Char> span = MemoryExtensions::AsSpan(array, Range::EndAt(charsUsed));
      Boolean completed2;
      do {
        Int32 charsUsed2;
        Int32 bytesUsed2;
        _innerEncoder->Convert(span, array2, false, charsUsed2, bytesUsed2, completed2);
        Span<Char> span2 = span;
        Int32 length3 = span2.get_Length();
        length2 = charsUsed2;
        num = length3 - length2;
        span = span2.Slice(length2, num);
        _innerStream->Write(array2, 0, bytesUsed2);
      } while (!completed2);
    } while (!completed);
  } catch (...) {
  } finally: {
    ArrayPool<Char>::in::get_Shared()->Return(array);
    ArrayPool<Byte>::in::get_Shared()->Return(array2);
  }
}

Task<> TranscodingStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer");
  }
  return WriteAsync(ReadOnlyMemory<Byte>(buffer, offset, count), cancellationToken).AsTask();
}

ValueTask<> TranscodingStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  auto WriteAsyncCore = [](ReadOnlyMemory<Byte> remainingOuterEncodedBytes, CancellationToken cancellationToken) -> ValueTask<> {
    __WriteAsync_g__WriteAsyncCore50_0_d stateMachine;
    stateMachine.__t__builder = AsyncValueTaskMethodBuilder<>::Create();
    stateMachine.__4__this = (TranscodingStream)this;
    stateMachine.remainingOuterEncodedBytes = remainingOuterEncodedBytes;
    stateMachine.cancellationToken = cancellationToken;
    stateMachine.__1__state = -1;
    stateMachine.__t__builder.Start(stateMachine);
    return stateMachine.__t__builder.get_Task();
  };
  EnsurePreWriteConditions();
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>::FromCanceled(cancellationToken);
  }
  return WriteAsyncCore(buffer, cancellationToken);
}

void TranscodingStream___::WriteByte(Byte value) {
  Write(MemoryMarshal::CreateReadOnlySpan(value, 1));
}

ValueTask<> TranscodingStream___::_DisposeAsync_g__DisposeAsyncCore30_0(ArraySegment<Byte> pendingData) {
  __DisposeAsync_g__DisposeAsyncCore30_0_d stateMachine;
  stateMachine.__t__builder = AsyncValueTaskMethodBuilder<>::Create();
  stateMachine.__4__this = (TranscodingStream)this;
  stateMachine.pendingData = pendingData;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

void TranscodingStream___::_EnsurePreReadConditions_g__InitializeReadDataStructures33_0() {
  if (!get_CanRead()) {
    rt::throw_exception(Error::GetReadNotSupported());
  }
  _innerDecoder = _innerEncoding->GetDecoder();
  _thisEncoder = _thisEncoding->GetEncoder();
  _readCharBufferMaxSize = _innerEncoding->GetMaxCharCount(4096);
  _readBuffer = GC::AllocateUninitializedArray<Byte>(_thisEncoding->GetMaxByteCount(_readCharBufferMaxSize));
}

void TranscodingStream___::_EnsurePreWriteConditions_g__InitializeReadDataStructures34_0() {
  if (!get_CanWrite()) {
    rt::throw_exception(Error::GetWriteNotSupported());
  }
  _innerEncoder = _innerEncoding->GetEncoder();
  _thisDecoder = _thisEncoding->GetDecoder();
}

ValueTask<Int32> TranscodingStream___::_ReadAsync_g__ReadAsyncCore41_0(Memory<Byte> buffer, CancellationToken cancellationToken) {
  __ReadAsync_g__ReadAsyncCore41_0_d stateMachine;
  stateMachine.__t__builder = AsyncValueTaskMethodBuilder<Int32>::Create();
  stateMachine.__4__this = (TranscodingStream)this;
  stateMachine.buffer = buffer;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

ValueTask<> TranscodingStream___::_WriteAsync_g__WriteAsyncCore50_0(ReadOnlyMemory<Byte> remainingOuterEncodedBytes, CancellationToken cancellationToken) {
  __WriteAsync_g__WriteAsyncCore50_0_d stateMachine;
  stateMachine.__t__builder = AsyncValueTaskMethodBuilder<>::Create();
  stateMachine.__4__this = (TranscodingStream)this;
  stateMachine.remainingOuterEncodedBytes = remainingOuterEncodedBytes;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

} // namespace System::Private::CoreLib::System::Text::TranscodingStreamNamespace
