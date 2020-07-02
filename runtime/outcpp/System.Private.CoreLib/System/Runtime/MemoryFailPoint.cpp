#include "MemoryFailPoint-dep.h"

namespace System::Private::CoreLib::System::Runtime::MemoryFailPointNamespace {
Int64 MemoryFailPoint___::get_LastKnownFreeAddressSpace() {
  return Int64();
};
void MemoryFailPoint___::set_LastKnownFreeAddressSpace(Int64 value) {
  return void();
};
Int64 MemoryFailPoint___::get_LastTimeCheckingAddressSpace() {
  return Int64();
};
void MemoryFailPoint___::set_LastTimeCheckingAddressSpace(Int64 value) {
  return void();
};
UInt64 MemoryFailPoint___::get_MemoryFailPointReservedMemory() {
  return UInt64();
};
Int64 MemoryFailPoint___::AddToLastKnownFreeAddressSpace(Int64 addend) {
  return Int64();
};
void MemoryFailPoint___::Finalize() {
  return void();
};
void MemoryFailPoint___::Dispose() {
  return void();
};
void MemoryFailPoint___::Dispose(Boolean disposing) {
  return void();
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
Boolean MemoryFailPoint___::CheckForFreeAddressSpace(UInt64 size, Boolean shouldThrow) {
  return Boolean();
};
UInt64 MemoryFailPoint___::MemFreeAfterAddress(void* address, UInt64 size) {
  return UInt64();
};
void MemoryFailPoint___::GrowPageFileIfNecessaryAndPossible(UIntPtr numBytes) {
  return void();
};
} // namespace System::Private::CoreLib::System::Runtime::MemoryFailPointNamespace
