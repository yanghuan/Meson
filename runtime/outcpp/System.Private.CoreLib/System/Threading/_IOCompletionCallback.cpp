#include "_IOCompletionCallback-dep.h"

#include <System.Private.CoreLib/System/Threading/_IOCompletionCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/OverlappedData-dep.h>

namespace System::Private::CoreLib::System::Threading::_IOCompletionCallbackNamespace {
void _IOCompletionCallback___::ctor(IOCompletionCallback ioCompletionCallback, ExecutionContext executionContext) {
  _ioCompletionCallback = ioCompletionCallback;
  _executionContext = executionContext;
}

void _IOCompletionCallback___::IOCompletionCallback_Context(Object state) {
  _IOCompletionCallback iOCompletionCallback = (_IOCompletionCallback)state;
  iOCompletionCallback->_ioCompletionCallback(iOCompletionCallback->_errorCode, iOCompletionCallback->_numBytes, iOCompletionCallback->_pNativeOverlapped);
}

void _IOCompletionCallback___::PerformIOCompletionCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* pNativeOverlapped) {
  do {
    OverlappedData overlappedFromNative = OverlappedData::in::GetOverlappedFromNative(pNativeOverlapped);
    IOCompletionCallback iOCompletionCallback = rt::as<IOCompletionCallback>(overlappedFromNative->_callback);
    if (iOCompletionCallback != nullptr) {
      iOCompletionCallback(errorCode, numBytes, pNativeOverlapped);
    } else {
      _IOCompletionCallback iOCompletionCallback2 = (_IOCompletionCallback)overlappedFromNative->_callback;
      iOCompletionCallback2->_errorCode = errorCode;
      iOCompletionCallback2->_numBytes = numBytes;
      iOCompletionCallback2->_pNativeOverlapped = pNativeOverlapped;
      ExecutionContext::in::RunInternal(iOCompletionCallback2->_executionContext, _ccb, iOCompletionCallback2);
    }
    OverlappedData::in::CheckVMForIOPacket(pNativeOverlapped, errorCode, numBytes);
  } while (pNativeOverlapped != nullptr);
}

void _IOCompletionCallback___::cctor() {
  _ccb = &IOCompletionCallback_Context;
}

} // namespace System::Private::CoreLib::System::Threading::_IOCompletionCallbackNamespace
