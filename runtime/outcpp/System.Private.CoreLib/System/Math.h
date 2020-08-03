#pragma once

#include <System.Private.CoreLib/System/Double.h>

namespace System::Private::CoreLib::System {
enum class MidpointRounding;
FORWARD_(Array, T1, T2)
FORWARDS(Byte)
FORWARDS(Decimal)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
namespace MathNamespace {
class Math {
  public: static Double Abs(Double value);
  public: static Single Abs(Single value);
  public: static Double Acos(Double d);
  public: static Double Acosh(Double d);
  public: static Double Asin(Double d);
  public: static Double Asinh(Double d);
  public: static Double Atan(Double d);
  public: static Double Atan2(Double y, Double x);
  public: static Double Atanh(Double d);
  public: static Double Cbrt(Double d);
  public: static Double Ceiling(Double a);
  public: static Double Cos(Double d);
  public: static Double Cosh(Double value);
  public: static Double Exp(Double d);
  public: static Double Floor(Double d);
  public: static Double FusedMultiplyAdd(Double x, Double y, Double z);
  public: static Int32 ILogB(Double x);
  public: static Double Log(Double d);
  public: static Double Log2(Double x);
  public: static Double Log10(Double d);
  public: static Double Pow(Double x, Double y);
  public: static Double ScaleB(Double x, Int32 n);
  public: static Double Sin(Double a);
  public: static Double Sinh(Double value);
  public: static Double Sqrt(Double d);
  public: static Double Tan(Double a);
  public: static Double Tanh(Double value);
  private: static Double ModF(Double x, Double* intptr);
  public: static Int16 Abs(Int16 value);
  public: static Int32 Abs(Int32 value);
  public: static Int64 Abs(Int64 value);
  public: static SByte Abs(SByte value);
  public: static Decimal Abs(Decimal value);
  private: static void ThrowAbsOverflow();
  public: static Int64 BigMul(Int32 a, Int32 b);
  public: static UInt64 BigMul(UInt64 a, UInt64 b, UInt64& low);
  public: static Int64 BigMul(Int64 a, Int64 b, Int64& low);
  public: static Double BitDecrement(Double x);
  public: static Double BitIncrement(Double x);
  public: static Double CopySign(Double x, Double y);
  public: static Int32 DivRem(Int32 a, Int32 b, Int32& result);
  public: static Int64 DivRem(Int64 a, Int64 b, Int64& result);
  public: static UInt32 DivRem(UInt32 a, UInt32 b, UInt32& result);
  public: static UInt64 DivRem(UInt64 a, UInt64 b, UInt64& result);
  public: static Decimal Ceiling(Decimal d);
  public: static Byte Clamp(Byte value, Byte min, Byte max);
  public: static Decimal Clamp(Decimal value, Decimal min, Decimal max);
  public: static Double Clamp(Double value, Double min, Double max);
  public: static Int16 Clamp(Int16 value, Int16 min, Int16 max);
  public: static Int32 Clamp(Int32 value, Int32 min, Int32 max);
  public: static Int64 Clamp(Int64 value, Int64 min, Int64 max);
  public: static SByte Clamp(SByte value, SByte min, SByte max);
  public: static Single Clamp(Single value, Single min, Single max);
  public: static UInt16 Clamp(UInt16 value, UInt16 min, UInt16 max);
  public: static UInt32 Clamp(UInt32 value, UInt32 min, UInt32 max);
  public: static UInt64 Clamp(UInt64 value, UInt64 min, UInt64 max);
  public: static Decimal Floor(Decimal d);
  public: static Double IEEERemainder(Double x, Double y);
  public: static Double Log(Double a, Double newBase);
  public: static Byte Max(Byte val1, Byte val2);
  public: static Decimal Max(Decimal val1, Decimal val2);
  public: static Double Max(Double val1, Double val2);
  public: static Int16 Max(Int16 val1, Int16 val2);
  public: static Int32 Max(Int32 val1, Int32 val2);
  public: static Int64 Max(Int64 val1, Int64 val2);
  public: static SByte Max(SByte val1, SByte val2);
  public: static Single Max(Single val1, Single val2);
  public: static UInt16 Max(UInt16 val1, UInt16 val2);
  public: static UInt32 Max(UInt32 val1, UInt32 val2);
  public: static UInt64 Max(UInt64 val1, UInt64 val2);
  public: static Double MaxMagnitude(Double x, Double y);
  public: static Byte Min(Byte val1, Byte val2);
  public: static Decimal Min(Decimal val1, Decimal val2);
  public: static Double Min(Double val1, Double val2);
  public: static Int16 Min(Int16 val1, Int16 val2);
  public: static Int32 Min(Int32 val1, Int32 val2);
  public: static Int64 Min(Int64 val1, Int64 val2);
  public: static SByte Min(SByte val1, SByte val2);
  public: static Single Min(Single val1, Single val2);
  public: static UInt16 Min(UInt16 val1, UInt16 val2);
  public: static UInt32 Min(UInt32 val1, UInt32 val2);
  public: static UInt64 Min(UInt64 val1, UInt64 val2);
  public: static Double MinMagnitude(Double x, Double y);
  public: static Decimal Round(Decimal d);
  public: static Decimal Round(Decimal d, Int32 decimals);
  public: static Decimal Round(Decimal d, MidpointRounding mode);
  public: static Decimal Round(Decimal d, Int32 decimals, MidpointRounding mode);
  public: static Double Round(Double a);
  public: static Double Round(Double value, Int32 digits);
  public: static Double Round(Double value, MidpointRounding mode);
  public: static Double Round(Double value, Int32 digits, MidpointRounding mode);
  public: static Int32 Sign(Decimal value);
  public: static Int32 Sign(Double value);
  public: static Int32 Sign(Int16 value);
  public: static Int32 Sign(Int32 value);
  public: static Int32 Sign(Int64 value);
  public: static Int32 Sign(SByte value);
  public: static Int32 Sign(Single value);
  public: static Decimal Truncate(Decimal d);
  public: static Double Truncate(Double d);
  private: template <class T>
  static void ThrowMinMaxException(T min, T max);
  private: static void SCtor();
  public: static constexpr Double E = 2.718281828459045;
  public: static constexpr Double PI = 3.141592653589793;
  private: static Array<Double> roundPower10Double;
};
} // namespace MathNamespace
using Math = MathNamespace::Math;
} // namespace System::Private::CoreLib::System
