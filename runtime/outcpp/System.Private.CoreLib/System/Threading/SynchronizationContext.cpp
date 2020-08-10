#include "SynchronizationContext-dep.h"

#include <System.Private.CoreLib/System/Threading/SynchronizationContext-dep.h>

namespace System::Private::CoreLib::System::Threading::SynchronizationContextNamespace {
SynchronizationContext SynchronizationContext___::get_Current() {
  return nullptr;
}

Int32 SynchronizationContext___::InvokeWaitMethodHelper(SynchronizationContext syncContext, Array<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  return Int32();
}

void SynchronizationContext___::ctor() {
}

void SynchronizationContext___::SetWaitNotificationRequired() {
}

Boolean SynchronizationContext___::IsWaitNotificationRequired() {
  return Boolean();
}

void SynchronizationContext___::Send(SendOrPostCallback d, Object state) {
}

void SynchronizationContext___::Post(SendOrPostCallback d, Object state) {
}

void SynchronizationContext___::OperationStarted() {
}

void SynchronizationContext___::OperationCompleted() {
}

Int32 SynchronizationContext___::Wait(Array<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  return Int32();
}

Int32 SynchronizationContext___::WaitHelper(Array<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout) {
  return Int32();
}

void SynchronizationContext___::SetSynchronizationContext(SynchronizationContext syncContext) {
}

SynchronizationContext SynchronizationContext___::CreateCopy() {
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Threading::SynchronizationContextNamespace
