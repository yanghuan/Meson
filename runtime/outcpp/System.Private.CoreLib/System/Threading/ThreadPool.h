#pragma once

#include <System.Private.CoreLib/Interop.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolWorkQueue.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
FORWARD(IEnumerator)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARDS(Int64)
FORWARDS(IntPtr)
FORWARDS(TimeSpan)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Threading {
FORWARD(IThreadPoolWorkItem)
FORWARDS(NativeOverlapped)
FORWARD(RegisteredWaitHandle)
FORWARD(WaitCallback)
FORWARD(WaitHandle)
FORWARD(WaitOrTimerCallback)
namespace ThreadPoolNamespace {
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;
template <class T>
using IEnumerable = Collections::Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Collections::Generic::IEnumerator<T>;
using IEnumerator_ = Collections::IEnumerator;
class ThreadPool {
  private: CLASS(_GetQueuedWorkItems_d__51) : public object {
    public: using interface = rt::TypeList<IEnumerable<Object>, IEnumerable_, IEnumerator<Object>, IDisposable, IEnumerator_>;
    private: Object get_CurrentOfObject();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void __m__Finally1();
    private: void ResetOfIEnumerator();
    private: IEnumerator<Object> GetEnumeratorOfObject();
    private: IEnumerator_ GetEnumeratorOfIEnumerable();
    private: Int32 __1__state;
    private: Object __2__current;
    private: Int32 __l__initialThreadId;
    private: IEnumerator<Object> __7__wrap1;
    private: Array<ThreadPoolWorkQueue::in::WorkStealingQueue> __7__wrap2;
    private: Int32 __7__wrap3;
    private: Array<Object> _items_5__5;
    private: Int32 _i_5__6;
  };
  private: CLASS(_GetLocallyQueuedWorkItems_d__52) : public object {
    public: using interface = rt::TypeList<IEnumerable<Object>, IEnumerable_, IEnumerator<Object>, IDisposable, IEnumerator_>;
    private: Object get_CurrentOfObject();
    private: Object get_CurrentOfIEnumerator();
    public: void ctor(Int32 __1__state);
    private: void DisposeOfIDisposable();
    private: Boolean MoveNext();
    private: void ResetOfIEnumerator();
    private: IEnumerator<Object> GetEnumeratorOfObject();
    private: IEnumerator_ GetEnumeratorOfIEnumerable();
    private: Int32 __1__state;
    private: Object __2__current;
    private: Int32 __l__initialThreadId;
    private: Array<Object> _items_5__2;
    private: Int32 _i_5__3;
  };
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _cctor_b__60_0(Object state);
    public: static __c __9;
  };
  public: static Int32 get_ThreadCount();
  public: static Int64 get_CompletedWorkItemCount();
  private: static Int64 get_PendingUnmanagedWorkItemCount();
  public: static Int64 get_PendingWorkItemCount();
  public: static Boolean KeepDispatching(Int32 startTickCount);
  public: static Boolean SetMaxThreads(Int32 workerThreads, Int32 completionPortThreads);
  public: static void GetMaxThreads(Int32& workerThreads, Int32& completionPortThreads);
  public: static Boolean SetMinThreads(Int32 workerThreads, Int32 completionPortThreads);
  public: static void GetMinThreads(Int32& workerThreads, Int32& completionPortThreads);
  public: static void GetAvailableThreads(Int32& workerThreads, Int32& completionPortThreads);
  private: static Int64 GetCompletedWorkItemCount();
  private: static RegisteredWaitHandle RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, UInt32 millisecondsTimeOutInterval, Boolean executeOnlyOnce, Boolean compressStack);
  public: static Interop::BOOL RequestWorkerThread();
  private: static Boolean PostQueuedCompletionStatus(NativeOverlapped* overlapped);
  public: static Boolean UnsafeQueueNativeOverlapped(NativeOverlapped* overlapped);
  private: static Boolean SetMinThreadsNative(Int32 workerThreads, Int32 completionPortThreads);
  private: static Boolean SetMaxThreadsNative(Int32 workerThreads, Int32 completionPortThreads);
  private: static void GetMinThreadsNative(Int32& workerThreads, Int32& completionPortThreads);
  private: static void GetMaxThreadsNative(Int32& workerThreads, Int32& completionPortThreads);
  private: static void GetAvailableThreadsNative(Int32& workerThreads, Int32& completionPortThreads);
  public: static Boolean NotifyWorkItemComplete();
  public: static void ReportThreadStatus(Boolean isWorking);
  public: static void NotifyWorkItemProgress();
  public: static void NotifyWorkItemProgressNative();
  private: static Boolean GetEnableWorkerTracking();
  private: static IntPtr RegisterWaitForSingleObjectNative(WaitHandle waitHandle, Object state, UInt32 timeOutInterval, Boolean executeOnlyOnce, RegisteredWaitHandle registeredWaitHandle);
  public: static Boolean BindHandle(IntPtr osHandle);
  public: static Boolean BindHandle(SafeHandle osHandle);
  private: static Boolean BindIOCompletionCallbackNative(IntPtr fileHandle);
  public: static RegisteredWaitHandle RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, UInt32 millisecondsTimeOutInterval, Boolean executeOnlyOnce);
  public: static RegisteredWaitHandle UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, UInt32 millisecondsTimeOutInterval, Boolean executeOnlyOnce);
  public: static RegisteredWaitHandle RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int32 millisecondsTimeOutInterval, Boolean executeOnlyOnce);
  public: static RegisteredWaitHandle UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int32 millisecondsTimeOutInterval, Boolean executeOnlyOnce);
  public: static RegisteredWaitHandle RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int64 millisecondsTimeOutInterval, Boolean executeOnlyOnce);
  public: static RegisteredWaitHandle UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int64 millisecondsTimeOutInterval, Boolean executeOnlyOnce);
  public: static RegisteredWaitHandle RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, TimeSpan timeout, Boolean executeOnlyOnce);
  public: static RegisteredWaitHandle UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, TimeSpan timeout, Boolean executeOnlyOnce);
  public: static Boolean QueueUserWorkItem(WaitCallback callBack);
  public: static Boolean QueueUserWorkItem(WaitCallback callBack, Object state);
  public: template <class TState>
  static Boolean QueueUserWorkItem(Action<TState> callBack, TState state, Boolean preferLocal);
  public: template <class TState>
  static Boolean UnsafeQueueUserWorkItem(Action<TState> callBack, TState state, Boolean preferLocal);
  public: static Boolean UnsafeQueueUserWorkItem(WaitCallback callBack, Object state);
  public: static Boolean UnsafeQueueUserWorkItem(IThreadPoolWorkItem callBack, Boolean preferLocal);
  public: static void UnsafeQueueUserWorkItemInternal(Object callBack, Boolean preferLocal);
  public: static Boolean TryPopCustomWorkItem(Object workItem);
  public: static IEnumerable<Object> GetQueuedWorkItems();
  public: static IEnumerable<Object> GetLocallyQueuedWorkItems();
  public: static IEnumerable<Object> GetGloballyQueuedWorkItems();
  private: static Array<Object> ToObjectArray(IEnumerable<Object> workitems);
  public: static Array<Object> GetQueuedWorkItemsForDebugger();
  public: static Array<Object> GetGloballyQueuedWorkItemsForDebugger();
  public: static Array<Object> GetLocallyQueuedWorkItemsForDebugger();
  public: static void cctor();
  public: static Boolean EnableWorkerTracking;
  public: static ThreadPoolWorkQueue s_workQueue;
  public: static Action<Object> s_invokeAsyncStateMachineBox;
};
} // namespace ThreadPoolNamespace
using ThreadPool = ThreadPoolNamespace::ThreadPool;
} // namespace System::Private::CoreLib::System::Threading
