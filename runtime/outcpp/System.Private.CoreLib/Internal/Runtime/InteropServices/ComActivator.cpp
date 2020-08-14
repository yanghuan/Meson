#include "ComActivator-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/InteropServices/ComActivator-dep.h>
#include <System.Private.CoreLib/Internal/Runtime/InteropServices/LicenseInteropProxy-dep.h>
#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Reflection/AssemblyName-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/COMException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/StringComparer-dep.h>

namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComActivatorNamespace {
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::Loader;

void ComActivator::BasicClassFactory___::ctor(Guid clsid, Type classType) {
  _classId = clsid;
  _classType = classType;
}

Type ComActivator::BasicClassFactory___::GetValidatedInterfaceType(Type classType, Guid& riid, Object outer) {
  if (riid == Marshal::IID_IUnknown) {
  }
  if (outer != nullptr) {
    rt::throw_exception<COMException>(String::in::Empty, -2147221232);
  }
  Array<Type> interfaces = classType->GetInterfaces();
}

void ComActivator::BasicClassFactory___::ValidateObjectIsMarshallableAsInterface(Object obj, Type interfaceType) {
}

Object ComActivator::BasicClassFactory___::CreateAggregatedObject(Object pUnkOuter, Object comObject) {
  IntPtr iUnknownForObject = Marshal::GetIUnknownForObject(pUnkOuter);
  try{
    IntPtr pUnk = Marshal::CreateAggregatedObject(iUnknownForObject, comObject);
    return Marshal::GetObjectForIUnknown(pUnk);
  } finally: {
    Marshal::Release(iUnknownForObject);
  }
}

void ComActivator::BasicClassFactory___::CreateInstance(Object pUnkOuter, Guid& riid, Object& ppvObject) {
  Type validatedInterfaceType = GetValidatedInterfaceType(_classType, riid, pUnkOuter);
  ppvObject = Activator::CreateInstance(_classType);
  if (pUnkOuter != nullptr) {
    ppvObject = CreateAggregatedObject(pUnkOuter, ppvObject);
  }
  ValidateObjectIsMarshallableAsInterface(ppvObject, validatedInterfaceType);
}

void ComActivator::BasicClassFactory___::LockServer(Boolean fLock) {
}

void ComActivator::LicenseClassFactory___::ctor(Guid clsid, Type classType) {
  _licenseProxy = rt::newobj<LicenseInteropProxy>();
}

void ComActivator::LicenseClassFactory___::CreateInstance(Object pUnkOuter, Guid& riid, Object& ppvObject) {
  CreateInstanceInner(pUnkOuter, riid, nullptr, true, ppvObject);
}

void ComActivator::LicenseClassFactory___::LockServer(Boolean fLock) {
}

void ComActivator::LicenseClassFactory___::GetLicInfo(LICINFO& licInfo) {
}

void ComActivator::LicenseClassFactory___::RequestLicKey(Int32 dwReserved, String& pBstrKey) {
  pBstrKey = _licenseProxy->RequestLicKey(_classType);
}

void ComActivator::LicenseClassFactory___::CreateInstanceLic(Object pUnkOuter, Object pUnkReserved, Guid& riid, String bstrKey, Object& ppvObject) {
  CreateInstanceInner(pUnkOuter, riid, bstrKey, false, ppvObject);
}

void ComActivator::LicenseClassFactory___::CreateInstanceInner(Object pUnkOuter, Guid& riid, String key, Boolean isDesignTime, Object& ppvObject) {
  Type validatedInterfaceType = BasicClassFactory::in::GetValidatedInterfaceType(_classType, riid, pUnkOuter);
  ppvObject = _licenseProxy->AllocateAndValidateLicense(_classType, key, isDesignTime);
  if (pUnkOuter != nullptr) {
    ppvObject = BasicClassFactory::in::CreateAggregatedObject(pUnkOuter, ppvObject);
  }
  BasicClassFactory::in::ValidateObjectIsMarshallableAsInterface(ppvObject, validatedInterfaceType);
}

Object ComActivator::GetClassFactoryForType(ComActivationContext cxt) {
}

void ComActivator::ClassRegistrationScenarioForType(ComActivationContext cxt, Boolean register_) {
  String str = register ? "ComRegisterFunctionAttribute" : "ComUnregisterFunctionAttribute";
  Type type = Type::in::GetType("System.Runtime.InteropServices." + str + ", System.Runtime.InteropServices", false);
  if (type == nullptr) {
    return;
  }
  if (!Path::IsPathRooted(cxt.AssemblyPath)) {
    rt::throw_exception<ArgumentException>(nullptr, "cxt");
  }
  Type type2 = FindClassType(cxt.ClassId, cxt.AssemblyPath, cxt.AssemblyName, cxt.TypeName);
  Type type3 = type2;
  Boolean flag = false;
  while (type3 != nullptr && !flag) {
    Array<MethodInfo> methods = type3->GetMethods(BindingFlags::Instance | BindingFlags::Static | BindingFlags::Public | BindingFlags::NonPublic);
    Array<MethodInfo> array = methods;
  }
}

Int32 ComActivator::GetClassFactoryForTypeInternal(ComActivationContextInternal* pCxtInt) {
  ComActivationContextInternal& reference = pCxtInt;
  if (IsLoggingEnabled()) {
  }
  try{
    ComActivationContext cxt = ComActivationContext::Create(reference);
    Object classFactoryForType = GetClassFactoryForType(cxt);
    IntPtr iUnknownForObject = Marshal::GetIUnknownForObject(classFactoryForType);
    Marshal::WriteIntPtr(reference.ClassFactoryDest, iUnknownForObject);
  } catch (Exception ex) {
  }
  return 0;
}

Int32 ComActivator::RegisterClassForTypeInternal(ComActivationContextInternal* pCxtInt) {
  ComActivationContextInternal& reference = pCxtInt;
  if (IsLoggingEnabled()) {
  }
  if (reference.InterfaceId != Guid::Empty || reference.ClassFactoryDest != IntPtr::Zero) {
    rt::throw_exception<ArgumentException>(nullptr, "pCxtInt");
  }
  try{
    ComActivationContext cxt = ComActivationContext::Create(reference);
    ClassRegistrationScenarioForType(cxt, true);
  } catch (Exception ex) {
  }
  return 0;
}

Int32 ComActivator::UnregisterClassForTypeInternal(ComActivationContextInternal* pCxtInt) {
  ComActivationContextInternal& reference = pCxtInt;
  if (IsLoggingEnabled()) {
  }
  if (reference.InterfaceId != Guid::Empty || reference.ClassFactoryDest != IntPtr::Zero) {
    rt::throw_exception<ArgumentException>(nullptr, "pCxtInt");
  }
  try{
    ComActivationContext cxt = ComActivationContext::Create(reference);
    ClassRegistrationScenarioForType(cxt, false);
  } catch (Exception ex) {
  }
  return 0;
}

Boolean ComActivator::IsLoggingEnabled() {
  return false;
}

Type ComActivator::FindClassType(Guid clsid, String assemblyPath, String assemblyName, String typeName) {
  try{
    AssemblyLoadContext aLC = GetALC(assemblyPath);
    AssemblyName assemblyName2 = rt::newobj<AssemblyName>(assemblyName);
    Assembly assembly = aLC->LoadFromAssemblyName(assemblyName2);
    Type type = assembly->GetType(typeName);
    if (type != nullptr) {
      return type;
    }
  } catch (Exception) {
  }
  rt::throw_exception<COMException>(String::in::Empty, -2147221231);
}

AssemblyLoadContext ComActivator::GetALC(String assemblyPath) {
}

void ComActivator::cctor() {
  s_assemblyLoadContexts = rt::newobj<Dictionary<String, AssemblyLoadContext>>(StringComparer::in::get_InvariantCultureIgnoreCase());
}

} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComActivatorNamespace
