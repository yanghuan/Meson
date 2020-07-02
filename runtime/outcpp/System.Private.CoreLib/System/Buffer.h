#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(UInt64)
FORWARDS(Int64)
namespace BufferNamespace {
class Buffer {
  private: struct Block16 {
  };
  private: struct Block64 {
  };
  public: static void BlockCopy(Array<> src, Int32 srcOffset, Array<> dst, Int32 dstOffset, Int32 count);
  private: static Boolean IsPrimitiveTypeArray(Array<> array);
  private: static Int32 _ByteLength(Array<> array);
  public: static void Memcpy(Byte* dest, Byte* src, Int32 len);
  private: static void __Memmove(Byte* dest, Byte* src, UInt64 len);
  public: static Int32 ByteLength(Array<> array);
  public: static Byte GetByte(Array<> array, Int32 index);
  public: static void SetByte(Array<> array, Int32 index, Byte value);
  public: static void ZeroMemory(Byte* dest, Int64 len);
  public: static void ZeroMemory(Byte* dest, UInt64 len);
  public: static void MemoryCopy(void* source, void* destination, Int64 destinationSizeInBytes, Int64 sourceBytesToCopy);
  public: static void MemoryCopy(void* source, void* destination, UInt64 destinationSizeInBytes, UInt64 sourceBytesToCopy);
  public: static void Memcpy(Array<Byte> dest, Int32 destIndex, Byte* src, Int32 srcIndex, Int32 len);
  public: static void Memcpy(Byte* pDest, Int32 destIndex, Array<Byte> src, Int32 srcIndex, Int32 len);
  public: static void Memmove(Byte* dest, Byte* src, UInt64 len);
  private: static void Memmove(Byte& dest, Byte& src, UInt64 len);
  private: static void _Memmove(Byte* dest, Byte* src, UInt64 len);
  private: static void _Memmove(Byte& dest, Byte& src, UInt64 len);
};
} // namespace BufferNamespace
using Buffer = BufferNamespace::Buffer;
} // namespace System::Private::CoreLib::System
