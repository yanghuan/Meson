#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Intrinsics {
FORWARDS_(Vector128)
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Double)
FORWARDS(Single)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Numerics {
namespace VectorMathNamespace {
using namespace System::Runtime::Intrinsics;
class VectorMath {
  public: static Vector128<Single> ConditionalSelectBitwise(Vector128<Single> selector, Vector128<Single> ifTrue, Vector128<Single> ifFalse);
  public: static Vector128<Double> ConditionalSelectBitwise(Vector128<Double> selector, Vector128<Double> ifTrue, Vector128<Double> ifFalse);
  public: static Boolean Equal(Vector128<Single> vector1, Vector128<Single> vector2);
  public: static Vector128<Single> Lerp(Vector128<Single> a, Vector128<Single> b, Vector128<Single> t);
  public: static Boolean NotEqual(Vector128<Single> vector1, Vector128<Single> vector2);
};
} // namespace VectorMathNamespace
using VectorMath = VectorMathNamespace::VectorMath;
} // namespace System::Private::CoreLib::System::Numerics
