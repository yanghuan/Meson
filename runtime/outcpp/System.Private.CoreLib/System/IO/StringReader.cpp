#include "StringReader-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/IO/StringReader-dep.h>
#include <System.Private.CoreLib/System/MemoryExtensions-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::IO::StringReaderNamespace {
void StringReader___::ctor(String s) {
  if (s == nullptr) {
    rt::throw_exception<ArgumentNullException>("s");
  }
  _s = s;
  _length = s->get_Length();
}

void StringReader___::Close() {
  Dispose(true);
}

void StringReader___::Dispose(Boolean disposing) {
  _s = nullptr;
  _pos = 0;
  _length = 0;
  TextReader::in::Dispose(disposing);
}

Int32 StringReader___::Peek() {
  if (_s == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ReaderClosed());
  }
  if (_pos == _length) {
    return -1;
  }
  return _s[_pos];
}

Int32 StringReader___::Read() {
  if (_s == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ReaderClosed());
  }
  if (_pos == _length) {
    return -1;
  }
  return _s[_pos++];
}

Int32 StringReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
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
  if (_s == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ReaderClosed());
  }
  Int32 num = _length - _pos;
  if (num > 0) {
    if (num > count) {
      num = count;
    }
    _s->CopyTo(_pos, buffer, index, num);
    _pos += num;
  }
  return num;
}

Int32 StringReader___::Read(Span<Char> buffer) {
  if (GetType() != typeof<StringReader>()) {
    return TextReader::in::Read(buffer);
  }
  if (_s == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ReaderClosed());
  }
  Int32 num = _length - _pos;
  if (num > 0) {
    if (num > buffer.get_Length()) {
      num = buffer.get_Length();
    }
    MemoryExtensions::AsSpan(_s, _pos, num).CopyTo(buffer);
    _pos += num;
  }
  return num;
}

Int32 StringReader___::ReadBlock(Span<Char> buffer) {
  return Read(buffer);
}

String StringReader___::ReadToEnd() {
  if (_s == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ReaderClosed());
  }
  String result = (_pos != 0) ? _s->Substring(_pos, _length - _pos) : _s;
  _pos = _length;
  return result;
}

String StringReader___::ReadLine() {
  if (_s == nullptr) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_ReaderClosed());
  }
  Int32 i;
  for (i = _pos; i < _length; i++) {
    Char c = _s[i];
    if (c == 13 || c == 10) {
      String result = _s->Substring(_pos, i - _pos);
      _pos = i + 1;
      if (c == 13 && _pos < _length && _s[_pos] == 10) {
        _pos++;
      }
      return result;
    }
  }
  if (i > _pos) {
    String result2 = _s->Substring(_pos, i - _pos);
    _pos = i;
    return result2;
  }
  return nullptr;
}

Task<String> StringReader___::ReadLineAsync() {
  return Task<>::in::FromResult(ReadLine());
}

Task<String> StringReader___::ReadToEndAsync() {
  return Task<>::in::FromResult(ReadToEnd());
}

Task<Int32> StringReader___::ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return Task<>::in::FromResult(ReadBlock(buffer, index, count));
}

template <>
ValueTask<Int32> StringReader___::ReadBlockAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<Int32>(ReadBlock(buffer.get_Span()));
  }
  return ValueTask<>::FromCanceled<Int32>(cancellationToken);
}

Task<Int32> StringReader___::ReadAsync(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return Task<>::in::FromResult(Read(buffer, index, count));
}

template <>
ValueTask<Int32> StringReader___::ReadAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    return ValueTask<Int32>(Read(buffer.get_Span()));
  }
  return ValueTask<>::FromCanceled<Int32>(cancellationToken);
}

} // namespace System::Private::CoreLib::System::IO::StringReaderNamespace
