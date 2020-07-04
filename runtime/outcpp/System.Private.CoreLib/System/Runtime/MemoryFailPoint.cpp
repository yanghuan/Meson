#include "MemoryFailPoint-dep.h"

namespace System::Private::CoreLib::System::Runtime::MemoryFailPointNamespace {
Int64 MemoryFailPoint___::get_LastKnownFreeAddressSpace() {
  return Int64();
};
void MemoryFailPoint___::set_LastKnownFreeAddressSpace(Int64 value) {
};
Int64 MemoryFailPoint___::get_LastTimeCheckingAddressSpace() {
  return Int64();
};
void MemoryFailPoint___::set_LastTimeCheckingAddressSpace(Int64 value) {
};
UInt64 MemoryFailPoint___::get_MemoryFailPointReservedMemory() {
  return UInt64();
};
void MemoryFailPoint___::AddToLastKnownFreeAddressSpace(Int64 addend) {
};
void MemoryFailPoint___::Finalize() {
};
void MemoryFailPoint___::Dispose() {
};
void MemoryFailPoint___::Dispose(Boolean disposing) {
};
Int64 MemoryFailPoint___::AddMemoryFailPointReservation(Int64 size) {
  return Int64();
};
UInt64 MemoryFailPoint___::GetTopOfMemory() {
  return UInt64();
};
Boolean MemoryFailPoint___::CheckForAvailableMemory(UInt64& availPageFile, UInt64& totalAddressSpaceFree) {
  return Boolean();
};
void MemoryFailPoint___::CheckForFreeAddressSpace(UInt64 size, Boolean shouldThrow) {
};
UInt64 MemoryFailPoint___::MemFreeAfterAddress(void* address, UInt64 size) {
  return UInt64();
};
void MemoryFailPoint___::GrowPageFileIfNecessaryAndPossible(UIntPtr numBytes) {
};
} // namespace System::Private::CoreLib::System::Runtime::MemoryFailPointNamespace
