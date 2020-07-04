#include "Buffer-dep.h"

namespace System::Private::CoreLib::System::BufferNamespace {
void Buffer::_ZeroMemory(Byte& b, UIntPtr byteLength) {
};
void Buffer::BulkMoveWithWriteBarrier(Byte& destination, Byte& source, UIntPtr byteCount) {
};
void Buffer::_BulkMoveWithWriteBarrier(Byte& destination, Byte& source, UIntPtr byteCount) {
};
void Buffer::Memcpy(Byte* dest, Byte* src, Int32 len) {
};
void Buffer::Memcpy(Byte* pDest, Int32 destIndex, Array<Byte> src, Int32 srcIndex, Int32 len) {
};
void Buffer::BlockCopy(Array<> src, Int32 srcOffset, Array<> dst, Int32 dstOffset, Int32 count) {
};
Int32 Buffer::ByteLength(Array<> array) {
  return Int32();
};
Byte Buffer::GetByte(Array<> array, Int32 index) {
  return Byte();
};
void Buffer::SetByte(Array<> array, Int32 index, Byte value) {
};
void Buffer::ZeroMemory(Byte* dest, UIntPtr len) {
};
void Buffer::MemoryCopy(void* source, void* destination, Int64 destinationSizeInBytes, Int64 sourceBytesToCopy) {
};
void Buffer::MemoryCopy(void* source, void* destination, UInt64 destinationSizeInBytes, UInt64 sourceBytesToCopy) {
};
void Buffer::Memmove(Byte* dest, Byte* src, UIntPtr len) {
};
void Buffer::Memmove(Byte& dest, Byte& src, UIntPtr len) {
};
void Buffer::_Memmove(Byte* dest, Byte* src, UIntPtr len) {
};
void Buffer::_Memmove(Byte& dest, Byte& src, UIntPtr len) {
};
} // namespace System::Private::CoreLib::System::BufferNamespace
