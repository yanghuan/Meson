#include "Type-dep.h"

#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::TypeNamespace {
Boolean Type___::get_IsInterface() {
  return Boolean();
}

MemberTypes Type___::get_MemberType() {
  return MemberTypes::All;
}

Boolean Type___::get_IsNested() {
  return Boolean();
}

Type Type___::get_DeclaringType() {
  return nullptr;
}

MethodBase Type___::get_DeclaringMethod() {
  return nullptr;
}

Type Type___::get_ReflectedType() {
  return nullptr;
}

Boolean Type___::get_IsTypeDefinition() {
  return Boolean();
}

Boolean Type___::get_IsArray() {
  return Boolean();
}

Boolean Type___::get_IsByRef() {
  return Boolean();
}

Boolean Type___::get_IsPointer() {
  return Boolean();
}

Boolean Type___::get_IsConstructedGenericType() {
  return Boolean();
}

Boolean Type___::get_IsGenericParameter() {
  return Boolean();
}

Boolean Type___::get_IsGenericTypeParameter() {
  return Boolean();
}

Boolean Type___::get_IsGenericMethodParameter() {
  return Boolean();
}

Boolean Type___::get_IsGenericType() {
  return Boolean();
}

Boolean Type___::get_IsGenericTypeDefinition() {
  return Boolean();
}

Boolean Type___::get_IsSZArray() {
  return Boolean();
}

Boolean Type___::get_IsVariableBoundArray() {
  return Boolean();
}

Boolean Type___::get_IsByRefLike() {
  return Boolean();
}

Boolean Type___::get_HasElementType() {
  return Boolean();
}

Array<Type> Type___::get_GenericTypeArguments() {
  return Array<Type>();
}

Int32 Type___::get_GenericParameterPosition() {
  return Int32();
}

GenericParameterAttributes Type___::get_GenericParameterAttributes() {
  return GenericParameterAttributes::DefaultConstructorConstraint;
}

TypeAttributes Type___::get_Attributes() {
  return TypeAttributes::ReservedMask;
}

Boolean Type___::get_IsAbstract() {
  return Boolean();
}

Boolean Type___::get_IsImport() {
  return Boolean();
}

Boolean Type___::get_IsSealed() {
  return Boolean();
}

Boolean Type___::get_IsSpecialName() {
  return Boolean();
}

Boolean Type___::get_IsClass() {
  return Boolean();
}

Boolean Type___::get_IsNestedAssembly() {
  return Boolean();
}

Boolean Type___::get_IsNestedFamANDAssem() {
  return Boolean();
}

Boolean Type___::get_IsNestedFamily() {
  return Boolean();
}

Boolean Type___::get_IsNestedFamORAssem() {
  return Boolean();
}

Boolean Type___::get_IsNestedPrivate() {
  return Boolean();
}

Boolean Type___::get_IsNestedPublic() {
  return Boolean();
}

Boolean Type___::get_IsNotPublic() {
  return Boolean();
}

Boolean Type___::get_IsPublic() {
  return Boolean();
}

Boolean Type___::get_IsAutoLayout() {
  return Boolean();
}

Boolean Type___::get_IsExplicitLayout() {
  return Boolean();
}

Boolean Type___::get_IsLayoutSequential() {
  return Boolean();
}

Boolean Type___::get_IsAnsiClass() {
  return Boolean();
}

Boolean Type___::get_IsAutoClass() {
  return Boolean();
}

Boolean Type___::get_IsUnicodeClass() {
  return Boolean();
}

Boolean Type___::get_IsCOMObject() {
  return Boolean();
}

Boolean Type___::get_IsContextful() {
  return Boolean();
}

Boolean Type___::get_IsEnum() {
  return Boolean();
}

Boolean Type___::get_IsMarshalByRef() {
  return Boolean();
}

Boolean Type___::get_IsPrimitive() {
  return Boolean();
}

Boolean Type___::get_IsValueType() {
  return Boolean();
}

Boolean Type___::get_IsSignatureType() {
  return Boolean();
}

Boolean Type___::get_IsSecurityCritical() {
  return Boolean();
}

Boolean Type___::get_IsSecuritySafeCritical() {
  return Boolean();
}

Boolean Type___::get_IsSecurityTransparent() {
  return Boolean();
}

StructLayoutAttribute Type___::get_StructLayoutAttribute() {
  return nullptr;
}

ConstructorInfo Type___::get_TypeInitializer() {
  return nullptr;
}

RuntimeTypeHandle Type___::get_TypeHandle() {
  return RuntimeTypeHandle();
}

Binder Type___::get_DefaultBinder() {
  return nullptr;
}

Boolean Type___::get_IsSerializable() {
  return Boolean();
}

Boolean Type___::get_ContainsGenericParameters() {
  return Boolean();
}

Boolean Type___::get_IsVisible() {
  return Boolean();
}

Type Type___::GetType(String typeName, Boolean throwOnError, Boolean ignoreCase) {
  return nullptr;
}

Type Type___::GetType(String typeName, Boolean throwOnError) {
  return nullptr;
}

Type Type___::GetType(String typeName) {
  return nullptr;
}

Type Type___::GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver) {
  return nullptr;
}

Type Type___::GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError) {
  return nullptr;
}

Type Type___::GetType(String typeName, Func<AssemblyName, Assembly> assemblyResolver, Func<Assembly, String, Boolean, Type> typeResolver, Boolean throwOnError, Boolean ignoreCase) {
  return nullptr;
}

Type Type___::GetTypeFromProgID(String progID, String server, Boolean throwOnError) {
  return nullptr;
}

Type Type___::GetTypeFromCLSID(Guid clsid, String server, Boolean throwOnError) {
  return nullptr;
}

RuntimeTypeHandle Type___::GetTypeHandleInternal() {
  return RuntimeTypeHandle();
}

Boolean Type___::IsRuntimeImplemented() {
  return Boolean();
}

void Type___::ctor() {
}

Type Type___::GetType() {
  return nullptr;
}

Int32 Type___::GetArrayRank() {
  return Int32();
}

Type Type___::GetGenericTypeDefinition() {
  return nullptr;
}

Array<Type> Type___::GetGenericArguments() {
  return Array<Type>();
}

Array<Type> Type___::GetGenericParameterConstraints() {
  return Array<Type>();
}

Boolean Type___::IsContextfulImpl() {
  return Boolean();
}

Boolean Type___::IsMarshalByRefImpl() {
  return Boolean();
}

Boolean Type___::IsValueTypeImpl() {
  return Boolean();
}

ConstructorInfo Type___::GetConstructor(Array<Type> types) {
  return nullptr;
}

ConstructorInfo Type___::GetConstructor(BindingFlags bindingAttr, Binder binder, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

ConstructorInfo Type___::GetConstructor(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

Array<ConstructorInfo> Type___::GetConstructors() {
  return Array<ConstructorInfo>();
}

EventInfo Type___::GetEvent(String name) {
  return nullptr;
}

Array<EventInfo> Type___::GetEvents() {
  return Array<EventInfo>();
}

FieldInfo Type___::GetField(String name) {
  return nullptr;
}

Array<FieldInfo> Type___::GetFields() {
  return Array<FieldInfo>();
}

Array<MemberInfo> Type___::GetMember(String name) {
  return Array<MemberInfo>();
}

Array<MemberInfo> Type___::GetMember(String name, BindingFlags bindingAttr) {
  return Array<MemberInfo>();
}

Array<MemberInfo> Type___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  return Array<MemberInfo>();
}

Array<MemberInfo> Type___::GetMembers() {
  return Array<MemberInfo>();
}

MethodInfo Type___::GetMethod(String name) {
  return nullptr;
}

MethodInfo Type___::GetMethod(String name, BindingFlags bindingAttr) {
  return nullptr;
}

MethodInfo Type___::GetMethod(String name, Array<Type> types) {
  return nullptr;
}

MethodInfo Type___::GetMethod(String name, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

MethodInfo Type___::GetMethod(String name, BindingFlags bindingAttr, Binder binder, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

MethodInfo Type___::GetMethod(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

MethodInfo Type___::GetMethod(String name, Int32 genericParameterCount, Array<Type> types) {
  return nullptr;
}

MethodInfo Type___::GetMethod(String name, Int32 genericParameterCount, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

MethodInfo Type___::GetMethod(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

MethodInfo Type___::GetMethod(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

MethodInfo Type___::GetMethodImpl(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

Array<MethodInfo> Type___::GetMethods() {
  return Array<MethodInfo>();
}

Type Type___::GetNestedType(String name) {
  return nullptr;
}

Array<Type> Type___::GetNestedTypes() {
  return Array<Type>();
}

PropertyInfo Type___::GetProperty(String name) {
  return nullptr;
}

PropertyInfo Type___::GetProperty(String name, BindingFlags bindingAttr) {
  return nullptr;
}

PropertyInfo Type___::GetProperty(String name, Type returnType) {
  return nullptr;
}

PropertyInfo Type___::GetProperty(String name, Array<Type> types) {
  return nullptr;
}

PropertyInfo Type___::GetProperty(String name, Type returnType, Array<Type> types) {
  return nullptr;
}

PropertyInfo Type___::GetProperty(String name, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

PropertyInfo Type___::GetProperty(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

Array<PropertyInfo> Type___::GetProperties() {
  return Array<PropertyInfo>();
}

Array<MemberInfo> Type___::GetDefaultMembers() {
  return Array<MemberInfo>();
}

RuntimeTypeHandle Type___::GetTypeHandle(Object o) {
  return RuntimeTypeHandle();
}

Array<Type> Type___::GetTypeArray(Array<Object> args) {
  return Array<Type>();
}

TypeCode Type___::GetTypeCode(Type type) {
  return TypeCode::String;
}

TypeCode Type___::GetTypeCodeImpl() {
  return TypeCode::String;
}

Type Type___::GetTypeFromCLSID(Guid clsid) {
  return nullptr;
}

Type Type___::GetTypeFromCLSID(Guid clsid, Boolean throwOnError) {
  return nullptr;
}

Type Type___::GetTypeFromCLSID(Guid clsid, String server) {
  return nullptr;
}

Type Type___::GetTypeFromProgID(String progID) {
  return nullptr;
}

Type Type___::GetTypeFromProgID(String progID, Boolean throwOnError) {
  return nullptr;
}

Type Type___::GetTypeFromProgID(String progID, String server) {
  return nullptr;
}

Object Type___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args) {
  return nullptr;
}

Object Type___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, CultureInfo culture) {
  return nullptr;
}

Type Type___::GetInterface(String name) {
  return nullptr;
}

InterfaceMapping Type___::GetInterfaceMap(Type interfaceType) {
  return InterfaceMapping();
}

Boolean Type___::IsInstanceOfType(Object o) {
  return Boolean();
}

Boolean Type___::IsEquivalentTo(Type other) {
  return Boolean();
}

Type Type___::GetEnumUnderlyingType() {
  return nullptr;
}

Array<> Type___::GetEnumValues() {
  return nullptr;
}

Type Type___::MakeArrayType() {
  return nullptr;
}

Type Type___::MakeArrayType(Int32 rank) {
  return nullptr;
}

Type Type___::MakeByRefType() {
  return nullptr;
}

Type Type___::MakeGenericType(Array<Type> typeArguments) {
  return nullptr;
}

Type Type___::MakePointerType() {
  return nullptr;
}

Type Type___::MakeGenericSignatureType(Type genericTypeDefinition, Array<Type> typeArguments) {
  return nullptr;
}

Type Type___::MakeGenericMethodParameter(Int32 position) {
  return nullptr;
}

String Type___::FormatTypeName() {
  return nullptr;
}

String Type___::ToString() {
  return nullptr;
}

Boolean Type___::Equals(Object o) {
  return Boolean();
}

Int32 Type___::GetHashCode() {
  return Int32();
}

Boolean Type___::Equals(Type o) {
  return Boolean();
}

Type Type___::ReflectionOnlyGetType(String typeName, Boolean throwIfNotFound, Boolean ignoreCase) {
  return nullptr;
}

Boolean Type___::IsEnumDefined(Object value) {
  return Boolean();
}

String Type___::GetEnumName(Object value) {
  return nullptr;
}

Array<String> Type___::GetEnumNames() {
  return Array<String>();
}

Array<> Type___::GetEnumRawConstantValues() {
  return nullptr;
}

void Type___::GetEnumData(Array<String>& enumNames, Array<>& enumValues) {
}

Int32 Type___::BinarySearch(Array<> array, Object value) {
  return Int32();
}

Boolean Type___::IsIntegerType(Type t) {
  return Boolean();
}

Type Type___::GetRootElementType() {
  return nullptr;
}

Array<Type> Type___::FindInterfaces(TypeFilter filter, Object filterCriteria) {
  return Array<Type>();
}

Array<MemberInfo> Type___::FindMembers(MemberTypes memberType, BindingFlags bindingAttr, MemberFilter filter, Object filterCriteria) {
  return Array<MemberInfo>();
}

Boolean Type___::IsSubclassOf(Type c) {
  return Boolean();
}

Boolean Type___::IsAssignableFrom(Type c) {
  return Boolean();
}

Boolean Type___::ImplementInterface(Type ifaceType) {
  return Boolean();
}

Boolean Type___::FilterAttributeImpl(MemberInfo m, Object filterCriteria) {
  return Boolean();
}

Boolean Type___::FilterNameImpl(MemberInfo m, Object filterCriteria, StringComparison comparison) {
  return Boolean();
}

void Type___::ctor_static() {
}

} // namespace System::Private::CoreLib::System::TypeNamespace
