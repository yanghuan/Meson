#include "VectorMath-dep.h"

#include <System.Private.CoreLib/System/Runtime/Intrinsics/X86/Sse-dep.h>

namespace System::Private::CoreLib::System::Numerics::VectorMathNamespace {
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

} // namespace System::Private::CoreLib::System::Numerics::VectorMathNamespace
