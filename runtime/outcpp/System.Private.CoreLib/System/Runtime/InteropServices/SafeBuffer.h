#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/UIntPtr.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt64)
FORWARDS(UInt32)
FORWARDS(Byte)
FORWARD(InvalidOperationException)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace SafeBufferNamespace {
CLASS(SafeBuffer) {
  public: UInt64 get_ByteLength();
  public: void Initialize(UInt64 numBytes);
  public: void Initialize(UInt32 numElements, UInt32 sizeOfEachElement);
  public: void AcquirePointer(Byte*& pointer);
  public: void ReleasePointer();
  private: void SpaceCheck(Byte* ptr, UInt64 sizeInBytes);
  private: static void NotEnoughRoom();
  private: static InvalidOperationException NotInitialized();
  private: static UIntPtr Uninitialized;
  private: UIntPtr _numBytes;
};
} // namespace SafeBufferNamespace
using SafeBuffer = SafeBufferNamespace::SafeBuffer;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
