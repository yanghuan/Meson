#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(IOCompletionCallback)
FORWARDS(NativeOverlapped)
FORWARD(PreAllocatedOverlapped)
FORWARD(ThreadPoolBoundHandle)
namespace ThreadPoolBoundHandleOverlappedNamespace {
CLASS(ThreadPoolBoundHandleOverlapped) {
  private: static void CompletionCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* nativeOverlapped);
  private: static IOCompletionCallback s_completionCallback;
  private: IOCompletionCallback _userCallback;
  public: Object _userState;
  public: PreAllocatedOverlapped _preAllocated;
  public: NativeOverlapped* _nativeOverlapped;
  public: ThreadPoolBoundHandle _boundHandle;
  public: Boolean _completed;
};
} // namespace ThreadPoolBoundHandleOverlappedNamespace
using ThreadPoolBoundHandleOverlapped = ThreadPoolBoundHandleOverlappedNamespace::ThreadPoolBoundHandleOverlapped;
} // namespace System::Private::CoreLib::System::Threading
