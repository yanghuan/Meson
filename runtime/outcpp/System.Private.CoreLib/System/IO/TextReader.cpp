#include "TextReader-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ArraySegment-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/TextReader-dep.h>
#include <System.Private.CoreLib/System/Memory-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Tuple-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::IO::TextReaderNamespace {
using namespace System::Buffers;
using namespace System::Runtime::InteropServices;
using namespace System::Text;
using namespace System::Threading;

void NullTextReader___::ctor() {
}

Int32 NullTextReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  return 0;
}

String NullTextReader___::ReadLine() {
  return nullptr;
}

void SyncTextReader___::ctor(TextReader t) {
  _in = t;
}

void SyncTextReader___::Close() {
  _in->Close();
}

void SyncTextReader___::Dispose(Boolean disposing) {
  if (disposing) {
    ((IDisposable)_in)->Dispose();
  }
}

Int32 SyncTextReader___::Peek() {
  return _in->Peek();
}

Int32 SyncTextReader___::Read() {
  return _in->Read();
}

Int32 SyncTextReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
  return _in->Read(buffer, index, count);
}

Int32 SyncTextReader___::ReadBlock(Array<Char> buffer, Int32 index, Int32 count) {
  return _in->ReadBlock(buffer, index, count);
}

String SyncTextReader___::ReadLine() {
  return _in->ReadLine();
}

String SyncTextReader___::ReadToEnd() {
  return _in->ReadToEnd();
}

Task<String> SyncTextReader___::ReadLineAsync() {
  return Task::in::FromResult(ReadLine());
}

Task<String> SyncTextReader___::ReadToEndAsync() {
  return Task::in::FromResult(ReadToEnd());
}

Task<Int32> SyncTextReader___::ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return Task::in::FromResult(ReadBlock(buffer, index, count));
}

Task<Int32> SyncTextReader___::ReadAsync(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return Task::in::FromResult(Read(buffer, index, count));
}

void TextReader___::ctor() {
}

void TextReader___::Close() {
  Dispose(true);
  GC::SuppressFinalize((TextReader)this);
}

void TextReader___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((TextReader)this);
}

void TextReader___::Dispose(Boolean disposing) {
}

Int32 TextReader___::Peek() {
  return -1;
}

Int32 TextReader___::Read() {
  return -1;
}

Int32 TextReader___::Read(Array<Char> buffer, Int32 index, Int32 count) {
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
  Int32 i;
  for (i = 0; i < count; i++) {
    Int32 num = Read();
    if (num == -1) {
      break;
    }
    buffer[index + i] = (Char)num;
  }
  return i;
}

Int32 TextReader___::Read(Span<Char> buffer) {
  Array<Char> array = ArrayPool<Char>::in::get_Shared()->Rent(buffer.get_Length());
  try{
    Int32 num = Read(array, 0, buffer.get_Length());
    if ((UInt32)num > (UInt32)buffer.get_Length()) {
      rt::throw_exception<IOException>(SR::get_IO_InvalidReadLength());
    }
    Span<Char>(array, 0, num).CopyTo(buffer);
    return num;
  } catch (...) {
  } finally: {
    ArrayPool<Char>::in::get_Shared()->Return(array);
  }
}

String TextReader___::ReadToEnd() {
  Array<Char> array = rt::newarr<Array<Char>>(4096);
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(4096);
  Int32 charCount;
  while ((charCount = Read(array, 0, array->get_Length())) != 0) {
    stringBuilder->Append(array, 0, charCount);
  }
  return stringBuilder->ToString();
}

Int32 TextReader___::ReadBlock(Array<Char> buffer, Int32 index, Int32 count) {
  Int32 num = 0;
  Int32 num2;
  do {
    num += (num2 = Read(buffer, index + num, count - num));
  } while (num2 > 0 && num < count)
  return num;
}

Int32 TextReader___::ReadBlock(Span<Char> buffer) {
  Array<Char> array = ArrayPool<Char>::in::get_Shared()->Rent(buffer.get_Length());
  try{
    Int32 num = ReadBlock(array, 0, buffer.get_Length());
    if ((UInt32)num > (UInt32)buffer.get_Length()) {
      rt::throw_exception<IOException>(SR::get_IO_InvalidReadLength());
    }
    Span<Char>(array, 0, num).CopyTo(buffer);
    return num;
  } catch (...) {
  } finally: {
    ArrayPool<Char>::in::get_Shared()->Return(array);
  }
}

String TextReader___::ReadLine() {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  while (true) {
    Int32 num = Read();
    switch (num.get()) {
      case 10:
      case 13:
        if (num == 13 && Peek() == 10) {
          Read();
        }
        return stringBuilder->ToString();
      case -1:
        if (stringBuilder->get_Length() > 0) {
          return stringBuilder->ToString();
        }
        return nullptr;
    }
    stringBuilder->Append((Char)num);
  }
}

Task<String> TextReader___::ReadLineAsync() {
}

Task<String> TextReader___::ReadToEndAsync() {
  StringBuilder sb = rt::newobj<StringBuilder>(4096);
  Array<Char> chars = ArrayPool<Char>::in::get_Shared()->Rent(4096);
  try{
    Int32 charCount;
  } catch (...) {
  } finally: {
    ArrayPool<Char>::in::get_Shared()->Return(chars);
  }
  return sb->ToString();
}

Task<Int32> TextReader___::ReadAsync(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return ReadAsyncInternal(Memory<Char>(buffer, index, count), CancellationToken()).AsTask();
}

ValueTask<Int32> TextReader___::ReadAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  ArraySegment<Char> segment;
}

ValueTask<Int32> TextReader___::ReadAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken) {
  Tuple<TextReader, Memory<Char>> state2 = rt::newobj<Tuple<TextReader, Memory<Char>>>((TextReader)this, buffer);
}

Task<Int32> TextReader___::ReadBlockAsync(Array<Char> buffer, Int32 index, Int32 count) {
  if (buffer == nullptr) {
    rt::throw_exception<ArgumentNullException>("buffer", SR::get_ArgumentNull_Buffer());
  }
  if (index < 0 || count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>((index < 0) ? "index" : "count", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  if (buffer->get_Length() - index < count) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  return ReadBlockAsyncInternal(Memory<Char>(buffer, index, count), CancellationToken()).AsTask();
}

ValueTask<Int32> TextReader___::ReadBlockAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  ArraySegment<Char> segment;
}

ValueTask<Int32> TextReader___::ReadBlockAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken) {
  Int32 i = 0;
  Int32 num;
  do {
  } while (num > 0 && i < buffer.get_Length())
  return i;
}

TextReader TextReader___::Synchronized(TextReader reader) {
  if (reader == nullptr) {
    rt::throw_exception<ArgumentNullException>("reader");
  }
  if (!rt::is<SyncTextReader>(reader)) {
    return rt::newobj<SyncTextReader>(reader);
  }
  return reader;
}

void TextReader___::cctor() {
  Null = rt::newobj<NullTextReader>();
}

} // namespace System::Private::CoreLib::System::IO::TextReaderNamespace
