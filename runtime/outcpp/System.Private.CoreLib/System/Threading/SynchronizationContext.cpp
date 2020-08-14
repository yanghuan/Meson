#include "SynchronizationContext-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Threading/WaitHandle-dep.h>

namespace System::Private::CoreLib::System::Threading::SynchronizationContextNamespace {
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
