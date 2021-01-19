#include "MathF-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/BitConverter-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/MidpointRounding.h>
#include <System.Private.CoreLib/System/Numerics/VectorMath-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Arm/AdvSimd-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::MathFNamespace {
using namespace System::Numerics;
using namespace System::Runtime::Intrinsics;
using namespace System::Runtime::Intrinsics::Arm;
using namespace System::Runtime::Intrinsics::X86;

Single MathF::Abs(Single x) {
  return Math::Abs(x);
}

Single MathF::BitDecrement(Single x) {
  Int32 num = BitConverter::SingleToInt32Bits(x);
  if ((num & 2139095040) >= 2139095040) {
    if (num != 2139095040) {
      return x;
    }
    return Single::MaxValue;
  }
  if (num == 0) {
    return -1E-45;
  }
  num += ((num < 0) ? 1 : (-1));
  return BitConverter::Int32BitsToSingle(num);
}

Single MathF::BitIncrement(Single x) {
  Int32 num = BitConverter::SingleToInt32Bits(x);
  if ((num & 2139095040) >= 2139095040) {
    if (num != -8388608) {
      return x;
    }
    return Single::MinValue;
  }
  if (num == Int32::MinValue) {
    return Single::Epsilon;
  }
  num += ((num >= 0) ? 1 : (-1));
  return BitConverter::Int32BitsToSingle(num);
}

Single MathF::CopySign(Single x, Single y) {
  auto SoftwareFallback = [](Single x, Single y) -> Single {
    Int32 num = BitConverter::SingleToInt32Bits(x);
    Int32 num2 = BitConverter::SingleToInt32Bits(y);
    num &= 2147483647;
    num2 &= Int32::MinValue;
    return BitConverter::Int32BitsToSingle(num | num2);
  };
  if (Sse::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Vector128<>::ToScalar(VectorMath::ConditionalSelectBitwise(Vector128<>::CreateScalarUnsafe(-0), Vector128<>::CreateScalarUnsafe(y), Vector128<>::CreateScalarUnsafe(x)));
  }
  return SoftwareFallback(x, y);
}

Single MathF::IEEERemainder(Single x, Single y) {
  if (Single::IsNaN(x)) {
    return x;
  }
  if (Single::IsNaN(y)) {
    return y;
  }
  Single num = x % y;
  if (Single::IsNaN(num)) {
    return Single::NaN;
  }
  if (num == 0 && Single::IsNegative(x)) {
    return -0;
  }
  Single num2 = num - Abs(y) * (Single)Sign(x);
  if (Abs(num2) == Abs(num)) {
    Single x2 = x / y;
    Single x3 = Round(x2);
    if (Abs(x3) > Abs(x2)) {
      return num2;
    }
    return num;
  }
  if (Abs(num2) < Abs(num)) {
    return num2;
  }
  return num;
}

Single MathF::Log(Single x, Single y) {
  if (Single::IsNaN(x)) {
    return x;
  }
  if (Single::IsNaN(y)) {
    return y;
  }
  if (y == 1) {
    return Single::NaN;
  }
  if (x != 1 && (y == 0 || Single::IsPositiveInfinity(y))) {
    return Single::NaN;
  }
  return Log(x) / Log(y);
}

Single MathF::Max(Single x, Single y) {
  return Math::Max(x, y);
}

Single MathF::MaxMagnitude(Single x, Single y) {
  Single num = Abs(x);
  Single num2 = Abs(y);
  if (num > num2 || Single::IsNaN(num)) {
    return x;
  }
  if (num == num2) {
    if (!Single::IsNegative(x)) {
      return x;
    }
    return y;
  }
  return y;
}

Single MathF::Min(Single x, Single y) {
  return Math::Min(x, y);
}

Single MathF::MinMagnitude(Single x, Single y) {
  Single num = Abs(x);
  Single num2 = Abs(y);
  if (num < num2 || Single::IsNaN(num)) {
    return x;
  }
  if (num == num2) {
    if (!Single::IsNegative(x)) {
      return y;
    }
    return x;
  }
  return y;
}

Single MathF::Round(Single x) {
  UInt32 num = (UInt32)BitConverter::SingleToInt32Bits(x);
  Int32 num2 = Single::ExtractExponentFromBits(num);
  if (num2 <= 126) {
    if (num << 1 == 0) {
      return x;
    }
    Single x2 = ((num2 == 126 && Single::ExtractSignificandFromBits(num) != 0) ? 1 : 0);
    return CopySign(x2, x);
  }
  if (num2 >= 150) {
    return x;
  }
  UInt32 num3 = (UInt32)(1 << 150 - num2);
  UInt32 num4 = num3 - 1;
  num += num3 >> 1;
  num = (((num & num4) != 0) ? (num & ~num4) : (num & ~num3));
  return BitConverter::Int32BitsToSingle((Int32)num);
}

Single MathF::Round(Single x, Int32 digits) {
  return Round(x, digits, MidpointRounding::ToEven);
}

Single MathF::Round(Single x, MidpointRounding mode) {
  return Round(x, 0, mode);
}

Single MathF::Round(Single x, Int32 digits, MidpointRounding mode) {
  if (digits < 0 || digits > 6) {
    rt::throw_exception<ArgumentOutOfRangeException>("digits", SR::get_ArgumentOutOfRange_RoundingDigits());
  }
  if (mode < MidpointRounding::ToEven || mode > MidpointRounding::ToPositiveInfinity) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidEnumValue(), mode, "MidpointRounding"), "mode");
  }
  if (Abs(x) < 100000000) {
    Single num = roundPower10Single[digits];
    x *= num;
    switch (mode) {
      case MidpointRounding::ToEven:
        x = Round(x);
        break;
      case MidpointRounding::AwayFromZero:
        {
          Single x2 = ModF(x, &x);
          if ((Double)Abs(x2) >= 0.5) {
            x += (Single)Sign(x2);
          }
          break;
        }case MidpointRounding::ToZero:
        x = Truncate(x);
        break;
      case MidpointRounding::ToNegativeInfinity:
        x = Floor(x);
        break;
      case MidpointRounding::ToPositiveInfinity:
        x = Ceiling(x);
        break;
      default:
        rt::throw_exception<ArgumentException>(SR::Format(SR::get_Argument_InvalidEnumValue(), mode, "MidpointRounding"), "mode");
    }
    x /= num;
  }
  return x;
}

Int32 MathF::Sign(Single x) {
  return Math::Sign(x);
}

Single MathF::Truncate(Single x) {
  ModF(x, &x);
  return x;
}

void MathF::cctor() {
  roundPower10Single = rt::newarr<Array<Single>>(7);
}

Single MathF::_CopySign_g__SoftwareFallback36_0(Single x, Single y) {
  Int32 num = BitConverter::SingleToInt32Bits(x);
  Int32 num2 = BitConverter::SingleToInt32Bits(y);
  num &= 2147483647;
  num2 &= Int32::MinValue;
  return BitConverter::Int32BitsToSingle(num | num2);
}

} // namespace System::Private::CoreLib::System::MathFNamespace
