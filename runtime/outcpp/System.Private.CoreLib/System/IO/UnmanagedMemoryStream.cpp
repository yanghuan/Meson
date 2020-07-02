#include "UnmanagedMemoryStream-dep.h"

namespace System::Private::CoreLib::System::IO::UnmanagedMemoryStreamNamespace {
Boolean UnmanagedMemoryStream___::get_CanRead() {
  return Boolean();
};
Boolean UnmanagedMemoryStream___::get_CanSeek() {
  return Boolean();
};
Boolean UnmanagedMemoryStream___::get_CanWrite() {
  return Boolean();
};
Int64 UnmanagedMemoryStream___::get_Length() {
  return Int64();
};
Int64 UnmanagedMemoryStream___::get_Capacity() {
  return Int64();
};
Int64 UnmanagedMemoryStream___::get_Position() {
  return Int64();
};
void UnmanagedMemoryStream___::set_Position(Int64 value) {
  return void();
};
Byte* UnmanagedMemoryStream___::get_PositionPointer() {
  return nullptr;
};
void UnmanagedMemoryStream___::set_PositionPointer(Byte* value) {
  return void();
};
void UnmanagedMemoryStream___::Initialize(SafeBuffer buffer, Int64 offset, Int64 length, FileAccess access) {
  return void();
};
void UnmanagedMemoryStream___::Initialize(Byte* pointer, Int64 length, Int64 capacity, FileAccess access) {
  return void();
};
void UnmanagedMemoryStream___::Dispose(Boolean disposing) {
  return void();
};
void UnmanagedMemoryStream___::EnsureNotClosed() {
  return void();
};
void UnmanagedMemoryStream___::EnsureReadable() {
  return void();
};
void UnmanagedMemoryStream___::EnsureWriteable() {
  return void();
};
void UnmanagedMemoryStream___::Flush() {
  return void();
};
Task<> UnmanagedMemoryStream___::FlushAsync(CancellationToken cancellationToken) {
  return nullptr;
};
Int32 UnmanagedMemoryStream___::Read(Array<Byte> buffer, Int32 offset, Int32 count) {
  return Int32();
};
Int32 UnmanagedMemoryStream___::Read(Span<Byte> buffer) {
  return Int32();
};
Int32 UnmanagedMemoryStream___::ReadCore(Span<Byte> buffer) {
  return Int32();
};
Task<Int32> UnmanagedMemoryStream___::ReadAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
};
ValueTask<Int32> UnmanagedMemoryStream___::ReadAsync(Memory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<Int32>();
};
Int32 UnmanagedMemoryStream___::ReadByte() {
  return Int32();
};
Int64 UnmanagedMemoryStream___::Seek(Int64 offset, SeekOrigin loc) {
  return Int64();
};
void UnmanagedMemoryStream___::SetLength(Int64 value) {
  return void();
};
void UnmanagedMemoryStream___::Write(Array<Byte> buffer, Int32 offset, Int32 count) {
  return void();
};
void UnmanagedMemoryStream___::Write(ReadOnlySpan<Byte> buffer) {
  return void();
};
void UnmanagedMemoryStream___::WriteCore(ReadOnlySpan<Byte> buffer) {
  return void();
};
Task<> UnmanagedMemoryStream___::WriteAsync(Array<Byte> buffer, Int32 offset, Int32 count, CancellationToken cancellationToken) {
  return nullptr;
};
ValueTask<> UnmanagedMemoryStream___::WriteAsync(ReadOnlyMemory<Byte> buffer, CancellationToken cancellationToken) {
  return ValueTask<>();
};
void UnmanagedMemoryStream___::WriteByte(Byte value) {
  return void();
};
} // namespace System::Private::CoreLib::System::IO::UnmanagedMemoryStreamNamespace