#include "StreamWriter-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/EncodingCache-dep.h>
#include <System.Private.CoreLib/System/IO/FileAccess.h>
#include <System.Private.CoreLib/System/IO/FileMode.h>
#include <System.Private.CoreLib/System/IO/FileOptions.h>
#include <System.Private.CoreLib/System/IO/FileShare.h>
#include <System.Private.CoreLib/System/IO/FileStream-dep.h>
#include <System.Private.CoreLib/System/IO/StreamWriter-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilderCache-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::IO::StreamWriterNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Text;
using namespace System::Threading::Tasks;

void StreamWriter___::_DisposeAsyncCore_d__33::MoveNext() {
  Int32 num = __1__state;
  StreamWriter streamWriter = __4__this;
  try {
    try {
      ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
      if (num == 0) {
        awaiter = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_0076;
      }
      if (!streamWriter->_disposed) {
        awaiter = streamWriter->FlushAsync()->ConfigureAwait(false).GetAwaiter();
        if (!awaiter.get_IsCompleted()) {
          num = (__1__state = 0);
          __u__1 = awaiter;
          __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
          return;
        }
        goto IL_0076;
      }
      goto end_IL_0011;

    IL_0076:
      awaiter.GetResult();

    end_IL_0011:
    } catch (...) {
    } finally: {
      if (num < 0) {
        streamWriter->CloseStreamFromDispose(true);
      }
    }
    GC::SuppressFinalize(streamWriter);
  } catch (Exception exception) {
    __1__state = -2;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  __t__builder.SetResult();
}

void StreamWriter___::_DisposeAsyncCore_d__33::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

void StreamWriter___::_WriteAsyncInternal_d__61::MoveNext() {
  Int32 num = __1__state;
  try {
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter3;
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter2;
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
    switch (num.get()) {
      default:
        if (charPos == charLen) {
          awaiter3 = _this->FlushAsyncInternal(false, false, charBuffer, charPos)->ConfigureAwait(false).GetAwaiter();
          if (!awaiter3.get_IsCompleted()) {
            num = (__1__state = 0);
            __u__1 = awaiter3;
            __t__builder.AwaitUnsafeOnCompleted(awaiter3, *this);
            return;
          }
          goto IL_00a3;
        }
        goto IL_00b1;
      case 0:
        awaiter3 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_00a3;
      case 1:
        awaiter2 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_017a;
      case 2:
        {
          awaiter = __u__1;
          __u__1 = rt::default__;
          num = (__1__state = -1);
          goto IL_025d;
        }
      IL_01d9:
        if (!autoFlush) {
          break;
        }
        awaiter = _this->FlushAsyncInternal(true, false, charBuffer, charPos)->ConfigureAwait(false).GetAwaiter();
        if (!awaiter.get_IsCompleted()) {
          num = (__1__state = 2);
          __u__1 = awaiter;
          __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
          return;
        }
        goto IL_025d;

      IL_025d:
        awaiter.GetResult();
        charPos = 0;
        break;

      IL_00a3:
        awaiter3.GetResult();
        charPos = 0;
        goto IL_00b1;

      IL_00b1:
        charBuffer[charPos] = value;
        charPos++;
        if (appendNewLine) {
          _i_5__2 = 0;
          goto IL_01c6;
        }
        goto IL_01d9;

      IL_017a:
        awaiter2.GetResult();
        charPos = 0;
        goto IL_0188;

      IL_01c6:
        if (_i_5__2 < coreNewLine->get_Length()) {
          if (charPos == charLen) {
            awaiter2 = _this->FlushAsyncInternal(false, false, charBuffer, charPos)->ConfigureAwait(false).GetAwaiter();
            if (!awaiter2.get_IsCompleted()) {
              num = (__1__state = 1);
              __u__1 = awaiter2;
              __t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
              return;
            }
            goto IL_017a;
          }
          goto IL_0188;
        }
        goto IL_01d9;

      IL_0188:
        charBuffer[charPos] = coreNewLine[_i_5__2];
        charPos++;
        _i_5__2++;
        goto IL_01c6;
    }
    _this->_charPos = charPos;
  } catch (Exception exception) {
    __1__state = -2;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  __t__builder.SetResult();
}

void StreamWriter___::_WriteAsyncInternal_d__61::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

void StreamWriter___::_WriteAsyncInternal_d__63::MoveNext() {
  Int32 num = __1__state;
  try {
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter3;
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter2;
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
    Int32 num2;
    switch (num.get()) {
      default:
        _count_5__2 = value->get_Length();
        _index_5__3 = 0;
        goto IL_0135;
      case 0:
        awaiter3 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_00c1;
      case 1:
        awaiter2 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_01e6;
      case 2:
        {
          awaiter = __u__1;
          __u__1 = rt::default__;
          num = (__1__state = -1);
          goto IL_02ca;
        }
      IL_0135:
        if (_count_5__2 > 0) {
          if (charPos == charLen) {
            awaiter3 = _this->FlushAsyncInternal(false, false, charBuffer, charPos)->ConfigureAwait(false).GetAwaiter();
            if (!awaiter3.get_IsCompleted()) {
              num = (__1__state = 0);
              __u__1 = awaiter3;
              __t__builder.AwaitUnsafeOnCompleted(awaiter3, *this);
              return;
            }
            goto IL_00c1;
          }
          goto IL_00cf;
        }
        if (appendNewLine) {
          _i_5__4 = 0;
          goto IL_0232;
        }
        goto IL_0245;

      IL_01f4:
        charBuffer[charPos] = coreNewLine[_i_5__4];
        charPos++;
        _i_5__4++;
        goto IL_0232;

      IL_00c1:
        awaiter3.GetResult();
        charPos = 0;
        goto IL_00cf;

      IL_0232:
        if (_i_5__4 < coreNewLine->get_Length()) {
          if (charPos == charLen) {
            awaiter2 = _this->FlushAsyncInternal(false, false, charBuffer, charPos)->ConfigureAwait(false).GetAwaiter();
            if (!awaiter2.get_IsCompleted()) {
              num = (__1__state = 1);
              __u__1 = awaiter2;
              __t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
              return;
            }
            goto IL_01e6;
          }
          goto IL_01f4;
        }
        goto IL_0245;

      IL_0245:
        if (!autoFlush) {
          break;
        }
        awaiter = _this->FlushAsyncInternal(true, false, charBuffer, charPos)->ConfigureAwait(false).GetAwaiter();
        if (!awaiter.get_IsCompleted()) {
          num = (__1__state = 2);
          __u__1 = awaiter;
          __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
          return;
        }
        goto IL_02ca;

      IL_00cf:
        num2 = charLen - charPos;
        if (num2 > _count_5__2) {
          num2 = _count_5__2;
        }
        value->CopyTo(_index_5__3, charBuffer, charPos, num2);
        charPos += num2;
        _index_5__3 += num2;
        _count_5__2 -= num2;
        goto IL_0135;

      IL_02ca:
        awaiter.GetResult();
        charPos = 0;
        break;

      IL_01e6:
        awaiter2.GetResult();
        charPos = 0;
        goto IL_01f4;
    }
    _this->_charPos = charPos;
  } catch (Exception exception) {
    __1__state = -2;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  __t__builder.SetResult();
}

void StreamWriter___::_WriteAsyncInternal_d__63::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

void StreamWriter___::_WriteAsyncInternal_d__66::MoveNext() {
  Int32 num = __1__state;
  try {
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter3;
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter2;
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
    Int32 num2;
    ReadOnlySpan<Char> readOnlySpan;
    switch (num.get()) {
      default:
        _copied_5__2 = 0;
        goto IL_0131;
      case 0:
        awaiter3 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_00ac;
      case 1:
        awaiter2 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_01e8;
      case 2:
        {
          awaiter = __u__1;
          __u__1 = rt::default__;
          num = (__1__state = -1);
          goto IL_02c8;
        }
      IL_0131:
        if (_copied_5__2 < source.get_Length()) {
          if (charPos == charLen) {
            awaiter3 = _this->FlushAsyncInternal(false, false, charBuffer, charPos, cancellationToken)->ConfigureAwait(false).GetAwaiter();
            if (!awaiter3.get_IsCompleted()) {
              num = (__1__state = 0);
              __u__1 = awaiter3;
              __t__builder.AwaitUnsafeOnCompleted(awaiter3, *this);
              return;
            }
            goto IL_00ac;
          }
          goto IL_00ba;
        }
        if (appendNewLine) {
          _i_5__3 = 0;
          goto IL_0234;
        }
        goto IL_0247;

      IL_01f6:
        charBuffer[charPos] = coreNewLine[_i_5__3];
        charPos++;
        _i_5__3++;
        goto IL_0234;

      IL_00ac:
        awaiter3.GetResult();
        charPos = 0;
        goto IL_00ba;

      IL_0234:
        if (_i_5__3 < coreNewLine->get_Length()) {
          if (charPos == charLen) {
            awaiter2 = _this->FlushAsyncInternal(false, false, charBuffer, charPos, cancellationToken)->ConfigureAwait(false).GetAwaiter();
            if (!awaiter2.get_IsCompleted()) {
              num = (__1__state = 1);
              __u__1 = awaiter2;
              __t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
              return;
            }
            goto IL_01e8;
          }
          goto IL_01f6;
        }
        goto IL_0247;

      IL_0247:
        if (!autoFlush) {
          break;
        }
        awaiter = _this->FlushAsyncInternal(true, false, charBuffer, charPos, cancellationToken)->ConfigureAwait(false).GetAwaiter();
        if (!awaiter.get_IsCompleted()) {
          num = (__1__state = 2);
          __u__1 = awaiter;
          __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
          return;
        }
        goto IL_02c8;

      IL_00ba:
        num2 = Math::Min(charLen - charPos, source.get_Length() - _copied_5__2);
        readOnlySpan = source.get_Span();
        readOnlySpan = readOnlySpan.Slice(_copied_5__2, num2);
        readOnlySpan.CopyTo(Span<Char>(charBuffer, charPos, num2));
        charPos += num2;
        _copied_5__2 += num2;
        goto IL_0131;

      IL_02c8:
        awaiter.GetResult();
        charPos = 0;
        break;

      IL_01e8:
        awaiter2.GetResult();
        charPos = 0;
        goto IL_01f6;
    }
    _this->_charPos = charPos;
  } catch (Exception exception) {
    __1__state = -2;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  __t__builder.SetResult();
}

void StreamWriter___::_WriteAsyncInternal_d__66::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

void StreamWriter___::_FlushAsyncInternal_d__74::MoveNext() {
  Int32 num = __1__state;
  try {
    ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter3;
    ConfiguredValueTaskAwaitable<>::ConfiguredValueTaskAwaiter awaiter2;
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
    Int32 bytes;
    switch (num.get()) {
      default:
        if (!haveWrittenPreamble) {
          _this->_haveWrittenPreamble = true;
          Array<Byte> preamble = encoding->GetPreamble();
          if (preamble->get_Length() != 0) {
            awaiter3 = stream->WriteAsync(ReadOnlyMemory<Byte>(preamble), cancellationToken).ConfigureAwait(false).GetAwaiter();
            if (!awaiter3.get_IsCompleted()) {
              num = (__1__state = 0);
              __u__1 = awaiter3;
              __t__builder.AwaitUnsafeOnCompleted(awaiter3, *this);
              return;
            }
            goto IL_00b3;
          }
        }
        goto IL_00ba;
      case 0:
        awaiter3 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_00b3;
      case 1:
        awaiter2 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_0164;
      case 2:
        {
          awaiter = __u__2;
          __u__2 = rt::default__;
          num = (__1__state = -1);
          break;
        }
      IL_00ba:
        bytes = encoder->GetBytes(charBuffer, 0, charPos, byteBuffer, 0, flushEncoder);
        if (bytes > 0) {
          awaiter2 = stream->WriteAsync(ReadOnlyMemory<Byte>(byteBuffer, 0, bytes), cancellationToken).ConfigureAwait(false).GetAwaiter();
          if (!awaiter2.get_IsCompleted()) {
            num = (__1__state = 1);
            __u__1 = awaiter2;
            __t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
            return;
          }
          goto IL_0164;
        }
        goto IL_016b;

      IL_0164:
        awaiter2.GetResult();
        goto IL_016b;

      IL_016b:
        if (flushStream) {
          awaiter = stream->FlushAsync(cancellationToken)->ConfigureAwait(false).GetAwaiter();
          if (!awaiter.get_IsCompleted()) {
            num = (__1__state = 2);
            __u__2 = awaiter;
            __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
            return;
          }
          break;
        }
        goto end_IL_0007;

      IL_00b3:
        awaiter3.GetResult();
        goto IL_00ba;
    }
    awaiter.GetResult();

  end_IL_0007:
  } catch (Exception exception) {
    __1__state = -2;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  __t__builder.SetResult();
}

void StreamWriter___::_FlushAsyncInternal_d__74::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

Encoding StreamWriter___::get_UTF8NoBOM() {
  return EncodingCache::UTF8NoBOM;
}

Boolean StreamWriter___::get_AutoFlush() {
  return _autoFlush;
}

void StreamWriter___::set_AutoFlush(Boolean value) {
  CheckAsyncTaskInProgress();
  _autoFlush = value;
  if (value) {
    Flush(true, false);
  }
}

Stream StreamWriter___::get_BaseStream() {
  return _stream;
}

Encoding StreamWriter___::get_Encoding() {
  return _encoding;
}

void StreamWriter___::CheckAsyncTaskInProgress() {
  if (!_asyncWriteTask->get_IsCompleted()) {
    ThrowAsyncIOInProgress();
  }
}

void StreamWriter___::ThrowAsyncIOInProgress() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_AsyncIOInProgress());
}

void StreamWriter___::ctor(Stream stream) {
}

void StreamWriter___::ctor(Stream stream, Encoding encoding) {
}

void StreamWriter___::ctor(Stream stream, Encoding encoding, Int32 bufferSize) {
}

void StreamWriter___::ctor(Stream stream, Encoding encoding, Int32 bufferSize, Boolean leaveOpen) {
  _asyncWriteTask = Task<>::in::get_CompletedTask();
  TextWriter::in::ctor(nullptr);
  if (stream == nullptr) {
    rt::throw_exception<ArgumentNullException>("stream");
  }
  if (encoding == nullptr) {
    encoding = get_UTF8NoBOM();
  }
  if (!stream->get_CanWrite()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_StreamNotWritable());
  }
  if (bufferSize == -1) {
    bufferSize = 1024;
  } else if (bufferSize <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", SR::get_ArgumentOutOfRange_NeedPosNum());
  }

  _stream = stream;
  _encoding = encoding;
  _encoder = _encoding->GetEncoder();
  if (bufferSize < 128) {
    bufferSize = 128;
  }
  _charBuffer = rt::newarr<Array<Char>>(bufferSize);
  _byteBuffer = rt::newarr<Array<Byte>>(_encoding->GetMaxByteCount(bufferSize));
  _charLen = bufferSize;
  if (_stream->get_CanSeek() && _stream->get_Position() > 0) {
    _haveWrittenPreamble = true;
  }
  _closable = !leaveOpen;
}

void StreamWriter___::ctor(String path) {
}

void StreamWriter___::ctor(String path, Boolean append) {
}

void StreamWriter___::ctor(String path, Boolean append, Encoding encoding) {
}

void StreamWriter___::ctor(String path, Boolean append, Encoding encoding, Int32 bufferSize) {
}

Stream StreamWriter___::ValidateArgsAndOpenPath(String path, Boolean append, Encoding encoding, Int32 bufferSize) {
  if (path == nullptr) {
    rt::throw_exception<ArgumentNullException>("path");
  }
  if (encoding == nullptr) {
    rt::throw_exception<ArgumentNullException>("encoding");
  }
  if (path->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyPath());
  }
  if (bufferSize <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  return rt::newobj<FileStream>(path, append ? FileMode::Append : FileMode::Create, FileAccess::Write, FileShare::Read, 4096, FileOptions::SequentialScan);
}

void StreamWriter___::Close() {
  Dispose(true);
  GC::SuppressFinalize((StreamWriter)this);
}

void StreamWriter___::Dispose(Boolean disposing) {
  try {
    if (!_disposed && disposing) {
      CheckAsyncTaskInProgress();
      Flush(true, true);
    }
  } catch (...) {
  } finally: {
    CloseStreamFromDispose(disposing);
  }
}

void StreamWriter___::CloseStreamFromDispose(Boolean disposing) {
  if (!_closable || _disposed) {
    return;
  }
  try {
    if (disposing) {
      _stream->Close();
    }
  } catch (...) {
  } finally: {
    _disposed = true;
    _charLen = 0;
    TextWriter::in::Dispose(disposing);
  }
}

ValueTask<> StreamWriter___::DisposeAsync() {
  if (!(GetType() != typeof<StreamWriter>())) {
    return DisposeAsyncCore();
  }
  return TextWriter::in::DisposeAsync();
}

ValueTask<> StreamWriter___::DisposeAsyncCore() {
  try {
    if (!_disposed) {
    }
  } catch (...) {
  } finally: {
    CloseStreamFromDispose(true);
  }
  GC::SuppressFinalize((StreamWriter)this);
}

void StreamWriter___::Flush() {
  CheckAsyncTaskInProgress();
  Flush(true, true);
}

void StreamWriter___::Flush(Boolean flushStream, Boolean flushEncoder) {
  ThrowIfDisposed();
  if (_charPos == 0 && !flushStream && !flushEncoder) {
    return;
  }
  if (!_haveWrittenPreamble) {
    _haveWrittenPreamble = true;
    ReadOnlySpan<Byte> preamble = _encoding->get_Preamble();
    if (preamble.get_Length() > 0) {
      _stream->Write(preamble);
    }
  }
  Int32 bytes = _encoder->GetBytes(_charBuffer, 0, _charPos, _byteBuffer, 0, flushEncoder);
  _charPos = 0;
  if (bytes > 0) {
    _stream->Write(_byteBuffer, 0, bytes);
  }
  if (flushStream) {
    _stream->Flush();
  }
}

void StreamWriter___::Write(Char value) {
  CheckAsyncTaskInProgress();
  if (_charPos == _charLen) {
    Flush(false, false);
  }
  _charBuffer[_charPos] = value;
  _charPos++;
  if (_autoFlush) {
    Flush(true, false);
  }
}

void StreamWriter___::Write(Array<Char> buffer) {
  WriteSpan(buffer, false);
}

void StreamWriter___::Write(Array<Char> buffer, Int32 index, Int32 count) {
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
  WriteSpan(MemoryExtensions::AsSpan(buffer, index, count), false);
}

void StreamWriter___::Write(ReadOnlySpan<Char> buffer) {
  if (GetType() == typeof<StreamWriter>()) {
    WriteSpan(buffer, false);
  } else {
    TextWriter::in::Write(buffer);
  }
}

void StreamWriter___::WriteSpan(ReadOnlySpan<Char> buffer, Boolean appendNewLine) {
  CheckAsyncTaskInProgress();
  if (buffer.get_Length() <= 4 && buffer.get_Length() <= _charLen - _charPos) {
    for (Int32 i = 0; i < buffer.get_Length(); i++) {
      _charBuffer[_charPos++] = buffer[i];
    }
  } else {
    ThrowIfDisposed();
    Array<Char> charBuffer = _charBuffer;
    {
      Char* ptr = rt::fixed(&MemoryMarshal::GetReference(buffer));
      {
        Char* ptr3 = rt::fixed(&charBuffer[0]);
        Char* ptr2 = ptr;
        Int32 num = buffer.get_Length();
        Int32 num2 = _charPos;
        while (num > 0) {
          if (num2 == charBuffer->get_Length()) {
            Flush(false, false);
            num2 = 0;
          }
          Int32 num3 = Math::Min(charBuffer->get_Length() - num2, num);
          Int32 num4 = num3 * 2;
          Buffer::MemoryCopy(ptr2, ptr3 + num2, num4, num4);
          _charPos += num3;
          num2 += num3;
          ptr2 += num3;
          num -= num3;
        }
      }
    }
  }
  if (appendNewLine) {
    Array<Char> coreNewLine = CoreNewLine;
    for (Int32 j = 0; j < coreNewLine->get_Length(); j++) {
      if (_charPos == _charLen) {
        Flush(false, false);
      }
      _charBuffer[_charPos] = coreNewLine[j];
      _charPos++;
    }
  }
  if (_autoFlush) {
    Flush(true, false);
  }
}

void StreamWriter___::Write(String value) {
  WriteSpan(value, false);
}

void StreamWriter___::WriteLine(String value) {
  CheckAsyncTaskInProgress();
  WriteSpan(value, true);
}

void StreamWriter___::WriteLine(ReadOnlySpan<Char> value) {
  if (GetType() == typeof<StreamWriter>()) {
    CheckAsyncTaskInProgress();
    WriteSpan(value, true);
  } else {
    TextWriter::in::WriteLine(value);
  }
}

void StreamWriter___::WriteFormatHelper(String format, ParamsArray args, Boolean appendNewLine) {
  StringBuilder stringBuilder = StringBuilderCache::Acquire(((format != nullptr) ? format->get_Length() : 0) + args.get_Length() * 8)->AppendFormatHelper(nullptr, format, args);
  StringBuilder::in::ChunkEnumerator chunks = stringBuilder->GetChunks();
  Boolean flag = chunks.MoveNext();
  while (flag) {
    ReadOnlySpan<Char> span = chunks.get_Current().get_Span();
    flag = chunks.MoveNext();
    WriteSpan(span, !flag && appendNewLine);
  }
  StringBuilderCache::Release(stringBuilder);
}

void StreamWriter___::Write(String format, Object arg0) {
  if (GetType() == typeof<StreamWriter>()) {
    WriteFormatHelper(format, ParamsArray(arg0), false);
  } else {
    TextWriter::in::Write(format, arg0);
  }
}

void StreamWriter___::Write(String format, Object arg0, Object arg1) {
  if (GetType() == typeof<StreamWriter>()) {
    WriteFormatHelper(format, ParamsArray(arg0, arg1), false);
  } else {
    TextWriter::in::Write(format, arg0, arg1);
  }
}

void StreamWriter___::Write(String format, Object arg0, Object arg1, Object arg2) {
  if (GetType() == typeof<StreamWriter>()) {
    WriteFormatHelper(format, ParamsArray(arg0, arg1, arg2), false);
  } else {
    TextWriter::in::Write(format, arg0, arg1, arg2);
  }
}

void StreamWriter___::Write(String format, Array<Object> arg) {
  if (GetType() == typeof<StreamWriter>()) {
    if (arg == nullptr) {
      rt::throw_exception<ArgumentNullException>((format == nullptr) ? "format" : "arg");
    }
    WriteFormatHelper(format, ParamsArray(arg), false);
  } else {
    TextWriter::in::Write(format, arg);
  }
}

void StreamWriter___::WriteLine(String format, Object arg0) {
  if (GetType() == typeof<StreamWriter>()) {
    WriteFormatHelper(format, ParamsArray(arg0), true);
  } else {
    TextWriter::in::WriteLine(format, arg0);
  }
}

void StreamWriter___::WriteLine(String format, Object arg0, Object arg1) {
  if (GetType() == typeof<StreamWriter>()) {
    WriteFormatHelper(format, ParamsArray(arg0, arg1), true);
  } else {
    TextWriter::in::WriteLine(format, arg0, arg1);
  }
}

void StreamWriter___::WriteLine(String format, Object arg0, Object arg1, Object arg2) {
  if (GetType() == typeof<StreamWriter>()) {
    WriteFormatHelper(format, ParamsArray(arg0, arg1, arg2), true);
  } else {
    TextWriter::in::WriteLine(format, arg0, arg1, arg2);
  }
}

void StreamWriter___::WriteLine(String format, Array<Object> arg) {
  if (GetType() == typeof<StreamWriter>()) {
    if (arg == nullptr) {
      rt::throw_exception<ArgumentNullException>("arg");
    }
    WriteFormatHelper(format, ParamsArray(arg), true);
  } else {
    TextWriter::in::WriteLine(format, arg);
  }
}

Task<> StreamWriter___::WriteAsync(Char value) {
  if (GetType() != typeof<StreamWriter>()) {
    return TextWriter::in::WriteAsync(value);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return _asyncWriteTask = WriteAsyncInternal((StreamWriter)this, value, _charBuffer, _charPos, _charLen, CoreNewLine, _autoFlush, false);
}

Task<> StreamWriter___::WriteAsyncInternal(StreamWriter _this, Char value, Array<Char> charBuffer, Int32 charPos, Int32 charLen, Array<Char> coreNewLine, Boolean autoFlush, Boolean appendNewLine) {
  if (charPos == charLen) {
  }
  charBuffer[charPos] = value;
  charPos++;
  if (appendNewLine) {
    for (Int32 i = 0; i < coreNewLine->get_Length(); i++) {
      if (charPos == charLen) {
      }
      charBuffer[charPos] = coreNewLine[i];
      charPos++;
    }
  }
  if (autoFlush) {
  }
  _this->_charPos = charPos;
}

Task<> StreamWriter___::WriteAsync(String value) {
  if (GetType() != typeof<StreamWriter>()) {
    return TextWriter::in::WriteAsync(value);
  }
  if (value != nullptr) {
    ThrowIfDisposed();
    CheckAsyncTaskInProgress();
    return _asyncWriteTask = WriteAsyncInternal((StreamWriter)this, value, _charBuffer, _charPos, _charLen, CoreNewLine, _autoFlush, false);
  }
  return Task<>::in::get_CompletedTask();
}

Task<> StreamWriter___::WriteAsyncInternal(StreamWriter _this, String value, Array<Char> charBuffer, Int32 charPos, Int32 charLen, Array<Char> coreNewLine, Boolean autoFlush, Boolean appendNewLine) {
  Int32 count = value->get_Length();
  Int32 index = 0;
  while (count > 0) {
    if (charPos == charLen) {
    }
    Int32 num = charLen - charPos;
    if (num > count) {
      num = count;
    }
    value->CopyTo(index, charBuffer, charPos, num);
    charPos += num;
    index += num;
    count -= num;
  }
  if (appendNewLine) {
    for (Int32 i = 0; i < coreNewLine->get_Length(); i++) {
      if (charPos == charLen) {
      }
      charBuffer[charPos] = coreNewLine[i];
      charPos++;
    }
  }
  if (autoFlush) {
  }
  _this->_charPos = charPos;
}

Task<> StreamWriter___::WriteAsync(Array<Char> buffer, Int32 index, Int32 count) {
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
  if (GetType() != typeof<StreamWriter>()) {
    return TextWriter::in::WriteAsync(buffer, index, count);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return _asyncWriteTask = WriteAsyncInternal((StreamWriter)this, ReadOnlyMemory<Char>(buffer, index, count), _charBuffer, _charPos, _charLen, CoreNewLine, _autoFlush, false, rt::default__);
}

template <>
Task<> StreamWriter___::WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (GetType() != typeof<StreamWriter>()) {
    return TextWriter::in::WriteAsync(buffer, cancellationToken);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  return _asyncWriteTask = WriteAsyncInternal((StreamWriter)this, buffer, _charBuffer, _charPos, _charLen, CoreNewLine, _autoFlush, false, cancellationToken);
}

Task<> StreamWriter___::WriteAsyncInternal(StreamWriter _this, ReadOnlyMemory<Char> source, Array<Char> charBuffer, Int32 charPos, Int32 charLen, Array<Char> coreNewLine, Boolean autoFlush, Boolean appendNewLine, CancellationToken cancellationToken) {
  Int32 num;
  for (Int32 copied = 0; copied < source.get_Length(); copied += num) {
    if (charPos == charLen) {
    }
    num = Math::Min(charLen - charPos, source.get_Length() - copied);
    ReadOnlySpan<Char> readOnlySpan = source.get_Span();
    readOnlySpan = readOnlySpan.Slice(copied, num);
    readOnlySpan.CopyTo(Span<Char>(charBuffer, charPos, num));
    charPos += num;
  }
  if (appendNewLine) {
    for (Int32 i = 0; i < coreNewLine->get_Length(); i++) {
      if (charPos == charLen) {
      }
      charBuffer[charPos] = coreNewLine[i];
      charPos++;
    }
  }
  if (autoFlush) {
  }
  _this->_charPos = charPos;
}

Task<> StreamWriter___::WriteLineAsync() {
  if (GetType() != typeof<StreamWriter>()) {
    return TextWriter::in::WriteLineAsync();
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return _asyncWriteTask = WriteAsyncInternal((StreamWriter)this, ReadOnlyMemory<Char>::get_Empty(), _charBuffer, _charPos, _charLen, CoreNewLine, _autoFlush, true, rt::default__);
}

Task<> StreamWriter___::WriteLineAsync(Char value) {
  if (GetType() != typeof<StreamWriter>()) {
    return TextWriter::in::WriteLineAsync(value);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return _asyncWriteTask = WriteAsyncInternal((StreamWriter)this, value, _charBuffer, _charPos, _charLen, CoreNewLine, _autoFlush, true);
}

Task<> StreamWriter___::WriteLineAsync(String value) {
  if (value == nullptr) {
    return WriteLineAsync();
  }
  if (GetType() != typeof<StreamWriter>()) {
    return TextWriter::in::WriteLineAsync(value);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return _asyncWriteTask = WriteAsyncInternal((StreamWriter)this, value, _charBuffer, _charPos, _charLen, CoreNewLine, _autoFlush, true);
}

Task<> StreamWriter___::WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count) {
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
  if (GetType() != typeof<StreamWriter>()) {
    return TextWriter::in::WriteLineAsync(buffer, index, count);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return _asyncWriteTask = WriteAsyncInternal((StreamWriter)this, ReadOnlyMemory<Char>(buffer, index, count), _charBuffer, _charPos, _charLen, CoreNewLine, _autoFlush, true, rt::default__);
}

template <>
Task<> StreamWriter___::WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (GetType() != typeof<StreamWriter>()) {
    return TextWriter::in::WriteLineAsync(buffer, cancellationToken);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  return _asyncWriteTask = WriteAsyncInternal((StreamWriter)this, buffer, _charBuffer, _charPos, _charLen, CoreNewLine, _autoFlush, true, cancellationToken);
}

Task<> StreamWriter___::FlushAsync() {
  if (GetType() != typeof<StreamWriter>()) {
    return TextWriter::in::FlushAsync();
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return _asyncWriteTask = FlushAsyncInternal(true, true, _charBuffer, _charPos);
}

template <>
Task<> StreamWriter___::FlushAsyncInternal(Boolean flushStream, Boolean flushEncoder, Array<Char> sCharBuffer, Int32 sCharPos, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  if (sCharPos == 0 && !flushStream && !flushEncoder) {
    return Task<>::in::get_CompletedTask();
  }
  Task<> result = FlushAsyncInternal((StreamWriter)this, flushStream, flushEncoder, sCharBuffer, sCharPos, _haveWrittenPreamble, _encoding, _encoder, _byteBuffer, _stream, cancellationToken);
  _charPos = 0;
  return result;
}

Task<> StreamWriter___::FlushAsyncInternal(StreamWriter _this, Boolean flushStream, Boolean flushEncoder, Array<Char> charBuffer, Int32 charPos, Boolean haveWrittenPreamble, Encoding encoding, Encoder encoder, Array<Byte> byteBuffer, Stream stream, CancellationToken cancellationToken) {
  if (!haveWrittenPreamble) {
    _this->_haveWrittenPreamble = true;
    Array<Byte> preamble = encoding->GetPreamble();
    if (preamble->get_Length() != 0) {
    }
  }
  Int32 bytes = encoder->GetBytes(charBuffer, 0, charPos, byteBuffer, 0, flushEncoder);
  if (bytes > 0) {
  }
  if (flushStream) {
  }
}

void StreamWriter___::ThrowIfDisposed() {
  auto ThrowObjectDisposedException = []() -> void {
    rt::throw_exception<ObjectDisposedException>(GetType()->get_Name(), SR::get_ObjectDisposed_WriterClosed());
  };
  if (_disposed) {
    ThrowObjectDisposedException();
  }
}

void StreamWriter___::cctor() {
  Null = rt::newobj<StreamWriter>(Stream::in::Null, get_UTF8NoBOM(), 128, true);
}

void StreamWriter___::_ThrowIfDisposed_g__ThrowObjectDisposedException75_0() {
  rt::throw_exception<ObjectDisposedException>(GetType()->get_Name(), SR::get_ObjectDisposed_WriterClosed());
}

} // namespace System::Private::CoreLib::System::IO::StreamWriterNamespace
