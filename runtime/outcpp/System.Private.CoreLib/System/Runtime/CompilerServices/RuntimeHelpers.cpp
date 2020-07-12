#include "RuntimeHelpers-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeHelpersNamespace {
Int32 RuntimeHelpers::get_OffsetToStringData() {
  return Int32();
};

void RuntimeHelpers::RunClassConstructor(RuntimeTypeHandle type) {
};

void RuntimeHelpers::RunModuleConstructor(ModuleHandle module) {
};

void RuntimeHelpers::PrepareMethod(RuntimeMethodHandle method) {
};

void RuntimeHelpers::PrepareMethod(RuntimeMethodHandle method, Array<RuntimeTypeHandle> instantiation) {
};

UIntPtr RuntimeHelpers::GetRawObjectDataSize(Object obj) {
  return UIntPtr();
};

UInt16 RuntimeHelpers::GetElementSize(Array<> array) {
  return UInt16();
};

Int32 RuntimeHelpers::GetMultiDimensionalArrayRank(Array<> array) {
  return Int32();
};

Boolean RuntimeHelpers::ObjectHasComponentSize(Object obj) {
  return Boolean();
};

MethodTable* RuntimeHelpers::GetMethodTable(Object obj) {
  return nullptr;
};

IntPtr RuntimeHelpers::AllocateTypeAssociatedMemory(Type type, Int32 size) {
  return IntPtr();
};

Object RuntimeHelpers::GetUninitializedObject(Type type) {
  return nullptr;
};

void RuntimeHelpers::ExecuteCodeWithGuaranteedCleanup(TryCode code, CleanupCode backoutCode, Object userData) {
};

void RuntimeHelpers::PrepareContractedDelegate(Delegate d) {
};

void RuntimeHelpers::ProbeForSufficientStack() {
};

void RuntimeHelpers::PrepareConstrainedRegions() {
};

void RuntimeHelpers::PrepareConstrainedRegionsNoOP() {
};

Boolean RuntimeHelpers::IsPrimitiveType(CorElementType et) {
  return Boolean();
};

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeHelpersNamespace
