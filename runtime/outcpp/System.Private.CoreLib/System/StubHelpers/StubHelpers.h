#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
FORWARDS(Boolean)
FORWARD(Delegate)
FORWARDS(Int32)
FORWARD(Exception)
FORWARD(Object)
FORWARDS(UInt32)
FORWARDS(Byte)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::StubHelpers {
FORWARD(CleanupWorkListElement)
namespace StubHelpersNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
class StubHelpers {
  public: static Boolean IsQCall(IntPtr pMD);
  public: static void InitDeclaringType(IntPtr pMD);
  public: static IntPtr GetNDirectTarget(IntPtr pMD);
  public: static IntPtr GetDelegateTarget(Delegate pThis, IntPtr& pStubArg);
  public: static void ClearLastError();
  public: static void SetLastError();
  public: static void ThrowInteropParamException(Int32 resID, Int32 paramIdx);
  public: static IntPtr AddToCleanupList(CleanupWorkListElement& pCleanupWorkList, SafeHandle handle);
  public: static void AddToCleanupList(CleanupWorkListElement& pCleanupWorkList, Delegate del);
  public: static void DestroyCleanupList(CleanupWorkListElement& pCleanupWorkList);
  public: static Exception GetHRExceptionObject(Int32 hr);
  public: static Exception InternalGetHRExceptionObject(Int32 hr);
  public: static Exception GetCOMHRExceptionObject(Int32 hr, IntPtr pCPCMD, Object pThis);
  public: static Exception GetCOMHRExceptionObject_WinRT(Int32 hr, IntPtr pCPCMD, Object pThis);
  public: static Exception InternalGetCOMHRExceptionObject(Int32 hr, IntPtr pCPCMD, Object pThis, Boolean fForWinRT);
  public: static IntPtr CreateCustomMarshalerHelper(IntPtr pMD, Int32 paramToken, IntPtr hndManagedType);
  public: static IntPtr SafeHandleAddRef(SafeHandle pHandle, Boolean& success);
  public: static void SafeHandleRelease(SafeHandle pHandle);
  public: static IntPtr GetCOMIPFromRCW(Object objSrc, IntPtr pCPCMD, IntPtr& ppTarget, Boolean& pfNeedsRelease);
  public: static IntPtr GetCOMIPFromRCW_WinRT(Object objSrc, IntPtr pCPCMD, IntPtr& ppTarget);
  public: static IntPtr GetCOMIPFromRCW_WinRTSharedGeneric(Object objSrc, IntPtr pCPCMD, IntPtr& ppTarget);
  public: static IntPtr GetCOMIPFromRCW_WinRTDelegate(Object objSrc, IntPtr pCPCMD, IntPtr& ppTarget);
  public: static Boolean ShouldCallWinRTInterface(Object objSrc, IntPtr pCPCMD);
  public: static Delegate GetTargetForAmbiguousVariantCall(Object objSrc, IntPtr pMT, Boolean& fUseString);
  public: static IntPtr GetDelegateInvokeMethod(Delegate pThis);
  public: static Object GetWinRTFactoryObject(IntPtr pCPCMD);
  public: static IntPtr GetWinRTFactoryReturnValue(Object pThis, IntPtr pCtorEntry);
  public: static IntPtr GetOuterInspectable(Object pThis, IntPtr pCtorMD);
  public: static IntPtr ProfilerBeginTransitionCallback(IntPtr pSecretParam, IntPtr pThread, Object pThis);
  public: static void ProfilerEndTransitionCallback(IntPtr pMD, IntPtr pThread);
  public: static void CheckStringLength(Int32 length);
  public: static void CheckStringLength(UInt32 length);
  public: static void FmtClassUpdateNativeInternal(Object obj, Byte* pNative, CleanupWorkListElement& pCleanupWorkList);
  public: static void FmtClassUpdateCLRInternal(Object obj, Byte* pNative);
  public: static void LayoutDestroyNativeInternal(Byte* pNative, IntPtr pMT);
  public: static Object AllocateInternal(IntPtr typeHandle);
  public: static void MarshalToUnmanagedVaListInternal(IntPtr va_list, UInt32 vaListSize, IntPtr pArgIterator);
  public: static void MarshalToManagedVaListInternal(IntPtr va_list, IntPtr pArgIterator);
  public: static UInt32 CalcVaListSize(IntPtr va_list);
  public: static void ValidateObject(Object obj, IntPtr pMD, Object pThis);
  public: static void LogPinnedArgument(IntPtr localDesc, IntPtr nativeArg);
  public: static void ValidateByref(IntPtr byref, IntPtr pMD, Object pThis);
  public: static IntPtr GetStubContext();
  public: static IntPtr GetStubContextAddr();
  public: static void ArrayTypeCheck(Object o, Array<Object> arr);
  public: static void MulticastDebuggerTraceHelper(Object o, Int32 count);
};
} // namespace StubHelpersNamespace
using StubHelpers = StubHelpersNamespace::StubHelpers;
} // namespace System::Private::CoreLib::System::StubHelpers
