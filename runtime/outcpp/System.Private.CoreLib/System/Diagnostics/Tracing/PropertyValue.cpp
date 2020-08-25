#include "PropertyValue-dep.h"

#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/PropertyValue-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Reflection/IntrospectionExtensions-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::PropertyValueNamespace {
using namespace System::Reflection;

Delegate PropertyValue::TypeHelper___::GetGetMethod(PropertyInfo property, Type propertyType) {
  return property->get_GetMethod()->CreateDelegate(typeof<Func<T, TResult>>()->MakeGenericType(rt::newarr<Array<Type>>(2, property->get_DeclaringType(), propertyType)));
}

void PropertyValue::TypeHelper___::ctor() {
}

Object PropertyValue::get_ReferenceValue() {
  return _reference;
}

PropertyValue::Scalar PropertyValue::get_ScalarValue() {
  return _scalar;
}

Int32 PropertyValue::get_ScalarLength() {
  return _scalarLength;
}

PropertyValue::PropertyValue(Object value) {
  _reference = value;
  _scalar = Scalar();
  _scalarLength = 0;
}

PropertyValue::PropertyValue(Scalar scalar, Int32 scalarLength) {
  _reference = nullptr;
  _scalar = scalar;
  _scalarLength = scalarLength;
}

PropertyValue::PropertyValue(Boolean value) {
}

PropertyValue::PropertyValue(Byte value) {
}

PropertyValue::PropertyValue(SByte value) {
}

PropertyValue::PropertyValue(Char value) {
}

PropertyValue::PropertyValue(Int16 value) {
}

PropertyValue::PropertyValue(UInt16 value) {
}

PropertyValue::PropertyValue(Int32 value) {
}

PropertyValue::PropertyValue(UInt32 value) {
}

PropertyValue::PropertyValue(Int64 value) {
}

PropertyValue::PropertyValue(UInt64 value) {
}

PropertyValue::PropertyValue(IntPtr value) {
}

PropertyValue::PropertyValue(UIntPtr value) {
}

PropertyValue::PropertyValue(Single value) {
}

PropertyValue::PropertyValue(Double value) {
}

PropertyValue::PropertyValue(Guid value) {
}

PropertyValue::PropertyValue(DateTime value) {
}

PropertyValue::PropertyValue(DateTimeOffset value) {
}

PropertyValue::PropertyValue(TimeSpan value) {
}

PropertyValue::PropertyValue(Decimal value) {
}

Func<Object, PropertyValue> PropertyValue::GetFactory(Type type) {
  if (type == typeof<Boolean>()) {
  }
  if (type == typeof<Byte>()) {
  }
  if (type == typeof<SByte>()) {
  }
  if (type == typeof<Char>()) {
  }
  if (type == typeof<Int16>()) {
  }
  if (type == typeof<UInt16>()) {
  }
  if (type == typeof<Int32>()) {
  }
  if (type == typeof<UInt32>()) {
  }
  if (type == typeof<Int64>()) {
  }
  if (type == typeof<UInt64>()) {
  }
  if (type == typeof<IntPtr>()) {
  }
  if (type == typeof<UIntPtr>()) {
  }
  if (type == typeof<Single>()) {
  }
  if (type == typeof<Double>()) {
  }
  if (type == typeof<Guid>()) {
  }
  if (type == typeof<DateTime>()) {
  }
  if (type == typeof<DateTimeOffset>()) {
  }
  if (type == typeof<TimeSpan>()) {
  }
  if (type == typeof<Decimal>()) {
  }
}

Func<PropertyValue, PropertyValue> PropertyValue::GetPropertyGetter(PropertyInfo property) {
  if (IntrospectionExtensions::GetTypeInfo(property->get_DeclaringType())->get_IsValueType()) {
    return GetBoxedValueTypePropertyGetter(property);
  }
  return GetReferenceTypePropertyGetter(property);
}

Func<PropertyValue, PropertyValue> PropertyValue::GetBoxedValueTypePropertyGetter(PropertyInfo property) {
  Type type = property->get_PropertyType();
  if (IntrospectionExtensions::GetTypeInfo(type)->get_IsEnum()) {
    type = Enum::in::GetUnderlyingType(type);
  }
  Func<Object, PropertyValue> factory = GetFactory(type);
}

Func<PropertyValue, PropertyValue> PropertyValue::GetReferenceTypePropertyGetter(PropertyInfo property) {
  TypeHelper typeHelper = (TypeHelper)Activator::CreateInstance(typeof<ReferenceTypeHelper<TContainer>>()->MakeGenericType(property->get_DeclaringType()));
  return typeHelper->GetPropertyGetter(property);
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::PropertyValueNamespace
