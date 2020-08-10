#include "ComWrappers-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComWrappersNamespace {
IntPtr ComWrappers___::GetOrCreateComInterfaceForObject(Object instance, CreateComInterfaceFlags flags) {
  return IntPtr();
}

Boolean ComWrappers___::TryGetOrCreateComInterfaceForObjectInternal(ComWrappers impl, Object instance, CreateComInterfaceFlags flags, IntPtr& retValue) {
  return Boolean();
}

void* ComWrappers___::CallComputeVtables(ComWrappersScenario scenario, ComWrappers comWrappersImpl, Object obj, CreateComInterfaceFlags flags, Int32& count) {
  return nullptr;
}

Object ComWrappers___::GetOrCreateObjectForComInstance(IntPtr externalComObject, CreateObjectFlags flags) {
  return nullptr;
}

Object ComWrappers___::CallCreateObject(ComWrappersScenario scenario, ComWrappers comWrappersImpl, IntPtr externalComObject, CreateObjectFlags flags) {
  return nullptr;
}

Object ComWrappers___::GetOrRegisterObjectForComInstance(IntPtr externalComObject, CreateObjectFlags flags, Object wrapper) {
  return nullptr;
}

Boolean ComWrappers___::TryGetOrCreateObjectForComInstanceInternal(ComWrappers impl, IntPtr externalComObject, CreateObjectFlags flags, Object wrapperMaybe, Object& retValue) {
  return Boolean();
}

void ComWrappers___::CallReleaseObjects(ComWrappers comWrappersImpl, IEnumerable objects) {
}

void ComWrappers___::RegisterForTrackerSupport(ComWrappers instance) {
}

void ComWrappers___::RegisterForMarshalling(ComWrappers instance) {
}

void ComWrappers___::GetIUnknownImpl(IntPtr& fpQueryInterface, IntPtr& fpAddRef, IntPtr& fpRelease) {
}

Int32 ComWrappers___::CallICustomQueryInterface(Object customQueryInterfaceMaybe, Guid& iid, IntPtr& ppObject) {
  return Int32();
}

void ComWrappers___::ctor() {
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComWrappersNamespace
