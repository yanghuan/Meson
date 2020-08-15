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
#include <System.Private.CoreLib/System/Runtime/InteropServices/MemoryMarshal-dep.h>
#include <System.Private.CoreLib/System/Span-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Tuple-dep.h>

namespace System::Private::CoreLib::System::IO::TextWriterNamespace {
using namespace System::Buffers;
using namespace System::Globalization;
using namespace System::Runtime::InteropServices;

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
  _out->set_NewLine = value;
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
  _out->Write(format, rt::newarr<Array<Object>>(1, arg));
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
  _out->WriteLine(format, rt::newarr<Array<Object>>(1, arg));
}

ValueTask<> SyncTextWriter___::DisposeAsync() {
  Dispose();
  return ValueTask();
}

Task<> SyncTextWriter___::WriteAsync(Char value) {
  Write(value);
  return Task::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteAsync(String value) {
  Write(value);
  return Task::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteAsync(StringBuilder value, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task::in::FromCanceled(cancellationToken);
  }
  Write(value);
  return Task::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteAsync(Array<Char> buffer, Int32 index, Int32 count) {
  Write(buffer, index, count);
  return Task::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task::in::FromCanceled(cancellationToken);
  }
  Write(buffer.get_Span());
  return Task::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task::in::FromCanceled(cancellationToken);
  }
  WriteLine(buffer.get_Span());
  return Task::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteLineAsync(Char value) {
  WriteLine(value);
  return Task::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteLineAsync() {
  WriteLine();
  return Task::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteLineAsync(String value) {
  WriteLine(value);
  return Task::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteLineAsync(StringBuilder value, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task::in::FromCanceled(cancellationToken);
  }
  WriteLine(value);
  return Task::in::get_CompletedTask();
}

Task<> SyncTextWriter___::WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count) {
  WriteLine(buffer, index, count);
  return Task::in::get_CompletedTask();
}

Task<> SyncTextWriter___::FlushAsync() {
  Flush();
  return Task::in::get_CompletedTask();
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
    value = "
";
  }
  CoreNewLineStr = value;
  CoreNewLine = value->ToCharArray();
}

void TextWriter___::ctor() {
  CoreNewLine = s_coreNewLine;
  CoreNewLineStr = "
";
  MarshalByRefObject::in::ctor();
  _internalFormatProvider = nullptr;
}

void TextWriter___::ctor(IFormatProvider formatProvider) {
  CoreNewLine = s_coreNewLine;
  CoreNewLineStr = "
";
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
  try{
    Dispose();
    return ValueTask();
  } catch (Exception exception) {
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
  try{
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
  Write(String::in::Format(get_FormatProvider(), format, rt::newarr<Array<Object>>(1, arg)));
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
  try{
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
  WriteLine(String::in::Format(get_FormatProvider(), format, rt::newarr<Array<Object>>(1, arg)));
}

Task<> TextWriter___::WriteAsync(Char value) {
  Tuple<TextWriter, Char> state2 = rt::newobj<Tuple<TextWriter, Char>>((TextWriter)this, value);
}

Task<> TextWriter___::WriteAsync(String value) {
  Tuple<TextWriter, String> state2 = rt::newobj<Tuple<TextWriter, String>>((TextWriter)this, value);
}

Task<> TextWriter___::WriteAsync(StringBuilder value, CancellationToken cancellationToken) {
  auto WriteAsyncCore = [](StringBuilder sb, CancellationToken ct) -> Task {
    StringBuilder::in::ChunkEnumerator enumerator = sb->GetChunks().GetEnumerator();
    while (enumerator.MoveNext()) {
      ReadOnlyMemory<Char> current = enumerator.get_Current();
    }
  };
  if (!cancellationToken.get_IsCancellationRequested()) {
    if (value != nullptr) {
      return WriteAsyncCore(value, cancellationToken);
    }
    return Task::in::get_CompletedTask();
  }
  return Task::in::FromCanceled(cancellationToken);
}

Task<> TextWriter___::WriteAsync(Array<Char> buffer) {
  if (buffer == nullptr) {
    return Task::in::get_CompletedTask();
  }
  return WriteAsync(buffer, 0, buffer->get_Length());
}

Task<> TextWriter___::WriteAsync(Array<Char> buffer, Int32 index, Int32 count) {
  Tuple<TextWriter, Array<Char>, Int32, Int32> state2 = rt::newobj<Tuple<TextWriter, Array<Char>, Int32, Int32>>((TextWriter)this, buffer, index, count);
}

Task<> TextWriter___::WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    ArraySegment<Char> segment;
    if (!MemoryMarshal::TryGetArray(buffer, segment)) {
    }
    return WriteAsync(segment.get_Array(), segment.get_Offset(), segment.get_Count());
  }
  return Task::in::FromCanceled(cancellationToken);
}

Task<> TextWriter___::WriteLineAsync(Char value) {
  Tuple<TextWriter, Char> state2 = rt::newobj<Tuple<TextWriter, Char>>((TextWriter)this, value);
}

Task<> TextWriter___::WriteLineAsync(String value) {
  Tuple<TextWriter, String> state2 = rt::newobj<Tuple<TextWriter, String>>((TextWriter)this, value);
}

Task<> TextWriter___::WriteLineAsync(StringBuilder value, CancellationToken cancellationToken) {
  auto WriteLineAsyncCore = [](StringBuilder sb, CancellationToken ct) -> Task {
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
  return Task::in::FromCanceled(cancellationToken);
}

Task<> TextWriter___::WriteLineAsync(Array<Char> buffer) {
  if (buffer == nullptr) {
    return WriteLineAsync();
  }
  return WriteLineAsync(buffer, 0, buffer->get_Length());
}

Task<> TextWriter___::WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count) {
  Tuple<TextWriter, Array<Char>, Int32, Int32> state2 = rt::newobj<Tuple<TextWriter, Array<Char>, Int32, Int32>>((TextWriter)this, buffer, index, count);
}

Task<> TextWriter___::WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (!cancellationToken.get_IsCancellationRequested()) {
    ArraySegment<Char> segment;
    if (!MemoryMarshal::TryGetArray(buffer, segment)) {
    }
    return WriteLineAsync(segment.get_Array(), segment.get_Offset(), segment.get_Count());
  }
  return Task::in::FromCanceled(cancellationToken);
}

Task<> TextWriter___::WriteLineAsync() {
  return WriteAsync(CoreNewLine);
}

Task<> TextWriter___::FlushAsync() {
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
  s_coreNewLine = "
"->ToCharArray();
}

} // namespace System::Private::CoreLib::System::IO::TextWriterNamespace
