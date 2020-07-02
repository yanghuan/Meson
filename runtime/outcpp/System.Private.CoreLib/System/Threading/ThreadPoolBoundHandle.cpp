#include "ThreadPoolBoundHandle-dep.h"

#include <System.Private.CoreLib/System/Threading/ThreadPoolBoundHandle-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadPoolBoundHandleNamespace {
SafeHandle ThreadPoolBoundHandle___::get_Handle() {
  return nullptr;
};
ThreadPoolBoundHandle ThreadPoolBoundHandle___::BindHandle(SafeHandle handle) {
  return nullptr;
};
NativeOverlapped* ThreadPoolBoundHandle___::AllocateNativeOverlapped(IOCompletionCallback callback, Object state, Object pinData) {
  return nullptr;
};
NativeOverlapped* ThreadPoolBoundHandle___::AllocateNativeOverlapped(PreAllocatedOverlapped preAllocated) {
  return nullptr;
};
void ThreadPoolBoundHandle___::FreeNativeOverlapped(NativeOverlapped* overlapped) {
  return void();
};
Object ThreadPoolBoundHandle___::GetNativeOverlappedState(NativeOverlapped* overlapped) {
  return nullptr;
};
ThreadPoolBoundHandleOverlapped ThreadPoolBoundHandle___::GetOverlappedWrapper(NativeOverlapped* overlapped, ThreadPoolBoundHandle expectedBoundHandle) {
  return nullptr;
};
void ThreadPoolBoundHandle___::Dispose() {
  return void();
};
void ThreadPoolBoundHandle___::EnsureNotDisposed() {
  return void();
};
ThreadPoolBoundHandle ThreadPoolBoundHandle___::BindHandleCore(SafeHandle handle) {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Threading::ThreadPoolBoundHandleNamespace
