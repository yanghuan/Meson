#include "ThreadPool-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/_ThreadPoolWaitOrTimerCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallbackBase-dep.h>
#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallbackDefaultContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolWorkQueue-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolWorkQueueThreadLocals-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadPoolNamespace {
using namespace System::Threading::Tasks;

Int64 ThreadPool::get_CompletedWorkItemCount() {
  return GetCompletedWorkItemCount();
}

Int64 ThreadPool::get_PendingWorkItemCount() {
  ThreadPoolWorkQueue threadPoolWorkQueue = s_workQueue;
  return threadPoolWorkQueue->get_LocalCount() + threadPoolWorkQueue->get_GlobalCount() + get_PendingUnmanagedWorkItemCount();
}

Boolean ThreadPool::KeepDispatching(Int32 startTickCount) {
  return (UInt32)(Environment::get_TickCount() - startTickCount) < 30u;
}

Boolean ThreadPool::SetMaxThreads(Int32 workerThreads, Int32 completionPortThreads) {
  if (workerThreads >= 0 && completionPortThreads >= 0) {
    return SetMaxThreadsNative(workerThreads, completionPortThreads);
  }
  return false;
}

void ThreadPool::GetMaxThreads(Int32& workerThreads, Int32& completionPortThreads) {
  GetMaxThreadsNative(workerThreads, completionPortThreads);
}

Boolean ThreadPool::SetMinThreads(Int32 workerThreads, Int32 completionPortThreads) {
  if (workerThreads >= 0 && completionPortThreads >= 0) {
    return SetMinThreadsNative(workerThreads, completionPortThreads);
  }
  return false;
}

void ThreadPool::GetMinThreads(Int32& workerThreads, Int32& completionPortThreads) {
  GetMinThreadsNative(workerThreads, completionPortThreads);
}

void ThreadPool::GetAvailableThreads(Int32& workerThreads, Int32& completionPortThreads) {
  GetAvailableThreadsNative(workerThreads, completionPortThreads);
}

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, UInt32 millisecondsTimeOutInterval, Boolean executeOnlyOnce, Boolean compressStack) {
  RegisteredWaitHandle registeredWaitHandle = rt::newobj<RegisteredWaitHandle>();
  if (callBack != nullptr) {
    _ThreadPoolWaitOrTimerCallback threadPoolWaitOrTimerCallback = rt::newobj<_ThreadPoolWaitOrTimerCallback>(callBack, state, compressStack);
    state = threadPoolWaitOrTimerCallback;
    registeredWaitHandle->SetWaitObject(waitObject);
    IntPtr handle = RegisterWaitForSingleObjectNative(waitObject, state, millisecondsTimeOutInterval, executeOnlyOnce, registeredWaitHandle);
    registeredWaitHandle->SetHandle(handle);
    return registeredWaitHandle;
  }
  rt::throw_exception<ArgumentNullException>("WaitOrTimerCallback");
}

Boolean ThreadPool::UnsafeQueueNativeOverlapped(NativeOverlapped* overlapped) {
  return PostQueuedCompletionStatus(overlapped);
}

void ThreadPool::NotifyWorkItemProgress() {
  NotifyWorkItemProgressNative();
}

Boolean ThreadPool::BindHandle(IntPtr osHandle) {
  return BindIOCompletionCallbackNative(osHandle);
}

Boolean ThreadPool::BindHandle(SafeHandle osHandle) {
  if (osHandle == nullptr) {
    rt::throw_exception<ArgumentNullException>("osHandle");
  }
  Boolean flag = false;
  Boolean success = false;
  try {
    osHandle->DangerousAddRef(success);
    return BindIOCompletionCallbackNative(osHandle->DangerousGetHandle());
  } catch (...) {
  } finally: {
    if (success) {
      osHandle->DangerousRelease();
    }
  }
}

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, UInt32 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  if (millisecondsTimeOutInterval > Int32::MaxValue && millisecondsTimeOutInterval != UInt32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeOutInterval", SR::get_ArgumentOutOfRange_LessEqualToIntegerMaxVal());
  }
  return RegisterWaitForSingleObject(waitObject, callBack, state, millisecondsTimeOutInterval, executeOnlyOnce, true);
}

RegisteredWaitHandle ThreadPool::UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, UInt32 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  if (millisecondsTimeOutInterval > Int32::MaxValue && millisecondsTimeOutInterval != UInt32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeOutInterval", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  return RegisterWaitForSingleObject(waitObject, callBack, state, millisecondsTimeOutInterval, executeOnlyOnce, false);
}

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int32 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  if (millisecondsTimeOutInterval < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeOutInterval", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  return RegisterWaitForSingleObject(waitObject, callBack, state, (UInt32)millisecondsTimeOutInterval, executeOnlyOnce, true);
}

RegisteredWaitHandle ThreadPool::UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int32 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  if (millisecondsTimeOutInterval < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeOutInterval", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  return RegisterWaitForSingleObject(waitObject, callBack, state, (UInt32)millisecondsTimeOutInterval, executeOnlyOnce, false);
}

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int64 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  if (millisecondsTimeOutInterval < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeOutInterval", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (millisecondsTimeOutInterval > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeOutInterval", SR::get_ArgumentOutOfRange_LessEqualToIntegerMaxVal());
  }
  return RegisterWaitForSingleObject(waitObject, callBack, state, (UInt32)millisecondsTimeOutInterval, executeOnlyOnce, true);
}

RegisteredWaitHandle ThreadPool::UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int64 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  if (millisecondsTimeOutInterval < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeOutInterval", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (millisecondsTimeOutInterval > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeOutInterval", SR::get_ArgumentOutOfRange_LessEqualToIntegerMaxVal());
  }
  return RegisterWaitForSingleObject(waitObject, callBack, state, (UInt32)millisecondsTimeOutInterval, executeOnlyOnce, false);
}

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, TimeSpan timeout, Boolean executeOnlyOnce) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", SR::get_ArgumentOutOfRange_LessEqualToIntegerMaxVal());
  }
  return RegisterWaitForSingleObject(waitObject, callBack, state, (UInt32)num, executeOnlyOnce, true);
}

RegisteredWaitHandle ThreadPool::UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, TimeSpan timeout, Boolean executeOnlyOnce) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  if (num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", SR::get_ArgumentOutOfRange_LessEqualToIntegerMaxVal());
  }
  return RegisterWaitForSingleObject(waitObject, callBack, state, (UInt32)num, executeOnlyOnce, false);
}

Boolean ThreadPool::QueueUserWorkItem(WaitCallback callBack) {
  return QueueUserWorkItem(callBack, nullptr);
}

Boolean ThreadPool::QueueUserWorkItem(WaitCallback callBack, Object state) {
  if (callBack == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::callBack);
  }
  ExecutionContext executionContext = ExecutionContext::in::Capture();
  Object callback = (executionContext == nullptr || executionContext->get_IsDefault()) ? ((QueueUserWorkItemCallbackBase)rt::newobj<QueueUserWorkItemCallbackDefaultContext<>>(callBack, state)) : ((QueueUserWorkItemCallbackBase)rt::newobj<QueueUserWorkItemCallback<>>(callBack, state, executionContext));
  s_workQueue->Enqueue(callback, true);
  return true;
}

Boolean ThreadPool::UnsafeQueueUserWorkItem(WaitCallback callBack, Object state) {
  if (callBack == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::callBack);
  }
  Object callback = rt::newobj<QueueUserWorkItemCallbackDefaultContext<>>(callBack, state);
  s_workQueue->Enqueue(callback, true);
  return true;
}

Boolean ThreadPool::UnsafeQueueUserWorkItem(IThreadPoolWorkItem callBack, Boolean preferLocal) {
  if (callBack == nullptr) {
    ThrowHelper::ThrowArgumentNullException(ExceptionArgument::callBack);
  }
  if (rt::is<Task<>>(callBack)) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::callBack);
  }
  UnsafeQueueUserWorkItemInternal(callBack, preferLocal);
  return true;
}

void ThreadPool::UnsafeQueueUserWorkItemInternal(Object callBack, Boolean preferLocal) {
  s_workQueue->Enqueue(callBack, !preferLocal);
}

Boolean ThreadPool::TryPopCustomWorkItem(Object workItem) {
  return s_workQueue->LocalFindAndPop(workItem);
}

IEnumerable<Object> ThreadPool::GetQueuedWorkItems() {
}

IEnumerable<Object> ThreadPool::GetLocallyQueuedWorkItems() {
  auto& as = ThreadPoolWorkQueueThreadLocals::in::threadLocals;
  ThreadPoolWorkQueue::in::WorkStealingQueue workStealingQueue = as == nullptr ? nullptr : as->workStealingQueue;
  if (workStealingQueue == nullptr || workStealingQueue->m_array == nullptr) {
  }
  Array<Object> items = workStealingQueue->m_array;
}

IEnumerable<Object> ThreadPool::GetGloballyQueuedWorkItems() {
  return s_workQueue->workItems;
}

Array<Object> ThreadPool::ToObjectArray(IEnumerable<Object> workitems) {
  Int32 num = 0;
}

Array<Object> ThreadPool::GetQueuedWorkItemsForDebugger() {
  return ToObjectArray(GetQueuedWorkItems());
}

Array<Object> ThreadPool::GetGloballyQueuedWorkItemsForDebugger() {
  return ToObjectArray(GetGloballyQueuedWorkItems());
}

Array<Object> ThreadPool::GetLocallyQueuedWorkItemsForDebugger() {
  return ToObjectArray(GetLocallyQueuedWorkItems());
}

void ThreadPool::cctor() {
  EnableWorkerTracking = GetEnableWorkerTracking();
  s_workQueue = rt::newobj<ThreadPoolWorkQueue>();
}

} // namespace System::Private::CoreLib::System::Threading::ThreadPoolNamespace
