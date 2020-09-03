#include "ComActivator-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/InteropServices/ComActivator-dep.h>
#include <System.Private.CoreLib/Internal/Runtime/InteropServices/IsolatedComponentLoadContext-dep.h>
#include <System.Private.CoreLib/Internal/Runtime/InteropServices/LicenseInteropProxy-dep.h>
#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/Dictionary-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidCastException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/IO/Path-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Reflection/AssemblyName-dep.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/ParameterInfo-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/COMException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/CustomQueryInterfaceMode.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Runtime/Loader/AssemblyLoadContext-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
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
    return typeof<Object>();
  }
  if (outer != nullptr) {
    rt::throw_exception<COMException>(String::in::Empty, -2147221232);
  }
  Array<Type> interfaces = classType->GetInterfaces();
  for (Type&& type : *interfaces) {
    if (type->get_GUID() == riid) {
      return type;
    }
  }
  rt::throw_exception<InvalidCastException>();
}

void ComActivator::BasicClassFactory___::ValidateObjectIsMarshallableAsInterface(Object obj, Type interfaceType) {
  if (!(interfaceType == typeof<Object>())) {
    IntPtr comInterfaceForObject = Marshal::GetComInterfaceForObject(obj, interfaceType, CustomQueryInterfaceMode::Ignore);
    Marshal::Release(comInterfaceForObject);
  }
}

Object ComActivator::BasicClassFactory___::CreateAggregatedObject(Object pUnkOuter, Object comObject) {
  IntPtr iUnknownForObject = Marshal::GetIUnknownForObject(pUnkOuter);
  try {
    IntPtr pUnk = Marshal::CreateAggregatedObject(iUnknownForObject, comObject);
    return Marshal::GetObjectForIUnknown(pUnk);
  } catch (...) {
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
  Object::in::ctor();
  _classId = clsid;
  _classType = classType;
}

void ComActivator::LicenseClassFactory___::CreateInstance(Object pUnkOuter, Guid& riid, Object& ppvObject) {
  CreateInstanceInner(pUnkOuter, riid, nullptr, true, ppvObject);
}

void ComActivator::LicenseClassFactory___::LockServer(Boolean fLock) {
}

void ComActivator::LicenseClassFactory___::GetLicInfo(LICINFO& licInfo) {
  Boolean runtimeKeyAvail;
  Boolean licVerified;
  _licenseProxy->GetLicInfo(_classType, runtimeKeyAvail, licVerified);
  licInfo.cbLicInfo = 12;
  licInfo.fRuntimeKeyAvail = runtimeKeyAvail;
  licInfo.fLicVerified = licVerified;
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
  if (cxt.InterfaceId != typeof<IClassFactory>()->get_GUID() && cxt.InterfaceId != typeof<IClassFactory2>()->get_GUID()) {
    rt::throw_exception<NotSupportedException>();
  }
  if (!Path::IsPathRooted(cxt.AssemblyPath)) {
    rt::throw_exception<ArgumentException>(nullptr, "cxt");
  }
  Type type = FindClassType(cxt.ClassId, cxt.AssemblyPath, cxt.AssemblyName, cxt.TypeName);
  if (LicenseInteropProxy::in::HasLicense(type)) {
    return rt::newobj<LicenseClassFactory>(cxt.ClassId, type);
  }
  return rt::newobj<BasicClassFactory>(cxt.ClassId, type);
}

void ComActivator::ClassRegistrationScenarioForType(ComActivationContext cxt, Boolean register一) {
  String str = register一 ? "ComRegisterFunctionAttribute" : "ComUnregisterFunctionAttribute";
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
    for (MethodInfo&& methodInfo : *array) {
      if (methodInfo->GetCustomAttributes(type, true)->get_Length() != 0) {
        if (!methodInfo->get_IsStatic()) {
          String resourceFormat = register一 ? SR::get_InvalidOperation_NonStaticComRegFunction() : SR::get_InvalidOperation_NonStaticComUnRegFunction();
          rt::throw_exception<InvalidOperationException>(SR::Format(resourceFormat, Array<>::in::Empty<Object>()));
        }
        Array<ParameterInfo> parameters = methodInfo->GetParameters();
        if (methodInfo->get_ReturnType() != typeof<void>() || parameters == nullptr || parameters->get_Length() != 1 || (parameters[0]->get_ParameterType() != typeof<String>() && parameters[0]->get_ParameterType() != typeof<Type>())) {
          String resourceFormat2 = register一 ? SR::get_InvalidOperation_InvalidComRegFunctionSig() : SR::get_InvalidOperation_InvalidComUnRegFunctionSig();
          rt::throw_exception<InvalidOperationException>(SR::Format(resourceFormat2, Array<>::in::Empty<Object>()));
        }
        if (flag) {
          String resourceFormat3 = register一 ? SR::get_InvalidOperation_MultipleComRegFunctions() : SR::get_InvalidOperation_MultipleComUnRegFunctions();
          rt::throw_exception<InvalidOperationException>(SR::Format(resourceFormat3, Array<>::in::Empty<Object>()));
        }
        Array<Object> array2 = rt::newarr<Array<Object>>(1);
        if (parameters[0]->get_ParameterType() == typeof<String>()) {
          array2[0] = "HKEY_LOCAL_MACHINE\\SOFTWARE\\Classes\\CLSID\\" + cxt.ClassId.ToString("B");
        } else {
          array2[0] = type2;
        }
        methodInfo->Invoke(nullptr, array2);
        flag = true;
      }
    }
    type3 = type3->get_BaseType();
  }
}

Int32 ComActivator::GetClassFactoryForTypeInternal(ComActivationContextInternal* pCxtInt) {
  ComActivationContextInternal& reference = pCxtInt;
  if (IsLoggingEnabled()) {
  }
  try {
    ComActivationContext cxt = ComActivationContext::Create(reference);
    Object classFactoryForType = GetClassFactoryForType(cxt);
    IntPtr iUnknownForObject = Marshal::GetIUnknownForObject(classFactoryForType);
    Marshal::WriteIntPtr(reference.ClassFactoryDest, iUnknownForObject);
  } catch (Exception ex) {
    return ex->get_HResult();
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
  try {
    ComActivationContext cxt = ComActivationContext::Create(reference);
    ClassRegistrationScenarioForType(cxt, true);
  } catch (Exception ex) {
    return ex->get_HResult();
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
  try {
    ComActivationContext cxt = ComActivationContext::Create(reference);
    ClassRegistrationScenarioForType(cxt, false);
  } catch (Exception ex) {
    return ex->get_HResult();
  }
  return 0;
}

Boolean ComActivator::IsLoggingEnabled() {
  return false;
}

Type ComActivator::FindClassType(Guid clsid, String assemblyPath, String assemblyName, String typeName) {
  try {
    AssemblyLoadContext aLC = GetALC(assemblyPath);
    AssemblyName assemblyName2 = rt::newobj<AssemblyName>(assemblyName);
    Assembly assembly = aLC->LoadFromAssemblyName(assemblyName2);
    Type type = assembly->GetType(typeName);
    if (type != nullptr) {
      return type;
    }
  } catch (Exception) {
    if (!IsLoggingEnabled()) {
    }
  }
  rt::throw_exception<COMException>(String::in::Empty, -2147221231);
}

AssemblyLoadContext ComActivator::GetALC(String assemblyPath) {
  {
    rt::lock(s_assemblyLoadContexts);
    AssemblyLoadContext value;
    if (!s_assemblyLoadContexts->TryGetValue(assemblyPath, value)) {
      value = rt::newobj<IsolatedComponentLoadContext>(assemblyPath);
      s_assemblyLoadContexts->Add(assemblyPath, value);
      return value;
    }
    return value;
  }
}

void ComActivator::cctor() {
  s_assemblyLoadContexts = rt::newobj<Dictionary<String, AssemblyLoadContext>>(StringComparer::in::get_InvariantCultureIgnoreCase());
}

} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComActivatorNamespace
