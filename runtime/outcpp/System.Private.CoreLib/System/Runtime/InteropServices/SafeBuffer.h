#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/UIntPtr.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARD(InvalidOperationException)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace SafeBufferNamespace {
CLASS(SafeBuffer) {
  private: static UIntPtr get_Uninitialized();
  public: UInt64 get_ByteLength();
  protected: void Ctor(Boolean ownsHandle);
  public: void Initialize(UInt64 numBytes);
  public: void Initialize(UInt32 numElements, UInt32 sizeOfEachElement);
  public: void AcquirePointer(Byte*& pointer);
  public: void ReleasePointer();
  private: void SpaceCheck(Byte* ptr, UIntPtr sizeInBytes);
  private: static void NotEnoughRoom();
  private: static InvalidOperationException NotInitialized();
  private: UIntPtr _numBytes;
};
} // namespace SafeBufferNamespace
using SafeBuffer = SafeBufferNamespace::SafeBuffer;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
