#include "Buffer-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/SpanHelpers-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::BufferNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::CompilerServices;

void Buffer::_ZeroMemory(Byte& b, unsigned int byteLength) {
  {
    Byte* b2 = &b;
    __ZeroMemory(b2, byteLength);
  }
}

void Buffer::BulkMoveWithWriteBarrier(Byte& destination, Byte& source, unsigned int byteCount) {
  if (byteCount <= 16384) {
    __BulkMoveWithWriteBarrier(destination, source, byteCount);
  } else {
    _BulkMoveWithWriteBarrier(destination, source, byteCount);
  }
}

void Buffer::_BulkMoveWithWriteBarrier(Byte& destination, Byte& source, unsigned int byteCount) {
  if (Unsafe::AreSame(source, destination)) {
    return;
  }
  if ((unsigned int)(int)Unsafe::ByteOffset(source, destination) >= byteCount) {
  } else {
  }
  __BulkMoveWithWriteBarrier(destination, source, byteCount);
}

void Buffer::Memcpy(Byte* dest, Byte* src, Int32 len) {
  Memmove(dest, src, (unsigned int)len);
}

void Buffer::Memcpy(Byte* pDest, Int32 destIndex, Array<Byte> src, Int32 srcIndex, Int32 len) {
  if (len != 0) {
    {
      Byte* ptr = src;
      Memcpy(pDest + destIndex, ptr + srcIndex, len);
    }
  }
}

void Buffer::BlockCopy(Array<> src, Int32 srcOffset, Array<> dst, Int32 dstOffset, Int32 count) {
  if (src == nullptr) {
    rt::throw_exception<ArgumentNullException>("src");
  }
  if (dst == nullptr) {
    rt::throw_exception<ArgumentNullException>("dst");
  }
  unsigned int num = (unsigned int)src->get_LongLength();
}

Int32 Buffer::ByteLength(Array<> array) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (!RuntimeHelpers::IsPrimitiveType(array->GetCorElementTypeOfElementType())) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBePrimArray(), "array");
  }
  unsigned int num = (unsigned int)((int)array->get_LongLength() * RuntimeHelpers::GetElementSize(array));
  return (Int32)num;
}

Byte Buffer::GetByte(Array<> array, Int32 index) {
  if ((UInt32)index >= (UInt32)ByteLength(array)) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  return Unsafe::Add(RuntimeHelpers::GetRawArrayData(array), index);
}

void Buffer::SetByte(Array<> array, Int32 index, Byte value) {
  if ((UInt32)index >= (UInt32)ByteLength(array)) {
    rt::throw_exception<ArgumentOutOfRangeException>("index");
  }
  Unsafe::Add(RuntimeHelpers::GetRawArrayData(array), index) = value;
}

void Buffer::ZeroMemory(Byte* dest, unsigned int len) {
  SpanHelpers::ClearWithoutReferences(*dest, len);
}

void Buffer::MemoryCopy(void* source, void* destination, Int64 destinationSizeInBytes, Int64 sourceBytesToCopy) {
  if (sourceBytesToCopy > destinationSizeInBytes) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::sourceBytesToCopy);
  }
  Memmove((Byte*)destination, (Byte*)source, (unsigned int)sourceBytesToCopy);
}

void Buffer::MemoryCopy(void* source, void* destination, UInt64 destinationSizeInBytes, UInt64 sourceBytesToCopy) {
  if (sourceBytesToCopy > destinationSizeInBytes) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::sourceBytesToCopy);
  }
  Memmove((Byte*)destination, (Byte*)source, (unsigned int)sourceBytesToCopy);
}

void Buffer::Memmove(Byte* dest, Byte* src, unsigned int len) {
  if ((unsigned int)((int)(unsigned int)(UIntPtr)(void*)dest - (int)(unsigned int)(UIntPtr)(void*)src) >= len && (unsigned int)((int)(unsigned int)(UIntPtr)(void*)src - (int)(unsigned int)(UIntPtr)(void*)dest) >= len) {
    Byte* ptr = src + len;
    Byte* ptr2 = dest + len;
  }
}

void Buffer::Memmove(Byte& dest, Byte& src, unsigned int len) {
  if ((unsigned int)(int)Unsafe::ByteOffset(src, dest) >= len && (unsigned int)(int)Unsafe::ByteOffset(dest, src) >= len) {
    Byte& source = Unsafe::Add(src, (int)len);
    Byte& source2 = Unsafe::Add(dest, (int)len);
  }
  if (Unsafe::AreSame(dest, src)) {
    return;
  }
}

void Buffer::_Memmove(Byte* dest, Byte* src, unsigned int len) {
  __Memmove(dest, src, len);
}

void Buffer::_Memmove(Byte& dest, Byte& src, unsigned int len) {
  {
    Byte* dest2 = &dest;
    {
      Byte* src2 = &src;
      __Memmove(dest2, src2, len);
    }
  }
}

} // namespace System::Private::CoreLib::System::BufferNamespace
