#include "PropertyValue-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/PropertyValue-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::PropertyValueNamespace {
Delegate PropertyValue::TypeHelper___::GetGetMethod(PropertyInfo property, Type propertyType) {
  return nullptr;
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
