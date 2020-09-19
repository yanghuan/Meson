#include "StreamReader-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/FileAccess.h>
#include <System.Private.CoreLib/System/IO/FileMode.h>
#include <System.Private.CoreLib/System/IO/FileOptions.h>
#include <System.Private.CoreLib/System/IO/FileShare.h>
#include <System.Private.CoreLib/System/IO/FileStream-dep.h>
#include <System.Private.CoreLib/System/IO/StreamReader-dep.h>
#include <System.Private.CoreLib/System/Memory-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/ReadOnlySpan-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/UTF32Encoding-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::IO::StreamReaderNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Text;
using namespace System::Threading;
using namespace System::Threading::Tasks;

Encoding NullStreamReader___::get_CurrentEncoding() {
  return Encoding::in::get_Unicode();
}

void NullStreamReader___::Dispose(Boolean disposing) {
}

Int32 NullStreamReader___::Peek() {
  return -1;
}

Int32 NullStreamReader___::Read() {
  return -1;
}

Int32 NullStreamReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  return 0;
}

String NullStreamReader___::ReadLine() {
  return nullptr;
}

String NullStreamReader___::ReadToEnd() {
  return String::in::Empty;
}

Int32 NullStreamReader___::ReadBuffer() {
  return 0;
}

void NullStreamReader___::ctor() {
}

void StreamReader___::_ReadLineAsyncInternal_d__59::MoveNext() {
  Int32 num = __1__state;
  StreamReader streamReader = __4__this;
  String result3;
  try {
    Boolean flag2;
    ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter3;
    ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter2;
    ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter;
    Int32 charLen;
    Array<Char> charBuffer;
    Int32 result;
    Boolean flag3;
    Int32 result2;
    Boolean flag4;
    Int32 num2;
    Char c;
    Int32 charPos;
    Boolean flag5;
    Int32 result4;
    switch (num.get()) {
      default:
        {
          Boolean flag = streamReader->_charPos == streamReader->_charLen;
          flag2 = flag;
          if (flag2) {
            awaiter3 = streamReader->ReadBufferAsync(CancellationToken::get_None()).ConfigureAwait(false).GetAwaiter();
            if (!awaiter3.get_IsCompleted()) {
              num = (__1__state = 0);
              __u__1 = awaiter3;
              __t__builder.AwaitUnsafeOnCompleted(awaiter3, *this);
              return;
            }
            goto IL_00a0;
          }
          goto IL_00b0;
        }case 0:
        awaiter3 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_00a0;
      case 1:
        awaiter2 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_01d2;
      case 2:
        {
          awaiter = __u__1;
          __u__1 = rt::default__;
          num = (__1__state = -1);
          goto IL_02bf;
        }
      IL_0227:
        num2 = charLen - charPos;
        if (_sb_5__2 == nullptr) {
          _sb_5__2 = rt::newobj<StringBuilder>(num2 + 80);
        }
        _sb_5__2->Append(charBuffer, charPos, num2);
        awaiter = streamReader->ReadBufferAsync(CancellationToken::get_None()).ConfigureAwait(false).GetAwaiter();
        if (!awaiter.get_IsCompleted()) {
          num = (__1__state = 2);
          __u__1 = awaiter;
          __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
          return;
        }
        goto IL_02bf;

      IL_01d2:
        result = awaiter2.GetResult();
        flag3 = (result > 0);
        goto IL_01e2;

      IL_00a0:
        result2 = awaiter3.GetResult();
        flag2 = (result2 == 0);
        goto IL_00b0;

      IL_00b0:
        if (flag2) {
          result3 = nullptr;
          break;
        }
        _sb_5__2 = nullptr;
        goto IL_00c2;

      IL_01e6:
        if (flag4) {
          charPos = streamReader->_charPos;
          if (streamReader->_charBuffer[charPos] == '\n') {
            charPos = (streamReader->_charPos = charPos + 1);
          }
        }
        result3 = _s_5__3;
        break;

      IL_01e2:
        flag4 = flag3;
        goto IL_01e6;

      IL_00c2:
        charBuffer = streamReader->_charBuffer;
        charLen = streamReader->_charLen;
        charPos = streamReader->_charPos;
        num2 = charPos;
        while (true) {
          c = charBuffer[num2];
          if (c == '\r' || c == '\n') {
            break;
          }
          num2++;
          if (num2 < charLen) {
            continue;
          }
          goto IL_0227;
        }
        if (_sb_5__2 != nullptr) {
          _sb_5__2->Append(charBuffer, charPos, num2 - charPos);
          _s_5__3 = _sb_5__2->ToString();
        } else {
          _s_5__3 = rt::newstr<String>(charBuffer, charPos, num2 - charPos);
        }
        charPos = (streamReader->_charPos = num2 + 1);
        flag5 = (c == '\r');
        flag4 = flag5;
        if (flag4) {
          Boolean flag6 = charPos < charLen;
          flag3 = flag6;
          if (!flag3) {
            awaiter2 = streamReader->ReadBufferAsync(CancellationToken::get_None()).ConfigureAwait(false).GetAwaiter();
            if (!awaiter2.get_IsCompleted()) {
              num = (__1__state = 1);
              __u__1 = awaiter2;
              __t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
              return;
            }
            goto IL_01d2;
          }
          goto IL_01e2;
        }
        goto IL_01e6;

      IL_02bf:
        result4 = awaiter.GetResult();
        if (result4 <= 0) {
          result3 = _sb_5__2->ToString();
          break;
        }
        goto IL_00c2;
    }
  } catch (Exception exception) {
    __1__state = -2;
    _sb_5__2 = nullptr;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  _sb_5__2 = nullptr;
  __t__builder.SetResult(result3);
}

void StreamReader___::_ReadLineAsyncInternal_d__59::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

void StreamReader___::_ReadToEndAsyncInternal_d__61::MoveNext() {
  Int32 num = __1__state;
  StreamReader streamReader = __4__this;
  String result;
  try {
    if (num != 0) {
      _sb_5__2 = rt::newobj<StringBuilder>(streamReader->_charLen - streamReader->_charPos);
      goto IL_002c;
    }
    ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter = __u__1;
    __u__1 = rt::default__;
    num = (__1__state = -1);
    goto IL_00c1;

  IL_00c1:
    awaiter.GetResult();
    if (streamReader->_charLen > 0) {
      goto IL_002c;
    }
    result = _sb_5__2->ToString();
    goto end_IL_000e;

  IL_002c:
    Int32 charPos = streamReader->_charPos;
    _sb_5__2->Append(streamReader->_charBuffer, charPos, streamReader->_charLen - charPos);
    streamReader->_charPos = streamReader->_charLen;
    awaiter = streamReader->ReadBufferAsync(CancellationToken::get_None()).ConfigureAwait(false).GetAwaiter();
    if (!awaiter.get_IsCompleted()) {
      num = (__1__state = 0);
      __u__1 = awaiter;
      __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
      return;
    }
    goto IL_00c1;

  end_IL_000e:
  } catch (Exception exception) {
    __1__state = -2;
    _sb_5__2 = nullptr;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  _sb_5__2 = nullptr;
  __t__builder.SetResult(result);
}

void StreamReader___::_ReadToEndAsyncInternal_d__61::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

void StreamReader___::_ReadAsyncInternal_d__64::MoveNext() {
  Int32 num = __1__state;
  StreamReader streamReader = __4__this;
  Int32 result2;
  try {
    Boolean flag2;
    ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter3;
    ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter2;
    ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter;
    Int32 result;
    Int32 num2;
    Int32 result3;
    Int32 num3;
    switch (num.get()) {
      default:
        {
          Boolean flag = streamReader->_charPos == streamReader->_charLen;
          flag2 = flag;
          if (flag2) {
            awaiter3 = streamReader->ReadBufferAsync(cancellationToken).ConfigureAwait(false).GetAwaiter();
            if (!awaiter3.get_IsCompleted()) {
              num = (__1__state = 0);
              __u__1 = awaiter3;
              __t__builder.AwaitUnsafeOnCompleted(awaiter3, *this);
              return;
            }
            goto IL_00a1;
          }
          goto IL_00b1;
        }case 0:
        awaiter3 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_00a1;
      case 1:
        awaiter2 = __u__1;
        __u__1 = rt::default__;
        num = (__1__state = -1);
        goto IL_01e5;
      case 2:
        {
          awaiter = __u__1;
          __u__1 = rt::default__;
          num = (__1__state = -1);
          goto IL_0327;
        }
      IL_0446:
        if (_n_5__7 > _count_5__6) {
          _n_5__7 = _count_5__6;
        }
        if (!_readToUserBuffer_5__3) {
          Span<Char>(streamReader->_charBuffer, streamReader->_charPos, _n_5__7).CopyTo(buffer.get_Span().Slice(_charsRead_5__2));
          streamReader->_charPos += _n_5__7;
        }
        _charsRead_5__2 += _n_5__7;
        _count_5__6 -= _n_5__7;
        if (streamReader->_isBlocked) {
          break;
        }
        goto IL_04e3;

      IL_043b:
        if (_n_5__7 == 0) {
          break;
        }
        goto IL_0446;

      IL_00a1:
        result = awaiter3.GetResult();
        flag2 = (result == 0);
        goto IL_00b1;

      IL_00b1:
        if (!flag2) {
          _charsRead_5__2 = 0;
          _readToUserBuffer_5__3 = false;
          _tmpByteBuffer_5__4 = streamReader->_byteBuffer;
          _tmpStream_5__5 = streamReader->_stream;
          _count_5__6 = buffer.get_Length();
          goto IL_04e3;
        }
        result2 = 0;
        goto end_IL_000e;

      IL_014a:
        if (streamReader->_checkPreamble) {
          Int32 bytePos = streamReader->_bytePos;
          awaiter2 = _tmpStream_5__5->ReadAsync(Memory<Byte>(_tmpByteBuffer_5__4, bytePos, _tmpByteBuffer_5__4->get_Length() - bytePos), cancellationToken).ConfigureAwait(false).GetAwaiter();
          if (!awaiter2.get_IsCompleted()) {
            num = (__1__state = 1);
            __u__1 = awaiter2;
            __t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
            return;
          }
          goto IL_01e5;
        }
        awaiter = _tmpStream_5__5->ReadAsync(Memory<Byte>(_tmpByteBuffer_5__4), cancellationToken).ConfigureAwait(false).GetAwaiter();
        if (!awaiter.get_IsCompleted()) {
          num = (__1__state = 2);
          __u__1 = awaiter;
          __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
          return;
        }
        goto IL_0327;

      IL_034c:
        streamReader->_isBlocked = (streamReader->_byteLen < _tmpByteBuffer_5__4->get_Length());
        if (!streamReader->IsPreamble()) {
          if (streamReader->_detectEncoding && streamReader->_byteLen >= 2) {
            streamReader->DetectEncoding();
            _readToUserBuffer_5__3 = (_count_5__6 >= streamReader->_maxCharsPerBuffer);
          }
          streamReader->_charPos = 0;
          if (_readToUserBuffer_5__3) {
            _n_5__7 += streamReader->_decoder->GetChars(ReadOnlySpan<Byte>(_tmpByteBuffer_5__4, 0, streamReader->_byteLen), buffer.get_Span().Slice(_charsRead_5__2), false);
            streamReader->_charLen = 0;
          } else {
            _n_5__7 = streamReader->_decoder->GetChars(_tmpByteBuffer_5__4, 0, streamReader->_byteLen, streamReader->_charBuffer, 0);
            streamReader->_charLen += _n_5__7;
          }
        }
        if (_n_5__7 == 0) {
          goto IL_014a;
        }
        goto IL_043b;

      IL_04e3:
        if (_count_5__6 <= 0) {
          break;
        }
        _n_5__7 = streamReader->_charLen - streamReader->_charPos;
        if (_n_5__7 == 0) {
          streamReader->_charLen = 0;
          streamReader->_charPos = 0;
          if (!streamReader->_checkPreamble) {
            streamReader->_byteLen = 0;
          }
          _readToUserBuffer_5__3 = (_count_5__6 >= streamReader->_maxCharsPerBuffer);
          goto IL_014a;
        }
        goto IL_0446;

      IL_0327:
        num2 = (streamReader->_byteLen = awaiter.GetResult());
        if (streamReader->_byteLen != 0) {
          goto IL_034c;
        }
        streamReader->_isBlocked = true;
        goto IL_043b;

      IL_01e5:
        result3 = awaiter2.GetResult();
        num3 = result3;
        if (num3 == 0) {
          if (streamReader->_byteLen > 0) {
            if (_readToUserBuffer_5__3) {
              _n_5__7 = streamReader->_decoder->GetChars(ReadOnlySpan<Byte>(_tmpByteBuffer_5__4, 0, streamReader->_byteLen), buffer.get_Span().Slice(_charsRead_5__2), false);
              streamReader->_charLen = 0;
            } else {
              _n_5__7 = streamReader->_decoder->GetChars(_tmpByteBuffer_5__4, 0, streamReader->_byteLen, streamReader->_charBuffer, 0);
              streamReader->_charLen += _n_5__7;
            }
          }
          streamReader->_isBlocked = true;
          goto IL_043b;
        }
        streamReader->_byteLen += num3;
        goto IL_034c;
    }
    result2 = _charsRead_5__2;

  end_IL_000e:
  } catch (Exception exception) {
    __1__state = -2;
    _tmpByteBuffer_5__4 = nullptr;
    _tmpStream_5__5 = nullptr;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  _tmpByteBuffer_5__4 = nullptr;
  _tmpStream_5__5 = nullptr;
  __t__builder.SetResult(result2);
}

void StreamReader___::_ReadAsyncInternal_d__64::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

void StreamReader___::_ReadBufferAsync_d__67::MoveNext() {
  Int32 num = __1__state;
  StreamReader streamReader = __4__this;
  Int32 charLen;
  try {
    ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter;
    if (num != 0) {
      if (num != 1) {
        streamReader->_charLen = 0;
        streamReader->_charPos = 0;
        _tmpByteBuffer_5__2 = streamReader->_byteBuffer;
        _tmpStream_5__3 = streamReader->_stream;
        if (!streamReader->_checkPreamble) {
          streamReader->_byteLen = 0;
        }
        goto IL_0050;
      }
      awaiter = __u__1;
      __u__1 = rt::default__;
      num = (__1__state = -1);
      goto IL_01dc;
    }
    ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter2 = __u__1;
    __u__1 = rt::default__;
    num = (__1__state = -1);
    goto IL_00e8;

  IL_00e8:
    Int32 result = awaiter2.GetResult();
    Int32 num2 = result;
    if (num2 != 0) {
      streamReader->_byteLen += num2;
      goto IL_0201;
    }
    if (streamReader->_byteLen > 0) {
      streamReader->_charLen += streamReader->_decoder->GetChars(_tmpByteBuffer_5__2, 0, streamReader->_byteLen, streamReader->_charBuffer, streamReader->_charLen);
      streamReader->_bytePos = 0;
      streamReader->_byteLen = 0;
    }
    charLen = streamReader->_charLen;
    goto end_IL_000e;

  IL_0201:
    streamReader->_isBlocked = (streamReader->_byteLen < _tmpByteBuffer_5__2->get_Length());
    if (!streamReader->IsPreamble()) {
      if (streamReader->_detectEncoding && streamReader->_byteLen >= 2) {
        streamReader->DetectEncoding();
      }
      streamReader->_charLen += streamReader->_decoder->GetChars(_tmpByteBuffer_5__2, 0, streamReader->_byteLen, streamReader->_charBuffer, streamReader->_charLen);
    }
    if (streamReader->_charLen == 0) {
      goto IL_0050;
    }
    charLen = streamReader->_charLen;
    goto end_IL_000e;

  IL_0050:
    if (streamReader->_checkPreamble) {
      Int32 bytePos = streamReader->_bytePos;
      awaiter2 = _tmpStream_5__3->ReadAsync(Memory<Byte>(_tmpByteBuffer_5__2, bytePos, _tmpByteBuffer_5__2->get_Length() - bytePos), cancellationToken).ConfigureAwait(false).GetAwaiter();
      if (!awaiter2.get_IsCompleted()) {
        num = (__1__state = 0);
        __u__1 = awaiter2;
        __t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
        return;
      }
      goto IL_00e8;
    }
    awaiter = _tmpStream_5__3->ReadAsync(Memory<Byte>(_tmpByteBuffer_5__2), cancellationToken).ConfigureAwait(false).GetAwaiter();
    if (!awaiter.get_IsCompleted()) {
      num = (__1__state = 1);
      __u__1 = awaiter;
      __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
      return;
    }
    goto IL_01dc;

  IL_01dc:
    Int32 num3 = streamReader->_byteLen = awaiter.GetResult();
    if (streamReader->_byteLen != 0) {
      goto IL_0201;
    }
    charLen = streamReader->_charLen;

  end_IL_000e:
  } catch (Exception exception) {
    __1__state = -2;
    _tmpByteBuffer_5__2 = nullptr;
    _tmpStream_5__3 = nullptr;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  _tmpByteBuffer_5__2 = nullptr;
  _tmpStream_5__3 = nullptr;
  __t__builder.SetResult(charLen);
}

void StreamReader___::_ReadBufferAsync_d__67::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

Encoding StreamReader___::get_CurrentEncoding() {
  return _encoding;
}

Stream StreamReader___::get_BaseStream() {
  return _stream;
}

Boolean StreamReader___::get_EndOfStream() {
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  if (_charPos < _charLen) {
    return false;
  }
  Int32 num = ReadBuffer();
  return num == 0;
}

void StreamReader___::CheckAsyncTaskInProgress() {
  if (!_asyncReadTask->get_IsCompleted()) {
    ThrowAsyncIOInProgress();
  }
}

void StreamReader___::ThrowAsyncIOInProgress() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_AsyncIOInProgress());
}

void StreamReader___::ctor() {
  _asyncReadTask = Task<>::in::get_CompletedTask();
  TextReader::in::ctor();
  _stream = Stream::in::Null;
  _closable = true;
}

void StreamReader___::ctor(Stream stream) {
}

void StreamReader___::ctor(Stream stream, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::ctor(Stream stream, Encoding encoding) {
}

void StreamReader___::ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize) {
}

void StreamReader___::ctor(Stream stream, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize, Boolean leaveOpen) {
  _asyncReadTask = Task<>::in::get_CompletedTask();
  TextReader::in::ctor();
  if (stream == nullptr) {
    rt::throw_exception<ArgumentNullException>("stream");
  }
  if (encoding == nullptr) {
    encoding = Encoding::in::get_UTF8();
  }
  if (!stream->get_CanRead()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_StreamNotReadable());
  }
  if (bufferSize == -1) {
    bufferSize = 1024;
  } else if (bufferSize <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bufferSize", SR::get_ArgumentOutOfRange_NeedPosNum());
  }

  _stream = stream;
  _encoding = encoding;
  _decoder = encoding->GetDecoder();
  if (bufferSize < 128) {
    bufferSize = 128;
  }
  _byteBuffer = rt::newarr<Array<Byte>>(bufferSize);
  _maxCharsPerBuffer = encoding->GetMaxCharCount(bufferSize);
  _charBuffer = rt::newarr<Array<Char>>(_maxCharsPerBuffer);
  _detectEncoding = detectEncodingFromByteOrderMarks;
  _checkPreamble = (encoding->get_Preamble().get_Length() > 0);
  _closable = !leaveOpen;
}

void StreamReader___::ctor(String path) {
}

void StreamReader___::ctor(String path, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::ctor(String path, Encoding encoding) {
}

void StreamReader___::ctor(String path, Encoding encoding, Boolean detectEncodingFromByteOrderMarks) {
}

void StreamReader___::ctor(String path, Encoding encoding, Boolean detectEncodingFromByteOrderMarks, Int32 bufferSize) {
}

Stream StreamReader___::ValidateArgsAndOpenPath(String path, Encoding encoding, Int32 bufferSize) {
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
  return rt::newobj<FileStream>(path, FileMode::Open, FileAccess::Read, FileShare::Read, 4096, FileOptions::SequentialScan);
}

void StreamReader___::Close() {
  Dispose(true);
}

void StreamReader___::Dispose(Boolean disposing) {
  if (_disposed) {
    return;
  }
  _disposed = true;
  if (!_closable) {
    return;
  }
  try {
    if (disposing) {
      _stream->Close();
    }
  } catch (...) {
  } finally: {
    _charPos = 0;
    _charLen = 0;
    TextReader::in::Dispose(disposing);
  }
}

void StreamReader___::DiscardBufferedData() {
  CheckAsyncTaskInProgress();
  _byteLen = 0;
  _charLen = 0;
  _charPos = 0;
  if (_encoding != nullptr) {
    _decoder = _encoding->GetDecoder();
  }
  _isBlocked = false;
}

Int32 StreamReader___::Peek() {
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  if (_charPos == _charLen && (_isBlocked || ReadBuffer() == 0)) {
    return -1;
  }
  return _charBuffer[_charPos];
}

Int32 StreamReader___::Read() {
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  if (_charPos == _charLen && ReadBuffer() == 0) {
    return -1;
  }
  Int32 result = _charBuffer[_charPos];
  _charPos++;
  return result;
}

Int32 StreamReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return ReadSpan(Span<Char>(buffer, index, count));
}

Int32 StreamReader___::Read(Span<Char> buffer) {
  if (!(GetType() == typeof<StreamReader>())) {
    return TextReader::in::Read(buffer);
  }
  return ReadSpan(buffer);
}

Int32 StreamReader___::ReadSpan(Span<Char> buffer) {
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  Int32 num = 0;
  Boolean readToUserBuffer = false;
  Int32 num2 = buffer.get_Length();
  while (num2 > 0) {
    Int32 num3 = _charLen - _charPos;
    if (num3 == 0) {
      num3 = ReadBuffer(buffer.Slice(num), readToUserBuffer);
    }
    if (num3 == 0) {
      break;
    }
    if (num3 > num2) {
      num3 = num2;
    }
    if (!readToUserBuffer) {
      Span<Char>(_charBuffer, _charPos, num3).CopyTo(buffer.Slice(num));
      _charPos += num3;
    }
    num += num3;
    num2 -= num3;
    if (_isBlocked) {
      break;
    }
  }
  return num;
}

String StreamReader___::ReadToEnd() {
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(_charLen - _charPos);
  do {
    stringBuilder->Append(_charBuffer, _charPos, _charLen - _charPos);
    _charPos = _charLen;
    ReadBuffer();
  } while (_charLen > 0);
  return stringBuilder->ToString();
}

Int32 StreamReader___::ReadBlock(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return TextReader::in::ReadBlock(buffer, index, count);
}

Int32 StreamReader___::ReadBlock(Span<Char> buffer) {
  if (GetType() != typeof<StreamReader>()) {
    return TextReader::in::ReadBlock(buffer);
  }
  Int32 num = 0;
  Int32 num2;
  do {
    num2 = ReadSpan(buffer.Slice(num));
    num += num2;
  } while (num2 > 0 && num < buffer.get_Length());
  return num;
}

void StreamReader___::CompressBuffer(Int32 n) {
  Buffer::BlockCopy(_byteBuffer, n, _byteBuffer, 0, _byteLen - n);
  _byteLen -= n;
}

void StreamReader___::DetectEncoding() {
  if (_byteLen < 2) {
    return;
  }
  _detectEncoding = false;
  Boolean flag = false;
  if (_byteBuffer[0] == 254 && _byteBuffer[1] == Byte::MaxValue) {
    _encoding = Encoding::in::get_BigEndianUnicode();
    CompressBuffer(2);
    flag = true;
  } else if (_byteBuffer[0] == Byte::MaxValue && _byteBuffer[1] == 254) {
    if (_byteLen < 4 || _byteBuffer[2] != 0 || _byteBuffer[3] != 0) {
      _encoding = Encoding::in::get_Unicode();
      CompressBuffer(2);
      flag = true;
    } else {
      _encoding = Encoding::in::get_UTF32();
      CompressBuffer(4);
      flag = true;
    }
  } else if (_byteLen >= 3 && _byteBuffer[0] == 239 && _byteBuffer[1] == 187 && _byteBuffer[2] == 191) {
    _encoding = Encoding::in::get_UTF8();
    CompressBuffer(3);
    flag = true;
  } else if (_byteLen >= 4 && _byteBuffer[0] == 0 && _byteBuffer[1] == 0 && _byteBuffer[2] == 254 && _byteBuffer[3] == Byte::MaxValue) {
    _encoding = rt::newobj<UTF32Encoding>(true, true);
    CompressBuffer(4);
    flag = true;
  } else if (_byteLen == 2) {
    _detectEncoding = true;
  }




  if (flag) {
    _decoder = _encoding->GetDecoder();
    Int32 maxCharCount = _encoding->GetMaxCharCount(_byteBuffer->get_Length());
    if (maxCharCount > _maxCharsPerBuffer) {
      _charBuffer = rt::newarr<Array<Char>>(maxCharCount);
    }
    _maxCharsPerBuffer = maxCharCount;
  }
}

Boolean StreamReader___::IsPreamble() {
  if (!_checkPreamble) {
    return _checkPreamble;
  }
  ReadOnlySpan<Byte> preamble = _encoding->get_Preamble();
  Int32 num = (_byteLen >= preamble.get_Length()) ? (preamble.get_Length() - _bytePos) : (_byteLen - _bytePos);
  Int32 num2 = 0;
  while (num2 < num) {
    if (_byteBuffer[_bytePos] != preamble[_bytePos]) {
      _bytePos = 0;
      _checkPreamble = false;
      break;
    }
    num2++;
    _bytePos++;
  }
  if (_checkPreamble && _bytePos == preamble.get_Length()) {
    CompressBuffer(preamble.get_Length());
    _bytePos = 0;
    _checkPreamble = false;
    _detectEncoding = false;
  }
  return _checkPreamble;
}

Int32 StreamReader___::ReadBuffer() {
  _charLen = 0;
  _charPos = 0;
  if (!_checkPreamble) {
    _byteLen = 0;
  }
  do {
    if (_checkPreamble) {
      Int32 num = _stream->Read(_byteBuffer, _bytePos, _byteBuffer->get_Length() - _bytePos);
      if (num == 0) {
        if (_byteLen > 0) {
          _charLen += _decoder->GetChars(_byteBuffer, 0, _byteLen, _charBuffer, _charLen);
          _bytePos = (_byteLen = 0);
        }
        return _charLen;
      }
      _byteLen += num;
    } else {
      _byteLen = _stream->Read(_byteBuffer, 0, _byteBuffer->get_Length());
      if (_byteLen == 0) {
        return _charLen;
      }
    }
    _isBlocked = (_byteLen < _byteBuffer->get_Length());
    if (!IsPreamble()) {
      if (_detectEncoding && _byteLen >= 2) {
        DetectEncoding();
      }
      _charLen += _decoder->GetChars(_byteBuffer, 0, _byteLen, _charBuffer, _charLen);
    }
  } while (_charLen == 0);
  return _charLen;
}

Int32 StreamReader___::ReadBuffer(Span<Char> userBuffer, Boolean& readToUserBuffer) {
  _charLen = 0;
  _charPos = 0;
  if (!_checkPreamble) {
    _byteLen = 0;
  }
  Int32 num = 0;
  readToUserBuffer = (userBuffer.get_Length() >= _maxCharsPerBuffer);
  do {
    if (_checkPreamble) {
      Int32 num2 = _stream->Read(_byteBuffer, _bytePos, _byteBuffer->get_Length() - _bytePos);
      if (num2 == 0) {
        if (_byteLen > 0) {
          if (readToUserBuffer) {
            num = _decoder->GetChars(ReadOnlySpan<Byte>(_byteBuffer, 0, _byteLen), userBuffer.Slice(num), false);
            _charLen = 0;
          } else {
            num = _decoder->GetChars(_byteBuffer, 0, _byteLen, _charBuffer, num);
            _charLen += num;
          }
        }
        return num;
      }
      _byteLen += num2;
    } else {
      _byteLen = _stream->Read(_byteBuffer, 0, _byteBuffer->get_Length());
      if (_byteLen == 0) {
        break;
      }
    }
    _isBlocked = (_byteLen < _byteBuffer->get_Length());
    if (!IsPreamble()) {
      if (_detectEncoding && _byteLen >= 2) {
        DetectEncoding();
        readToUserBuffer = (userBuffer.get_Length() >= _maxCharsPerBuffer);
      }
      _charPos = 0;
      if (readToUserBuffer) {
        num += _decoder->GetChars(ReadOnlySpan<Byte>(_byteBuffer, 0, _byteLen), userBuffer.Slice(num), false);
        _charLen = 0;
      } else {
        num = _decoder->GetChars(_byteBuffer, 0, _byteLen, _charBuffer, num);
        _charLen += num;
      }
    }
  } while (num == 0);
  _isBlocked &= (num < userBuffer.get_Length());
  return num;
}

String StreamReader___::ReadLine() {
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  if (_charPos == _charLen && ReadBuffer() == 0) {
    return nullptr;
  }
  StringBuilder stringBuilder = nullptr;
  do {
    Int32 num = _charPos;
    do {
      Char c = _charBuffer[num];
      if (c == '\r' || c == '\n') {
        String result;
        if (stringBuilder != nullptr) {
          stringBuilder->Append(_charBuffer, _charPos, num - _charPos);
          result = stringBuilder->ToString();
        } else {
          result = rt::newstr<String>(_charBuffer, _charPos, num - _charPos);
        }
        _charPos = num + 1;
        if (c == '\r' && (_charPos < _charLen || ReadBuffer() > 0) && _charBuffer[_charPos] == '\n') {
          _charPos++;
        }
        return result;
      }
      num++;
    } while (num < _charLen);
    num = _charLen - _charPos;
    if (stringBuilder == nullptr) {
      stringBuilder = rt::newobj<StringBuilder>(num + 80);
    }
    stringBuilder->Append(_charBuffer, _charPos, num);
  } while (ReadBuffer() > 0);
  return stringBuilder->ToString();
}

Task<String> StreamReader___::ReadLineAsync() {
  if (GetType() != typeof<StreamReader>()) {
    return TextReader::in::ReadLineAsync();
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return (Task<String>)(_asyncReadTask = ReadLineAsyncInternal());
}

Task<String> StreamReader___::ReadLineAsyncInternal() {
  _ReadLineAsyncInternal_d__59 stateMachine;
  stateMachine.__t__builder = AsyncTaskMethodBuilder<String>::Create();
  stateMachine.__4__this = (StreamReader)this;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

Task<String> StreamReader___::ReadToEndAsync() {
  if (GetType() != typeof<StreamReader>()) {
    return TextReader::in::ReadToEndAsync();
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return (Task<String>)(_asyncReadTask = ReadToEndAsyncInternal());
}

Task<String> StreamReader___::ReadToEndAsyncInternal() {
  _ReadToEndAsyncInternal_d__61 stateMachine;
  stateMachine.__t__builder = AsyncTaskMethodBuilder<String>::Create();
  stateMachine.__4__this = (StreamReader)this;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

Task<Int32> StreamReader___::ReadAsync(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (GetType() != typeof<StreamReader>()) {
    return TextReader::in::ReadAsync(buffer, index, count);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return (Task<Int32>)(_asyncReadTask = ReadAsyncInternal(Memory<Char>(buffer, index, count), CancellationToken::get_None()).AsTask());
}

template <>
ValueTask<Int32> StreamReader___::ReadAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  if (GetType() != typeof<StreamReader>()) {
    return TextReader::in::ReadAsync(buffer, cancellationToken);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>::FromCanceled<Int32>(cancellationToken);
  }
  return ReadAsyncInternal(buffer, cancellationToken);
}

ValueTask<Int32> StreamReader___::ReadAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken) {
  _ReadAsyncInternal_d__64 stateMachine;
  stateMachine.__t__builder = AsyncValueTaskMethodBuilder<Int32>::Create();
  stateMachine.__4__this = (StreamReader)this;
  stateMachine.buffer = buffer;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

Task<Int32> StreamReader___::ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  if (GetType() != typeof<StreamReader>()) {
    return TextReader::in::ReadBlockAsync(buffer, index, count);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return (Task<Int32>)(_asyncReadTask = TextReader::in::ReadBlockAsync(buffer, index, count));
}

template <>
ValueTask<Int32> StreamReader___::ReadBlockAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  if (GetType() != typeof<StreamReader>()) {
    return TextReader::in::ReadBlockAsync(buffer, cancellationToken);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<>::FromCanceled<Int32>(cancellationToken);
  }
  ValueTask<Int32> result = ReadBlockAsyncInternal(buffer, cancellationToken);
  if (result.get_IsCompletedSuccessfully()) {
    return result;
  }
  return ValueTask<Int32>((Task<Int32>)(_asyncReadTask = result.AsTask()));
}

ValueTask<Int32> StreamReader___::ReadBufferAsync(CancellationToken cancellationToken) {
  _ReadBufferAsync_d__67 stateMachine;
  stateMachine.__t__builder = AsyncValueTaskMethodBuilder<Int32>::Create();
  stateMachine.__4__this = (StreamReader)this;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
}

void StreamReader___::ThrowIfDisposed() {
  auto ThrowObjectDisposedException = []() -> void {
    rt::throw_exception<ObjectDisposedException>(GetType()->get_Name(), SR::get_ObjectDisposed_ReaderClosed());
  };
  if (_disposed) {
    ThrowObjectDisposedException();
  }
}

void StreamReader___::cctor() {
  Null = rt::newobj<NullStreamReader>();
}

void StreamReader___::_ThrowIfDisposed_g__ThrowObjectDisposedException68_0() {
  rt::throw_exception<ObjectDisposedException>(GetType()->get_Name(), SR::get_ObjectDisposed_ReaderClosed());
}

} // namespace System::Private::CoreLib::System::IO::StreamReaderNamespace
