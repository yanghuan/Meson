#include "Vector128-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector4-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Arm/AdvSimd-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector128-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>

namespace System::Private::CoreLib::System::Runtime::Intrinsics::Vector128Namespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Numerics;
using namespace System::Runtime::Intrinsics::Arm;
using namespace System::Runtime::Intrinsics::X86;

Vector128<Single> Vector128<>::AsVector128(Vector2 value) {
  return Vector128<>::AsVector128(Vector4(value, 0, 0));
}

Vector128<Single> Vector128<>::AsVector128(Vector3 value) {
  return Vector128<>::AsVector128(Vector4(value, 0));
}

Vector128<Single> Vector128<>::AsVector128(Vector4 value) {
  return Unsafe::As<Vector4, Vector128<Single>>(value);
}

Vector2 Vector128<>::AsVector2(Vector128<Single> value) {
  return Unsafe::As<Vector128<Single>, Vector2>(value);
}

Vector3 Vector128<>::AsVector3(Vector128<Single> value) {
  return Unsafe::As<Vector128<Single>, Vector3>(value);
}

Vector4 Vector128<>::AsVector4(Vector128<Single> value) {
  return Unsafe::As<Vector128<Single>, Vector4>(value);
}

Vector128<Byte> Vector128<>::Create(Byte value) {
  auto SoftwareFallback = [](Byte value) -> Vector128<Byte> {
    Byte as[16] = {};
    Byte* source = as;
    return Unsafe::AsRef<Vector128<Byte>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector128<Double> Vector128<>::Create(Double value) {
  auto SoftwareFallback = [](Double value) -> Vector128<Double> {
    Double as[2] = {};
    Double* source = as;
    return Unsafe::AsRef<Vector128<Double>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector128<Int16> Vector128<>::Create(Int16 value) {
  auto SoftwareFallback = [](Int16 value) -> Vector128<Int16> {
    Int16 as[8] = {};
    Int16* source = as;
    return Unsafe::AsRef<Vector128<Int16>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector128<Int32> Vector128<>::Create(Int32 value) {
  auto SoftwareFallback = [](Int32 value) -> Vector128<Int32> {
    Int32 as[4] = {};
    Int32* source = as;
    return Unsafe::AsRef<Vector128<Int32>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector128<Int64> Vector128<>::Create(Int64 value) {
  auto SoftwareFallback = [](Int64 value) -> Vector128<Int64> {
    Int64 as[2] = {};
    Int64* source = as;
    return Unsafe::AsRef<Vector128<Int64>>(source);
  };
  if (Sse2::in::X64::in::get_IsSupported() || AdvSimd::in::Arm64::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector128<SByte> Vector128<>::Create(SByte value) {
  auto SoftwareFallback = [](SByte value) -> Vector128<SByte> {
    SByte as[16] = {};
    SByte* source = as;
    return Unsafe::AsRef<Vector128<SByte>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector128<Single> Vector128<>::Create(Single value) {
  auto SoftwareFallback = [](Single value) -> Vector128<Single> {
    Single as[4] = {};
    Single* source = as;
    return Unsafe::AsRef<Vector128<Single>>(source);
  };
  if (Sse::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector128<UInt16> Vector128<>::Create(UInt16 value) {
  auto SoftwareFallback = [](UInt16 value) -> Vector128<UInt16> {
    UInt16 as[8] = {};
    UInt16* source = as;
    return Unsafe::AsRef<Vector128<UInt16>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector128<UInt32> Vector128<>::Create(UInt32 value) {
  auto SoftwareFallback = [](UInt32 value) -> Vector128<UInt32> {
    UInt32 as[4] = {};
    UInt32* source = as;
    return Unsafe::AsRef<Vector128<UInt32>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector128<UInt64> Vector128<>::Create(UInt64 value) {
  auto SoftwareFallback = [](UInt64 value) -> Vector128<UInt64> {
    UInt64 as[2] = {};
    UInt64* source = as;
    return Unsafe::AsRef<Vector128<UInt64>>(source);
  };
  if (Sse2::in::X64::in::get_IsSupported() || AdvSimd::in::Arm64::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector128<Byte> Vector128<>::Create(Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7, Byte e8, Byte e9, Byte e10, Byte e11, Byte e12, Byte e13, Byte e14, Byte e15) {
  auto SoftwareFallback = [](Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7, Byte e8, Byte e9, Byte e10, Byte e11, Byte e12, Byte e13, Byte e14, Byte e15) -> Vector128<Byte> {
    Byte as[16] = {};
    Byte* source = as;
    return Unsafe::AsRef<Vector128<Byte>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
}

Vector128<Double> Vector128<>::Create(Double e0, Double e1) {
  auto SoftwareFallback = [](Double e0, Double e1) -> Vector128<Double> {
    Double as[2] = {};
    Double* source = as;
    return Unsafe::AsRef<Vector128<Double>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1);
  }
  return SoftwareFallback(e0, e1);
}

Vector128<Int16> Vector128<>::Create(Int16 e0, Int16 e1, Int16 e2, Int16 e3, Int16 e4, Int16 e5, Int16 e6, Int16 e7) {
  auto SoftwareFallback = [](Int16 e0, Int16 e1, Int16 e2, Int16 e3, Int16 e4, Int16 e5, Int16 e6, Int16 e7) -> Vector128<Int16> {
    Int16 as[8] = {};
    Int16* source = as;
    return Unsafe::AsRef<Vector128<Int16>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7);
}

Vector128<Int32> Vector128<>::Create(Int32 e0, Int32 e1, Int32 e2, Int32 e3) {
  auto SoftwareFallback = [](Int32 e0, Int32 e1, Int32 e2, Int32 e3) -> Vector128<Int32> {
    Int32 as[4] = {};
    Int32* source = as;
    return Unsafe::AsRef<Vector128<Int32>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3);
  }
  return SoftwareFallback(e0, e1, e2, e3);
}

Vector128<Int64> Vector128<>::Create(Int64 e0, Int64 e1) {
  auto SoftwareFallback = [](Int64 e0, Int64 e1) -> Vector128<Int64> {
    Int64 as[2] = {};
    Int64* source = as;
    return Unsafe::AsRef<Vector128<Int64>>(source);
  };
  if (Sse2::in::X64::in::get_IsSupported() || AdvSimd::in::Arm64::in::get_IsSupported()) {
    return Create(e0, e1);
  }
  return SoftwareFallback(e0, e1);
}

Vector128<SByte> Vector128<>::Create(SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7, SByte e8, SByte e9, SByte e10, SByte e11, SByte e12, SByte e13, SByte e14, SByte e15) {
  auto SoftwareFallback = [](SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7, SByte e8, SByte e9, SByte e10, SByte e11, SByte e12, SByte e13, SByte e14, SByte e15) -> Vector128<SByte> {
    SByte as[16] = {};
    SByte* source = as;
    return Unsafe::AsRef<Vector128<SByte>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15);
}

Vector128<Single> Vector128<>::Create(Single e0, Single e1, Single e2, Single e3) {
  auto SoftwareFallback = [](Single e0, Single e1, Single e2, Single e3) -> Vector128<Single> {
    Single as[4] = {};
    Single* source = as;
    return Unsafe::AsRef<Vector128<Single>>(source);
  };
  if (Sse::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3);
  }
  return SoftwareFallback(e0, e1, e2, e3);
}

Vector128<UInt16> Vector128<>::Create(UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3, UInt16 e4, UInt16 e5, UInt16 e6, UInt16 e7) {
  auto SoftwareFallback = [](UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3, UInt16 e4, UInt16 e5, UInt16 e6, UInt16 e7) -> Vector128<UInt16> {
    UInt16 as[8] = {};
    UInt16* source = as;
    return Unsafe::AsRef<Vector128<UInt16>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7);
}

Vector128<UInt32> Vector128<>::Create(UInt32 e0, UInt32 e1, UInt32 e2, UInt32 e3) {
  auto SoftwareFallback = [](UInt32 e0, UInt32 e1, UInt32 e2, UInt32 e3) -> Vector128<UInt32> {
    UInt32 as[4] = {};
    UInt32* source = as;
    return Unsafe::AsRef<Vector128<UInt32>>(source);
  };
  if (Sse2::in::get_IsSupported() || AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3);
  }
  return SoftwareFallback(e0, e1, e2, e3);
}

Vector128<UInt64> Vector128<>::Create(UInt64 e0, UInt64 e1) {
  auto SoftwareFallback = [](UInt64 e0, UInt64 e1) -> Vector128<UInt64> {
    UInt64 as[2] = {};
    UInt64* source = as;
    return Unsafe::AsRef<Vector128<UInt64>>(source);
  };
  if (Sse2::in::X64::in::get_IsSupported() || AdvSimd::in::Arm64::in::get_IsSupported()) {
    return Create(e0, e1);
  }
  return SoftwareFallback(e0, e1);
}

Vector128<Byte> Vector128<>::Create(Vector64<Byte> lower, Vector64<Byte> upper) {
  Vector128<Byte> source = Vector128<Byte>::get_Zero();
  Vector64<Byte>& reference = Unsafe::As<Vector128<Byte>, Vector64<Byte>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector128<Double> Vector128<>::Create(Vector64<Double> lower, Vector64<Double> upper) {
  Vector128<Double> source = Vector128<Double>::get_Zero();
  Vector64<Double>& reference = Unsafe::As<Vector128<Double>, Vector64<Double>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector128<Int16> Vector128<>::Create(Vector64<Int16> lower, Vector64<Int16> upper) {
  Vector128<Int16> source = Vector128<Int16>::get_Zero();
  Vector64<Int16>& reference = Unsafe::As<Vector128<Int16>, Vector64<Int16>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector128<Int32> Vector128<>::Create(Vector64<Int32> lower, Vector64<Int32> upper) {
  Vector128<Int32> source = Vector128<Int32>::get_Zero();
  Vector64<Int32>& reference = Unsafe::As<Vector128<Int32>, Vector64<Int32>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector128<Int64> Vector128<>::Create(Vector64<Int64> lower, Vector64<Int64> upper) {
  Vector128<Int64> source = Vector128<Int64>::get_Zero();
  Vector64<Int64>& reference = Unsafe::As<Vector128<Int64>, Vector64<Int64>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector128<SByte> Vector128<>::Create(Vector64<SByte> lower, Vector64<SByte> upper) {
  Vector128<SByte> source = Vector128<SByte>::get_Zero();
  Vector64<SByte>& reference = Unsafe::As<Vector128<SByte>, Vector64<SByte>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector128<Single> Vector128<>::Create(Vector64<Single> lower, Vector64<Single> upper) {
  Vector128<Single> source = Vector128<Single>::get_Zero();
  Vector64<Single>& reference = Unsafe::As<Vector128<Single>, Vector64<Single>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector128<UInt16> Vector128<>::Create(Vector64<UInt16> lower, Vector64<UInt16> upper) {
  Vector128<UInt16> source = Vector128<UInt16>::get_Zero();
  Vector64<UInt16>& reference = Unsafe::As<Vector128<UInt16>, Vector64<UInt16>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector128<UInt32> Vector128<>::Create(Vector64<UInt32> lower, Vector64<UInt32> upper) {
  Vector128<UInt32> source = Vector128<UInt32>::get_Zero();
  Vector64<UInt32>& reference = Unsafe::As<Vector128<UInt32>, Vector64<UInt32>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector128<UInt64> Vector128<>::Create(Vector64<UInt64> lower, Vector64<UInt64> upper) {
  Vector128<UInt64> source = Vector128<UInt64>::get_Zero();
  Vector64<UInt64>& reference = Unsafe::As<Vector128<UInt64>, Vector64<UInt64>>(source);
  reference = lower;
  Unsafe::Add(reference, 1) = upper;
  return source;
}

Vector128<Byte> Vector128<>::CreateScalar(Byte value) {
  auto SoftwareFallback = [](Byte value) -> Vector128<Byte> {
    Vector128<Byte> source = Vector128<Byte>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector128<Byte>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector128<Byte>::get_Zero(), 0, value);
  }
  if (Sse2::in::get_IsSupported()) {
    return Vector128<>::AsByte(Sse2::in::ConvertScalarToVector128UInt32(value));
  }
  return SoftwareFallback(value);
}

Vector128<Double> Vector128<>::CreateScalar(Double value) {
  auto SoftwareFallback = [](Double value) -> Vector128<Double> {
    Vector128<Double> source = Vector128<Double>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector128<Double>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector128<Double>::get_Zero(), 0, value);
  }
  if (Sse2::in::get_IsSupported()) {
    return Sse2::in::MoveScalar(Vector128<Double>::get_Zero(), CreateScalarUnsafe(value));
  }
  return SoftwareFallback(value);
}

Vector128<Int16> Vector128<>::CreateScalar(Int16 value) {
  auto SoftwareFallback = [](Int16 value) -> Vector128<Int16> {
    Vector128<Int16> source = Vector128<Int16>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector128<Int16>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector128<Int16>::get_Zero(), 0, value);
  }
  if (Sse2::in::get_IsSupported()) {
    return Vector128<>::AsInt16(Sse2::in::ConvertScalarToVector128UInt32((UInt16)value));
  }
  return SoftwareFallback(value);
}

Vector128<Int32> Vector128<>::CreateScalar(Int32 value) {
  auto SoftwareFallback = [](Int32 value) -> Vector128<Int32> {
    Vector128<Int32> source = Vector128<Int32>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector128<Int32>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector128<Int32>::get_Zero(), 0, value);
  }
  if (Sse2::in::get_IsSupported()) {
    return Sse2::in::ConvertScalarToVector128Int32(value);
  }
  return SoftwareFallback(value);
}

Vector128<Int64> Vector128<>::CreateScalar(Int64 value) {
  auto SoftwareFallback = [](Int64 value) -> Vector128<Int64> {
    Vector128<Int64> source = Vector128<Int64>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector128<Int64>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector128<Int64>::get_Zero(), 0, value);
  }
  if (Sse2::in::X64::in::get_IsSupported()) {
    return Sse2::in::X64::in::ConvertScalarToVector128Int64(value);
  }
  return SoftwareFallback(value);
}

Vector128<SByte> Vector128<>::CreateScalar(SByte value) {
  auto SoftwareFallback = [](SByte value) -> Vector128<SByte> {
    Vector128<SByte> source = Vector128<SByte>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector128<SByte>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector128<SByte>::get_Zero(), 0, value);
  }
  if (Sse2::in::get_IsSupported()) {
    return Vector128<>::AsSByte(Sse2::in::ConvertScalarToVector128UInt32((Byte)value));
  }
  return SoftwareFallback(value);
}

Vector128<Single> Vector128<>::CreateScalar(Single value) {
  auto SoftwareFallback = [](Single value) -> Vector128<Single> {
    Vector128<Single> source = Vector128<Single>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector128<Single>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector128<Single>::get_Zero(), 0, value);
  }
  if (Sse::in::get_IsSupported()) {
    return Sse::in::MoveScalar(Vector128<Single>::get_Zero(), CreateScalarUnsafe(value));
  }
  return SoftwareFallback(value);
}

Vector128<UInt16> Vector128<>::CreateScalar(UInt16 value) {
  auto SoftwareFallback = [](UInt16 value) -> Vector128<UInt16> {
    Vector128<UInt16> source = Vector128<UInt16>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector128<UInt16>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector128<UInt16>::get_Zero(), 0, value);
  }
  if (Sse2::in::get_IsSupported()) {
    return Vector128<>::AsUInt16(Sse2::in::ConvertScalarToVector128UInt32(value));
  }
  return SoftwareFallback(value);
}

Vector128<UInt32> Vector128<>::CreateScalar(UInt32 value) {
  auto SoftwareFallback = [](UInt32 value) -> Vector128<UInt32> {
    Vector128<UInt32> source = Vector128<UInt32>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector128<UInt32>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector128<UInt32>::get_Zero(), 0, value);
  }
  if (Sse2::in::get_IsSupported()) {
    return Sse2::in::ConvertScalarToVector128UInt32(value);
  }
  return SoftwareFallback(value);
}

Vector128<UInt64> Vector128<>::CreateScalar(UInt64 value) {
  auto SoftwareFallback = [](UInt64 value) -> Vector128<UInt64> {
    Vector128<UInt64> source = Vector128<UInt64>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector128<UInt64>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector128<UInt64>::get_Zero(), 0, value);
  }
  if (Sse2::in::X64::in::get_IsSupported()) {
    return Sse2::in::X64::in::ConvertScalarToVector128UInt64(value);
  }
  return SoftwareFallback(value);
}

Vector128<Byte> Vector128<>::CreateScalarUnsafe(Byte value) {
  Byte as[16] = {};
  Byte* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector128<Byte>>(ptr);
}

Vector128<Double> Vector128<>::CreateScalarUnsafe(Double value) {
  Double as[2] = {};
  Double* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector128<Double>>(ptr);
}

Vector128<Int16> Vector128<>::CreateScalarUnsafe(Int16 value) {
  Int16 as[8] = {};
  Int16* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector128<Int16>>(ptr);
}

Vector128<Int32> Vector128<>::CreateScalarUnsafe(Int32 value) {
  Int32 as[4] = {};
  Int32* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector128<Int32>>(ptr);
}

Vector128<Int64> Vector128<>::CreateScalarUnsafe(Int64 value) {
  Int64 as[2] = {};
  Int64* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector128<Int64>>(ptr);
}

Vector128<SByte> Vector128<>::CreateScalarUnsafe(SByte value) {
  SByte as[16] = {};
  SByte* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector128<SByte>>(ptr);
}

Vector128<Single> Vector128<>::CreateScalarUnsafe(Single value) {
  Single as[4] = {};
  Single* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector128<Single>>(ptr);
}

Vector128<UInt16> Vector128<>::CreateScalarUnsafe(UInt16 value) {
  UInt16 as[8] = {};
  UInt16* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector128<UInt16>>(ptr);
}

Vector128<UInt32> Vector128<>::CreateScalarUnsafe(UInt32 value) {
  UInt32 as[4] = {};
  UInt32* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector128<UInt32>>(ptr);
}

Vector128<UInt64> Vector128<>::CreateScalarUnsafe(UInt64 value) {
  UInt64 as[2] = {};
  UInt64* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector128<UInt64>>(ptr);
}

} // namespace System::Private::CoreLib::System::Runtime::Intrinsics::Vector128Namespace
