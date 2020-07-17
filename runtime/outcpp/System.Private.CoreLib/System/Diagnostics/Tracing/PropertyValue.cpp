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

void PropertyValue::Ctor(Object value) {
};

void PropertyValue::Ctor(Scalar scalar, Int32 scalarLength) {
};

void PropertyValue::Ctor(Boolean value) {
};

void PropertyValue::Ctor(Byte value) {
};

void PropertyValue::Ctor(SByte value) {
};

void PropertyValue::Ctor(Char value) {
};

void PropertyValue::Ctor(Int16 value) {
};

void PropertyValue::Ctor(UInt16 value) {
};

void PropertyValue::Ctor(Int32 value) {
};

void PropertyValue::Ctor(UInt32 value) {
};

void PropertyValue::Ctor(Int64 value) {
};

void PropertyValue::Ctor(UInt64 value) {
};

void PropertyValue::Ctor(IntPtr value) {
};

void PropertyValue::Ctor(UIntPtr value) {
};

void PropertyValue::Ctor(Single value) {
};

void PropertyValue::Ctor(Double value) {
};

void PropertyValue::Ctor(Guid value) {
};

void PropertyValue::Ctor(DateTime value) {
};

void PropertyValue::Ctor(DateTimeOffset value) {
};

void PropertyValue::Ctor(TimeSpan value) {
};

void PropertyValue::Ctor(Decimal value) {
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
