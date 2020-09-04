#include "SpanHelpers-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Arm/AdvSimd-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector256-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Avx2-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::SpanHelpersNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Numerics;
using namespace System::Runtime::Intrinsics;
using namespace System::Runtime::Intrinsics::Arm;
using namespace System::Runtime::Intrinsics::X86;

Int32 SpanHelpers::IndexOf(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength) {
  if (valueLength == 0) {
    return 0;
  }
  Byte value2 = value;
  Byte& second = Unsafe::Add(value, 1);
  Int32 num = valueLength - 1;
  Int32 num2 = searchSpaceLength - num;
  Int32 num3 = 0;
  while (num2 > 0) {
    Int32 num4 = IndexOf(Unsafe::Add(searchSpace, num3), value2, num2);
    if (num4 == -1) {
      break;
    }
    num2 -= num4;
    num3 += num4;
    if (num2 <= 0) {
      break;
    }
    if (SequenceEqual(Unsafe::Add(searchSpace, num3 + 1), second, (UIntPtr)num)) {
      return num3;
    }
    num2--;
    num3++;
  }
  return -1;
}

Int32 SpanHelpers::IndexOfAny(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength) {
  if (valueLength == 0) {
    return -1;
  }
  Int32 num = -1;
  for (Int32 i = 0; i < valueLength; i++) {
    Int32 num2 = IndexOf(searchSpace, Unsafe::Add(value, i), searchSpaceLength);
    if ((UInt32)num2 < (UInt32)num) {
      num = num2;
      searchSpaceLength = num2;
      if (num == 0) {
        break;
      }
    }
  }
  return num;
}

Int32 SpanHelpers::LastIndexOfAny(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength) {
  if (valueLength == 0) {
    return -1;
  }
  Int32 num = -1;
  for (Int32 i = 0; i < valueLength; i++) {
    Int32 num2 = LastIndexOf(searchSpace, Unsafe::Add(value, i), searchSpaceLength);
    if (num2 > num) {
      num = num2;
    }
  }
  return num;
}

Boolean SpanHelpers::Contains(Byte& searchSpace, Byte value, Int32 length) {
  UIntPtr uIntPtr = (UIntPtr)(void*)nullptr;
  UIntPtr uIntPtr2 = (UIntPtr)(UInt32)length;
  if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    uIntPtr2 = UnalignedCountVector(searchSpace);
  }
  while (true) {
    if ((UInt64)uIntPtr2 >= 8) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 8);
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 0)) || value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1)) || value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2)) || value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3)) || value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 4)) || value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 5)) || value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 6)) || value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 7))) {
        break;
      }
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 8);
      continue;
    }
    if ((UInt64)uIntPtr2 >= 4) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 4);
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 0)) || value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1)) || value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2)) || value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3))) {
        break;
      }
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 4);
    }
    while (uIntPtr2 != (UIntPtr)(void*)nullptr) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 1);
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr)) {
        goto end_IL_00bd;
      }
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 1);
    }
    if (Vector<>::get_IsHardwareAccelerated() && (UInt64)uIntPtr < (UInt64)(UInt32)length) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(IntPtr)(void*)((Int64)(UInt32)length - (Int64)(UInt64)uIntPtr) & (UInt64)(~(Vector<Byte>::get_Count() - 1)));
      Vector<Byte> left = Vector<Byte>(value);
      for (; (UInt64)uIntPtr2 > (UInt64)uIntPtr; uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector<Byte>::get_Count())) {
        Vector<Byte> other = Vector<>::Equals(left, LoadVector(searchSpace, (UIntPtr)uIntPtr));
        if (!Vector<Byte>::get_Zero().Equals(other)) {
          goto end_IL_00bd;
        }
      }
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
        continue;
      }
    }
    return false;
    continue;

  end_IL_00bd:
    break;
  }
  return true;
}

Int32 SpanHelpers::IndexOf(Byte& searchSpace, Byte value, Int32 length) {
  UIntPtr uIntPtr = (UIntPtr)(void*)nullptr;
  UIntPtr uIntPtr2 = (UIntPtr)(UInt32)length;
  if (Sse2::in::get_IsSupported() || AdvSimd::in::Arm64::in::get_IsSupported()) {
    if (length >= Vector128<Byte>::get_Count() * 2) {
      uIntPtr2 = UnalignedCountVector128(searchSpace);
    }
  } else if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    uIntPtr2 = UnalignedCountVector(searchSpace);
  }

  while (true) {
    if ((UInt64)uIntPtr2 >= 8) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 8);
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr)) {
        goto IL_03b0;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1))) {
        goto IL_03b3;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2))) {
        goto IL_03b9;
      }
      if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3))) {
        if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 4))) {
          if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 5))) {
            if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 6))) {
              if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 7))) {
                break;
              }
              uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 8);
              continue;
            }
            return (Int32)((Int64)(UInt64)uIntPtr + 6);
          }
          return (Int32)((Int64)(UInt64)uIntPtr + 5);
        }
        return (Int32)((Int64)(UInt64)uIntPtr + 4);
      }
      goto IL_03bf;
    }
    if ((UInt64)uIntPtr2 >= 4) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 4);
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr)) {
        goto IL_03b0;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1))) {
        goto IL_03b3;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2))) {
        goto IL_03b9;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3))) {
        goto IL_03bf;
      }
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 4);
    }
    while (uIntPtr2 != (UIntPtr)(void*)nullptr) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 1);
      if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr)) {
        uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 1);
        continue;
      }
      goto IL_03b0;
    }
    if (Avx2::in::get_IsSupported()) {
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        if ((IntPtr)(void*)((Int64)(IntPtr)(void*)((Int64)(UInt32)Unsafe::AsPointer(searchSpace) + (Int64)(UInt64)uIntPtr) & (Int64)(Vector256<Byte>::get_Count() - 1)) != (IntPtr)(Int32)0) {
          Vector128<Byte> left = Vector128<>::Create(value);
          Vector128<Byte> right = LoadVector128(searchSpace, (UIntPtr)uIntPtr);
          Int32 num = Sse2::in::MoveMask(Sse2::in::CompareEqual(left, right));
          if (num != 0) {
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)BitOperations::TrailingZeroCount(num));
          }
          uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector128<Byte>::get_Count());
        }
        uIntPtr2 = GetByteVector256SpanLength((UIntPtr)uIntPtr, length);
        if ((UInt64)uIntPtr2 > (UInt64)uIntPtr) {
          Vector256<Byte> left2 = Vector256<>::Create(value);
          do {
            Vector256<Byte> right2 = LoadVector256(searchSpace, (UIntPtr)uIntPtr);
            Int32 num2 = Avx2::in::MoveMask(Avx2::in::CompareEqual(left2, right2));
            if (num2 == 0) {
              uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector256<Byte>::get_Count());
              continue;
            }
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)BitOperations::TrailingZeroCount(num2));
          } while ((UInt64)uIntPtr2 > (UInt64)uIntPtr)
        }
        uIntPtr2 = GetByteVector128SpanLength((UIntPtr)uIntPtr, length);
        if ((UInt64)uIntPtr2 > (UInt64)uIntPtr) {
          Vector128<Byte> left3 = Vector128<>::Create(value);
          Vector128<Byte> right3 = LoadVector128(searchSpace, (UIntPtr)uIntPtr);
          Int32 num3 = Sse2::in::MoveMask(Sse2::in::CompareEqual(left3, right3));
          if (num3 != 0) {
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)BitOperations::TrailingZeroCount(num3));
          }
          uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector128<Byte>::get_Count());
        }
        if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
          continue;
        }
      }
    } else if (Sse2::in::get_IsSupported()) {
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = GetByteVector128SpanLength((UIntPtr)uIntPtr, length);
        Vector128<Byte> left4 = Vector128<>::Create(value);
        for (; (UInt64)uIntPtr2 > (UInt64)uIntPtr; uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector128<Byte>::get_Count())) {
          Vector128<Byte> right4 = LoadVector128(searchSpace, (UIntPtr)uIntPtr);
          Int32 num4 = Sse2::in::MoveMask(Sse2::in::CompareEqual(left4, right4));
          if (num4 != 0) {
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)BitOperations::TrailingZeroCount(num4));
          }
        }
        if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
          continue;
        }
      }
    } else if (AdvSimd::in::Arm64::in::get_IsSupported()) {
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = GetByteVector128SpanLength((UIntPtr)uIntPtr, length);
        Vector128<Byte> mask = Vector128<>::AsByte(Vector128<>::Create((UInt16)(Int32)4097));
        Int32 matchedLane = 0;
        Vector128<Byte> left5 = Vector128<>::Create(value);
        for (; (UInt64)uIntPtr2 > (UInt64)uIntPtr; uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector128<Byte>::get_Count())) {
          Vector128<Byte> right5 = LoadVector128(searchSpace, (UIntPtr)uIntPtr);
          Vector128<Byte> compareResult = AdvSimd::in::CompareEqual(left5, right5);
          if (TryFindFirstMatchedLane(mask, compareResult, matchedLane)) {
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)matchedLane);
          }
        }
        if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
          continue;
        }
      }
    } else if (Vector<>::get_IsHardwareAccelerated() && (UInt64)uIntPtr < (UInt64)(UInt32)length) {
      uIntPtr2 = GetByteVectorSpanLength((UIntPtr)uIntPtr, length);
      Vector<Byte> left6 = Vector<Byte>(value);
      for (; (UInt64)uIntPtr2 > (UInt64)uIntPtr; uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector<Byte>::get_Count())) {
        Vector<Byte> vector = Vector<>::Equals(left6, LoadVector(searchSpace, (UIntPtr)uIntPtr));
        if (!Vector<Byte>::get_Zero().Equals(vector)) {
          return (Int32)(UInt64)uIntPtr + LocateFirstFoundByte(vector);
        }
      }
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
        continue;
      }
    }



    return -1;

  IL_03b0:
    return (Int32)(UInt64)uIntPtr;

  IL_03b9:
    return (Int32)((Int64)(UInt64)uIntPtr + 2);

  IL_03b3:
    return (Int32)((Int64)(UInt64)uIntPtr + 1);

  IL_03bf:
    return (Int32)((Int64)(UInt64)uIntPtr + 3);
  }
  return (Int32)((Int64)(UInt64)uIntPtr + 7);
}

Int32 SpanHelpers::LastIndexOf(Byte& searchSpace, Int32 searchSpaceLength, Byte& value, Int32 valueLength) {
  if (valueLength == 0) {
    return searchSpaceLength;
  }
  Byte value2 = value;
  Byte& second = Unsafe::Add(value, 1);
  Int32 num = valueLength - 1;
  Int32 num2 = 0;
  while (true) {
    Int32 num3 = searchSpaceLength - num2 - num;
    if (num3 <= 0) {
      break;
    }
    Int32 num4 = LastIndexOf(searchSpace, value2, num3);
    if (num4 == -1) {
      break;
    }
    if (SequenceEqual(Unsafe::Add(searchSpace, num4 + 1), second, (UIntPtr)(UInt32)num)) {
      return num4;
    }
    num2 += num3 - num4;
  }
  return -1;
}

Int32 SpanHelpers::LastIndexOf(Byte& searchSpace, Byte value, Int32 length) {
  UIntPtr uIntPtr = (UIntPtr)(UInt32)length;
  UIntPtr uIntPtr2 = (UIntPtr)(UInt32)length;
  if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    uIntPtr2 = UnalignedCountVectorFromEnd(searchSpace, length);
  }
  while (true) {
    if ((UInt64)uIntPtr2 >= 8) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 8);
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 8);
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 7))) {
        break;
      }
      if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 6))) {
        if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 5))) {
          if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 4))) {
            if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3))) {
              if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2))) {
                if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1))) {
                  if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr)) {
                    continue;
                  }
                  goto IL_01ba;
                }
                goto IL_01bd;
              }
              goto IL_01c3;
            }
            goto IL_01c9;
          }
          return (Int32)((Int64)(UInt64)uIntPtr + 4);
        }
        return (Int32)((Int64)(UInt64)uIntPtr + 5);
      }
      return (Int32)((Int64)(UInt64)uIntPtr + 6);
    }
    if ((UInt64)uIntPtr2 >= 4) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 4);
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 4);
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3))) {
        goto IL_01c9;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2))) {
        goto IL_01c3;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1))) {
        goto IL_01bd;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr)) {
        goto IL_01ba;
      }
    }
    while (uIntPtr2 != (UIntPtr)(void*)nullptr) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 1);
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1);
      if (value != Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr)) {
        continue;
      }
      goto IL_01ba;
    }
    if (Vector<>::get_IsHardwareAccelerated() && uIntPtr != (UIntPtr)(void*)nullptr) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr & (UInt64)(~(Vector<Byte>::get_Count() - 1)));
      Vector<Byte> left = Vector<Byte>(value);
      while ((UInt64)uIntPtr2 > (UInt64)(Vector<Byte>::get_Count() - 1)) {
        Vector<Byte> vector = Vector<>::Equals(left, LoadVector(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr - (UInt64)Vector<Byte>::get_Count())));
        if (Vector<Byte>::get_Zero().Equals(vector)) {
          uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - (UInt64)Vector<Byte>::get_Count());
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - (UInt64)Vector<Byte>::get_Count());
          continue;
        }
        return (Int32)(UInt64)uIntPtr - Vector<Byte>::get_Count() + LocateLastFoundByte(vector);
      }
      if (uIntPtr != (UIntPtr)(void*)nullptr) {
        uIntPtr2 = uIntPtr;
        continue;
      }
    }
    return -1;

  IL_01ba:
    return (Int32)(UInt64)uIntPtr;

  IL_01c3:
    return (Int32)((Int64)(UInt64)uIntPtr + 2);

  IL_01c9:
    return (Int32)((Int64)(UInt64)uIntPtr + 3);

  IL_01bd:
    return (Int32)((Int64)(UInt64)uIntPtr + 1);
  }
  return (Int32)((Int64)(UInt64)uIntPtr + 7);
}

Int32 SpanHelpers::IndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Int32 length) {
  UIntPtr uIntPtr = (UIntPtr)(void*)nullptr;
  UIntPtr uIntPtr2 = (UIntPtr)(UInt32)length;
  if (Sse2::in::get_IsSupported() || AdvSimd::in::Arm64::in::get_IsSupported()) {
    if (length >= Vector128<Byte>::get_Count() * 2) {
      uIntPtr2 = UnalignedCountVector128(searchSpace);
    }
  } else if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    uIntPtr2 = UnalignedCountVector(searchSpace);
  }

  while (true) {
    if ((UInt64)uIntPtr2 >= 8) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 8);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
      if (value0 == num || value1 == num) {
        goto IL_047a;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1));
      if (value0 == num || value1 == num) {
        goto IL_047d;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2));
      if (value0 == num || value1 == num) {
        goto IL_0483;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3));
      if (value0 != num && value1 != num) {
        num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 4));
        if (value0 != num && value1 != num) {
          num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 5));
          if (value0 != num && value1 != num) {
            num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 6));
            if (value0 != num && value1 != num) {
              num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 7));
              if (value0 == num || value1 == num) {
                break;
              }
              uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 8);
              continue;
            }
            return (Int32)((Int64)(UInt64)uIntPtr + 6);
          }
          return (Int32)((Int64)(UInt64)uIntPtr + 5);
        }
        return (Int32)((Int64)(UInt64)uIntPtr + 4);
      }
      goto IL_0489;
    }
    if ((UInt64)uIntPtr2 >= 4) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 4);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
      if (value0 == num || value1 == num) {
        goto IL_047a;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1));
      if (value0 == num || value1 == num) {
        goto IL_047d;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2));
      if (value0 == num || value1 == num) {
        goto IL_0483;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3));
      if (value0 == num || value1 == num) {
        goto IL_0489;
      }
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 4);
    }
    while (uIntPtr2 != (UIntPtr)(void*)nullptr) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 1);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
      if (value0 != num && value1 != num) {
        uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 1);
        continue;
      }
      goto IL_047a;
    }
    if (Avx2::in::get_IsSupported()) {
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = GetByteVector256SpanLength((UIntPtr)uIntPtr, length);
        if ((UInt64)uIntPtr2 > (UInt64)uIntPtr) {
          Vector256<Byte> left = Vector256<>::Create(value0);
          Vector256<Byte> left2 = Vector256<>::Create(value1);
          do {
            Vector256<Byte> right = LoadVector256(searchSpace, (UIntPtr)uIntPtr);
            Int32 num2 = Avx2::in::MoveMask(Avx2::in::Or(Avx2::in::CompareEqual(left, right), Avx2::in::CompareEqual(left2, right)));
            if (num2 == 0) {
              uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector256<Byte>::get_Count());
              continue;
            }
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)BitOperations::TrailingZeroCount(num2));
          } while ((UInt64)uIntPtr2 > (UInt64)uIntPtr)
        }
        uIntPtr2 = GetByteVector128SpanLength((UIntPtr)uIntPtr, length);
        if ((UInt64)uIntPtr2 > (UInt64)uIntPtr) {
          Vector128<Byte> left3 = Vector128<>::Create(value0);
          Vector128<Byte> left4 = Vector128<>::Create(value1);
          Vector128<Byte> right2 = LoadVector128(searchSpace, (UIntPtr)uIntPtr);
          Int32 num3 = Sse2::in::MoveMask(Sse2::in::Or(Sse2::in::CompareEqual(left3, right2), Sse2::in::CompareEqual(left4, right2)));
          if (num3 != 0) {
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)BitOperations::TrailingZeroCount(num3));
          }
          uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector128<Byte>::get_Count());
        }
        if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
          continue;
        }
      }
    } else if (Sse2::in::get_IsSupported()) {
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = GetByteVector128SpanLength((UIntPtr)uIntPtr, length);
        Vector128<Byte> left5 = Vector128<>::Create(value0);
        Vector128<Byte> left6 = Vector128<>::Create(value1);
        for (; (UInt64)uIntPtr2 > (UInt64)uIntPtr; uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector128<Byte>::get_Count())) {
          Vector128<Byte> right3 = LoadVector128(searchSpace, (UIntPtr)uIntPtr);
          Int32 num4 = Sse2::in::MoveMask(Sse2::in::Or(Sse2::in::CompareEqual(left5, right3), Sse2::in::CompareEqual(left6, right3)));
          if (num4 != 0) {
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)BitOperations::TrailingZeroCount(num4));
          }
        }
        if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
          continue;
        }
      }
    } else if (AdvSimd::in::Arm64::in::get_IsSupported()) {
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = GetByteVector128SpanLength((UIntPtr)uIntPtr, length);
        Vector128<Byte> mask = Vector128<>::AsByte(Vector128<>::Create((UInt16)(Int32)4097));
        Int32 matchedLane = 0;
        Vector128<Byte> left7 = Vector128<>::Create(value0);
        Vector128<Byte> left8 = Vector128<>::Create(value1);
        for (; (UInt64)uIntPtr2 > (UInt64)uIntPtr; uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector128<Byte>::get_Count())) {
          Vector128<Byte> right4 = LoadVector128(searchSpace, (UIntPtr)uIntPtr);
          Vector128<Byte> compareResult = AdvSimd::in::Or(AdvSimd::in::CompareEqual(left7, right4), AdvSimd::in::CompareEqual(left8, right4));
          if (TryFindFirstMatchedLane(mask, compareResult, matchedLane)) {
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)matchedLane);
          }
        }
        if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
          continue;
        }
      }
    } else if (Vector<>::get_IsHardwareAccelerated() && (UInt64)uIntPtr < (UInt64)(UInt32)length) {
      uIntPtr2 = GetByteVectorSpanLength((UIntPtr)uIntPtr, length);
      Vector<Byte> right5 = Vector<Byte>(value0);
      Vector<Byte> right6 = Vector<Byte>(value1);
      for (; (UInt64)uIntPtr2 > (UInt64)uIntPtr; uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector<Byte>::get_Count())) {
        Vector<Byte> left9 = LoadVector(searchSpace, (UIntPtr)uIntPtr);
        Vector<Byte> vector = Vector<>::BitwiseOr(Vector<>::Equals(left9, right5), Vector<>::Equals(left9, right6));
        if (!Vector<Byte>::get_Zero().Equals(vector)) {
          return (Int32)(UInt64)uIntPtr + LocateFirstFoundByte(vector);
        }
      }
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
        continue;
      }
    }



    return -1;

  IL_047a:
    return (Int32)(UInt64)uIntPtr;

  IL_0489:
    return (Int32)((Int64)(UInt64)uIntPtr + 3);

  IL_0483:
    return (Int32)((Int64)(UInt64)uIntPtr + 2);

  IL_047d:
    return (Int32)((Int64)(UInt64)uIntPtr + 1);
  }
  return (Int32)((Int64)(UInt64)uIntPtr + 7);
}

Int32 SpanHelpers::IndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Byte value2, Int32 length) {
  UIntPtr uIntPtr = (UIntPtr)(void*)nullptr;
  UIntPtr uIntPtr2 = (UIntPtr)(UInt32)length;
  if (Sse2::in::get_IsSupported() || AdvSimd::in::Arm64::in::get_IsSupported()) {
    if (length >= Vector128<Byte>::get_Count() * 2) {
      uIntPtr2 = UnalignedCountVector128(searchSpace);
    }
  } else if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    uIntPtr2 = UnalignedCountVector(searchSpace);
  }

  while (true) {
    if ((UInt64)uIntPtr2 >= 8) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 8);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
      if (value0 == num || value1 == num || value2 == num) {
        goto IL_05ba;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1));
      if (value0 == num || value1 == num || value2 == num) {
        goto IL_05bd;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2));
      if (value0 == num || value1 == num || value2 == num) {
        goto IL_05c3;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3));
      if (value0 != num && value1 != num && value2 != num) {
        num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 4));
        if (value0 != num && value1 != num && value2 != num) {
          num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 5));
          if (value0 != num && value1 != num && value2 != num) {
            num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 6));
            if (value0 != num && value1 != num && value2 != num) {
              num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 7));
              if (value0 == num || value1 == num || value2 == num) {
                break;
              }
              uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 8);
              continue;
            }
            return (Int32)((Int64)(UInt64)uIntPtr + 6);
          }
          return (Int32)((Int64)(UInt64)uIntPtr + 5);
        }
        return (Int32)((Int64)(UInt64)uIntPtr + 4);
      }
      goto IL_05c9;
    }
    if ((UInt64)uIntPtr2 >= 4) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 4);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
      if (value0 == num || value1 == num || value2 == num) {
        goto IL_05ba;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1));
      if (value0 == num || value1 == num || value2 == num) {
        goto IL_05bd;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2));
      if (value0 == num || value1 == num || value2 == num) {
        goto IL_05c3;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3));
      if (value0 == num || value1 == num || value2 == num) {
        goto IL_05c9;
      }
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 4);
    }
    while (uIntPtr2 != (UIntPtr)(void*)nullptr) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 1);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
      if (value0 != num && value1 != num && value2 != num) {
        uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + 1);
        continue;
      }
      goto IL_05ba;
    }
    if (Avx2::in::get_IsSupported()) {
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = GetByteVector256SpanLength((UIntPtr)uIntPtr, length);
        if ((UInt64)uIntPtr2 > (UInt64)uIntPtr) {
          Vector256<Byte> left = Vector256<>::Create(value0);
          Vector256<Byte> left2 = Vector256<>::Create(value1);
          Vector256<Byte> left3 = Vector256<>::Create(value2);
          do {
            Vector256<Byte> right = LoadVector256(searchSpace, (UIntPtr)uIntPtr);
            Vector256<Byte> left4 = Avx2::in::CompareEqual(left, right);
            Vector256<Byte> right2 = Avx2::in::CompareEqual(left2, right);
            Vector256<Byte> right3 = Avx2::in::CompareEqual(left3, right);
            Int32 num2 = Avx2::in::MoveMask(Avx2::in::Or(Avx2::in::Or(left4, right2), right3));
            if (num2 == 0) {
              uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector256<Byte>::get_Count());
              continue;
            }
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)BitOperations::TrailingZeroCount(num2));
          } while ((UInt64)uIntPtr2 > (UInt64)uIntPtr)
        }
        uIntPtr2 = GetByteVector128SpanLength((UIntPtr)uIntPtr, length);
        if ((UInt64)uIntPtr2 > (UInt64)uIntPtr) {
          Vector128<Byte> left5 = Vector128<>::Create(value0);
          Vector128<Byte> left6 = Vector128<>::Create(value1);
          Vector128<Byte> left7 = Vector128<>::Create(value2);
          Vector128<Byte> right4 = LoadVector128(searchSpace, (UIntPtr)uIntPtr);
          Vector128<Byte> left8 = Sse2::in::CompareEqual(left5, right4);
          Vector128<Byte> right5 = Sse2::in::CompareEqual(left6, right4);
          Vector128<Byte> right6 = Sse2::in::CompareEqual(left7, right4);
          Int32 num3 = Sse2::in::MoveMask(Sse2::in::Or(Sse2::in::Or(left8, right5), right6));
          if (num3 != 0) {
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)BitOperations::TrailingZeroCount(num3));
          }
          uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector128<Byte>::get_Count());
        }
        if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
          continue;
        }
      }
    } else if (Sse2::in::get_IsSupported()) {
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = GetByteVector128SpanLength((UIntPtr)uIntPtr, length);
        Vector128<Byte> left9 = Vector128<>::Create(value0);
        Vector128<Byte> left10 = Vector128<>::Create(value1);
        Vector128<Byte> left11 = Vector128<>::Create(value2);
        for (; (UInt64)uIntPtr2 > (UInt64)uIntPtr; uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector128<Byte>::get_Count())) {
          Vector128<Byte> right7 = LoadVector128(searchSpace, (UIntPtr)uIntPtr);
          Vector128<Byte> left12 = Sse2::in::CompareEqual(left9, right7);
          Vector128<Byte> right8 = Sse2::in::CompareEqual(left10, right7);
          Vector128<Byte> right9 = Sse2::in::CompareEqual(left11, right7);
          Int32 num4 = Sse2::in::MoveMask(Sse2::in::Or(Sse2::in::Or(left12, right8), right9));
          if (num4 != 0) {
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)BitOperations::TrailingZeroCount(num4));
          }
        }
        if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
          continue;
        }
      }
    } else if (AdvSimd::in::Arm64::in::get_IsSupported()) {
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = GetByteVector128SpanLength((UIntPtr)uIntPtr, length);
        Vector128<Byte> mask = Vector128<>::AsByte(Vector128<>::Create((UInt16)(Int32)4097));
        Int32 matchedLane = 0;
        Vector128<Byte> left13 = Vector128<>::Create(value0);
        Vector128<Byte> left14 = Vector128<>::Create(value1);
        Vector128<Byte> left15 = Vector128<>::Create(value2);
        for (; (UInt64)uIntPtr2 > (UInt64)uIntPtr; uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector128<Byte>::get_Count())) {
          Vector128<Byte> right10 = LoadVector128(searchSpace, (UIntPtr)uIntPtr);
          Vector128<Byte> left16 = AdvSimd::in::CompareEqual(left13, right10);
          Vector128<Byte> right11 = AdvSimd::in::CompareEqual(left14, right10);
          Vector128<Byte> right12 = AdvSimd::in::CompareEqual(left15, right10);
          Vector128<Byte> compareResult = AdvSimd::in::Or(AdvSimd::in::Or(left16, right11), right12);
          if (TryFindFirstMatchedLane(mask, compareResult, matchedLane)) {
            return (Int32)((Int64)(UInt64)uIntPtr + (Int64)(UInt32)matchedLane);
          }
        }
        if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
          continue;
        }
      }
    } else if (Vector<>::get_IsHardwareAccelerated() && (UInt64)uIntPtr < (UInt64)(UInt32)length) {
      uIntPtr2 = GetByteVectorSpanLength((UIntPtr)uIntPtr, length);
      Vector<Byte> right13 = Vector<Byte>(value0);
      Vector<Byte> right14 = Vector<Byte>(value1);
      Vector<Byte> right15 = Vector<Byte>(value2);
      for (; (UInt64)uIntPtr2 > (UInt64)uIntPtr; uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr + (UInt64)Vector<Byte>::get_Count())) {
        Vector<Byte> left17 = LoadVector(searchSpace, (UIntPtr)uIntPtr);
        Vector<Byte> vector = Vector<>::BitwiseOr(Vector<>::BitwiseOr(Vector<>::Equals(left17, right13), Vector<>::Equals(left17, right14)), Vector<>::Equals(left17, right15));
        if (!Vector<Byte>::get_Zero().Equals(vector)) {
          return (Int32)(UInt64)uIntPtr + LocateFirstFoundByte(vector);
        }
      }
      if ((UInt64)uIntPtr < (UInt64)(UInt32)length) {
        uIntPtr2 = (UIntPtr)(void*)((UInt64)(UInt32)length - (UInt64)(Int64)(UInt64)uIntPtr);
        continue;
      }
    }



    return -1;

  IL_05c3:
    return (Int32)((Int64)(UInt64)uIntPtr + 2);

  IL_05bd:
    return (Int32)((Int64)(UInt64)uIntPtr + 1);

  IL_05ba:
    return (Int32)(UInt64)uIntPtr;

  IL_05c9:
    return (Int32)((Int64)(UInt64)uIntPtr + 3);
  }
  return (Int32)((Int64)(UInt64)uIntPtr + 7);
}

Int32 SpanHelpers::LastIndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Int32 length) {
  UIntPtr uIntPtr = (UIntPtr)(UInt32)length;
  UIntPtr uIntPtr2 = (UIntPtr)(UInt32)length;
  if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    uIntPtr2 = UnalignedCountVectorFromEnd(searchSpace, length);
  }
  while (true) {
    if ((UInt64)uIntPtr2 >= 8) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 8);
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 8);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 7));
      if (value0 == num || value1 == num) {
        break;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 6));
      if (value0 != num && value1 != num) {
        num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 5));
        if (value0 != num && value1 != num) {
          num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 4));
          if (value0 != num && value1 != num) {
            num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3));
            if (value0 != num && value1 != num) {
              num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2));
              if (value0 != num && value1 != num) {
                num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1));
                if (value0 != num && value1 != num) {
                  num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
                  if (value0 != num && value1 != num) {
                    continue;
                  }
                  goto IL_027c;
                }
                goto IL_027f;
              }
              goto IL_0285;
            }
            goto IL_028b;
          }
          return (Int32)((Int64)(UInt64)uIntPtr + 4);
        }
        return (Int32)((Int64)(UInt64)uIntPtr + 5);
      }
      return (Int32)((Int64)(UInt64)uIntPtr + 6);
    }
    if ((UInt64)uIntPtr2 >= 4) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 4);
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 4);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3));
      if (value0 == num || value1 == num) {
        goto IL_028b;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2));
      if (value0 == num || value1 == num) {
        goto IL_0285;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1));
      if (value0 == num || value1 == num) {
        goto IL_027f;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
      if (value0 == num || value1 == num) {
        goto IL_027c;
      }
    }
    while (uIntPtr2 != (UIntPtr)(void*)nullptr) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 1);
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
      if (value0 != num && value1 != num) {
        continue;
      }
      goto IL_027c;
    }
    if (Vector<>::get_IsHardwareAccelerated() && uIntPtr != (UIntPtr)(void*)nullptr) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr & (UInt64)(~(Vector<Byte>::get_Count() - 1)));
      Vector<Byte> right = Vector<Byte>(value0);
      Vector<Byte> right2 = Vector<Byte>(value1);
      while ((UInt64)uIntPtr2 > (UInt64)(Vector<Byte>::get_Count() - 1)) {
        Vector<Byte> left = LoadVector(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr - (UInt64)Vector<Byte>::get_Count()));
        Vector<Byte> vector = Vector<>::BitwiseOr(Vector<>::Equals(left, right), Vector<>::Equals(left, right2));
        if (Vector<Byte>::get_Zero().Equals(vector)) {
          uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - (UInt64)Vector<Byte>::get_Count());
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - (UInt64)Vector<Byte>::get_Count());
          continue;
        }
        return (Int32)(UInt64)uIntPtr - Vector<Byte>::get_Count() + LocateLastFoundByte(vector);
      }
      if (uIntPtr != (UIntPtr)(void*)nullptr) {
        uIntPtr2 = uIntPtr;
        continue;
      }
    }
    return -1;

  IL_027c:
    return (Int32)(UInt64)uIntPtr;

  IL_028b:
    return (Int32)((Int64)(UInt64)uIntPtr + 3);

  IL_027f:
    return (Int32)((Int64)(UInt64)uIntPtr + 1);

  IL_0285:
    return (Int32)((Int64)(UInt64)uIntPtr + 2);
  }
  return (Int32)((Int64)(UInt64)uIntPtr + 7);
}

Int32 SpanHelpers::LastIndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Byte value2, Int32 length) {
  UIntPtr uIntPtr = (UIntPtr)(UInt32)length;
  UIntPtr uIntPtr2 = (UIntPtr)(UInt32)length;
  if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    uIntPtr2 = UnalignedCountVectorFromEnd(searchSpace, length);
  }
  while (true) {
    if ((UInt64)uIntPtr2 >= 8) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 8);
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 8);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 7));
      if (value0 == num || value1 == num || value2 == num) {
        break;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 6));
      if (value0 != num && value1 != num && value2 != num) {
        num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 5));
        if (value0 != num && value1 != num && value2 != num) {
          num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 4));
          if (value0 != num && value1 != num && value2 != num) {
            num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3));
            if (value0 != num && value1 != num && value2 != num) {
              num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2));
              if (value0 != num && value1 != num && value2 != num) {
                num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1));
                if (value0 != num && value1 != num && value2 != num) {
                  num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
                  if (value0 != num && value1 != num && value2 != num) {
                    continue;
                  }
                  goto IL_0310;
                }
                goto IL_0313;
              }
              goto IL_0319;
            }
            goto IL_031f;
          }
          return (Int32)((Int64)(UInt64)uIntPtr + 4);
        }
        return (Int32)((Int64)(UInt64)uIntPtr + 5);
      }
      return (Int32)((Int64)(UInt64)uIntPtr + 6);
    }
    if ((UInt64)uIntPtr2 >= 4) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 4);
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 4);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 3));
      if (value0 == num || value1 == num || value2 == num) {
        goto IL_031f;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 2));
      if (value0 == num || value1 == num || value2 == num) {
        goto IL_0319;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr + 1));
      if (value0 == num || value1 == num || value2 == num) {
        goto IL_0313;
      }
      num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
      if (value0 == num || value1 == num || value2 == num) {
        goto IL_0310;
      }
    }
    while (uIntPtr2 != (UIntPtr)(void*)nullptr) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - 1);
      uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - 1);
      UInt32 num = Unsafe::AddByteOffset(searchSpace, (UIntPtr)uIntPtr);
      if (value0 != num && value1 != num && value2 != num) {
        continue;
      }
      goto IL_0310;
    }
    if (Vector<>::get_IsHardwareAccelerated() && uIntPtr != (UIntPtr)(void*)nullptr) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr & (UInt64)(~(Vector<Byte>::get_Count() - 1)));
      Vector<Byte> right = Vector<Byte>(value0);
      Vector<Byte> right2 = Vector<Byte>(value1);
      Vector<Byte> right3 = Vector<Byte>(value2);
      while ((UInt64)uIntPtr2 > (UInt64)(Vector<Byte>::get_Count() - 1)) {
        Vector<Byte> left = LoadVector(searchSpace, (UIntPtr)((UInt64)(Int64)(UInt64)uIntPtr - (UInt64)Vector<Byte>::get_Count()));
        Vector<Byte> vector = Vector<>::BitwiseOr(Vector<>::BitwiseOr(Vector<>::Equals(left, right), Vector<>::Equals(left, right2)), Vector<>::Equals(left, right3));
        if (Vector<Byte>::get_Zero().Equals(vector)) {
          uIntPtr = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - (UInt64)Vector<Byte>::get_Count());
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 - (UInt64)Vector<Byte>::get_Count());
          continue;
        }
        return (Int32)(UInt64)uIntPtr - Vector<Byte>::get_Count() + LocateLastFoundByte(vector);
      }
      if (uIntPtr != (UIntPtr)(void*)nullptr) {
        uIntPtr2 = uIntPtr;
        continue;
      }
    }
    return -1;

  IL_0310:
    return (Int32)(UInt64)uIntPtr;

  IL_031f:
    return (Int32)((Int64)(UInt64)uIntPtr + 3);

  IL_0319:
    return (Int32)((Int64)(UInt64)uIntPtr + 2);

  IL_0313:
    return (Int32)((Int64)(UInt64)uIntPtr + 1);
  }
  return (Int32)((Int64)(UInt64)uIntPtr + 7);
}

Boolean SpanHelpers::SequenceEqual(Byte& first, Byte& second, UIntPtr length) {
  if ((UInt64)length < (UInt64)sizeof(UIntPtr)) {
    if (length < 4) {
      UInt32 num = 0u;
      UIntPtr uIntPtr = length & 2;
      if (uIntPtr != (UIntPtr)(void*)nullptr) {
        num = LoadUShort(first);
        num -= LoadUShort(second);
      }
      if ((length & 1) != 0) {
        num |= (UInt32)(Unsafe::AddByteOffset(first, (UIntPtr)uIntPtr) - Unsafe::AddByteOffset(second, (UIntPtr)uIntPtr));
      }
      return num == 0;
    }
    UIntPtr offset = length - 4;
    UInt32 num2 = LoadUInt(first) - LoadUInt(second);
    num2 |= LoadUInt(first, (UIntPtr)offset) - LoadUInt(second, (UIntPtr)offset);
    return num2 == 0;
  }
  if (Unsafe::AreSame(first, second)) {
    goto IL_0087;
  }
  UIntPtr uIntPtr3;
  UIntPtr uIntPtr5;
  UIntPtr uIntPtr7;
  Vector256<Byte> value;
  Vector128<Byte> value2;
  if (Sse2::in::get_IsSupported()) {
    if (Avx2::in::get_IsSupported() && (UInt64)length >= (UInt64)Vector256<Byte>::get_Count()) {
      UIntPtr uIntPtr2 = (UIntPtr)(void*)nullptr;
      uIntPtr3 = (UIntPtr)(void*)((UInt64)length - (UInt64)Vector256<Byte>::get_Count());
      if (uIntPtr3 == (UIntPtr)(void*)nullptr) {
        goto IL_00ea;
      }
      while (true) {
        value = Avx2::in::CompareEqual(LoadVector256(first, (UIntPtr)uIntPtr2), LoadVector256(second, (UIntPtr)uIntPtr2));
        if (Avx2::in::MoveMask(value) != -1) {
          break;
        }
        uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)Vector256<Byte>::get_Count());
        if ((UInt64)uIntPtr3 > (UInt64)uIntPtr2) {
          continue;
        }
        goto IL_00ea;
      }
    } else {
      if (length < 16) {
        goto IL_01fc;
      }
      UIntPtr uIntPtr4 = (UIntPtr)(void*)nullptr;
      uIntPtr5 = length - 16;
      if (uIntPtr5 == (UIntPtr)(void*)nullptr) {
        goto IL_0161;
      }
      while (true) {
        value2 = Sse2::in::CompareEqual(LoadVector128(first, (UIntPtr)uIntPtr4), LoadVector128(second, (UIntPtr)uIntPtr4));
        if (Sse2::in::MoveMask(value2) != 65535) {
          break;
        }
        uIntPtr4 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr4 + 16);
        if ((UInt64)uIntPtr5 > (UInt64)uIntPtr4) {
          continue;
        }
        goto IL_0161;
      }
    }
  } else {
    if (!Vector<>::get_IsHardwareAccelerated() || (UInt64)length < (UInt64)Vector<Byte>::get_Count()) {
      goto IL_01fc;
    }
    UIntPtr uIntPtr6 = (UIntPtr)(void*)nullptr;
    uIntPtr7 = (UIntPtr)(void*)((UInt64)length - (UInt64)Vector<Byte>::get_Count());
    if (uIntPtr7 == (UIntPtr)(void*)nullptr) {
      goto IL_01dd;
    }
    while (!(LoadVector(first, (UIntPtr)uIntPtr6) != LoadVector(second, (UIntPtr)uIntPtr6))) {
      uIntPtr6 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr6 + (UInt64)Vector<Byte>::get_Count());
      if ((UInt64)uIntPtr7 > (UInt64)uIntPtr6) {
        continue;
      }
      goto IL_01dd;
    }
  }
  goto IL_0290;

IL_0290:
  return false;

IL_01dd:
  if (LoadVector(first, (UIntPtr)uIntPtr7) == LoadVector(second, (UIntPtr)uIntPtr7)) {
    goto IL_0087;
  }
  goto IL_0290;

IL_0278:
  UIntPtr uIntPtr8;
  return LoadNUInt(first, (UIntPtr)uIntPtr8) == LoadNUInt(second, (UIntPtr)uIntPtr8);

IL_01fc:
  if (Sse2::in::get_IsSupported()) {
    UIntPtr offset2 = (UIntPtr)(void*)((UInt64)length - (UInt64)sizeof(UIntPtr));
    UIntPtr uIntPtr9 = LoadNUInt(first) - LoadNUInt(second);
    uIntPtr9 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr9 | (UInt64)(LoadNUInt(first, (UIntPtr)offset2) - LoadNUInt(second, (UIntPtr)offset2)));
    return uIntPtr9 == (UIntPtr)(void*)nullptr;
  }
  UIntPtr uIntPtr10 = (UIntPtr)(void*)nullptr;
  uIntPtr8 = (UIntPtr)(void*)((UInt64)length - (UInt64)sizeof(UIntPtr));
  if (uIntPtr8 == (UIntPtr)(void*)nullptr) {
    goto IL_0278;
  }
  while (LoadNUInt(first, (UIntPtr)uIntPtr10) == LoadNUInt(second, (UIntPtr)uIntPtr10)) {
    uIntPtr10 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr10 + (UInt64)sizeof(UIntPtr));
    if ((UInt64)uIntPtr8 > (UInt64)uIntPtr10) {
      continue;
    }
    goto IL_0278;
  }
  goto IL_0290;

IL_00ea:
  value = Avx2::in::CompareEqual(LoadVector256(first, (UIntPtr)uIntPtr3), LoadVector256(second, (UIntPtr)uIntPtr3));
  if (Avx2::in::MoveMask(value) == -1) {
    goto IL_0087;
  }
  goto IL_0290;

IL_0087:
  return true;

IL_0161:
  value2 = Sse2::in::CompareEqual(LoadVector128(first, (UIntPtr)uIntPtr5), LoadVector128(second, (UIntPtr)uIntPtr5));
  if (Sse2::in::MoveMask(value2) == 65535) {
    goto IL_0087;
  }
  goto IL_0290;
}

Int32 SpanHelpers::LocateFirstFoundByte(Vector<Byte> match) {
  Vector<UInt64> vector = Vector<>::AsVectorUInt64(match);
  UInt64 num = 0;
  Int32 i;
  for (i = 0; i < Vector<UInt64>::get_Count(); i++) {
    num = vector[i];
    if (num != 0) {
      break;
    }
  }
  return i * 8 + LocateFirstFoundByte(num);
}

Int32 SpanHelpers::SequenceCompareTo(Byte& first, Int32 firstLength, Byte& second, Int32 secondLength) {
  UIntPtr uIntPtr;
  UInt32 num3;
  UIntPtr uIntPtr3;
  UIntPtr uIntPtr2;
  if (!Unsafe::AreSame(first, second)) {
    uIntPtr = (UIntPtr)(UInt32)(((UInt32)firstLength < (UInt32)secondLength) ? firstLength : secondLength);
    uIntPtr2 = (UIntPtr)(void*)nullptr;
    uIntPtr3 = uIntPtr;
    if (!Avx2::in::get_IsSupported()) {
      if (Sse2::in::get_IsSupported()) {
        if ((UInt64)uIntPtr3 >= (UInt64)Vector128<Byte>::get_Count()) {
          uIntPtr3 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr3 - (UInt64)Vector128<Byte>::get_Count());
          while (true) {
            UInt32 num;
            if ((UInt64)uIntPtr3 > (UInt64)uIntPtr2) {
              num = (UInt32)Sse2::in::MoveMask(Sse2::in::CompareEqual(LoadVector128(first, (UIntPtr)uIntPtr2), LoadVector128(second, (UIntPtr)uIntPtr2)));
              if (num == 65535) {
                uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)Vector128<Byte>::get_Count());
                continue;
              }
            } else {
              uIntPtr2 = uIntPtr3;
              num = (UInt32)Sse2::in::MoveMask(Sse2::in::CompareEqual(LoadVector128(first, (UIntPtr)uIntPtr2), LoadVector128(second, (UIntPtr)uIntPtr2)));
              if (num == 65535) {
                break;
              }
            }
            UInt32 value = ~num;
            uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)(UInt32)BitOperations::TrailingZeroCount(value));
            return Unsafe::AddByteOffset(first, (UIntPtr)uIntPtr2).CompareTo(Unsafe::AddByteOffset(second, (UIntPtr)uIntPtr2));
          }
          goto IL_0277;
        }
      } else if (Vector<>::get_IsHardwareAccelerated() && (UInt64)uIntPtr3 > (UInt64)Vector<Byte>::get_Count()) {
        for (uIntPtr3 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr3 - (UInt64)Vector<Byte>::get_Count()); (UInt64)uIntPtr3 > (UInt64)uIntPtr2 && !(LoadVector(first, (UIntPtr)uIntPtr2) != LoadVector(second, (UIntPtr)uIntPtr2)); uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)Vector<Byte>::get_Count())) {
        }
        goto IL_0273;
      }

      goto IL_021b;
    }
    if ((UInt64)uIntPtr3 >= (UInt64)Vector256<Byte>::get_Count()) {
      uIntPtr3 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr3 - (UInt64)Vector256<Byte>::get_Count());
      while (true) {
        UInt32 num2;
        if ((UInt64)uIntPtr3 > (UInt64)uIntPtr2) {
          num2 = (UInt32)Avx2::in::MoveMask(Avx2::in::CompareEqual(LoadVector256(first, (UIntPtr)uIntPtr2), LoadVector256(second, (UIntPtr)uIntPtr2)));
          if (num2 == UInt32::MaxValue) {
            uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)Vector256<Byte>::get_Count());
            continue;
          }
        } else {
          uIntPtr2 = uIntPtr3;
          num2 = (UInt32)Avx2::in::MoveMask(Avx2::in::CompareEqual(LoadVector256(first, (UIntPtr)uIntPtr2), LoadVector256(second, (UIntPtr)uIntPtr2)));
          if (num2 == UInt32::MaxValue) {
            break;
          }
        }
        UInt32 value2 = ~num2;
        uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)(UInt32)BitOperations::TrailingZeroCount(value2));
        return Unsafe::AddByteOffset(first, (UIntPtr)uIntPtr2).CompareTo(Unsafe::AddByteOffset(second, (UIntPtr)uIntPtr2));
      }
    } else {
      if ((UInt64)uIntPtr3 < (UInt64)Vector128<Byte>::get_Count()) {
        goto IL_021b;
      }
      uIntPtr3 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr3 - (UInt64)Vector128<Byte>::get_Count());
      if ((UInt64)uIntPtr3 > (UInt64)uIntPtr2) {
        num3 = (UInt32)Sse2::in::MoveMask(Sse2::in::CompareEqual(LoadVector128(first, (UIntPtr)uIntPtr2), LoadVector128(second, (UIntPtr)uIntPtr2)));
        if (num3 != 65535) {
          goto IL_0111;
        }
      }
      uIntPtr2 = uIntPtr3;
      num3 = (UInt32)Sse2::in::MoveMask(Sse2::in::CompareEqual(LoadVector128(first, (UIntPtr)uIntPtr2), LoadVector128(second, (UIntPtr)uIntPtr2)));
      if (num3 != 65535) {
        goto IL_0111;
      }
    }
  }
  goto IL_0277;

IL_021b:
  if ((UInt64)uIntPtr3 > (UInt64)sizeof(UIntPtr)) {
    for (uIntPtr3 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr3 - (UInt64)sizeof(UIntPtr)); (UInt64)uIntPtr3 > (UInt64)uIntPtr2 && LoadNUInt(first, (UIntPtr)uIntPtr2) == LoadNUInt(second, (UIntPtr)uIntPtr2); uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)sizeof(UIntPtr))) {
    }
  }
  goto IL_0273;

IL_0111:
  UInt32 value3 = ~num3;
  uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)(UInt32)BitOperations::TrailingZeroCount(value3));
  return Unsafe::AddByteOffset(first, (UIntPtr)uIntPtr2).CompareTo(Unsafe::AddByteOffset(second, (UIntPtr)uIntPtr2));

IL_0273:
  for (; (UInt64)uIntPtr > (UInt64)uIntPtr2; uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + 1)) {
    Int32 num4 = Unsafe::AddByteOffset(first, (UIntPtr)uIntPtr2).CompareTo(Unsafe::AddByteOffset(second, (UIntPtr)uIntPtr2));
    if (num4 != 0) {
      return num4;
    }
  }
  goto IL_0277;

IL_0277:
  return firstLength - secondLength;
}

Int32 SpanHelpers::LocateLastFoundByte(Vector<Byte> match) {
  Vector<UInt64> vector = Vector<>::AsVectorUInt64(match);
  UInt64 num = 0;
  Int32 num2;
  for (num2 = Vector<UInt64>::get_Count() - 1; num2 >= 0; num2--) {
    num = vector[num2];
    if (num != 0) {
      break;
    }
  }
  return num2 * 8 + LocateLastFoundByte(num);
}

Int32 SpanHelpers::LocateFirstFoundByte(UInt64 match) {
  return BitOperations::TrailingZeroCount(match) >> 3;
}

Int32 SpanHelpers::LocateLastFoundByte(UInt64 match) {
  return BitOperations::Log2(match) >> 3;
}

UInt16 SpanHelpers::LoadUShort(Byte& start) {
  return Unsafe::ReadUnaligned<UInt16>(start);
}

UInt32 SpanHelpers::LoadUInt(Byte& start) {
  return Unsafe::ReadUnaligned<UInt32>(start);
}

UInt32 SpanHelpers::LoadUInt(Byte& start, UIntPtr offset) {
  return Unsafe::ReadUnaligned<UInt32>(Unsafe::AddByteOffset(start, offset));
}

UIntPtr SpanHelpers::LoadNUInt(Byte& start) {
  return Unsafe::ReadUnaligned<UIntPtr>(start);
}

UIntPtr SpanHelpers::LoadNUInt(Byte& start, UIntPtr offset) {
  return Unsafe::ReadUnaligned<UIntPtr>(Unsafe::AddByteOffset(start, offset));
}

Vector<Byte> SpanHelpers::LoadVector(Byte& start, UIntPtr offset) {
  return Unsafe::ReadUnaligned<Vector<Byte>>(Unsafe::AddByteOffset(start, offset));
}

Vector128<Byte> SpanHelpers::LoadVector128(Byte& start, UIntPtr offset) {
  return Unsafe::ReadUnaligned<Vector128<Byte>>(Unsafe::AddByteOffset(start, offset));
}

Vector256<Byte> SpanHelpers::LoadVector256(Byte& start, UIntPtr offset) {
  return Unsafe::ReadUnaligned<Vector256<Byte>>(Unsafe::AddByteOffset(start, offset));
}

UIntPtr SpanHelpers::GetByteVectorSpanLength(UIntPtr offset, Int32 length) {
  return (UInt32)((length - (Int32)offset) & ~(Vector<Byte>::get_Count() - 1));
}

UIntPtr SpanHelpers::GetByteVector128SpanLength(UIntPtr offset, Int32 length) {
  return (UInt32)((length - (Int32)offset) & ~(Vector128<Byte>::get_Count() - 1));
}

UIntPtr SpanHelpers::GetByteVector256SpanLength(UIntPtr offset, Int32 length) {
  return (UInt32)((length - (Int32)offset) & ~(Vector256<Byte>::get_Count() - 1));
}

UIntPtr SpanHelpers::UnalignedCountVector(Byte& searchSpace) {
  IntPtr intPtr = (IntPtr)(void*)((Int64)(IntPtr)Unsafe::AsPointer(searchSpace) & (Int64)(Vector<Byte>::get_Count() - 1));
  return (UIntPtr)((UInt64)(Int64)(IntPtr)(void*)((Int64)Vector<Byte>::get_Count() - (Int64)intPtr) & (UInt64)(Vector<Byte>::get_Count() - 1));
}

UIntPtr SpanHelpers::UnalignedCountVector128(Byte& searchSpace) {
  IntPtr intPtr = (IntPtr)(void*)((Int64)(IntPtr)Unsafe::AsPointer(searchSpace) & (Int64)(Vector128<Byte>::get_Count() - 1));
  return (UInt32)((UInt64)(Int64)(IntPtr)(void*)((Int64)Vector128<Byte>::get_Count() - (Int64)intPtr) & (UInt64)(Vector128<Byte>::get_Count() - 1));
}

UIntPtr SpanHelpers::UnalignedCountVectorFromEnd(Byte& searchSpace, Int32 length) {
  IntPtr intPtr = (IntPtr)(void*)((Int64)(IntPtr)Unsafe::AsPointer(searchSpace) & (Int64)(Vector<Byte>::get_Count() - 1));
  return (UInt32)((UInt64)(Int64)(IntPtr)(void*)((Int64)(length & (Vector<Byte>::get_Count() - 1)) + (Int64)intPtr) & (UInt64)(Vector<Byte>::get_Count() - 1));
}

Boolean SpanHelpers::TryFindFirstMatchedLane(Vector128<Byte> mask, Vector128<Byte> compareResult, Int32& matchedLane) {
  Vector128<Byte> vector = AdvSimd::in::And(compareResult, mask);
  Vector128<Byte> vector2 = AdvSimd::in::Arm64::in::AddPairwise(vector, vector);
  UInt64 num = Vector128<>::ToScalar(Vector128<>::AsUInt64(vector2));
  if (num == 0) {
    return false;
  }
  matchedLane = BitOperations::TrailingZeroCount(num) >> 2;
  return true;
}

Int32 SpanHelpers::IndexOf(Char& searchSpace, Int32 searchSpaceLength, Char& value, Int32 valueLength) {
  if (valueLength == 0) {
    return 0;
  }
  Char value2 = value;
  Char& source = Unsafe::Add(value, 1);
  Int32 num = valueLength - 1;
  Int32 num2 = searchSpaceLength - num;
  Int32 num3 = 0;
  while (num2 > 0) {
    Int32 num4 = IndexOf(Unsafe::Add(searchSpace, num3), value2, num2);
    if (num4 == -1) {
      break;
    }
    num2 -= num4;
    num3 += num4;
    if (num2 <= 0) {
      break;
    }
    if (SequenceEqual(Unsafe::As<Char, Byte>(Unsafe::Add(searchSpace, num3 + 1)), Unsafe::As<Char, Byte>(source), (UIntPtr)((UInt64)(UInt32)num * 2))) {
      return num3;
    }
    num2--;
    num3++;
  }
  return -1;
}

Int32 SpanHelpers::SequenceCompareTo(Char& first, Int32 firstLength, Char& second, Int32 secondLength) {
  Int32 result = firstLength - secondLength;
  if (!Unsafe::AreSame(first, second)) {
    UIntPtr uIntPtr = (UIntPtr)(UInt32)(((UInt32)firstLength < (UInt32)secondLength) ? firstLength : secondLength);
    UIntPtr uIntPtr2 = (UIntPtr)(void*)nullptr;
    if ((UInt64)uIntPtr >= (UInt64)(sizeof(UIntPtr) / 2)) {
      if (Vector<>::get_IsHardwareAccelerated() && (UInt64)uIntPtr >= (UInt64)Vector<UInt16>::get_Count()) {
        UIntPtr uIntPtr3 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr - (UInt64)Vector<UInt16>::get_Count());
        while (!(Unsafe::ReadUnaligned<Vector<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(first, (IntPtr)(void*)(UInt64)uIntPtr2))) != Unsafe::ReadUnaligned<Vector<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(second, (IntPtr)(void*)(UInt64)uIntPtr2))))) {
          uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)Vector<UInt16>::get_Count());
          if ((UInt64)uIntPtr3 < (UInt64)uIntPtr2) {
            break;
          }
        }
      }
      for (; (UInt64)uIntPtr >= (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr2 + (Int64)(sizeof(UIntPtr) / 2)) && Unsafe::ReadUnaligned<UIntPtr>(Unsafe::As<Char, Byte>(Unsafe::Add(first, (IntPtr)(void*)(UInt64)uIntPtr2))) == Unsafe::ReadUnaligned<UIntPtr>(Unsafe::As<Char, Byte>(Unsafe::Add(second, (IntPtr)(void*)(UInt64)uIntPtr2))); uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + (UInt64)(sizeof(UIntPtr) / 2))) {
      }
    }
    if ((UInt64)uIntPtr >= (UInt64)(UIntPtr)(void*)((Int64)(UInt64)uIntPtr2 + 2) && Unsafe::ReadUnaligned<Int32>(Unsafe::As<Char, Byte>(Unsafe::Add(first, (IntPtr)(void*)(UInt64)uIntPtr2))) == Unsafe::ReadUnaligned<Int32>(Unsafe::As<Char, Byte>(Unsafe::Add(second, (IntPtr)(void*)(UInt64)uIntPtr2)))) {
      uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + 2);
    }
    for (; (UInt64)uIntPtr2 < (UInt64)uIntPtr; uIntPtr2 = (UIntPtr)(void*)((UInt64)(Int64)(UInt64)uIntPtr2 + 1)) {
      Int32 num = Unsafe::Add(first, (IntPtr)(void*)(UInt64)uIntPtr2).CompareTo(Unsafe::Add(second, (IntPtr)(void*)(UInt64)uIntPtr2));
      if (num != 0) {
        return num;
      }
    }
  }
  return result;
}

Boolean SpanHelpers::Contains(Char& searchSpace, Char value, Int32 length) {
  {
    Char* ptr = &searchSpace;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2 + length;
    if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
      Int32 num = ((Int32)ptr2 & (Unsafe::SizeOf<Vector<UInt16>>() - 1)) / 2;
      length = ((Vector<UInt16>::get_Count() - num) & (Vector<UInt16>::get_Count() - 1));
    }
    while (true) {
      if (length >= 4) {
        length -= 4;
        if (value == *ptr2 || value == ptr2[1] || value == ptr2[2] || value == ptr2[3]) {
          break;
        }
        ptr2 += 4;
        continue;
      }
      while (length > 0) {
        length--;
        if (value == *ptr2) {
          goto end_IL_0079;
        }
        ptr2++;
      }
      if (Vector<>::get_IsHardwareAccelerated() && ptr2 < ptr3) {
        length = (Int32)((ptr3 - ptr2) & ~(Vector<UInt16>::get_Count() - 1));
        Vector<UInt16> left = Vector<UInt16>(value);
        while (length > 0) {
          Vector<UInt16> other = Vector<>::Equals(left, Unsafe::Read<Vector<UInt16>>(ptr2));
          if (!Vector<UInt16>::get_Zero().Equals(other)) {
            goto end_IL_0079;
          }
          ptr2 += Vector<UInt16>::get_Count();
          length -= Vector<UInt16>::get_Count();
        }
        if (ptr2 < ptr3) {
          length = (Int32)(ptr3 - ptr2);
          continue;
        }
      }
      return false;
      continue;

    end_IL_0079:
      break;
    }
    return true;
  }
}

Int32 SpanHelpers::IndexOf(Char& searchSpace, Char value, Int32 length) {
  IntPtr intPtr = (IntPtr)(Int32)0;
  IntPtr intPtr2 = (IntPtr)length;
  if (((Int32)Unsafe::AsPointer(searchSpace) & 1) == 0) {
    if (Sse2::in::get_IsSupported() || AdvSimd::in::Arm64::in::get_IsSupported()) {
      if (length >= Vector128<UInt16>::get_Count() * 2) {
        intPtr2 = UnalignedCountVector128(searchSpace);
      }
    } else if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
      intPtr2 = UnalignedCountVector(searchSpace);
    }

  }
  while (true) {
    if ((Int64)intPtr2 >= 4) {
      Char& reference = Unsafe::Add(searchSpace, intPtr);
      if (value == reference) {
        break;
      }
      if (value != Unsafe::Add(reference, 1)) {
        if (value != Unsafe::Add(reference, 2)) {
          if (value != Unsafe::Add(reference, 3)) {
            intPtr = (IntPtr)(void*)((Int64)intPtr + 4);
            intPtr2 = (IntPtr)(void*)((Int64)intPtr2 - 4);
            continue;
          }
          return (Int32)((Int64)intPtr + 3);
        }
        return (Int32)((Int64)intPtr + 2);
      }
      return (Int32)((Int64)intPtr + 1);
    }
    while ((Int64)intPtr2 > 0) {
      if (value == Unsafe::Add(searchSpace, intPtr)) {
        goto end_IL_0090;
      }
      intPtr = (IntPtr)(void*)((Int64)intPtr + 1);
      intPtr2 = (IntPtr)(void*)((Int64)intPtr2 - 1);
    }
    if (Avx2::in::get_IsSupported()) {
      if ((Int64)intPtr < (Int64)length) {
        if ((IntPtr)(void*)((Int64)(IntPtr)Unsafe::AsPointer(Unsafe::Add(searchSpace, intPtr)) & (Int64)(Vector256<Byte>::get_Count() - 1)) != (IntPtr)(Int32)0) {
          Vector128<UInt16> left = Vector128<>::Create(value);
          Vector128<UInt16> right = LoadVector128(searchSpace, (IntPtr)intPtr);
          Int32 num = Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::CompareEqual(left, right)));
          if (num != 0) {
            return (Int32)((Int64)intPtr + (UInt32)BitOperations::TrailingZeroCount(num) / 2u);
          }
          intPtr = (IntPtr)(void*)((Int64)intPtr + (Int64)Vector128<UInt16>::get_Count());
        }
        intPtr2 = GetCharVector256SpanLength((IntPtr)intPtr, (IntPtr)length);
        if ((Int64)intPtr2 > 0) {
          Vector256<UInt16> left2 = Vector256<>::Create(value);
          do {
            Vector256<UInt16> right2 = LoadVector256(searchSpace, (IntPtr)intPtr);
            Int32 num2 = Avx2::in::MoveMask(Vector256<>::AsByte(Avx2::in::CompareEqual(left2, right2)));
            if (num2 == 0) {
              intPtr = (IntPtr)(void*)((Int64)intPtr + (Int64)Vector256<UInt16>::get_Count());
              intPtr2 = (IntPtr)(void*)((Int64)intPtr2 - (Int64)Vector256<UInt16>::get_Count());
              continue;
            }
            return (Int32)((Int64)intPtr + (UInt32)BitOperations::TrailingZeroCount(num2) / 2u);
          } while ((Int64)intPtr2 > 0)
        }
        intPtr2 = GetCharVector128SpanLength((IntPtr)intPtr, (IntPtr)length);
        if ((Int64)intPtr2 > 0) {
          Vector128<UInt16> left3 = Vector128<>::Create(value);
          Vector128<UInt16> right3 = LoadVector128(searchSpace, (IntPtr)intPtr);
          Int32 num3 = Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::CompareEqual(left3, right3)));
          if (num3 != 0) {
            return (Int32)((Int64)intPtr + (UInt32)BitOperations::TrailingZeroCount(num3) / 2u);
          }
          intPtr = (IntPtr)(void*)((Int64)intPtr + (Int64)Vector128<UInt16>::get_Count());
        }
        if ((Int64)intPtr < (Int64)length) {
          intPtr2 = (IntPtr)(void*)((Int64)length - (Int64)intPtr);
          continue;
        }
      }
    } else if (Sse2::in::get_IsSupported()) {
      if ((Int64)intPtr < (Int64)length) {
        intPtr2 = GetCharVector128SpanLength((IntPtr)intPtr, (IntPtr)length);
        if ((Int64)intPtr2 > 0) {
          Vector128<UInt16> left4 = Vector128<>::Create(value);
          do {
            Vector128<UInt16> right4 = LoadVector128(searchSpace, (IntPtr)intPtr);
            Int32 num4 = Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::CompareEqual(left4, right4)));
            if (num4 == 0) {
              intPtr = (IntPtr)(void*)((Int64)intPtr + (Int64)Vector128<UInt16>::get_Count());
              intPtr2 = (IntPtr)(void*)((Int64)intPtr2 - (Int64)Vector128<UInt16>::get_Count());
              continue;
            }
            return (Int32)((Int64)intPtr + (UInt32)BitOperations::TrailingZeroCount(num4) / 2u);
          } while ((Int64)intPtr2 > 0)
        }
        if ((Int64)intPtr < (Int64)length) {
          intPtr2 = (IntPtr)(void*)((Int64)length - (Int64)intPtr);
          continue;
        }
      }
    } else if (AdvSimd::in::Arm64::in::get_IsSupported()) {
      if ((Int64)intPtr < (Int64)length) {
        intPtr2 = GetCharVector128SpanLength((IntPtr)intPtr, (IntPtr)length);
        if ((Int64)intPtr2 > 0) {
          Vector128<UInt16> left5 = Vector128<>::Create(value);
          Int32 matchedLane = 0;
          do {
            Vector128<UInt16> right5 = LoadVector128(searchSpace, (IntPtr)intPtr);
            Vector128<UInt16> compareResult = AdvSimd::in::CompareEqual(left5, right5);
            if (!TryFindFirstMatchedLane(compareResult, matchedLane)) {
              intPtr = (IntPtr)(void*)((Int64)intPtr + (Int64)Vector128<UInt16>::get_Count());
              intPtr2 = (IntPtr)(void*)((Int64)intPtr2 - (Int64)Vector128<UInt16>::get_Count());
              continue;
            }
            return (Int32)((Int64)intPtr + (Int64)matchedLane);
          } while ((Int64)intPtr2 > 0)
        }
        if ((Int64)intPtr < (Int64)length) {
          intPtr2 = (IntPtr)(void*)((Int64)length - (Int64)intPtr);
          continue;
        }
      }
    } else if (Vector<>::get_IsHardwareAccelerated() && (Int64)intPtr < (Int64)length) {
      intPtr2 = GetCharVectorSpanLength((IntPtr)intPtr, (IntPtr)length);
      if ((Int64)intPtr2 > 0) {
        Vector<UInt16> left6 = Vector<UInt16>(value);
        do {
          Vector<UInt16> vector = Vector<>::Equals(left6, LoadVector(searchSpace, (IntPtr)intPtr));
          if (Vector<UInt16>::get_Zero().Equals(vector)) {
            intPtr = (IntPtr)(void*)((Int64)intPtr + (Int64)Vector<UInt16>::get_Count());
            intPtr2 = (IntPtr)(void*)((Int64)intPtr2 - (Int64)Vector<UInt16>::get_Count());
            continue;
          }
          return (Int32)((Int64)intPtr + (Int64)LocateFirstFoundChar(vector));
        } while ((Int64)intPtr2 > 0)
      }
      if ((Int64)intPtr < (Int64)length) {
        intPtr2 = (IntPtr)(void*)((Int64)length - (Int64)intPtr);
        continue;
      }
    }



    return -1;
    continue;

  end_IL_0090:
    break;
  }
  return (Int32)(Int64)intPtr;
}

Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Int32 length) {
  {
    Char* ptr = &searchSpace;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2 + length;
    if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
      Int32 num = ((Int32)ptr2 & (Unsafe::SizeOf<Vector<UInt16>>() - 1)) / 2;
      length = ((Vector<UInt16>::get_Count() - num) & (Vector<UInt16>::get_Count() - 1));
    }
    while (true) {
      if (length >= 4) {
        length -= 4;
        if (*ptr2 == value0 || *ptr2 == value1) {
          break;
        }
        if (ptr2[1] != value0 && ptr2[1] != value1) {
          if (ptr2[2] != value0 && ptr2[2] != value1) {
            if (ptr2[3] != value0 && ptr2[3] != value1) {
              ptr2 += 4;
              continue;
            }
            ptr2++;
          }
          ptr2++;
        }
        ptr2++;
        break;
      }
      while (length > 0) {
        length--;
        if (*ptr2 == value0 || *ptr2 == value1) {
          goto end_IL_00ab;
        }
        ptr2++;
      }
      if (Vector<>::get_IsHardwareAccelerated() && ptr2 < ptr3) {
        length = (Int32)((ptr3 - ptr2) & ~(Vector<UInt16>::get_Count() - 1));
        Vector<UInt16> right = Vector<UInt16>(value0);
        Vector<UInt16> right2 = Vector<UInt16>(value1);
        while (length > 0) {
          Vector<UInt16> left = Unsafe::Read<Vector<UInt16>>(ptr2);
          Vector<UInt16> vector = Vector<>::BitwiseOr(Vector<>::Equals(left, right), Vector<>::Equals(left, right2));
          if (Vector<UInt16>::get_Zero().Equals(vector)) {
            ptr2 += Vector<UInt16>::get_Count();
            length -= Vector<UInt16>::get_Count();
            continue;
          }
          return (Int32)(ptr2 - ptr) + LocateFirstFoundChar(vector);
        }
        if (ptr2 < ptr3) {
          length = (Int32)(ptr3 - ptr2);
          continue;
        }
      }
      return -1;
      continue;

    end_IL_00ab:
      break;
    }
    return (Int32)(ptr2 - ptr);
  }
}

Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Int32 length) {
  {
    Char* ptr = &searchSpace;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2 + length;
    if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
      Int32 num = ((Int32)ptr2 & (Unsafe::SizeOf<Vector<UInt16>>() - 1)) / 2;
      length = ((Vector<UInt16>::get_Count() - num) & (Vector<UInt16>::get_Count() - 1));
    }
    while (true) {
      if (length >= 4) {
        length -= 4;
        if (*ptr2 == value0 || *ptr2 == value1 || *ptr2 == value2) {
          break;
        }
        if (ptr2[1] != value0 && ptr2[1] != value1 && ptr2[1] != value2) {
          if (ptr2[2] != value0 && ptr2[2] != value1 && ptr2[2] != value2) {
            if (ptr2[3] != value0 && ptr2[3] != value1 && ptr2[3] != value2) {
              ptr2 += 4;
              continue;
            }
            ptr2++;
          }
          ptr2++;
        }
        ptr2++;
        break;
      }
      while (length > 0) {
        length--;
        if (*ptr2 == value0 || *ptr2 == value1 || *ptr2 == value2) {
          goto end_IL_00dd;
        }
        ptr2++;
      }
      if (Vector<>::get_IsHardwareAccelerated() && ptr2 < ptr3) {
        length = (Int32)((ptr3 - ptr2) & ~(Vector<UInt16>::get_Count() - 1));
        Vector<UInt16> right = Vector<UInt16>(value0);
        Vector<UInt16> right2 = Vector<UInt16>(value1);
        Vector<UInt16> right3 = Vector<UInt16>(value2);
        while (length > 0) {
          Vector<UInt16> left = Unsafe::Read<Vector<UInt16>>(ptr2);
          Vector<UInt16> vector = Vector<>::BitwiseOr(Vector<>::BitwiseOr(Vector<>::Equals(left, right), Vector<>::Equals(left, right2)), Vector<>::Equals(left, right3));
          if (Vector<UInt16>::get_Zero().Equals(vector)) {
            ptr2 += Vector<UInt16>::get_Count();
            length -= Vector<UInt16>::get_Count();
            continue;
          }
          return (Int32)(ptr2 - ptr) + LocateFirstFoundChar(vector);
        }
        if (ptr2 < ptr3) {
          length = (Int32)(ptr3 - ptr2);
          continue;
        }
      }
      return -1;
      continue;

    end_IL_00dd:
      break;
    }
    return (Int32)(ptr2 - ptr);
  }
}

Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Char value3, Int32 length) {
  {
    Char* ptr = &searchSpace;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2 + length;
    if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
      Int32 num = ((Int32)ptr2 & (Unsafe::SizeOf<Vector<UInt16>>() - 1)) / 2;
      length = ((Vector<UInt16>::get_Count() - num) & (Vector<UInt16>::get_Count() - 1));
    }
    while (true) {
      if (length >= 4) {
        length -= 4;
        if (*ptr2 == value0 || *ptr2 == value1 || *ptr2 == value2 || *ptr2 == value3) {
          break;
        }
        if (ptr2[1] != value0 && ptr2[1] != value1 && ptr2[1] != value2 && ptr2[1] != value3) {
          if (ptr2[2] != value0 && ptr2[2] != value1 && ptr2[2] != value2 && ptr2[2] != value3) {
            if (ptr2[3] != value0 && ptr2[3] != value1 && ptr2[3] != value2 && ptr2[3] != value3) {
              ptr2 += 4;
              continue;
            }
            ptr2++;
          }
          ptr2++;
        }
        ptr2++;
        break;
      }
      while (length > 0) {
        length--;
        if (*ptr2 == value0 || *ptr2 == value1 || *ptr2 == value2 || *ptr2 == value3) {
          goto end_IL_010d;
        }
        ptr2++;
      }
      if (Vector<>::get_IsHardwareAccelerated() && ptr2 < ptr3) {
        length = (Int32)((ptr3 - ptr2) & ~(Vector<UInt16>::get_Count() - 1));
        Vector<UInt16> right = Vector<UInt16>(value0);
        Vector<UInt16> right2 = Vector<UInt16>(value1);
        Vector<UInt16> right3 = Vector<UInt16>(value2);
        Vector<UInt16> right4 = Vector<UInt16>(value3);
        while (length > 0) {
          Vector<UInt16> left = Unsafe::Read<Vector<UInt16>>(ptr2);
          Vector<UInt16> vector = Vector<>::BitwiseOr(Vector<>::BitwiseOr(Vector<>::BitwiseOr(Vector<>::Equals(left, right), Vector<>::Equals(left, right2)), Vector<>::Equals(left, right3)), Vector<>::Equals(left, right4));
          if (Vector<UInt16>::get_Zero().Equals(vector)) {
            ptr2 += Vector<UInt16>::get_Count();
            length -= Vector<UInt16>::get_Count();
            continue;
          }
          return (Int32)(ptr2 - ptr) + LocateFirstFoundChar(vector);
        }
        if (ptr2 < ptr3) {
          length = (Int32)(ptr3 - ptr2);
          continue;
        }
      }
      return -1;
      continue;

    end_IL_010d:
      break;
    }
    return (Int32)(ptr2 - ptr);
  }
}

Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Char value3, Char value4, Int32 length) {
  {
    Char* ptr = &searchSpace;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2 + length;
    if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
      Int32 num = ((Int32)ptr2 & (Unsafe::SizeOf<Vector<UInt16>>() - 1)) / 2;
      length = ((Vector<UInt16>::get_Count() - num) & (Vector<UInt16>::get_Count() - 1));
    }
    while (true) {
      if (length >= 4) {
        length -= 4;
        if (*ptr2 == value0 || *ptr2 == value1 || *ptr2 == value2 || *ptr2 == value3 || *ptr2 == value4) {
          break;
        }
        if (ptr2[1] != value0 && ptr2[1] != value1 && ptr2[1] != value2 && ptr2[1] != value3 && ptr2[1] != value4) {
          if (ptr2[2] != value0 && ptr2[2] != value1 && ptr2[2] != value2 && ptr2[2] != value3 && ptr2[2] != value4) {
            if (ptr2[3] != value0 && ptr2[3] != value1 && ptr2[3] != value2 && ptr2[3] != value3 && ptr2[3] != value4) {
              ptr2 += 4;
              continue;
            }
            ptr2++;
          }
          ptr2++;
        }
        ptr2++;
        break;
      }
      while (length > 0) {
        length--;
        if (*ptr2 == value0 || *ptr2 == value1 || *ptr2 == value2 || *ptr2 == value3 || *ptr2 == value4) {
          goto end_IL_013d;
        }
        ptr2++;
      }
      if (Vector<>::get_IsHardwareAccelerated() && ptr2 < ptr3) {
        length = (Int32)((ptr3 - ptr2) & ~(Vector<UInt16>::get_Count() - 1));
        Vector<UInt16> right = Vector<UInt16>(value0);
        Vector<UInt16> right2 = Vector<UInt16>(value1);
        Vector<UInt16> right3 = Vector<UInt16>(value2);
        Vector<UInt16> right4 = Vector<UInt16>(value3);
        Vector<UInt16> right5 = Vector<UInt16>(value4);
        while (length > 0) {
          Vector<UInt16> left = Unsafe::Read<Vector<UInt16>>(ptr2);
          Vector<UInt16> vector = Vector<>::BitwiseOr(Vector<>::BitwiseOr(Vector<>::BitwiseOr(Vector<>::BitwiseOr(Vector<>::Equals(left, right), Vector<>::Equals(left, right2)), Vector<>::Equals(left, right3)), Vector<>::Equals(left, right4)), Vector<>::Equals(left, right5));
          if (Vector<UInt16>::get_Zero().Equals(vector)) {
            ptr2 += Vector<UInt16>::get_Count();
            length -= Vector<UInt16>::get_Count();
            continue;
          }
          return (Int32)(ptr2 - ptr) + LocateFirstFoundChar(vector);
        }
        if (ptr2 < ptr3) {
          length = (Int32)(ptr3 - ptr2);
          continue;
        }
      }
      return -1;
      continue;

    end_IL_013d:
      break;
    }
    return (Int32)(ptr2 - ptr);
  }
}

Int32 SpanHelpers::LastIndexOf(Char& searchSpace, Char value, Int32 length) {
  {
    Char* ptr = &searchSpace;
    Char* ptr2 = ptr + length;
    Char* ptr3 = ptr;
    if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
      length = ((Int32)ptr2 & (Unsafe::SizeOf<Vector<UInt16>>() - 1)) / 2;
    }
    while (true) {
      if (length >= 4) {
        length -= 4;
        ptr2 -= 4;
        if (ptr2[3] == value) {
          break;
        }
        if (ptr2[2] != value) {
          if (ptr2[1] != value) {
            if (*ptr2 != value) {
              continue;
            }
            goto IL_011d;
          }
          return (Int32)(ptr2 - ptr3) + 1;
        }
        return (Int32)(ptr2 - ptr3) + 2;
      }
      while (length > 0) {
        length--;
        ptr2--;
        if (*ptr2 != value) {
          continue;
        }
        goto IL_011d;
      }
      if (Vector<>::get_IsHardwareAccelerated() && ptr2 > ptr3) {
        length = (Int32)((ptr2 - ptr3) & ~(Vector<UInt16>::get_Count() - 1));
        Vector<UInt16> left = Vector<UInt16>(value);
        while (length > 0) {
          Char* ptr4 = ptr2 - Vector<UInt16>::get_Count();
          Vector<UInt16> vector = Vector<>::Equals(left, Unsafe::Read<Vector<UInt16>>(ptr4));
          if (Vector<UInt16>::get_Zero().Equals(vector)) {
            ptr2 -= Vector<UInt16>::get_Count();
            length -= Vector<UInt16>::get_Count();
            continue;
          }
          return (Int32)(ptr4 - ptr3) + LocateLastFoundChar(vector);
        }
        if (ptr2 > ptr3) {
          length = (Int32)(ptr2 - ptr3);
          continue;
        }
      }
      return -1;

    IL_011d:
      return (Int32)(ptr2 - ptr3);
    }
    return (Int32)(ptr2 - ptr3) + 3;
  }
}

Int32 SpanHelpers::LocateFirstFoundChar(Vector<UInt16> match) {
  Vector<UInt64> vector = Vector<>::AsVectorUInt64(match);
  UInt64 num = 0;
  Int32 i;
  for (i = 0; i < Vector<UInt64>::get_Count(); i++) {
    num = vector[i];
    if (num != 0) {
      break;
    }
  }
  return i * 4 + LocateFirstFoundChar(num);
}

Int32 SpanHelpers::LocateFirstFoundChar(UInt64 match) {
  return BitOperations::TrailingZeroCount(match) >> 4;
}

Int32 SpanHelpers::LocateLastFoundChar(Vector<UInt16> match) {
  Vector<UInt64> vector = Vector<>::AsVectorUInt64(match);
  UInt64 num = 0;
  Int32 num2;
  for (num2 = Vector<UInt64>::get_Count() - 1; num2 >= 0; num2--) {
    num = vector[num2];
    if (num != 0) {
      break;
    }
  }
  return num2 * 4 + LocateLastFoundChar(num);
}

Int32 SpanHelpers::LocateLastFoundChar(UInt64 match) {
  return BitOperations::Log2(match) >> 4;
}

Vector<UInt16> SpanHelpers::LoadVector(Char& start, IntPtr offset) {
  return Unsafe::ReadUnaligned<Vector<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(start, offset)));
}

Vector128<UInt16> SpanHelpers::LoadVector128(Char& start, IntPtr offset) {
  return Unsafe::ReadUnaligned<Vector128<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(start, offset)));
}

Vector256<UInt16> SpanHelpers::LoadVector256(Char& start, IntPtr offset) {
  return Unsafe::ReadUnaligned<Vector256<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(start, offset)));
}

IntPtr SpanHelpers::GetCharVectorSpanLength(IntPtr offset, IntPtr length) {
  return (length - offset) & ~(Vector<UInt16>::get_Count() - 1);
}

IntPtr SpanHelpers::GetCharVector128SpanLength(IntPtr offset, IntPtr length) {
  return (length - offset) & ~(Vector128<UInt16>::get_Count() - 1);
}

IntPtr SpanHelpers::GetCharVector256SpanLength(IntPtr offset, IntPtr length) {
  return (length - offset) & ~(Vector256<UInt16>::get_Count() - 1);
}

IntPtr SpanHelpers::UnalignedCountVector(Char& searchSpace) {
  return (IntPtr)((Int64)(UInt32)(-(Int32)Unsafe::AsPointer(searchSpace) / 2) & (Int64)(Vector<UInt16>::get_Count() - 1));
}

IntPtr SpanHelpers::UnalignedCountVector128(Char& searchSpace) {
  return (IntPtr)((Int64)(UInt32)(-(Int32)Unsafe::AsPointer(searchSpace) / 2) & (Int64)(Vector128<UInt16>::get_Count() - 1));
}

Boolean SpanHelpers::TryFindFirstMatchedLane(Vector128<UInt16> compareResult, Int32& matchedLane) {
  Vector128<Byte> vector = AdvSimd::in::Arm64::in::AddPairwise(Vector128<>::AsByte(compareResult), Vector128<>::AsByte(compareResult));
  UInt64 num = Vector128<>::ToScalar(Vector128<>::AsUInt64(vector));
  if (num == 0) {
    return false;
  }
  matchedLane = BitOperations::TrailingZeroCount(num) >> 3;
  return true;
}

void SpanHelpers::ClearWithoutReferences(Byte& b, UIntPtr byteLength) {
  if (byteLength != 0) {
    if (byteLength <= 768) {
      Unsafe::InitBlockUnaligned(b, 0, (UInt32)byteLength);
    } else {
      Buffer::_ZeroMemory(b, byteLength);
    }
  }
}

void SpanHelpers::ClearWithReferences(IntPtr& ip, UIntPtr pointerSizeLength) {
  while (pointerSizeLength >= 8) {
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)(void*)pointerSizeLength), -1) = rt::default__;
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)(void*)pointerSizeLength), -2) = rt::default__;
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)(void*)pointerSizeLength), -3) = rt::default__;
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)(void*)pointerSizeLength), -4) = rt::default__;
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)(void*)pointerSizeLength), -5) = rt::default__;
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)(void*)pointerSizeLength), -6) = rt::default__;
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)(void*)pointerSizeLength), -7) = rt::default__;
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)(void*)pointerSizeLength), -8) = rt::default__;
    pointerSizeLength -= 8;
  }
  if (pointerSizeLength < 4) {
    if (pointerSizeLength < 2) {
      if (pointerSizeLength == 0) {
        return;
      }
      goto IL_012f;
    }
  } else {
    Unsafe::Add(ip, 2) = rt::default__;
    Unsafe::Add(ip, 3) = rt::default__;
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)(void*)pointerSizeLength), -3) = rt::default__;
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)(void*)pointerSizeLength), -2) = rt::default__;
  }
  Unsafe::Add(ip, 1) = rt::default__;
  Unsafe::Add(Unsafe::Add(ip, (IntPtr)(void*)pointerSizeLength), -1) = rt::default__;
  goto IL_012f;

IL_012f:
  ip = rt::default__;
}

} // namespace System::Private::CoreLib::System::SpanHelpersNamespace
