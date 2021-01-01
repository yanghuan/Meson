#include "TextWriter-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/ArraySegment-dep.h>
#include <System.Private.CoreLib/System/Buffers/ArrayPool-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/IFormattable.h>
#include <System.Private.CoreLib/System/IO/TextWriter-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ConfiguredTaskAwaitable-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskScheduler-dep.h>
#include <System.Private.CoreLib/System/Tuple-dep.h>

namespace System::Private::CoreLib::System::IO::TextWriterNamespace {
using namespace System::Buffers;
using namespace System::Globalization;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Threading::Tasks;

Encoding NullTextWriter___::get_Encoding() {
  return Encoding::in::get_Unicode();
}

void NullTextWriter___::ctor() {
}

void NullTextWriter___::Write(Array<Char> buffer, Int32 index, Int32 count) {
}

void NullTextWriter___::Write(String value) {
}

void NullTextWriter___::WriteLine() {
}

void NullTextWriter___::WriteLine(String value) {
}

void NullTextWriter___::WriteLine(Object value) {
}

void NullTextWriter___::Write(Char value) {
}

Encoding SyncTextWriter___::get_Encoding() {
  return _out->get_Encoding();
}

IFormatProvider SyncTextWriter___::get_FormatProvider() {
  return _out->get_FormatProvider();
}

String SyncTextWriter___::get_NewLine() {
  return _out->get_NewLine();
}

void SyncTextWriter___::set_NewLine(String value) {
  _out->set_NewLine(value);
}

void SyncTextWriter___::ctor(TextWriter t) {
  _out = t;
}

void SyncTextWriter___::Close() {
  _out->Close();
}

void SyncTextWriter___::Dispose(Boolean disposing) {
  if (disposing) {
    ((IDisposable)_out)->Dispose();
  }
}

void SyncTextWriter___::Flush() {
  _out->Flush();
}

void SyncTextWriter___::Write(Char value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(Array<Char> buffer) {
  _out->Write(buffer);
}

void SyncTextWriter___::Write(Array<Char> buffer, Int32 index, Int32 count) {
  _out->Write(buffer, index, count);
}

void SyncTextWriter___::Write(ReadOnlySpan<Char> buffer) {
  _out->Write(buffer);
}

void SyncTextWriter___::Write(Boolean value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(Int32 value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(UInt32 value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(Int64 value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(UInt64 value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(Single value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(Double value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(Decimal value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(String value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(StringBuilder value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(Object value) {
  _out->Write(value);
}

void SyncTextWriter___::Write(String format, Object arg0) {
  _out->Write(format, arg0);
}

void SyncTextWriter___::Write(String format, Object arg0, Object arg1) {
  _out->Write(format, arg0, arg1);
}

void SyncTextWriter___::Write(String format, Object arg0, Object arg1, Object arg2) {
  _out->Write(format, arg0, arg1, arg2);
}

void SyncTextWriter___::Write(String format, Array<Object> arg) {
  _out->Write(format, arg);
}

void SyncTextWriter___::WriteLine() {
  _out->WriteLine();
}

void SyncTextWriter___::WriteLine(Char value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(Decimal value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(Array<Char> buffer) {
  _out->WriteLine(buffer);
}

void SyncTextWriter___::WriteLine(Array<Char> buffer, Int32 index, Int32 count) {
  _out->WriteLine(buffer, index, count);
}

void SyncTextWriter___::WriteLine(ReadOnlySpan<Char> buffer) {
  _out->WriteLine(buffer);
}

void SyncTextWriter___::WriteLine(Boolean value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(Int32 value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(UInt32 value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(Int64 value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(UInt64 value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(Single value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(Double value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(String value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(StringBuilder value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(Object value) {
  _out->WriteLine(value);
}

void SyncTextWriter___::WriteLine(String format, Object arg0) {
  _out->WriteLine(format, arg0);
}

void SyncTextWriter___::WriteLine(String format, Object arg0, Object arg1) {
  _out->WriteLine(format, arg0, arg1);
}

void SyncTextWriter___::WriteLine(String format, Object arg0, Object arg1, Object arg2) {
  _out->WriteLine(format, arg0, arg1, arg2);
}

void SyncTextWriter___::WriteLine(String format, Array<Object> arg) {
  _out->WriteLine(format, arg);
}

ValueTask<> SyncTextWriter___::DisposeAsync() {
  Dispose();
  return rt::default__;
}

Task<> SyncTextWriter___::WriteAsync(Char value) {
  Write(value);
  return Task<>::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteAsync(String value) {
  Write(value);
  return Task<>::in::get_CompletedTask();
}

template <>
Task<> SyncTextWriter___::WriteAsync(StringBuilder value, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  Write(value);
  return Task<>::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteAsync(Array<Char> buffer, Int32 index, Int32 count) {
  Write(buffer, index, count);
  return Task<>::in::get_CompletedTask();
}

template <>
Task<> SyncTextWriter___::WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  Write(buffer.get_Span());
  return Task<>::in::get_CompletedTask();
}

template <>
Task<> SyncTextWriter___::WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  WriteLine(buffer.get_Span());
  return Task<>::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteLineAsync(Char value) {
  WriteLine(value);
  return Task<>::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteLineAsync() {
  WriteLine();
  return Task<>::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteLineAsync(String value) {
  WriteLine(value);
  return Task<>::in::get_CompletedTask();
}

template <>
Task<> SyncTextWriter___::WriteLineAsync(StringBuilder value, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  WriteLine(value);
  return Task<>::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count) {
  WriteLine(buffer, index, count);
  return Task<>::in::get_CompletedTask();
}

Task<> SyncTextWriter___::FlushAsync() {
  Flush();
  return Task<>::in::get_CompletedTask();
}

void TextWriter___::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void TextWriter___::__c___::ctor() {
}

void TextWriter___::__c___::_WriteAsync_b__58_0(Object state) {
  Tuple<TextWriter, Char> tuple = (Tuple<TextWriter, Char>)state;
  tuple->get_Item1()->Write(tuple->get_Item2());
}

void TextWriter___::__c___::_WriteAsync_b__59_0(Object state) {
  Tuple<TextWriter, String> tuple = (Tuple<TextWriter, String>)state;
  tuple->get_Item1()->Write(tuple->get_Item2());
}

void TextWriter___::__c___::_WriteAsync_b__62_0(Object state) {
  Tuple<TextWriter, Array<Char>, Int32, Int32> tuple = (Tuple<TextWriter, Array<Char>, Int32, Int32>)state;
  tuple->get_Item1()->Write(tuple->get_Item2(), tuple->get_Item3(), tuple->get_Item4());
}

void TextWriter___::__c___::_WriteAsync_b__63_0(Object state) {
  Tuple<TextWriter, ReadOnlyMemory<Char>> tuple = (Tuple<TextWriter, ReadOnlyMemory<Char>>)state;
  tuple->get_Item1()->Write(tuple->get_Item2().get_Span());
}

void TextWriter___::__c___::_WriteLineAsync_b__64_0(Object state) {
  Tuple<TextWriter, Char> tuple = (Tuple<TextWriter, Char>)state;
  tuple->get_Item1()->WriteLine(tuple->get_Item2());
}

void TextWriter___::__c___::_WriteLineAsync_b__65_0(Object state) {
  Tuple<TextWriter, String> tuple = (Tuple<TextWriter, String>)state;
  tuple->get_Item1()->WriteLine(tuple->get_Item2());
}

void TextWriter___::__c___::_WriteLineAsync_b__68_0(Object state) {
  Tuple<TextWriter, Array<Char>, Int32, Int32> tuple = (Tuple<TextWriter, Array<Char>, Int32, Int32>)state;
  tuple->get_Item1()->WriteLine(tuple->get_Item2(), tuple->get_Item3(), tuple->get_Item4());
}

void TextWriter___::__c___::_WriteLineAsync_b__69_0(Object state) {
  Tuple<TextWriter, ReadOnlyMemory<Char>> tuple = (Tuple<TextWriter, ReadOnlyMemory<Char>>)state;
  tuple->get_Item1()->WriteLine(tuple->get_Item2().get_Span());
}

void TextWriter___::__c___::_FlushAsync_b__71_0(Object state) {
  ((TextWriter)state)->Flush();
}

void TextWriter___::__WriteAsync_g__WriteAsyncCore60_0_d::MoveNext() {
  Int32 num = __1__state;
  TextWriter textWriter = __4__this;
  try {
    if (num != 0) {
      __7__wrap1 = sb->GetChunks().GetEnumerator();
      goto IL_00a4;
    }
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter = __u__1;
    __u__1 = rt::default__;
    num = (__1__state = -1);
    goto IL_009d;

  IL_009d:
    awaiter.GetResult();
    goto IL_00a4;

  IL_00a4:
    if (__7__wrap1.MoveNext()) {
      ReadOnlyMemory<Char> current = __7__wrap1.get_Current();
      awaiter = textWriter->WriteAsync(current, ct)->ConfigureAwait(false).GetAwaiter();
      if (!awaiter.get_IsCompleted()) {
        num = (__1__state = 0);
        __u__1 = awaiter;
        __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
        return;
      }
      goto IL_009d;
    }
    __7__wrap1 = rt::default__;
  } catch (Exception exception) {
    __1__state = -2;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  __t__builder.SetResult();
}

void TextWriter___::__WriteAsync_g__WriteAsyncCore60_0_d::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

void TextWriter___::__WriteLineAsync_g__WriteLineAsyncCore66_0_d::MoveNext() {
  Int32 num = __1__state;
  TextWriter textWriter = __4__this;
  try {
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter;
    if (num != 0) {
      if (num != 1) {
        __7__wrap1 = sb->GetChunks().GetEnumerator();
        goto IL_00ae;
      }
      awaiter = __u__1;
      __u__1 = rt::default__;
      num = (__1__state = -1);
      goto IL_0139;
    }
    ConfiguredTaskAwaitable<>::ConfiguredTaskAwaiter awaiter2 = __u__1;
    __u__1 = rt::default__;
    num = (__1__state = -1);
    goto IL_00a7;

  IL_00a7:
    awaiter2.GetResult();
    goto IL_00ae;

  IL_00ae:
    if (__7__wrap1.MoveNext()) {
      ReadOnlyMemory<Char> current = __7__wrap1.get_Current();
      awaiter2 = textWriter->WriteAsync(current, ct)->ConfigureAwait(false).GetAwaiter();
      if (!awaiter2.get_IsCompleted()) {
        num = (__1__state = 0);
        __u__1 = awaiter2;
        __t__builder.AwaitUnsafeOnCompleted(awaiter2, *this);
        return;
      }
      goto IL_00a7;
    }
    __7__wrap1 = rt::default__;
    awaiter = textWriter->WriteAsync(textWriter->CoreNewLine, ct)->ConfigureAwait(false).GetAwaiter();
    if (!awaiter.get_IsCompleted()) {
      num = (__1__state = 1);
      __u__1 = awaiter;
      __t__builder.AwaitUnsafeOnCompleted(awaiter, *this);
      return;
    }
    goto IL_0139;

  IL_0139:
    awaiter.GetResult();
  } catch (Exception exception) {
    __1__state = -2;
    __t__builder.SetException(exception);
    return;
  }
  __1__state = -2;
  __t__builder.SetResult();
}

void TextWriter___::__WriteLineAsync_g__WriteLineAsyncCore66_0_d::SetStateMachine(IAsyncStateMachine stateMachine) {
  __t__builder.SetStateMachine(stateMachine);
}

IFormatProvider TextWriter___::get_FormatProvider() {
  if (_internalFormatProvider == nullptr) {
    return CultureInfo::in::get_CurrentCulture();
  }
  return _internalFormatProvider;
}

String TextWriter___::get_NewLine() {
  return CoreNewLineStr;
}

void TextWriter___::set_NewLine(String value) {
  if (value == nullptr) {
    value = "\r\n";
  }
  CoreNewLineStr = value;
  CoreNewLine = value->ToCharArray();
}

void TextWriter___::ctor() {
  CoreNewLine = s_coreNewLine;
  CoreNewLineStr = "\r\n";
  MarshalByRefObject::in::ctor();
  _internalFormatProvider = nullptr;
}

void TextWriter___::ctor(IFormatProvider formatProvider) {
  CoreNewLine = s_coreNewLine;
  CoreNewLineStr = "\r\n";
  MarshalByRefObject::in::ctor();
  _internalFormatProvider = formatProvider;
}

void TextWriter___::Close() {
  Dispose(true);
  GC::SuppressFinalize((TextWriter)this);
}

void TextWriter___::Dispose(Boolean disposing) {
}

void TextWriter___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((TextWriter)this);
}

ValueTask<> TextWriter___::DisposeAsync() {
  try {
    Dispose();
    return rt::default__;
  } catch (Exception exception) {
    return ValueTask<>(Task<>::in::FromException(exception));
  }
}

void TextWriter___::Flush() {
}

void TextWriter___::Write(Char value) {
}

void TextWriter___::Write(Array<Char> buffer) {
  if (buffer != nullptr) {
    Write(buffer, 0, buffer->get_Length());
  }
}

void TextWriter___::Write(Array<Char> buffer, Int32 index, Int32 count) {
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
  for (Int32 i = 0; i < count; i++) {
    Write(buffer[index + i]);
  }
}

void TextWriter___::Write(ReadOnlySpan<Char> buffer) {
  Array<Char> array = ArrayPool<Char>::in::get_Shared()->Rent(buffer.get_Length());
  try {
    buffer.CopyTo(Span<Char>(array));
    Write(array, 0, buffer.get_Length());
  } catch (...) {
  } finally: {
    ArrayPool<Char>::in::get_Shared()->Return(array);
  }
}

void TextWriter___::Write(Boolean value) {
  Write(value ? "True" : "False");
}

void TextWriter___::Write(Int32 value) {
  Write(value.ToString(get_FormatProvider()));
}

void TextWriter___::Write(UInt32 value) {
  Write(value.ToString(get_FormatProvider()));
}

void TextWriter___::Write(Int64 value) {
  Write(value.ToString(get_FormatProvider()));
}

void TextWriter___::Write(UInt64 value) {
  Write(value.ToString(get_FormatProvider()));
}

void TextWriter___::Write(Single value) {
  Write(value.ToString(get_FormatProvider()));
}

void TextWriter___::Write(Double value) {
  Write(value.ToString(get_FormatProvider()));
}

void TextWriter___::Write(Decimal value) {
  Write(value.ToString(get_FormatProvider()));
}

void TextWriter___::Write(String value) {
  if (value != nullptr) {
    Write(value->ToCharArray());
  }
}

void TextWriter___::Write(Object value) {
  if (value != nullptr) {
    IFormattable formattable = rt::as<IFormattable>(value);
    if (formattable != nullptr) {
      Write(formattable->ToString(nullptr, get_FormatProvider()));
    } else {
      Write(value->ToString());
    }
  }
}

void TextWriter___::Write(StringBuilder value) {
  if (value != nullptr) {
    StringBuilder::in::ChunkEnumerator enumerator = value->GetChunks().GetEnumerator();
    while (enumerator.MoveNext()) {
      Write(enumerator.get_Current().get_Span());
    }
  }
}

void TextWriter___::Write(String format, Object arg0) {
  Write(String::in::Format(get_FormatProvider(), format, arg0));
}

void TextWriter___::Write(String format, Object arg0, Object arg1) {
  Write(String::in::Format(get_FormatProvider(), format, arg0, arg1));
}

void TextWriter___::Write(String format, Object arg0, Object arg1, Object arg2) {
  Write(String::in::Format(get_FormatProvider(), format, arg0, arg1, arg2));
}

void TextWriter___::Write(String format, Array<Object> arg) {
  Write(String::in::Format(get_FormatProvider(), format, arg));
}

void TextWriter___::WriteLine() {
  Write(CoreNewLine);
}

void TextWriter___::WriteLine(Char value) {
  Write(value);
  WriteLine();
}

void TextWriter___::WriteLine(Array<Char> buffer) {
  Write(buffer);
  WriteLine();
}

void TextWriter___::WriteLine(Array<Char> buffer, Int32 index, Int32 count) {
  Write(buffer, index, count);
  WriteLine();
}

void TextWriter___::WriteLine(ReadOnlySpan<Char> buffer) {
  Array<Char> array = ArrayPool<Char>::in::get_Shared()->Rent(buffer.get_Length());
  try {
    buffer.CopyTo(Span<Char>(array));
    WriteLine(array, 0, buffer.get_Length());
  } catch (...) {
  } finally: {
    ArrayPool<Char>::in::get_Shared()->Return(array);
  }
}

void TextWriter___::WriteLine(Boolean value) {
  Write(value);
  WriteLine();
}

void TextWriter___::WriteLine(Int32 value) {
  Write(value);
  WriteLine();
}

void TextWriter___::WriteLine(UInt32 value) {
  Write(value);
  WriteLine();
}

void TextWriter___::WriteLine(Int64 value) {
  Write(value);
  WriteLine();
}

void TextWriter___::WriteLine(UInt64 value) {
  Write(value);
  WriteLine();
}

void TextWriter___::WriteLine(Single value) {
  Write(value);
  WriteLine();
}

void TextWriter___::WriteLine(Double value) {
  Write(value);
  WriteLine();
}

void TextWriter___::WriteLine(Decimal value) {
  Write(value);
  WriteLine();
}

void TextWriter___::WriteLine(String value) {
  if (value != nullptr) {
    Write(value);
  }
  Write(CoreNewLineStr);
}

void TextWriter___::WriteLine(StringBuilder value) {
  Write(value);
  WriteLine();
}

void TextWriter___::WriteLine(Object value) {
  if (value == nullptr) {
    WriteLine();
    return;
  }
  IFormattable formattable = rt::as<IFormattable>(value);
  if (formattable != nullptr) {
    WriteLine(formattable->ToString(nullptr, get_FormatProvider()));
  } else {
    WriteLine(value->ToString());
  }
}

void TextWriter___::WriteLine(String format, Object arg0) {
  WriteLine(String::in::Format(get_FormatProvider(), format, arg0));
}

void TextWriter___::WriteLine(String format, Object arg0, Object arg1) {
  WriteLine(String::in::Format(get_FormatProvider(), format, arg0, arg1));
}

void TextWriter___::WriteLine(String format, Object arg0, Object arg1, Object arg2) {
  WriteLine(String::in::Format(get_FormatProvider(), format, arg0, arg1, arg2));
}

void TextWriter___::WriteLine(String format, Array<Object> arg) {
  WriteLine(String::in::Format(get_FormatProvider(), format, arg));
}

Task<> TextWriter___::WriteAsync(Char value) {
  Tuple<TextWriter, Char> state = rt::newobj<Tuple<TextWriter, Char>>((TextWriter)this, value);
  Action<Object> as = __c::in::__9__58_0;
  return Task<>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__58_0 = {__c::in::__9, &__c::in::_WriteAsync_b__58_0}), state, CancellationToken::get_None(), TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
}

Task<> TextWriter___::WriteAsync(String value) {
  Tuple<TextWriter, String> state = rt::newobj<Tuple<TextWriter, String>>((TextWriter)this, value);
  Action<Object> as = __c::in::__9__59_0;
  return Task<>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__59_0 = {__c::in::__9, &__c::in::_WriteAsync_b__59_0}), state, CancellationToken::get_None(), TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
}

template <>
Task<> TextWriter___::WriteAsync(StringBuilder value, CancellationToken cancellationToken) {
  auto WriteAsyncCore = [](StringBuilder sb, CancellationToken ct) -> Task<> {
    StringBuilder::in::ChunkEnumerator enumerator = sb->GetChunks().GetEnumerator();
    while (enumerator.MoveNext()) {
      ReadOnlyMemory<Char> current = enumerator.get_Current();
    }
  };
  if (!cancellationToken.get_IsCancellationRequested()) {
    if (value != nullptr) {
      return WriteAsyncCore(value, cancellationToken);
    }
    return Task<>::in::get_CompletedTask();
  }
  return Task<>::in::FromCanceled(cancellationToken);
}

Task<> TextWriter___::WriteAsync(Array<Char> buffer) {
  if (buffer == nullptr) {
    return Task<>::in::get_CompletedTask();
  }
  return WriteAsync(buffer, 0, buffer->get_Length());
}

Task<> TextWriter___::WriteAsync(Array<Char> buffer, Int32 index, Int32 count) {
  Tuple<TextWriter, Array<Char>, Int32, Int32> state = rt::newobj<Tuple<TextWriter, Array<Char>, Int32, Int32>>((TextWriter)this, buffer, index, count);
  Action<Object> as = __c::in::__9__62_0;
  return Task<>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__62_0 = {__c::in::__9, &__c::in::_WriteAsync_b__62_0}), state, CancellationToken::get_None(), TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
}

template <>
Task<> TextWriter___::WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    ArraySegment<Char> segment;
    if (!MemoryMarshal::TryGetArray(buffer, segment)) {
      Action<Object> as = __c::in::__9__63_0;
      return Task<>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__63_0 = {__c::in::__9, &__c::in::_WriteAsync_b__63_0}), Tuple<>::Create((TextWriter)this, buffer), cancellationToken, TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
    }
    return WriteAsync(segment.get_Array(), segment.get_Offset(), segment.get_Count());
  }
  return Task<>::in::FromCanceled(cancellationToken);
}

Task<> TextWriter___::WriteLineAsync(Char value) {
  Tuple<TextWriter, Char> state = rt::newobj<Tuple<TextWriter, Char>>((TextWriter)this, value);
  Action<Object> as = __c::in::__9__64_0;
  return Task<>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__64_0 = {__c::in::__9, &__c::in::_WriteLineAsync_b__64_0}), state, CancellationToken::get_None(), TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
}

Task<> TextWriter___::WriteLineAsync(String value) {
  Tuple<TextWriter, String> state = rt::newobj<Tuple<TextWriter, String>>((TextWriter)this, value);
  Action<Object> as = __c::in::__9__65_0;
  return Task<>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__65_0 = {__c::in::__9, &__c::in::_WriteLineAsync_b__65_0}), state, CancellationToken::get_None(), TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
}

template <>
Task<> TextWriter___::WriteLineAsync(StringBuilder value, CancellationToken cancellationToken) {
  auto WriteLineAsyncCore = [](StringBuilder sb, CancellationToken ct) -> Task<> {
    StringBuilder::in::ChunkEnumerator enumerator = sb->GetChunks().GetEnumerator();
    while (enumerator.MoveNext()) {
      ReadOnlyMemory<Char> current = enumerator.get_Current();
    }
  };
  if (!cancellationToken.get_IsCancellationRequested()) {
    if (value != nullptr) {
      return WriteLineAsyncCore(value, cancellationToken);
    }
    return WriteAsync(CoreNewLine, cancellationToken);
  }
  return Task<>::in::FromCanceled(cancellationToken);
}

Task<> TextWriter___::WriteLineAsync(Array<Char> buffer) {
  if (buffer == nullptr) {
    return WriteLineAsync();
  }
  return WriteLineAsync(buffer, 0, buffer->get_Length());
}

Task<> TextWriter___::WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count) {
  Tuple<TextWriter, Array<Char>, Int32, Int32> state = rt::newobj<Tuple<TextWriter, Array<Char>, Int32, Int32>>((TextWriter)this, buffer, index, count);
  Action<Object> as = __c::in::__9__68_0;
  return Task<>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__68_0 = {__c::in::__9, &__c::in::_WriteLineAsync_b__68_0}), state, CancellationToken::get_None(), TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
}

template <>
Task<> TextWriter___::WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    ArraySegment<Char> segment;
    if (!MemoryMarshal::TryGetArray(buffer, segment)) {
      Action<Object> as = __c::in::__9__69_0;
      return Task<>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__69_0 = {__c::in::__9, &__c::in::_WriteLineAsync_b__69_0}), Tuple<>::Create((TextWriter)this, buffer), cancellationToken, TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
    }
    return WriteLineAsync(segment.get_Array(), segment.get_Offset(), segment.get_Count());
  }
  return Task<>::in::FromCanceled(cancellationToken);
}

Task<> TextWriter___::WriteLineAsync() {
  return WriteAsync(CoreNewLine);
}

Task<> TextWriter___::FlushAsync() {
  Action<Object> as = __c::in::__9__71_0;
  return Task<>::in::get_Factory()->StartNew(as != nullptr ? as : (__c::in::__9__71_0 = {__c::in::__9, &__c::in::_FlushAsync_b__71_0}), (TextWriter)this, CancellationToken::get_None(), TaskCreationOptions::DenyChildAttach, TaskScheduler::in::get_Default());
}

TextWriter TextWriter___::Synchronized(TextWriter writer) {
  if (writer == nullptr) {
    rt::throw_exception<ArgumentNullException>("writer");
  }
  if (!rt::is<SyncTextWriter>(writer)) {
    return rt::newobj<SyncTextWriter>(writer);
  }
  return writer;
}

void TextWriter___::cctor() {
  Null = rt::newobj<NullTextWriter>();
  s_coreNewLine = "\r\n"->ToCharArray();
}

Task<> TextWriter___::_WriteAsync_g__WriteAsyncCore60_0(StringBuilder sb, CancellationToken ct) {
  StringBuilder::in::ChunkEnumerator enumerator = sb->GetChunks().GetEnumerator();
  while (enumerator.MoveNext()) {
    ReadOnlyMemory<Char> current = enumerator.get_Current();
  }
}

Task<> TextWriter___::_WriteLineAsync_g__WriteLineAsyncCore66_0(StringBuilder sb, CancellationToken ct) {
  StringBuilder::in::ChunkEnumerator enumerator = sb->GetChunks().GetEnumerator();
  while (enumerator.MoveNext()) {
    ReadOnlyMemory<Char> current = enumerator.get_Current();
  }
}

} // namespace System::Private::CoreLib::System::IO::TextWriterNamespace
