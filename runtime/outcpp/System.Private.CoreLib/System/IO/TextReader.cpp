#include "TextReader-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ArraySegment-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/IO/IOException-dep.h>
#include <System.Private.CoreLib/System/IO/TextReader-dep.h>
#include <System.Private.CoreLib/System/Memory-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredValueTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Tuple-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::IO::TextReaderNamespace {
using namespace System::Buffers;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Text;
using namespace System::Threading::Tasks;

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
  return Task<>::in::FromResult(ReadLine());
}

Task<String> SyncTextReader___::ReadToEndAsync() {
  return Task<>::in::FromResult(ReadToEnd());
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
  return Task<>::in::FromResult(ReadBlock(buffer, index, count));
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
  return Task<>::in::FromResult(Read(buffer, index, count));
}

void TextReader___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void TextReader___::__c___::ctor() {
}

String TextReader___::__c___::_ReadLineAsync_b__13_0(Object state) {
  return ((TextReader)state)->ReadLine();
}

Int32 TextReader___::__c___::_ReadAsync_b__16_0(Object state) {
  Tuple<TextReader, Memory<Char>> tuple = (Tuple<TextReader, Memory<Char>>)state;
  return tuple->get_Item1()->Read(tuple->get_Item2().get_Span());
}

Int32 TextReader___::__c___::_ReadAsyncInternal_b__17_0(Object state) {
  Tuple<TextReader, Memory<Char>> tuple = (Tuple<TextReader, Memory<Char>>)state;
  return tuple->get_Item1()->Read(tuple->get_Item2().get_Span());
}

Int32 TextReader___::__c___::_ReadBlockAsync_b__19_0(Object state) {
  Tuple<TextReader, Memory<Char>> tuple = (Tuple<TextReader, Memory<Char>>)state;
  return tuple->get_Item1()->ReadBlock(tuple->get_Item2().get_Span());
}

void TextReader___::_ReadToEndAsync_d__14::MoveNext() {
  Int32 num = __1__state;
  TextReader textReader = __4__this;
  String result2;
  try {
    if (num != 0) {
      _sb_5__2 = rt::newobj<StringBuilder>(4096);
      _chars_5__3 = ArrayPool<Char>::in::get_Shared()->Rent(4096);
    }
    try {
      if (num != 0) {
        goto IL_0050;
      }
      ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter = __u__1;
      __u__1 = rt::default__;
      num = (__1__state = -1);
      goto IL_00ca;

    IL_0050:
      awaiter = textReader->ReadAsyncInternal(_chars_5__3, rt::default__).ConfigureAwait(false).GetAwaiter();
      if (!awaiter.get_IsCompleted()) {
        num = (__1__state = 0);
        __u__1 = awaiter;
        __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
        return;
      }
      goto IL_00ca;

    IL_00ca:
      Int32 result = awaiter.GetResult();
      Int32 charCount;
      if ((charCount = result) != 0) {
        _sb_5__2->Append(_chars_5__3, 0, charCount);
        goto IL_0050;
      }
    } catch (...) {
    } finally: {
      if (num < 0) {
        ArrayPool<Char>::in::get_Shared()->Return(_chars_5__3);
      }
    }
    result2 = _sb_5__2->ToString();
  } catch (Exception exception) {
    __1__state = -2;
    _sb_5__2 = nullptr;
    _chars_5__3 = nullptr;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  _sb_5__2 = nullptr;
  _chars_5__3 = nullptr;
  __t__builder.SetResult(result2);
}

void TextReader___::_ReadToEndAsync_d__14::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

void TextReader___::_ReadBlockAsyncInternal_d__20::MoveNext() {
  Int32 num = __1__state;
  TextReader textReader = __4__this;
  Int32 result2;
  try {
    if (num != 0) {
      _n_5__2 = 0;
      goto IL_0018;
    }
    ConfiguredValueTaskAwaitable<TResult>::ConfiguredValueTaskAwaiter awaiter = __u__1;
    __u__1 = rt::default__;
    num = (__1__state = -1);
    goto IL_0094;

  IL_0094:
    Int32 result = awaiter.GetResult();
    Int32 num2 = result;
    _n_5__2 += num2;
    if (num2 > 0 && _n_5__2 < buffer.get_Length()) {
      goto IL_0018;
    }
    result2 = _n_5__2;
    goto end_IL_000e;

  IL_0018:
    awaiter = textReader->ReadAsyncInternal(buffer.Slice(_n_5__2), cancellationToken).ConfigureAwait(false).GetAwaiter();
    if (!awaiter.get_IsCompleted()) {
      num = (__1__state = 0);
      __u__1 = awaiter;
      __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
      return;
    }
    goto IL_0094;

  end_IL_000e:
  } catch (Exception exception) {
    __1__state = -2;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  __t__builder.SetResult(result2);
}

void TextReader___::_ReadBlockAsyncInternal_d__20::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
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
  try {
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
  } while (num2 > 0 && num < count);
  return num;
}

Int32 TextReader___::ReadBlock(Span<Char> buffer) {
  Array<Char> array = ArrayPool<Char>::in::get_Shared()->Rent(buffer.get_Length());
  try {
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
  Func<Object, String> as = __c::in::__9__13_0;
  return Task<String>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__13_0 = {__c::in::__9, &__c::in::_ReadLineAsync_b__13_0}), (TextReader)this, CancellationToken::get_None(), TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
}

Task<String> TextReader___::ReadToEndAsync() {
  _ReadToEndAsync_d__14 stateMachine;
  stateMachine.__t__builder = AsyncTaskMethodBuilder<String>::Create();
  stateMachine.__4__this = (TextReader)this;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
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
  return ReadAsyncInternal(Memory<Char>(buffer, index, count), rt::default__).AsTask();
}

template <>
ValueTask<Int32> TextReader___::ReadAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  ArraySegment<Char> segment;
  Func<Object, Int32> as = __c::in::__9__16_0;
  return ValueTask<Int32>(MemoryMarshal::TryGetArray(buffer, segment) ? ReadAsync(segment.get_Array(), segment.get_Offset(), segment.get_Count()) : Task<Int32>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__16_0 = {__c::in::__9, &__c::in::_ReadAsync_b__16_0}), Tuple<>::Create((TextReader)this, buffer), cancellationToken, TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default()));
}

ValueTask<Int32> TextReader___::ReadAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken) {
  Tuple<TextReader, Memory<Char>> state = rt::newobj<Tuple<TextReader, Memory<Char>>>((TextReader)this, buffer);
  Func<Object, Int32> as = __c::in::__9__17_0;
  return ValueTask<Int32>(Task<Int32>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__17_0 = {__c::in::__9, &__c::in::_ReadAsyncInternal_b__17_0}), state, cancellationToken, TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default()));
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
  return ReadBlockAsyncInternal(Memory<Char>(buffer, index, count), rt::default__).AsTask();
}

template <>
ValueTask<Int32> TextReader___::ReadBlockAsync(Memory<Char> buffer, CancellationToken cancellationToken) {
  ArraySegment<Char> segment;
  Func<Object, Int32> as = __c::in::__9__19_0;
  return ValueTask<Int32>(MemoryMarshal::TryGetArray(buffer, segment) ? ReadBlockAsync(segment.get_Array(), segment.get_Offset(), segment.get_Count()) : Task<Int32>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__19_0 = {__c::in::__9, &__c::in::_ReadBlockAsync_b__19_0}), Tuple<>::Create((TextReader)this, buffer), cancellationToken, TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default()));
}

ValueTask<Int32> TextReader___::ReadBlockAsyncInternal(Memory<Char> buffer, CancellationToken cancellationToken) {
  _ReadBlockAsyncInternal_d__20 stateMachine;
  stateMachine.__t__builder = AsyncValueTaskMethodBuilder<Int32>::Create();
  stateMachine.__4__this = (TextReader)this;
  stateMachine.buffer = buffer;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.__1__state = -1;
  stateMachine.__t__builder.Start(stateMachine);
  return stateMachine.__t__builder.get_Task();
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
