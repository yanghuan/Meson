#include "ThreadPoolBoundHandle-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/NullReferenceException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/Overlapped-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolBoundHandle-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolBoundHandleOverlapped-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadPoolBoundHandleNamespace {
SafeHandle ThreadPoolBoundHandle___::get_Handle() {
  return _handle;
}

void ThreadPoolBoundHandle___::ctor(SafeHandle handle) {
  _handle = handle;
}

ThreadPoolBoundHandle ThreadPoolBoundHandle___::BindHandle(SafeHandle handle) {
  if (handle == nullptr) {
    rt::throw_exception<ArgumentNullException>("handle");
  }
  if (handle->get_IsClosed() || handle->get_IsInvalid()) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidHandle(), "handle");
  }
  return BindHandleCore(handle);
}

NativeOverlapped* ThreadPoolBoundHandle___::AllocateNativeOverlapped(IOCompletionCallback callback, Object state, Object pinData) {
  if (callback == nullptr) {
    rt::throw_exception<ArgumentNullException>("callback");
  }
  EnsureNotDisposed();
  ThreadPoolBoundHandleOverlapped threadPoolBoundHandleOverlapped = rt::newobj<ThreadPoolBoundHandleOverlapped>(callback, state, pinData, nullptr);
  threadPoolBoundHandleOverlapped->_boundHandle = (ThreadPoolBoundHandle)this;
  return threadPoolBoundHandleOverlapped->_nativeOverlapped;
}

NativeOverlapped* ThreadPoolBoundHandle___::AllocateNativeOverlapped(PreAllocatedOverlapped preAllocated) {
  if (preAllocated == nullptr) {
    rt::throw_exception<ArgumentNullException>("preAllocated");
  }
  EnsureNotDisposed();
  preAllocated->AddRef();
  try {
    ThreadPoolBoundHandleOverlapped overlapped = preAllocated->_overlapped;
    if (overlapped->_boundHandle != nullptr) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_PreAllocatedAlreadyAllocated(), "preAllocated");
    }
    overlapped->_boundHandle = (ThreadPoolBoundHandle)this;
    return overlapped->_nativeOverlapped;
  } catch (...) {
    preAllocated->Release();
    throw;
  }
}

void ThreadPoolBoundHandle___::FreeNativeOverlapped(NativeOverlapped* overlapped) {
  if (overlapped == nullptr) {
    rt::throw_exception<ArgumentNullException>("overlapped");
  }
  ThreadPoolBoundHandleOverlapped overlappedWrapper = GetOverlappedWrapper(overlapped);
  if (overlappedWrapper->_boundHandle != (ThreadPoolBoundHandle)this) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NativeOverlappedWrongBoundHandle(), "overlapped");
  }
  if (overlappedWrapper->_preAllocated != nullptr) {
    overlappedWrapper->_preAllocated->Release();
  } else {
    Overlapped::in::Free(overlapped);
  }
}

Object ThreadPoolBoundHandle___::GetNativeOverlappedState(NativeOverlapped* overlapped) {
  if (overlapped == nullptr) {
    rt::throw_exception<ArgumentNullException>("overlapped");
  }
  ThreadPoolBoundHandleOverlapped overlappedWrapper = GetOverlappedWrapper(overlapped);
  return overlappedWrapper->_userState;
}

ThreadPoolBoundHandleOverlapped ThreadPoolBoundHandle___::GetOverlappedWrapper(NativeOverlapped* overlapped) {
  try {
    return (ThreadPoolBoundHandleOverlapped)Overlapped::in::Unpack(overlapped);
  } catch (NullReferenceException innerException) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_NativeOverlappedAlreadyFree(), "overlapped", innerException);
  }
}

void ThreadPoolBoundHandle___::Dispose() {
  _isDisposed = true;
}

void ThreadPoolBoundHandle___::EnsureNotDisposed() {
  if (_isDisposed) {
    rt::throw_exception<ObjectDisposedException>(GetType()->ToString());
  }
}

ThreadPoolBoundHandle ThreadPoolBoundHandle___::BindHandleCore(SafeHandle handle) {
  try {
    Boolean flag = ThreadPool::BindHandle(handle);
  } catch (Exception ex) {
    if (ex->get_HResult() == -2147024890) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_InvalidHandle(), "handle");
    }
    if (ex->get_HResult() == -2147024809) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_AlreadyBoundOrSyncHandle(), "handle");
    }
    throw;
  }
  return rt::newobj<ThreadPoolBoundHandle>(handle);
}

} // namespace System::Private::CoreLib::System::Threading::ThreadPoolBoundHandleNamespace
