#include "ComActivator-dep.h"

namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComActivatorNamespace {
void ComActivator::BasicClassFactory___::Ctor(Guid clsid, Type classType) {
};

Type ComActivator::BasicClassFactory___::GetValidatedInterfaceType(Type classType, Guid& riid, Object outer) {
  return nullptr;
};

void ComActivator::BasicClassFactory___::ValidateObjectIsMarshallableAsInterface(Object obj, Type interfaceType) {
};

Object ComActivator::BasicClassFactory___::CreateAggregatedObject(Object pUnkOuter, Object comObject) {
  return nullptr;
};

void ComActivator::BasicClassFactory___::CreateInstance(Object pUnkOuter, Guid& riid, Object& ppvObject) {
};

void ComActivator::BasicClassFactory___::LockServer(Boolean fLock) {
};

void ComActivator::LicenseClassFactory___::Ctor(Guid clsid, Type classType) {
};

void ComActivator::LicenseClassFactory___::CreateInstance(Object pUnkOuter, Guid& riid, Object& ppvObject) {
};

void ComActivator::LicenseClassFactory___::LockServer(Boolean fLock) {
};

void ComActivator::LicenseClassFactory___::GetLicInfo(LICINFO& licInfo) {
};

void ComActivator::LicenseClassFactory___::RequestLicKey(Int32 dwReserved, String& pBstrKey) {
};

void ComActivator::LicenseClassFactory___::CreateInstanceLic(Object pUnkOuter, Object pUnkReserved, Guid& riid, String bstrKey, Object& ppvObject) {
};

void ComActivator::LicenseClassFactory___::CreateInstanceInner(Object pUnkOuter, Guid& riid, String key, Boolean isDesignTime, Object& ppvObject) {
};

Object ComActivator::GetClassFactoryForType(ComActivationContext cxt) {
  return nullptr;
};

void ComActivator::ClassRegistrationScenarioForType(ComActivationContext cxt, Boolean register_) {
};

Int32 ComActivator::GetClassFactoryForTypeInternal(ComActivationContextInternal* pCxtInt) {
  return Int32();
};

Int32 ComActivator::RegisterClassForTypeInternal(ComActivationContextInternal* pCxtInt) {
  return Int32();
};

Int32 ComActivator::UnregisterClassForTypeInternal(ComActivationContextInternal* pCxtInt) {
  return Int32();
};

Boolean ComActivator::IsLoggingEnabled() {
  return Boolean();
};

Type ComActivator::FindClassType(Guid clsid, String assemblyPath, String assemblyName, String typeName) {
  return nullptr;
};

AssemblyLoadContext ComActivator::GetALC(String assemblyPath) {
  return nullptr;
};

void ComActivator::SCtor() {
};

} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::ComActivatorNamespace
