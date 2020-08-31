#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(UIntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(UInt64)
namespace BufferNamespace {
class Buffer {
  private: struct Block16 : public valueType<Block16> {
  };
  private: struct Block64 : public valueType<Block64> {
  };
  public: static void _ZeroMemory(Byte& b, UIntPtr byteLength);
  private: static void __ZeroMemory(void* b, UIntPtr byteLength);
  public: static void BulkMoveWithWriteBarrier(Byte& destination, Byte& source, UIntPtr byteCount);
  private: static void _BulkMoveWithWriteBarrier(Byte& destination, Byte& source, UIntPtr byteCount);
  private: static void __BulkMoveWithWriteBarrier(Byte& destination, Byte& source, UIntPtr byteCount);
  private: static void __Memmove(Byte* dest, Byte* src, UIntPtr len);
  public: static void Memcpy(Byte* dest, Byte* src, Int32 len);
  public: static void Memcpy(Byte* pDest, Int32 destIndex, Array<Byte> src, Int32 srcIndex, Int32 len);
  public: template <class T>
  static void Memmove(T& destination, T& source, UIntPtr elementCount);
  public: static void BlockCopy(Array<> src, Int32 srcOffset, Array<> dst, Int32 dstOffset, Int32 count);
  public: static Int32 ByteLength(Array<> array);
  public: static Byte GetByte(Array<> array, Int32 index);
  public: static void SetByte(Array<> array, Int32 index, Byte value);
  public: static void ZeroMemory(Byte* dest, UIntPtr len);
  public: static void MemoryCopy(void* source, void* destination, Int64 destinationSizeInBytes, Int64 sourceBytesToCopy);
  public: static void MemoryCopy(void* source, void* destination, UInt64 destinationSizeInBytes, UInt64 sourceBytesToCopy);
  public: static void Memmove(Byte* dest, Byte* src, UIntPtr len);
  private: static void Memmove(Byte& dest, Byte& src, UIntPtr len);
  private: static void _Memmove(Byte* dest, Byte* src, UIntPtr len);
  private: static void _Memmove(Byte& dest, Byte& src, UIntPtr len);
};
} // namespace BufferNamespace
using Buffer = BufferNamespace::Buffer;
} // namespace System::Private::CoreLib::System
