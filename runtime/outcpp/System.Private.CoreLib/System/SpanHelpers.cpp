#include "SpanHelpers-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Buffer-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/Numerics/BitOperations-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector256-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Avx2-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>
#include <System.Private.CoreLib/System/UIntPtr-dep.h>

namespace System::Private::CoreLib::System::SpanHelpersNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Numerics;
using namespace System::Runtime::Intrinsics;
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
  UIntPtr num = 0u;
  UIntPtr num2 = (UInt32)length;
  if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    num2 = UnalignedCountVector(searchSpace);
  }
  while (true) {
    if (num2 >= 8) {
      num2 -= 8;
      if (value == Unsafe::AddByteOffset(searchSpace, num + 0) || value == Unsafe::AddByteOffset(searchSpace, num + 1) || value == Unsafe::AddByteOffset(searchSpace, num + 2) || value == Unsafe::AddByteOffset(searchSpace, num + 3) || value == Unsafe::AddByteOffset(searchSpace, num + 4) || value == Unsafe::AddByteOffset(searchSpace, num + 5) || value == Unsafe::AddByteOffset(searchSpace, num + 6) || value == Unsafe::AddByteOffset(searchSpace, num + 7)) {
        break;
      }
      num += 8;
      continue;
    }
    if (num2 >= 4) {
      num2 -= 4;
      if (value == Unsafe::AddByteOffset(searchSpace, num + 0) || value == Unsafe::AddByteOffset(searchSpace, num + 1) || value == Unsafe::AddByteOffset(searchSpace, num + 2) || value == Unsafe::AddByteOffset(searchSpace, num + 3)) {
        break;
      }
      num += 4;
    }
    while (num2 != 0) {
      num2--;
      if (value == Unsafe::AddByteOffset(searchSpace, num)) {
        goto end_IL_00bd;
      }
      num++;
    }
    if (Vector<>::get_IsHardwareAccelerated() && num < (UInt32)length) {
      num2 = (((UInt32)length - num) & (UIntPtr)(~(Vector<Byte>::get_Count() - 1)));
      Vector<Byte> left = Vector<Byte>(value);
      for (; num2 > num; num += (UIntPtr)Vector<Byte>::get_Count()) {
        Vector<Byte> other = Vector<>::Equals(left, LoadVector(searchSpace, num));
        if (!Vector<Byte>::get_Zero().Equals(other)) {
          goto end_IL_00bd;
        }
      }
      if (num < (UInt32)length) {
        num2 = (UInt32)length - num;
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
  UIntPtr num = 0u;
  UIntPtr num2 = (UInt32)length;
  if (Avx2::in::get_IsSupported() || Sse2::in::get_IsSupported()) {
    if (length >= Vector128<Byte>::get_Count() * 2) {
      num2 = UnalignedCountVector128(searchSpace);
    }
  } else if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    num2 = UnalignedCountVector(searchSpace);
  }

  while (true) {
    if (num2 >= 8) {
      num2 -= 8;
      if (value == Unsafe::AddByteOffset(searchSpace, num)) {
        goto IL_0332;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 1)) {
        goto IL_0335;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 2)) {
        goto IL_033b;
      }
      if (value != Unsafe::AddByteOffset(searchSpace, num + 3)) {
        if (value != Unsafe::AddByteOffset(searchSpace, num + 4)) {
          if (value != Unsafe::AddByteOffset(searchSpace, num + 5)) {
            if (value != Unsafe::AddByteOffset(searchSpace, num + 6)) {
              if (value == Unsafe::AddByteOffset(searchSpace, num + 7)) {
                break;
              }
              num += 8;
              continue;
            }
            return (Int32)(num + 6);
          }
          return (Int32)(num + 5);
        }
        return (Int32)(num + 4);
      }
      goto IL_0341;
    }
    if (num2 >= 4) {
      num2 -= 4;
      if (value == Unsafe::AddByteOffset(searchSpace, num)) {
        goto IL_0332;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 1)) {
        goto IL_0335;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 2)) {
        goto IL_033b;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 3)) {
        goto IL_0341;
      }
      num += 4;
    }
    while (num2 != 0) {
      num2--;
      if (value != Unsafe::AddByteOffset(searchSpace, num)) {
        num++;
        continue;
      }
      goto IL_0332;
    }
    if (Avx2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
        if (((IntPtr)((UInt32)Unsafe::AsPointer(searchSpace) + num) & (IntPtr)(Vector256<Byte>::get_Count() - 1)) != 0) {
          Vector128<Byte> left = Vector128<>::Create(value);
          Vector128<Byte> right = LoadVector128(searchSpace, num);
          Int32 num3 = Sse2::in::MoveMask(Sse2::in::CompareEqual(left, right));
          if (num3 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num3));
          }
          num += (UIntPtr)Vector128<Byte>::get_Count();
        }
        num2 = GetByteVector256SpanLength(num, length);
        if (num2 > num) {
          Vector256<Byte> left2 = Vector256<>::Create(value);
          do {
            Vector256<Byte> right2 = LoadVector256(searchSpace, num);
            Int32 num4 = Avx2::in::MoveMask(Avx2::in::CompareEqual(left2, right2));
            if (num4 == 0) {
              num += (UIntPtr)Vector256<Byte>::get_Count();
              continue;
            }
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num4));
          } while (num2 > num)
        }
        num2 = GetByteVector128SpanLength(num, length);
        if (num2 > num) {
          Vector128<Byte> left3 = Vector128<>::Create(value);
          Vector128<Byte> right3 = LoadVector128(searchSpace, num);
          Int32 num5 = Sse2::in::MoveMask(Sse2::in::CompareEqual(left3, right3));
          if (num5 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num5));
          }
          num += (UIntPtr)Vector128<Byte>::get_Count();
        }
        if (num < (UInt32)length) {
          num2 = (UInt32)length - num;
          continue;
        }
      }
    } else if (Sse2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
        num2 = GetByteVector128SpanLength(num, length);
        Vector128<Byte> left4 = Vector128<>::Create(value);
        for (; num2 > num; num += (UIntPtr)Vector128<Byte>::get_Count()) {
          Vector128<Byte> right4 = LoadVector128(searchSpace, num);
          Int32 num6 = Sse2::in::MoveMask(Sse2::in::CompareEqual(left4, right4));
          if (num6 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num6));
          }
        }
        if (num < (UInt32)length) {
          num2 = (UInt32)length - num;
          continue;
        }
      }
    } else if (Vector<>::get_IsHardwareAccelerated() && num < (UInt32)length) {
      num2 = GetByteVectorSpanLength(num, length);
      Vector<Byte> left5 = Vector<Byte>(value);
      for (; num2 > num; num += (UIntPtr)Vector<Byte>::get_Count()) {
        Vector<Byte> vector = Vector<>::Equals(left5, LoadVector(searchSpace, num));
        if (!Vector<Byte>::get_Zero().Equals(vector)) {
          return (Int32)num + LocateFirstFoundByte(vector);
        }
      }
      if (num < (UInt32)length) {
        num2 = (UInt32)length - num;
        continue;
      }
    }


    return -1;

  IL_0332:
    return (Int32)num;

  IL_0341:
    return (Int32)(num + 3);

  IL_033b:
    return (Int32)(num + 2);

  IL_0335:
    return (Int32)(num + 1);
  }
  return (Int32)(num + 7);
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
    if (SequenceEqual(Unsafe::Add(searchSpace, num4 + 1), second, (UInt32)num)) {
      return num4;
    }
    num2 += num3 - num4;
  }
  return -1;
}

Int32 SpanHelpers::LastIndexOf(Byte& searchSpace, Byte value, Int32 length) {
  UIntPtr num = (UInt32)length;
  UIntPtr num2 = (UInt32)length;
  if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    num2 = UnalignedCountVectorFromEnd(searchSpace, length);
  }
  while (true) {
    if (num2 >= 8) {
      num2 -= 8;
      num -= 8;
      if (value == Unsafe::AddByteOffset(searchSpace, num + 7)) {
        break;
      }
      if (value != Unsafe::AddByteOffset(searchSpace, num + 6)) {
        if (value != Unsafe::AddByteOffset(searchSpace, num + 5)) {
          if (value != Unsafe::AddByteOffset(searchSpace, num + 4)) {
            if (value != Unsafe::AddByteOffset(searchSpace, num + 3)) {
              if (value != Unsafe::AddByteOffset(searchSpace, num + 2)) {
                if (value != Unsafe::AddByteOffset(searchSpace, num + 1)) {
                  if (value != Unsafe::AddByteOffset(searchSpace, num)) {
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
          return (Int32)(num + 4);
        }
        return (Int32)(num + 5);
      }
      return (Int32)(num + 6);
    }
    if (num2 >= 4) {
      num2 -= 4;
      num -= 4;
      if (value == Unsafe::AddByteOffset(searchSpace, num + 3)) {
        goto IL_01c9;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 2)) {
        goto IL_01c3;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 1)) {
        goto IL_01bd;
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num)) {
        goto IL_01ba;
      }
    }
    while (num2 != 0) {
      num2--;
      num--;
      if (value != Unsafe::AddByteOffset(searchSpace, num)) {
        continue;
      }
      goto IL_01ba;
    }
    if (Vector<>::get_IsHardwareAccelerated() && num != 0) {
      num2 = (num & (UIntPtr)(~(Vector<Byte>::get_Count() - 1)));
      Vector<Byte> left = Vector<Byte>(value);
      while (num2 > (UIntPtr)(Vector<Byte>::get_Count() - 1)) {
        Vector<Byte> vector = Vector<>::Equals(left, LoadVector(searchSpace, num - (UIntPtr)Vector<Byte>::get_Count()));
        if (Vector<Byte>::get_Zero().Equals(vector)) {
          num -= (UIntPtr)Vector<Byte>::get_Count();
          num2 -= (UIntPtr)Vector<Byte>::get_Count();
          continue;
        }
        return (Int32)num - Vector<Byte>::get_Count() + LocateLastFoundByte(vector);
      }
      if (num != 0) {
        num2 = num;
        continue;
      }
    }
    return -1;

  IL_01ba:
    return (Int32)num;

  IL_01c3:
    return (Int32)(num + 2);

  IL_01c9:
    return (Int32)(num + 3);

  IL_01bd:
    return (Int32)(num + 1);
  }
  return (Int32)(num + 7);
}

Int32 SpanHelpers::IndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Int32 length) {
  UIntPtr num = 0u;
  UIntPtr num2 = (UInt32)length;
  if (Avx2::in::get_IsSupported() || Sse2::in::get_IsSupported()) {
    if (length >= Vector128<Byte>::get_Count() * 2) {
      num2 = UnalignedCountVector128(searchSpace);
    }
  } else if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    num2 = UnalignedCountVector(searchSpace);
  }

  while (true) {
    if (num2 >= 8) {
      num2 -= 8;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3) {
        goto IL_03e3;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3) {
        goto IL_03e6;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3) {
        goto IL_03ec;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 3);
      if (value0 != num3 && value1 != num3) {
        num3 = Unsafe::AddByteOffset(searchSpace, num + 4);
        if (value0 != num3 && value1 != num3) {
          num3 = Unsafe::AddByteOffset(searchSpace, num + 5);
          if (value0 != num3 && value1 != num3) {
            num3 = Unsafe::AddByteOffset(searchSpace, num + 6);
            if (value0 != num3 && value1 != num3) {
              num3 = Unsafe::AddByteOffset(searchSpace, num + 7);
              if (value0 == num3 || value1 == num3) {
                break;
              }
              num += 8;
              continue;
            }
            return (Int32)(num + 6);
          }
          return (Int32)(num + 5);
        }
        return (Int32)(num + 4);
      }
      goto IL_03f2;
    }
    if (num2 >= 4) {
      num2 -= 4;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3) {
        goto IL_03e3;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3) {
        goto IL_03e6;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3) {
        goto IL_03ec;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 3);
      if (value0 == num3 || value1 == num3) {
        goto IL_03f2;
      }
      num += 4;
    }
    while (num2 != 0) {
      num2--;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 != num3 && value1 != num3) {
        num++;
        continue;
      }
      goto IL_03e3;
    }
    if (Avx2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
        num2 = GetByteVector256SpanLength(num, length);
        if (num2 > num) {
          Vector256<Byte> left = Vector256<>::Create(value0);
          Vector256<Byte> left2 = Vector256<>::Create(value1);
          do {
            Vector256<Byte> right = LoadVector256(searchSpace, num);
            Int32 num4 = Avx2::in::MoveMask(Avx2::in::Or(Avx2::in::CompareEqual(left, right), Avx2::in::CompareEqual(left2, right)));
            if (num4 == 0) {
              num += (UIntPtr)Vector256<Byte>::get_Count();
              continue;
            }
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num4));
          } while (num2 > num)
        }
        num2 = GetByteVector128SpanLength(num, length);
        if (num2 > num) {
          Vector128<Byte> left3 = Vector128<>::Create(value0);
          Vector128<Byte> left4 = Vector128<>::Create(value1);
          Vector128<Byte> right2 = LoadVector128(searchSpace, num);
          Int32 num5 = Sse2::in::MoveMask(Sse2::in::Or(Sse2::in::CompareEqual(left3, right2), Sse2::in::CompareEqual(left4, right2)));
          if (num5 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num5));
          }
          num += (UIntPtr)Vector128<Byte>::get_Count();
        }
        if (num < (UInt32)length) {
          num2 = (UInt32)length - num;
          continue;
        }
      }
    } else if (Sse2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
        num2 = GetByteVector128SpanLength(num, length);
        Vector128<Byte> left5 = Vector128<>::Create(value0);
        Vector128<Byte> left6 = Vector128<>::Create(value1);
        for (; num2 > num; num += (UIntPtr)Vector128<Byte>::get_Count()) {
          Vector128<Byte> right3 = LoadVector128(searchSpace, num);
          Int32 num6 = Sse2::in::MoveMask(Sse2::in::Or(Sse2::in::CompareEqual(left5, right3), Sse2::in::CompareEqual(left6, right3)));
          if (num6 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num6));
          }
        }
        if (num < (UInt32)length) {
          num2 = (UInt32)length - num;
          continue;
        }
      }
    } else if (Vector<>::get_IsHardwareAccelerated() && num < (UInt32)length) {
      num2 = GetByteVectorSpanLength(num, length);
      Vector<Byte> right4 = Vector<Byte>(value0);
      Vector<Byte> right5 = Vector<Byte>(value1);
      for (; num2 > num; num += (UIntPtr)Vector<Byte>::get_Count()) {
        Vector<Byte> left7 = LoadVector(searchSpace, num);
        Vector<Byte> vector = Vector<>::BitwiseOr(Vector<>::Equals(left7, right4), Vector<>::Equals(left7, right5));
        if (!Vector<Byte>::get_Zero().Equals(vector)) {
          return (Int32)num + LocateFirstFoundByte(vector);
        }
      }
      if (num < (UInt32)length) {
        num2 = (UInt32)length - num;
        continue;
      }
    }


    return -1;

  IL_03e3:
    return (Int32)num;

  IL_03e6:
    return (Int32)(num + 1);

  IL_03f2:
    return (Int32)(num + 3);

  IL_03ec:
    return (Int32)(num + 2);
  }
  return (Int32)(num + 7);
}

Int32 SpanHelpers::IndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Byte value2, Int32 length) {
  UIntPtr num = 0u;
  UIntPtr num2 = (UInt32)length;
  if (Avx2::in::get_IsSupported() || Sse2::in::get_IsSupported()) {
    if (length >= Vector128<Byte>::get_Count() * 2) {
      num2 = UnalignedCountVector128(searchSpace);
    }
  } else if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    num2 = UnalignedCountVector(searchSpace);
  }

  while (true) {
    if (num2 >= 8) {
      num2 -= 8;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        goto IL_04fa;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        goto IL_04fd;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        goto IL_0503;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 3);
      if (value0 != num3 && value1 != num3 && value2 != num3) {
        num3 = Unsafe::AddByteOffset(searchSpace, num + 4);
        if (value0 != num3 && value1 != num3 && value2 != num3) {
          num3 = Unsafe::AddByteOffset(searchSpace, num + 5);
          if (value0 != num3 && value1 != num3 && value2 != num3) {
            num3 = Unsafe::AddByteOffset(searchSpace, num + 6);
            if (value0 != num3 && value1 != num3 && value2 != num3) {
              num3 = Unsafe::AddByteOffset(searchSpace, num + 7);
              if (value0 == num3 || value1 == num3 || value2 == num3) {
                break;
              }
              num += 8;
              continue;
            }
            return (Int32)(num + 6);
          }
          return (Int32)(num + 5);
        }
        return (Int32)(num + 4);
      }
      goto IL_0509;
    }
    if (num2 >= 4) {
      num2 -= 4;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        goto IL_04fa;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        goto IL_04fd;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        goto IL_0503;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 3);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        goto IL_0509;
      }
      num += 4;
    }
    while (num2 != 0) {
      num2--;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 != num3 && value1 != num3 && value2 != num3) {
        num++;
        continue;
      }
      goto IL_04fa;
    }
    if (Avx2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
        num2 = GetByteVector256SpanLength(num, length);
        if (num2 > num) {
          Vector256<Byte> left = Vector256<>::Create(value0);
          Vector256<Byte> left2 = Vector256<>::Create(value1);
          Vector256<Byte> left3 = Vector256<>::Create(value2);
          do {
            Vector256<Byte> right = LoadVector256(searchSpace, num);
            Vector256<Byte> left4 = Avx2::in::CompareEqual(left, right);
            Vector256<Byte> right2 = Avx2::in::CompareEqual(left2, right);
            Vector256<Byte> right3 = Avx2::in::CompareEqual(left3, right);
            Int32 num4 = Avx2::in::MoveMask(Avx2::in::Or(Avx2::in::Or(left4, right2), right3));
            if (num4 == 0) {
              num += (UIntPtr)Vector256<Byte>::get_Count();
              continue;
            }
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num4));
          } while (num2 > num)
        }
        num2 = GetByteVector128SpanLength(num, length);
        if (num2 > num) {
          Vector128<Byte> left5 = Vector128<>::Create(value0);
          Vector128<Byte> left6 = Vector128<>::Create(value1);
          Vector128<Byte> left7 = Vector128<>::Create(value2);
          Vector128<Byte> right4 = LoadVector128(searchSpace, num);
          Vector128<Byte> left8 = Sse2::in::CompareEqual(left5, right4);
          Vector128<Byte> right5 = Sse2::in::CompareEqual(left6, right4);
          Vector128<Byte> right6 = Sse2::in::CompareEqual(left7, right4);
          Int32 num5 = Sse2::in::MoveMask(Sse2::in::Or(Sse2::in::Or(left8, right5), right6));
          if (num5 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num5));
          }
          num += (UIntPtr)Vector128<Byte>::get_Count();
        }
        if (num < (UInt32)length) {
          num2 = (UInt32)length - num;
          continue;
        }
      }
    } else if (Sse2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
        num2 = GetByteVector128SpanLength(num, length);
        Vector128<Byte> left9 = Vector128<>::Create(value0);
        Vector128<Byte> left10 = Vector128<>::Create(value1);
        Vector128<Byte> left11 = Vector128<>::Create(value2);
        for (; num2 > num; num += (UIntPtr)Vector128<Byte>::get_Count()) {
          Vector128<Byte> right7 = LoadVector128(searchSpace, num);
          Vector128<Byte> left12 = Sse2::in::CompareEqual(left9, right7);
          Vector128<Byte> right8 = Sse2::in::CompareEqual(left10, right7);
          Vector128<Byte> right9 = Sse2::in::CompareEqual(left11, right7);
          Int32 num6 = Sse2::in::MoveMask(Sse2::in::Or(Sse2::in::Or(left12, right8), right9));
          if (num6 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num6));
          }
        }
        if (num < (UInt32)length) {
          num2 = (UInt32)length - num;
          continue;
        }
      }
    } else if (Vector<>::get_IsHardwareAccelerated() && num < (UInt32)length) {
      num2 = GetByteVectorSpanLength(num, length);
      Vector<Byte> right10 = Vector<Byte>(value0);
      Vector<Byte> right11 = Vector<Byte>(value1);
      Vector<Byte> right12 = Vector<Byte>(value2);
      for (; num2 > num; num += (UIntPtr)Vector<Byte>::get_Count()) {
        Vector<Byte> left13 = LoadVector(searchSpace, num);
        Vector<Byte> vector = Vector<>::BitwiseOr(Vector<>::BitwiseOr(Vector<>::Equals(left13, right10), Vector<>::Equals(left13, right11)), Vector<>::Equals(left13, right12));
        if (!Vector<Byte>::get_Zero().Equals(vector)) {
          return (Int32)num + LocateFirstFoundByte(vector);
        }
      }
      if (num < (UInt32)length) {
        num2 = (UInt32)length - num;
        continue;
      }
    }


    return -1;

  IL_0503:
    return (Int32)(num + 2);

  IL_0509:
    return (Int32)(num + 3);

  IL_04fd:
    return (Int32)(num + 1);

  IL_04fa:
    return (Int32)num;
  }
  return (Int32)(num + 7);
}

Int32 SpanHelpers::LastIndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Int32 length) {
  UIntPtr num = (UInt32)length;
  UIntPtr num2 = (UInt32)length;
  if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    num2 = UnalignedCountVectorFromEnd(searchSpace, length);
  }
  while (true) {
    if (num2 >= 8) {
      num2 -= 8;
      num -= 8;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num + 7);
      if (value0 == num3 || value1 == num3) {
        break;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 6);
      if (value0 != num3 && value1 != num3) {
        num3 = Unsafe::AddByteOffset(searchSpace, num + 5);
        if (value0 != num3 && value1 != num3) {
          num3 = Unsafe::AddByteOffset(searchSpace, num + 4);
          if (value0 != num3 && value1 != num3) {
            num3 = Unsafe::AddByteOffset(searchSpace, num + 3);
            if (value0 != num3 && value1 != num3) {
              num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
              if (value0 != num3 && value1 != num3) {
                num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
                if (value0 != num3 && value1 != num3) {
                  num3 = Unsafe::AddByteOffset(searchSpace, num);
                  if (value0 != num3 && value1 != num3) {
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
          return (Int32)(num + 4);
        }
        return (Int32)(num + 5);
      }
      return (Int32)(num + 6);
    }
    if (num2 >= 4) {
      num2 -= 4;
      num -= 4;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num + 3);
      if (value0 == num3 || value1 == num3) {
        goto IL_028b;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3) {
        goto IL_0285;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3) {
        goto IL_027f;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3) {
        goto IL_027c;
      }
    }
    while (num2 != 0) {
      num2--;
      num--;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 != num3 && value1 != num3) {
        continue;
      }
      goto IL_027c;
    }
    if (Vector<>::get_IsHardwareAccelerated() && num != 0) {
      num2 = (num & (UIntPtr)(~(Vector<Byte>::get_Count() - 1)));
      Vector<Byte> right = Vector<Byte>(value0);
      Vector<Byte> right2 = Vector<Byte>(value1);
      while (num2 > (UIntPtr)(Vector<Byte>::get_Count() - 1)) {
        Vector<Byte> left = LoadVector(searchSpace, num - (UIntPtr)Vector<Byte>::get_Count());
        Vector<Byte> vector = Vector<>::BitwiseOr(Vector<>::Equals(left, right), Vector<>::Equals(left, right2));
        if (Vector<Byte>::get_Zero().Equals(vector)) {
          num -= (UIntPtr)Vector<Byte>::get_Count();
          num2 -= (UIntPtr)Vector<Byte>::get_Count();
          continue;
        }
        return (Int32)num - Vector<Byte>::get_Count() + LocateLastFoundByte(vector);
      }
      if (num != 0) {
        num2 = num;
        continue;
      }
    }
    return -1;

  IL_027c:
    return (Int32)num;

  IL_028b:
    return (Int32)(num + 3);

  IL_027f:
    return (Int32)(num + 1);

  IL_0285:
    return (Int32)(num + 2);
  }
  return (Int32)(num + 7);
}

Int32 SpanHelpers::LastIndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Byte value2, Int32 length) {
  UIntPtr num = (UInt32)length;
  UIntPtr num2 = (UInt32)length;
  if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    num2 = UnalignedCountVectorFromEnd(searchSpace, length);
  }
  while (true) {
    if (num2 >= 8) {
      num2 -= 8;
      num -= 8;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num + 7);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        break;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 6);
      if (value0 != num3 && value1 != num3 && value2 != num3) {
        num3 = Unsafe::AddByteOffset(searchSpace, num + 5);
        if (value0 != num3 && value1 != num3 && value2 != num3) {
          num3 = Unsafe::AddByteOffset(searchSpace, num + 4);
          if (value0 != num3 && value1 != num3 && value2 != num3) {
            num3 = Unsafe::AddByteOffset(searchSpace, num + 3);
            if (value0 != num3 && value1 != num3 && value2 != num3) {
              num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
              if (value0 != num3 && value1 != num3 && value2 != num3) {
                num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
                if (value0 != num3 && value1 != num3 && value2 != num3) {
                  num3 = Unsafe::AddByteOffset(searchSpace, num);
                  if (value0 != num3 && value1 != num3 && value2 != num3) {
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
          return (Int32)(num + 4);
        }
        return (Int32)(num + 5);
      }
      return (Int32)(num + 6);
    }
    if (num2 >= 4) {
      num2 -= 4;
      num -= 4;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num + 3);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        goto IL_031f;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        goto IL_0319;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        goto IL_0313;
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
        goto IL_0310;
      }
    }
    while (num2 != 0) {
      num2--;
      num--;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 != num3 && value1 != num3 && value2 != num3) {
        continue;
      }
      goto IL_0310;
    }
    if (Vector<>::get_IsHardwareAccelerated() && num != 0) {
      num2 = (num & (UIntPtr)(~(Vector<Byte>::get_Count() - 1)));
      Vector<Byte> right = Vector<Byte>(value0);
      Vector<Byte> right2 = Vector<Byte>(value1);
      Vector<Byte> right3 = Vector<Byte>(value2);
      while (num2 > (UIntPtr)(Vector<Byte>::get_Count() - 1)) {
        Vector<Byte> left = LoadVector(searchSpace, num - (UIntPtr)Vector<Byte>::get_Count());
        Vector<Byte> vector = Vector<>::BitwiseOr(Vector<>::BitwiseOr(Vector<>::Equals(left, right), Vector<>::Equals(left, right2)), Vector<>::Equals(left, right3));
        if (Vector<Byte>::get_Zero().Equals(vector)) {
          num -= (UIntPtr)Vector<Byte>::get_Count();
          num2 -= (UIntPtr)Vector<Byte>::get_Count();
          continue;
        }
        return (Int32)num - Vector<Byte>::get_Count() + LocateLastFoundByte(vector);
      }
      if (num != 0) {
        num2 = num;
        continue;
      }
    }
    return -1;

  IL_0310:
    return (Int32)num;

  IL_031f:
    return (Int32)(num + 3);

  IL_0319:
    return (Int32)(num + 2);

  IL_0313:
    return (Int32)(num + 1);
  }
  return (Int32)(num + 7);
}

Boolean SpanHelpers::SequenceEqual(Byte& first, Byte& second, UIntPtr length) {
  if (length < (UIntPtr)sizeof(UIntPtr)) {
    if (length < 4) {
      UInt32 num = 0u;
      UIntPtr num2 = length & 2;
      if (num2 != 0) {
        num = LoadUShort(first);
        num -= LoadUShort(second);
      }
      if ((length & 1) != 0) {
        num |= (UInt32)(Unsafe::AddByteOffset(first, num2) - Unsafe::AddByteOffset(second, num2));
      }
      return num == 0;
    }
    UIntPtr offset = length - 4;
    UInt32 num3 = LoadUInt(first) - LoadUInt(second);
    num3 |= LoadUInt(first, offset) - LoadUInt(second, offset);
    return num3 == 0;
  }
  if (Unsafe::AreSame(first, second)) {
    goto IL_0087;
  }
  UIntPtr num5;
  UIntPtr num7;
  UIntPtr num9;
  Vector256<Byte> value;
  Vector128<Byte> value2;
  if (Sse2::in::get_IsSupported()) {
    if (Avx2::in::get_IsSupported() && length >= (UIntPtr)Vector256<Byte>::get_Count()) {
      UIntPtr num4 = 0u;
      num5 = length - (UIntPtr)Vector256<Byte>::get_Count();
      if (num5 == 0) {
        goto IL_00ea;
      }
      while (true) {
        value = Avx2::in::CompareEqual(LoadVector256(first, num4), LoadVector256(second, num4));
        if (Avx2::in::MoveMask(value) != -1) {
          break;
        }
        num4 += (UIntPtr)Vector256<Byte>::get_Count();
        if (num5 > num4) {
          continue;
        }
        goto IL_00ea;
      }
    } else {
      if (length < 16) {
        goto IL_01fc;
      }
      UIntPtr num6 = 0u;
      num7 = length - 16;
      if (num7 == 0) {
        goto IL_0161;
      }
      while (true) {
        value2 = Sse2::in::CompareEqual(LoadVector128(first, num6), LoadVector128(second, num6));
        if (Sse2::in::MoveMask(value2) != 65535) {
          break;
        }
        num6 += 16;
        if (num7 > num6) {
          continue;
        }
        goto IL_0161;
      }
    }
  } else {
    if (!Vector<>::get_IsHardwareAccelerated() || length < (UIntPtr)Vector<Byte>::get_Count()) {
      goto IL_01fc;
    }
    UIntPtr num8 = 0u;
    num9 = length - (UIntPtr)Vector<Byte>::get_Count();
    if (num9 == 0) {
      goto IL_01dd;
    }
    while (!(LoadVector(first, num8) != LoadVector(second, num8))) {
      num8 += (UIntPtr)Vector<Byte>::get_Count();
      if (num9 > num8) {
        continue;
      }
      goto IL_01dd;
    }
  }
  goto IL_0290;

IL_0290:
  return false;

IL_01dd:
  if (LoadVector(first, num9) == LoadVector(second, num9)) {
    goto IL_0087;
  }
  goto IL_0290;

IL_0278:
  UIntPtr num10;
  return LoadNUInt(first, num10) == LoadNUInt(second, num10);

IL_01fc:
  if (Sse2::in::get_IsSupported()) {
    UIntPtr offset2 = length - (UIntPtr)sizeof(UIntPtr);
    UIntPtr num11 = LoadNUInt(first) - LoadNUInt(second);
    num11 |= LoadNUInt(first, offset2) - LoadNUInt(second, offset2);
    return num11 == 0;
  }
  UIntPtr num12 = 0u;
  num10 = length - (UIntPtr)sizeof(UIntPtr);
  if (num10 == 0) {
    goto IL_0278;
  }
  while (LoadNUInt(first, num12) == LoadNUInt(second, num12)) {
    num12 += (UIntPtr)sizeof(UIntPtr);
    if (num10 > num12) {
      continue;
    }
    goto IL_0278;
  }
  goto IL_0290;

IL_00ea:
  value = Avx2::in::CompareEqual(LoadVector256(first, num5), LoadVector256(second, num5));
  if (Avx2::in::MoveMask(value) == -1) {
    goto IL_0087;
  }
  goto IL_0290;

IL_0087:
  return true;

IL_0161:
  value2 = Sse2::in::CompareEqual(LoadVector128(first, num7), LoadVector128(second, num7));
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
  UIntPtr num;
  UInt32 num6;
  UIntPtr num3;
  UIntPtr num2;
  if (!Unsafe::AreSame(first, second)) {
    num = (UInt32)(((UInt32)firstLength < (UInt32)secondLength) ? firstLength : secondLength);
    num2 = 0u;
    num3 = num;
    if (!Avx2::in::get_IsSupported()) {
      if (Sse2::in::get_IsSupported()) {
        if (num3 >= (UIntPtr)Vector128<Byte>::get_Count()) {
          num3 -= (UIntPtr)Vector128<Byte>::get_Count();
          while (true) {
            UInt32 num4;
            if (num3 > num2) {
              num4 = (UInt32)Sse2::in::MoveMask(Sse2::in::CompareEqual(LoadVector128(first, num2), LoadVector128(second, num2)));
              if (num4 == 65535) {
                num2 += (UIntPtr)Vector128<Byte>::get_Count();
                continue;
              }
            } else {
              num2 = num3;
              num4 = (UInt32)Sse2::in::MoveMask(Sse2::in::CompareEqual(LoadVector128(first, num2), LoadVector128(second, num2)));
              if (num4 == 65535) {
                break;
              }
            }
            UInt32 value = ~num4;
            num2 += (UInt32)BitOperations::TrailingZeroCount(value);
            return Unsafe::AddByteOffset(first, num2).CompareTo(Unsafe::AddByteOffset(second, num2));
          }
          goto IL_0277;
        }
      } else if (Vector<>::get_IsHardwareAccelerated() && num3 > (UIntPtr)Vector<Byte>::get_Count()) {
        for (num3 -= (UIntPtr)Vector<Byte>::get_Count(); num3 > num2 && !(LoadVector(first, num2) != LoadVector(second, num2)); num2 += (UIntPtr)Vector<Byte>::get_Count()) {
        }
        goto IL_0273;
      }

      goto IL_021b;
    }
    if (num3 >= (UIntPtr)Vector256<Byte>::get_Count()) {
      num3 -= (UIntPtr)Vector256<Byte>::get_Count();
      while (true) {
        UInt32 num5;
        if (num3 > num2) {
          num5 = (UInt32)Avx2::in::MoveMask(Avx2::in::CompareEqual(LoadVector256(first, num2), LoadVector256(second, num2)));
          if (num5 == UInt32::MaxValue) {
            num2 += (UIntPtr)Vector256<Byte>::get_Count();
            continue;
          }
        } else {
          num2 = num3;
          num5 = (UInt32)Avx2::in::MoveMask(Avx2::in::CompareEqual(LoadVector256(first, num2), LoadVector256(second, num2)));
          if (num5 == UInt32::MaxValue) {
            break;
          }
        }
        UInt32 value2 = ~num5;
        num2 += (UInt32)BitOperations::TrailingZeroCount(value2);
        return Unsafe::AddByteOffset(first, num2).CompareTo(Unsafe::AddByteOffset(second, num2));
      }
    } else {
      if (num3 < (UIntPtr)Vector128<Byte>::get_Count()) {
        goto IL_021b;
      }
      num3 -= (UIntPtr)Vector128<Byte>::get_Count();
      if (num3 > num2) {
        num6 = (UInt32)Sse2::in::MoveMask(Sse2::in::CompareEqual(LoadVector128(first, num2), LoadVector128(second, num2)));
        if (num6 != 65535) {
          goto IL_0111;
        }
      }
      num2 = num3;
      num6 = (UInt32)Sse2::in::MoveMask(Sse2::in::CompareEqual(LoadVector128(first, num2), LoadVector128(second, num2)));
      if (num6 != 65535) {
        goto IL_0111;
      }
    }
  }
  goto IL_0277;

IL_021b:
  if (num3 > (UIntPtr)sizeof(UIntPtr)) {
    for (num3 -= (UIntPtr)sizeof(UIntPtr); num3 > num2 && LoadNUInt(first, num2) == LoadNUInt(second, num2); num2 += (UIntPtr)sizeof(UIntPtr)) {
    }
  }
  goto IL_0273;

IL_0111:
  UInt32 value3 = ~num6;
  num2 += (UInt32)BitOperations::TrailingZeroCount(value3);
  return Unsafe::AddByteOffset(first, num2).CompareTo(Unsafe::AddByteOffset(second, num2));

IL_0273:
  for (; num > num2; num2++) {
    Int32 num7 = Unsafe::AddByteOffset(first, num2).CompareTo(Unsafe::AddByteOffset(second, num2));
    if (num7 != 0) {
      return num7;
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
  IntPtr num = (IntPtr)(IntPtr)Unsafe::AsPointer(searchSpace) & (Vector<Byte>::get_Count() - 1);
  return (UIntPtr)((Vector<Byte>::get_Count() - num) & (Vector<Byte>::get_Count() - 1));
}

UIntPtr SpanHelpers::UnalignedCountVector128(Byte& searchSpace) {
  IntPtr num = (IntPtr)(IntPtr)Unsafe::AsPointer(searchSpace) & (Vector128<Byte>::get_Count() - 1);
  return (UInt32)((Vector128<Byte>::get_Count() - num) & (Vector128<Byte>::get_Count() - 1));
}

UIntPtr SpanHelpers::UnalignedCountVectorFromEnd(Byte& searchSpace, Int32 length) {
  IntPtr num = (IntPtr)(IntPtr)Unsafe::AsPointer(searchSpace) & (Vector<Byte>::get_Count() - 1);
  return (UInt32)(((length & (Vector<Byte>::get_Count() - 1)) + num) & (Vector<Byte>::get_Count() - 1));
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
    if (SequenceEqual(Unsafe::As<Char, Byte>(Unsafe::Add(searchSpace, num3 + 1)), Unsafe::As<Char, Byte>(source), (UIntPtr)(UInt32)num * (?)2u)) {
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
    UIntPtr num = (UInt32)(((UInt32)firstLength < (UInt32)secondLength) ? firstLength : secondLength);
    UIntPtr num2 = 0u;
    if (num >= (UIntPtr)(sizeof(UIntPtr) / 2)) {
      if (Vector<>::get_IsHardwareAccelerated() && num >= (UIntPtr)Vector<UInt16>::get_Count()) {
        UIntPtr num3 = num - (UIntPtr)Vector<UInt16>::get_Count();
        while (!(Unsafe::ReadUnaligned<Vector<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(first, (IntPtr)num2))) != Unsafe::ReadUnaligned<Vector<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(second, (IntPtr)num2))))) {
          num2 += (UIntPtr)Vector<UInt16>::get_Count();
          if (num3 < num2) {
            break;
          }
        }
      }
      for (; num >= (UIntPtr)((IntPtr)num2 + (IntPtr)(sizeof(UIntPtr) / 2)) && Unsafe::ReadUnaligned<UIntPtr>(Unsafe::As<Char, Byte>(Unsafe::Add(first, (IntPtr)num2))) == Unsafe::ReadUnaligned<UIntPtr>(Unsafe::As<Char, Byte>(Unsafe::Add(second, (IntPtr)num2))); num2 += (UIntPtr)(sizeof(UIntPtr) / 2)) {
      }
    }
    if (num >= num2 + 2 && Unsafe::ReadUnaligned<Int32>(Unsafe::As<Char, Byte>(Unsafe::Add(first, (IntPtr)num2))) == Unsafe::ReadUnaligned<Int32>(Unsafe::As<Char, Byte>(Unsafe::Add(second, (IntPtr)num2)))) {
      num2 += 2;
    }
    for (; num2 < num; num2++) {
      Int32 num4 = Unsafe::Add(first, (IntPtr)num2).CompareTo(Unsafe::Add(second, (IntPtr)num2));
      if (num4 != 0) {
        return num4;
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
  IntPtr num = 0;
  IntPtr num2 = length;
  if (((Int32)Unsafe::AsPointer(searchSpace) & 1) == 0) {
    if (Sse2::in::get_IsSupported()) {
      if (length >= Vector128<UInt16>::get_Count() * 2) {
        num2 = UnalignedCountVector128(searchSpace);
      }
    } else if (Vector<>::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
      num2 = UnalignedCountVector(searchSpace);
    }

  }
  while (true) {
    if (num2 >= 4) {
      Char& reference = Unsafe::Add(searchSpace, num);
      if (value == reference) {
        break;
      }
      if (value != Unsafe::Add(reference, 1)) {
        if (value != Unsafe::Add(reference, 2)) {
          if (value != Unsafe::Add(reference, 3)) {
            num += 4;
            num2 -= 4;
            continue;
          }
          return (Int32)(num + 3);
        }
        return (Int32)(num + 2);
      }
      return (Int32)(num + 1);
    }
    while (num2 > 0) {
      if (value == Unsafe::Add(searchSpace, num)) {
        goto end_IL_0089;
      }
      num++;
      num2--;
    }
    if (Avx2::in::get_IsSupported()) {
      if (num < length) {
        if (((IntPtr)(IntPtr)Unsafe::AsPointer(Unsafe::Add(searchSpace, num)) & (Vector256<Byte>::get_Count() - 1)) != 0) {
          Vector128<UInt16> left = Vector128<>::Create(value);
          Vector128<UInt16> right = LoadVector128(searchSpace, num);
          Int32 num3 = Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::CompareEqual(left, right)));
          if (num3 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num3) / 2u);
          }
          num += Vector128<UInt16>::get_Count();
        }
        num2 = GetCharVector256SpanLength(num, length);
        if (num2 > 0) {
          Vector256<UInt16> left2 = Vector256<>::Create(value);
          do {
            Vector256<UInt16> right2 = LoadVector256(searchSpace, num);
            Int32 num4 = Avx2::in::MoveMask(Vector256<>::AsByte(Avx2::in::CompareEqual(left2, right2)));
            if (num4 == 0) {
              num += Vector256<UInt16>::get_Count();
              num2 -= Vector256<UInt16>::get_Count();
              continue;
            }
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num4) / 2u);
          } while (num2 > 0)
        }
        num2 = GetCharVector128SpanLength(num, length);
        if (num2 > 0) {
          Vector128<UInt16> left3 = Vector128<>::Create(value);
          Vector128<UInt16> right3 = LoadVector128(searchSpace, num);
          Int32 num5 = Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::CompareEqual(left3, right3)));
          if (num5 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num5) / 2u);
          }
          num += Vector128<UInt16>::get_Count();
        }
        if (num < length) {
          num2 = length - num;
          continue;
        }
      }
    } else if (Sse2::in::get_IsSupported()) {
      if (num < length) {
        num2 = GetCharVector128SpanLength(num, length);
        if (num2 > 0) {
          Vector128<UInt16> left4 = Vector128<>::Create(value);
          do {
            Vector128<UInt16> right4 = LoadVector128(searchSpace, num);
            Int32 num6 = Sse2::in::MoveMask(Vector128<>::AsByte(Sse2::in::CompareEqual(left4, right4)));
            if (num6 == 0) {
              num += Vector128<UInt16>::get_Count();
              num2 -= Vector128<UInt16>::get_Count();
              continue;
            }
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num6) / 2u);
          } while (num2 > 0)
        }
        if (num < length) {
          num2 = length - num;
          continue;
        }
      }
    } else if (Vector<>::get_IsHardwareAccelerated() && num < length) {
      num2 = GetCharVectorSpanLength(num, length);
      if (num2 > 0) {
        Vector<UInt16> left5 = Vector<UInt16>(value);
        do {
          Vector<UInt16> vector = Vector<>::Equals(left5, LoadVector(searchSpace, num));
          if (Vector<UInt16>::get_Zero().Equals(vector)) {
            num += Vector<UInt16>::get_Count();
            num2 -= Vector<UInt16>::get_Count();
            continue;
          }
          return (Int32)(num + LocateFirstFoundChar(vector));
        } while (num2 > 0)
      }
      if (num < length) {
        num2 = length - num;
        continue;
      }
    }


    return -1;
    continue;

  end_IL_0089:
    break;
  }
  return (Int32)num;
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
  return (IntPtr)(UInt32)(-(Int32)Unsafe::AsPointer(searchSpace) / 2) & (IntPtr)(Vector<UInt16>::get_Count() - 1);
}

IntPtr SpanHelpers::UnalignedCountVector128(Char& searchSpace) {
  return (IntPtr)(UInt32)(-(Int32)Unsafe::AsPointer(searchSpace) / 2) & (IntPtr)(Vector128<UInt16>::get_Count() - 1);
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
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)pointerSizeLength), -1) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)pointerSizeLength), -2) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)pointerSizeLength), -3) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)pointerSizeLength), -4) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)pointerSizeLength), -5) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)pointerSizeLength), -6) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)pointerSizeLength), -7) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)pointerSizeLength), -8) = IntPtr();
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
    Unsafe::Add(ip, 2) = IntPtr();
    Unsafe::Add(ip, 3) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)pointerSizeLength), -3) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (IntPtr)pointerSizeLength), -2) = IntPtr();
  }
  Unsafe::Add(ip, 1) = IntPtr();
  Unsafe::Add(Unsafe::Add(ip, (IntPtr)pointerSizeLength), -1) = IntPtr();
  goto IL_012f;

IL_012f:
  ip = IntPtr();
}

} // namespace System::Private::CoreLib::System::SpanHelpersNamespace
