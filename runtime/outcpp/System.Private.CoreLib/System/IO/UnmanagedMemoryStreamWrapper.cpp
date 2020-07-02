#include "UnmanagedMemoryStreamWrapper-dep.h"

namespace System::Private::CoreLib::System::IO::UnmanagedMemoryStreamWrapperNamespace {
Boolean UnmanagedMemoryStreamWrapper___::get_CanRead() {
  return Boolean();
};
Boolean UnmanagedMemoryStreamWrapper___::get_CanSeek() {
  return Boolean();
};
Boolean UnmanagedMemoryStreamWrapper___::get_CanWrite() {
  return Boolean();
};
Int32 UnmanagedMemoryStreamWrapper___::get_Capacity() {
  return Int32();
};
void UnmanagedMemoryStreamWrapper___::set_Capacity(Int32 value) {
  return void();
};
Int64 UnmanagedMemoryStreamWrapper___::get_Length() {
  return Int64();
};
Int64 UnmanagedMemoryStreamWrapper___::get_Position() {
  return Int64();
};
void UnmanagedMemoryStreamWrapper___::set_Position(Int64 value) {
  return void();
};
void UnmanagedMemoryStreamWrapper___::Dispose(Boolean disposing) {
  return void();
};
void UnmanagedMemoryStreamWrapper___::Flush() {
  return void();
};
Array<Byte> UnmanagedMemoryStreamWrapper___::GetBuffer() {
  return Array<Byte>();
};
Boolean UnmanagedMemoryStreamWrapper___::TryGetBuffer(ArraySegment<Byte>& buffer) {
  return Boolean();
};
Int32 UnmanagedMemoryStreamWrapper___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  return Int32();
};
Int32 UnmanagedMemoryStreamWrapper___::Read(Span<Byte> buffer) {
  return Int32();
};
Int32 UnmanagedMemoryStreamWrapper___::ReadByte() {
  return Int32();
};
Int64 UnmanagedMemoryStreamWrapper___::Seek(Int64 offset, SeekOrigin loc) {
  return Int64();
};
Array<Byte> UnmanagedMemoryStreamWrapper___::ToArray() {
  return Array<Byte>();
};
void UnmanagedMemoryStreamWrapper___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
  return void();
};
void UnmanagedMemoryStreamWrapper___::Write(ReadOnlySpan<Byte> buffer) {
  return void();
};
void UnmanagedMemoryStreamWrapper___::WriteByte(Byte value) {
  return void();
};
void UnmanagedMemoryStreamWrapper___::WriteTo(Stream stream) {
  return void();
};
void UnmanagedMemoryStreamWrapper___::SetLength(Int64 value) {
  return void();
};
Task<> UnmanagedMemoryStreamWrapper___::CopyToAsync(Stream destination, Int32 bufferSize, CancellationToken cancellationToken) {
  return nullptr;
};
Task<> UnmanagedMemoryStreamWrapper___::FlushAsync(CancellationToken cancellationToken) {
  return nullptr;
};
Task<Int32> UnmanagedMemoryStreamWrapper___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
};
ValueTask<Int32> UnmanagedMemoryStreamWrapper___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
};
Task<> UnmanagedMemoryStreamWrapper___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
};
ValueTask<> UnmanagedMemoryStreamWrapper___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<>();
};
} // namespace System::Private::CoreLib::System::IO::UnmanagedMemoryStreamWrapperNamespace
