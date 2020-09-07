#pragma once

#include <System.Private.CoreLib/System/UInt64.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Double)
FORWARD(IEquatable, T)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARDS(SByte)
FORWARDS(Single)
FORWARD(String)
FORWARDS(UInt16)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Numerics {
FORWARDS_(Vector, T1, T2)
} // namespace System::Private::CoreLib::System::Numerics
namespace System::Private::CoreLib::System::Runtime::Intrinsics {
FORWARDS_(Vector128, T1, T2)
namespace Vector256Namespace {
using namespace System::Numerics;
template <class T1 = void, class T2 = void>
class Vector256 {
};
template <>
class Vector256<> {
  public: template <class T, class U>
  static Vector256<U> As(Vector256<T> vector);
  public: template <class T>
  static Vector256<Byte> AsByte(Vector256<T> vector);
  public: template <class T>
  static Vector256<Double> AsDouble(Vector256<T> vector);
  public: template <class T>
  static Vector256<Int16> AsInt16(Vector256<T> vector);
  public: template <class T>
  static Vector256<Int32> AsInt32(Vector256<T> vector);
  public: template <class T>
  static Vector256<Int64> AsInt64(Vector256<T> vector);
  public: template <class T>
  static Vector256<SByte> AsSByte(Vector256<T> vector);
  public: template <class T>
  static Vector256<Single> AsSingle(Vector256<T> vector);
  public: template <class T>
  static Vector256<UInt16> AsUInt16(Vector256<T> vector);
  public: template <class T>
  static Vector256<UInt32> AsUInt32(Vector256<T> vector);
  public: template <class T>
  static Vector256<UInt64> AsUInt64(Vector256<T> vector);
  public: template <class T>
  static Vector256<T> AsVector256(Vector<T> value);
  public: template <class T>
  static Vector<T> AsVector(Vector256<T> value);
  public: static Vector256<Byte> Create(Byte value);
  public: static Vector256<Double> Create(Double value);
  public: static Vector256<Int16> Create(Int16 value);
  public: static Vector256<Int32> Create(Int32 value);
  public: static Vector256<Int64> Create(Int64 value);
  public: static Vector256<SByte> Create(SByte value);
  public: static Vector256<Single> Create(Single value);
  public: static Vector256<UInt16> Create(UInt16 value);
  public: static Vector256<UInt32> Create(UInt32 value);
  public: static Vector256<UInt64> Create(UInt64 value);
  public: static Vector256<Byte> Create(Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7, Byte e8, Byte e9, Byte e10, Byte e11, Byte e12, Byte e13, Byte e14, Byte e15, Byte e16, Byte e17, Byte e18, Byte e19, Byte e20, Byte e21, Byte e22, Byte e23, Byte e24, Byte e25, Byte e26, Byte e27, Byte e28, Byte e29, Byte e30, Byte e31);
  public: static Vector256<Double> Create(Double e0, Double e1, Double e2, Double e3);
  public: static Vector256<Int16> Create(Int16 e0, Int16 e1, Int16 e2, Int16 e3, Int16 e4, Int16 e5, Int16 e6, Int16 e7, Int16 e8, Int16 e9, Int16 e10, Int16 e11, Int16 e12, Int16 e13, Int16 e14, Int16 e15);
  public: static Vector256<Int32> Create(Int32 e0, Int32 e1, Int32 e2, Int32 e3, Int32 e4, Int32 e5, Int32 e6, Int32 e7);
  public: static Vector256<Int64> Create(Int64 e0, Int64 e1, Int64 e2, Int64 e3);
  public: static Vector256<SByte> Create(SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7, SByte e8, SByte e9, SByte e10, SByte e11, SByte e12, SByte e13, SByte e14, SByte e15, SByte e16, SByte e17, SByte e18, SByte e19, SByte e20, SByte e21, SByte e22, SByte e23, SByte e24, SByte e25, SByte e26, SByte e27, SByte e28, SByte e29, SByte e30, SByte e31);
  public: static Vector256<Single> Create(Single e0, Single e1, Single e2, Single e3, Single e4, Single e5, Single e6, Single e7);
  public: static Vector256<UInt16> Create(UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3, UInt16 e4, UInt16 e5, UInt16 e6, UInt16 e7, UInt16 e8, UInt16 e9, UInt16 e10, UInt16 e11, UInt16 e12, UInt16 e13, UInt16 e14, UInt16 e15);
  public: static Vector256<UInt32> Create(UInt32 e0, UInt32 e1, UInt32 e2, UInt32 e3, UInt32 e4, UInt32 e5, UInt32 e6, UInt32 e7);
  public: static Vector256<UInt64> Create(UInt64 e0, UInt64 e1, UInt64 e2, UInt64 e3);
  public: static Vector256<Byte> Create(Vector128<Byte> lower, Vector128<Byte> upper);
  public: static Vector256<Double> Create(Vector128<Double> lower, Vector128<Double> upper);
  public: static Vector256<Int16> Create(Vector128<Int16> lower, Vector128<Int16> upper);
  public: static Vector256<Int32> Create(Vector128<Int32> lower, Vector128<Int32> upper);
  public: static Vector256<Int64> Create(Vector128<Int64> lower, Vector128<Int64> upper);
  public: static Vector256<SByte> Create(Vector128<SByte> lower, Vector128<SByte> upper);
  public: static Vector256<Single> Create(Vector128<Single> lower, Vector128<Single> upper);
  public: static Vector256<UInt16> Create(Vector128<UInt16> lower, Vector128<UInt16> upper);
  public: static Vector256<UInt32> Create(Vector128<UInt32> lower, Vector128<UInt32> upper);
  public: static Vector256<UInt64> Create(Vector128<UInt64> lower, Vector128<UInt64> upper);
  public: static Vector256<Byte> CreateScalar(Byte value);
  public: static Vector256<Double> CreateScalar(Double value);
  public: static Vector256<Int16> CreateScalar(Int16 value);
  public: static Vector256<Int32> CreateScalar(Int32 value);
  public: static Vector256<Int64> CreateScalar(Int64 value);
  public: static Vector256<SByte> CreateScalar(SByte value);
  public: static Vector256<Single> CreateScalar(Single value);
  public: static Vector256<UInt16> CreateScalar(UInt16 value);
  public: static Vector256<UInt32> CreateScalar(UInt32 value);
  public: static Vector256<UInt64> CreateScalar(UInt64 value);
  public: static Vector256<Byte> CreateScalarUnsafe(Byte value);
  public: static Vector256<Double> CreateScalarUnsafe(Double value);
  public: static Vector256<Int16> CreateScalarUnsafe(Int16 value);
  public: static Vector256<Int32> CreateScalarUnsafe(Int32 value);
  public: static Vector256<Int64> CreateScalarUnsafe(Int64 value);
  public: static Vector256<SByte> CreateScalarUnsafe(SByte value);
  public: static Vector256<Single> CreateScalarUnsafe(Single value);
  public: static Vector256<UInt16> CreateScalarUnsafe(UInt16 value);
  public: static Vector256<UInt32> CreateScalarUnsafe(UInt32 value);
  public: static Vector256<UInt64> CreateScalarUnsafe(UInt64 value);
  public: template <class T>
  static T GetElement(Vector256<T> vector, Int32 index);
  public: template <class T>
  static Vector256<T> WithElement(Vector256<T> vector, Int32 index, T value);
  public: template <class T>
  static Vector128<T> GetLower(Vector256<T> vector);
  public: template <class T>
  static Vector256<T> WithLower(Vector256<T> vector, Vector128<T> value);
  public: template <class T>
  static Vector128<T> GetUpper(Vector256<T> vector);
  public: template <class T>
  static Vector256<T> WithUpper(Vector256<T> vector, Vector128<T> value);
  public: template <class T>
  static T ToScalar(Vector256<T> vector);
  public: static Vector256<Byte> _Create_g__SoftwareFallback14_0(Byte value);
  public: static Vector256<Double> _Create_g__SoftwareFallback15_0(Double value);
  public: static Vector256<Int16> _Create_g__SoftwareFallback16_0(Int16 value);
  public: static Vector256<Int32> _Create_g__SoftwareFallback17_0(Int32 value);
  public: static Vector256<Int64> _Create_g__SoftwareFallback18_0(Int64 value);
  public: static Vector256<SByte> _Create_g__SoftwareFallback19_0(SByte value);
  public: static Vector256<Single> _Create_g__SoftwareFallback20_0(Single value);
  public: static Vector256<UInt16> _Create_g__SoftwareFallback21_0(UInt16 value);
  public: static Vector256<UInt32> _Create_g__SoftwareFallback22_0(UInt32 value);
  public: static Vector256<UInt64> _Create_g__SoftwareFallback23_0(UInt64 value);
  public: static Vector256<Byte> _Create_g__SoftwareFallback24_0(Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7, Byte e8, Byte e9, Byte e10, Byte e11, Byte e12, Byte e13, Byte e14, Byte e15, Byte e16, Byte e17, Byte e18, Byte e19, Byte e20, Byte e21, Byte e22, Byte e23, Byte e24, Byte e25, Byte e26, Byte e27, Byte e28, Byte e29, Byte e30, Byte e31);
  public: static Vector256<Double> _Create_g__SoftwareFallback25_0(Double e0, Double e1, Double e2, Double e3);
  public: static Vector256<Int16> _Create_g__SoftwareFallback26_0(Int16 e0, Int16 e1, Int16 e2, Int16 e3, Int16 e4, Int16 e5, Int16 e6, Int16 e7, Int16 e8, Int16 e9, Int16 e10, Int16 e11, Int16 e12, Int16 e13, Int16 e14, Int16 e15);
  public: static Vector256<Int32> _Create_g__SoftwareFallback27_0(Int32 e0, Int32 e1, Int32 e2, Int32 e3, Int32 e4, Int32 e5, Int32 e6, Int32 e7);
  public: static Vector256<Int64> _Create_g__SoftwareFallback28_0(Int64 e0, Int64 e1, Int64 e2, Int64 e3);
  public: static Vector256<SByte> _Create_g__SoftwareFallback29_0(SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7, SByte e8, SByte e9, SByte e10, SByte e11, SByte e12, SByte e13, SByte e14, SByte e15, SByte e16, SByte e17, SByte e18, SByte e19, SByte e20, SByte e21, SByte e22, SByte e23, SByte e24, SByte e25, SByte e26, SByte e27, SByte e28, SByte e29, SByte e30, SByte e31);
  public: static Vector256<Single> _Create_g__SoftwareFallback30_0(Single e0, Single e1, Single e2, Single e3, Single e4, Single e5, Single e6, Single e7);
  public: static Vector256<UInt16> _Create_g__SoftwareFallback31_0(UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3, UInt16 e4, UInt16 e5, UInt16 e6, UInt16 e7, UInt16 e8, UInt16 e9, UInt16 e10, UInt16 e11, UInt16 e12, UInt16 e13, UInt16 e14, UInt16 e15);
  public: static Vector256<UInt32> _Create_g__SoftwareFallback32_0(UInt32 e0, UInt32 e1, UInt32 e2, UInt32 e3, UInt32 e4, UInt32 e5, UInt32 e6, UInt32 e7);
  public: static Vector256<UInt64> _Create_g__SoftwareFallback33_0(UInt64 e0, UInt64 e1, UInt64 e2, UInt64 e3);
  public: static Vector256<Byte> _Create_g__SoftwareFallback34_0(Vector128<Byte> lower, Vector128<Byte> upper);
  public: static Vector256<Double> _Create_g__SoftwareFallback35_0(Vector128<Double> lower, Vector128<Double> upper);
  public: static Vector256<Int16> _Create_g__SoftwareFallback36_0(Vector128<Int16> lower, Vector128<Int16> upper);
  public: static Vector256<Int32> _Create_g__SoftwareFallback37_0(Vector128<Int32> lower, Vector128<Int32> upper);
  public: static Vector256<Int64> _Create_g__SoftwareFallback38_0(Vector128<Int64> lower, Vector128<Int64> upper);
  public: static Vector256<SByte> _Create_g__SoftwareFallback39_0(Vector128<SByte> lower, Vector128<SByte> upper);
  public: static Vector256<Single> _Create_g__SoftwareFallback40_0(Vector128<Single> lower, Vector128<Single> upper);
  public: static Vector256<UInt16> _Create_g__SoftwareFallback41_0(Vector128<UInt16> lower, Vector128<UInt16> upper);
  public: static Vector256<UInt32> _Create_g__SoftwareFallback42_0(Vector128<UInt32> lower, Vector128<UInt32> upper);
  public: static Vector256<UInt64> _Create_g__SoftwareFallback43_0(Vector128<UInt64> lower, Vector128<UInt64> upper);
  public: static Vector256<Byte> _CreateScalar_g__SoftwareFallback44_0(Byte value);
  public: static Vector256<Double> _CreateScalar_g__SoftwareFallback45_0(Double value);
  public: static Vector256<Int16> _CreateScalar_g__SoftwareFallback46_0(Int16 value);
  public: static Vector256<Int32> _CreateScalar_g__SoftwareFallback47_0(Int32 value);
  public: static Vector256<Int64> _CreateScalar_g__SoftwareFallback48_0(Int64 value);
  public: static Vector256<SByte> _CreateScalar_g__SoftwareFallback49_0(SByte value);
  public: static Vector256<Single> _CreateScalar_g__SoftwareFallback50_0(Single value);
  public: static Vector256<UInt16> _CreateScalar_g__SoftwareFallback51_0(UInt16 value);
  public: static Vector256<UInt32> _CreateScalar_g__SoftwareFallback52_0(UInt32 value);
  public: static Vector256<UInt64> _CreateScalar_g__SoftwareFallback53_0(UInt64 value);
  public: template <class T>
  static Vector256<T> _WithLower_g__SoftwareFallback67_0(Vector256<T> vector, Vector128<T> value);
  public: template <class T>
  static Vector128<T> _GetUpper_g__SoftwareFallback68_0(Vector256<T> vector);
  public: template <class T>
  static Vector256<T> _WithUpper_g__SoftwareFallback69_0(Vector256<T> vector, Vector128<T> value);
};
template <class T>
struct Vector256<T> : public valueType<Vector256<T>> {
  public: using interface = rt::TypeList<IEquatable<Vector256<T>>>;
  public: static Int32 get_Count();
  public: static Vector256<T> get_Zero();
  public: static Vector256<T> get_AllBitsSet();
  public: String get_DisplayString();
  public: static Boolean get_IsSupported();
  public: Boolean Equals(Vector256<T> other);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: static Boolean _Equals_g__SoftwareFallback14_0(Vector256<T>& vector, Vector256<T> other);
  private: UInt64 _00;
  private: UInt64 _01;
  private: UInt64 _02;
  private: UInt64 _03;
};
} // namespace Vector256Namespace
template <class T1 = void, class T2 = void>
using Vector256 = Vector256Namespace::Vector256<T1, T2>;
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
