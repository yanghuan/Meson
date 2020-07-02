#include "MemoryStream-dep.h"

namespace System::Private::CoreLib::System::IO::MemoryStreamNamespace {
Boolean MemoryStream___::get_CanRead() {
  return Boolean();
};
Boolean MemoryStream___::get_CanSeek() {
  return Boolean();
};
Boolean MemoryStream___::get_CanWrite() {
  return Boolean();
};
Int32 MemoryStream___::get_Capacity() {
  return Int32();
};
void MemoryStream___::set_Capacity(Int32 value) {
  return void();
};
Int64 MemoryStream___::get_Length() {
  return Int64();
};
Int64 MemoryStream___::get_Position() {
  return Int64();
};
void MemoryStream___::set_Position(Int64 value) {
  return void();
};
void MemoryStream___::EnsureNotClosed() {
  return void();
};
void MemoryStream___::EnsureWriteable() {
  return void();
};
void MemoryStream___::Dispose(Boolean disposing) {
  return void();
};
Boolean MemoryStream___::EnsureCapacity(Int32 value) {
  return Boolean();
};
void MemoryStream___::Flush() {
  return void();
};
Task<> MemoryStream___::FlushAsync(CancellationToken cancellationToken) {
  return nullptr;
};
Array<Byte> MemoryStream___::GetBuffer() {
  return Array<Byte>();
};
Boolean MemoryStream___::TryGetBuffer(ArraySegment<Byte>& buffer) {
  return Boolean();
};
Array<Byte> MemoryStream___::InternalGetBuffer() {
  return Array<Byte>();
};
Int32 MemoryStream___::InternalGetPosition() {
  return Int32();
};
ReadOnlySpan<Byte> MemoryStream___::InternalReadSpan(Int32 count) {
  return ReadOnlySpan<Byte>();
};
Int32 MemoryStream___::InternalEmulateRead(Int32 count) {
  return Int32();
};
Int32 MemoryStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  return Int32();
};
Int32 MemoryStream___::Read(Span<Byte> buffer) {
  return Int32();
};
Task<Int32> MemoryStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
};
ValueTask<Int32> MemoryStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
};
Int32 MemoryStream___::ReadByte() {
  return Int32();
};
void MemoryStream___::CopyTo(Stream destination, Int32 bufferSize) {
  return void();
};
Task<> MemoryStream___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
};
Int64 MemoryStream___::Seek(Int64 offset, SeekOrigin loc) {
  return Int64();
};
void MemoryStream___::SetLength(Int64 value) {
  return void();
};
Array<Byte> MemoryStream___::ToArray() {
  return Array<Byte>();
};
void MemoryStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
  return void();
};
void MemoryStream___::Write(ReadOnlySpan<Byte> buffer) {
  return void();
};
Task<> MemoryStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
};
ValueTask<> MemoryStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<>();
};
void MemoryStream___::WriteByte(Byte value) {
  return void();
};
void MemoryStream___::WriteTo(Stream stream) {
  return void();
};
} // namespace System::Private::CoreLib::System::IO::MemoryStreamNamespace
