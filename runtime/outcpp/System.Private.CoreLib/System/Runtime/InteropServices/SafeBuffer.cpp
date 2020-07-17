#include "SafeBuffer-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::SafeBufferNamespace {
UIntPtr SafeBuffer___::get_Uninitialized() {
  return UIntPtr();
};

UInt64 SafeBuffer___::get_ByteLength() {
  return UInt64();
};

void SafeBuffer___::Ctor(Boolean ownsHandle) {
};

void SafeBuffer___::Initialize(UInt64 numBytes) {
};

void SafeBuffer___::Initialize(UInt32 numElements, UInt32 sizeOfEachElement) {
};

void SafeBuffer___::AcquirePointer(Byte*& pointer) {
};

void SafeBuffer___::ReleasePointer() {
};

void SafeBuffer___::SpaceCheck(Byte* ptr, UIntPtr sizeInBytes) {
};

void SafeBuffer___::NotEnoughRoom() {
};

InvalidOperationException SafeBuffer___::NotInitialized() {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::SafeBufferNamespace
