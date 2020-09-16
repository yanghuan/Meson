#include "ThreadPool-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/ExceptionArgument.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/IAsyncStateMachineBox.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/_ThreadPoolWaitOrTimerCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallbackBase-dep.h>
#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallbackDefaultContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolWorkQueue-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolWorkQueueThreadLocals-dep.h>
#include <System.Private.CoreLib/System/ThrowHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadPoolNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Threading::Tasks;

Object ThreadPool::_GetQueuedWorkItems_d__51___::get_CurrentOfObject() {
  return __2__current;
}

Object ThreadPool::_GetQueuedWorkItems_d__51___::get_CurrentOfIEnumerator() {
  return __2__current;
}

void ThreadPool::_GetQueuedWorkItems_d__51___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
  __l__initialThreadId = Environment::get_CurrentManagedThreadId();
}

void ThreadPool::_GetQueuedWorkItems_d__51___::DisposeOfIDisposable() {
  Int32 num = __1__state;
  if (num == -3 || num == 1) {
    try {
    } catch (...) {
    } finally: {
      __m__Finally1();
    }
  }
}

Boolean ThreadPool::_GetQueuedWorkItems_d__51___::MoveNext() {
  try {
    switch (__1__state.get()) {
      default:
        return false;
      case 0:
        __1__state = -1;
        __7__wrap1 = s_workQueue->workItems->GetEnumerator();
        __1__state = -3;
        goto IL_006f;
      case 1:
        __1__state = -3;
        goto IL_006f;
      case 2:
        {
          __1__state = -1;
          goto IL_00ff;
        }
      IL_006f:
        if (__7__wrap1->MoveNext()) {
          Object obj = __2__current = __7__wrap1->get_Current();
          __1__state = 1;
          return true;
        }
        __m__Finally1();
        __7__wrap1 = nullptr;
        __7__wrap2 = ThreadPoolWorkQueue::in::WorkStealingQueueList::get_Queues();
        __7__wrap3 = 0;
        goto IL_0136;

      IL_00ff:
        _i_5__6++;
        goto IL_0111;

      IL_0136:
        if (__7__wrap3 < __7__wrap2->get_Length()) {
          ThreadPoolWorkQueue::in::WorkStealingQueue workStealingQueue = __7__wrap2[__7__wrap3];
          if (workStealingQueue != nullptr && workStealingQueue->m_array != nullptr) {
            _items_5__5 = workStealingQueue->m_array;
            _i_5__6 = 0;
            goto IL_0111;
          }
          goto IL_0128;
        }
        __7__wrap2 = nullptr;
        return false;

      IL_0128:
        __7__wrap3++;
        goto IL_0136;

      IL_0111:
        if (_i_5__6 < _items_5__5->get_Length()) {
          Object obj2 = _items_5__5[_i_5__6];
          if (obj2 != nullptr) {
            __2__current = obj2;
            __1__state = 2;
            return true;
          }
          goto IL_00ff;
        }
        _items_5__5 = nullptr;
        goto IL_0128;
    }
  } catch (...) {
    ((IDisposable)(_GetQueuedWorkItems_d__51)this)->Dispose();
    throw;
  }
}

void ThreadPool::_GetQueuedWorkItems_d__51___::__m__Finally1() {
  __1__state = -1;
  if (__7__wrap1 != nullptr) {
    __7__wrap1->Dispose();
  }
}

void ThreadPool::_GetQueuedWorkItems_d__51___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

IEnumerator<Object> ThreadPool::_GetQueuedWorkItems_d__51___::GetEnumeratorOfObject() {
  if (__1__state == -2 && __l__initialThreadId == Environment::get_CurrentManagedThreadId()) {
    __1__state = 0;
    return (_GetQueuedWorkItems_d__51)this;
  }
  return rt::newobj<_GetQueuedWorkItems_d__51>(0);
}

IEnumerator_ ThreadPool::_GetQueuedWorkItems_d__51___::GetEnumeratorOfIEnumerable() {
  return ((IEnumerable<Object>)(_GetQueuedWorkItems_d__51)this)->GetEnumerator();
}

Object ThreadPool::_GetLocallyQueuedWorkItems_d__52___::get_CurrentOfObject() {
  return __2__current;
}

Object ThreadPool::_GetLocallyQueuedWorkItems_d__52___::get_CurrentOfIEnumerator() {
  return __2__current;
}

void ThreadPool::_GetLocallyQueuedWorkItems_d__52___::ctor(Int32 __1__state) {
  this->__1__state = __1__state;
  __l__initialThreadId = Environment::get_CurrentManagedThreadId();
}

void ThreadPool::_GetLocallyQueuedWorkItems_d__52___::DisposeOfIDisposable() {
}

Boolean ThreadPool::_GetLocallyQueuedWorkItems_d__52___::MoveNext() {
  Int32 num = __1__state;
  if (num != 0) {
    if (num != 1) {
      return false;
    }
    __1__state = -1;
    goto IL_0075;
  }
  __1__state = -1;
  ThreadPoolWorkQueueThreadLocals threadLocals = ThreadPoolWorkQueueThreadLocals::in::threadLocals;
  ThreadPoolWorkQueue::in::WorkStealingQueue workStealingQueue = (threadLocals != nullptr) ? threadLocals->workStealingQueue : nullptr;
  if (workStealingQueue != nullptr && workStealingQueue->m_array != nullptr) {
    _items_5__2 = workStealingQueue->m_array;
    _i_5__3 = 0;
    goto IL_0085;
  }
  goto IL_009c;

IL_0075:
  _i_5__3++;
  goto IL_0085;

IL_0085:
  if (_i_5__3 < _items_5__2->get_Length()) {
    Object obj = _items_5__2[_i_5__3];
    if (obj != nullptr) {
      __2__current = obj;
      __1__state = 1;
      return true;
    }
    goto IL_0075;
  }
  _items_5__2 = nullptr;
  goto IL_009c;

IL_009c:
  return false;
}

void ThreadPool::_GetLocallyQueuedWorkItems_d__52___::ResetOfIEnumerator() {
  rt::throw_exception<NotSupportedException>();
}

IEnumerator<Object> ThreadPool::_GetLocallyQueuedWorkItems_d__52___::GetEnumeratorOfObject() {
  if (__1__state == -2 && __l__initialThreadId == Environment::get_CurrentManagedThreadId()) {
    __1__state = 0;
    return (_GetLocallyQueuedWorkItems_d__52)this;
  }
  return rt::newobj<_GetLocallyQueuedWorkItems_d__52>(0);
}

IEnumerator_ ThreadPool::_GetLocallyQueuedWorkItems_d__52___::GetEnumeratorOfIEnumerable() {
  return ((IEnumerable<Object>)(_GetLocallyQueuedWorkItems_d__52)this)->GetEnumerator();
}

void ThreadPool::__c___::cctor() {
  __9 = rt::newobj<__c>();
}

void ThreadPool::__c___::ctor() {
}

void ThreadPool::__c___::_cctor_b__60_0(Object state) {
  IAsyncStateMachineBox asyncStateMachineBox = rt::as<IAsyncStateMachineBox>(state);
  if (asyncStateMachineBox == nullptr) {
    ThrowHelper::ThrowArgumentOutOfRangeException(ExceptionArgument::state);
  } else {
    asyncStateMachineBox->MoveNext();
  }
}

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
  for (Object&& workItem : *s_workQueue->workItems) {
  }
  Array<ThreadPoolWorkQueue::in::WorkStealingQueue> queues = ThreadPoolWorkQueue::in::WorkStealingQueueList::get_Queues();
  for (ThreadPoolWorkQueue::in::WorkStealingQueue&& workStealingQueue : *queues) {
    if (workStealingQueue == nullptr || workStealingQueue->m_array == nullptr) {
      continue;
    }
    Array<Object> items = workStealingQueue->m_array;
    for (Object&& obj : *items) {
      if (obj != nullptr) {
      }
    }
  }
}

IEnumerable<Object> ThreadPool::GetLocallyQueuedWorkItems() {
  ThreadPoolWorkQueueThreadLocals threadLocals = ThreadPoolWorkQueueThreadLocals::in::threadLocals;
  ThreadPoolWorkQueue::in::WorkStealingQueue workStealingQueue = (threadLocals != nullptr) ? threadLocals->workStealingQueue : nullptr;
  if (workStealingQueue == nullptr || workStealingQueue->m_array == nullptr) {
  }
  Array<Object> items = workStealingQueue->m_array;
  for (Object&& obj : *items) {
    if (obj != nullptr) {
    }
  }
}

IEnumerable<Object> ThreadPool::GetGloballyQueuedWorkItems() {
  return s_workQueue->workItems;
}

Array<Object> ThreadPool::ToObjectArray(IEnumerable<Object> workitems) {
  Int32 num = 0;
  for (Object&& workitem : *workitems) {
    num++;
  }
  Array<Object> array = rt::newarr<Array<Object>>(num);
  num = 0;
  for (Object&& workitem2 : *workitems) {
    if (num < array->get_Length()) {
      array[num] = workitem2;
    }
    num++;
  }
  return array;
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
  s_invokeAsyncStateMachineBox = {__c::in::__9, &__c::in::_cctor_b__60_0};
}

} // namespace System::Private::CoreLib::System::Threading::ThreadPoolNamespace
