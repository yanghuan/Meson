#include "PropertyValue-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/PropertyValue-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::PropertyValueNamespace {
Delegate PropertyValue::TypeHelper___::GetGetMethod(PropertyInfo property, Type propertyType) {
  return nullptr;
};

void PropertyValue::TypeHelper___::Ctor() {
};

Object PropertyValue::get_ReferenceValue() {
  return nullptr;
};

PropertyValue::Scalar PropertyValue::get_ScalarValue() {
  return PropertyValue::Scalar();
};

Int32 PropertyValue::get_ScalarLength() {
  return Int32();
};

PropertyValue::PropertyValue(Object value) {
};

PropertyValue::PropertyValue(Scalar scalar, Int32 scalarLength) {
};

PropertyValue::PropertyValue(Boolean value) {
};

PropertyValue::PropertyValue(Byte value) {
};

PropertyValue::PropertyValue(SByte value) {
};

PropertyValue::PropertyValue(Char value) {
};

PropertyValue::PropertyValue(Int16 value) {
};

PropertyValue::PropertyValue(UInt16 value) {
};

PropertyValue::PropertyValue(Int32 value) {
};

PropertyValue::PropertyValue(UInt32 value) {
};

PropertyValue::PropertyValue(Int64 value) {
};

PropertyValue::PropertyValue(UInt64 value) {
};

PropertyValue::PropertyValue(IntPtr value) {
};

PropertyValue::PropertyValue(UIntPtr value) {
};

PropertyValue::PropertyValue(Single value) {
};

PropertyValue::PropertyValue(Double value) {
};

PropertyValue::PropertyValue(Guid value) {
};

PropertyValue::PropertyValue(DateTime value) {
};

PropertyValue::PropertyValue(DateTimeOffset value) {
};

PropertyValue::PropertyValue(TimeSpan value) {
};

PropertyValue::PropertyValue(Decimal value) {
};

Func<Object, PropertyValue> PropertyValue::GetFactory(Type type) {
  return nullptr;
};

Func<PropertyValue, PropertyValue> PropertyValue::GetPropertyGetter(PropertyInfo property) {
  return nullptr;
};

Func<PropertyValue, PropertyValue> PropertyValue::GetBoxedValueTypePropertyGetter(PropertyInfo property) {
  return nullptr;
};

Func<PropertyValue, PropertyValue> PropertyValue::GetReferenceTypePropertyGetter(PropertyInfo property) {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::PropertyValueNamespace
