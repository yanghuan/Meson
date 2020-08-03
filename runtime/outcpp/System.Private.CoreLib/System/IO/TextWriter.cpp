#include "TextWriter-dep.h"

#include <System.Private.CoreLib/System/IO/TextWriter-dep.h>

namespace System::Private::CoreLib::System::IO::TextWriterNamespace {
Encoding NullTextWriter___::get_Encoding() {
  return nullptr;
}

void NullTextWriter___::Ctor() {
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
  return nullptr;
}

IFormatProvider SyncTextWriter___::get_FormatProvider() {
  return nullptr;
}

String SyncTextWriter___::get_NewLine() {
  return nullptr;
}

void SyncTextWriter___::set_NewLine(String value) {
}

void SyncTextWriter___::Ctor(TextWriter t) {
}

void SyncTextWriter___::Close() {
}

void SyncTextWriter___::Dispose(Boolean disposing) {
}

void SyncTextWriter___::Flush() {
}

void SyncTextWriter___::Write(Char value) {
}

void SyncTextWriter___::Write(Array<Char> buffer) {
}

void SyncTextWriter___::Write(Array<Char> buffer, Int32 index, Int32 count) {
}

void SyncTextWriter___::Write(ReadOnlySpan<Char> buffer) {
}

void SyncTextWriter___::Write(Boolean value) {
}

void SyncTextWriter___::Write(Int32 value) {
}

void SyncTextWriter___::Write(UInt32 value) {
}

void SyncTextWriter___::Write(Int64 value) {
}

void SyncTextWriter___::Write(UInt64 value) {
}

void SyncTextWriter___::Write(Single value) {
}

void SyncTextWriter___::Write(Double value) {
}

void SyncTextWriter___::Write(Decimal value) {
}

void SyncTextWriter___::Write(String value) {
}

void SyncTextWriter___::Write(StringBuilder value) {
}

void SyncTextWriter___::Write(Object value) {
}

void SyncTextWriter___::Write(String format, Object arg0) {
}

void SyncTextWriter___::Write(String format, Object arg0, Object arg1) {
}

void SyncTextWriter___::Write(String format, Object arg0, Object arg1, Object arg2) {
}

void SyncTextWriter___::Write(String format, Array<Object> arg) {
}

void SyncTextWriter___::WriteLine() {
}

void SyncTextWriter___::WriteLine(Char value) {
}

void SyncTextWriter___::WriteLine(Decimal value) {
}

void SyncTextWriter___::WriteLine(Array<Char> buffer) {
}

void SyncTextWriter___::WriteLine(Array<Char> buffer, Int32 index, Int32 count) {
}

void SyncTextWriter___::WriteLine(ReadOnlySpan<Char> buffer) {
}

void SyncTextWriter___::WriteLine(Boolean value) {
}

void SyncTextWriter___::WriteLine(Int32 value) {
}

void SyncTextWriter___::WriteLine(UInt32 value) {
}

void SyncTextWriter___::WriteLine(Int64 value) {
}

void SyncTextWriter___::WriteLine(UInt64 value) {
}

void SyncTextWriter___::WriteLine(Single value) {
}

void SyncTextWriter___::WriteLine(Double value) {
}

void SyncTextWriter___::WriteLine(String value) {
}

void SyncTextWriter___::WriteLine(StringBuilder value) {
}

void SyncTextWriter___::WriteLine(Object value) {
}

void SyncTextWriter___::WriteLine(String format, Object arg0) {
}

void SyncTextWriter___::WriteLine(String format, Object arg0, Object arg1) {
}

void SyncTextWriter___::WriteLine(String format, Object arg0, Object arg1, Object arg2) {
}

void SyncTextWriter___::WriteLine(String format, Array<Object> arg) {
}

ValueTask<> SyncTextWriter___::DisposeAsync() {
  return ValueTask<>();
}

Task<> SyncTextWriter___::WriteAsync(Char value) {
  return nullptr;
}

Task<> SyncTextWriter___::WriteAsync(String value) {
  return nullptr;
}

Task<> SyncTextWriter___::WriteAsync(StringBuilder value, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> SyncTextWriter___::WriteAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
}

Task<> SyncTextWriter___::WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> SyncTextWriter___::WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> SyncTextWriter___::WriteLineAsync(Char value) {
  return nullptr;
}

Task<> SyncTextWriter___::WriteLineAsync() {
  return nullptr;
}

Task<> SyncTextWriter___::WriteLineAsync(String value) {
  return nullptr;
}

Task<> SyncTextWriter___::WriteLineAsync(StringBuilder value, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> SyncTextWriter___::WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
}

Task<> SyncTextWriter___::FlushAsync() {
  return nullptr;
}

IFormatProvider TextWriter___::get_FormatProvider() {
  return nullptr;
}

String TextWriter___::get_NewLine() {
  return nullptr;
}

void TextWriter___::set_NewLine(String value) {
}

void TextWriter___::Ctor() {
}

void TextWriter___::Ctor(IFormatProvider formatProvider) {
}

void TextWriter___::Close() {
}

void TextWriter___::Dispose(Boolean disposing) {
}

void TextWriter___::Dispose() {
}

ValueTask<> TextWriter___::DisposeAsync() {
  return ValueTask<>();
}

void TextWriter___::Flush() {
}

void TextWriter___::Write(Char value) {
}

void TextWriter___::Write(Array<Char> buffer) {
}

void TextWriter___::Write(Array<Char> buffer, Int32 index, Int32 count) {
}

void TextWriter___::Write(ReadOnlySpan<Char> buffer) {
}

void TextWriter___::Write(Boolean value) {
}

void TextWriter___::Write(Int32 value) {
}

void TextWriter___::Write(UInt32 value) {
}

void TextWriter___::Write(Int64 value) {
}

void TextWriter___::Write(UInt64 value) {
}

void TextWriter___::Write(Single value) {
}

void TextWriter___::Write(Double value) {
}

void TextWriter___::Write(Decimal value) {
}

void TextWriter___::Write(String value) {
}

void TextWriter___::Write(Object value) {
}

void TextWriter___::Write(StringBuilder value) {
}

void TextWriter___::Write(String format, Object arg0) {
}

void TextWriter___::Write(String format, Object arg0, Object arg1) {
}

void TextWriter___::Write(String format, Object arg0, Object arg1, Object arg2) {
}

void TextWriter___::Write(String format, Array<Object> arg) {
}

void TextWriter___::WriteLine() {
}

void TextWriter___::WriteLine(Char value) {
}

void TextWriter___::WriteLine(Array<Char> buffer) {
}

void TextWriter___::WriteLine(Array<Char> buffer, Int32 index, Int32 count) {
}

void TextWriter___::WriteLine(ReadOnlySpan<Char> buffer) {
}

void TextWriter___::WriteLine(Boolean value) {
}

void TextWriter___::WriteLine(Int32 value) {
}

void TextWriter___::WriteLine(UInt32 value) {
}

void TextWriter___::WriteLine(Int64 value) {
}

void TextWriter___::WriteLine(UInt64 value) {
}

void TextWriter___::WriteLine(Single value) {
}

void TextWriter___::WriteLine(Double value) {
}

void TextWriter___::WriteLine(Decimal value) {
}

void TextWriter___::WriteLine(String value) {
}

void TextWriter___::WriteLine(StringBuilder value) {
}

void TextWriter___::WriteLine(Object value) {
}

void TextWriter___::WriteLine(String format, Object arg0) {
}

void TextWriter___::WriteLine(String format, Object arg0, Object arg1) {
}

void TextWriter___::WriteLine(String format, Object arg0, Object arg1, Object arg2) {
}

void TextWriter___::WriteLine(String format, Array<Object> arg) {
}

Task<> TextWriter___::WriteAsync(Char value) {
  return nullptr;
}

Task<> TextWriter___::WriteAsync(String value) {
  return nullptr;
}

Task<> TextWriter___::WriteAsync(StringBuilder value, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> TextWriter___::WriteAsync(Array<Char> buffer) {
  return nullptr;
}

Task<> TextWriter___::WriteAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
}

Task<> TextWriter___::WriteAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> TextWriter___::WriteLineAsync(Char value) {
  return nullptr;
}

Task<> TextWriter___::WriteLineAsync(String value) {
  return nullptr;
}

Task<> TextWriter___::WriteLineAsync(StringBuilder value, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> TextWriter___::WriteLineAsync(Array<Char> buffer) {
  return nullptr;
}

Task<> TextWriter___::WriteLineAsync(Array<Char> buffer, Int32 index, Int32 count) {
  return nullptr;
}

Task<> TextWriter___::WriteLineAsync(ReadOnlyMemory<Char> buffer, CancellationToken cancellationToken) {
  return nullptr;
}

Task<> TextWriter___::WriteLineAsync() {
  return nullptr;
}

Task<> TextWriter___::FlushAsync() {
  return nullptr;
}

TextWriter TextWriter___::Synchronized(TextWriter writer) {
  return nullptr;
}

void TextWriter___::SCtor() {
}

} // namespace System::Private::CoreLib::System::IO::TextWriterNamespace
