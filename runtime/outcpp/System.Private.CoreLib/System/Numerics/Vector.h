#pragma once

#include <System.Private.CoreLib/System/Numerics/Register.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(Double)
FORWARD(IEquatable, T)
FORWARD(IFormatProvider)
FORWARD(IFormattable)
FORWARDS(Int16)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARDS(ReadOnlySpan, T)
FORWARDS(SByte)
FORWARDS(Single)
FORWARDS(Span, T)
FORWARD(String)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Numerics {
namespace VectorNamespace {
template <class ...T>
class Vector {
};
template <>
class Vector<> {
  public: static Boolean get_IsHardwareAccelerated();
  public: static void Widen(Vector<Byte> source, Vector<UInt16>& low, Vector<UInt16>& high);
  public: static void Widen(Vector<UInt16> source, Vector<UInt32>& low, Vector<UInt32>& high);
  public: static void Widen(Vector<UInt32> source, Vector<UInt64>& low, Vector<UInt64>& high);
  public: static void Widen(Vector<SByte> source, Vector<Int16>& low, Vector<Int16>& high);
  public: static void Widen(Vector<Int16> source, Vector<Int32>& low, Vector<Int32>& high);
  public: static void Widen(Vector<Int32> source, Vector<Int64>& low, Vector<Int64>& high);
  public: static void Widen(Vector<Single> source, Vector<Double>& low, Vector<Double>& high);
  public: static Vector<Byte> Narrow(Vector<UInt16> low, Vector<UInt16> high);
  public: static Vector<UInt16> Narrow(Vector<UInt32> low, Vector<UInt32> high);
  public: static Vector<UInt32> Narrow(Vector<UInt64> low, Vector<UInt64> high);
  public: static Vector<SByte> Narrow(Vector<Int16> low, Vector<Int16> high);
  public: static Vector<Int16> Narrow(Vector<Int32> low, Vector<Int32> high);
  public: static Vector<Int32> Narrow(Vector<Int64> low, Vector<Int64> high);
  public: static Vector<Single> Narrow(Vector<Double> low, Vector<Double> high);
  public: static Vector<Single> ConvertToSingle(Vector<Int32> value);
  public: static Vector<Single> ConvertToSingle(Vector<UInt32> value);
  public: static Vector<Double> ConvertToDouble(Vector<Int64> value);
  public: static Vector<Double> ConvertToDouble(Vector<UInt64> value);
  public: static Vector<Int32> ConvertToInt32(Vector<Single> value);
  public: static Vector<UInt32> ConvertToUInt32(Vector<Single> value);
  public: static Vector<Int64> ConvertToInt64(Vector<Double> value);
  public: static Vector<UInt64> ConvertToUInt64(Vector<Double> value);
  public: static void ThrowInsufficientNumberOfElementsException(Int32 requiredElementCount);
  public: static Vector<Single> ConditionalSelect(Vector<Int32> condition, Vector<Single> left, Vector<Single> right);
  public: static Vector<Double> ConditionalSelect(Vector<Int64> condition, Vector<Double> left, Vector<Double> right);
  public: template <class T>
  static Vector<T> ConditionalSelect(Vector<T> condition, Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> Equals(Vector<T> left, Vector<T> right);
  public: static Vector<Int32> Equals(Vector<Single> left, Vector<Single> right);
  public: static Vector<Int32> Equals(Vector<Int32> left, Vector<Int32> right);
  public: static Vector<Int64> Equals(Vector<Double> left, Vector<Double> right);
  public: static Vector<Int64> Equals(Vector<Int64> left, Vector<Int64> right);
  public: template <class T>
  static Boolean EqualsAll(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Boolean EqualsAny(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> LessThan(Vector<T> left, Vector<T> right);
  public: static Vector<Int32> LessThan(Vector<Single> left, Vector<Single> right);
  public: static Vector<Int32> LessThan(Vector<Int32> left, Vector<Int32> right);
  public: static Vector<Int64> LessThan(Vector<Double> left, Vector<Double> right);
  public: static Vector<Int64> LessThan(Vector<Int64> left, Vector<Int64> right);
  public: template <class T>
  static Boolean LessThanAll(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Boolean LessThanAny(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> LessThanOrEqual(Vector<T> left, Vector<T> right);
  public: static Vector<Int32> LessThanOrEqual(Vector<Single> left, Vector<Single> right);
  public: static Vector<Int32> LessThanOrEqual(Vector<Int32> left, Vector<Int32> right);
  public: static Vector<Int64> LessThanOrEqual(Vector<Int64> left, Vector<Int64> right);
  public: static Vector<Int64> LessThanOrEqual(Vector<Double> left, Vector<Double> right);
  public: template <class T>
  static Boolean LessThanOrEqualAll(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Boolean LessThanOrEqualAny(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> GreaterThan(Vector<T> left, Vector<T> right);
  public: static Vector<Int32> GreaterThan(Vector<Single> left, Vector<Single> right);
  public: static Vector<Int32> GreaterThan(Vector<Int32> left, Vector<Int32> right);
  public: static Vector<Int64> GreaterThan(Vector<Double> left, Vector<Double> right);
  public: static Vector<Int64> GreaterThan(Vector<Int64> left, Vector<Int64> right);
  public: template <class T>
  static Boolean GreaterThanAll(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Boolean GreaterThanAny(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> GreaterThanOrEqual(Vector<T> left, Vector<T> right);
  public: static Vector<Int32> GreaterThanOrEqual(Vector<Single> left, Vector<Single> right);
  public: static Vector<Int32> GreaterThanOrEqual(Vector<Int32> left, Vector<Int32> right);
  public: static Vector<Int64> GreaterThanOrEqual(Vector<Int64> left, Vector<Int64> right);
  public: static Vector<Int64> GreaterThanOrEqual(Vector<Double> left, Vector<Double> right);
  public: template <class T>
  static Boolean GreaterThanOrEqualAll(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Boolean GreaterThanOrEqualAny(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> Abs(Vector<T> value);
  public: template <class T>
  static Vector<T> Min(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> Max(Vector<T> left, Vector<T> right);
  public: template <class T>
  static T Dot(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> SquareRoot(Vector<T> value);
  public: static Vector<Single> Ceiling(Vector<Single> value);
  public: static Vector<Double> Ceiling(Vector<Double> value);
  public: static Vector<Single> Floor(Vector<Single> value);
  public: static Vector<Double> Floor(Vector<Double> value);
  public: template <class T>
  static Vector<T> Add(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> Subtract(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> Multiply(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> Multiply(Vector<T> left, T right);
  public: template <class T>
  static Vector<T> Multiply(T left, Vector<T> right);
  public: template <class T>
  static Vector<T> Divide(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> Negate(Vector<T> value);
  public: template <class T>
  static Vector<T> BitwiseAnd(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> BitwiseOr(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> OnesComplement(Vector<T> value);
  public: template <class T>
  static Vector<T> Xor(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<T> AndNot(Vector<T> left, Vector<T> right);
  public: template <class T>
  static Vector<Byte> AsVectorByte(Vector<T> value);
  public: template <class T>
  static Vector<SByte> AsVectorSByte(Vector<T> value);
  public: template <class T>
  static Vector<UInt16> AsVectorUInt16(Vector<T> value);
  public: template <class T>
  static Vector<Int16> AsVectorInt16(Vector<T> value);
  public: template <class T>
  static Vector<UInt32> AsVectorUInt32(Vector<T> value);
  public: template <class T>
  static Vector<Int32> AsVectorInt32(Vector<T> value);
  public: template <class T>
  static Vector<UInt64> AsVectorUInt64(Vector<T> value);
  public: template <class T>
  static Vector<Int64> AsVectorInt64(Vector<T> value);
  public: template <class T>
  static Vector<Single> AsVectorSingle(Vector<T> value);
  public: template <class T>
  static Vector<Double> AsVectorDouble(Vector<T> value);
};
template <class T>
struct Vector<T> : public valueType<Vector<T>> {
  public: using interface = rt::TypeList<IEquatable<Vector<T>>, IFormattable>;
  public: static Int32 get_Count();
  public: static Vector<T> get_Zero();
  public: static Vector<T> get_One();
  public: static Vector<T> get_AllBitsSet();
  public: T get_Item(Int32 index);
  public: explicit Vector(T value);
  public: explicit Vector(Array<T> values);
  public: explicit Vector(Array<T> values, Int32 index);
  public: explicit Vector(void* dataPointer);
  private: explicit Vector(Register& existingRegister);
  public: explicit Vector(ReadOnlySpan<Byte> values);
  public: explicit Vector(ReadOnlySpan<T> values);
  public: explicit Vector(Span<T> values);
  public: void CopyTo(Span<Byte> destination);
  public: void CopyTo(Span<T> destination);
  public: void CopyTo(Array<T> destination);
  public: void CopyTo(Array<T> destination, Int32 startIndex);
  public: Boolean Equals(Object obj);
  public: Boolean Equals(Vector<T> other);
  public: Int32 GetHashCode();
  public: String ToString();
  public: String ToString(String format);
  public: String ToString(String format, IFormatProvider formatProvider);
  public: Boolean TryCopyTo(Span<Byte> destination);
  public: Boolean TryCopyTo(Span<T> destination);
  public: static Vector<T> op_Addition(Vector<T> left, Vector<T> right);
  public: static Vector<T> op_Subtraction(Vector<T> left, Vector<T> right);
  public: static Vector<T> op_Multiply(Vector<T> left, Vector<T> right);
  public: static Vector<T> op_Multiply(Vector<T> value, T factor);
  public: static Vector<T> op_Multiply(T factor, Vector<T> value);
  public: static Vector<T> op_Division(Vector<T> left, Vector<T> right);
  public: static Vector<T> op_UnaryNegation(Vector<T> value);
  public: static Vector<T> op_BitwiseAnd(Vector<T> left, Vector<T> right);
  public: static Vector<T> op_BitwiseOr(Vector<T> left, Vector<T> right);
  public: static Vector<T> op_ExclusiveOr(Vector<T> left, Vector<T> right);
  public: static Vector<T> op_OnesComplement(Vector<T> value);
  public: static Boolean op_Equality(Vector<T> left, Vector<T> right);
  public: static Boolean op_Inequality(Vector<T> left, Vector<T> right);
  public: static Vector<Byte> op_Explicit(Vector<T> value, Vector<Byte>);
  public: static Vector<SByte> op_Explicit(Vector<T> value, Vector<SByte>);
  public: static Vector<UInt16> op_Explicit(Vector<T> value, Vector<UInt16>);
  public: static Vector<Int16> op_Explicit(Vector<T> value, Vector<Int16>);
  public: static Vector<UInt32> op_Explicit(Vector<T> value, Vector<UInt32>);
  public: static Vector<Int32> op_Explicit(Vector<T> value, Vector<Int32>);
  public: static Vector<UInt64> op_Explicit(Vector<T> value, Vector<UInt64>);
  public: static Vector<Int64> op_Explicit(Vector<T> value, Vector<Int64>);
  public: static Vector<Single> op_Explicit(Vector<T> value, Vector<Single>);
  public: static Vector<Double> op_Explicit(Vector<T> value, Vector<Double>);
  public: static Vector<T> Equals(Vector<T> left, Vector<T> right);
  public: static Vector<T> LessThan(Vector<T> left, Vector<T> right);
  public: static Vector<T> GreaterThan(Vector<T> left, Vector<T> right);
  public: static Vector<T> GreaterThanOrEqual(Vector<T> left, Vector<T> right);
  public: static Vector<T> LessThanOrEqual(Vector<T> left, Vector<T> right);
  public: static Vector<T> ConditionalSelect(Vector<T> condition, Vector<T> left, Vector<T> right);
  public: static Vector<T> Abs(Vector<T> value);
  public: static Vector<T> Min(Vector<T> left, Vector<T> right);
  public: static Vector<T> Max(Vector<T> left, Vector<T> right);
  public: static T Dot(Vector<T> left, Vector<T> right);
  public: static Vector<T> SquareRoot(Vector<T> value);
  public: static Vector<T> Ceiling(Vector<T> value);
  public: static Vector<T> Floor(Vector<T> value);
  private: static Boolean ScalarEquals(T left, T right);
  private: static Boolean ScalarLessThan(T left, T right);
  private: static Boolean ScalarGreaterThan(T left, T right);
  private: static T ScalarAdd(T left, T right);
  private: static T ScalarSubtract(T left, T right);
  private: static T ScalarMultiply(T left, T right);
  private: static T ScalarDivide(T left, T right);
  private: static T GetOneValue();
  private: static T GetAllBitsSetValue();
  public: static void cctor();
  public: explicit Vector() {}
  private: Register register一;
  private: static Vector<T> s_zero;
  private: static Vector<T> s_one;
  private: static Vector<T> s_allBitsSet;
};
} // namespace VectorNamespace
template <class ...T>
using Vector = VectorNamespace::Vector<T...>;
} // namespace System::Private::CoreLib::System::Numerics
