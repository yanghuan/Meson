#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/Interop.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(IntPtr)
FORWARD(Object)
FORWARDS(TimeSpan)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading {
FORWARD(IThreadPoolWorkItem)
FORWARDS(NativeOverlapped)
FORWARD(RegisteredWaitHandle)
FORWARD(ThreadPoolWorkQueue)
FORWARD(WaitCallback)
FORWARD(WaitHandle)
FORWARD(WaitOrTimerCallback)
namespace ThreadPoolNamespace {
using namespace Collections::Generic;
using namespace Runtime::InteropServices;
class ThreadPool {
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
  private: static void SCtor();
  public: static Boolean EnableWorkerTracking;
  public: static ThreadPoolWorkQueue s_workQueue;
  public: static Action<Object> s_invokeAsyncStateMachineBox;
};
} // namespace ThreadPoolNamespace
using ThreadPool = ThreadPoolNamespace::ThreadPool;
} // namespace System::Private::CoreLib::System::Threading
