#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Threading/Overlapped.h>

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
CLASS(ThreadPoolBoundHandleOverlapped) : public Overlapped::in {
  public: void ctor(IOCompletionCallback callback, Object state, Object pinData, PreAllocatedOverlapped preAllocated);
  private: static void CompletionCallback(UInt32 errorCode, UInt32 numBytes, NativeOverlapped* nativeOverlapped);
  private: static void ctor_static();
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
