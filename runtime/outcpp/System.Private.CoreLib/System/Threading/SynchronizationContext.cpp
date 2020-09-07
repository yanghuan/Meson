#include "SynchronizationContext-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/Threading/WaitHandle-dep.h>

namespace System::Private::CoreLib::System::Threading::SynchronizationContextNamespace {
void SynchronizationContext___::__c___::cctor() {
  <>9 = rt::newobj<__c>();
}

void SynchronizationContext___::__c___::ctor() {
}

void SynchronizationContext___::__c___::_Post_b__8_0(ValueTuple<SendOrPostCallback, Object> s) {
  s.Item1(s.Item2);
}

SynchronizationContext SynchronizationContext___::get_Current() {
  return Thread::in::get_CurrentThread()->_synchronizationContext;
}

Int32 SynchronizationContext___::InvokeWaitMethodHelper(SynchronizationContext syncContext, Array<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  return syncContext->Wait(waitHandles, waitAll, millisecondsTimeout);
}

void SynchronizationContext___::ctor() {
}

void SynchronizationContext___::SetWaitNotificationRequired() {
  _requireWaitNotification = true;
}

Boolean SynchronizationContext___::IsWaitNotificationRequired() {
  return _requireWaitNotification;
}

void SynchronizationContext___::Send(SendOrPostCallback d, Object state) {
  d(state);
}

void SynchronizationContext___::Post(SendOrPostCallback d, Object state) {
  Action<ValueTuple<SendOrPostCallback, Object>> as = __c::in::__9__8_0;
  ThreadPool::QueueUserWorkItem(as != nullptr ? as : (__c::in::__9__8_0 = rt::newobj<Action<ValueTuple<SendOrPostCallback, Object>>>(&_Post_b__8_0)), {d, state}, false);
}

void SynchronizationContext___::OperationStarted() {
}

void SynchronizationContext___::OperationCompleted() {
}

Int32 SynchronizationContext___::Wait(Array<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  return WaitHelper(waitHandles, waitAll, millisecondsTimeout);
}

Int32 SynchronizationContext___::WaitHelper(Array<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  if (waitHandles == nullptr) {
    rt::throw_exception<ArgumentNullException>("waitHandles");
  }
  return WaitHandle::in::WaitMultipleIgnoringSyncContext(waitHandles, waitAll, millisecondsTimeout);
}

void SynchronizationContext___::SetSynchronizationContext(SynchronizationContext syncContext) {
  Thread::in::get_CurrentThread()->_synchronizationContext = syncContext;
}

SynchronizationContext SynchronizationContext___::CreateCopy() {
  return rt::newobj<SynchronizationContext>();
}

} // namespace System::Private::CoreLib::System::Threading::SynchronizationContextNamespace
