#include "SecureString-dep.h"

#include <System.Private.CoreLib/System/Security/SecureString-dep.h>

namespace System::Private::CoreLib::System::Security::SecureStringNamespace {
SecureString::in::UnmanagedBuffer SecureString___::UnmanagedBuffer___::Allocate(Int32 byteLength) {
  return nullptr;
};
void SecureString___::UnmanagedBuffer___::Copy(UnmanagedBuffer source, UnmanagedBuffer destination, UInt64 bytesLength) {
};
Boolean SecureString___::UnmanagedBuffer___::ReleaseHandle() {
  return Boolean();
};
Int32 SecureString___::get_Length() {
  return Int32();
};
void SecureString___::Initialize(ReadOnlySpan<Char> value) {
};
void SecureString___::EnsureCapacity(Int32 capacity) {
};
void SecureString___::AppendChar(Char c) {
};
void SecureString___::Clear() {
};
SecureString SecureString___::Copy() {
  return nullptr;
};
void SecureString___::Dispose() {
};
void SecureString___::InsertAt(Int32 index, Char c) {
};
Boolean SecureString___::IsReadOnly() {
  return Boolean();
};
void SecureString___::MakeReadOnly() {
};
void SecureString___::RemoveAt(Int32 index) {
};
void SecureString___::SetAt(Int32 index, Char c) {
};
Span<Char> SecureString___::AcquireSpan(SafeBuffer& bufferToRelease) {
  return Span<Char>();
};
void SecureString___::EnsureNotReadOnly() {
};
void SecureString___::EnsureNotDisposed() {
};
IntPtr SecureString___::MarshalToBSTR() {
  return IntPtr();
};
IntPtr SecureString___::MarshalToString(Boolean globalAlloc, Boolean unicode) {
  return IntPtr();
};
Int32 SecureString___::GetAlignedByteSize(Int32 length) {
  return Int32();
};
void SecureString___::ProtectMemory() {
};
void SecureString___::UnprotectMemory() {
};
} // namespace System::Private::CoreLib::System::Security::SecureStringNamespace
