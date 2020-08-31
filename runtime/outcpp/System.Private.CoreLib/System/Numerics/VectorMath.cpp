#include "VectorMath-dep.h"

#include <System.Private.CoreLib/System/Runtime/Intrinsics/Arm/AdvSimd-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse-dep.h>
#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse2-dep.h>

namespace System::Private::CoreLib::System::Numerics::VectorMathNamespace {
using namespace System::Runtime::Intrinsics::Arm;
using namespace System::Runtime::Intrinsics::X86;

Vector128<Single> VectorMath::Lerp(Vector128<Single> a, Vector128<Single> b, Vector128<Single> t) {
  return Sse::in::Add(a, Sse::in::Multiply(Sse::in::Subtract(b, a), t));
}

Boolean VectorMath::Equal(Vector128<Single> vector1, Vector128<Single> vector2) {
  return Sse::in::MoveMask(Sse::in::CompareNotEqual(vector1, vector2)) == 0;
}

Boolean VectorMath::NotEqual(Vector128<Single> vector1, Vector128<Single> vector2) {
  return Sse::in::MoveMask(Sse::in::CompareNotEqual(vector1, vector2)) != 0;
}

Vector128<Single> VectorMath::ConditionalSelectBitwise(Vector128<Single> selector, Vector128<Single> ifTrue, Vector128<Single> ifFalse) {
  if (Sse::in::get_IsSupported()) {
    return Sse::in::Or(Sse::in::And(ifTrue, selector), Sse::in::AndNot(selector, ifFalse));
  }
  if (AdvSimd::in::get_IsSupported()) {
    return Vector128<>::As(AdvSimd::in::BitwiseSelect(Vector128<>::AsByte(selector), Vector128<>::AsByte(ifTrue), Vector128<>::AsByte(ifFalse)));
  }
  return Vector128<T>();
}

Vector128<Double> VectorMath::ConditionalSelectBitwise(Vector128<Double> selector, Vector128<Double> ifTrue, Vector128<Double> ifFalse) {
  if (Sse2::in::get_IsSupported()) {
    return Sse2::in::Or(Sse2::in::And(ifTrue, selector), Sse2::in::AndNot(selector, ifFalse));
  }
  if (Sse::in::get_IsSupported()) {
    return Vector128<>::As(Sse::in::Or(Sse::in::And(Vector128<>::AsSingle(ifTrue), Vector128<>::AsSingle(selector)), Sse::in::AndNot(Vector128<>::AsSingle(selector), Vector128<>::AsSingle(ifFalse))));
  }
  if (AdvSimd::in::get_IsSupported()) {
    return Vector128<>::As(AdvSimd::in::BitwiseSelect(Vector128<>::AsByte(selector), Vector128<>::AsByte(ifTrue), Vector128<>::AsByte(ifFalse)));
  }
  return Vector128<T>();
}

} // namespace System::Private::CoreLib::System::Numerics::VectorMathNamespace
