#include "Buffer-dep.h"

namespace System::Private::CoreLib::System::BufferNamespace {
void Buffer::Memcpy(Byte* dest, Byte* src, Int32 len) {
  return void();
};
Int32 Buffer::ByteLength(Array<> array) {
  return Int32();
};
Byte Buffer::GetByte(Array<> array, Int32 index) {
  return Byte();
};
void Buffer::SetByte(Array<> array, Int32 index, Byte value) {
  return void();
};
void Buffer::ZeroMemory(Byte* dest, Int64 len) {
  return void();
};
void Buffer::ZeroMemory(Byte* dest, UInt64 len) {
  return void();
};
void Buffer::MemoryCopy(void* source, void* destination, Int64 destinationSizeInBytes, Int64 sourceBytesToCopy) {
  return void();
};
void Buffer::MemoryCopy(void* source, void* destination, UInt64 destinationSizeInBytes, UInt64 sourceBytesToCopy) {
  return void();
};
void Buffer::Memcpy(Array<Byte> dest, Int32 destIndex, Byte* src, Int32 srcIndex, Int32 len) {
  return void();
};
void Buffer::Memcpy(Byte* pDest, Int32 destIndex, Array<Byte> src, Int32 srcIndex, Int32 len) {
  return void();
};
void Buffer::Memmove(Byte* dest, Byte* src, UInt64 len) {
  return void();
};
void Buffer::Memmove(Byte& dest, Byte& src, UInt64 len) {
  return void();
};
void Buffer::_Memmove(Byte* dest, Byte* src, UInt64 len) {
  return void();
};
void Buffer::_Memmove(Byte& dest, Byte& src, UInt64 len) {
  return void();
};
} // namespace System::Private::CoreLib::System::BufferNamespace
