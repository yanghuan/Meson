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
FORWARDS_(Vector)
FORWARDS(Vector2)
FORWARDS(Vector3)
FORWARDS(Vector4)
} // namespace System::Private::CoreLib::System::Numerics
namespace System::Private::CoreLib::System::Runtime::Intrinsics {
FORWARDS_(Vector256)
FORWARDS_(Vector64)
namespace Vector128Namespace {
using namespace System::Numerics;
template <class ...T>
class Vector128 {
};
template <>
class Vector128<> {
  public: template <class T, class U>
  static Vector128<U> As(Vector128<T> vector);
  public: template <class T>
  static Vector128<Byte> AsByte(Vector128<T> vector);
  public: template <class T>
  static Vector128<Double> AsDouble(Vector128<T> vector);
  public: template <class T>
  static Vector128<Int16> AsInt16(Vector128<T> vector);
  public: template <class T>
  static Vector128<Int32> AsInt32(Vector128<T> vector);
  public: template <class T>
  static Vector128<Int64> AsInt64(Vector128<T> vector);
  public: template <class T>
  static Vector128<SByte> AsSByte(Vector128<T> vector);
  public: template <class T>
  static Vector128<Single> AsSingle(Vector128<T> vector);
  public: template <class T>
  static Vector128<UInt16> AsUInt16(Vector128<T> vector);
  public: template <class T>
  static Vector128<UInt32> AsUInt32(Vector128<T> vector);
  public: template <class T>
  static Vector128<UInt64> AsUInt64(Vector128<T> vector);
  public: static Vector128<Single> AsVector128(Vector2 value);
  public: static Vector128<Single> AsVector128(Vector3 value);
  public: static Vector128<Single> AsVector128(Vector4 value);
  public: template <class T>
  static Vector128<T> AsVector128(Vector<T> value);
  public: static Vector2 AsVector2(Vector128<Single> value);
  public: static Vector3 AsVector3(Vector128<Single> value);
  public: static Vector4 AsVector4(Vector128<Single> value);
  public: template <class T>
  static Vector<T> AsVector(Vector128<T> value);
  public: static Vector128<Byte> Create(Byte value);
  public: static Vector128<Double> Create(Double value);
  public: static Vector128<Int16> Create(Int16 value);
  public: static Vector128<Int32> Create(Int32 value);
  public: static Vector128<Int64> Create(Int64 value);
  public: static Vector128<SByte> Create(SByte value);
  public: static Vector128<Single> Create(Single value);
  public: static Vector128<UInt16> Create(UInt16 value);
  public: static Vector128<UInt32> Create(UInt32 value);
  public: static Vector128<UInt64> Create(UInt64 value);
  public: static Vector128<Byte> Create(Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7, Byte e8, Byte e9, Byte e10, Byte e11, Byte e12, Byte e13, Byte e14, Byte e15);
  public: static Vector128<Double> Create(Double e0, Double e1);
  public: static Vector128<Int16> Create(Int16 e0, Int16 e1, Int16 e2, Int16 e3, Int16 e4, Int16 e5, Int16 e6, Int16 e7);
  public: static Vector128<Int32> Create(Int32 e0, Int32 e1, Int32 e2, Int32 e3);
  public: static Vector128<Int64> Create(Int64 e0, Int64 e1);
  public: static Vector128<SByte> Create(SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7, SByte e8, SByte e9, SByte e10, SByte e11, SByte e12, SByte e13, SByte e14, SByte e15);
  public: static Vector128<Single> Create(Single e0, Single e1, Single e2, Single e3);
  public: static Vector128<UInt16> Create(UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3, UInt16 e4, UInt16 e5, UInt16 e6, UInt16 e7);
  public: static Vector128<UInt32> Create(UInt32 e0, UInt32 e1, UInt32 e2, UInt32 e3);
  public: static Vector128<UInt64> Create(UInt64 e0, UInt64 e1);
  public: static Vector128<Byte> Create(Vector64<Byte> lower, Vector64<Byte> upper);
  public: static Vector128<Double> Create(Vector64<Double> lower, Vector64<Double> upper);
  public: static Vector128<Int16> Create(Vector64<Int16> lower, Vector64<Int16> upper);
  public: static Vector128<Int32> Create(Vector64<Int32> lower, Vector64<Int32> upper);
  public: static Vector128<Int64> Create(Vector64<Int64> lower, Vector64<Int64> upper);
  public: static Vector128<SByte> Create(Vector64<SByte> lower, Vector64<SByte> upper);
  public: static Vector128<Single> Create(Vector64<Single> lower, Vector64<Single> upper);
  public: static Vector128<UInt16> Create(Vector64<UInt16> lower, Vector64<UInt16> upper);
  public: static Vector128<UInt32> Create(Vector64<UInt32> lower, Vector64<UInt32> upper);
  public: static Vector128<UInt64> Create(Vector64<UInt64> lower, Vector64<UInt64> upper);
  public: static Vector128<Byte> CreateScalar(Byte value);
  public: static Vector128<Double> CreateScalar(Double value);
  public: static Vector128<Int16> CreateScalar(Int16 value);
  public: static Vector128<Int32> CreateScalar(Int32 value);
  public: static Vector128<Int64> CreateScalar(Int64 value);
  public: static Vector128<SByte> CreateScalar(SByte value);
  public: static Vector128<Single> CreateScalar(Single value);
  public: static Vector128<UInt16> CreateScalar(UInt16 value);
  public: static Vector128<UInt32> CreateScalar(UInt32 value);
  public: static Vector128<UInt64> CreateScalar(UInt64 value);
  public: static Vector128<Byte> CreateScalarUnsafe(Byte value);
  public: static Vector128<Double> CreateScalarUnsafe(Double value);
  public: static Vector128<Int16> CreateScalarUnsafe(Int16 value);
  public: static Vector128<Int32> CreateScalarUnsafe(Int32 value);
  public: static Vector128<Int64> CreateScalarUnsafe(Int64 value);
  public: static Vector128<SByte> CreateScalarUnsafe(SByte value);
  public: static Vector128<Single> CreateScalarUnsafe(Single value);
  public: static Vector128<UInt16> CreateScalarUnsafe(UInt16 value);
  public: static Vector128<UInt32> CreateScalarUnsafe(UInt32 value);
  public: static Vector128<UInt64> CreateScalarUnsafe(UInt64 value);
  public: template <class T>
  static T GetElement(Vector128<T> vector, Int32 index);
  public: template <class T>
  static Vector128<T> WithElement(Vector128<T> vector, Int32 index, T value);
  public: template <class T>
  static Vector64<T> GetLower(Vector128<T> vector);
  public: template <class T>
  static Vector128<T> WithLower(Vector128<T> vector, Vector64<T> value);
  public: template <class T>
  static Vector64<T> GetUpper(Vector128<T> vector);
  public: template <class T>
  static Vector128<T> WithUpper(Vector128<T> vector, Vector64<T> value);
  public: template <class T>
  static T ToScalar(Vector128<T> vector);
  public: template <class T>
  static Vector256<T> ToVector256(Vector128<T> vector);
  public: template <class T>
  static Vector256<T> ToVector256Unsafe(Vector128<T> vector);
  public: static Vector128<Byte> _Create_g__SoftwareFallback20_0(Byte value);
  public: static Vector128<Double> _Create_g__SoftwareFallback21_0(Double value);
  public: static Vector128<Int16> _Create_g__SoftwareFallback22_0(Int16 value);
  public: static Vector128<Int32> _Create_g__SoftwareFallback23_0(Int32 value);
  public: static Vector128<Int64> _Create_g__SoftwareFallback24_0(Int64 value);
  public: static Vector128<SByte> _Create_g__SoftwareFallback25_0(SByte value);
  public: static Vector128<Single> _Create_g__SoftwareFallback26_0(Single value);
  public: static Vector128<UInt16> _Create_g__SoftwareFallback27_0(UInt16 value);
  public: static Vector128<UInt32> _Create_g__SoftwareFallback28_0(UInt32 value);
  public: static Vector128<UInt64> _Create_g__SoftwareFallback29_0(UInt64 value);
  public: static Vector128<Byte> _Create_g__SoftwareFallback30_0(Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7, Byte e8, Byte e9, Byte e10, Byte e11, Byte e12, Byte e13, Byte e14, Byte e15);
  public: static Vector128<Double> _Create_g__SoftwareFallback31_0(Double e0, Double e1);
  public: static Vector128<Int16> _Create_g__SoftwareFallback32_0(Int16 e0, Int16 e1, Int16 e2, Int16 e3, Int16 e4, Int16 e5, Int16 e6, Int16 e7);
  public: static Vector128<Int32> _Create_g__SoftwareFallback33_0(Int32 e0, Int32 e1, Int32 e2, Int32 e3);
  public: static Vector128<Int64> _Create_g__SoftwareFallback34_0(Int64 e0, Int64 e1);
  public: static Vector128<SByte> _Create_g__SoftwareFallback35_0(SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7, SByte e8, SByte e9, SByte e10, SByte e11, SByte e12, SByte e13, SByte e14, SByte e15);
  public: static Vector128<Single> _Create_g__SoftwareFallback36_0(Single e0, Single e1, Single e2, Single e3);
  public: static Vector128<UInt16> _Create_g__SoftwareFallback37_0(UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3, UInt16 e4, UInt16 e5, UInt16 e6, UInt16 e7);
  public: static Vector128<UInt32> _Create_g__SoftwareFallback38_0(UInt32 e0, UInt32 e1, UInt32 e2, UInt32 e3);
  public: static Vector128<UInt64> _Create_g__SoftwareFallback39_0(UInt64 e0, UInt64 e1);
  public: static Vector128<Byte> _Create_g__SoftwareFallback40_0(Vector64<Byte> lower, Vector64<Byte> upper);
  public: static Vector128<Double> _Create_g__SoftwareFallback41_0(Vector64<Double> lower, Vector64<Double> upper);
  public: static Vector128<Int16> _Create_g__SoftwareFallback42_0(Vector64<Int16> lower, Vector64<Int16> upper);
  public: static Vector128<Int32> _Create_g__SoftwareFallback43_0(Vector64<Int32> lower, Vector64<Int32> upper);
  public: static Vector128<Int64> _Create_g__SoftwareFallback44_0(Vector64<Int64> lower, Vector64<Int64> upper);
  public: static Vector128<SByte> _Create_g__SoftwareFallback45_0(Vector64<SByte> lower, Vector64<SByte> upper);
  public: static Vector128<Single> _Create_g__SoftwareFallback46_0(Vector64<Single> lower, Vector64<Single> upper);
  public: static Vector128<UInt16> _Create_g__SoftwareFallback47_0(Vector64<UInt16> lower, Vector64<UInt16> upper);
  public: static Vector128<UInt32> _Create_g__SoftwareFallback48_0(Vector64<UInt32> lower, Vector64<UInt32> upper);
  public: static Vector128<UInt64> _Create_g__SoftwareFallback49_0(Vector64<UInt64> lower, Vector64<UInt64> upper);
  public: static Vector128<Byte> _CreateScalar_g__SoftwareFallback50_0(Byte value);
  public: static Vector128<Double> _CreateScalar_g__SoftwareFallback51_0(Double value);
  public: static Vector128<Int16> _CreateScalar_g__SoftwareFallback52_0(Int16 value);
  public: static Vector128<Int32> _CreateScalar_g__SoftwareFallback53_0(Int32 value);
  public: static Vector128<Int64> _CreateScalar_g__SoftwareFallback54_0(Int64 value);
  public: static Vector128<SByte> _CreateScalar_g__SoftwareFallback55_0(SByte value);
  public: static Vector128<Single> _CreateScalar_g__SoftwareFallback56_0(Single value);
  public: static Vector128<UInt16> _CreateScalar_g__SoftwareFallback57_0(UInt16 value);
  public: static Vector128<UInt32> _CreateScalar_g__SoftwareFallback58_0(UInt32 value);
  public: static Vector128<UInt64> _CreateScalar_g__SoftwareFallback59_0(UInt64 value);
  public: template <class T>
  static Vector128<T> _WithLower_g__SoftwareFallback73_0(Vector128<T> vector, Vector64<T> value);
  public: template <class T>
  static Vector128<T> _WithUpper_g__SoftwareFallback75_0(Vector128<T> vector, Vector64<T> value);
};
template <class T>
struct Vector128<T> : public valueType<Vector128<T>> {
  public: using interface = rt::TypeList<IEquatable<Vector128<T>>>;
  public: static Int32 get_Count();
  public: static Vector128<T> get_Zero();
  public: static Vector128<T> get_AllBitsSet();
  public: String get_DisplayString();
  public: static Boolean get_IsSupported();
  public: Boolean Equals(Vector128<T> other);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  public: static Boolean _Equals_g__SoftwareFallback12_0(Vector128<T>& vector, Vector128<T> other);
  private: UInt64 _00;
  private: UInt64 _01;
};
} // namespace Vector128Namespace
template <class ...T>
using Vector128 = Vector128Namespace::Vector128<T...>;
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
