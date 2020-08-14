#include "SafeBuffer-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::SafeBufferNamespace {
UIntPtr SafeBuffer___::get_Uninitialized() {
  return UIntPtr::get_MaxValue();
}

UInt64 SafeBuffer___::get_ByteLength() {
  if (_numBytes == get_Uninitialized()) {
    rt::throw_exception(NotInitialized());
  }
  return _numBytes;
}

void SafeBuffer___::ctor(Boolean ownsHandle) {
  _numBytes = get_Uninitialized();
}

void SafeBuffer___::Initialize(UInt64 numBytes) {
  if (IntPtr::get_Size() == 4) {
  }
  if (numBytes >= get_Uninitialized()) {
    rt::throw_exception<ArgumentOutOfRangeException>("numBytes", SR::get_ArgumentOutOfRange_UIntPtrMax());
  }
  _numBytes = (UIntPtr)numBytes;
}

void SafeBuffer___::Initialize(UInt32 numElements, UInt32 sizeOfEachElement) {
  Initialize((UInt64)numElements * (UInt64)sizeOfEachElement);
}

void SafeBuffer___::AcquirePointer(Byte*& pointer) {
  if (_numBytes == get_Uninitialized()) {
    rt::throw_exception(NotInitialized());
  }
  pointer = nullptr;
  Boolean success = false;
  DangerousAddRef(success);
  pointer = (Byte*)(void*)handle;
}

void SafeBuffer___::ReleasePointer() {
  if (_numBytes == get_Uninitialized()) {
    rt::throw_exception(NotInitialized());
  }
  DangerousRelease();
}

void SafeBuffer___::SpaceCheck(Byte* ptr, UIntPtr sizeInBytes) {
  if (_numBytes < sizeInBytes) {
    NotEnoughRoom();
  }
  if ((UInt64)(ptr - (Byte*)(void*)handle) > (UInt64)(_numBytes - sizeInBytes)) {
    NotEnoughRoom();
  }
}

void SafeBuffer___::NotEnoughRoom() {
  rt::throw_exception<ArgumentException>(SR::get_Arg_BufferTooSmall());
}

InvalidOperationException SafeBuffer___::NotInitialized() {
  return rt::newobj<InvalidOperationException>(SR::get_InvalidOperation_MustCallInitialize());
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::SafeBufferNamespace
