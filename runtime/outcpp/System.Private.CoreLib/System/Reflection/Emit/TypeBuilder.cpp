#include "TypeBuilder-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/TypeBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::TypeBuilderNamespace {
void TypeBuilder___::CustAttr___::ctor(ConstructorInfo con, Array<Byte> binaryAttribute) {
}

void TypeBuilder___::CustAttr___::ctor(CustomAttributeBuilder customBuilder) {
}

void TypeBuilder___::CustAttr___::Bake(ModuleBuilder module, Int32 token) {
}

Object TypeBuilder___::get_SyncRoot() {
  return nullptr;
}

RuntimeType TypeBuilder___::get_BakedRuntimeType() {
  return nullptr;
}

Type TypeBuilder___::get_DeclaringType() {
  return nullptr;
}

Type TypeBuilder___::get_ReflectedType() {
  return nullptr;
}

String TypeBuilder___::get_Name() {
  return nullptr;
}

Module TypeBuilder___::get_Module() {
  return nullptr;
}

Boolean TypeBuilder___::get_IsByRefLike() {
  return Boolean();
}

Int32 TypeBuilder___::get_MetadataTokenInternal() {
  return Int32();
}

Guid TypeBuilder___::get_GUID() {
  return Guid();
}

Assembly TypeBuilder___::get_Assembly() {
  return nullptr;
}

RuntimeTypeHandle TypeBuilder___::get_TypeHandle() {
  return RuntimeTypeHandle();
}

String TypeBuilder___::get_FullName() {
  return nullptr;
}

String TypeBuilder___::get_Namespace() {
  return nullptr;
}

String TypeBuilder___::get_AssemblyQualifiedName() {
  return nullptr;
}

Type TypeBuilder___::get_BaseType() {
  return nullptr;
}

Boolean TypeBuilder___::get_IsTypeDefinition() {
  return Boolean();
}

Boolean TypeBuilder___::get_IsSZArray() {
  return Boolean();
}

Boolean TypeBuilder___::get_IsSecurityCritical() {
  return Boolean();
}

Boolean TypeBuilder___::get_IsSecuritySafeCritical() {
  return Boolean();
}

Boolean TypeBuilder___::get_IsSecurityTransparent() {
  return Boolean();
}

Type TypeBuilder___::get_UnderlyingSystemType() {
  return nullptr;
}

GenericParameterAttributes TypeBuilder___::get_GenericParameterAttributes() {
  return GenericParameterAttributes::DefaultConstructorConstraint;
}

Boolean TypeBuilder___::get_IsGenericTypeDefinition() {
  return Boolean();
}

Boolean TypeBuilder___::get_IsGenericType() {
  return Boolean();
}

Boolean TypeBuilder___::get_IsGenericParameter() {
  return Boolean();
}

Boolean TypeBuilder___::get_IsConstructedGenericType() {
  return Boolean();
}

Int32 TypeBuilder___::get_GenericParameterPosition() {
  return Int32();
}

MethodBase TypeBuilder___::get_DeclaringMethod() {
  return nullptr;
}

Int32 TypeBuilder___::get_Size() {
  return Int32();
}

PackingSize TypeBuilder___::get_PackingSize() {
  return PackingSize::Size128;
}

TypeToken TypeBuilder___::get_TypeToken() {
  return TypeToken();
}

Boolean TypeBuilder___::IsAssignableFrom(TypeInfo typeInfo) {
  return Boolean();
}

MethodInfo TypeBuilder___::GetMethod(Type type, MethodInfo method) {
  return nullptr;
}

ConstructorInfo TypeBuilder___::GetConstructor(Type type, ConstructorInfo constructor) {
  return nullptr;
}

FieldInfo TypeBuilder___::GetField(Type type, FieldInfo field) {
  return nullptr;
}

void TypeBuilder___::DefineCustomAttribute(ModuleBuilder module, Int32 tkAssociate, Int32 tkConstructor, Array<Byte> attr, Boolean toDisk, Boolean updateCompilerFlags) {
}

Boolean TypeBuilder___::IsTypeEqual(Type t1, Type t2) {
  return Boolean();
}

void TypeBuilder___::SetConstantValue(ModuleBuilder module, Int32 tk, Type destType, Object value) {
}

void TypeBuilder___::ctor(ModuleBuilder module) {
}

void TypeBuilder___::ctor(String szName, Int32 genParamPos, MethodBuilder declMeth) {
}

void TypeBuilder___::ctor(String szName, Int32 genParamPos, TypeBuilder declType) {
}

void TypeBuilder___::ctor(String fullname, TypeAttributes attr, Type parent, Array<Type> interfaces, ModuleBuilder module, PackingSize iPackingSize, Int32 iTypeSize, TypeBuilder enclosingType) {
}

FieldBuilder TypeBuilder___::DefineDataHelper(String name, Array<Byte> data, Int32 size, FieldAttributes attributes) {
  return nullptr;
}

void TypeBuilder___::VerifyTypeAttributes(TypeAttributes attr) {
}

Boolean TypeBuilder___::IsCreated() {
  return Boolean();
}

void TypeBuilder___::ThrowIfCreated() {
}

ModuleBuilder TypeBuilder___::GetModuleBuilder() {
  return nullptr;
}

void TypeBuilder___::SetGenParamAttributes(GenericParameterAttributes genericParameterAttributes) {
}

void TypeBuilder___::SetGenParamCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
}

void TypeBuilder___::SetGenParamCustomAttribute(CustomAttributeBuilder customBuilder) {
}

void TypeBuilder___::SetGenParamCustomAttributeNoLock(CustAttr ca) {
}

String TypeBuilder___::ToString() {
  return nullptr;
}

Object TypeBuilder___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters) {
  return nullptr;
}

ConstructorInfo TypeBuilder___::GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

Array<ConstructorInfo> TypeBuilder___::GetConstructors(BindingFlags bindingAttr) {
  return Array<ConstructorInfo>();
}

MethodInfo TypeBuilder___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

Array<MethodInfo> TypeBuilder___::GetMethods(BindingFlags bindingAttr) {
  return Array<MethodInfo>();
}

FieldInfo TypeBuilder___::GetField(String name, BindingFlags bindingAttr) {
  return nullptr;
}

Array<FieldInfo> TypeBuilder___::GetFields(BindingFlags bindingAttr) {
  return Array<FieldInfo>();
}

Type TypeBuilder___::GetInterface(String name, Boolean ignoreCase) {
  return nullptr;
}

Array<Type> TypeBuilder___::GetInterfaces() {
  return Array<Type>();
}

EventInfo TypeBuilder___::GetEvent(String name, BindingFlags bindingAttr) {
  return nullptr;
}

Array<EventInfo> TypeBuilder___::GetEvents() {
  return Array<EventInfo>();
}

PropertyInfo TypeBuilder___::GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
}

Array<PropertyInfo> TypeBuilder___::GetProperties(BindingFlags bindingAttr) {
  return Array<PropertyInfo>();
}

Array<Type> TypeBuilder___::GetNestedTypes(BindingFlags bindingAttr) {
  return Array<Type>();
}

Type TypeBuilder___::GetNestedType(String name, BindingFlags bindingAttr) {
  return nullptr;
}

Array<MemberInfo> TypeBuilder___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  return Array<MemberInfo>();
}

InterfaceMapping TypeBuilder___::GetInterfaceMap(Type interfaceType) {
  return InterfaceMapping();
}

Array<EventInfo> TypeBuilder___::GetEvents(BindingFlags bindingAttr) {
  return Array<EventInfo>();
}

Array<MemberInfo> TypeBuilder___::GetMembers(BindingFlags bindingAttr) {
  return Array<MemberInfo>();
}

Boolean TypeBuilder___::IsAssignableFrom(Type c) {
  return Boolean();
}

TypeAttributes TypeBuilder___::GetAttributeFlagsImpl() {
  return TypeAttributes::ReservedMask;
}

Boolean TypeBuilder___::IsArrayImpl() {
  return Boolean();
}

Boolean TypeBuilder___::IsByRefImpl() {
  return Boolean();
}

Boolean TypeBuilder___::IsPointerImpl() {
  return Boolean();
}

Boolean TypeBuilder___::IsPrimitiveImpl() {
  return Boolean();
}

Boolean TypeBuilder___::IsCOMObjectImpl() {
  return Boolean();
}

Type TypeBuilder___::GetElementType() {
  return nullptr;
}

Boolean TypeBuilder___::HasElementTypeImpl() {
  return Boolean();
}

Boolean TypeBuilder___::IsSubclassOf(Type c) {
  return Boolean();
}

Type TypeBuilder___::MakePointerType() {
  return nullptr;
}

Type TypeBuilder___::MakeByRefType() {
  return nullptr;
}

Type TypeBuilder___::MakeArrayType() {
  return nullptr;
}

Type TypeBuilder___::MakeArrayType(Int32 rank) {
  return nullptr;
}

Array<Object> TypeBuilder___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
}

Array<Object> TypeBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
}

Boolean TypeBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
}

void TypeBuilder___::SetInterfaces(Array<Type> interfaces) {
}

Array<GenericTypeParameterBuilder> TypeBuilder___::DefineGenericParameters(Array<String> names) {
  return Array<GenericTypeParameterBuilder>();
}

Type TypeBuilder___::MakeGenericType(Array<Type> typeArguments) {
  return nullptr;
}

Array<Type> TypeBuilder___::GetGenericArguments() {
  return Array<Type>();
}

Type TypeBuilder___::GetGenericTypeDefinition() {
  return nullptr;
}

void TypeBuilder___::DefineMethodOverride(MethodInfo methodInfoBody, MethodInfo methodInfoDeclaration) {
}

void TypeBuilder___::DefineMethodOverrideNoLock(MethodInfo methodInfoBody, MethodInfo methodInfoDeclaration) {
}

MethodBuilder TypeBuilder___::DefineMethod(String name, MethodAttributes attributes, Type returnType, Array<Type> parameterTypes) {
  return nullptr;
}

MethodBuilder TypeBuilder___::DefineMethod(String name, MethodAttributes attributes) {
  return nullptr;
}

MethodBuilder TypeBuilder___::DefineMethod(String name, MethodAttributes attributes, CallingConventions callingConvention) {
  return nullptr;
}

MethodBuilder TypeBuilder___::DefineMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  return nullptr;
}

MethodBuilder TypeBuilder___::DefineMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
  return nullptr;
}

MethodBuilder TypeBuilder___::DefineMethodNoLock(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
  return nullptr;
}

MethodBuilder TypeBuilder___::DefinePInvokeMethod(String name, String dllName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  return nullptr;
}

MethodBuilder TypeBuilder___::DefinePInvokeMethod(String name, String dllName, String entryName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  return nullptr;
}

MethodBuilder TypeBuilder___::DefinePInvokeMethod(String name, String dllName, String entryName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  return nullptr;
}

MethodBuilder TypeBuilder___::DefinePInvokeMethodHelper(String name, String dllName, String importName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  return nullptr;
}

ConstructorBuilder TypeBuilder___::DefineTypeInitializer() {
  return nullptr;
}

ConstructorBuilder TypeBuilder___::DefineTypeInitializerNoLock() {
  return nullptr;
}

ConstructorBuilder TypeBuilder___::DefineDefaultConstructor(MethodAttributes attributes) {
  return nullptr;
}

ConstructorBuilder TypeBuilder___::DefineDefaultConstructorNoLock(MethodAttributes attributes) {
  return nullptr;
}

ConstructorBuilder TypeBuilder___::DefineConstructor(MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes) {
  return nullptr;
}

ConstructorBuilder TypeBuilder___::DefineConstructor(MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes, Array<Array<Type>> requiredCustomModifiers, Array<Array<Type>> optionalCustomModifiers) {
  return nullptr;
}

ConstructorBuilder TypeBuilder___::DefineConstructorNoLock(MethodAttributes attributes, CallingConventions callingConvention, Array<Type> parameterTypes, Array<Array<Type>> requiredCustomModifiers, Array<Array<Type>> optionalCustomModifiers) {
  return nullptr;
}

TypeBuilder TypeBuilder___::DefineNestedType(String name) {
  return nullptr;
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr, Type parent, Array<Type> interfaces) {
  return nullptr;
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr, Type parent) {
  return nullptr;
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr) {
  return nullptr;
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr, Type parent, Int32 typeSize) {
  return nullptr;
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr, Type parent, PackingSize packSize) {
  return nullptr;
}

TypeBuilder TypeBuilder___::DefineNestedType(String name, TypeAttributes attr, Type parent, PackingSize packSize, Int32 typeSize) {
  return nullptr;
}

TypeBuilder TypeBuilder___::DefineNestedTypeNoLock(String name, TypeAttributes attr, Type parent, Array<Type> interfaces, PackingSize packSize, Int32 typeSize) {
  return nullptr;
}

FieldBuilder TypeBuilder___::DefineField(String fieldName, Type type, FieldAttributes attributes) {
  return nullptr;
}

FieldBuilder TypeBuilder___::DefineField(String fieldName, Type type, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers, FieldAttributes attributes) {
  return nullptr;
}

FieldBuilder TypeBuilder___::DefineFieldNoLock(String fieldName, Type type, Array<Type> requiredCustomModifiers, Array<Type> optionalCustomModifiers, FieldAttributes attributes) {
  return nullptr;
}

FieldBuilder TypeBuilder___::DefineInitializedData(String name, Array<Byte> data, FieldAttributes attributes) {
  return nullptr;
}

FieldBuilder TypeBuilder___::DefineInitializedDataNoLock(String name, Array<Byte> data, FieldAttributes attributes) {
  return nullptr;
}

FieldBuilder TypeBuilder___::DefineUninitializedData(String name, Int32 size, FieldAttributes attributes) {
  return nullptr;
}

FieldBuilder TypeBuilder___::DefineUninitializedDataNoLock(String name, Int32 size, FieldAttributes attributes) {
  return nullptr;
}

PropertyBuilder TypeBuilder___::DefineProperty(String name, PropertyAttributes attributes, Type returnType, Array<Type> parameterTypes) {
  return nullptr;
}

PropertyBuilder TypeBuilder___::DefineProperty(String name, PropertyAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  return nullptr;
}

PropertyBuilder TypeBuilder___::DefineProperty(String name, PropertyAttributes attributes, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
  return nullptr;
}

PropertyBuilder TypeBuilder___::DefineProperty(String name, PropertyAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
  return nullptr;
}

PropertyBuilder TypeBuilder___::DefinePropertyNoLock(String name, PropertyAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> returnTypeRequiredCustomModifiers, Array<Type> returnTypeOptionalCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> parameterTypeRequiredCustomModifiers, Array<Array<Type>> parameterTypeOptionalCustomModifiers) {
  return nullptr;
}

EventBuilder TypeBuilder___::DefineEvent(String name, EventAttributes attributes, Type eventtype) {
  return nullptr;
}

EventBuilder TypeBuilder___::DefineEventNoLock(String name, EventAttributes attributes, Type eventtype) {
  return nullptr;
}

TypeInfo TypeBuilder___::CreateTypeInfo() {
  return nullptr;
}

Type TypeBuilder___::CreateType() {
  return nullptr;
}

void TypeBuilder___::CheckContext(Array<Array<Type>> typess) {
}

void TypeBuilder___::CheckContext(Array<Type> types) {
}

TypeInfo TypeBuilder___::CreateTypeNoLock() {
  return nullptr;
}

void TypeBuilder___::SetParent(Type parent) {
}

void TypeBuilder___::AddInterfaceImplementation(Type interfaceType) {
}

void TypeBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
}

void TypeBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::TypeBuilderNamespace
