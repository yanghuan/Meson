#pragma once

#include <System.Private.CoreLib/Microsoft/Win32/SafeHandles/SafeHandleZeroOrMinusOneIsInvalid.h>
#include <System.Private.CoreLib/System/UIntPtr.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARD(InvalidOperationException)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace SafeBufferNamespace {
using namespace ::System::Private::CoreLib::Microsoft::Win32::SafeHandles;
CLASS(SafeBuffer) : public SafeHandleZeroOrMinusOneIsInvalid::in {
  private: static UIntPtr get_Uninitialized();
  public: UInt64 get_ByteLength();
  protected: void ctor(Boolean ownsHandle);
  public: void Initialize(UInt64 numBytes);
  public: void Initialize(UInt32 numElements, UInt32 sizeOfEachElement);
  public: template <class T>
  void Initialize(UInt32 numElements);
  public: void AcquirePointer(Byte*& pointer);
  public: void ReleasePointer();
  public: template <class T>
  T Read(UInt64 byteOffset);
  public: template <class T>
  void ReadArray(UInt64 byteOffset, Array<T> array, Int32 index, Int32 count);
  public: template <class T>
  void Write(UInt64 byteOffset, T value);
  public: template <class T>
  void WriteArray(UInt64 byteOffset, Array<T> array, Int32 index, Int32 count);
  private: void SpaceCheck(Byte* ptr, UIntPtr sizeInBytes);
  private: static void NotEnoughRoom();
  private: static InvalidOperationException NotInitialized();
  public: template <class T>
  static UInt32 AlignedSizeOf();
  public: template <class T>
  static UInt32 SizeOf();
  private: UIntPtr _numBytes;
};
} // namespace SafeBufferNamespace
using SafeBuffer = SafeBufferNamespace::SafeBuffer;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
