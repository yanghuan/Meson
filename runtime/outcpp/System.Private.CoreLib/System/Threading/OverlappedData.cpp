#include "OverlappedData-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/_IOCompletionCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>

namespace System::Private::CoreLib::System::Threading::OverlappedDataNamespace {
Int32& OverlappedData___::get_OffsetLow() {
  if (_pNativeOverlapped == nullptr) {
    return _offsetLow;
  }
  return _pNativeOverlapped->OffsetLow;
}

Int32& OverlappedData___::get_OffsetHigh() {
  if (_pNativeOverlapped == nullptr) {
    return _offsetHigh;
  }
  return _pNativeOverlapped->OffsetHigh;
}

IntPtr& OverlappedData___::get_EventHandle() {
  if (_pNativeOverlapped == nullptr) {
    return _eventHandle;
  }
  return _pNativeOverlapped->EventHandle;
}

void OverlappedData___::ctor(Overlapped overlapped) {
  _overlapped = overlapped;
}

NativeOverlapped* OverlappedData___::Pack(IOCompletionCallback iocb, Object userData) {
  if (_pNativeOverlapped != nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_Overlapped_Pack());
  }
  if (iocb != nullptr) {
    ExecutionContext executionContext = ExecutionContext::in::Capture();
    _callback = ((executionContext != nullptr && !executionContext->get_IsDefault()) ? ((Object)rt::newobj<_IOCompletionCallback>(iocb, executionContext)) : ((Object)iocb));
  } else {
    _callback = nullptr;
  }
  _userObject = userData;
  return AllocateNativeOverlapped();
}

NativeOverlapped* OverlappedData___::UnsafePack(IOCompletionCallback iocb, Object userData) {
  if (_pNativeOverlapped != nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_Overlapped_Pack());
  }
  _userObject = userData;
  _callback = iocb;
  return AllocateNativeOverlapped();
}

} // namespace System::Private::CoreLib::System::Threading::OverlappedDataNamespace
