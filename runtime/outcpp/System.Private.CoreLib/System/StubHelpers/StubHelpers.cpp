#include "StubHelpers-dep.h"

#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/ExceptionResource.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/MarshalDirectiveException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StubHelpers/KeepAliveCleanupWorkListElement-dep.h>
#include <System.Private.CoreLib/System/StubHelpers/SafeHandleCleanupWorkListElement-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::StubHelpersNamespace {
using namespace System::Runtime::InteropServices;

IntPtr StubHelpers::AddToCleanupList(CleanupWorkListElement& pCleanupWorkList, SafeHandle handle) {
  SafeHandleCleanupWorkListElement safeHandleCleanupWorkListElement = rt::newobj<SafeHandleCleanupWorkListElement>(handle);
  CleanupWorkListElement::in::AddToCleanupList(pCleanupWorkList, safeHandleCleanupWorkListElement);
  return safeHandleCleanupWorkListElement->AddRef();
}

void StubHelpers::KeepAliveViaCleanupList(CleanupWorkListElement& pCleanupWorkList, Object obj) {
  KeepAliveCleanupWorkListElement newElement = rt::newobj<KeepAliveCleanupWorkListElement>(obj);
  CleanupWorkListElement::in::AddToCleanupList(pCleanupWorkList, newElement);
}

void StubHelpers::DestroyCleanupList(CleanupWorkListElement& pCleanupWorkList) {
  if (pCleanupWorkList != nullptr) {
    pCleanupWorkList->Destroy();
    pCleanupWorkList = nullptr;
  }
}

Exception StubHelpers::GetHRExceptionObject(Int32 hr) {
  Exception ex = InternalGetHRExceptionObject(hr);
  ex->InternalPreserveStackTrace();
  return ex;
}

Exception StubHelpers::GetCOMHRExceptionObject(Int32 hr, IntPtr pCPCMD, Object pThis) {
  Exception ex = InternalGetCOMHRExceptionObject(hr, pCPCMD, pThis);
  ex->InternalPreserveStackTrace();
  return ex;
}

IntPtr StubHelpers::SafeHandleAddRef(SafeHandle pHandle, Boolean& success) {
  if (pHandle == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::pHandle, ExceptionResource::ArgumentNull_SafeHandle);
  }
  pHandle->DangerousAddRef(success);
  return pHandle->DangerousGetHandle();
}

void StubHelpers::SafeHandleRelease(SafeHandle pHandle) {
  if (pHandle == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::pHandle, ExceptionResource::ArgumentNull_SafeHandle);
  }
  pHandle->DangerousRelease();
}

void StubHelpers::CheckStringLength(Int32 length) {
  CheckStringLength((UInt32)length);
}

void StubHelpers::CheckStringLength(UInt32 length) {
  if (length > 2147483632) {
    rt::throw_exception<MarshalDirectiveException>(SR::get_Marshaler_StringTooLong());
  }
}

} // namespace System::Private::CoreLib::System::StubHelpers::StubHelpersNamespace
