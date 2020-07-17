#include "ModuleHandle-dep.h"

#include <System.Private.CoreLib/System/ModuleHandle-dep.h>

namespace System::Private::CoreLib::System::ModuleHandleNamespace {
Int32 ModuleHandle::get_MDStreamVersion() {
  return Int32();
};

ModuleHandle ModuleHandle::GetEmptyMH() {
  return ModuleHandle();
};

void ModuleHandle::Ctor(RuntimeModule module) {
};

RuntimeModule ModuleHandle::GetRuntimeModule() {
  return nullptr;
};

Int32 ModuleHandle::GetHashCode() {
  return Int32();
};

Boolean ModuleHandle::Equals(Object obj) {
  return Boolean();
};

Boolean ModuleHandle::Equals(ModuleHandle handle) {
  return Boolean();
};

Boolean ModuleHandle::op_Equality(ModuleHandle left, ModuleHandle right) {
  return Boolean();
};

Boolean ModuleHandle::op_Inequality(ModuleHandle left, ModuleHandle right) {
  return Boolean();
};

void ModuleHandle::ValidateModulePointer(RuntimeModule module) {
};

RuntimeTypeHandle ModuleHandle::GetRuntimeTypeHandleFromMetadataToken(Int32 typeToken) {
  return RuntimeTypeHandle();
};

RuntimeTypeHandle ModuleHandle::ResolveTypeHandle(Int32 typeToken) {
  return RuntimeTypeHandle();
};

RuntimeTypeHandle ModuleHandle::ResolveTypeHandle(Int32 typeToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  return RuntimeTypeHandle();
};

RuntimeType ModuleHandle::ResolveTypeHandleInternal(RuntimeModule module, Int32 typeToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  return nullptr;
};

RuntimeMethodHandle ModuleHandle::GetRuntimeMethodHandleFromMetadataToken(Int32 methodToken) {
  return RuntimeMethodHandle();
};

RuntimeMethodHandle ModuleHandle::ResolveMethodHandle(Int32 methodToken) {
  return RuntimeMethodHandle();
};

IRuntimeMethodInfo ModuleHandle::ResolveMethodHandleInternal(RuntimeModule module, Int32 methodToken) {
  return nullptr;
};

RuntimeMethodHandle ModuleHandle::ResolveMethodHandle(Int32 methodToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  return RuntimeMethodHandle();
};

IRuntimeMethodInfo ModuleHandle::ResolveMethodHandleInternal(RuntimeModule module, Int32 methodToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  return nullptr;
};

RuntimeMethodHandleInternal ModuleHandle::ResolveMethodHandleInternalCore(RuntimeModule module, Int32 methodToken, Array<IntPtr> typeInstantiationContext, Int32 typeInstCount, Array<IntPtr> methodInstantiationContext, Int32 methodInstCount) {
  return RuntimeMethodHandleInternal();
};

RuntimeFieldHandle ModuleHandle::GetRuntimeFieldHandleFromMetadataToken(Int32 fieldToken) {
  return RuntimeFieldHandle();
};

RuntimeFieldHandle ModuleHandle::ResolveFieldHandle(Int32 fieldToken) {
  return RuntimeFieldHandle();
};

RuntimeFieldHandle ModuleHandle::ResolveFieldHandle(Int32 fieldToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  return RuntimeFieldHandle();
};

IRuntimeFieldInfo ModuleHandle::ResolveFieldHandleInternal(RuntimeModule module, Int32 fieldToken, Array<RuntimeTypeHandle> typeInstantiationContext, Array<RuntimeTypeHandle> methodInstantiationContext) {
  return nullptr;
};

Boolean ModuleHandle::ContainsPropertyMatchingHash(RuntimeModule module, Int32 propertyToken, UInt32 hash) {
  return Boolean();
};

RuntimeType ModuleHandle::GetModuleType(RuntimeModule module) {
  return nullptr;
};

void ModuleHandle::GetPEKind(RuntimeModule module, PortableExecutableKinds& peKind, ImageFileMachine& machine) {
};

MetadataImport ModuleHandle::GetMetadataImport(RuntimeModule module) {
  return MetadataImport();
};

void ModuleHandle::SCtor() {
};

} // namespace System::Private::CoreLib::System::ModuleHandleNamespace
