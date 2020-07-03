#include "ThreadPoolWorkQueue-dep.h"

#include <System.Private.CoreLib/System/Threading/ThreadPoolWorkQueue-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadPoolWorkQueueNamespace {
Boolean ThreadPoolWorkQueue___::WorkStealingQueue___::get_CanSteal() {
  return Boolean();
};
Int32 ThreadPoolWorkQueue___::WorkStealingQueue___::get_Count() {
  return Int32();
};
void ThreadPoolWorkQueue___::WorkStealingQueue___::LocalPush(Object obj) {
};
Boolean ThreadPoolWorkQueue___::WorkStealingQueue___::LocalFindAndPop(Object obj) {
  return Boolean();
};
Object ThreadPoolWorkQueue___::WorkStealingQueue___::LocalPop() {
  return nullptr;
};
Object ThreadPoolWorkQueue___::WorkStealingQueue___::LocalPopCore() {
  return nullptr;
};
Object ThreadPoolWorkQueue___::WorkStealingQueue___::TrySteal(Boolean& missedSteal) {
  return nullptr;
};
Array<ThreadPoolWorkQueue::in::WorkStealingQueue> ThreadPoolWorkQueue___::WorkStealingQueueList::get_Queues() {
  return Array<ThreadPoolWorkQueue::in::WorkStealingQueue>();
};
void ThreadPoolWorkQueue___::WorkStealingQueueList::Add(WorkStealingQueue queue) {
};
void ThreadPoolWorkQueue___::WorkStealingQueueList::Remove(WorkStealingQueue queue) {
};
Int64 ThreadPoolWorkQueue___::get_LocalCount() {
  return Int64();
};
Int64 ThreadPoolWorkQueue___::get_GlobalCount() {
  return Int64();
};
ThreadPoolWorkQueueThreadLocals ThreadPoolWorkQueue___::GetOrCreateThreadLocals() {
  return nullptr;
};
ThreadPoolWorkQueueThreadLocals ThreadPoolWorkQueue___::CreateThreadLocals() {
  return nullptr;
};
void ThreadPoolWorkQueue___::EnsureThreadRequested() {
};
void ThreadPoolWorkQueue___::MarkThreadRequestSatisfied() {
};
void ThreadPoolWorkQueue___::Enqueue(Object callback, Boolean forceGlobal) {
};
Boolean ThreadPoolWorkQueue___::LocalFindAndPop(Object callback) {
  return Boolean();
};
Object ThreadPoolWorkQueue___::Dequeue(ThreadPoolWorkQueueThreadLocals tl, Boolean& missedSteal) {
  return nullptr;
};
Boolean ThreadPoolWorkQueue___::Dispatch() {
  return Boolean();
};
} // namespace System::Private::CoreLib::System::Threading::ThreadPoolWorkQueueNamespace
