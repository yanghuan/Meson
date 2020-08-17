#include "Vector-dep.h"

#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Numerics/Vector-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Numerics::VectorNamespace {
Boolean Vector<>::get_IsHardwareAccelerated() {
  return false;
}

void Vector<>::Widen(Vector<Byte> source, Vector<UInt16>& low, Vector<UInt16>& high) {
  Int32 count = Vector<Byte>::get_Count();
  UInt16 default[count / 2] = {};
  UInt16* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = source[i];
  }
  UInt16 extern[count / 2] = {};
  UInt16* ptr2 = extern;
  for (Int32 j = 0; j < count / 2; j++) {
    ptr2[j] = source[j + count / 2];
  }
  low = Vector<UInt16>(ptr);
  high = Vector<UInt16>(ptr2);
}

void Vector<>::Widen(Vector<UInt16> source, Vector<UInt32>& low, Vector<UInt32>& high) {
  Int32 count = Vector<UInt16>::get_Count();
  UInt32 default[count / 2] = {};
  UInt32* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = source[i];
  }
  UInt32 extern[count / 2] = {};
  UInt32* ptr2 = extern;
  for (Int32 j = 0; j < count / 2; j++) {
    ptr2[j] = source[j + count / 2];
  }
  low = Vector<UInt32>(ptr);
  high = Vector<UInt32>(ptr2);
}

void Vector<>::Widen(Vector<UInt32> source, Vector<UInt64>& low, Vector<UInt64>& high) {
  Int32 count = Vector<UInt32>::get_Count();
  UInt64 default[count / 2] = {};
  UInt64* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = source[i];
  }
  UInt64 extern[count / 2] = {};
  UInt64* ptr2 = extern;
  for (Int32 j = 0; j < count / 2; j++) {
    ptr2[j] = source[j + count / 2];
  }
  low = Vector<UInt64>(ptr);
  high = Vector<UInt64>(ptr2);
}

void Vector<>::Widen(Vector<SByte> source, Vector<Int16>& low, Vector<Int16>& high) {
  Int32 count = Vector<SByte>::get_Count();
  Int16 default[count / 2] = {};
  Int16* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = source[i];
  }
  Int16 extern[count / 2] = {};
  Int16* ptr2 = extern;
  for (Int32 j = 0; j < count / 2; j++) {
    ptr2[j] = source[j + count / 2];
  }
  low = Vector<Int16>(ptr);
  high = Vector<Int16>(ptr2);
}

void Vector<>::Widen(Vector<Int16> source, Vector<Int32>& low, Vector<Int32>& high) {
  Int32 count = Vector<Int16>::get_Count();
  Int32 default[count / 2] = {};
  Int32* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = source[i];
  }
  Int32 extern[count / 2] = {};
  Int32* ptr2 = extern;
  for (Int32 j = 0; j < count / 2; j++) {
    ptr2[j] = source[j + count / 2];
  }
  low = Vector<Int32>(ptr);
  high = Vector<Int32>(ptr2);
}

void Vector<>::Widen(Vector<Int32> source, Vector<Int64>& low, Vector<Int64>& high) {
  Int32 count = Vector<Int32>::get_Count();
  Int64 default[count / 2] = {};
  Int64* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = source[i];
  }
  Int64 extern[count / 2] = {};
  Int64* ptr2 = extern;
  for (Int32 j = 0; j < count / 2; j++) {
    ptr2[j] = source[j + count / 2];
  }
  low = Vector<Int64>(ptr);
  high = Vector<Int64>(ptr2);
}

void Vector<>::Widen(Vector<Single> source, Vector<Double>& low, Vector<Double>& high) {
  Int32 count = Vector<Single>::get_Count();
  Double default[count / 2] = {};
  Double* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = source[i];
  }
  Double extern[count / 2] = {};
  Double* ptr2 = extern;
  for (Int32 j = 0; j < count / 2; j++) {
    ptr2[j] = source[j + count / 2];
  }
  low = Vector<Double>(ptr);
  high = Vector<Double>(ptr2);
}

Vector<Byte> Vector<>::Narrow(Vector<UInt16> low, Vector<UInt16> high) {
  Int32 count = Vector<Byte>::get_Count();
  Byte default[(Int32)(UInt32)count] = {};
  Byte* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = (Byte)low[i];
  }
  for (Int32 j = 0; j < count / 2; j++) {
    ptr[j + count / 2] = (Byte)high[j];
  }
  return Vector<Byte>(ptr);
}

Vector<UInt16> Vector<>::Narrow(Vector<UInt32> low, Vector<UInt32> high) {
  Int32 count = Vector<UInt16>::get_Count();
  UInt16 default[count] = {};
  UInt16* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = (UInt16)low[i];
  }
  for (Int32 j = 0; j < count / 2; j++) {
    ptr[j + count / 2] = (UInt16)high[j];
  }
  return Vector<UInt16>(ptr);
}

Vector<UInt32> Vector<>::Narrow(Vector<UInt64> low, Vector<UInt64> high) {
  Int32 count = Vector<UInt32>::get_Count();
  UInt32 default[count] = {};
  UInt32* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = (UInt32)low[i];
  }
  for (Int32 j = 0; j < count / 2; j++) {
    ptr[j + count / 2] = (UInt32)high[j];
  }
  return Vector<UInt32>(ptr);
}

Vector<SByte> Vector<>::Narrow(Vector<Int16> low, Vector<Int16> high) {
  Int32 count = Vector<SByte>::get_Count();
  SByte default[(Int32)(UInt32)count] = {};
  SByte* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = (SByte)low[i];
  }
  for (Int32 j = 0; j < count / 2; j++) {
    ptr[j + count / 2] = (SByte)high[j];
  }
  return Vector<SByte>(ptr);
}

Vector<Int16> Vector<>::Narrow(Vector<Int32> low, Vector<Int32> high) {
  Int32 count = Vector<Int16>::get_Count();
  Int16 default[count] = {};
  Int16* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = (Int16)low[i];
  }
  for (Int32 j = 0; j < count / 2; j++) {
    ptr[j + count / 2] = (Int16)high[j];
  }
  return Vector<Int16>(ptr);
}

Vector<Int32> Vector<>::Narrow(Vector<Int64> low, Vector<Int64> high) {
  Int32 count = Vector<Int32>::get_Count();
  Int32 default[count] = {};
  Int32* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = (Int32)low[i];
  }
  for (Int32 j = 0; j < count / 2; j++) {
    ptr[j + count / 2] = (Int32)high[j];
  }
  return Vector<Int32>(ptr);
}

Vector<Single> Vector<>::Narrow(Vector<Double> low, Vector<Double> high) {
  Int32 count = Vector<Single>::get_Count();
  Single default[count] = {};
  Single* ptr = default;
  for (Int32 i = 0; i < count / 2; i++) {
    ptr[i] = (Single)low[i];
  }
  for (Int32 j = 0; j < count / 2; j++) {
    ptr[j + count / 2] = (Single)high[j];
  }
  return Vector<Single>(ptr);
}

Vector<Single> Vector<>::ConvertToSingle(Vector<Int32> value) {
  Int32 count = Vector<Single>::get_Count();
  Single default[count] = {};
  Single* ptr = default;
  for (Int32 i = 0; i < count; i++) {
    ptr[i] = value[i];
  }
  return Vector<Single>(ptr);
}

Vector<Single> Vector<>::ConvertToSingle(Vector<UInt32> value) {
  Int32 count = Vector<Single>::get_Count();
  Single default[count] = {};
  Single* ptr = default;
  for (Int32 i = 0; i < count; i++) {
    ptr[i] = value[i];
  }
  return Vector<Single>(ptr);
}

Vector<Double> Vector<>::ConvertToDouble(Vector<Int64> value) {
  Int32 count = Vector<Double>::get_Count();
  Double default[count] = {};
  Double* ptr = default;
  for (Int32 i = 0; i < count; i++) {
    ptr[i] = value[i];
  }
  return Vector<Double>(ptr);
}

Vector<Double> Vector<>::ConvertToDouble(Vector<UInt64> value) {
  Int32 count = Vector<Double>::get_Count();
  Double default[count] = {};
  Double* ptr = default;
  for (Int32 i = 0; i < count; i++) {
    ptr[i] = value[i];
  }
  return Vector<Double>(ptr);
}

Vector<Int32> Vector<>::ConvertToInt32(Vector<Single> value) {
  Int32 count = Vector<Int32>::get_Count();
  Int32 default[count] = {};
  Int32* ptr = default;
  for (Int32 i = 0; i < count; i++) {
    ptr[i] = (Int32)value[i];
  }
  return Vector<Int32>(ptr);
}

Vector<UInt32> Vector<>::ConvertToUInt32(Vector<Single> value) {
  Int32 count = Vector<UInt32>::get_Count();
  UInt32 default[count] = {};
  UInt32* ptr = default;
  for (Int32 i = 0; i < count; i++) {
    ptr[i] = (UInt32)value[i];
  }
  return Vector<UInt32>(ptr);
}

Vector<Int64> Vector<>::ConvertToInt64(Vector<Double> value) {
  Int32 count = Vector<Int64>::get_Count();
  Int64 default[count] = {};
  Int64* ptr = default;
  for (Int32 i = 0; i < count; i++) {
    ptr[i] = (Int64)value[i];
  }
  return Vector<Int64>(ptr);
}

Vector<UInt64> Vector<>::ConvertToUInt64(Vector<Double> value) {
  Int32 count = Vector<UInt64>::get_Count();
  UInt64 default[count] = {};
  UInt64* ptr = default;
  for (Int32 i = 0; i < count; i++) {
    ptr[i] = (UInt64)value[i];
  }
  return Vector<UInt64>(ptr);
}

void Vector<>::ThrowInsufficientNumberOfElementsException(Int32 requiredElementCount) {
  rt::throw_exception<IndexOutOfRangeException>(SR::Format(SR::get_Arg_InsufficientNumberOfElements(), requiredElementCount, "values"));
}

Vector<Single> Vector<>::ConditionalSelect(Vector<Int32> condition, Vector<Single> left, Vector<Single> right) {
  return Vector<Single>::ConditionalSelect((Vector<Single>)condition, left, right);
}

Vector<Double> Vector<>::ConditionalSelect(Vector<Int64> condition, Vector<Double> left, Vector<Double> right) {
  return Vector<Double>::ConditionalSelect((Vector<Double>)condition, left, right);
}

Vector<Int32> Vector<>::Equals(Vector<Single> left, Vector<Single> right) {
  return (Vector<Int32>)Vector<Single>::Equals(left, right);
}

Vector<Int32> Vector<>::Equals(Vector<Int32> left, Vector<Int32> right) {
  return Vector<Int32>::Equals(left, right);
}

Vector<Int64> Vector<>::Equals(Vector<Double> left, Vector<Double> right) {
  return (Vector<Int64>)Vector<Double>::Equals(left, right);
}

Vector<Int64> Vector<>::Equals(Vector<Int64> left, Vector<Int64> right) {
  return Vector<Int64>::Equals(left, right);
}

Vector<Int32> Vector<>::LessThan(Vector<Single> left, Vector<Single> right) {
  return (Vector<Int32>)Vector<Single>::LessThan(left, right);
}

Vector<Int32> Vector<>::LessThan(Vector<Int32> left, Vector<Int32> right) {
  return Vector<Int32>::LessThan(left, right);
}

Vector<Int64> Vector<>::LessThan(Vector<Double> left, Vector<Double> right) {
  return (Vector<Int64>)Vector<Double>::LessThan(left, right);
}

Vector<Int64> Vector<>::LessThan(Vector<Int64> left, Vector<Int64> right) {
  return Vector<Int64>::LessThan(left, right);
}

Vector<Int32> Vector<>::LessThanOrEqual(Vector<Single> left, Vector<Single> right) {
  return (Vector<Int32>)Vector<Single>::LessThanOrEqual(left, right);
}

Vector<Int32> Vector<>::LessThanOrEqual(Vector<Int32> left, Vector<Int32> right) {
  return Vector<Int32>::LessThanOrEqual(left, right);
}

Vector<Int64> Vector<>::LessThanOrEqual(Vector<Int64> left, Vector<Int64> right) {
  return Vector<Int64>::LessThanOrEqual(left, right);
}

Vector<Int64> Vector<>::LessThanOrEqual(Vector<Double> left, Vector<Double> right) {
  return (Vector<Int64>)Vector<Double>::LessThanOrEqual(left, right);
}

Vector<Int32> Vector<>::GreaterThan(Vector<Single> left, Vector<Single> right) {
  return (Vector<Int32>)Vector<Single>::GreaterThan(left, right);
}

Vector<Int32> Vector<>::GreaterThan(Vector<Int32> left, Vector<Int32> right) {
  return Vector<Int32>::GreaterThan(left, right);
}

Vector<Int64> Vector<>::GreaterThan(Vector<Double> left, Vector<Double> right) {
  return (Vector<Int64>)Vector<Double>::GreaterThan(left, right);
}

Vector<Int64> Vector<>::GreaterThan(Vector<Int64> left, Vector<Int64> right) {
  return Vector<Int64>::GreaterThan(left, right);
}

Vector<Int32> Vector<>::GreaterThanOrEqual(Vector<Single> left, Vector<Single> right) {
  return (Vector<Int32>)Vector<Single>::GreaterThanOrEqual(left, right);
}

Vector<Int32> Vector<>::GreaterThanOrEqual(Vector<Int32> left, Vector<Int32> right) {
  return Vector<Int32>::GreaterThanOrEqual(left, right);
}

Vector<Int64> Vector<>::GreaterThanOrEqual(Vector<Int64> left, Vector<Int64> right) {
  return Vector<Int64>::GreaterThanOrEqual(left, right);
}

Vector<Int64> Vector<>::GreaterThanOrEqual(Vector<Double> left, Vector<Double> right) {
  return (Vector<Int64>)Vector<Double>::GreaterThanOrEqual(left, right);
}

Vector<Single> Vector<>::Ceiling(Vector<Single> value) {
  return Vector<Single>::Ceiling(value);
}

Vector<Double> Vector<>::Ceiling(Vector<Double> value) {
  return Vector<Double>::Ceiling(value);
}

Vector<Single> Vector<>::Floor(Vector<Single> value) {
  return Vector<Single>::Floor(value);
}

Vector<Double> Vector<>::Floor(Vector<Double> value) {
  return Vector<Double>::Floor(value);
}

} // namespace System::Private::CoreLib::System::Numerics::VectorNamespace
