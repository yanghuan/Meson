#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(IOCompletionCallback)
FORWARDS(NativeOverlapped)
FORWARD(PreAllocatedOverlapped)
FORWARD(ThreadPoolBoundHandleOverlapped)
namespace ThreadPoolBoundHandleNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::InteropServices;
CLASS(ThreadPoolBoundHandle) {
  public: SafeHandle get_Handle();
  public: static ThreadPoolBoundHandle BindHandle(SafeHandle handle);
  public: NativeOverlapped* AllocateNativeOverlapped(IOCompletionCallback callback, Object state, Object pinData);
  public: NativeOverlapped* AllocateNativeOverlapped(PreAllocatedOverlapped preAllocated);
  public: void FreeNativeOverlapped(NativeOverlapped* overlapped);
  public: static Object GetNativeOverlappedState(NativeOverlapped* overlapped);
  private: static ThreadPoolBoundHandleOverlapped GetOverlappedWrapper(NativeOverlapped* overlapped, ThreadPoolBoundHandle expectedBoundHandle);
  public: void Dispose();
  private: void EnsureNotDisposed();
  private: static ThreadPoolBoundHandle BindHandleCore(SafeHandle handle);
  private: SafeHandle _handle;
  private: Boolean _isDisposed;
};
} // namespace ThreadPoolBoundHandleNamespace
using ThreadPoolBoundHandle = ThreadPoolBoundHandleNamespace::ThreadPoolBoundHandle;
} // namespace System::Private::CoreLib::System::Threading
