#include "ThreadPool-dep.h"

namespace System::Private::CoreLib::System::Threading::ThreadPoolNamespace {
Int64 ThreadPool::get_CompletedWorkItemCount() {
  return Int64();
};

Int64 ThreadPool::get_PendingWorkItemCount() {
  return Int64();
};

Boolean ThreadPool::KeepDispatching(Int32 startTickCount) {
  return Boolean();
};

Boolean ThreadPool::SetMaxThreads(Int32 workerThreads, Int32 completionPortThreads) {
  return Boolean();
};

void ThreadPool::GetMaxThreads(Int32& workerThreads, Int32& completionPortThreads) {
};

Boolean ThreadPool::SetMinThreads(Int32 workerThreads, Int32 completionPortThreads) {
  return Boolean();
};

void ThreadPool::GetMinThreads(Int32& workerThreads, Int32& completionPortThreads) {
};

void ThreadPool::GetAvailableThreads(Int32& workerThreads, Int32& completionPortThreads) {
};

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, UInt32 millisecondsTimeOutInterval, Boolean executeOnlyOnce, Boolean compressStack) {
  return nullptr;
};

Boolean ThreadPool::UnsafeQueueNativeOverlapped(NativeOverlapped* overlapped) {
  return Boolean();
};

void ThreadPool::NotifyWorkItemProgress() {
};

Boolean ThreadPool::BindHandle(IntPtr osHandle) {
  return Boolean();
};

Boolean ThreadPool::BindHandle(SafeHandle osHandle) {
  return Boolean();
};

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, UInt32 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  return nullptr;
};

RegisteredWaitHandle ThreadPool::UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, UInt32 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  return nullptr;
};

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int32 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  return nullptr;
};

RegisteredWaitHandle ThreadPool::UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int32 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  return nullptr;
};

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int64 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  return nullptr;
};

RegisteredWaitHandle ThreadPool::UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, Int64 millisecondsTimeOutInterval, Boolean executeOnlyOnce) {
  return nullptr;
};

RegisteredWaitHandle ThreadPool::RegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, TimeSpan timeout, Boolean executeOnlyOnce) {
  return nullptr;
};

RegisteredWaitHandle ThreadPool::UnsafeRegisterWaitForSingleObject(WaitHandle waitObject, WaitOrTimerCallback callBack, Object state, TimeSpan timeout, Boolean executeOnlyOnce) {
  return nullptr;
};

Boolean ThreadPool::QueueUserWorkItem(WaitCallback callBack) {
  return Boolean();
};

Boolean ThreadPool::QueueUserWorkItem(WaitCallback callBack, Object state) {
  return Boolean();
};

Boolean ThreadPool::UnsafeQueueUserWorkItem(WaitCallback callBack, Object state) {
  return Boolean();
};

Boolean ThreadPool::UnsafeQueueUserWorkItem(IThreadPoolWorkItem callBack, Boolean preferLocal) {
  return Boolean();
};

void ThreadPool::UnsafeQueueUserWorkItemInternal(Object callBack, Boolean preferLocal) {
};

Boolean ThreadPool::TryPopCustomWorkItem(Object workItem) {
  return Boolean();
};

IEnumerable<Object> ThreadPool::GetQueuedWorkItems() {
  return nullptr;
};

IEnumerable<Object> ThreadPool::GetLocallyQueuedWorkItems() {
  return nullptr;
};

IEnumerable<Object> ThreadPool::GetGloballyQueuedWorkItems() {
  return nullptr;
};

Array<Object> ThreadPool::ToObjectArray(IEnumerable<Object> workitems) {
  return Array<Object>();
};

Array<Object> ThreadPool::GetQueuedWorkItemsForDebugger() {
  return Array<Object>();
};

Array<Object> ThreadPool::GetGloballyQueuedWorkItemsForDebugger() {
  return Array<Object>();
};

Array<Object> ThreadPool::GetLocallyQueuedWorkItemsForDebugger() {
  return Array<Object>();
};

} // namespace System::Private::CoreLib::System::Threading::ThreadPoolNamespace
