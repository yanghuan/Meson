#include "Buffer-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/RuntimeHelpers-dep.h>
#include <System.Private.CoreLib/System/SpanHelpers-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

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
  if ((UIntPtr)(IntPtr)Unsafe::ByteOffset(source, destination) >= byteCount) {
  } else {
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
  UIntPtr num = (UIntPtr)src->get_LongLength();
}

Int32 Buffer::ByteLength(Array<> array) {
  if (array == nullptr) {
    rt::throw_exception<ArgumentNullException>("array");
  }
  if (!RuntimeHelpers::IsPrimitiveType(array->GetCorElementTypeOfElementType())) {
    rt::throw_exception<ArgumentException>(SR::get_Arg_MustBePrimArray(), "array");
  }
  UIntPtr num = (UIntPtr)((IntPtr)array->get_LongLength() * RuntimeHelpers::GetElementSize(array));
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

void Buffer::ZeroMemory(Byte* dest, UIntPtr len) {
  SpanHelpers::ClearWithoutReferences(*dest, len);
}

void Buffer::MemoryCopy(void* source, void* destination, Int64 destinationSizeInBytes, Int64 sourceBytesToCopy) {
  if (sourceBytesToCopy > destinationSizeInBytes) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::sourceBytesToCopy);
  }
  Memmove((Byte*)destination, (Byte*)source, (UIntPtr)sourceBytesToCopy);
}

void Buffer::MemoryCopy(void* source, void* destination, UInt64 destinationSizeInBytes, UInt64 sourceBytesToCopy) {
  if (sourceBytesToCopy > destinationSizeInBytes) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::sourceBytesToCopy);
  }
  Memmove((Byte*)destination, (Byte*)source, (UIntPtr)sourceBytesToCopy);
}

void Buffer::Memmove(Byte* dest, Byte* src, UIntPtr len) {
  if ((UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)dest - (IntPtr)(UIntPtr)(UIntPtr)(void*)src) >= len && (UIntPtr)((IntPtr)(UIntPtr)(UIntPtr)(void*)src - (IntPtr)(UIntPtr)(UIntPtr)(void*)dest) >= len) {
    Byte* ptr = src + len;
    Byte* ptr2 = dest + len;
    if (len > 16) {
      if (len > 64) {
        if (len > 2048) {
        }
        UIntPtr num = len >> 6;
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
}

void Buffer::Memmove(Byte& dest, Byte& src, UIntPtr len) {
  if ((UIntPtr)(IntPtr)Unsafe::ByteOffset(src, dest) >= len && (UIntPtr)(IntPtr)Unsafe::ByteOffset(dest, src) >= len) {
    Byte& source = Unsafe::Add(src, (IntPtr)len);
    Byte& source2 = Unsafe::Add(dest, (IntPtr)len);
    if (len > 16) {
      if (len > 64) {
        if (len > 2048) {
        }
        UIntPtr num = len >> 6;
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
