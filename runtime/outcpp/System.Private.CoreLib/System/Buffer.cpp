#include "Buffer-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/SpanHelpers-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::BufferNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::CompilerServices;

void Buffer::_ZeroMemory(Byte& b, UIntPtr byteLength) {
  {
    Byte* b2 = &b;
    __ZeroMemory(b2, byteLength);
  }
}

void Buffer::BulkMoveWithWriteBarrier(Byte& destination, Byte& source, UIntPtr byteCount) {
  if (byteCount <= 16384) {
    __BulkMoveWithWriteBarrier(destination, source, byteCount);
  } else {
    _BulkMoveWithWriteBarrier(destination, source, byteCount);
  }
}

void Buffer::_BulkMoveWithWriteBarrier(Byte& destination, Byte& source, UIntPtr byteCount) {
  if (Unsafe::AreSame(source, destination)) {
    return;
  }
  if ((UInt64)(Int64)Unsafe::ByteOffset(source, destination) >= (UInt64)byteCount) {
    do {
      byteCount -= 16384;
      __BulkMoveWithWriteBarrier(destination, source, (UIntPtr)(UInt32)16384u);
      destination = Unsafe::AddByteOffset(destination, (UIntPtr)(UInt32)16384u);
      source = Unsafe::AddByteOffset(source, (UIntPtr)(UInt32)16384u);
    } while (byteCount > 16384);
  } else {
    do {
      byteCount -= 16384;
      __BulkMoveWithWriteBarrier(Unsafe::AddByteOffset(destination, byteCount), Unsafe::AddByteOffset(source, byteCount), (UIntPtr)(UInt32)16384u);
    } while (byteCount > 16384);
  }
  __BulkMoveWithWriteBarrier(destination, source, byteCount);
}

void Buffer::Memcpy(Byte* dest, Byte* src, Int32 len) {
  Memmove(dest, src, (UIntPtr)len);
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
  UIntPtr uIntPtr = (UIntPtr)(void*)src->get_LongLength();
  if (src->GetType() != typeof<Array<Byte>>()) {
    if (!RuntimeHelpers::IsPrimitiveType(src->GetCorElementTypeOfElementType())) {
      rt::throw_exception<ArgumentException>(SR::get_Arg_MustBePrimArray(), "src");
    }
    uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr * (UInt64)RuntimeHelpers::GetElementSize(src));
  }
  UIntPtr uIntPtr2 = uIntPtr;
  if (src != dst) {
    uIntPtr2 = (UIntPtr)(void*)dst->get_LongLength();
    if (dst->GetType() != typeof<Array<Byte>>()) {
      if (!RuntimeHelpers::IsPrimitiveType(dst->GetCorElementTypeOfElementType())) {
        rt::throw_exception<ArgumentException>(SR::get_Arg_MustBePrimArray(), "dst");
      }
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 * (UInt64)RuntimeHelpers::GetElementSize(dst));
    }
  }
  if (srcOffset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("srcOffset", SR::get_ArgumentOutOfRange_MustBeNonNegInt32());
  }
  if (dstOffset < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("dstOffset", SR::get_ArgumentOutOfRange_MustBeNonNegInt32());
  }
  if (count < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("count", SR::get_ArgumentOutOfRange_MustBeNonNegInt32());
  }
  UIntPtr uIntPtr3 = (UIntPtr)(void*)count;
  UIntPtr uIntPtr4 = (UIntPtr)(void*)srcOffset;
  UIntPtr uIntPtr5 = (UIntPtr)(void*)dstOffset;
  if ((UInt64)uIntPtr < (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr4 + (Int64)(UInt64)uIntPtr3) || (UInt64)uIntPtr2 < (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr5 + (Int64)(UInt64)uIntPtr3)) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidOffLen());
  }
  Memmove(Unsafe::AddByteOffset(RuntimeHelpers::GetRawArrayData(dst), uIntPtr5), Unsafe::AddByteOffset(RuntimeHelpers::GetRawArrayData(src), uIntPtr4), uIntPtr3);
}

Int32 Buffer::ByteLength(Array<> array) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (!RuntimeHelpers::IsPrimitiveType(array->GetCorElementTypeOfElementType())) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBePrimArray(), "array");
  }
  UIntPtr uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(IntPtr)(void*)array->get_LongLength() * (UInt64)RuntimeHelpers::GetElementSize(array));
  return (Int32)(UInt64)uIntPtr;
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

void Buffer::ZeroMemory(Byte* dest, UIntPtr len) {
  SpanHelpers::ClearWithoutReferences(*dest, len);
}

void Buffer::MemoryCopy(void* source, void* destination, Int64 destinationSizeInBytes, Int64 sourceBytesToCopy) {
  if (sourceBytesToCopy > destinationSizeInBytes) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::sourceBytesToCopy);
  }
  Memmove((Byte*)destination, (Byte*)source, (UIntPtr)(UInt64)sourceBytesToCopy);
}

void Buffer::MemoryCopy(void* source, void* destination, UInt64 destinationSizeInBytes, UInt64 sourceBytesToCopy) {
  if (sourceBytesToCopy > destinationSizeInBytes) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::sourceBytesToCopy);
  }
  Memmove((Byte*)destination, (Byte*)source, (UIntPtr)sourceBytesToCopy);
}

void Buffer::Memmove(Byte* dest, Byte* src, UIntPtr len) {
  if ((UInt64)(UIntPtr)(void*)((Int64)(UInt64)(UIntPtr)(void*)dest - (Int64)(UInt64)(UIntPtr)(void*)src) >= (UInt64)len && (UInt64)(UIntPtr)(void*)((Int64)(UInt64)(UIntPtr)(void*)src - (Int64)(UInt64)(UIntPtr)(void*)dest) >= (UInt64)len) {
    Byte* ptr = src + len;
    Byte* ptr2 = dest + len;
    if (len > 16) {
      if (len > 64) {
        if (len > 2048) {
          goto IL_011e;
        }
        UIntPtr uIntPtr = (UIntPtr)(void*)((UInt64)len >> 6);
        do {
          *(Block64*)dest = *(Block64*)src;
          dest += 64;
          src += 64;
          uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1);
        } while (uIntPtr != (UIntPtr)(void*)nullptr);
        len = (UIntPtr)((UInt64)len % 64);
        if (len <= 16) {
          *(Block16*)(ptr2 - 16) = *(Block16*)(ptr - 16);
          return;
        }
      }
      *(Block16*)dest = *(Block16*)src;
      if (len > 32) {
        *(Block16*)(dest + 16) = *(Block16*)(src + 16);
        if (len > 48) {
          *(Block16*)(dest + 32) = *(Block16*)(src + 32);
        }
      }
      *(Block16*)(ptr2 - 16) = *(Block16*)(ptr - 16);
    } else if ((len & 24) != 0) {
      *(Int64*)dest = *(Int64*)src;
      *(Int64*)(ptr2 - 8) = *(Int64*)(ptr - 8);
    } else if ((len & 4) != 0) {
      *(Int32*)dest = *(Int32*)src;
      *(Int32*)(ptr2 - 4) = *(Int32*)(ptr - 4);
    } else if (len != 0) {
      *dest = *src;
      if ((len & 2) != 0) {
        *(Int16*)(ptr2 - 2) = *(Int16*)(ptr - 2);
      }
    }



    return;
  }
  goto IL_011e;

IL_011e:
  _Memmove(dest, src, len);
}

void Buffer::Memmove(Byte& dest, Byte& src, UIntPtr len) {
  if ((UInt64)(Int64)Unsafe::ByteOffset(src, dest) >= (UInt64)len && (UInt64)(Int64)Unsafe::ByteOffset(dest, src) >= (UInt64)len) {
    Byte& source = Unsafe::Add(src, (IntPtr)(void*)len);
    Byte& source2 = Unsafe::Add(dest, (IntPtr)(void*)len);
    if (len > 16) {
      if (len > 64) {
        if (len > 2048) {
          goto IL_01db;
        }
        UIntPtr uIntPtr = (UIntPtr)(void*)((UInt64)len >> 6);
        do {
          Unsafe::As<Byte, Block64>(dest) = Unsafe::As<Byte, Block64>(src);
          dest = Unsafe::Add(dest, 64);
          src = Unsafe::Add(src, 64);
          uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1);
        } while (uIntPtr != (UIntPtr)(void*)nullptr);
        len = (UIntPtr)((UInt64)len % 64);
        if (len <= 16) {
          Unsafe::As<Byte, Block16>(Unsafe::Add(source2, -16)) = Unsafe::As<Byte, Block16>(Unsafe::Add(source, -16));
          return;
        }
      }
      Unsafe::As<Byte, Block16>(dest) = Unsafe::As<Byte, Block16>(src);
      if (len > 32) {
        Unsafe::As<Byte, Block16>(Unsafe::Add(dest, 16)) = Unsafe::As<Byte, Block16>(Unsafe::Add(src, 16));
        if (len > 48) {
          Unsafe::As<Byte, Block16>(Unsafe::Add(dest, 32)) = Unsafe::As<Byte, Block16>(Unsafe::Add(src, 32));
        }
      }
      Unsafe::As<Byte, Block16>(Unsafe::Add(source2, -16)) = Unsafe::As<Byte, Block16>(Unsafe::Add(source, -16));
    } else if ((len & 24) != 0) {
      Unsafe::As<Byte, Int64>(dest) = Unsafe::As<Byte, Int64>(src);
      Unsafe::As<Byte, Int64>(Unsafe::Add(source2, -8)) = Unsafe::As<Byte, Int64>(Unsafe::Add(source, -8));
    } else if ((len & 4) != 0) {
      Unsafe::As<Byte, Int32>(dest) = Unsafe::As<Byte, Int32>(src);
      Unsafe::As<Byte, Int32>(Unsafe::Add(source2, -4)) = Unsafe::As<Byte, Int32>(Unsafe::Add(source, -4));
    } else if (len != 0) {
      dest = src;
      if ((len & 2) != 0) {
        Unsafe::As<Byte, Int16>(Unsafe::Add(source2, -2)) = Unsafe::As<Byte, Int16>(Unsafe::Add(source, -2));
      }
    }



    return;
  }
  if (Unsafe::AreSame(dest, src)) {
    return;
  }
  goto IL_01db;

IL_01db:
  _Memmove(dest, src, len);
}

void Buffer::_Memmove(Byte* dest, Byte* src, UIntPtr len) {
  __Memmove(dest, src, len);
}

void Buffer::_Memmove(Byte& dest, Byte& src, UIntPtr len) {
  {
    Byte* dest2 = &dest;
    {
      Byte* src2 = &src;
      __Memmove(dest2, src2, len);
    }
  }
}

} // namespace System::Private::CoreLib::System::BufferNamespace
