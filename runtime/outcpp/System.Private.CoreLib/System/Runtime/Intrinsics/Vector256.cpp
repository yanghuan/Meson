#include "Vector256-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector256-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Avx-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>

namespace System::Private::CoreLib::System::Runtime::Intrinsics::Vector256Namespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::Intrinsics::X86;

Vector256<Byte> Vector256<>::Create(Byte value) {
  auto SoftwareFallback = [](Byte value) -> Vector256<Byte> {
    Byte as[32] = {};
    Byte* source = as;
    return Unsafe::AsRef<Vector256<Byte>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector256<Double> Vector256<>::Create(Double value) {
  auto SoftwareFallback = [](Double value) -> Vector256<Double> {
    Double as[4] = {};
    Double* source = as;
    return Unsafe::AsRef<Vector256<Double>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector256<Int16> Vector256<>::Create(Int16 value) {
  auto SoftwareFallback = [](Int16 value) -> Vector256<Int16> {
    Int16 as[16] = {};
    Int16* source = as;
    return Unsafe::AsRef<Vector256<Int16>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector256<Int32> Vector256<>::Create(Int32 value) {
  auto SoftwareFallback = [](Int32 value) -> Vector256<Int32> {
    Int32 as[8] = {};
    Int32* source = as;
    return Unsafe::AsRef<Vector256<Int32>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector256<Int64> Vector256<>::Create(Int64 value) {
  auto SoftwareFallback = [](Int64 value) -> Vector256<Int64> {
    Int64 as[4] = {};
    Int64* source = as;
    return Unsafe::AsRef<Vector256<Int64>>(source);
  };
  if (Sse2::in::X64::in::get_IsSupported() && Avx::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector256<SByte> Vector256<>::Create(SByte value) {
  auto SoftwareFallback = [](SByte value) -> Vector256<SByte> {
    SByte as[32] = {};
    SByte* source = as;
    return Unsafe::AsRef<Vector256<SByte>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector256<Single> Vector256<>::Create(Single value) {
  auto SoftwareFallback = [](Single value) -> Vector256<Single> {
    Single as[8] = {};
    Single* source = as;
    return Unsafe::AsRef<Vector256<Single>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector256<UInt16> Vector256<>::Create(UInt16 value) {
  auto SoftwareFallback = [](UInt16 value) -> Vector256<UInt16> {
    UInt16 as[16] = {};
    UInt16* source = as;
    return Unsafe::AsRef<Vector256<UInt16>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector256<UInt32> Vector256<>::Create(UInt32 value) {
  auto SoftwareFallback = [](UInt32 value) -> Vector256<UInt32> {
    UInt32 as[8] = {};
    UInt32* source = as;
    return Unsafe::AsRef<Vector256<UInt32>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector256<UInt64> Vector256<>::Create(UInt64 value) {
  auto SoftwareFallback = [](UInt64 value) -> Vector256<UInt64> {
    UInt64 as[4] = {};
    UInt64* source = as;
    return Unsafe::AsRef<Vector256<UInt64>>(source);
  };
  if (Sse2::in::X64::in::get_IsSupported() && Avx::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector256<Byte> Vector256<>::Create(Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7, Byte e8, Byte e9, Byte e10, Byte e11, Byte e12, Byte e13, Byte e14, Byte e15, Byte e16, Byte e17, Byte e18, Byte e19, Byte e20, Byte e21, Byte e22, Byte e23, Byte e24, Byte e25, Byte e26, Byte e27, Byte e28, Byte e29, Byte e30, Byte e31) {
  auto SoftwareFallback = [](Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7, Byte e8, Byte e9, Byte e10, Byte e11, Byte e12, Byte e13, Byte e14, Byte e15, Byte e16, Byte e17, Byte e18, Byte e19, Byte e20, Byte e21, Byte e22, Byte e23, Byte e24, Byte e25, Byte e26, Byte e27, Byte e28, Byte e29, Byte e30, Byte e31) -> Vector256<Byte> {
    Byte as[32] = {};
    Byte* source = as;
    return Unsafe::AsRef<Vector256<Byte>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31);
}

Vector256<Double> Vector256<>::Create(Double e0, Double e1, Double e2, Double e3) {
  auto SoftwareFallback = [](Double e0, Double e1, Double e2, Double e3) -> Vector256<Double> {
    Double as[4] = {};
    Double* source = as;
    return Unsafe::AsRef<Vector256<Double>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3);
  }
  return SoftwareFallback(e0, e1, e2, e3);
}

Vector256<Int16> Vector256<>::Create(Int16 e0, Int16 e1, Int16 e2, Int16 e3, Int16 e4, Int16 e5, Int16 e6, Int16 e7, Int16 e8, Int16 e9, Int16 e10, Int16 e11, Int16 e12, Int16 e13, Int16 e14, Int16 e15) {
  auto SoftwareFallback = [](Int16 e0, Int16 e1, Int16 e2, Int16 e3, Int16 e4, Int16 e5, Int16 e6, Int16 e7, Int16 e8, Int16 e9, Int16 e10, Int16 e11, Int16 e12, Int16 e13, Int16 e14, Int16 e15) -> Vector256<Int16> {
    Int16 as[16] = {};
    Int16* source = as;
    return Unsafe::AsRef<Vector256<Int16>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
}

Vector256<Int32> Vector256<>::Create(Int32 e0, Int32 e1, Int32 e2, Int32 e3, Int32 e4, Int32 e5, Int32 e6, Int32 e7) {
  auto SoftwareFallback = [](Int32 e0, Int32 e1, Int32 e2, Int32 e3, Int32 e4, Int32 e5, Int32 e6, Int32 e7) -> Vector256<Int32> {
    Int32 as[8] = {};
    Int32* source = as;
    return Unsafe::AsRef<Vector256<Int32>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7);
}

Vector256<Int64> Vector256<>::Create(Int64 e0, Int64 e1, Int64 e2, Int64 e3) {
  auto SoftwareFallback = [](Int64 e0, Int64 e1, Int64 e2, Int64 e3) -> Vector256<Int64> {
    Int64 as[4] = {};
    Int64* source = as;
    return Unsafe::AsRef<Vector256<Int64>>(source);
  };
  if (Sse2::in::X64::in::get_IsSupported() && Avx::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3);
  }
  return SoftwareFallback(e0, e1, e2, e3);
}

Vector256<SByte> Vector256<>::Create(SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7, SByte e8, SByte e9, SByte e10, SByte e11, SByte e12, SByte e13, SByte e14, SByte e15, SByte e16, SByte e17, SByte e18, SByte e19, SByte e20, SByte e21, SByte e22, SByte e23, SByte e24, SByte e25, SByte e26, SByte e27, SByte e28, SByte e29, SByte e30, SByte e31) {
  auto SoftwareFallback = [](SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7, SByte e8, SByte e9, SByte e10, SByte e11, SByte e12, SByte e13, SByte e14, SByte e15, SByte e16, SByte e17, SByte e18, SByte e19, SByte e20, SByte e21, SByte e22, SByte e23, SByte e24, SByte e25, SByte e26, SByte e27, SByte e28, SByte e29, SByte e30, SByte e31) -> Vector256<SByte> {
    SByte as[32] = {};
    SByte* source = as;
    return Unsafe::AsRef<Vector256<SByte>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31);
}

Vector256<Single> Vector256<>::Create(Single e0, Single e1, Single e2, Single e3, Single e4, Single e5, Single e6, Single e7) {
  auto SoftwareFallback = [](Single e0, Single e1, Single e2, Single e3, Single e4, Single e5, Single e6, Single e7) -> Vector256<Single> {
    Single as[8] = {};
    Single* source = as;
    return Unsafe::AsRef<Vector256<Single>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7);
}

Vector256<UInt16> Vector256<>::Create(UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3, UInt16 e4, UInt16 e5, UInt16 e6, UInt16 e7, UInt16 e8, UInt16 e9, UInt16 e10, UInt16 e11, UInt16 e12, UInt16 e13, UInt16 e14, UInt16 e15) {
  auto SoftwareFallback = [](UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3, UInt16 e4, UInt16 e5, UInt16 e6, UInt16 e7, UInt16 e8, UInt16 e9, UInt16 e10, UInt16 e11, UInt16 e12, UInt16 e13, UInt16 e14, UInt16 e15) -> Vector256<UInt16> {
    UInt16 as[16] = {};
    UInt16* source = as;
    return Unsafe::AsRef<Vector256<UInt16>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
}

Vector256<UInt32> Vector256<>::Create(UInt32 e0, UInt32 e1, UInt32 e2, UInt32 e3, UInt32 e4, UInt32 e5, UInt32 e6, UInt32 e7) {
  auto SoftwareFallback = [](UInt32 e0, UInt32 e1, UInt32 e2, UInt32 e3, UInt32 e4, UInt32 e5, UInt32 e6, UInt32 e7) -> Vector256<UInt32> {
    UInt32 as[8] = {};
    UInt32* source = as;
    return Unsafe::AsRef<Vector256<UInt32>>(source);
  };
  if (Avx::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7);
}

Vector256<UInt64> Vector256<>::Create(UInt64 e0, UInt64 e1, UInt64 e2, UInt64 e3) {
  auto SoftwareFallback = [](UInt64 e0, UInt64 e1, UInt64 e2, UInt64 e3) -> Vector256<UInt64> {
    UInt64 as[4] = {};
    UInt64* source = as;
    return Unsafe::AsRef<Vector256<UInt64>>(source);
  };
  if (Sse2::in::X64::in::get_IsSupported() && Avx::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3);
  }
  return SoftwareFallback(e0, e1, e2, e3);
}

Vector256<Byte> Vector256<>::Create(Vector128<Byte> lower, Vector128<Byte> upper) {
  auto SoftwareFallback = [](Vector128<Byte> lower, Vector128<Byte> upper) -> Vector256<Byte> {
    Vector256<Byte> source = Vector256<Byte>::get_Zero();
    Vector128<Byte>& reference = Unsafe::As<Vector256<Byte>, Vector128<Byte>>(source);
    reference = lower;
    Unsafe::Add(reference, 1) = upper;
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    Vector256<Byte> vector = Vector128<>::ToVector256Unsafe(lower);
    return Vector256<>::WithUpper(vector, upper);
  }
  return SoftwareFallback(lower, upper);
}

Vector256<Double> Vector256<>::Create(Vector128<Double> lower, Vector128<Double> upper) {
  auto SoftwareFallback = [](Vector128<Double> lower, Vector128<Double> upper) -> Vector256<Double> {
    Vector256<Double> source = Vector256<Double>::get_Zero();
    Vector128<Double>& reference = Unsafe::As<Vector256<Double>, Vector128<Double>>(source);
    reference = lower;
    Unsafe::Add(reference, 1) = upper;
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    Vector256<Double> vector = Vector128<>::ToVector256Unsafe(lower);
    return Vector256<>::WithUpper(vector, upper);
  }
  return SoftwareFallback(lower, upper);
}

Vector256<Int16> Vector256<>::Create(Vector128<Int16> lower, Vector128<Int16> upper) {
  auto SoftwareFallback = [](Vector128<Int16> lower, Vector128<Int16> upper) -> Vector256<Int16> {
    Vector256<Int16> source = Vector256<Int16>::get_Zero();
    Vector128<Int16>& reference = Unsafe::As<Vector256<Int16>, Vector128<Int16>>(source);
    reference = lower;
    Unsafe::Add(reference, 1) = upper;
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    Vector256<Int16> vector = Vector128<>::ToVector256Unsafe(lower);
    return Vector256<>::WithUpper(vector, upper);
  }
  return SoftwareFallback(lower, upper);
}

Vector256<Int32> Vector256<>::Create(Vector128<Int32> lower, Vector128<Int32> upper) {
  auto SoftwareFallback = [](Vector128<Int32> lower, Vector128<Int32> upper) -> Vector256<Int32> {
    Vector256<Int32> source = Vector256<Int32>::get_Zero();
    Vector128<Int32>& reference = Unsafe::As<Vector256<Int32>, Vector128<Int32>>(source);
    reference = lower;
    Unsafe::Add(reference, 1) = upper;
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    Vector256<Int32> vector = Vector128<>::ToVector256Unsafe(lower);
    return Vector256<>::WithUpper(vector, upper);
  }
  return SoftwareFallback(lower, upper);
}

Vector256<Int64> Vector256<>::Create(Vector128<Int64> lower, Vector128<Int64> upper) {
  auto SoftwareFallback = [](Vector128<Int64> lower, Vector128<Int64> upper) -> Vector256<Int64> {
    Vector256<Int64> source = Vector256<Int64>::get_Zero();
    Vector128<Int64>& reference = Unsafe::As<Vector256<Int64>, Vector128<Int64>>(source);
    reference = lower;
    Unsafe::Add(reference, 1) = upper;
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    Vector256<Int64> vector = Vector128<>::ToVector256Unsafe(lower);
    return Vector256<>::WithUpper(vector, upper);
  }
  return SoftwareFallback(lower, upper);
}

Vector256<SByte> Vector256<>::Create(Vector128<SByte> lower, Vector128<SByte> upper) {
  auto SoftwareFallback = [](Vector128<SByte> lower, Vector128<SByte> upper) -> Vector256<SByte> {
    Vector256<SByte> source = Vector256<SByte>::get_Zero();
    Vector128<SByte>& reference = Unsafe::As<Vector256<SByte>, Vector128<SByte>>(source);
    reference = lower;
    Unsafe::Add(reference, 1) = upper;
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    Vector256<SByte> vector = Vector128<>::ToVector256Unsafe(lower);
    return Vector256<>::WithUpper(vector, upper);
  }
  return SoftwareFallback(lower, upper);
}

Vector256<Single> Vector256<>::Create(Vector128<Single> lower, Vector128<Single> upper) {
  auto SoftwareFallback = [](Vector128<Single> lower, Vector128<Single> upper) -> Vector256<Single> {
    Vector256<Single> source = Vector256<Single>::get_Zero();
    Vector128<Single>& reference = Unsafe::As<Vector256<Single>, Vector128<Single>>(source);
    reference = lower;
    Unsafe::Add(reference, 1) = upper;
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    Vector256<Single> vector = Vector128<>::ToVector256Unsafe(lower);
    return Vector256<>::WithUpper(vector, upper);
  }
  return SoftwareFallback(lower, upper);
}

Vector256<UInt16> Vector256<>::Create(Vector128<UInt16> lower, Vector128<UInt16> upper) {
  auto SoftwareFallback = [](Vector128<UInt16> lower, Vector128<UInt16> upper) -> Vector256<UInt16> {
    Vector256<UInt16> source = Vector256<UInt16>::get_Zero();
    Vector128<UInt16>& reference = Unsafe::As<Vector256<UInt16>, Vector128<UInt16>>(source);
    reference = lower;
    Unsafe::Add(reference, 1) = upper;
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    Vector256<UInt16> vector = Vector128<>::ToVector256Unsafe(lower);
    return Vector256<>::WithUpper(vector, upper);
  }
  return SoftwareFallback(lower, upper);
}

Vector256<UInt32> Vector256<>::Create(Vector128<UInt32> lower, Vector128<UInt32> upper) {
  auto SoftwareFallback = [](Vector128<UInt32> lower, Vector128<UInt32> upper) -> Vector256<UInt32> {
    Vector256<UInt32> source = Vector256<UInt32>::get_Zero();
    Vector128<UInt32>& reference = Unsafe::As<Vector256<UInt32>, Vector128<UInt32>>(source);
    reference = lower;
    Unsafe::Add(reference, 1) = upper;
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    Vector256<UInt32> vector = Vector128<>::ToVector256Unsafe(lower);
    return Vector256<>::WithUpper(vector, upper);
  }
  return SoftwareFallback(lower, upper);
}

Vector256<UInt64> Vector256<>::Create(Vector128<UInt64> lower, Vector128<UInt64> upper) {
  auto SoftwareFallback = [](Vector128<UInt64> lower, Vector128<UInt64> upper) -> Vector256<UInt64> {
    Vector256<UInt64> source = Vector256<UInt64>::get_Zero();
    Vector128<UInt64>& reference = Unsafe::As<Vector256<UInt64>, Vector128<UInt64>>(source);
    reference = lower;
    Unsafe::Add(reference, 1) = upper;
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    Vector256<UInt64> vector = Vector128<>::ToVector256Unsafe(lower);
    return Vector256<>::WithUpper(vector, upper);
  }
  return SoftwareFallback(lower, upper);
}

Vector256<Byte> Vector256<>::CreateScalar(Byte value) {
  auto SoftwareFallback = [](Byte value) -> Vector256<Byte> {
    Vector256<Byte> source = Vector256<Byte>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector256<Byte>, Byte>(source), value);
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    return Vector128<>::ToVector256(Vector128<>::CreateScalar(value));
  }
  return SoftwareFallback(value);
}

Vector256<Double> Vector256<>::CreateScalar(Double value) {
  auto SoftwareFallback = [](Double value) -> Vector256<Double> {
    Vector256<Double> source = Vector256<Double>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector256<Double>, Byte>(source), value);
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    return Vector128<>::ToVector256(Vector128<>::CreateScalar(value));
  }
  return SoftwareFallback(value);
}

Vector256<Int16> Vector256<>::CreateScalar(Int16 value) {
  auto SoftwareFallback = [](Int16 value) -> Vector256<Int16> {
    Vector256<Int16> source = Vector256<Int16>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector256<Int16>, Byte>(source), value);
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    return Vector128<>::ToVector256(Vector128<>::CreateScalar(value));
  }
  return SoftwareFallback(value);
}

Vector256<Int32> Vector256<>::CreateScalar(Int32 value) {
  auto SoftwareFallback = [](Int32 value) -> Vector256<Int32> {
    Vector256<Int32> source = Vector256<Int32>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector256<Int32>, Byte>(source), value);
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    return Vector128<>::ToVector256(Vector128<>::CreateScalar(value));
  }
  return SoftwareFallback(value);
}

Vector256<Int64> Vector256<>::CreateScalar(Int64 value) {
  auto SoftwareFallback = [](Int64 value) -> Vector256<Int64> {
    Vector256<Int64> source = Vector256<Int64>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector256<Int64>, Byte>(source), value);
    return source;
  };
  if (Sse2::in::X64::in::get_IsSupported() && Avx::in::get_IsSupported()) {
    return Vector128<>::ToVector256(Vector128<>::CreateScalar(value));
  }
  return SoftwareFallback(value);
}

Vector256<SByte> Vector256<>::CreateScalar(SByte value) {
  auto SoftwareFallback = [](SByte value) -> Vector256<SByte> {
    Vector256<SByte> source = Vector256<SByte>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector256<SByte>, Byte>(source), value);
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    return Vector128<>::ToVector256(Vector128<>::CreateScalar(value));
  }
  return SoftwareFallback(value);
}

Vector256<Single> Vector256<>::CreateScalar(Single value) {
  auto SoftwareFallback = [](Single value) -> Vector256<Single> {
    Vector256<Single> source = Vector256<Single>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector256<Single>, Byte>(source), value);
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    return Vector128<>::ToVector256(Vector128<>::CreateScalar(value));
  }
  return SoftwareFallback(value);
}

Vector256<UInt16> Vector256<>::CreateScalar(UInt16 value) {
  auto SoftwareFallback = [](UInt16 value) -> Vector256<UInt16> {
    Vector256<UInt16> source = Vector256<UInt16>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector256<UInt16>, Byte>(source), value);
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    return Vector128<>::ToVector256(Vector128<>::CreateScalar(value));
  }
  return SoftwareFallback(value);
}

Vector256<UInt32> Vector256<>::CreateScalar(UInt32 value) {
  auto SoftwareFallback = [](UInt32 value) -> Vector256<UInt32> {
    Vector256<UInt32> source = Vector256<UInt32>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector256<UInt32>, Byte>(source), value);
    return source;
  };
  if (Avx::in::get_IsSupported()) {
    return Vector128<>::ToVector256(Vector128<>::CreateScalar(value));
  }
  return SoftwareFallback(value);
}

Vector256<UInt64> Vector256<>::CreateScalar(UInt64 value) {
  auto SoftwareFallback = [](UInt64 value) -> Vector256<UInt64> {
    Vector256<UInt64> source = Vector256<UInt64>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector256<UInt64>, Byte>(source), value);
    return source;
  };
  if (Sse2::in::X64::in::get_IsSupported() && Avx::in::get_IsSupported()) {
    return Vector128<>::ToVector256(Vector128<>::CreateScalar(value));
  }
  return SoftwareFallback(value);
}

Vector256<Byte> Vector256<>::CreateScalarUnsafe(Byte value) {
  Byte as[32] = {};
  Byte* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector256<Byte>>(ptr);
}

Vector256<Double> Vector256<>::CreateScalarUnsafe(Double value) {
  Double as[4] = {};
  Double* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector256<Double>>(ptr);
}

Vector256<Int16> Vector256<>::CreateScalarUnsafe(Int16 value) {
  Int16 as[16] = {};
  Int16* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector256<Int16>>(ptr);
}

Vector256<Int32> Vector256<>::CreateScalarUnsafe(Int32 value) {
  Int32 as[8] = {};
  Int32* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector256<Int32>>(ptr);
}

Vector256<Int64> Vector256<>::CreateScalarUnsafe(Int64 value) {
  Int64 as[4] = {};
  Int64* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector256<Int64>>(ptr);
}

Vector256<SByte> Vector256<>::CreateScalarUnsafe(SByte value) {
  SByte as[32] = {};
  SByte* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector256<SByte>>(ptr);
}

Vector256<Single> Vector256<>::CreateScalarUnsafe(Single value) {
  Single as[8] = {};
  Single* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector256<Single>>(ptr);
}

Vector256<UInt16> Vector256<>::CreateScalarUnsafe(UInt16 value) {
  UInt16 as[16] = {};
  UInt16* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector256<UInt16>>(ptr);
}

Vector256<UInt32> Vector256<>::CreateScalarUnsafe(UInt32 value) {
  UInt32 as[8] = {};
  UInt32* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector256<UInt32>>(ptr);
}

Vector256<UInt64> Vector256<>::CreateScalarUnsafe(UInt64 value) {
  UInt64 as[4] = {};
  UInt64* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector256<UInt64>>(ptr);
}

Vector256<Byte> Vector256<>::_Create_g__SoftwareFallback14_0(Byte value) {
  Byte as[32] = {};
  Byte* source = as;
  return Unsafe::AsRef<Vector256<Byte>>(source);
}

Vector256<Double> Vector256<>::_Create_g__SoftwareFallback15_0(Double value) {
  Double as[4] = {};
  Double* source = as;
  return Unsafe::AsRef<Vector256<Double>>(source);
}

Vector256<Int16> Vector256<>::_Create_g__SoftwareFallback16_0(Int16 value) {
  Int16 as[16] = {};
  Int16* source = as;
  return Unsafe::AsRef<Vector256<Int16>>(source);
}

Vector256<Int32> Vector256<>::_Create_g__SoftwareFallback17_0(Int32 value) {
  Int32 as[8] = {};
  Int32* source = as;
  return Unsafe::AsRef<Vector256<Int32>>(source);
}

Vector256<Int64> Vector256<>::_Create_g__SoftwareFallback18_0(Int64 value) {
  Int64 as[4] = {};
  Int64* source = as;
  return Unsafe::AsRef<Vector256<Int64>>(source);
}

Vector256<SByte> Vector256<>::_Create_g__SoftwareFallback19_0(SByte value) {
  SByte as[32] = {};
  SByte* source = as;
  return Unsafe::AsRef<Vector256<SByte>>(source);
}

Vector256<Single> Vector256<>::_Create_g__SoftwareFallback20_0(Single value) {
  Single as[8] = {};
  Single* source = as;
  return Unsafe::AsRef<Vector256<Single>>(source);
}

Vector256<UInt16> Vector256<>::_Create_g__SoftwareFallback21_0(UInt16 value) {
  UInt16 as[16] = {};
  UInt16* source = as;
  return Unsafe::AsRef<Vector256<UInt16>>(source);
}

Vector256<UInt32> Vector256<>::_Create_g__SoftwareFallback22_0(UInt32 value) {
  UInt32 as[8] = {};
  UInt32* source = as;
  return Unsafe::AsRef<Vector256<UInt32>>(source);
}

Vector256<UInt64> Vector256<>::_Create_g__SoftwareFallback23_0(UInt64 value) {
  UInt64 as[4] = {};
  UInt64* source = as;
  return Unsafe::AsRef<Vector256<UInt64>>(source);
}

Vector256<Byte> Vector256<>::_Create_g__SoftwareFallback24_0(Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7, Byte e8, Byte e9, Byte e10, Byte e11, Byte e12, Byte e13, Byte e14, Byte e15, Byte e16, Byte e17, Byte e18, Byte e19, Byte e20, Byte e21, Byte e22, Byte e23, Byte e24, Byte e25, Byte e26, Byte e27, Byte e28, Byte e29, Byte e30, Byte e31) {
  Byte as[32] = {};
  Byte* source = as;
  return Unsafe::AsRef<Vector256<Byte>>(source);
}

Vector256<Double> Vector256<>::_Create_g__SoftwareFallback25_0(Double e0, Double e1, Double e2, Double e3) {
  Double as[4] = {};
  Double* source = as;
  return Unsafe::AsRef<Vector256<Double>>(source);
}

Vector256<Int16> Vector256<>::_Create_g__SoftwareFallback26_0(Int16 e0, Int16 e1, Int16 e2, Int16 e3, Int16 e4, Int16 e5, Int16 e6, Int16 e7, Int16 e8, Int16 e9, Int16 e10, Int16 e11, Int16 e12, Int16 e13, Int16 e14, Int16 e15) {
  Int16 as[16] = {};
  Int16* source = as;
  return Unsafe::AsRef<Vector256<Int16>>(source);
}

Vector256<Int32> Vector256<>::_Create_g__SoftwareFallback27_0(Int32 e0, Int32 e1, Int32 e2, Int32 e3, Int32 e4, Int32 e5, Int32 e6, Int32 e7) {
  Int32 as[8] = {};
  Int32* source = as;
  return Unsafe::AsRef<Vector256<Int32>>(source);
}

Vector256<Int64> Vector256<>::_Create_g__SoftwareFallback28_0(Int64 e0, Int64 e1, Int64 e2, Int64 e3) {
  Int64 as[4] = {};
  Int64* source = as;
  return Unsafe::AsRef<Vector256<Int64>>(source);
}

Vector256<SByte> Vector256<>::_Create_g__SoftwareFallback29_0(SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7, SByte e8, SByte e9, SByte e10, SByte e11, SByte e12, SByte e13, SByte e14, SByte e15, SByte e16, SByte e17, SByte e18, SByte e19, SByte e20, SByte e21, SByte e22, SByte e23, SByte e24, SByte e25, SByte e26, SByte e27, SByte e28, SByte e29, SByte e30, SByte e31) {
  SByte as[32] = {};
  SByte* source = as;
  return Unsafe::AsRef<Vector256<SByte>>(source);
}

Vector256<Single> Vector256<>::_Create_g__SoftwareFallback30_0(Single e0, Single e1, Single e2, Single e3, Single e4, Single e5, Single e6, Single e7) {
  Single as[8] = {};
  Single* source = as;
  return Unsafe::AsRef<Vector256<Single>>(source);
}

Vector256<UInt16> Vector256<>::_Create_g__SoftwareFallback31_0(UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3, UInt16 e4, UInt16 e5, UInt16 e6, UInt16 e7, UInt16 e8, UInt16 e9, UInt16 e10, UInt16 e11, UInt16 e12, UInt16 e13, UInt16 e14, UInt16 e15) {
  UInt16 as[16] = {};
  UInt16* source = as;
  return Unsafe::AsRef<Vector256<UInt16>>(source);
}

Vector256<UInt32> Vector256<>::_Create_g__SoftwareFallback32_0(UInt32 e0, UInt32 e1, UInt32 e2, UInt32 e3, UInt32 e4, UInt32 e5, UInt32 e6, UInt32 e7) {
  UInt32 as[8] = {};
  UInt32* source = as;
  return Unsafe::AsRef<Vector256<UInt32>>(source);
}

Vector256<UInt64> Vector256<>::_Create_g__SoftwareFallback33_0(UInt64 e0, UInt64 e1, UInt64 e2, UInt64 e3) {
  UInt64 as[4] = {};
  UInt64* source = as;
  return Unsafe::AsRef<Vector256<UInt64>>(source);
}

Vector256<Byte> Vector256<>::_Create_g__SoftwareFallback34_0(Vector128<Byte> lower, Vector128<Byte> upper) {
  Vector256<Byte> source = Vector256<Byte>::get_Zero();
  Vector128<Byte>& reference = Unsafe::As<Vector256<Byte>, Vector128<Byte>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector256<Double> Vector256<>::_Create_g__SoftwareFallback35_0(Vector128<Double> lower, Vector128<Double> upper) {
  Vector256<Double> source = Vector256<Double>::get_Zero();
  Vector128<Double>& reference = Unsafe::As<Vector256<Double>, Vector128<Double>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector256<Int16> Vector256<>::_Create_g__SoftwareFallback36_0(Vector128<Int16> lower, Vector128<Int16> upper) {
  Vector256<Int16> source = Vector256<Int16>::get_Zero();
  Vector128<Int16>& reference = Unsafe::As<Vector256<Int16>, Vector128<Int16>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector256<Int32> Vector256<>::_Create_g__SoftwareFallback37_0(Vector128<Int32> lower, Vector128<Int32> upper) {
  Vector256<Int32> source = Vector256<Int32>::get_Zero();
  Vector128<Int32>& reference = Unsafe::As<Vector256<Int32>, Vector128<Int32>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector256<Int64> Vector256<>::_Create_g__SoftwareFallback38_0(Vector128<Int64> lower, Vector128<Int64> upper) {
  Vector256<Int64> source = Vector256<Int64>::get_Zero();
  Vector128<Int64>& reference = Unsafe::As<Vector256<Int64>, Vector128<Int64>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector256<SByte> Vector256<>::_Create_g__SoftwareFallback39_0(Vector128<SByte> lower, Vector128<SByte> upper) {
  Vector256<SByte> source = Vector256<SByte>::get_Zero();
  Vector128<SByte>& reference = Unsafe::As<Vector256<SByte>, Vector128<SByte>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector256<Single> Vector256<>::_Create_g__SoftwareFallback40_0(Vector128<Single> lower, Vector128<Single> upper) {
  Vector256<Single> source = Vector256<Single>::get_Zero();
  Vector128<Single>& reference = Unsafe::As<Vector256<Single>, Vector128<Single>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector256<UInt16> Vector256<>::_Create_g__SoftwareFallback41_0(Vector128<UInt16> lower, Vector128<UInt16> upper) {
  Vector256<UInt16> source = Vector256<UInt16>::get_Zero();
  Vector128<UInt16>& reference = Unsafe::As<Vector256<UInt16>, Vector128<UInt16>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector256<UInt32> Vector256<>::_Create_g__SoftwareFallback42_0(Vector128<UInt32> lower, Vector128<UInt32> upper) {
  Vector256<UInt32> source = Vector256<UInt32>::get_Zero();
  Vector128<UInt32>& reference = Unsafe::As<Vector256<UInt32>, Vector128<UInt32>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector256<UInt64> Vector256<>::_Create_g__SoftwareFallback43_0(Vector128<UInt64> lower, Vector128<UInt64> upper) {
  Vector256<UInt64> source = Vector256<UInt64>::get_Zero();
  Vector128<UInt64>& reference = Unsafe::As<Vector256<UInt64>, Vector128<UInt64>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector256<Byte> Vector256<>::_CreateScalar_g__SoftwareFallback44_0(Byte value) {
  Vector256<Byte> source = Vector256<Byte>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector256<Byte>, Byte>(source), value);
  return source;
}

Vector256<Double> Vector256<>::_CreateScalar_g__SoftwareFallback45_0(Double value) {
  Vector256<Double> source = Vector256<Double>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector256<Double>, Byte>(source), value);
  return source;
}

Vector256<Int16> Vector256<>::_CreateScalar_g__SoftwareFallback46_0(Int16 value) {
  Vector256<Int16> source = Vector256<Int16>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector256<Int16>, Byte>(source), value);
  return source;
}

Vector256<Int32> Vector256<>::_CreateScalar_g__SoftwareFallback47_0(Int32 value) {
  Vector256<Int32> source = Vector256<Int32>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector256<Int32>, Byte>(source), value);
  return source;
}

Vector256<Int64> Vector256<>::_CreateScalar_g__SoftwareFallback48_0(Int64 value) {
  Vector256<Int64> source = Vector256<Int64>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector256<Int64>, Byte>(source), value);
  return source;
}

Vector256<SByte> Vector256<>::_CreateScalar_g__SoftwareFallback49_0(SByte value) {
  Vector256<SByte> source = Vector256<SByte>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector256<SByte>, Byte>(source), value);
  return source;
}

Vector256<Single> Vector256<>::_CreateScalar_g__SoftwareFallback50_0(Single value) {
  Vector256<Single> source = Vector256<Single>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector256<Single>, Byte>(source), value);
  return source;
}

Vector256<UInt16> Vector256<>::_CreateScalar_g__SoftwareFallback51_0(UInt16 value) {
  Vector256<UInt16> source = Vector256<UInt16>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector256<UInt16>, Byte>(source), value);
  return source;
}

Vector256<UInt32> Vector256<>::_CreateScalar_g__SoftwareFallback52_0(UInt32 value) {
  Vector256<UInt32> source = Vector256<UInt32>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector256<UInt32>, Byte>(source), value);
  return source;
}

Vector256<UInt64> Vector256<>::_CreateScalar_g__SoftwareFallback53_0(UInt64 value) {
  Vector256<UInt64> source = Vector256<UInt64>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector256<UInt64>, Byte>(source), value);
  return source;
}

} // namespace System::Private::CoreLib::System::Runtime::Intrinsics::Vector256Namespace
