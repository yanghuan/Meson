#include "RuntimeModule-dep.h"

#include <System.Private.CoreLib/System/Reflection/RuntimeModule-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeModuleNamespace {
Int32 RuntimeModule___::get_MDStreamVersion() {
  return Int32();
};

RuntimeType RuntimeModule___::get_RuntimeType() {
  return nullptr;
};

MetadataImport RuntimeModule___::get_MetadataImport() {
  return MetadataImport();
};

String RuntimeModule___::get_FullyQualifiedName() {
  return nullptr;
};

Guid RuntimeModule___::get_ModuleVersionId() {
  return Guid();
};

Int32 RuntimeModule___::get_MetadataToken() {
  return Int32();
};

String RuntimeModule___::get_ScopeName() {
  return nullptr;
};

String RuntimeModule___::get_Name() {
  return nullptr;
};

Assembly RuntimeModule___::get_Assembly() {
  return nullptr;
};

void RuntimeModule___::Ctor() {
};

Array<RuntimeType> RuntimeModule___::GetDefinedTypes() {
  return Array<RuntimeType>();
};

Array<RuntimeTypeHandle> RuntimeModule___::ConvertToTypeHandleArray(Array<Type> genericArguments) {
  return Array<RuntimeTypeHandle>();
};

Array<Byte> RuntimeModule___::ResolveSignature(Int32 metadataToken) {
  return Array<Byte>();
};

MethodBase RuntimeModule___::ResolveMethod(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return nullptr;
};

FieldInfo RuntimeModule___::ResolveLiteralField(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return nullptr;
};

FieldInfo RuntimeModule___::ResolveField(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return nullptr;
};

Type RuntimeModule___::ResolveType(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return nullptr;
};

MemberInfo RuntimeModule___::ResolveMember(Int32 metadataToken, Array<Type> genericTypeArguments, Array<Type> genericMethodArguments) {
  return nullptr;
};

String RuntimeModule___::ResolveString(Int32 metadataToken) {
  return nullptr;
};

void RuntimeModule___::GetPEKind(PortableExecutableKinds& peKind, ImageFileMachine& machine) {
};

MethodInfo RuntimeModule___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
};

MethodInfo RuntimeModule___::GetMethodInternal(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  return nullptr;
};

Boolean RuntimeModule___::IsTransientInternal() {
  return Boolean();
};

Array<Object> RuntimeModule___::GetCustomAttributes(Boolean inherit) {
  return Array<Object>();
};

Array<Object> RuntimeModule___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  return Array<Object>();
};

Boolean RuntimeModule___::IsDefined(Type attributeType, Boolean inherit) {
  return Boolean();
};

IList<CustomAttributeData> RuntimeModule___::GetCustomAttributesData() {
  return nullptr;
};

void RuntimeModule___::GetObjectData(SerializationInfo info, StreamingContext context) {
};

Type RuntimeModule___::GetType(String className, Boolean throwOnError, Boolean ignoreCase) {
  return nullptr;
};

String RuntimeModule___::GetFullyQualifiedName() {
  return nullptr;
};

Array<Type> RuntimeModule___::GetTypes() {
  return Array<Type>();
};

Boolean RuntimeModule___::IsResource() {
  return Boolean();
};

Array<FieldInfo> RuntimeModule___::GetFields(BindingFlags bindingFlags) {
  return Array<FieldInfo>();
};

FieldInfo RuntimeModule___::GetField(String name, BindingFlags bindingAttr) {
  return nullptr;
};

Array<MethodInfo> RuntimeModule___::GetMethods(BindingFlags bindingFlags) {
  return Array<MethodInfo>();
};

RuntimeAssembly RuntimeModule___::GetRuntimeAssembly() {
  return nullptr;
};

ModuleHandle RuntimeModule___::GetModuleHandleImpl() {
  return ModuleHandle();
};

RuntimeModule RuntimeModule___::GetNativeHandle() {
  return nullptr;
};

IntPtr RuntimeModule___::GetUnderlyingNativeHandle() {
  return IntPtr();
};

} // namespace System::Private::CoreLib::System::Reflection::RuntimeModuleNamespace
