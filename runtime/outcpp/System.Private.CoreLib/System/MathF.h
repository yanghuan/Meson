#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Single)
FORWARDS(Int32)
enum class MidpointRounding;
FORWARD_(Array, T1, T2)
namespace MathFNamespace {
class MathF {
  public: static Single Acos(Single x);
  public: static Single Acosh(Single x);
  public: static Single Asin(Single x);
  public: static Single Asinh(Single x);
  public: static Single Atan(Single x);
  public: static Single Atan2(Single y, Single x);
  public: static Single Atanh(Single x);
  public: static Single Cbrt(Single x);
  public: static Single Ceiling(Single x);
  public: static Single Cos(Single x);
  public: static Single Cosh(Single x);
  public: static Single Exp(Single x);
  public: static Single Floor(Single x);
  public: static Single FusedMultiplyAdd(Single x, Single y, Single z);
  public: static Int32 ILogB(Single x);
  public: static Single Log(Single x);
  public: static Single Log2(Single x);
  public: static Single Log10(Single x);
  public: static Single Pow(Single x, Single y);
  public: static Single ScaleB(Single x, Int32 n);
  public: static Single Sin(Single x);
  public: static Single Sinh(Single x);
  public: static Single Sqrt(Single x);
  public: static Single Tan(Single x);
  public: static Single Tanh(Single x);
  private: static Single ModF(Single x, Single* intptr);
  public: static Single Abs(Single x);
  public: static Single BitDecrement(Single x);
  public: static Single BitIncrement(Single x);
  public: static Single CopySign(Single x, Single y);
  public: static Single IEEERemainder(Single x, Single y);
  public: static Single Log(Single x, Single y);
  public: static Single Max(Single x, Single y);
  public: static Single MaxMagnitude(Single x, Single y);
  public: static Single Min(Single x, Single y);
  public: static Single MinMagnitude(Single x, Single y);
  public: static Single Round(Single x);
  public: static Single Round(Single x, Int32 digits);
  public: static Single Round(Single x, MidpointRounding mode);
  public: static Single Round(Single x, Int32 digits, MidpointRounding mode);
  public: static Int32 Sign(Single x);
  public: static Single Truncate(Single x);
  public: static Single E;
  public: static Single PI;
  private: static Array<Single> roundPower10Single;
};
} // namespace MathFNamespace
using MathF = MathFNamespace::MathF;
} // namespace System::Private::CoreLib::System