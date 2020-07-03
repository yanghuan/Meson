#include "SafeBuffer-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::SafeBufferNamespace {
UInt64 SafeBuffer___::get_ByteLength() {
  return UInt64();
};
void SafeBuffer___::Initialize(UInt64 numBytes) {
};
void SafeBuffer___::Initialize(UInt32 numElements, UInt32 sizeOfEachElement) {
};
void SafeBuffer___::AcquirePointer(Byte*& pointer) {
};
void SafeBuffer___::ReleasePointer() {
};
void SafeBuffer___::SpaceCheck(Byte* ptr, UInt64 sizeInBytes) {
};
void SafeBuffer___::NotEnoughRoom() {
};
InvalidOperationException SafeBuffer___::NotInitialized() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::SafeBufferNamespace
