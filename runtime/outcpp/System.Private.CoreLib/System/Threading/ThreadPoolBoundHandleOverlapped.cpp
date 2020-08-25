#include "ThreadPoolBoundHandleOverlapped-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolBoundHandleOverlapped-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadPoolBoundHandleOverlappedNamespace {
void ThreadPoolBoundHandleOverlapped___::ctor(IOCompletionCallback callback, Object state, Object pinData, PreAllocatedOverlapped preAllocated) {
  _userCallback = callback;
  _userState = state;
  _preAllocated = preAllocated;
  _nativeOverlapped = Pack(s_completionCallback, pinData);
  _nativeOverlapped->OffsetLow = 0;
  _nativeOverlapped->OffsetHigh = 0;
}

void ThreadPoolBoundHandleOverlapped___::CompletionCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* nativeOverlapped) {
  ThreadPoolBoundHandleOverlapped threadPoolBoundHandleOverlapped = (ThreadPoolBoundHandleOverlapped)Overlapped::in::Unpack(nativeOverlapped);
  if (threadPoolBoundHandleOverlapped->_completed) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NativeOverlappedReused());
  }
  threadPoolBoundHandleOverlapped->_completed = true;
  if (threadPoolBoundHandleOverlapped->_boundHandle == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_Argument_NativeOverlappedAlreadyFree());
  }
  threadPoolBoundHandleOverlapped->_userCallback(errorCode, numBytes, nativeOverlapped);
}

void ThreadPoolBoundHandleOverlapped___::cctor() {
  s_completionCallback = &CompletionCallback;
}

} // namespace System::Private::CoreLib::System::Threading::ThreadPoolBoundHandleOverlappedNamespace
