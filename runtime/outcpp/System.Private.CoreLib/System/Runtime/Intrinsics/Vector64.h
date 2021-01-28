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
namespace System::Private::CoreLib::System::Runtime::Intrinsics {
FORWARDS_(Vector128)
namespace Vector64Namespace {
template <class ...T>
class Vector64 {
};
template <>
class Vector64<> {
  public: template <class T, class U>
  static Vector64<U> As(Vector64<T> vector);
  public: template <class T>
  static Vector64<Byte> AsByte(Vector64<T> vector);
  public: template <class T>
  static Vector64<Double> AsDouble(Vector64<T> vector);
  public: template <class T>
  static Vector64<Int16> AsInt16(Vector64<T> vector);
  public: template <class T>
  static Vector64<Int32> AsInt32(Vector64<T> vector);
  public: template <class T>
  static Vector64<Int64> AsInt64(Vector64<T> vector);
  public: template <class T>
  static Vector64<SByte> AsSByte(Vector64<T> vector);
  public: template <class T>
  static Vector64<Single> AsSingle(Vector64<T> vector);
  public: template <class T>
  static Vector64<UInt16> AsUInt16(Vector64<T> vector);
  public: template <class T>
  static Vector64<UInt32> AsUInt32(Vector64<T> vector);
  public: template <class T>
  static Vector64<UInt64> AsUInt64(Vector64<T> vector);
  public: static Vector64<Byte> Create(Byte value);
  public: static Vector64<Double> Create(Double value);
  public: static Vector64<Int16> Create(Int16 value);
  public: static Vector64<Int32> Create(Int32 value);
  public: static Vector64<Int64> Create(Int64 value);
  public: static Vector64<SByte> Create(SByte value);
  public: static Vector64<Single> Create(Single value);
  public: static Vector64<UInt16> Create(UInt16 value);
  public: static Vector64<UInt32> Create(UInt32 value);
  public: static Vector64<UInt64> Create(UInt64 value);
  public: static Vector64<Byte> Create(Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7);
  public: static Vector64<Int16> Create(Int16 e0, Int16 e1, Int16 e2, Int16 e3);
  public: static Vector64<Int32> Create(Int32 e0, Int32 e1);
  public: static Vector64<SByte> Create(SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7);
  public: static Vector64<Single> Create(Single e0, Single e1);
  public: static Vector64<UInt16> Create(UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3);
  public: static Vector64<UInt32> Create(UInt32 e0, UInt32 e1);
  public: static Vector64<Byte> CreateScalar(Byte value);
  public: static Vector64<Int16> CreateScalar(Int16 value);
  public: static Vector64<Int32> CreateScalar(Int32 value);
  public: static Vector64<SByte> CreateScalar(SByte value);
  public: static Vector64<Single> CreateScalar(Single value);
  public: static Vector64<UInt16> CreateScalar(UInt16 value);
  public: static Vector64<UInt32> CreateScalar(UInt32 value);
  public: static Vector64<Byte> CreateScalarUnsafe(Byte value);
  public: static Vector64<Int16> CreateScalarUnsafe(Int16 value);
  public: static Vector64<Int32> CreateScalarUnsafe(Int32 value);
  public: static Vector64<SByte> CreateScalarUnsafe(SByte value);
  public: static Vector64<Single> CreateScalarUnsafe(Single value);
  public: static Vector64<UInt16> CreateScalarUnsafe(UInt16 value);
  public: static Vector64<UInt32> CreateScalarUnsafe(UInt32 value);
  public: template <class T>
  static T GetElement(Vector64<T> vector, Int32 index);
  public: template <class T>
  static Vector64<T> WithElement(Vector64<T> vector, Int32 index, T value);
  public: template <class T>
  static T ToScalar(Vector64<T> vector);
  public: template <class T>
  static Vector128<T> ToVector128(Vector64<T> vector);
  public: template <class T>
  static Vector128<T> ToVector128Unsafe(Vector64<T> vector);
  public: static Vector64<Byte> _Create_g__SoftwareFallback12_0(Byte value);
  public: static Vector64<Double> _Create_g__SoftwareFallback13_0(Double value);
  public: static Vector64<Int16> _Create_g__SoftwareFallback14_0(Int16 value);
  public: static Vector64<Int32> _Create_g__SoftwareFallback15_0(Int32 value);
  public: static Vector64<Int64> _Create_g__SoftwareFallback16_0(Int64 value);
  public: static Vector64<SByte> _Create_g__SoftwareFallback17_0(SByte value);
  public: static Vector64<Single> _Create_g__SoftwareFallback18_0(Single value);
  public: static Vector64<UInt16> _Create_g__SoftwareFallback19_0(UInt16 value);
  public: static Vector64<UInt32> _Create_g__SoftwareFallback20_0(UInt32 value);
  public: static Vector64<UInt64> _Create_g__SoftwareFallback21_0(UInt64 value);
  public: static Vector64<Byte> _Create_g__SoftwareFallback22_0(Byte e0, Byte e1, Byte e2, Byte e3, Byte e4, Byte e5, Byte e6, Byte e7);
  public: static Vector64<Int16> _Create_g__SoftwareFallback23_0(Int16 e0, Int16 e1, Int16 e2, Int16 e3);
  public: static Vector64<Int32> _Create_g__SoftwareFallback24_0(Int32 e0, Int32 e1);
  public: static Vector64<SByte> _Create_g__SoftwareFallback25_0(SByte e0, SByte e1, SByte e2, SByte e3, SByte e4, SByte e5, SByte e6, SByte e7);
  public: static Vector64<Single> _Create_g__SoftwareFallback26_0(Single e0, Single e1);
  public: static Vector64<UInt16> _Create_g__SoftwareFallback27_0(UInt16 e0, UInt16 e1, UInt16 e2, UInt16 e3);
  public: static Vector64<UInt32> _Create_g__SoftwareFallback28_0(UInt32 e0, UInt32 e1);
  public: static Vector64<Byte> _CreateScalar_g__SoftwareFallback29_0(Byte value);
  public: static Vector64<Int16> _CreateScalar_g__SoftwareFallback30_0(Int16 value);
  public: static Vector64<Int32> _CreateScalar_g__SoftwareFallback31_0(Int32 value);
  public: static Vector64<SByte> _CreateScalar_g__SoftwareFallback32_0(SByte value);
  public: static Vector64<Single> _CreateScalar_g__SoftwareFallback33_0(Single value);
  public: static Vector64<UInt16> _CreateScalar_g__SoftwareFallback34_0(UInt16 value);
  public: static Vector64<UInt32> _CreateScalar_g__SoftwareFallback35_0(UInt32 value);
};
template <class T>
struct Vector64<T> : public valueType<Vector64<T>> {
  public: using interface = rt::TypeList<IEquatable<Vector64<T>>>;
  public: static Int32 get_Count();
  public: static Vector64<T> get_Zero();
  public: static Vector64<T> get_AllBitsSet();
  public: String get_DisplayString();
  public: static Boolean get_IsSupported();
  public: Boolean Equals(Vector64<T> other);
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  public: String ToString();
  private: UInt64 _00;
};
} // namespace Vector64Namespace
template <class ...T>
using Vector64 = Vector64Namespace::Vector64<T...>;
} // namespace System::Private::CoreLib::System::Runtime::Intrinsics
