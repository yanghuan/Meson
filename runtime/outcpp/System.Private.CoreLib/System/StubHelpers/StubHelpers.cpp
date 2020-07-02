#include "StubHelpers-dep.h"

namespace System::Private::CoreLib::System::StubHelpers::StubHelpersNamespace {
IntPtr StubHelpers::AddToCleanupList(CleanupWorkListElement& pCleanupWorkList, SafeHandle handle) {
  return IntPtr();
};
void StubHelpers::AddToCleanupList(CleanupWorkListElement& pCleanupWorkList, Delegate del) {
  return void();
};
void StubHelpers::DestroyCleanupList(CleanupWorkListElement& pCleanupWorkList) {
  return void();
};
Exception StubHelpers::GetHRExceptionObject(Int32 hr) {
  return nullptr;
};
Exception StubHelpers::GetCOMHRExceptionObject(Int32 hr, IntPtr pCPCMD, Object pThis) {
  return nullptr;
};
Exception StubHelpers::GetCOMHRExceptionObject_WinRT(Int32 hr, IntPtr pCPCMD, Object pThis) {
  return nullptr;
};
IntPtr StubHelpers::SafeHandleAddRef(SafeHandle pHandle, Boolean& success) {
  return IntPtr();
};
void StubHelpers::SafeHandleRelease(SafeHandle pHandle) {
  return void();
};
void StubHelpers::CheckStringLength(Int32 length) {
  return void();
};
void StubHelpers::CheckStringLength(UInt32 length) {
  return void();
};
} // namespace System::Private::CoreLib::System::StubHelpers::StubHelpersNamespace
