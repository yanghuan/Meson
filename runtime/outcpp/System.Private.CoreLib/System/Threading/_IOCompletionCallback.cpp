#include "_IOCompletionCallback-dep.h"

#include <System.Private.CoreLib/System/Threading/_IOCompletionCallback-dep.h>

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
}

void _IOCompletionCallback___::cctor() {
  _ccb = IOCompletionCallback_Context;
}

} // namespace System::Private::CoreLib::System::Threading::_IOCompletionCallbackNamespace
