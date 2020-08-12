#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(IntPtr)
FORWARDS(RuntimeTypeHandle)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::Internal::Runtime::InteropServices {
namespace LicenseInteropProxyNamespace {
using namespace System;
using namespace System::Reflection;
CLASS(LicenseInteropProxy) : public Object::in {
  public: void ctor();
  public: static Object Create();
  public: static Boolean HasLicense(Type type);
  public: void GetLicInfo(Type type, Boolean& runtimeKeyAvail, Boolean& licVerified);
  public: String RequestLicKey(Type type);
  public: Object AllocateAndValidateLicense(Type type, String key, Boolean isDesignTime);
  public: void GetCurrentContextInfo(RuntimeTypeHandle rth, Boolean& isDesignTime, IntPtr& bstrKey);
  public: void SaveKeyInCurrentContext(IntPtr bstrKey);
  private: static void ctor_static();
  private: static Type s_licenseAttrType;
  private: static Type s_licenseExceptionType;
  private: MethodInfo _createWithContext;
  private: MethodInfo _validateTypeAndReturnDetails;
  private: MethodInfo _getCurrentContextInfo;
  private: MethodInfo _createDesignContext;
  private: MethodInfo _createRuntimeContext;
  private: MethodInfo _setSavedLicenseKey;
  private: Type _licInfoHelper;
  private: MethodInfo _licInfoHelperContains;
  private: Object _licContext;
  private: Type _targetRcwType;
};
} // namespace LicenseInteropProxyNamespace
using LicenseInteropProxy = LicenseInteropProxyNamespace::LicenseInteropProxy;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices
