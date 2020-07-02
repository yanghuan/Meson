#include "LicenseInteropProxy-dep.h"

namespace System::Private::CoreLib::Internal::Runtime::InteropServices::LicenseInteropProxyNamespace {
Object LicenseInteropProxy___::Create() {
  return nullptr;
};
Boolean LicenseInteropProxy___::HasLicense(Type type) {
  return Boolean();
};
void LicenseInteropProxy___::GetLicInfo(Type type, Boolean& runtimeKeyAvail, Boolean& licVerified) {
  return void();
};
String LicenseInteropProxy___::RequestLicKey(Type type) {
  return nullptr;
};
Object LicenseInteropProxy___::AllocateAndValidateLicense(Type type, String key, Boolean isDesignTime) {
  return nullptr;
};
void LicenseInteropProxy___::GetCurrentContextInfo(RuntimeTypeHandle rth, Boolean& isDesignTime, IntPtr& bstrKey) {
  return void();
};
void LicenseInteropProxy___::SaveKeyInCurrentContext(IntPtr bstrKey) {
  return void();
};
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::LicenseInteropProxyNamespace
