#include "StringWriter-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/IO/StringWriter-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/UnicodeEncoding-dep.h>

namespace System::Private::CoreLib::System::IO::StringWriterNamespace {
using namespace System::Text;

Encoding StringWriter___::get_Encoding() {
  if (s_encoding == nullptr) {
    s_encoding = rt::newobj<UnicodeEncoding>(false, false);
  }
  return s_encoding;
}

void StringWriter___::ctor() {
}

void StringWriter___::ctor(IFormatProvider formatProvider) {
}

void StringWriter___::ctor(StringBuilder sb) {
}

void StringWriter___::ctor(StringBuilder sb, IFormatProvider formatProvider) {
  if (sb == nullptr) {
    rt::throw_exception<ArgumentNullException>("sb", SR::get_ArgumentNull_Buffer());
  }
  _sb = sb;
  _isOpen = true;
}

void StringWriter___::Close() {
  Dispose(true);
}

void StringWriter___::Dispose(Boolean disposing) {
  _isOpen = false;
  TextWriter::in::Dispose(disposing);
}

StringBuilder StringWriter___::GetStringBuilder() {
  return _sb;
}

void StringWriter___::Write(Char value) {
  if (!_isOpen) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_WriterClosed());
  }
  _sb->Append(value);
}

void StringWriter___::Write(Array<Char> buffer, Int32 index, Int32 count) {
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
  if (!_isOpen) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_WriterClosed());
  }
  _sb->Append(buffer, index, count);
}

void StringWriter___::Write(ReadOnlySpan<Char> buffer) {
  if (GetType() != rt::typeof<StringWriter>()) {
    TextWriter::in::Write(buffer);
    return;
  }
  if (!_isOpen) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_WriterClosed());
  }
  _sb->Append(buffer);
}

void StringWriter___::Write(String value) {
  if (!_isOpen) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_WriterClosed());
  }
  if (value != nullptr) {
    _sb->Append(value);
  }
}

void StringWriter___::Write(StringBuilder value) {
  if (GetType() != rt::typeof<StringWriter>()) {
    TextWriter::in::Write(value);
    return;
  }
  if (!_isOpen) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_WriterClosed());
  }
  _sb->Append(value);
}

void StringWriter___::WriteLine(ReadOnlySpan<Char> buffer) {
  if (GetType() != rt::typeof<StringWriter>()) {
    TextWriter::in::WriteLine(buffer);
    return;
  }
  if (!_isOpen) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_WriterClosed());
  }
  _sb->Append(buffer);
  WriteLine();
}

void StringWriter___::WriteLine(StringBuilder value) {
  if (GetType() != rt::typeof<StringWriter>()) {
    TextWriter::in::WriteLine(value);
    return;
  }
  if (!_isOpen) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_WriterClosed());
  }
  _sb->Append(value);
  WriteLine();
}

Task<> StringWriter___::WriteAsync(Char value) {
  Write(value);
  return Task<>::in::get_CompletedTask();
}

Task<> StringWriter___::WriteAsync(String value) {
  Write(value);
  return Task<>::in::get_CompletedTask();
}

Task<> StringWriter___::WriteAsync(Array<Char> buffer, Int32 index, Int32 count) {
  Write(buffer, index, count);
  return Task<>::in::get_CompletedTask();
}

Task<> StringWriter___::WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  Write(buffer.get_Span());
  return Task<>::in::get_CompletedTask();
}

Task<> StringWriter___::WriteAsync(StringBuilder value, CancellationToken cancellationToken) {
  if (GetType() != rt::typeof<StringWriter>()) {
    return TextWriter::in::WriteAsync(value, cancellationToken);
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  if (!_isOpen) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_WriterClosed());
  }
  _sb->Append(value);
  return Task<>::in::get_CompletedTask();
}

Task<> StringWriter___::WriteLineAsync(Char value) {
  WriteLine(value);
  return Task<>::in::get_CompletedTask();
}

Task<> StringWriter___::WriteLineAsync(String value) {
  WriteLine(value);
  return Task<>::in::get_CompletedTask();
}

Task<> StringWriter___::WriteLineAsync(StringBuilder value, CancellationToken cancellationToken) {
  if (GetType() != rt::typeof<StringWriter>()) {
    return TextWriter::in::WriteLineAsync(value, cancellationToken);
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  if (!_isOpen) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_ObjectDisposed_WriterClosed());
  }
  _sb->Append(value);
  WriteLine();
  return Task<>::in::get_CompletedTask();
}

Task<> StringWriter___::WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count) {
  WriteLine(buffer, index, count);
  return Task<>::in::get_CompletedTask();
}

Task<> StringWriter___::WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled(cancellationToken);
  }
  WriteLine(buffer.get_Span());
  return Task<>::in::get_CompletedTask();
}

Task<> StringWriter___::FlushAsync() {
  return Task<>::in::get_CompletedTask();
}

String StringWriter___::ToString() {
  return _sb->ToString();
}

} // namespace System::Private::CoreLib::System::IO::StringWriterNamespace
