#include "ComWrappers-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ObjectHandleOnStack-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ComWrappers-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/ICustomQueryInterface.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComWrappersNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Threading;

IntPtr ComWrappers___::GetOrCreateComInterfaceForObject(Object instance, CreateComInterfaceFlags flags) {
  IntPtr retValue;
  if (!TryGetOrCreateComInterfaceForObjectInternal((ComWrappers)this, instance, flags, retValue)) {
    rt::throw_exception<ArgumentException>(nullptr, "instance");
  }
  return retValue;
}

Boolean ComWrappers___::TryGetOrCreateComInterfaceForObjectInternal(ComWrappers impl, Object instance, CreateComInterfaceFlags flags, IntPtr& retValue) {
  if (instance == nullptr) {
    rt::throw_exception<ArgumentNullException>("instance");
  }
  return TryGetOrCreateComInterfaceForObjectInternal(ObjectHandleOnStack::Create(impl), ObjectHandleOnStack::Create(instance), flags, retValue);
}

void* ComWrappers___::CallComputeVtables(ComWrappersScenario scenario, ComWrappers comWrappersImpl, Object obj, CreateComInterfaceFlags flags, Int32& count) {
  ComWrappers comWrappers = nullptr;
  switch (scenario) {
    case ComWrappersScenario::Instance:
      comWrappers = comWrappersImpl;
      break;
    case ComWrappersScenario::TrackerSupportGlobalInstance:
      comWrappers = s_globalInstanceForTrackerSupport;
      break;
    case ComWrappersScenario::MarshallingGlobalInstance:
      comWrappers = s_globalInstanceForMarshalling;
      break;
  }
  if (comWrappers == nullptr) {
    count = -1;
    return nullptr;
  }
  return comWrappers->ComputeVtables(obj, flags, count);
}

Object ComWrappers___::GetOrCreateObjectForComInstance(IntPtr externalComObject, CreateObjectFlags flags) {
  Object retValue;
  if (!TryGetOrCreateObjectForComInstanceInternal((ComWrappers)this, externalComObject, flags, nullptr, retValue)) {
    rt::throw_exception<ArgumentNullException>("externalComObject");
  }
  return retValue;
}

Object ComWrappers___::CallCreateObject(ComWrappersScenario scenario, ComWrappers comWrappersImpl, IntPtr externalComObject, CreateObjectFlags flags) {
  ComWrappers comWrappers = nullptr;
  switch (scenario) {
    case ComWrappersScenario::Instance:
      comWrappers = comWrappersImpl;
      break;
    case ComWrappersScenario::TrackerSupportGlobalInstance:
      comWrappers = s_globalInstanceForTrackerSupport;
      break;
    case ComWrappersScenario::MarshallingGlobalInstance:
      comWrappers = s_globalInstanceForMarshalling;
      break;
  }
  auto& default = comWrappers;
  return default == nullptr ? nullptr : default->CreateObject(externalComObject, flags);
}

Object ComWrappers___::GetOrRegisterObjectForComInstance(IntPtr externalComObject, CreateObjectFlags flags, Object wrapper) {
  if (wrapper == nullptr) {
    rt::throw_exception<ArgumentNullException>("externalComObject");
  }
  Object retValue;
  if (!TryGetOrCreateObjectForComInstanceInternal((ComWrappers)this, externalComObject, flags, wrapper, retValue)) {
    rt::throw_exception<ArgumentNullException>("externalComObject");
  }
  return retValue;
}

Boolean ComWrappers___::TryGetOrCreateObjectForComInstanceInternal(ComWrappers impl, IntPtr externalComObject, CreateObjectFlags flags, Object wrapperMaybe, Object& retValue) {
  if (externalComObject == IntPtr::Zero) {
    rt::throw_exception<ArgumentNullException>("externalComObject");
  }
  Object o = wrapperMaybe;
  retValue = nullptr;
  return TryGetOrCreateObjectForComInstanceInternal(ObjectHandleOnStack::Create(impl), externalComObject, flags, ObjectHandleOnStack::Create(o), ObjectHandleOnStack::Create(retValue));
}

void ComWrappers___::CallReleaseObjects(ComWrappers comWrappersImpl, IEnumerable objects) {
  auto& default = comWrappersImpl;
  (default != nullptr ? default : s_globalInstanceForTrackerSupport)->ReleaseObjects(objects);
}

void ComWrappers___::RegisterForTrackerSupport(ComWrappers instance) {
  if (instance == nullptr) {
    rt::throw_exception<ArgumentNullException>("instance");
  }
  if (Interlocked::CompareExchange(s_globalInstanceForTrackerSupport, instance, nullptr) != nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ResetGlobalComWrappersInstance());
  }
  SetGlobalInstanceRegisteredForTrackerSupport();
}

void ComWrappers___::RegisterForMarshalling(ComWrappers instance) {
  if (instance == nullptr) {
    rt::throw_exception<ArgumentNullException>("instance");
  }
  if (Interlocked::CompareExchange(s_globalInstanceForMarshalling, instance, nullptr) != nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ResetGlobalComWrappersInstance());
  }
  SetGlobalInstanceRegisteredForMarshalling();
}

void ComWrappers___::GetIUnknownImpl(IntPtr& fpQueryInterface, IntPtr& fpAddRef, IntPtr& fpRelease) {
  GetIUnknownImplInternal(fpQueryInterface, fpAddRef, fpRelease);
}

Int32 ComWrappers___::CallICustomQueryInterface(Object customQueryInterfaceMaybe, Guid& iid, IntPtr& ppObject) {
  ICustomQueryInterface customQueryInterface = rt::as<ICustomQueryInterface>(customQueryInterfaceMaybe);
  if (customQueryInterface == nullptr) {
    ppObject = IntPtr::Zero;
    return -1;
  }
  return (Int32)customQueryInterface->GetInterface(iid, ppObject);
}

void ComWrappers___::ctor() {
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComWrappersNamespace
