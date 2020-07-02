#include "ModuleBuilder-dep.h"

namespace System::Private::CoreLib::System::Reflection::Emit::ModuleBuilderNamespace {
AssemblyBuilder ModuleBuilder___::get_ContainingAssemblyBuilder() {
  return nullptr;
};
Object ModuleBuilder___::get_SyncRoot() {
  return nullptr;
};
InternalModuleBuilder ModuleBuilder___::get_InternalModule() {
  return nullptr;
};
String ModuleBuilder___::get_FullyQualifiedName() {
  return nullptr;
};
Int32 ModuleBuilder___::get_MDStreamVersion() {
  return Int32();
};
Guid ModuleBuilder___::get_ModuleVersionId() {
  return Guid();
};
Int32 ModuleBuilder___::get_MetadataToken() {
  return Int32();
};
String ModuleBuilder___::get_ScopeName() {
  return nullptr;
};
String ModuleBuilder___::get_Name() {
  return nullptr;
};
Assembly ModuleBuilder___::get_Assembly() {
  return nullptr;
};
String ModuleBuilder___::UnmangleTypeName(String typeName) {
  return nullptr;
};
void ModuleBuilder___::AddType(String name, Type type) {
  return void();
};
void ModuleBuilder___::CheckTypeNameConflict(String strTypeName, Type enclosingType) {
  return void();
};
Type ModuleBuilder___::GetType(String strFormat, Type baseType) {
  return nullptr;
};
void ModuleBuilder___::CheckContext(Array<Array<Type>> typess) {
  return void();
};
void ModuleBuilder___::CheckContext(Array<Type> types) {
  return void();
};
Int32 ModuleBuilder___::GetMemberRef(Module refedModule, Int32 tr, Int32 defToken) {
  return Int32();
};
Int32 ModuleBuilder___::GetMemberRefFromSignature(Int32 tr, String methodName, Array<Byte> signature, Int32 length) {
  return Int32();
};
Int32 ModuleBuilder___::GetMemberRefOfMethodInfo(Int32 tr, RuntimeMethodInfo method) {
  return Int32();
};
Int32 ModuleBuilder___::GetMemberRefOfMethodInfo(Int32 tr, RuntimeConstructorInfo method) {
  return Int32();
};
Int32 ModuleBuilder___::GetMemberRefOfFieldInfo(Int32 tkType, RuntimeTypeHandle declaringType, RuntimeFieldInfo runtimeField) {
  return Int32();
};
Int32 ModuleBuilder___::GetTokenFromTypeSpec(Array<Byte> signature, Int32 length) {
  return Int32();
};
Type ModuleBuilder___::FindTypeBuilderWithName(String strTypeName, Boolean ignoreCase) {
  return nullptr;
};
Int32 ModuleBuilder___::GetTypeRefNested(Type type, Module refedModule, String strRefedModuleFileName) {
  return Int32();
};
MethodToken ModuleBuilder___::InternalGetConstructorToken(ConstructorInfo con, Boolean usingRef) {
  return MethodToken();
};
void ModuleBuilder___::Init(String strModuleName) {
  return void();
};
void ModuleBuilder___::SetSymWriter(ISymbolWriter writer) {
  return void();
};
ModuleHandle ModuleBuilder___::GetModuleHandleImpl() {
  return ModuleHandle();
};
RuntimeModule ModuleBuilder___::GetNativeHandle() {
  return nullptr;
};
RuntimeModule ModuleBuilder___::GetRuntimeModuleFromModule(Module m) {
  return nullptr;
};
Int32 ModuleBuilder___::GetMemberRefToken(MethodBase method, IEnumerable<Type> optionalParameterTypes) {
  return Int32();
};
SignatureHelper ModuleBuilder___::GetMemberRefSignature(CallingConventions call, Type returnType, Array<Type> parameterTypes, IEnumerable<Type> optionalParameterTypes, Int32 cGenericParameters) {
  return nullptr;
};
Boolean ModuleBuilder___::Equals(Object obj) {
  return Boolean();
};
Int32 ModuleBuilder___::GetHashCode() {
  return Int32();
};
Array<Object> ModuleBuilder___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};
Array<Object> ModuleBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};
Boolean ModuleBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};
IList<CustomAttributeData> ModuleBuilder___::GetCustomAttributesData() {
  return nullptr;
};
Array<Type> ModuleBuilder___::GetTypes() {
  return Array<Type>();
};
Array<Type> ModuleBuilder___::GetTypesNoLock() {
  return Array<Type>();
};
Type ModuleBuilder___::GetType(String className) {
  return nullptr;
};
Type ModuleBuilder___::GetType(String className, Boolean ignoreCase) {
  return nullptr;
};
Type ModuleBuilder___::GetType(String className, Boolean throwOnError, Boolean ignoreCase) {
  return nullptr;
};
Type ModuleBuilder___::GetTypeNoLock(String className, Boolean throwOnError, Boolean ignoreCase) {
  return nullptr;
};
Array<Byte> ModuleBuilder___::ResolveSignature(Int32 metadataToken) {
  return Array<Byte>();
};
MethodBase ModuleBuilder___::ResolveMethod(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return nullptr;
};
FieldInfo ModuleBuilder___::ResolveField(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return nullptr;
};
Type ModuleBuilder___::ResolveType(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return nullptr;
};
MemberInfo ModuleBuilder___::ResolveMember(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return nullptr;
};
String ModuleBuilder___::ResolveString(Int32 metadataToken) {
  return nullptr;
};
void ModuleBuilder___::GetPEKind(PortableExecutableKinds& peKind, ImageFileMachine& machine) {
  return void();
};
Boolean ModuleBuilder___::IsResource() {
  return Boolean();
};
Array<FieldInfo> ModuleBuilder___::GetFields(BindingFlags bindingFlags) {
  return Array<FieldInfo>();
};
FieldInfo ModuleBuilder___::GetField(String name, BindingFlags bindingAttr) {
  return nullptr;
};
Array<MethodInfo> ModuleBuilder___::GetMethods(BindingFlags bindingFlags) {
  return Array<MethodInfo>();
};
MethodInfo ModuleBuilder___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
};
TypeBuilder ModuleBuilder___::DefineType(String name) {
  return nullptr;
};
TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr) {
  return nullptr;
};
TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr, Type parent) {
  return nullptr;
};
TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr, Type parent, Int32 typesize) {
  return nullptr;
};
TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr, Type parent, PackingSize packingSize, Int32 typesize) {
  return nullptr;
};
TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr, Type parent, Array<Type> interfaces) {
  return nullptr;
};
TypeBuilder ModuleBuilder___::DefineTypeNoLock(String name, TypeAttributes attr, Type parent, Array<Type> interfaces, PackingSize packingSize, Int32 typesize) {
  return nullptr;
};
TypeBuilder ModuleBuilder___::DefineType(String name, TypeAttributes attr, Type parent, PackingSize packsize) {
  return nullptr;
};
TypeBuilder ModuleBuilder___::DefineTypeNoLock(String name, TypeAttributes attr, Type parent, PackingSize packsize) {
  return nullptr;
};
EnumBuilder ModuleBuilder___::DefineEnum(String name, TypeAttributes visibility, Type underlyingType) {
  return nullptr;
};
EnumBuilder ModuleBuilder___::DefineEnumNoLock(String name, TypeAttributes visibility, Type underlyingType) {
  return nullptr;
};
MethodBuilder ModuleBuilder___::DefinePInvokeMethod(String name, String dllName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  return nullptr;
};
MethodBuilder ModuleBuilder___::DefinePInvokeMethod(String name, String dllName, String entryName, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes, CallingConvention nativeCallConv, CharSet nativeCharSet) {
  return nullptr;
};
MethodBuilder ModuleBuilder___::DefineGlobalMethod(String name, MethodAttributes attributes, Type returnType, Array<Type> parameterTypes) {
  return nullptr;
};
MethodBuilder ModuleBuilder___::DefineGlobalMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  return nullptr;
};
MethodBuilder ModuleBuilder___::DefineGlobalMethod(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  return nullptr;
};
MethodBuilder ModuleBuilder___::DefineGlobalMethodNoLock(String name, MethodAttributes attributes, CallingConventions callingConvention, Type returnType, Array<Type> requiredReturnTypeCustomModifiers, Array<Type> optionalReturnTypeCustomModifiers, Array<Type> parameterTypes, Array<Array<Type>> requiredParameterTypeCustomModifiers, Array<Array<Type>> optionalParameterTypeCustomModifiers) {
  return nullptr;
};
void ModuleBuilder___::CreateGlobalFunctions() {
  return void();
};
void ModuleBuilder___::CreateGlobalFunctionsNoLock() {
  return void();
};
FieldBuilder ModuleBuilder___::DefineInitializedData(String name, Array<Byte> data, FieldAttributes attributes) {
  return nullptr;
};
FieldBuilder ModuleBuilder___::DefineInitializedDataNoLock(String name, Array<Byte> data, FieldAttributes attributes) {
  return nullptr;
};
FieldBuilder ModuleBuilder___::DefineUninitializedData(String name, Int32 size, FieldAttributes attributes) {
  return nullptr;
};
FieldBuilder ModuleBuilder___::DefineUninitializedDataNoLock(String name, Int32 size, FieldAttributes attributes) {
  return nullptr;
};
TypeToken ModuleBuilder___::GetTypeTokenInternal(Type type) {
  return TypeToken();
};
TypeToken ModuleBuilder___::GetTypeTokenInternal(Type type, Boolean getGenericDefinition) {
  return TypeToken();
};
TypeToken ModuleBuilder___::GetTypeToken(Type type) {
  return TypeToken();
};
TypeToken ModuleBuilder___::GetTypeTokenWorkerNoLock(Type type, Boolean getGenericDefinition) {
  return TypeToken();
};
TypeToken ModuleBuilder___::GetTypeToken(String name) {
  return TypeToken();
};
MethodToken ModuleBuilder___::GetMethodToken(MethodInfo method) {
  return MethodToken();
};
MethodToken ModuleBuilder___::GetMethodTokenInternal(MethodInfo method) {
  return MethodToken();
};
MethodToken ModuleBuilder___::GetMethodTokenNoLock(MethodInfo method, Boolean getGenericTypeDefinition) {
  return MethodToken();
};
Int32 ModuleBuilder___::GetMethodTokenInternal(MethodBase method, IEnumerable<Type> optionalParameterTypes, Boolean useMethodDef) {
  return Int32();
};
MethodToken ModuleBuilder___::GetArrayMethodToken(Type arrayClass, String methodName, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  return MethodToken();
};
MethodToken ModuleBuilder___::GetArrayMethodTokenNoLock(Type arrayClass, String methodName, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  return MethodToken();
};
MethodInfo ModuleBuilder___::GetArrayMethod(Type arrayClass, String methodName, CallingConventions callingConvention, Type returnType, Array<Type> parameterTypes) {
  return nullptr;
};
MethodToken ModuleBuilder___::GetConstructorToken(ConstructorInfo con) {
  return MethodToken();
};
FieldToken ModuleBuilder___::GetFieldToken(FieldInfo field) {
  return FieldToken();
};
FieldToken ModuleBuilder___::GetFieldTokenNoLock(FieldInfo field) {
  return FieldToken();
};
StringToken ModuleBuilder___::GetStringConstant(String str) {
  return StringToken();
};
SignatureToken ModuleBuilder___::GetSignatureToken(SignatureHelper sigHelper) {
  return SignatureToken();
};
SignatureToken ModuleBuilder___::GetSignatureToken(Array<Byte> sigBytes, Int32 sigLength) {
  return SignatureToken();
};
void ModuleBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  return void();
};
void ModuleBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  return void();
};
ISymbolWriter ModuleBuilder___::GetSymWriter() {
  return nullptr;
};
ISymbolDocumentWriter ModuleBuilder___::DefineDocument(String url, Guid language, Guid languageVendor, Guid documentType) {
  return nullptr;
};
ISymbolDocumentWriter ModuleBuilder___::DefineDocumentNoLock(String url, Guid language, Guid languageVendor, Guid documentType) {
  return nullptr;
};
Boolean ModuleBuilder___::IsTransient() {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Reflection::Emit::ModuleBuilderNamespace
