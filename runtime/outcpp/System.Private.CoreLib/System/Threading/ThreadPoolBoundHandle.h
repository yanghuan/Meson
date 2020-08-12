#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Threading {
FORWARD(IOCompletionCallback)
FORWARDS(NativeOverlapped)
FORWARD(PreAllocatedOverlapped)
FORWARD(ThreadPoolBoundHandleOverlapped)
namespace ThreadPoolBoundHandleNamespace {
using namespace System::Runtime::InteropServices;
CLASS(ThreadPoolBoundHandle) : public Object::in {
  public: using interface = rt::TypeList<IDisposable>;
  public: SafeHandle get_Handle();
  private: void ctor(SafeHandle handle);
  public: static ThreadPoolBoundHandle BindHandle(SafeHandle handle);
  public: NativeOverlapped* AllocateNativeOverlapped(IOCompletionCallback callback, Object state, Object pinData);
  public: NativeOverlapped* AllocateNativeOverlapped(PreAllocatedOverlapped preAllocated);
  public: void FreeNativeOverlapped(NativeOverlapped* overlapped);
  public: static Object GetNativeOverlappedState(NativeOverlapped* overlapped);
  private: static ThreadPoolBoundHandleOverlapped GetOverlappedWrapper(NativeOverlapped* overlapped);
  public: void Dispose();
  private: void EnsureNotDisposed();
  private: static ThreadPoolBoundHandle BindHandleCore(SafeHandle handle);
  private: SafeHandle _handle;
  private: Boolean _isDisposed;
};
} // namespace ThreadPoolBoundHandleNamespace
using ThreadPoolBoundHandle = ThreadPoolBoundHandleNamespace::ThreadPoolBoundHandle;
} // namespace System::Private::CoreLib::System::Threading
