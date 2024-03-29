#include "Vector64-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Arm/AdvSimd-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector64-dep.h>

namespace System::Private::CoreLib::System::Runtime::Intrinsics::Vector64Namespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Runtime::Intrinsics::Arm;

Vector64<Byte> Vector64<>::Create(Byte value) {
  auto SoftwareFallback = [](Byte value) -> Vector64<Byte> {
    Byte as[8] = {};
    Byte* source = as;
    return Unsafe::AsRef<Vector64<Byte>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<Double> Vector64<>::Create(Double value) {
  auto SoftwareFallback = [](Double value) -> Vector64<Double> {
    return Unsafe::As<Double, Vector64<Double>>(value);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<Int16> Vector64<>::Create(Int16 value) {
  auto SoftwareFallback = [](Int16 value) -> Vector64<Int16> {
    Int16 as[4] = {};
    Int16* source = as;
    return Unsafe::AsRef<Vector64<Int16>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<Int32> Vector64<>::Create(Int32 value) {
  auto SoftwareFallback = [](Int32 value) -> Vector64<Int32> {
    Int32 as[2] = {};
    Int32* source = as;
    return Unsafe::AsRef<Vector64<Int32>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<Int64> Vector64<>::Create(Int64 value) {
  auto SoftwareFallback = [](Int64 value) -> Vector64<Int64> {
    return Unsafe::As<Int64, Vector64<Int64>>(value);
  };
  if (AdvSimd::in::Arm64::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<SByte> Vector64<>::Create(SByte value) {
  auto SoftwareFallback = [](SByte value) -> Vector64<SByte> {
    SByte as[8] = {};
    SByte* source = as;
    return Unsafe::AsRef<Vector64<SByte>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<Single> Vector64<>::Create(Single value) {
  auto SoftwareFallback = [](Single value) -> Vector64<Single> {
    Single as[2] = {};
    Single* source = as;
    return Unsafe::AsRef<Vector64<Single>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<UInt16> Vector64<>::Create(UInt16 value) {
  auto SoftwareFallback = [](UInt16 value) -> Vector64<UInt16> {
    UInt16 as[4] = {};
    UInt16* source = as;
    return Unsafe::AsRef<Vector64<UInt16>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<UInt32> Vector64<>::Create(UInt32 value) {
  auto SoftwareFallback = [](UInt32 value) -> Vector64<UInt32> {
    UInt32 as[2] = {};
    UInt32* source = as;
    return Unsafe::AsRef<Vector64<UInt32>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<UInt64> Vector64<>::Create(UInt64 value) {
  auto SoftwareFallback = [](UInt64 value) -> Vector64<UInt64> {
    return Unsafe::As<UInt64, Vector64<UInt64>>(value);
  };
  if (AdvSimd::in::Arm64::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<Byte> Vector64<>::Create(Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7) {
  auto SoftwareFallback = [](Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7) -> Vector64<Byte> {
    Byte as[8] = {};
    Byte* source = as;
    return Unsafe::AsRef<Vector64<Byte>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7);
}

Vector64<Int16> Vector64<>::Create(Int16 e0, Int16 e1, Int16 e2, Int16 e3) {
  auto SoftwareFallback = [](Int16 e0, Int16 e1, Int16 e2, Int16 e3) -> Vector64<Int16> {
    Int16 as[4] = {};
    Int16* source = as;
    return Unsafe::AsRef<Vector64<Int16>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3);
  }
  return SoftwareFallback(e0, e1, e2, e3);
}

Vector64<Int32> Vector64<>::Create(Int32 e0, Int32 e1) {
  auto SoftwareFallback = [](Int32 e0, Int32 e1) -> Vector64<Int32> {
    Int32 as[2] = {};
    Int32* source = as;
    return Unsafe::AsRef<Vector64<Int32>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1);
  }
  return SoftwareFallback(e0, e1);
}

Vector64<SByte> Vector64<>::Create(SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7) {
  auto SoftwareFallback = [](SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7) -> Vector64<SByte> {
    SByte as[8] = {};
    SByte* source = as;
    return Unsafe::AsRef<Vector64<SByte>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3, e4, e5, e6, e7);
  }
  return SoftwareFallback(e0, e1, e2, e3, e4, e5, e6, e7);
}

Vector64<Single> Vector64<>::Create(Single e0, Single e1) {
  auto SoftwareFallback = [](Single e0, Single e1) -> Vector64<Single> {
    Single as[2] = {};
    Single* source = as;
    return Unsafe::AsRef<Vector64<Single>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1);
  }
  return SoftwareFallback(e0, e1);
}

Vector64<UInt16> Vector64<>::Create(UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3) {
  auto SoftwareFallback = [](UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3) -> Vector64<UInt16> {
    UInt16 as[4] = {};
    UInt16* source = as;
    return Unsafe::AsRef<Vector64<UInt16>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1, e2, e3);
  }
  return SoftwareFallback(e0, e1, e2, e3);
}

Vector64<UInt32> Vector64<>::Create(UInt32 e0, UInt32 e1) {
  auto SoftwareFallback = [](UInt32 e0, UInt32 e1) -> Vector64<UInt32> {
    UInt32 as[2] = {};
    UInt32* source = as;
    return Unsafe::AsRef<Vector64<UInt32>>(source);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(e0, e1);
  }
  return SoftwareFallback(e0, e1);
}

Vector64<Byte> Vector64<>::CreateScalar(Byte value) {
  auto SoftwareFallback = [](Byte value) -> Vector64<Byte> {
    Vector64<Byte> source = Vector64<Byte>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector64<Byte>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector64<Byte>::get_Zero(), 0, value);
  }
  return SoftwareFallback(value);
}

Vector64<Double> Vector64<>::CreateScalar(Double value) {
  auto SoftwareFallback = [](Double value) -> Vector64<Double> {
    return Unsafe::As<Double, Vector64<Double>>(value);
  };
  if (AdvSimd::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<Int16> Vector64<>::CreateScalar(Int16 value) {
  auto SoftwareFallback = [](Int16 value) -> Vector64<Int16> {
    Vector64<Int16> source = Vector64<Int16>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector64<Int16>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector64<Int16>::get_Zero(), 0, value);
  }
  return SoftwareFallback(value);
}

Vector64<Int32> Vector64<>::CreateScalar(Int32 value) {
  auto SoftwareFallback = [](Int32 value) -> Vector64<Int32> {
    Vector64<Int32> source = Vector64<Int32>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector64<Int32>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector64<Int32>::get_Zero(), 0, value);
  }
  return SoftwareFallback(value);
}

Vector64<Int64> Vector64<>::CreateScalar(Int64 value) {
  auto SoftwareFallback = [](Int64 value) -> Vector64<Int64> {
    return Unsafe::As<Int64, Vector64<Int64>>(value);
  };
  if (AdvSimd::in::Arm64::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<SByte> Vector64<>::CreateScalar(SByte value) {
  auto SoftwareFallback = [](SByte value) -> Vector64<SByte> {
    Vector64<SByte> source = Vector64<SByte>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector64<SByte>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector64<SByte>::get_Zero(), 0, value);
  }
  return SoftwareFallback(value);
}

Vector64<Single> Vector64<>::CreateScalar(Single value) {
  auto SoftwareFallback = [](Single value) -> Vector64<Single> {
    Vector64<Single> source = Vector64<Single>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector64<Single>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector64<Single>::get_Zero(), 0, value);
  }
  return SoftwareFallback(value);
}

Vector64<UInt16> Vector64<>::CreateScalar(UInt16 value) {
  auto SoftwareFallback = [](UInt16 value) -> Vector64<UInt16> {
    Vector64<UInt16> source = Vector64<UInt16>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector64<UInt16>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector64<UInt16>::get_Zero(), 0, value);
  }
  return SoftwareFallback(value);
}

Vector64<UInt32> Vector64<>::CreateScalar(UInt32 value) {
  auto SoftwareFallback = [](UInt32 value) -> Vector64<UInt32> {
    Vector64<UInt32> source = Vector64<UInt32>::get_Zero();
    Unsafe::WriteUnaligned(Unsafe::As<Vector64<UInt32>, Byte>(source), value);
    return source;
  };
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::Insert(Vector64<UInt32>::get_Zero(), 0, value);
  }
  return SoftwareFallback(value);
}

Vector64<UInt64> Vector64<>::CreateScalar(UInt64 value) {
  auto SoftwareFallback = [](UInt64 value) -> Vector64<UInt64> {
    return Unsafe::As<UInt64, Vector64<UInt64>>(value);
  };
  if (AdvSimd::in::Arm64::in::get_IsSupported()) {
    return Create(value);
  }
  return SoftwareFallback(value);
}

Vector64<Byte> Vector64<>::CreateScalarUnsafe(Byte value) {
  Byte as[8] = {};
  Byte* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector64<Byte>>(ptr);
}

Vector64<Int16> Vector64<>::CreateScalarUnsafe(Int16 value) {
  Int16 as[4] = {};
  Int16* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector64<Int16>>(ptr);
}

Vector64<Int32> Vector64<>::CreateScalarUnsafe(Int32 value) {
  Int32 as[2] = {};
  Int32* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector64<Int32>>(ptr);
}

Vector64<SByte> Vector64<>::CreateScalarUnsafe(SByte value) {
  SByte as[8] = {};
  SByte* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector64<SByte>>(ptr);
}

Vector64<Single> Vector64<>::CreateScalarUnsafe(Single value) {
  Single as[2] = {};
  Single* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector64<Single>>(ptr);
}

Vector64<UInt16> Vector64<>::CreateScalarUnsafe(UInt16 value) {
  UInt16 as[4] = {};
  UInt16* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector64<UInt16>>(ptr);
}

Vector64<UInt32> Vector64<>::CreateScalarUnsafe(UInt32 value) {
  UInt32 as[2] = {};
  UInt32* ptr = as;
  *ptr = value;
  return Unsafe::AsRef<Vector64<UInt32>>(ptr);
}

Vector64<Byte> Vector64<>::_Create_g__SoftwareFallback12_0(Byte value) {
  Byte as[8] = {};
  Byte* source = as;
  return Unsafe::AsRef<Vector64<Byte>>(source);
}

Vector64<Double> Vector64<>::_Create_g__SoftwareFallback13_0(Double value) {
  return Unsafe::As<Double, Vector64<Double>>(value);
}

Vector64<Int16> Vector64<>::_Create_g__SoftwareFallback14_0(Int16 value) {
  Int16 as[4] = {};
  Int16* source = as;
  return Unsafe::AsRef<Vector64<Int16>>(source);
}

Vector64<Int32> Vector64<>::_Create_g__SoftwareFallback15_0(Int32 value) {
  Int32 as[2] = {};
  Int32* source = as;
  return Unsafe::AsRef<Vector64<Int32>>(source);
}

Vector64<Int64> Vector64<>::_Create_g__SoftwareFallback16_0(Int64 value) {
  return Unsafe::As<Int64, Vector64<Int64>>(value);
}

Vector64<SByte> Vector64<>::_Create_g__SoftwareFallback17_0(SByte value) {
  SByte as[8] = {};
  SByte* source = as;
  return Unsafe::AsRef<Vector64<SByte>>(source);
}

Vector64<Single> Vector64<>::_Create_g__SoftwareFallback18_0(Single value) {
  Single as[2] = {};
  Single* source = as;
  return Unsafe::AsRef<Vector64<Single>>(source);
}

Vector64<UInt16> Vector64<>::_Create_g__SoftwareFallback19_0(UInt16 value) {
  UInt16 as[4] = {};
  UInt16* source = as;
  return Unsafe::AsRef<Vector64<UInt16>>(source);
}

Vector64<UInt32> Vector64<>::_Create_g__SoftwareFallback20_0(UInt32 value) {
  UInt32 as[2] = {};
  UInt32* source = as;
  return Unsafe::AsRef<Vector64<UInt32>>(source);
}

Vector64<UInt64> Vector64<>::_Create_g__SoftwareFallback21_0(UInt64 value) {
  return Unsafe::As<UInt64, Vector64<UInt64>>(value);
}

Vector64<Byte> Vector64<>::_Create_g__SoftwareFallback22_0(Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7) {
  Byte as[8] = {};
  Byte* source = as;
  return Unsafe::AsRef<Vector64<Byte>>(source);
}

Vector64<Int16> Vector64<>::_Create_g__SoftwareFallback23_0(Int16 e0, Int16 e1, Int16 e2, Int16 e3) {
  Int16 as[4] = {};
  Int16* source = as;
  return Unsafe::AsRef<Vector64<Int16>>(source);
}

Vector64<Int32> Vector64<>::_Create_g__SoftwareFallback24_0(Int32 e0, Int32 e1) {
  Int32 as[2] = {};
  Int32* source = as;
  return Unsafe::AsRef<Vector64<Int32>>(source);
}

Vector64<SByte> Vector64<>::_Create_g__SoftwareFallback25_0(SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7) {
  SByte as[8] = {};
  SByte* source = as;
  return Unsafe::AsRef<Vector64<SByte>>(source);
}

Vector64<Single> Vector64<>::_Create_g__SoftwareFallback26_0(Single e0, Single e1) {
  Single as[2] = {};
  Single* source = as;
  return Unsafe::AsRef<Vector64<Single>>(source);
}

Vector64<UInt16> Vector64<>::_Create_g__SoftwareFallback27_0(UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3) {
  UInt16 as[4] = {};
  UInt16* source = as;
  return Unsafe::AsRef<Vector64<UInt16>>(source);
}

Vector64<UInt32> Vector64<>::_Create_g__SoftwareFallback28_0(UInt32 e0, UInt32 e1) {
  UInt32 as[2] = {};
  UInt32* source = as;
  return Unsafe::AsRef<Vector64<UInt32>>(source);
}

Vector64<Byte> Vector64<>::_CreateScalar_g__SoftwareFallback29_0(Byte value) {
  Vector64<Byte> source = Vector64<Byte>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector64<Byte>, Byte>(source), value);
  return source;
}

Vector64<Double> Vector64<>::_CreateScalar_g__SoftwareFallback30_0(Double value) {
  return Unsafe::As<Double, Vector64<Double>>(value);
}

Vector64<Int16> Vector64<>::_CreateScalar_g__SoftwareFallback31_0(Int16 value) {
  Vector64<Int16> source = Vector64<Int16>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector64<Int16>, Byte>(source), value);
  return source;
}

Vector64<Int32> Vector64<>::_CreateScalar_g__SoftwareFallback32_0(Int32 value) {
  Vector64<Int32> source = Vector64<Int32>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector64<Int32>, Byte>(source), value);
  return source;
}

Vector64<Int64> Vector64<>::_CreateScalar_g__SoftwareFallback33_0(Int64 value) {
  return Unsafe::As<Int64, Vector64<Int64>>(value);
}

Vector64<SByte> Vector64<>::_CreateScalar_g__SoftwareFallback34_0(SByte value) {
  Vector64<SByte> source = Vector64<SByte>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector64<SByte>, Byte>(source), value);
  return source;
}

Vector64<Single> Vector64<>::_CreateScalar_g__SoftwareFallback35_0(Single value) {
  Vector64<Single> source = Vector64<Single>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector64<Single>, Byte>(source), value);
  return source;
}

Vector64<UInt16> Vector64<>::_CreateScalar_g__SoftwareFallback36_0(UInt16 value) {
  Vector64<UInt16> source = Vector64<UInt16>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector64<UInt16>, Byte>(source), value);
  return source;
}

Vector64<UInt32> Vector64<>::_CreateScalar_g__SoftwareFallback37_0(UInt32 value) {
  Vector64<UInt32> source = Vector64<UInt32>::get_Zero();
  Unsafe::WriteUnaligned(Unsafe::As<Vector64<UInt32>, Byte>(source), value);
  return source;
}

Vector64<UInt64> Vector64<>::_CreateScalar_g__SoftwareFallback38_0(UInt64 value) {
  return Unsafe::As<UInt64, Vector64<UInt64>>(value);
}

} // namespace System::Private::CoreLib::System::Runtime::Intrinsics::Vector64Namespace
