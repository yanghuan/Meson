#include "RuntimeMethodHandle-dep.h"

namespace System::Private::CoreLib::System::RuntimeMethodHandleNamespace {
IntPtr RuntimeMethodHandle::get_Value() {
  return IntPtr();
};
IRuntimeMethodInfo RuntimeMethodHandle::EnsureNonNullMethodInfo(IRuntimeMethodInfo method) {
  return nullptr;
};
IRuntimeMethodInfo RuntimeMethodHandle::GetMethodInfo() {
  return nullptr;
};
IntPtr RuntimeMethodHandle::GetValueInternal(RuntimeMethodHandle rmh) {
  return IntPtr();
};
void RuntimeMethodHandle::GetObjectData(SerializationInfo info, StreamingContext context) {
  return void();
};
Int32 RuntimeMethodHandle::GetHashCode() {
  return Int32();
};
Boolean RuntimeMethodHandle::Equals(Object obj) {
  return Boolean();
};
Boolean RuntimeMethodHandle::Equals(RuntimeMethodHandle handle) {
  return Boolean();
};
Boolean RuntimeMethodHandle::IsNullHandle() {
  return Boolean();
};
IntPtr RuntimeMethodHandle::GetFunctionPointer() {
  return IntPtr();
};
IRuntimeMethodInfo RuntimeMethodHandle::GetCurrentMethod(StackCrawlMark& stackMark) {
  return nullptr;
};
MethodAttributes RuntimeMethodHandle::GetAttributes(IRuntimeMethodInfo method) {
  return MethodAttributes();
};
String RuntimeMethodHandle::ConstructInstantiation(IRuntimeMethodInfo method, TypeNameFormatFlags format) {
  return nullptr;
};
RuntimeType RuntimeMethodHandle::GetDeclaringType(IRuntimeMethodInfo method) {
  return nullptr;
};
Int32 RuntimeMethodHandle::GetSlot(IRuntimeMethodInfo method) {
  return Int32();
};
String RuntimeMethodHandle::GetName(IRuntimeMethodInfo method) {
  return nullptr;
};
MdUtf8String RuntimeMethodHandle::GetUtf8Name(RuntimeMethodHandleInternal method) {
  return MdUtf8String();
};
Array<RuntimeType> RuntimeMethodHandle::GetMethodInstantiationInternal(IRuntimeMethodInfo method) {
  return Array<RuntimeType>();
};
Array<RuntimeType> RuntimeMethodHandle::GetMethodInstantiationInternal(RuntimeMethodHandleInternal method) {
  return Array<RuntimeType>();
};
Array<Type> RuntimeMethodHandle::GetMethodInstantiationPublic(IRuntimeMethodInfo method) {
  return Array<Type>();
};
Boolean RuntimeMethodHandle::HasMethodInstantiation(IRuntimeMethodInfo method) {
  return Boolean();
};
Boolean RuntimeMethodHandle::IsGenericMethodDefinition(IRuntimeMethodInfo method) {
  return Boolean();
};
IRuntimeMethodInfo RuntimeMethodHandle::GetTypicalMethodDefinition(IRuntimeMethodInfo method) {
  return nullptr;
};
Int32 RuntimeMethodHandle::GetGenericParameterCount(IRuntimeMethodInfo method) {
  return Int32();
};
IRuntimeMethodInfo RuntimeMethodHandle::StripMethodInstantiation(IRuntimeMethodInfo method) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::RuntimeMethodHandleNamespace
