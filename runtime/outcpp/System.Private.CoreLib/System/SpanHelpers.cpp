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
    if (SequenceEqual(Unsafe::Add(searchSpace, num3 + 1), second, (unsigned int)num)) {
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
  unsigned int num = 0u;
  unsigned int num2 = (UInt32)length;
  if (Vector::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    num2 = UnalignedCountVector(searchSpace);
  }
  while (true) {
    if (num2 >= 8) {
      num2 -= 8;
      if (value == Unsafe::AddByteOffset(searchSpace, num + 0) || value == Unsafe::AddByteOffset(searchSpace, num + 1) || value == Unsafe::AddByteOffset(searchSpace, num + 2) || value == Unsafe::AddByteOffset(searchSpace, num + 3) || value == Unsafe::AddByteOffset(searchSpace, num + 4) || value == Unsafe::AddByteOffset(searchSpace, num + 5) || value == Unsafe::AddByteOffset(searchSpace, num + 6) || value == Unsafe::AddByteOffset(searchSpace, num + 7)) {
        break;
      }
      num += 8;
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
      }
      num++;
    }
    if (Vector::get_IsHardwareAccelerated() && num < (UInt32)length) {
    }
    return false;
  }
  return true;
}

Int32 SpanHelpers::IndexOf(Byte& searchSpace, Byte value, Int32 length) {
  unsigned int num = 0u;
  unsigned int num2 = (UInt32)length;
  if (Avx2::in::get_IsSupported() || Sse2::in::get_IsSupported()) {
    if (length >= Vector128<Byte>::get_Count() * 2) {
      num2 = UnalignedCountVector128(searchSpace);
    }
  } else if (Vector::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    num2 = UnalignedCountVector(searchSpace);
  }

  while (true) {
    if (num2 >= 8) {
      num2 -= 8;
      if (value == Unsafe::AddByteOffset(searchSpace, num)) {
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 1)) {
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 2)) {
      }
      if (value != Unsafe::AddByteOffset(searchSpace, num + 3)) {
        if (value != Unsafe::AddByteOffset(searchSpace, num + 4)) {
          if (value != Unsafe::AddByteOffset(searchSpace, num + 5)) {
            if (value != Unsafe::AddByteOffset(searchSpace, num + 6)) {
              if (value == Unsafe::AddByteOffset(searchSpace, num + 7)) {
                break;
              }
              num += 8;
            }
            return (Int32)(num + 6);
          }
          return (Int32)(num + 5);
        }
        return (Int32)(num + 4);
      }
    }
    if (num2 >= 4) {
      num2 -= 4;
      if (value == Unsafe::AddByteOffset(searchSpace, num)) {
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 1)) {
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 2)) {
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 3)) {
      }
      num += 4;
    }
    while (num2 != 0) {
      num2--;
      if (value != Unsafe::AddByteOffset(searchSpace, num)) {
        num++;
      }
    }
    if (Avx2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
      }
    } else if (Sse2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
        num2 = GetByteVector128SpanLength(num, length);
        Vector128<Byte> left4 = Vector128::Create(value);
        for (; num2 > num; num += (unsigned int)Vector128<Byte>::get_Count()) {
          Vector128<Byte> right4 = LoadVector128(searchSpace, num);
          Int32 num6 = Sse2::in::MoveMask(Sse2::in::CompareEqual(left4, right4));
          if (num6 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num6));
          }
        }
        if (num < (UInt32)length) {
          num2 = (UInt32)length - num;
        }
      }
    } else if (Vector::get_IsHardwareAccelerated() && num < (UInt32)length) {
      num2 = GetByteVectorSpanLength(num, length);
      Vector<Byte> left5 = Vector<Byte>(value);
      for (; num2 > num; num += (unsigned int)Vector<Byte>::get_Count()) {
        Vector<Byte> vector = Vector::Equals(left5, LoadVector(searchSpace, num));
        if (!Vector<Byte>::get_Zero().Equals(vector)) {
          return (Int32)num + LocateFirstFoundByte(vector);
        }
      }
      if (num < (UInt32)length) {
        num2 = (UInt32)length - num;
      }
    }


    return -1;
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
  unsigned int num = (UInt32)length;
  unsigned int num2 = (UInt32)length;
  if (Vector::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
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
                  }
                }
              }
            }
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
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 2)) {
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num + 1)) {
      }
      if (value == Unsafe::AddByteOffset(searchSpace, num)) {
      }
    }
    while (num2 != 0) {
      num2--;
      num--;
      if (value != Unsafe::AddByteOffset(searchSpace, num)) {
      }
    }
    if (Vector::get_IsHardwareAccelerated() && num != 0) {
    }
    return -1;
  }
  return (Int32)(num + 7);
}

Int32 SpanHelpers::IndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Int32 length) {
  unsigned int num = 0u;
  unsigned int num2 = (UInt32)length;
  if (Avx2::in::get_IsSupported() || Sse2::in::get_IsSupported()) {
    if (length >= Vector128<Byte>::get_Count() * 2) {
      num2 = UnalignedCountVector128(searchSpace);
    }
  } else if (Vector::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    num2 = UnalignedCountVector(searchSpace);
  }

  while (true) {
    if (num2 >= 8) {
      num2 -= 8;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3) {
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
            }
            return (Int32)(num + 6);
          }
          return (Int32)(num + 5);
        }
        return (Int32)(num + 4);
      }
    }
    if (num2 >= 4) {
      num2 -= 4;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 3);
      if (value0 == num3 || value1 == num3) {
      }
      num += 4;
    }
    while (num2 != 0) {
      num2--;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 != num3 && value1 != num3) {
        num++;
      }
    }
    if (Avx2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
        num2 = GetByteVector256SpanLength(num, length);
        if (num2 > num) {
          Vector256<Byte> left = Vector256::Create(value0);
          Vector256<Byte> left2 = Vector256::Create(value1);
        }
        num2 = GetByteVector128SpanLength(num, length);
        if (num2 > num) {
          Vector128<Byte> left3 = Vector128::Create(value0);
          Vector128<Byte> left4 = Vector128::Create(value1);
          Vector128<Byte> right2 = LoadVector128(searchSpace, num);
          Int32 num5 = Sse2::in::MoveMask(Sse2::in::Or(Sse2::in::CompareEqual(left3, right2), Sse2::in::CompareEqual(left4, right2)));
          if (num5 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num5));
          }
          num += (unsigned int)Vector128<Byte>::get_Count();
        }
        if (num < (UInt32)length) {
          num2 = (UInt32)length - num;
        }
      }
    } else if (Sse2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
        num2 = GetByteVector128SpanLength(num, length);
        Vector128<Byte> left5 = Vector128::Create(value0);
        Vector128<Byte> left6 = Vector128::Create(value1);
        for (; num2 > num; num += (unsigned int)Vector128<Byte>::get_Count()) {
          Vector128<Byte> right3 = LoadVector128(searchSpace, num);
          Int32 num6 = Sse2::in::MoveMask(Sse2::in::Or(Sse2::in::CompareEqual(left5, right3), Sse2::in::CompareEqual(left6, right3)));
          if (num6 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num6));
          }
        }
        if (num < (UInt32)length) {
          num2 = (UInt32)length - num;
        }
      }
    } else if (Vector::get_IsHardwareAccelerated() && num < (UInt32)length) {
      num2 = GetByteVectorSpanLength(num, length);
      Vector<Byte> right4 = Vector<Byte>(value0);
      Vector<Byte> right5 = Vector<Byte>(value1);
      for (; num2 > num; num += (unsigned int)Vector<Byte>::get_Count()) {
        Vector<Byte> left7 = LoadVector(searchSpace, num);
        Vector<Byte> vector = Vector::BitwiseOr(Vector::Equals(left7, right4), Vector::Equals(left7, right5));
        if (!Vector<Byte>::get_Zero().Equals(vector)) {
          return (Int32)num + LocateFirstFoundByte(vector);
        }
      }
      if (num < (UInt32)length) {
        num2 = (UInt32)length - num;
      }
    }


    return -1;
  }
  return (Int32)(num + 7);
}

Int32 SpanHelpers::IndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Byte value2, Int32 length) {
  unsigned int num = 0u;
  unsigned int num2 = (UInt32)length;
  if (Avx2::in::get_IsSupported() || Sse2::in::get_IsSupported()) {
    if (length >= Vector128<Byte>::get_Count() * 2) {
      num2 = UnalignedCountVector128(searchSpace);
    }
  } else if (Vector::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
    num2 = UnalignedCountVector(searchSpace);
  }

  while (true) {
    if (num2 >= 8) {
      num2 -= 8;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
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
            }
            return (Int32)(num + 6);
          }
          return (Int32)(num + 5);
        }
        return (Int32)(num + 4);
      }
    }
    if (num2 >= 4) {
      num2 -= 4;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 3);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
      }
      num += 4;
    }
    while (num2 != 0) {
      num2--;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 != num3 && value1 != num3 && value2 != num3) {
        num++;
      }
    }
    if (Avx2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
        num2 = GetByteVector256SpanLength(num, length);
        if (num2 > num) {
          Vector256<Byte> left = Vector256::Create(value0);
          Vector256<Byte> left2 = Vector256::Create(value1);
          Vector256<Byte> left3 = Vector256::Create(value2);
        }
        num2 = GetByteVector128SpanLength(num, length);
        if (num2 > num) {
          Vector128<Byte> left5 = Vector128::Create(value0);
          Vector128<Byte> left6 = Vector128::Create(value1);
          Vector128<Byte> left7 = Vector128::Create(value2);
          Vector128<Byte> right4 = LoadVector128(searchSpace, num);
          Vector128<Byte> left8 = Sse2::in::CompareEqual(left5, right4);
          Vector128<Byte> right5 = Sse2::in::CompareEqual(left6, right4);
          Vector128<Byte> right6 = Sse2::in::CompareEqual(left7, right4);
          Int32 num5 = Sse2::in::MoveMask(Sse2::in::Or(Sse2::in::Or(left8, right5), right6));
          if (num5 != 0) {
            return (Int32)(num + (UInt32)BitOperations::TrailingZeroCount(num5));
          }
          num += (unsigned int)Vector128<Byte>::get_Count();
        }
        if (num < (UInt32)length) {
          num2 = (UInt32)length - num;
        }
      }
    } else if (Sse2::in::get_IsSupported()) {
      if (num < (UInt32)length) {
        num2 = GetByteVector128SpanLength(num, length);
        Vector128<Byte> left9 = Vector128::Create(value0);
        Vector128<Byte> left10 = Vector128::Create(value1);
        Vector128<Byte> left11 = Vector128::Create(value2);
        for (; num2 > num; num += (unsigned int)Vector128<Byte>::get_Count()) {
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
        }
      }
    } else if (Vector::get_IsHardwareAccelerated() && num < (UInt32)length) {
      num2 = GetByteVectorSpanLength(num, length);
      Vector<Byte> right10 = Vector<Byte>(value0);
      Vector<Byte> right11 = Vector<Byte>(value1);
      Vector<Byte> right12 = Vector<Byte>(value2);
      for (; num2 > num; num += (unsigned int)Vector<Byte>::get_Count()) {
        Vector<Byte> left13 = LoadVector(searchSpace, num);
        Vector<Byte> vector = Vector::BitwiseOr(Vector::BitwiseOr(Vector::Equals(left13, right10), Vector::Equals(left13, right11)), Vector::Equals(left13, right12));
        if (!Vector<Byte>::get_Zero().Equals(vector)) {
          return (Int32)num + LocateFirstFoundByte(vector);
        }
      }
      if (num < (UInt32)length) {
        num2 = (UInt32)length - num;
      }
    }


    return -1;
  }
  return (Int32)(num + 7);
}

Int32 SpanHelpers::LastIndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Int32 length) {
  unsigned int num = (UInt32)length;
  unsigned int num2 = (UInt32)length;
  if (Vector::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
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
                  }
                }
              }
            }
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
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3) {
      }
    }
    while (num2 != 0) {
      num2--;
      num--;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 != num3 && value1 != num3) {
      }
    }
    if (Vector::get_IsHardwareAccelerated() && num != 0) {
    }
    return -1;
  }
  return (Int32)(num + 7);
}

Int32 SpanHelpers::LastIndexOfAny(Byte& searchSpace, Byte value0, Byte value1, Byte value2, Int32 length) {
  unsigned int num = (UInt32)length;
  unsigned int num2 = (UInt32)length;
  if (Vector::get_IsHardwareAccelerated() && length >= Vector<Byte>::get_Count() * 2) {
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
                  }
                }
              }
            }
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
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 2);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num + 1);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
      }
      num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 == num3 || value1 == num3 || value2 == num3) {
      }
    }
    while (num2 != 0) {
      num2--;
      num--;
      UInt32 num3 = Unsafe::AddByteOffset(searchSpace, num);
      if (value0 != num3 && value1 != num3 && value2 != num3) {
      }
    }
    if (Vector::get_IsHardwareAccelerated() && num != 0) {
    }
    return -1;
  }
  return (Int32)(num + 7);
}

Boolean SpanHelpers::SequenceEqual(Byte& first, Byte& second, unsigned int length) {
  if (length < (unsigned int)sizeof(UIntPtr)) {
    if (length < 4) {
      UInt32 num = 0u;
    }
    unsigned int offset = length - 4;
    UInt32 num3 = LoadUInt(first) - LoadUInt(second);
    num3 |= LoadUInt(first, offset) - LoadUInt(second, offset);
    return num3 == 0;
  }
  if (Unsafe::AreSame(first, second)) {
  }
  unsigned int num5;
  unsigned int num7;
  unsigned int num9;
  Vector256<Byte> value;
  Vector128<Byte> value2;
  if (Sse2::in::get_IsSupported()) {
    if (Avx2::in::get_IsSupported() && length >= (unsigned int)Vector256<Byte>::get_Count()) {
      unsigned int num4 = 0u;
      num5 = length - (unsigned int)Vector256<Byte>::get_Count();
      if (num5 == 0) {
      }
      while (true) {
        value = Avx2::in::CompareEqual(LoadVector256(first, num4), LoadVector256(second, num4));
        if (Avx2::in::MoveMask(value) != -1) {
          break;
        }
        num4 += (unsigned int)Vector256<Byte>::get_Count();
        if (num5 > num4) {
        }
      }
    } else {
      if (length < 16) {
      }
      unsigned int num6 = 0u;
      num7 = length - 16;
      if (num7 == 0) {
      }
      while (true) {
        value2 = Sse2::in::CompareEqual(LoadVector128(first, num6), LoadVector128(second, num6));
        if (Sse2::in::MoveMask(value2) != 65535) {
          break;
        }
        num6 += 16;
        if (num7 > num6) {
        }
      }
    }
  } else {
    if (!Vector::get_IsHardwareAccelerated() || length < (unsigned int)Vector<Byte>::get_Count()) {
    }
    unsigned int num8 = 0u;
    num9 = length - (unsigned int)Vector<Byte>::get_Count();
    if (num9 == 0) {
    }
    while (!(LoadVector(first, num8) != LoadVector(second, num8))) {
      num8 += (unsigned int)Vector<Byte>::get_Count();
      if (num9 > num8) {
      }
    }
  }
}

Int32 SpanHelpers::LocateFirstFoundByte(Vector<Byte> match) {
  Vector<UInt64> vector = Vector::AsVectorUInt64(match);
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
  unsigned int num;
  UInt32 num6;
  unsigned int num3;
  unsigned int num2;
  if (!Unsafe::AreSame(first, second)) {
    num = (UInt32)(((UInt32)firstLength < (UInt32)secondLength) ? firstLength : secondLength);
    num2 = 0u;
    num3 = num;
    if (!Avx2::in::get_IsSupported()) {
      if (Sse2::in::get_IsSupported()) {
        if (num3 >= (unsigned int)Vector128<Byte>::get_Count()) {
          num3 -= (unsigned int)Vector128<Byte>::get_Count();
          while (true) {
            UInt32 num4;
            if (num3 > num2) {
              num4 = (UInt32)Sse2::in::MoveMask(Sse2::in::CompareEqual(LoadVector128(first, num2), LoadVector128(second, num2)));
              if (num4 == 65535) {
                num2 += (unsigned int)Vector128<Byte>::get_Count();
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
        }
      } else if (Vector::get_IsHardwareAccelerated() && num3 > (unsigned int)Vector<Byte>::get_Count()) {
        for (num3 -= (unsigned int)Vector<Byte>::get_Count(); num3 > num2 && !(LoadVector(first, num2) != LoadVector(second, num2)); num2 += (unsigned int)Vector<Byte>::get_Count()) {
        }
      }

    }
    if (num3 >= (unsigned int)Vector256<Byte>::get_Count()) {
      num3 -= (unsigned int)Vector256<Byte>::get_Count();
      while (true) {
        UInt32 num5;
        if (num3 > num2) {
          num5 = (UInt32)Avx2::in::MoveMask(Avx2::in::CompareEqual(LoadVector256(first, num2), LoadVector256(second, num2)));
          if (num5 == UInt32::MaxValue) {
            num2 += (unsigned int)Vector256<Byte>::get_Count();
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
      if (num3 < (unsigned int)Vector128<Byte>::get_Count()) {
      }
      num3 -= (unsigned int)Vector128<Byte>::get_Count();
      if (num3 > num2) {
        num6 = (UInt32)Sse2::in::MoveMask(Sse2::in::CompareEqual(LoadVector128(first, num2), LoadVector128(second, num2)));
        if (num6 != 65535) {
        }
      }
      num2 = num3;
      num6 = (UInt32)Sse2::in::MoveMask(Sse2::in::CompareEqual(LoadVector128(first, num2), LoadVector128(second, num2)));
      if (num6 != 65535) {
      }
    }
  }
}

Int32 SpanHelpers::LocateLastFoundByte(Vector<Byte> match) {
  Vector<UInt64> vector = Vector::AsVectorUInt64(match);
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

UInt32 SpanHelpers::LoadUInt(Byte& start, unsigned int offset) {
  return Unsafe::ReadUnaligned<UInt32>(Unsafe::AddByteOffset(start, offset));
}

unsigned int SpanHelpers::LoadNUInt(Byte& start) {
  return Unsafe::ReadUnaligned<UIntPtr>(start);
}

unsigned int SpanHelpers::LoadNUInt(Byte& start, unsigned int offset) {
  return Unsafe::ReadUnaligned<UIntPtr>(Unsafe::AddByteOffset(start, offset));
}

Vector<Byte> SpanHelpers::LoadVector(Byte& start, unsigned int offset) {
  return Unsafe::ReadUnaligned<Vector<Byte>>(Unsafe::AddByteOffset(start, offset));
}

Vector128<Byte> SpanHelpers::LoadVector128(Byte& start, unsigned int offset) {
  return Unsafe::ReadUnaligned<Vector128<Byte>>(Unsafe::AddByteOffset(start, offset));
}

Vector256<Byte> SpanHelpers::LoadVector256(Byte& start, unsigned int offset) {
  return Unsafe::ReadUnaligned<Vector256<Byte>>(Unsafe::AddByteOffset(start, offset));
}

unsigned int SpanHelpers::GetByteVectorSpanLength(unsigned int offset, Int32 length) {
}

unsigned int SpanHelpers::GetByteVector128SpanLength(unsigned int offset, Int32 length) {
}

unsigned int SpanHelpers::GetByteVector256SpanLength(unsigned int offset, Int32 length) {
}

unsigned int SpanHelpers::UnalignedCountVector(Byte& searchSpace) {
}

unsigned int SpanHelpers::UnalignedCountVector128(Byte& searchSpace) {
}

unsigned int SpanHelpers::UnalignedCountVectorFromEnd(Byte& searchSpace, Int32 length) {
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
    if (SequenceEqual(Unsafe::As<Char, Byte>(Unsafe::Add(searchSpace, num3 + 1)), Unsafe::As<Char, Byte>(source), (unsigned int)(UInt32)num * (?)2u)) {
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
    unsigned int num = (UInt32)(((UInt32)firstLength < (UInt32)secondLength) ? firstLength : secondLength);
    unsigned int num2 = 0u;
    if (num >= (unsigned int)(sizeof(UIntPtr) / 2)) {
      if (Vector::get_IsHardwareAccelerated() && num >= (unsigned int)Vector<UInt16>::get_Count()) {
        unsigned int num3 = num - (unsigned int)Vector<UInt16>::get_Count();
        while (!(Unsafe::ReadUnaligned<Vector<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(first, (int)num2))) != Unsafe::ReadUnaligned<Vector<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(second, (int)num2))))) {
          num2 += (unsigned int)Vector<UInt16>::get_Count();
          if (num3 < num2) {
            break;
          }
        }
      }
      for (; num >= (unsigned int)((int)num2 + (int)(sizeof(UIntPtr) / 2)) && Unsafe::ReadUnaligned<UIntPtr>(Unsafe::As<Char, Byte>(Unsafe::Add(first, (int)num2))) == Unsafe::ReadUnaligned<UIntPtr>(Unsafe::As<Char, Byte>(Unsafe::Add(second, (int)num2))); num2 += (unsigned int)(sizeof(UIntPtr) / 2)) {
      }
    }
    if (num >= num2 + 2 && Unsafe::ReadUnaligned<Int32>(Unsafe::As<Char, Byte>(Unsafe::Add(first, (int)num2))) == Unsafe::ReadUnaligned<Int32>(Unsafe::As<Char, Byte>(Unsafe::Add(second, (int)num2)))) {
      num2 += 2;
    }
    for (; num2 < num; num2++) {
      Int32 num4 = Unsafe::Add(first, (int)num2).CompareTo(Unsafe::Add(second, (int)num2));
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
    if (Vector::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
    }
    while (true) {
      if (length >= 4) {
        length -= 4;
        if (value == *ptr2 || value == ptr2[1] || value == ptr2[2] || value == ptr2[3]) {
          break;
        }
        ptr2 += 4;
      }
      while (length > 0) {
        length--;
        if (value == *ptr2) {
        }
        ptr2++;
      }
      if (Vector::get_IsHardwareAccelerated() && ptr2 < ptr3) {
      }
      return false;
    }
    return true;
  }
}

Int32 SpanHelpers::IndexOf(Char& searchSpace, Char value, Int32 length) {
  int num = 0;
  int num2 = length;
}

Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Int32 length) {
  {
    Char* ptr = &searchSpace;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2 + length;
    if (Vector::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
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
        }
        ptr2++;
      }
      if (Vector::get_IsHardwareAccelerated() && ptr2 < ptr3) {
      }
      return -1;
    }
    return (Int32)(ptr2 - ptr);
  }
}

Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Int32 length) {
  {
    Char* ptr = &searchSpace;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2 + length;
    if (Vector::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
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
        }
        ptr2++;
      }
      if (Vector::get_IsHardwareAccelerated() && ptr2 < ptr3) {
      }
      return -1;
    }
    return (Int32)(ptr2 - ptr);
  }
}

Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Char value3, Int32 length) {
  {
    Char* ptr = &searchSpace;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2 + length;
    if (Vector::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
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
        }
        ptr2++;
      }
      if (Vector::get_IsHardwareAccelerated() && ptr2 < ptr3) {
      }
      return -1;
    }
    return (Int32)(ptr2 - ptr);
  }
}

Int32 SpanHelpers::IndexOfAny(Char& searchSpace, Char value0, Char value1, Char value2, Char value3, Char value4, Int32 length) {
  {
    Char* ptr = &searchSpace;
    Char* ptr2 = ptr;
    Char* ptr3 = ptr2 + length;
    if (Vector::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
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
        }
        ptr2++;
      }
      if (Vector::get_IsHardwareAccelerated() && ptr2 < ptr3) {
      }
      return -1;
    }
    return (Int32)(ptr2 - ptr);
  }
}

Int32 SpanHelpers::LastIndexOf(Char& searchSpace, Char value, Int32 length) {
  {
    Char* ptr = &searchSpace;
    Char* ptr2 = ptr + length;
    Char* ptr3 = ptr;
    if (Vector::get_IsHardwareAccelerated() && length >= Vector<UInt16>::get_Count() * 2) {
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
            }
          }
          return (Int32)(ptr2 - ptr3) + 1;
        }
        return (Int32)(ptr2 - ptr3) + 2;
      }
      while (length > 0) {
        length--;
        ptr2--;
        if (*ptr2 != value) {
        }
      }
      if (Vector::get_IsHardwareAccelerated() && ptr2 > ptr3) {
      }
      return -1;
    }
    return (Int32)(ptr2 - ptr3) + 3;
  }
}

Int32 SpanHelpers::LocateFirstFoundChar(Vector<UInt16> match) {
  Vector<UInt64> vector = Vector::AsVectorUInt64(match);
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
  Vector<UInt64> vector = Vector::AsVectorUInt64(match);
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

Vector<UInt16> SpanHelpers::LoadVector(Char& start, int offset) {
  return Unsafe::ReadUnaligned<Vector<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(start, offset)));
}

Vector128<UInt16> SpanHelpers::LoadVector128(Char& start, int offset) {
  return Unsafe::ReadUnaligned<Vector128<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(start, offset)));
}

Vector256<UInt16> SpanHelpers::LoadVector256(Char& start, int offset) {
  return Unsafe::ReadUnaligned<Vector256<UInt16>>(Unsafe::As<Char, Byte>(Unsafe::Add(start, offset)));
}

int SpanHelpers::GetCharVectorSpanLength(int offset, int length) {
}

int SpanHelpers::GetCharVector128SpanLength(int offset, int length) {
}

int SpanHelpers::GetCharVector256SpanLength(int offset, int length) {
}

int SpanHelpers::UnalignedCountVector(Char& searchSpace) {
}

int SpanHelpers::UnalignedCountVector128(Char& searchSpace) {
}

void SpanHelpers::ClearWithoutReferences(Byte& b, unsigned int byteLength) {
  if (byteLength != 0) {
    if (byteLength <= 768) {
      Unsafe::InitBlockUnaligned(b, 0, (UInt32)byteLength);
    } else {
      Buffer::_ZeroMemory(b, byteLength);
    }
  }
}

void SpanHelpers::ClearWithReferences(IntPtr& ip, unsigned int pointerSizeLength) {
  while (pointerSizeLength >= 8) {
    Unsafe::Add(Unsafe::Add(ip, (int)pointerSizeLength), -1) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (int)pointerSizeLength), -2) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (int)pointerSizeLength), -3) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (int)pointerSizeLength), -4) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (int)pointerSizeLength), -5) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (int)pointerSizeLength), -6) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (int)pointerSizeLength), -7) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (int)pointerSizeLength), -8) = IntPtr();
    pointerSizeLength -= 8;
  }
  if (pointerSizeLength < 4) {
    if (pointerSizeLength < 2) {
      if (pointerSizeLength == 0) {
        return;
      }
    }
  } else {
    Unsafe::Add(ip, 2) = IntPtr();
    Unsafe::Add(ip, 3) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (int)pointerSizeLength), -3) = IntPtr();
    Unsafe::Add(Unsafe::Add(ip, (int)pointerSizeLength), -2) = IntPtr();
  }
  Unsafe::Add(ip, 1) = IntPtr();
  Unsafe::Add(Unsafe::Add(ip, (int)pointerSizeLength), -1) = IntPtr();
}

} // namespace System::Private::CoreLib::System::SpanHelpersNamespace
