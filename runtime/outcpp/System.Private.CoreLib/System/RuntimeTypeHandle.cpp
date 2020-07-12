#include "RuntimeTypeHandle-dep.h"

#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>

namespace System::Private::CoreLib::System::RuntimeTypeHandleNamespace {
RuntimeMethodHandleInternal RuntimeTypeHandle::IntroducedMethodEnumerator::get_Current() {
  return RuntimeMethodHandleInternal();
};

Boolean RuntimeTypeHandle::IntroducedMethodEnumerator::MoveNext() {
  return Boolean();
};

RuntimeTypeHandle::IntroducedMethodEnumerator RuntimeTypeHandle::IntroducedMethodEnumerator::GetEnumerator() {
  return RuntimeTypeHandle::IntroducedMethodEnumerator();
};

IntPtr RuntimeTypeHandle::get_Value() {
  return IntPtr();
};

RuntimeTypeHandle RuntimeTypeHandle::GetNativeHandle() {
  return RuntimeTypeHandle();
};

RuntimeType RuntimeTypeHandle::GetTypeChecked() {
  return nullptr;
};

Type RuntimeTypeHandle::GetTypeHelper(Type typeStart, Array<Type> genericArgs, IntPtr pModifiers, Int32 cModifiers) {
  return nullptr;
};

Boolean RuntimeTypeHandle::op_Equality(RuntimeTypeHandle left, Object right) {
  return Boolean();
};

Boolean RuntimeTypeHandle::op_Equality(Object left, RuntimeTypeHandle right) {
  return Boolean();
};

Boolean RuntimeTypeHandle::op_Inequality(RuntimeTypeHandle left, Object right) {
  return Boolean();
};

Boolean RuntimeTypeHandle::op_Inequality(Object left, RuntimeTypeHandle right) {
  return Boolean();
};

Int32 RuntimeTypeHandle::GetHashCode() {
  return Int32();
};

Boolean RuntimeTypeHandle::Equals(Object obj) {
  return Boolean();
};

Boolean RuntimeTypeHandle::Equals(RuntimeTypeHandle handle) {
  return Boolean();
};

Boolean RuntimeTypeHandle::IsTypeDefinition(RuntimeType type) {
  return Boolean();
};

Boolean RuntimeTypeHandle::IsPrimitive(RuntimeType type) {
  return Boolean();
};

Boolean RuntimeTypeHandle::IsByRef(RuntimeType type) {
  return Boolean();
};

Boolean RuntimeTypeHandle::IsPointer(RuntimeType type) {
  return Boolean();
};

Boolean RuntimeTypeHandle::IsArray(RuntimeType type) {
  return Boolean();
};

Boolean RuntimeTypeHandle::IsSZArray(RuntimeType type) {
  return Boolean();
};

Boolean RuntimeTypeHandle::HasElementType(RuntimeType type) {
  return Boolean();
};

Array<IntPtr> RuntimeTypeHandle::CopyRuntimeTypeHandles(Array<RuntimeTypeHandle> inHandles, Int32& length) {
  return Array<IntPtr>();
};

Array<IntPtr> RuntimeTypeHandle::CopyRuntimeTypeHandles(Array<Type> inHandles, Int32& length) {
  return Array<IntPtr>();
};

RuntimeType RuntimeTypeHandle::GetRuntimeType() {
  return nullptr;
};

ModuleHandle RuntimeTypeHandle::GetModuleHandle() {
  return ModuleHandle();
};

RuntimeTypeHandle::IntroducedMethodEnumerator RuntimeTypeHandle::GetIntroducedMethods(RuntimeType type) {
  return RuntimeTypeHandle::IntroducedMethodEnumerator();
};

Array<Type> RuntimeTypeHandle::GetConstraints() {
  return Array<Type>();
};

IntPtr RuntimeTypeHandle::GetGCHandle(GCHandleType type) {
  return IntPtr();
};

IntPtr RuntimeTypeHandle::FreeGCHandle(IntPtr objHandle) {
  return IntPtr();
};

void RuntimeTypeHandle::VerifyInterfaceIsImplemented(RuntimeTypeHandle interfaceHandle) {
};

RuntimeMethodHandleInternal RuntimeTypeHandle::GetInterfaceMethodImplementation(RuntimeTypeHandle interfaceHandle, RuntimeMethodHandleInternal interfaceMethodHandle) {
  return RuntimeMethodHandleInternal();
};

Boolean RuntimeTypeHandle::IsVisible(RuntimeType type) {
  return Boolean();
};

String RuntimeTypeHandle::ConstructName(TypeNameFormatFlags formatFlags) {
  return nullptr;
};

MdUtf8String RuntimeTypeHandle::GetUtf8Name(RuntimeType type) {
  return MdUtf8String();
};

RuntimeType RuntimeTypeHandle::GetTypeByName(String name, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark) {
  return nullptr;
};

RuntimeType RuntimeTypeHandle::GetTypeByName(String name, Boolean throwOnError, Boolean ignoreCase, StackCrawlMark& stackMark, AssemblyLoadContext assemblyLoadContext) {
  return nullptr;
};

RuntimeType RuntimeTypeHandle::GetTypeByNameUsingCARules(String name, RuntimeModule scope) {
  return nullptr;
};

Array<RuntimeType> RuntimeTypeHandle::GetInstantiationInternal() {
  return Array<RuntimeType>();
};

Array<Type> RuntimeTypeHandle::GetInstantiationPublic() {
  return Array<Type>();
};

RuntimeType RuntimeTypeHandle::Instantiate(Array<Type> inst) {
  return nullptr;
};

RuntimeType RuntimeTypeHandle::MakeArray(Int32 rank) {
  return nullptr;
};

RuntimeType RuntimeTypeHandle::MakeSZArray() {
  return nullptr;
};

RuntimeType RuntimeTypeHandle::MakeByRef() {
  return nullptr;
};

RuntimeType RuntimeTypeHandle::MakePointer() {
  return nullptr;
};

RuntimeType RuntimeTypeHandle::GetGenericTypeDefinition(RuntimeType type) {
  return nullptr;
};

Int32 RuntimeTypeHandle::GetGenericVariableIndex() {
  return Int32();
};

Boolean RuntimeTypeHandle::ContainsGenericVariables() {
  return Boolean();
};

Boolean RuntimeTypeHandle::SatisfiesConstraints(RuntimeType paramType, Array<RuntimeType> typeContext, Array<RuntimeType> methodContext, RuntimeType toType) {
  return Boolean();
};

MetadataImport RuntimeTypeHandle::GetMetadataImport(RuntimeType type) {
  return MetadataImport();
};

void RuntimeTypeHandle::GetObjectData(SerializationInfo info, StreamingContext context) {
};

} // namespace System::Private::CoreLib::System::RuntimeTypeHandleNamespace
