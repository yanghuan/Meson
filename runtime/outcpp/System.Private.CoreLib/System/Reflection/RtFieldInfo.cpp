#include "RtFieldInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::RtFieldInfoNamespace {
INVOCATION_FLAGS RtFieldInfo___::get_InvocationFlags() {
  return INVOCATION_FLAGS::INVOCATION_FLAGS_CONSTRUCTOR_INVOKE;
}

RuntimeFieldHandleInternal RtFieldInfo___::get_ValueOfIRuntimeFieldInfo() {
  return RuntimeFieldHandleInternal();
}

String RtFieldInfo___::get_Name() {
  return nullptr;
}

Int32 RtFieldInfo___::get_MetadataToken() {
  return Int32();
}

RuntimeFieldHandle RtFieldInfo___::get_FieldHandle() {
  return RuntimeFieldHandle();
}

FieldAttributes RtFieldInfo___::get_Attributes() {
  return FieldAttributes::ReservedMask;
}

Type RtFieldInfo___::get_FieldType() {
  return nullptr;
}

INVOCATION_FLAGS RtFieldInfo___::InitializeInvocationFlags() {
  return INVOCATION_FLAGS::INVOCATION_FLAGS_CONSTRUCTOR_INVOKE;
}

void RtFieldInfo___::Ctor(RuntimeFieldHandleInternal handle, RuntimeType declaringType, RuntimeType::in::RuntimeTypeCache reflectedTypeCache, BindingFlags bindingFlags) {
}

void RtFieldInfo___::CheckConsistency(Object target) {
}

Boolean RtFieldInfo___::CacheEquals(Object o) {
  return Boolean();
}

RuntimeModule RtFieldInfo___::GetRuntimeModule() {
  return nullptr;
}

Object RtFieldInfo___::GetValue(Object obj) {
  return nullptr;
}

Object RtFieldInfo___::GetRawConstantValue() {
  return nullptr;
}

Object RtFieldInfo___::GetValueDirect(TypedReference obj) {
  return nullptr;
}

void RtFieldInfo___::SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, CultureInfo culture) {
}

void RtFieldInfo___::SetValueDirect(TypedReference obj, Object value) {
}

IntPtr RtFieldInfo___::GetFieldHandle() {
  return IntPtr();
}

RuntimeType RtFieldInfo___::InitializeFieldType() {
  return nullptr;
}

Array<Type> RtFieldInfo___::GetRequiredCustomModifiers() {
  return Array<Type>();
}

Array<Type> RtFieldInfo___::GetOptionalCustomModifiers() {
  return Array<Type>();
}

} // namespace System::Private::CoreLib::System::Reflection::RtFieldInfoNamespace
