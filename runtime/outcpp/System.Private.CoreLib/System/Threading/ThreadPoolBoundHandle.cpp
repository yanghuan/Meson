#include "ThreadPoolBoundHandle-dep.h"

#include <System.Private.CoreLib/System/Threading/ThreadPoolBoundHandle-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadPoolBoundHandleNamespace {
SafeHandle ThreadPoolBoundHandle___::get_Handle() {
  return nullptr;
}

void ThreadPoolBoundHandle___::Ctor(SafeHandle handle) {
}

ThreadPoolBoundHandle ThreadPoolBoundHandle___::BindHandle(SafeHandle handle) {
  return nullptr;
}

NativeOverlapped* ThreadPoolBoundHandle___::AllocateNativeOverlapped(IOCompletionCallback callback, Object state, Object pinData) {
  return nullptr;
}

NativeOverlapped* ThreadPoolBoundHandle___::AllocateNativeOverlapped(PreAllocatedOverlapped preAllocated) {
  return nullptr;
}

void ThreadPoolBoundHandle___::FreeNativeOverlapped(NativeOverlapped* overlapped) {
}

Object ThreadPoolBoundHandle___::GetNativeOverlappedState(NativeOverlapped* overlapped) {
  return nullptr;
}

ThreadPoolBoundHandleOverlapped ThreadPoolBoundHandle___::GetOverlappedWrapper(NativeOverlapped* overlapped) {
  return nullptr;
}

void ThreadPoolBoundHandle___::Dispose() {
}

void ThreadPoolBoundHandle___::EnsureNotDisposed() {
}

ThreadPoolBoundHandle ThreadPoolBoundHandle___::BindHandleCore(SafeHandle handle) {
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Threading::ThreadPoolBoundHandleNamespace
