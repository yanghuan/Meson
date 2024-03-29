#pragma once

#include <System.Private.CoreLib/System/Guid.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Loader {
FORWARD(AssemblyLoadContext)
} // namespace System::Private::CoreLib::System::Runtime::Loader
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(Dictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
FORWARDS(ComActivationContext)
FORWARDS(ComActivationContextInternal)
FORWARD(IClassFactory)
FORWARD(IClassFactory2)
FORWARD(LicenseInteropProxy)
FORWARDS(LICINFO)
namespace ComActivatorNamespace {
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::Loader;
class ComActivator {
  private: CLASS(BasicClassFactory) : public object {
    public: using interface = rt::TypeList<IClassFactory>;
    public: void ctor(Guid clsid, Type classType);
    public: static Type GetValidatedInterfaceType(Type classType, Guid& riid, Object outer);
    public: static IntPtr GetObjectAsInterface(Object obj, Type interfaceType);
    public: static Object CreateAggregatedObject(Object pUnkOuter, Object comObject);
    public: void CreateInstance(Object pUnkOuter, Guid& riid, IntPtr& ppvObject);
    public: void LockServer(Boolean fLock);
    private: Guid _classId;
    private: Type _classType;
  };
  private: CLASS(LicenseClassFactory) : public object {
    public: using interface = rt::TypeList<IClassFactory2, IClassFactory>;
    public: void ctor(Guid clsid, Type classType);
    public: void CreateInstance(Object pUnkOuter, Guid& riid, IntPtr& ppvObject);
    public: void LockServer(Boolean fLock);
    public: void GetLicInfo(LICINFO& licInfo);
    public: void RequestLicKey(Int32 dwReserved, String& pBstrKey);
    public: void CreateInstanceLic(Object pUnkOuter, Object pUnkReserved, Guid& riid, String bstrKey, IntPtr& ppvObject);
    private: void CreateInstanceInner(Object pUnkOuter, Guid& riid, String key, Boolean isDesignTime, IntPtr& ppvObject);
    private: LicenseInteropProxy _licenseProxy;
    private: Guid _classId;
    private: Type _classType;
  };
  public: static Object GetClassFactoryForType(ComActivationContext cxt);
  public: static void ClassRegistrationScenarioForType(ComActivationContext cxt, Boolean register一);
  public: static Int32 GetClassFactoryForTypeInternal(ComActivationContextInternal* pCxtInt);
  public: static Int32 RegisterClassForTypeInternal(ComActivationContextInternal* pCxtInt);
  public: static Int32 UnregisterClassForTypeInternal(ComActivationContextInternal* pCxtInt);
  private: static Boolean IsLoggingEnabled();
  private: static Type FindClassType(Guid clsid, String assemblyPath, String assemblyName, String typeName);
  private: static AssemblyLoadContext GetALC(String assemblyPath);
  public: static void cctor();
  private: static Dictionary<String, AssemblyLoadContext> s_assemblyLoadContexts;
};
} // namespace ComActivatorNamespace
using ComActivator = ComActivatorNamespace::ComActivator;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
