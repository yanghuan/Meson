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

void PropertyValue::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void PropertyValue::__c___::ctor() {
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_0(Object value) {
  return PropertyValue((Boolean)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_1(Object value) {
  return PropertyValue((Byte)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_2(Object value) {
  return PropertyValue((SByte)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_3(Object value) {
  return PropertyValue((Char)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_4(Object value) {
  return PropertyValue((Int16)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_5(Object value) {
  return PropertyValue((UInt16)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_6(Object value) {
  return PropertyValue((Int32)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_7(Object value) {
  return PropertyValue((UInt32)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_8(Object value) {
  return PropertyValue((Int64)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_9(Object value) {
  return PropertyValue((UInt64)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_10(Object value) {
  return PropertyValue((IntPtr)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_11(Object value) {
  return PropertyValue((UIntPtr)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_12(Object value) {
  return PropertyValue((Single)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_13(Object value) {
  return PropertyValue((Double)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_14(Object value) {
  return PropertyValue((Guid)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_15(Object value) {
  return PropertyValue((DateTime)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_16(Object value) {
  return PropertyValue((DateTimeOffset)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_17(Object value) {
  return PropertyValue((TimeSpan)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_18(Object value) {
  return PropertyValue((Decimal)value);
}

PropertyValue PropertyValue::__c___::_GetFactory_b__25_19(Object value) {
  return PropertyValue(value);
}

void PropertyValue::__c__DisplayClass33_0___::ctor() {
}

PropertyValue PropertyValue::__c__DisplayClass33_0___::_GetBoxedValueTypePropertyGetter_b__0(PropertyValue container) {
  return factory(property->GetValue(container.get_ReferenceValue()));
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
  _scalar = rt::default__;
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
    Func<Object, PropertyValue> as = __c::in::__9__25_0;
    return as != nullptr ? as : (__c::in::__9__25_0 = {__c::in::__9, &__c::in::_GetFactory_b__25_0});
  }
  if (type == typeof<Byte>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_1;
    return as != nullptr ? as : (__c::in::__9__25_1 = {__c::in::__9, &__c::in::_GetFactory_b__25_1});
  }
  if (type == typeof<SByte>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_2;
    return as != nullptr ? as : (__c::in::__9__25_2 = {__c::in::__9, &__c::in::_GetFactory_b__25_2});
  }
  if (type == typeof<Char>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_3;
    return as != nullptr ? as : (__c::in::__9__25_3 = {__c::in::__9, &__c::in::_GetFactory_b__25_3});
  }
  if (type == typeof<Int16>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_4;
    return as != nullptr ? as : (__c::in::__9__25_4 = {__c::in::__9, &__c::in::_GetFactory_b__25_4});
  }
  if (type == typeof<UInt16>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_5;
    return as != nullptr ? as : (__c::in::__9__25_5 = {__c::in::__9, &__c::in::_GetFactory_b__25_5});
  }
  if (type == typeof<Int32>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_6;
    return as != nullptr ? as : (__c::in::__9__25_6 = {__c::in::__9, &__c::in::_GetFactory_b__25_6});
  }
  if (type == typeof<UInt32>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_7;
    return as != nullptr ? as : (__c::in::__9__25_7 = {__c::in::__9, &__c::in::_GetFactory_b__25_7});
  }
  if (type == typeof<Int64>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_8;
    return as != nullptr ? as : (__c::in::__9__25_8 = {__c::in::__9, &__c::in::_GetFactory_b__25_8});
  }
  if (type == typeof<UInt64>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_9;
    return as != nullptr ? as : (__c::in::__9__25_9 = {__c::in::__9, &__c::in::_GetFactory_b__25_9});
  }
  if (type == typeof<IntPtr>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_10;
    return as != nullptr ? as : (__c::in::__9__25_10 = {__c::in::__9, &__c::in::_GetFactory_b__25_10});
  }
  if (type == typeof<UIntPtr>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_11;
    return as != nullptr ? as : (__c::in::__9__25_11 = {__c::in::__9, &__c::in::_GetFactory_b__25_11});
  }
  if (type == typeof<Single>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_12;
    return as != nullptr ? as : (__c::in::__9__25_12 = {__c::in::__9, &__c::in::_GetFactory_b__25_12});
  }
  if (type == typeof<Double>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_13;
    return as != nullptr ? as : (__c::in::__9__25_13 = {__c::in::__9, &__c::in::_GetFactory_b__25_13});
  }
  if (type == typeof<Guid>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_14;
    return as != nullptr ? as : (__c::in::__9__25_14 = {__c::in::__9, &__c::in::_GetFactory_b__25_14});
  }
  if (type == typeof<DateTime>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_15;
    return as != nullptr ? as : (__c::in::__9__25_15 = {__c::in::__9, &__c::in::_GetFactory_b__25_15});
  }
  if (type == typeof<DateTimeOffset>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_16;
    return as != nullptr ? as : (__c::in::__9__25_16 = {__c::in::__9, &__c::in::_GetFactory_b__25_16});
  }
  if (type == typeof<TimeSpan>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_17;
    return as != nullptr ? as : (__c::in::__9__25_17 = {__c::in::__9, &__c::in::_GetFactory_b__25_17});
  }
  if (type == typeof<Decimal>()) {
    Func<Object, PropertyValue> as = __c::in::__9__25_18;
    return as != nullptr ? as : (__c::in::__9__25_18 = {__c::in::__9, &__c::in::_GetFactory_b__25_18});
  }
  Func<Object, PropertyValue> as = __c::in::__9__25_19;
  return as != nullptr ? as : (__c::in::__9__25_19 = {__c::in::__9, &__c::in::_GetFactory_b__25_19});
}

Func<PropertyValue, PropertyValue> PropertyValue::GetPropertyGetter(PropertyInfo property) {
  if (IntrospectionExtensions::GetTypeInfo(property->get_DeclaringType())->get_IsValueType()) {
    return GetBoxedValueTypePropertyGetter(property);
  }
  return GetReferenceTypePropertyGetter(property);
}

Func<PropertyValue, PropertyValue> PropertyValue::GetBoxedValueTypePropertyGetter(PropertyInfo property) {
  __c__DisplayClass33_0 __c__DisplayClass33_ = rt::newobj<__c__DisplayClass33_0>();
  __c__DisplayClass33_->property = property;
  Type type = __c__DisplayClass33_->property->get_PropertyType();
  if (IntrospectionExtensions::GetTypeInfo(type)->get_IsEnum()) {
    type = Enum::in::GetUnderlyingType(type);
  }
  __c__DisplayClass33_->factory = GetFactory(type);
  return {__c__DisplayClass33_, &__c__DisplayClass33_0::in::_GetBoxedValueTypePropertyGetter_b__0};
}

Func<PropertyValue, PropertyValue> PropertyValue::GetReferenceTypePropertyGetter(PropertyInfo property) {
  TypeHelper typeHelper = (TypeHelper)Activator::CreateInstance(typeof<ReferenceTypeHelper<rt::Void>>()->MakeGenericType(property->get_DeclaringType()));
  return typeHelper->GetPropertyGetter(property);
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::PropertyValueNamespace
