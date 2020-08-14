#include "SignatureType-dep.h"

#include <System.Private.CoreLib/System/IndexOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureArrayType-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureByRefType-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignaturePointerType-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureType-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::SignatureTypeNamespace {
Boolean SignatureType___::get_IsSignatureType() {
  return true;
}

Boolean SignatureType___::get_IsGenericType() {
  if (!get_IsGenericTypeDefinition()) {
    return get_IsConstructedGenericType();
  }
  return true;
}

MemberTypes SignatureType___::get_MemberType() {
  return MemberTypes::TypeInfo;
}

Type SignatureType___::get_UnderlyingSystemType() {
  return (SignatureType)this;
}

String SignatureType___::get_FullName() {
  return nullptr;
}

String SignatureType___::get_AssemblyQualifiedName() {
  return nullptr;
}

Assembly SignatureType___::get_Assembly() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Module SignatureType___::get_Module() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Type SignatureType___::get_ReflectedType() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Type SignatureType___::get_BaseType() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Int32 SignatureType___::get_MetadataToken() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Type SignatureType___::get_DeclaringType() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

MethodBase SignatureType___::get_DeclaringMethod() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

GenericParameterAttributes SignatureType___::get_GenericParameterAttributes() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Guid SignatureType___::get_GUID() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

IEnumerable<CustomAttributeData> SignatureType___::get_CustomAttributes() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::get_IsEnum() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::get_IsSecurityCritical() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::get_IsSecuritySafeCritical() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::get_IsSecurityTransparent() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::get_IsSerializable() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

StructLayoutAttribute SignatureType___::get_StructLayoutAttribute() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

RuntimeTypeHandle SignatureType___::get_TypeHandle() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Type SignatureType___::MakeArrayType() {
  return rt::newobj<SignatureArrayType>((SignatureType)this, 1, false);
}

Type SignatureType___::MakeArrayType(Int32 rank) {
  if (rank <= 0) {
    rt::throw_exception<IndexOutOfRangeException>();
  }
  return rt::newobj<SignatureArrayType>((SignatureType)this, rank, true);
}

Type SignatureType___::MakeByRefType() {
  return rt::newobj<SignatureByRefType>((SignatureType)this);
}

Type SignatureType___::MakePointerType() {
  return rt::newobj<SignaturePointerType>((SignatureType)this);
}

Type SignatureType___::MakeGenericType(Array<Type> typeArguments) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Type SignatureType___::GetElementType() {
  return get_ElementType();
}

Array<Type> SignatureType___::GetInterfaces() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::IsAssignableFrom(Type c) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::HasSameMetadataDefinitionAs(MemberInfo other) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<Type> SignatureType___::GetGenericParameterConstraints() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::IsEnumDefined(Object value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

String SignatureType___::GetEnumName(Object value) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<String> SignatureType___::GetEnumNames() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Type SignatureType___::GetEnumUnderlyingType() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<> SignatureType___::GetEnumValues() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

TypeCode SignatureType___::GetTypeCodeImpl() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

TypeAttributes SignatureType___::GetAttributeFlagsImpl() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<ConstructorInfo> SignatureType___::GetConstructors(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

EventInfo SignatureType___::GetEvent(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<EventInfo> SignatureType___::GetEvents(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

FieldInfo SignatureType___::GetField(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<FieldInfo> SignatureType___::GetFields(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<MemberInfo> SignatureType___::GetMembers(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<MethodInfo> SignatureType___::GetMethods(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Type SignatureType___::GetNestedType(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<Type> SignatureType___::GetNestedTypes(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<PropertyInfo> SignatureType___::GetProperties(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Object SignatureType___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

MethodInfo SignatureType___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

MethodInfo SignatureType___::GetMethodImpl(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

PropertyInfo SignatureType___::GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<MemberInfo> SignatureType___::FindMembers(MemberTypes memberType, BindingFlags bindingAttr, MemberFilter filter, Object filterCriteria) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<MemberInfo> SignatureType___::GetMember(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<MemberInfo> SignatureType___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<MemberInfo> SignatureType___::GetDefaultMembers() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<EventInfo> SignatureType___::GetEvents() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<Object> SignatureType___::GetCustomAttributes(Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<Object> SignatureType___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::IsDefined(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

IList<CustomAttributeData> SignatureType___::GetCustomAttributesData() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Type SignatureType___::GetInterface(String name, Boolean ignoreCase) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

ConstructorInfo SignatureType___::GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::IsCOMObjectImpl() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::IsPrimitiveImpl() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Array<Type> SignatureType___::FindInterfaces(TypeFilter filter, Object filterCriteria) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

InterfaceMapping SignatureType___::GetInterfaceMap(Type interfaceType) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::IsContextfulImpl() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::IsEquivalentTo(Type other) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::IsInstanceOfType(Object o) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::IsMarshalByRefImpl() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::IsSubclassOf(Type c) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

Boolean SignatureType___::IsValueTypeImpl() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SignatureType());
}

void SignatureType___::ctor() {
}

} // namespace System::Private::CoreLib::System::Reflection::SignatureTypeNamespace
