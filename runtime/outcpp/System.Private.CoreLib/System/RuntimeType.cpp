#include "RuntimeType-dep.h"

#include <System.Private.CoreLib/System/RuntimeType-dep.h>

namespace System::Private::CoreLib::System::RuntimeTypeNamespace {
Boolean RuntimeType___::RuntimeTypeCache___::Filter::Match(MdUtf8String name) {
  return Boolean();
};
Boolean RuntimeType___::RuntimeTypeCache___::Filter::RequiresStringComparison() {
  return Boolean();
};
Boolean RuntimeType___::RuntimeTypeCache___::Filter::CaseSensitive() {
  return Boolean();
};
UInt32 RuntimeType___::RuntimeTypeCache___::Filter::GetHashToMatch() {
  return UInt32();
};
Object RuntimeType___::RuntimeTypeCache___::get_GenericCache() {
  return nullptr;
};
void RuntimeType___::RuntimeTypeCache___::set_GenericCache(Object value) {
  return void();
};
Boolean RuntimeType___::RuntimeTypeCache___::get_DomainInitialized() {
  return Boolean();
};
void RuntimeType___::RuntimeTypeCache___::set_DomainInitialized(Boolean value) {
  return void();
};
TypeCode RuntimeType___::RuntimeTypeCache___::get_TypeCode() {
  return TypeCode();
};
void RuntimeType___::RuntimeTypeCache___::set_TypeCode(TypeCode value) {
  return void();
};
Boolean RuntimeType___::RuntimeTypeCache___::get_IsGlobal() {
  return Boolean();
};
String RuntimeType___::RuntimeTypeCache___::ConstructName(String& name, TypeNameFormatFlags formatFlags) {
  return nullptr;
};
String RuntimeType___::RuntimeTypeCache___::GetName(TypeNameKind kind) {
  return nullptr;
};
String RuntimeType___::RuntimeTypeCache___::GetNameSpace() {
  return nullptr;
};
RuntimeType RuntimeType___::RuntimeTypeCache___::GetEnclosingType() {
  return nullptr;
};
RuntimeType RuntimeType___::RuntimeTypeCache___::GetRuntimeType() {
  return nullptr;
};
void RuntimeType___::RuntimeTypeCache___::InvalidateCachedNestedType() {
  return void();
};
String RuntimeType___::RuntimeTypeCache___::GetDefaultMemberName() {
  return nullptr;
};
Array<Object> RuntimeType___::RuntimeTypeCache___::GetEmptyArray() {
  return Array<Object>();
};
MethodInfo RuntimeType___::RuntimeTypeCache___::GetGenericMethodInfo(RuntimeMethodHandleInternal genericMethod) {
  return nullptr;
};
Array<RuntimeMethodInfo> RuntimeType___::RuntimeTypeCache___::GetMethodList(MemberListType listType, String name) {
  return Array<RuntimeMethodInfo>();
};
Array<RuntimeConstructorInfo> RuntimeType___::RuntimeTypeCache___::GetConstructorList(MemberListType listType, String name) {
  return Array<RuntimeConstructorInfo>();
};
Array<RuntimePropertyInfo> RuntimeType___::RuntimeTypeCache___::GetPropertyList(MemberListType listType, String name) {
  return Array<RuntimePropertyInfo>();
};
Array<RuntimeEventInfo> RuntimeType___::RuntimeTypeCache___::GetEventList(MemberListType listType, String name) {
  return Array<RuntimeEventInfo>();
};
Array<RuntimeFieldInfo> RuntimeType___::RuntimeTypeCache___::GetFieldList(MemberListType listType, String name) {
  return Array<RuntimeFieldInfo>();
};
Array<RuntimeType> RuntimeType___::RuntimeTypeCache___::GetInterfaceList(MemberListType listType, String name) {
  return Array<RuntimeType>();
};
Array<RuntimeType> RuntimeType___::RuntimeTypeCache___::GetNestedTypeList(MemberListType listType, String name) {
  return Array<RuntimeType>();
};
MethodBase RuntimeType___::RuntimeTypeCache___::GetMethod(RuntimeType declaringType, RuntimeMethodHandleInternal method) {
  return nullptr;
};
MethodBase RuntimeType___::RuntimeTypeCache___::GetConstructor(RuntimeType declaringType, RuntimeMethodHandleInternal constructor) {
  return nullptr;
};
FieldInfo RuntimeType___::RuntimeTypeCache___::GetField(RuntimeFieldHandleInternal field) {
  return nullptr;
};
void RuntimeType___::ActivatorCache___::Initialize() {
  return void();
};
void RuntimeType___::ActivatorCache___::EnsureInitialized() {
  return void();
};
Object RuntimeType___::get_GenericCache() {
  return nullptr;
};
void RuntimeType___::set_GenericCache(Object value) {
  return void();
};
Boolean RuntimeType___::get_DomainInitialized() {
  return Boolean();
};
void RuntimeType___::set_DomainInitialized(Boolean value) {
  return void();
};
RuntimeType::in::RuntimeTypeCache RuntimeType___::get_CacheIfExists() {
  return nullptr;
};
RuntimeType::in::RuntimeTypeCache RuntimeType___::get_Cache() {
  return nullptr;
};
Boolean RuntimeType___::get_IsCollectible() {
  return Boolean();
};
MethodBase RuntimeType___::get_DeclaringMethod() {
  return nullptr;
};
String RuntimeType___::get_FullName() {
  return nullptr;
};
String RuntimeType___::get_AssemblyQualifiedName() {
  return nullptr;
};
String RuntimeType___::get_Namespace() {
  return nullptr;
};
Guid RuntimeType___::get_GUID() {
  return Guid();
};
GenericParameterAttributes RuntimeType___::get_GenericParameterAttributes() {
  return GenericParameterAttributes();
};
Boolean RuntimeType___::get_IsSZArray() {
  return Boolean();
};
Int32 RuntimeType___::get_GenericParameterPosition() {
  return Int32();
};
Boolean RuntimeType___::get_ContainsGenericParameters() {
  return Boolean();
};
StructLayoutAttribute RuntimeType___::get_StructLayoutAttribute() {
  return nullptr;
};
String RuntimeType___::get_Name() {
  return nullptr;
};
Type RuntimeType___::get_DeclaringType() {
  return nullptr;
};
OleAutBinder RuntimeType___::get_ForwardCallBinder() {
  return nullptr;
};
Assembly RuntimeType___::get_Assembly() {
  return nullptr;
};
Type RuntimeType___::get_BaseType() {
  return nullptr;
};
Boolean RuntimeType___::get_IsByRefLike() {
  return Boolean();
};
Boolean RuntimeType___::get_IsConstructedGenericType() {
  return Boolean();
};
Boolean RuntimeType___::get_IsGenericType() {
  return Boolean();
};
Boolean RuntimeType___::get_IsGenericTypeDefinition() {
  return Boolean();
};
Boolean RuntimeType___::get_IsGenericParameter() {
  return Boolean();
};
Boolean RuntimeType___::get_IsTypeDefinition() {
  return Boolean();
};
Boolean RuntimeType___::get_IsSecurityCritical() {
  return Boolean();
};
Boolean RuntimeType___::get_IsSecuritySafeCritical() {
  return Boolean();
};
Boolean RuntimeType___::get_IsSecurityTransparent() {
  return Boolean();
};
MemberTypes RuntimeType___::get_MemberType() {
  return MemberTypes();
};
Int32 RuntimeType___::get_MetadataToken() {
  return Int32();
};
Module RuntimeType___::get_Module() {
  return nullptr;
};
Type RuntimeType___::get_ReflectedType() {
  return nullptr;
};
RuntimeTypeHandle RuntimeType___::get_TypeHandle() {
  return RuntimeTypeHandle();
};
Type RuntimeType___::get_UnderlyingSystemType() {
  return nullptr;
};
RuntimeType RuntimeType___::GetType(String typeName, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark) {
  return nullptr;
};
MethodBase RuntimeType___::GetMethodBase(RuntimeModule scope, Int32 typeMetadataToken) {
  return nullptr;
};
MethodBase RuntimeType___::GetMethodBase(IRuntimeMethodInfo methodHandle) {
  return nullptr;
};
MethodBase RuntimeType___::GetMethodBase(RuntimeType reflectedType, IRuntimeMethodInfo methodHandle) {
  return nullptr;
};
MethodBase RuntimeType___::GetMethodBase(RuntimeType reflectedType, RuntimeMethodHandleInternal methodHandle) {
  return nullptr;
};
FieldInfo RuntimeType___::GetFieldInfo(IRuntimeFieldInfo fieldHandle) {
  return nullptr;
};
FieldInfo RuntimeType___::GetFieldInfo(RuntimeType reflectedType, IRuntimeFieldInfo field) {
  return nullptr;
};
PropertyInfo RuntimeType___::GetPropertyInfo(RuntimeType reflectedType, Int32 tkProperty) {
  return nullptr;
};
void RuntimeType___::ThrowIfTypeNeverValidGenericArgument(RuntimeType type) {
  return void();
};
void RuntimeType___::SanityCheckGenericArguments(Array<RuntimeType> genericArguments, Array<RuntimeType> genericParamters) {
  return void();
};
void RuntimeType___::ValidateGenericArguments(MemberInfo definition, Array<RuntimeType> genericArguments, Exception e) {
  return void();
};
void RuntimeType___::SplitName(String fullname, String& name, String& ns) {
  return void();
};
BindingFlags RuntimeType___::FilterPreCalculate(Boolean isPublic, Boolean isInherited, Boolean isStatic) {
  return BindingFlags();
};
void RuntimeType___::FilterHelper(BindingFlags bindingFlags, String& name, Boolean allowPrefixLookup, Boolean& prefixLookup, Boolean& ignoreCase, MemberListType& listType) {
  return void();
};
void RuntimeType___::FilterHelper(BindingFlags bindingFlags, String& name, Boolean& ignoreCase, MemberListType& listType) {
  return void();
};
Boolean RuntimeType___::FilterApplyPrefixLookup(MemberInfo memberInfo, String name, Boolean ignoreCase) {
  return Boolean();
};
Boolean RuntimeType___::FilterApplyBase(MemberInfo memberInfo, BindingFlags bindingFlags, Boolean isPublic, Boolean isNonProtectedInternal, Boolean isStatic, String name, Boolean prefixLookup) {
  return Boolean();
};
Boolean RuntimeType___::FilterApplyType(Type type, BindingFlags bindingFlags, String name, Boolean prefixLookup, String ns) {
  return Boolean();
};
Boolean RuntimeType___::FilterApplyMethodInfo(RuntimeMethodInfo method, BindingFlags bindingFlags, CallingConventions callConv, Array<Type> argumentTypes) {
  return Boolean();
};
Boolean RuntimeType___::FilterApplyConstructorInfo(RuntimeConstructorInfo constructor, BindingFlags bindingFlags, CallingConventions callConv, Array<Type> argumentTypes) {
  return Boolean();
};
Boolean RuntimeType___::FilterApplyMethodBase(MethodBase methodBase, BindingFlags methodFlags, BindingFlags bindingFlags, CallingConventions callConv, Array<Type> argumentTypes) {
  return Boolean();
};
Boolean RuntimeType___::CacheEquals(Object o) {
  return Boolean();
};
RuntimeType::in::RuntimeTypeCache RuntimeType___::InitializeCache() {
  return nullptr;
};
String RuntimeType___::GetDefaultMemberName() {
  return nullptr;
};
RuntimeType::in::ListBuilder<MethodInfo> RuntimeType___::GetMethodCandidates(String name, Int32 genericParameterCount, BindingFlags bindingAttr, CallingConventions callConv, Array<Type> types, Boolean allowPrefixLookup) {
  return RuntimeType::in::ListBuilder<MethodInfo>();
};
RuntimeType::in::ListBuilder<ConstructorInfo> RuntimeType___::GetConstructorCandidates(String name, BindingFlags bindingAttr, CallingConventions callConv, Array<Type> types, Boolean allowPrefixLookup) {
  return RuntimeType::in::ListBuilder<ConstructorInfo>();
};
RuntimeType::in::ListBuilder<PropertyInfo> RuntimeType___::GetPropertyCandidates(String name, BindingFlags bindingAttr, Array<Type> types, Boolean allowPrefixLookup) {
  return RuntimeType::in::ListBuilder<PropertyInfo>();
};
RuntimeType::in::ListBuilder<EventInfo> RuntimeType___::GetEventCandidates(String name, BindingFlags bindingAttr, Boolean allowPrefixLookup) {
  return RuntimeType::in::ListBuilder<EventInfo>();
};
RuntimeType::in::ListBuilder<FieldInfo> RuntimeType___::GetFieldCandidates(String name, BindingFlags bindingAttr, Boolean allowPrefixLookup) {
  return RuntimeType::in::ListBuilder<FieldInfo>();
};
RuntimeType::in::ListBuilder<Type> RuntimeType___::GetNestedTypeCandidates(String fullname, BindingFlags bindingAttr, Boolean allowPrefixLookup) {
  return RuntimeType::in::ListBuilder<Type>();
};
Array<MethodInfo> RuntimeType___::GetMethods(BindingFlags bindingAttr) {
  return Array<MethodInfo>();
};
Array<ConstructorInfo> RuntimeType___::GetConstructors(BindingFlags bindingAttr) {
  return Array<ConstructorInfo>();
};
Array<PropertyInfo> RuntimeType___::GetProperties(BindingFlags bindingAttr) {
  return Array<PropertyInfo>();
};
Array<EventInfo> RuntimeType___::GetEvents(BindingFlags bindingAttr) {
  return Array<EventInfo>();
};
Array<FieldInfo> RuntimeType___::GetFields(BindingFlags bindingAttr) {
  return Array<FieldInfo>();
};
Array<Type> RuntimeType___::GetInterfaces() {
  return Array<Type>();
};
Array<Type> RuntimeType___::GetNestedTypes(BindingFlags bindingAttr) {
  return Array<Type>();
};
Array<MemberInfo> RuntimeType___::GetMembers(BindingFlags bindingAttr) {
  return Array<MemberInfo>();
};
InterfaceMapping RuntimeType___::GetInterfaceMap(Type ifaceType) {
  return InterfaceMapping();
};
MethodInfo RuntimeType___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConv, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
};
MethodInfo RuntimeType___::GetMethodImpl(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConv, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
};
MethodInfo RuntimeType___::GetMethodImplCommon(String name, Int32 genericParameterCount, BindingFlags bindingAttr, Binder binder, CallingConventions callConv, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
};
ConstructorInfo RuntimeType___::GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
};
PropertyInfo RuntimeType___::GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
};
EventInfo RuntimeType___::GetEvent(String name, BindingFlags bindingAttr) {
  return nullptr;
};
FieldInfo RuntimeType___::GetField(String name, BindingFlags bindingAttr) {
  return nullptr;
};
Type RuntimeType___::GetInterface(String fullname, Boolean ignoreCase) {
  return nullptr;
};
Type RuntimeType___::GetNestedType(String fullname, BindingFlags bindingAttr) {
  return nullptr;
};
Array<MemberInfo> RuntimeType___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  return Array<MemberInfo>();
};
Boolean RuntimeType___::IsSubclassOf(Type type) {
  return Boolean();
};
Boolean RuntimeType___::IsEquivalentTo(Type other) {
  return Boolean();
};
Boolean RuntimeType___::IsWindowsRuntimeObjectImpl() {
  return Boolean();
};
Boolean RuntimeType___::IsExportedToWindowsRuntimeImpl() {
  return Boolean();
};
Boolean RuntimeType___::IsDelegate() {
  return Boolean();
};
Array<Object> RuntimeType___::GetEmptyArray() {
  return Array<Object>();
};
Array<RuntimeType> RuntimeType___::GetGenericArgumentsInternal() {
  return Array<RuntimeType>();
};
Array<Type> RuntimeType___::GetGenericArguments() {
  return Array<Type>();
};
Type RuntimeType___::MakeGenericType(Array<Type> instantiation) {
  return nullptr;
};
Array<Type> RuntimeType___::GetGenericParameterConstraints() {
  return Array<Type>();
};
Boolean RuntimeType___::HasSameMetadataDefinitionAs(MemberInfo other) {
  return Boolean();
};
Type RuntimeType___::MakePointerType() {
  return nullptr;
};
Type RuntimeType___::MakeByRefType() {
  return nullptr;
};
Type RuntimeType___::MakeArrayType() {
  return nullptr;
};
Type RuntimeType___::MakeArrayType(Int32 rank) {
  return nullptr;
};
Object RuntimeType___::CheckValue(Object value, Binder binder, CultureInfo culture, BindingFlags invokeAttr) {
  return nullptr;
};
Object RuntimeType___::TryChangeType(Object value, Binder binder, CultureInfo culture, Boolean needsSpecialCast) {
  return nullptr;
};
Object RuntimeType___::InvokeMember(String name, BindingFlags bindingFlags, Binder binder, Object target, Array<Object> providedArgs, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParams) {
  return nullptr;
};
String RuntimeType___::ToString() {
  return nullptr;
};
String RuntimeType___::FormatTypeName() {
  return nullptr;
};
String RuntimeType___::GetCachedName(TypeNameKind kind) {
  return nullptr;
};
void RuntimeType___::CreateInstanceCheckThis() {
  return void();
};
Object RuntimeType___::CreateInstanceImpl(BindingFlags bindingAttr, Binder binder, Array<Object> args, CultureInfo culture) {
  return nullptr;
};
Object RuntimeType___::CreateInstanceDefaultCtorSlow(Boolean publicOnly, Boolean wrapExceptions, Boolean fillCache) {
  return nullptr;
};
Object RuntimeType___::CreateInstanceDefaultCtor(Boolean publicOnly, Boolean skipCheckThis, Boolean fillCache, Boolean wrapExceptions) {
  return nullptr;
};
void RuntimeType___::InvalidateCachedNestedType() {
  return void();
};
Boolean RuntimeType___::IsGenericCOMObjectImpl() {
  return Boolean();
};
Object RuntimeType___::CreateEnum(RuntimeType enumType, Int64 value) {
  return nullptr;
};
Object RuntimeType___::ForwardCallToInvokeMember(String memberName, BindingFlags flags, Object target, Array<Object> aArgs, Array<Boolean> aArgsIsByRef, Array<Int32> aArgsWrapperTypes, Array<Type> aArgsTypes, Type retType) {
  return nullptr;
};
void RuntimeType___::WrapArgsForInvokeCall(Array<Object> aArgs, Array<Int32> aArgsWrapperTypes) {
  return void();
};
Object RuntimeType___::Clone() {
  return nullptr;
};
Boolean RuntimeType___::Equals(Object obj) {
  return Boolean();
};
Int32 RuntimeType___::GetArrayRank() {
  return Int32();
};
TypeAttributes RuntimeType___::GetAttributeFlagsImpl() {
  return TypeAttributes();
};
Array<Object> RuntimeType___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};
Array<Object> RuntimeType___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};
IList<CustomAttributeData> RuntimeType___::GetCustomAttributesData() {
  return nullptr;
};
Array<MemberInfo> RuntimeType___::GetDefaultMembers() {
  return Array<MemberInfo>();
};
Type RuntimeType___::GetElementType() {
  return nullptr;
};
String RuntimeType___::GetEnumName(Object value) {
  return nullptr;
};
Array<String> RuntimeType___::GetEnumNames() {
  return Array<String>();
};
Array<> RuntimeType___::GetEnumValues() {
  return nullptr;
};
Type RuntimeType___::GetEnumUnderlyingType() {
  return nullptr;
};
Type RuntimeType___::GetGenericTypeDefinition() {
  return nullptr;
};
Int32 RuntimeType___::GetHashCode() {
  return Int32();
};
RuntimeModule RuntimeType___::GetRuntimeModule() {
  return nullptr;
};
TypeCode RuntimeType___::GetTypeCodeImpl() {
  return TypeCode();
};
Boolean RuntimeType___::HasElementTypeImpl() {
  return Boolean();
};
Boolean RuntimeType___::IsArrayImpl() {
  return Boolean();
};
Boolean RuntimeType___::IsContextfulImpl() {
  return Boolean();
};
Boolean RuntimeType___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};
Boolean RuntimeType___::IsEnumDefined(Object value) {
  return Boolean();
};
Boolean RuntimeType___::IsValueTypeImpl() {
  return Boolean();
};
Boolean RuntimeType___::IsByRefImpl() {
  return Boolean();
};
Boolean RuntimeType___::IsPrimitiveImpl() {
  return Boolean();
};
Boolean RuntimeType___::IsPointerImpl() {
  return Boolean();
};
Boolean RuntimeType___::IsCOMObjectImpl() {
  return Boolean();
};
Boolean RuntimeType___::IsInstanceOfType(Object o) {
  return Boolean();
};
Boolean RuntimeType___::IsAssignableFrom(TypeInfo typeInfo) {
  return Boolean();
};
Boolean RuntimeType___::IsAssignableFrom(Type c) {
  return Boolean();
};
RuntimeType RuntimeType___::GetBaseType() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::RuntimeTypeNamespace
