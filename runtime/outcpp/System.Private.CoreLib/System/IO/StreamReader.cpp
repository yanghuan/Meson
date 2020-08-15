#include "StreamReader-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
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
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Text/UTF32Encoding-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>

namespace System::Private::CoreLib::System::IO::StreamReaderNamespace {
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
  _asyncReadTask = Task::in::get_CompletedTask();
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
  _asyncReadTask = Task::in::get_CompletedTask();
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
  _byteLen = 0;
  _bytePos = 0;
  _detectEncoding = detectEncodingFromByteOrderMarks;
  _checkPreamble = (encoding->get_Preamble().get_Length() > 0);
  _isBlocked = false;
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
  try{
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
  if (!(GetType() == rt::typeof<StreamReader>())) {
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
  } while (_charLen > 0)
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
  if (GetType() != rt::typeof<StreamReader>()) {
    return TextReader::in::ReadBlock(buffer);
  }
  Int32 num = 0;
  Int32 num2;
  do {
    num2 = ReadSpan(buffer.Slice(num));
    num += num2;
  } while (num2 > 0 && num < buffer.get_Length())
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
  } while (_charLen == 0)
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
  } while (num == 0)
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
      if (c == 13 || c == 10) {
        String result;
        if (stringBuilder != nullptr) {
          stringBuilder->Append(_charBuffer, _charPos, num - _charPos);
          result = stringBuilder->ToString();
        } else {
          result = rt::newobj<String>(_charBuffer, _charPos, num - _charPos);
        }
        _charPos = num + 1;
        if (c == 13 && (_charPos < _charLen || ReadBuffer() > 0) && _charBuffer[_charPos] == 10) {
          _charPos++;
        }
        return result;
      }
      num++;
    } while (num < _charLen)
    num = _charLen - _charPos;
    if (stringBuilder == nullptr) {
      stringBuilder = rt::newobj<StringBuilder>(num + 80);
    }
    stringBuilder->Append(_charBuffer, _charPos, num);
  } while (ReadBuffer() > 0)
  return stringBuilder->ToString();
}

Task<String> StreamReader___::ReadLineAsync() {
  if (GetType() != rt::typeof<StreamReader>()) {
    return TextReader::in::ReadLineAsync();
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return (Task<String>)(_asyncReadTask = ReadLineAsyncInternal());
}

Task<String> StreamReader___::ReadLineAsyncInternal() {
  Boolean flag = _charPos == _charLen;
  Boolean flag2 = flag;
  if (flag2) {
  }
  if (flag2) {
    return nullptr;
  }
  StringBuilder sb = nullptr;
}

Task<String> StreamReader___::ReadToEndAsync() {
  if (GetType() != rt::typeof<StreamReader>()) {
    return TextReader::in::ReadToEndAsync();
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return (Task<String>)(_asyncReadTask = ReadToEndAsyncInternal());
}

Task<String> StreamReader___::ReadToEndAsyncInternal() {
  StringBuilder sb = rt::newobj<StringBuilder>(_charLen - _charPos);
  do {
    Int32 charPos = _charPos;
    sb->Append(_charBuffer, charPos, _charLen - charPos);
    _charPos = _charLen;
  } while (_charLen > 0)
  return sb->ToString();
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
  if (GetType() != rt::typeof<StreamReader>()) {
    return TextReader::in::ReadAsync(buffer, index, count);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return (Task<Int32>)(_asyncReadTask = ReadAsyncInternal(Memory<Char>(buffer, index, count), CancellationToken::get_None()).AsTask());
}

ValueTask<Int32> StreamReader___::ReadAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  if (GetType() != rt::typeof<StreamReader>()) {
    return TextReader::in::ReadAsync(buffer, cancellationToken);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<Int32>(Task::in::FromCanceled<Int32>(cancellationToken));
  }
  return ReadAsyncInternal(buffer, cancellationToken);
}

ValueTask<Int32> StreamReader___::ReadAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken) {
  Boolean flag = _charPos == _charLen;
  Boolean flag2 = flag;
  if (flag2) {
  }
  if (flag2) {
    return 0;
  }
  Int32 charsRead = 0;
  Boolean readToUserBuffer = false;
  Array<Byte> tmpByteBuffer = _byteBuffer;
  Stream tmpStream = _stream;
  Int32 count = buffer.get_Length();
  while (count > 0) {
    Int32 i = _charLen - _charPos;
    if (i == 0) {
      _charLen = 0;
      _charPos = 0;
      if (!_checkPreamble) {
        _byteLen = 0;
      }
      readToUserBuffer = (count >= _maxCharsPerBuffer);
      do {
        if (_checkPreamble) {
          Int32 bytePos = _bytePos;
        } else {
        }
        _isBlocked = (_byteLen < tmpByteBuffer->get_Length());
        if (!IsPreamble()) {
          if (_detectEncoding && _byteLen >= 2) {
            DetectEncoding();
            readToUserBuffer = (count >= _maxCharsPerBuffer);
          }
          _charPos = 0;
          if (readToUserBuffer) {
            i += _decoder->GetChars(ReadOnlySpan<Byte>(tmpByteBuffer, 0, _byteLen), buffer.get_Span().Slice(charsRead), false);
            _charLen = 0;
          } else {
            i = _decoder->GetChars(tmpByteBuffer, 0, _byteLen, _charBuffer, 0);
            _charLen += i;
          }
        }
      } while (i == 0)
      if (i == 0) {
        break;
      }
    }
    if (i > count) {
      i = count;
    }
    if (!readToUserBuffer) {
      Span<Char>(_charBuffer, _charPos, i).CopyTo(buffer.get_Span().Slice(charsRead));
      _charPos += i;
    }
    charsRead += i;
    count -= i;
    if (_isBlocked) {
      break;
    }
  }
  return charsRead;
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
  if (GetType() != rt::typeof<StreamReader>()) {
    return TextReader::in::ReadBlockAsync(buffer, index, count);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  return (Task<Int32>)(_asyncReadTask = TextReader::in::ReadBlockAsync(buffer, index, count));
}

ValueTask<Int32> StreamReader___::ReadBlockAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  if (GetType() != rt::typeof<StreamReader>()) {
    return TextReader::in::ReadBlockAsync(buffer, cancellationToken);
  }
  ThrowIfDisposed();
  CheckAsyncTaskInProgress();
  if (cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<Int32>(Task::in::FromCanceled<Int32>(cancellationToken));
  }
  ValueTask<Int32> result = ReadBlockAsyncInternal(buffer, cancellationToken);
  if (result.get_IsCompletedSuccessfully()) {
    return result;
  }
  return ValueTask<Int32>((Task<Int32>)(_asyncReadTask = result.AsTask()));
}

ValueTask<Int32> StreamReader___::ReadBufferAsync(CancellationToken cancellationToken) {
  _charLen = 0;
  _charPos = 0;
  Array<Byte> tmpByteBuffer = _byteBuffer;
  Stream tmpStream = _stream;
  if (!_checkPreamble) {
    _byteLen = 0;
  }
  do {
    if (_checkPreamble) {
      Int32 bytePos = _bytePos;
    } else {
    }
    _isBlocked = (_byteLen < tmpByteBuffer->get_Length());
    if (!IsPreamble()) {
      if (_detectEncoding && _byteLen >= 2) {
        DetectEncoding();
      }
      _charLen += _decoder->GetChars(tmpByteBuffer, 0, _byteLen, _charBuffer, _charLen);
    }
  } while (_charLen == 0)
  return _charLen;
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

} // namespace System::Private::CoreLib::System::IO::StreamReaderNamespace
