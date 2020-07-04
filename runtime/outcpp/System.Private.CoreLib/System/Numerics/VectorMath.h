#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::Intrinsics {
FORWARDS_(Vector128, T1, T2)
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Single)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Numerics {
namespace VectorMathNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::Intrinsics;
class VectorMath {
  public: static Vector128<Single> Lerp(Vector128<Single> a, Vector128<Single> b, Vector128<Single> t);
  public: static Boolean Equal(Vector128<Single> vector1, Vector128<Single> vector2);
  public: static Boolean NotEqual(Vector128<Single> vector1, Vector128<Single> vector2);
};
} // namespace VectorMathNamespace
using VectorMath = VectorMathNamespace::VectorMath;
} // namespace System::Private::CoreLib::System::Numerics
