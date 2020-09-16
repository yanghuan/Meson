#include "VectorMath-dep.h"

#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Arm/AdvSimd-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/Vector64-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Fma-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Numerics::VectorMathNamespace {
using namespace System::Runtime::Intrinsics;
using namespace System::Runtime::Intrinsics::Arm;
using namespace System::Runtime::Intrinsics::X86;

Vector128<Single> VectorMath::ConditionalSelectBitwise(Vector128<Single> selector, Vector128<Single> ifTrue, Vector128<Single> ifFalse) {
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::BitwiseSelect(selector, ifTrue, ifFalse);
  }
  if (Sse::in::get_IsSupported()) {
    return Sse::in::Or(Sse::in::And(ifTrue, selector), Sse::in::AndNot(selector, ifFalse));
  }
  rt::throw_exception<PlatformNotSupportedException>();
}

Vector128<Double> VectorMath::ConditionalSelectBitwise(Vector128<Double> selector, Vector128<Double> ifTrue, Vector128<Double> ifFalse) {
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::BitwiseSelect(selector, ifTrue, ifFalse);
  }
  if (Sse2::in::get_IsSupported()) {
    return Sse2::in::Or(Sse2::in::And(ifTrue, selector), Sse2::in::AndNot(selector, ifFalse));
  }
  rt::throw_exception<PlatformNotSupportedException>();
}

Boolean VectorMath::Equal(Vector128<Single> vector1, Vector128<Single> vector2) {
  if (AdvSimd::in::Arm64::in::get_IsSupported()) {
    Vector128<UInt32> vector3 = Vector128<>::AsUInt32(AdvSimd::in::CompareEqual(vector1, vector2));
    Vector64<Byte> left = Vector64<>::AsByte(Vector128<>::GetLower(vector3));
    Vector64<Byte> right = Vector64<>::AsByte(Vector128<>::GetUpper(vector3));
    Vector64<Byte> vector4 = AdvSimd::in::Arm64::in::ZipLow(left, right);
    Vector64<Byte> vector5 = AdvSimd::in::Arm64::in::ZipHigh(left, right);
    Vector64<UInt16> vector6 = AdvSimd::in::Arm64::in::ZipHigh(Vector64<>::AsUInt16(vector4), Vector64<>::AsUInt16(vector5));
    return Vector64<>::GetElement(Vector64<>::AsUInt32(vector6), 1) == UInt32::MaxValue;
  }
  if (Sse::in::get_IsSupported()) {
    return Sse::in::MoveMask(Sse::in::CompareNotEqual(vector1, vector2)) == 0;
  }
  rt::throw_exception<PlatformNotSupportedException>();
}

Vector128<Single> VectorMath::Lerp(Vector128<Single> a, Vector128<Single> b, Vector128<Single> t) {
  if (AdvSimd::in::get_IsSupported()) {
    return AdvSimd::in::FusedMultiplyAdd(a, AdvSimd::in::Subtract(b, a), t);
  }
  if (Fma::in::get_IsSupported()) {
    return Fma::in::MultiplyAdd(Sse::in::Subtract(b, a), t, a);
  }
  if (Sse::in::get_IsSupported()) {
    return Sse::in::Add(Sse::in::Multiply(a, Sse::in::Subtract(Vector128<>::Create(1), t)), Sse::in::Multiply(b, t));
  }
  rt::throw_exception<PlatformNotSupportedException>();
}

Boolean VectorMath::NotEqual(Vector128<Single> vector1, Vector128<Single> vector2) {
  if (AdvSimd::in::get_IsSupported()) {
    Vector128<UInt32> vector3 = Vector128<>::AsUInt32(AdvSimd::in::CompareEqual(vector1, vector2));
    Vector64<Byte> left = Vector64<>::AsByte(Vector128<>::GetLower(vector3));
    Vector64<Byte> right = Vector64<>::AsByte(Vector128<>::GetUpper(vector3));
    Vector64<Byte> vector4 = AdvSimd::in::Arm64::in::ZipLow(left, right);
    Vector64<Byte> vector5 = AdvSimd::in::Arm64::in::ZipHigh(left, right);
    Vector64<UInt16> vector6 = AdvSimd::in::Arm64::in::ZipHigh(Vector64<>::AsUInt16(vector4), Vector64<>::AsUInt16(vector5));
    return Vector64<>::GetElement(Vector64<>::AsUInt32(vector6), 1) != UInt32::MaxValue;
  }
  if (Sse::in::get_IsSupported()) {
    return Sse::in::MoveMask(Sse::in::CompareNotEqual(vector1, vector2)) != 0;
  }
  rt::throw_exception<PlatformNotSupportedException>();
}

} // namespace System::Private::CoreLib::System::Numerics::VectorMathNamespace
