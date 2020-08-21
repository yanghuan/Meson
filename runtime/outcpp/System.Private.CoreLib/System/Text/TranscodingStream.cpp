#include "TranscodingStream-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArraySegment-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/IO/Error-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Memory-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlyMemory-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskToApm-dep.h>

namespace System::Private::CoreLib::System::Text::TranscodingStreamNamespace {
using namespace System::Buffers;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;
using namespace System::Threading::Tasks;

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
    Stream innerStream2 = _innerStream;
    _innerStream = nullptr;
  };
  if (_innerStream == nullptr) {
    return ValueTask<>();
  }
  ArraySegment<Byte> pendingData2 = FinalFlushWriteBuffers();
  if (pendingData2.get_Count() == 0) {
    Stream innerStream = _innerStream;
    _innerStream = nullptr;
    if (!_leaveOpen) {
      return innerStream->DisposeAsync();
    }
    return ValueTask<>();
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
    return ArraySegment<T>();
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
    if (_readBufferCount == 0) {
      Array<Byte> rentedBytes = ArrayPool<Byte>::in::get_Shared()->Rent(4096);
      Array<Char> rentedChars = ArrayPool<Char>::in::get_Shared()->Rent(_readCharBufferMaxSize);
      try {
      } catch (...) {
      } finally: {
        ArrayPool<Byte>::in::get_Shared()->Return(rentedBytes);
        ArrayPool<Char>::in::get_Shared()->Return(rentedChars);
      }
    }
    Int32 num2 = Math::Min(_readBufferCount, buffer.get_Length());
    MemoryExtensions::AsSpan(_readBuffer, _readBufferOffset, num2).CopyTo(buffer.get_Span());
    _readBufferOffset += num2;
    _readBufferCount -= num2;
    return num2;
  };
  EnsurePreReadConditions();
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<Int32>(Task<>::in::FromCanceled<Int32>(cancellationToken));
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
    } while (!completed)
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
    Int32 minimumLength = Math::Clamp(remainingOuterEncodedBytes.get_Length(), 4096, 1048576);
    Array<Char> scratchChars = ArrayPool<Char>::in::get_Shared()->Rent(minimumLength);
    Array<Byte> scratchBytes = ArrayPool<Byte>::in::get_Shared()->Rent(minimumLength);
    try {
      Boolean decoderFinished;
      do {
        Int32 bytesUsed;
        Int32 charsUsed;
        _thisDecoder->Convert(remainingOuterEncodedBytes.get_Span(), scratchChars, false, bytesUsed, charsUsed, decoderFinished);
        ReadOnlyMemory<Byte> readOnlyMemory = remainingOuterEncodedBytes;
        Int32 length = readOnlyMemory.get_Length();
      } while (!decoderFinished)
    } catch (...) {
    } finally: {
      ArrayPool<Char>::in::get_Shared()->Return(scratchChars);
      ArrayPool<Byte>::in::get_Shared()->Return(scratchBytes);
    }
  };
  EnsurePreWriteConditions();
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>(Task<>::in::FromCanceled(cancellationToken));
  }
  return WriteAsyncCore(buffer, cancellationToken);
}

void TranscodingStream___::WriteByte(Byte value) {
  Write(MemoryMarshal::CreateReadOnlySpan(value, 1));
}

} // namespace System::Private::CoreLib::System::Text::TranscodingStreamNamespace
