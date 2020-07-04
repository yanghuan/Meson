#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Guid.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
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
FORWARDS(LICINFO)
FORWARD(LicenseInteropProxy)
FORWARDS(ComActivationContext)
FORWARDS(ComActivationContextInternal)
namespace ComActivatorNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using namespace ::System::Private::CoreLib::System::Runtime::Loader;
class ComActivator {
  private: CLASS(BasicClassFactory) {
    public: static Type GetValidatedInterfaceType(Type classType, Guid& riid, Object outer);
    public: static void ValidateObjectIsMarshallableAsInterface(Object obj, Type interfaceType);
    public: static Object CreateAggregatedObject(Object pUnkOuter, Object comObject);
    public: void CreateInstance(Object pUnkOuter, Guid& riid, Object& ppvObject);
    public: void LockServer(Boolean fLock);
    private: Guid _classId;
    private: Type _classType;
  };
  private: CLASS(LicenseClassFactory) {
    public: void CreateInstance(Object pUnkOuter, Guid& riid, Object& ppvObject);
    public: void LockServer(Boolean fLock);
    public: void GetLicInfo(LICINFO& licInfo);
    public: void RequestLicKey(Int32 dwReserved, String& pBstrKey);
    public: void CreateInstanceLic(Object pUnkOuter, Object pUnkReserved, Guid& riid, String bstrKey, Object& ppvObject);
    private: void CreateInstanceInner(Object pUnkOuter, Guid& riid, String key, Boolean isDesignTime, Object& ppvObject);
    private: LicenseInteropProxy _licenseProxy;
    private: Guid _classId;
    private: Type _classType;
  };
  public: static Object GetClassFactoryForType(ComActivationContext cxt);
  public: static void ClassRegistrationScenarioForType(ComActivationContext cxt, Boolean register_);
  public: static Int32 GetClassFactoryForTypeInternal(ComActivationContextInternal* pCxtInt);
  public: static Int32 RegisterClassForTypeInternal(ComActivationContextInternal* pCxtInt);
  public: static Int32 UnregisterClassForTypeInternal(ComActivationContextInternal* pCxtInt);
  private: static Boolean IsLoggingEnabled();
  private: static Type FindClassType(Guid clsid, String assemblyPath, String assemblyName, String typeName);
  private: static AssemblyLoadContext GetALC(String assemblyPath);
  private: static Dictionary<String, AssemblyLoadContext> s_assemblyLoadContexts;
};
} // namespace ComActivatorNamespace
using ComActivator = ComActivatorNamespace::ComActivator;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
