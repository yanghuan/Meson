#include "LicenseInteropProxy-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/InteropServices/LicenseInteropProxy-dep.h>
#include <System.Private.CoreLib/System/Activator-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/IDisposable.h>
#include <System.Private.CoreLib/System/Reflection/BindingFlags.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/COMException-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/Marshal-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::Internal::Runtime::InteropServices::LicenseInteropProxyNamespace {
using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::InteropServices;

void LicenseInteropProxy___::ctor() {
  Type type = Type::in::GetType("System.ComponentModel.LicenseManager, System.ComponentModel.TypeConverter", true);
  Type type2 = Type::in::GetType("System.ComponentModel.LicenseContext, System.ComponentModel.TypeConverter", true);
  _setSavedLicenseKey = type2->GetMethod("SetSavedLicenseKey", BindingFlags::Instance | BindingFlags::Public);
  _createWithContext = type->GetMethod("CreateWithContext", rt::newarr<Array<Type>>(2));
  Type nestedType = type->GetNestedType("LicenseInteropHelper", BindingFlags::NonPublic);
  _validateTypeAndReturnDetails = nestedType->GetMethod("ValidateAndRetrieveLicenseDetails", BindingFlags::Static | BindingFlags::Public);
  _getCurrentContextInfo = nestedType->GetMethod("GetCurrentContextInfo", BindingFlags::Static | BindingFlags::Public);
  Type nestedType2 = type->GetNestedType("CLRLicenseContext", BindingFlags::NonPublic);
  _createDesignContext = nestedType2->GetMethod("CreateDesignContext", BindingFlags::Static | BindingFlags::Public);
  _createRuntimeContext = nestedType2->GetMethod("CreateRuntimeContext", BindingFlags::Static | BindingFlags::Public);
  _licInfoHelper = type->GetNestedType("LicInfoHelperLicenseContext", BindingFlags::NonPublic);
  _licInfoHelperContains = _licInfoHelper->GetMethod("Contains", BindingFlags::Instance | BindingFlags::Public);
}

Object LicenseInteropProxy___::Create() {
  return rt::newobj<LicenseInteropProxy>();
}

Boolean LicenseInteropProxy___::HasLicense(Type type) {
  if (s_licenseAttrType == nullptr) {
    return false;
  }
  return type->IsDefined(s_licenseAttrType, true);
}

void LicenseInteropProxy___::GetLicInfo(Type type, Boolean& runtimeKeyAvail, Boolean& licVerified) {
  runtimeKeyAvail = false;
  licVerified = false;
  Object obj = Activator::CreateInstance(_licInfoHelper);
  Array<Object> array = rt::newarr<Array<Object>>(4);
  if ((Boolean)_validateTypeAndReturnDetails->Invoke(nullptr, BindingFlags::DoNotWrapExceptions, nullptr, array, nullptr)) {
    IDisposable disposable = (IDisposable)array[2];
    if (disposable != nullptr) {
      disposable->Dispose();
      licVerified = true;
    }
    array = rt::newarr<Array<Object>>(1);
    runtimeKeyAvail = (Boolean)_licInfoHelperContains->Invoke(obj, BindingFlags::DoNotWrapExceptions, nullptr, array, nullptr);
  }
}

String LicenseInteropProxy___::RequestLicKey(Type type) {
  Array<Object> array = rt::newarr<Array<Object>>(4);
  if (!(Boolean)_validateTypeAndReturnDetails->Invoke(nullptr, BindingFlags::DoNotWrapExceptions, nullptr, array, nullptr)) {
    rt::throw_exception<COMException>();
  }
  auto& default = ((IDisposable)array[2]);
  default == nullptr ? nullptr : default->Dispose();
  String text = (String)array[3];
  if (text == nullptr) {
    rt::throw_exception<COMException>();
  }
  return text;
}

Object LicenseInteropProxy___::AllocateAndValidateLicense(Type type, String key, Boolean isDesignTime) {
  Object obj;
  if (isDesignTime) {
    Array<Object> parameters = rt::newarr<Array<Object>>(1);
    obj = _createDesignContext->Invoke(nullptr, BindingFlags::DoNotWrapExceptions, nullptr, parameters, nullptr);
  } else {
    Array<Object> parameters = rt::newarr<Array<Object>>(2);
    obj = _createRuntimeContext->Invoke(nullptr, BindingFlags::DoNotWrapExceptions, nullptr, parameters, nullptr);
  }
  try {
    Array<Object> parameters = rt::newarr<Array<Object>>(2);
    return _createWithContext->Invoke(nullptr, BindingFlags::DoNotWrapExceptions, nullptr, parameters, nullptr);
  } catch (Exception ex) {
  }
}

void LicenseInteropProxy___::GetCurrentContextInfo(RuntimeTypeHandle rth, Boolean& isDesignTime, IntPtr& bstrKey) {
  Type typeFromHandle = Type::in::GetTypeFromHandle(rth);
  Array<Object> array = rt::newarr<Array<Object>>(3);
  _licContext = _getCurrentContextInfo->Invoke(nullptr, BindingFlags::DoNotWrapExceptions, nullptr, array, nullptr);
  _targetRcwType = typeFromHandle;
  isDesignTime = (Boolean)array[1];
  bstrKey = Marshal::StringToBSTR((String)array[2]);
}

void LicenseInteropProxy___::SaveKeyInCurrentContext(IntPtr bstrKey) {
  if (!(bstrKey == IntPtr::Zero)) {
    String text = Marshal::PtrToStringBSTR(bstrKey);
    Array<Object> parameters = rt::newarr<Array<Object>>(2);
    _setSavedLicenseKey->Invoke(_licContext, BindingFlags::DoNotWrapExceptions, nullptr, parameters, nullptr);
  }
}

void LicenseInteropProxy___::cctor() {
  s_licenseAttrType = Type::in::GetType("System.ComponentModel.LicenseProviderAttribute, System.ComponentModel.TypeConverter", false);
  s_licenseExceptionType = Type::in::GetType("System.ComponentModel.LicenseException, System.ComponentModel.TypeConverter", false);
}

} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::LicenseInteropProxyNamespace
