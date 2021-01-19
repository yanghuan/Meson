#include "ThreadPoolWorkQueue-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/Collections/Concurrent/ConcurrentQueue-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventKeywords.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventLevel.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/FrameworkEventSource-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/IThreadPoolWorkItem.h>
#include <System.Private.CoreLib/System/Threading/SpinLock-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/Task-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPool-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadPoolWorkQueue-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadPoolWorkQueueNamespace {
using namespace Internal::Runtime::CompilerServices;
using namespace System::Collections::Concurrent;
using namespace System::Diagnostics::Tracing;
using namespace System::Threading::Tasks;

Boolean ThreadPoolWorkQueue___::WorkStealingQueue___::get_CanSteal() {
  return m_headIndex < m_tailIndex;
}

Int32 ThreadPoolWorkQueue___::WorkStealingQueue___::get_Count() {
  Boolean lockTaken = false;
  try {
    m_foreignLock.Enter(lockTaken);
    return Math::Max(0, m_tailIndex - m_headIndex);
  } catch (...) {
  } finally: {
    if (lockTaken) {
      m_foreignLock.Exit(false);
    }
  }
}

void ThreadPoolWorkQueue___::WorkStealingQueue___::LocalPush(Object obj) {
  Int32 num = m_tailIndex;
  if (num == Int32::MaxValue) {
    Boolean lockTaken = false;
    try {
      m_foreignLock.Enter(lockTaken);
      if (m_tailIndex == Int32::MaxValue) {
        m_headIndex &= m_mask;
        num = (m_tailIndex &= m_mask);
      }
    } catch (...) {
    } finally: {
      if (lockTaken) {
        m_foreignLock.Exit(true);
      }
    }
  }
  if (num < m_headIndex + m_mask) {
    Volatile::Write(m_array[num & m_mask], obj);
    m_tailIndex = num + 1;
    return;
  }
  Boolean lockTaken2 = false;
  try {
    m_foreignLock.Enter(lockTaken2);
    Int32 headIndex = m_headIndex;
    Int32 num2 = m_tailIndex - m_headIndex;
    if (num2 >= m_mask) {
      Array<Object> array = rt::newarr<Array<Object>>(m_array->get_Length() << 1);
      for (Int32 i = 0; i < m_array->get_Length(); i++) {
        array[i] = m_array[(i + headIndex) & m_mask];
      }
      m_array = array;
      m_headIndex = 0;
      num = (m_tailIndex = num2);
      m_mask = (m_mask << 1) | 1;
    }
    Volatile::Write(m_array[num & m_mask], obj);
    m_tailIndex = num + 1;
  } catch (...) {
  } finally: {
    if (lockTaken2) {
      m_foreignLock.Exit(false);
    }
  }
}

Boolean ThreadPoolWorkQueue___::WorkStealingQueue___::LocalFindAndPop(Object obj) {
  if (m_array[(m_tailIndex - 1) & m_mask] == obj) {
    Object obj2 = LocalPop();
    return obj2 != nullptr;
  }
  for (Int32 num = m_tailIndex - 2; num >= m_headIndex; num--) {
    if (m_array[num & m_mask] == obj) {
      Boolean lockTaken = false;
      try {
        m_foreignLock.Enter(lockTaken);
        if (m_array[num & m_mask] == nullptr) {
          return false;
        }
        Volatile::Write(m_array[num & m_mask], (Object)nullptr);
        if (num == m_tailIndex) {
          m_tailIndex--;
        } else if (num == m_headIndex) {
          m_headIndex++;
        }

        return true;
      } catch (...) {
      } finally: {
        if (lockTaken) {
          m_foreignLock.Exit(false);
        }
      }
    }
  }
  return false;
}

Object ThreadPoolWorkQueue___::WorkStealingQueue___::LocalPop() {
  if (m_headIndex >= m_tailIndex) {
    return nullptr;
  }
  return LocalPopCore();
}

Object ThreadPoolWorkQueue___::WorkStealingQueue___::LocalPopCore() {
  Int32 num;
  Object obj;
  while (true) {
    Int32 tailIndex = m_tailIndex;
    if (m_headIndex >= tailIndex) {
      return nullptr;
    }
    tailIndex--;
    Interlocked::Exchange(m_tailIndex, tailIndex);
    if (m_headIndex <= tailIndex) {
      num = tailIndex & m_mask;
      obj = Volatile::Read(m_array[num]);
      if (obj != nullptr) {
        break;
      }
      continue;
    }
    Boolean lockTaken = false;
    try {
      m_foreignLock.Enter(lockTaken);
      if (m_headIndex <= tailIndex) {
        Int32 num2 = tailIndex & m_mask;
        Object obj2 = Volatile::Read(m_array[num2]);
        if (obj2 != nullptr) {
          m_array[num2] = nullptr;
          return obj2;
        }
        continue;
      }
      m_tailIndex = tailIndex + 1;
      return nullptr;
    } catch (...) {
    } finally: {
      if (lockTaken) {
        m_foreignLock.Exit(false);
      }
    }
  }
  m_array[num] = nullptr;
  return obj;
}

Object ThreadPoolWorkQueue___::WorkStealingQueue___::TrySteal(Boolean& missedSteal) {
  while (get_CanSteal()) {
    Boolean lockTaken = false;
    try {
      m_foreignLock.TryEnter(lockTaken);
      if (lockTaken) {
        Int32 headIndex = m_headIndex;
        Interlocked::Exchange(m_headIndex, headIndex + 1);
        if (headIndex < m_tailIndex) {
          Int32 num = headIndex & m_mask;
          Object obj = Volatile::Read(m_array[num]);
          if (obj == nullptr) {
            continue;
          }
          m_array[num] = nullptr;
          return obj;
        }
        m_headIndex = headIndex;
      }
    } catch (...) {
    } finally: {
      if (lockTaken) {
        m_foreignLock.Exit(false);
      }
    }
    missedSteal = true;
    break;
  }
  return nullptr;
}

void ThreadPoolWorkQueue___::WorkStealingQueue___::ctor() {
  m_array = rt::newarr<Array<Object>>(32);
  m_mask = 31;
  m_foreignLock = SpinLock(false);
  Object::in::ctor();
}

Array<ThreadPoolWorkQueue::in::WorkStealingQueue> ThreadPoolWorkQueue___::WorkStealingQueueList::get_Queues() {
  return _queues;
}

void ThreadPoolWorkQueue___::WorkStealingQueueList::Add(WorkStealingQueue queue) {
  Array<WorkStealingQueue> queues;
  Array<WorkStealingQueue> array;
  do {
    queues = _queues;
    array = rt::newarr<Array<WorkStealingQueue>>(queues->get_Length() + 1);
    Array<>::in::Copy(queues, array, queues->get_Length());
    array[array->get_Length() - 1] = queue;
  } while (Interlocked::CompareExchange(_queues, array, queues) != queues);
}

void ThreadPoolWorkQueue___::WorkStealingQueueList::Remove(WorkStealingQueue queue) {
  Array<WorkStealingQueue> queues;
  Array<WorkStealingQueue> array;
  do {
    queues = _queues;
    if (queues->get_Length() == 0) {
      break;
    }
    Int32 num = Array<>::in::IndexOf(queues, queue);
    if (num == -1) {
      break;
    }
    array = rt::newarr<Array<WorkStealingQueue>>(queues->get_Length() - 1);
    if (num == 0) {
      Array<>::in::Copy(queues, 1, array, 0, array->get_Length());
      continue;
    }
    if (num == queues->get_Length() - 1) {
      Array<>::in::Copy(queues, array, array->get_Length());
      continue;
    }
    Array<>::in::Copy(queues, array, num);
    Array<>::in::Copy(queues, num + 1, array, num, array->get_Length() - num);
  } while (Interlocked::CompareExchange(_queues, array, queues) != queues);
}

void ThreadPoolWorkQueue___::WorkStealingQueueList::cctor() {
  _queues = rt::newarr<Array<WorkStealingQueue>>(0);
}

Int64 ThreadPoolWorkQueue___::get_LocalCount() {
  Int64 num = 0;
  Array<WorkStealingQueue> queues = WorkStealingQueueList::get_Queues();
  for (WorkStealingQueue&& workStealingQueue : *queues) {
    num += workStealingQueue->get_Count();
  }
  return num;
}

Int64 ThreadPoolWorkQueue___::get_GlobalCount() {
  return workItems->get_Count();
}

void ThreadPoolWorkQueue___::ctor() {
  workItems = rt::newobj<ConcurrentQueue<Object>>();
  Object::in::ctor();
  loggingEnabled = FrameworkEventSource::in::Log->IsEnabled(EventLevel::Verbose, (EventKeywords)18);
}

ThreadPoolWorkQueueThreadLocals ThreadPoolWorkQueue___::GetOrCreateThreadLocals() {
  ThreadPoolWorkQueueThreadLocals as = ThreadPoolWorkQueueThreadLocals::in::threadLocals;
  return as != nullptr ? as : CreateThreadLocals();
}

ThreadPoolWorkQueueThreadLocals ThreadPoolWorkQueue___::CreateThreadLocals() {
  return ThreadPoolWorkQueueThreadLocals::in::threadLocals = rt::newobj<ThreadPoolWorkQueueThreadLocals>((ThreadPoolWorkQueue)this);
}

void ThreadPoolWorkQueue___::EnsureThreadRequested() {
  Int32 num = numOutstandingThreadRequests;
  while (num < Environment::get_ProcessorCount()) {
    Int32 num2 = Interlocked::CompareExchange(numOutstandingThreadRequests, num + 1, num);
    if (num2 == num) {
      ThreadPool::RequestWorkerThread();
      break;
    }
    num = num2;
  }
}

void ThreadPoolWorkQueue___::MarkThreadRequestSatisfied() {
  Int32 num = numOutstandingThreadRequests;
  while (num > 0) {
    Int32 num2 = Interlocked::CompareExchange(numOutstandingThreadRequests, num - 1, num);
    if (num2 != num) {
      num = num2;
      continue;
    }
    break;
  }
}

void ThreadPoolWorkQueue___::Enqueue(Object callback, Boolean forceGlobal) {
  if (loggingEnabled) {
    FrameworkEventSource::in::Log->ThreadPoolEnqueueWorkObject(callback);
  }
  ThreadPoolWorkQueueThreadLocals threadPoolWorkQueueThreadLocals = nullptr;
  if (!forceGlobal) {
    threadPoolWorkQueueThreadLocals = ThreadPoolWorkQueueThreadLocals::in::threadLocals;
  }
  if (threadPoolWorkQueueThreadLocals != nullptr) {
    threadPoolWorkQueueThreadLocals->workStealingQueue->LocalPush(callback);
  } else {
    workItems->Enqueue(callback);
  }
  EnsureThreadRequested();
}

Boolean ThreadPoolWorkQueue___::LocalFindAndPop(Object callback) {
  ThreadPoolWorkQueueThreadLocals threadLocals = ThreadPoolWorkQueueThreadLocals::in::threadLocals;
  if (threadLocals != nullptr) {
    return threadLocals->workStealingQueue->LocalFindAndPop(callback);
  }
  return false;
}

Object ThreadPoolWorkQueue___::Dequeue(ThreadPoolWorkQueueThreadLocals tl, Boolean& missedSteal) {
  WorkStealingQueue workStealingQueue = tl->workStealingQueue;
  Object result;
  if ((result = workStealingQueue->LocalPop()) == nullptr && !workItems->TryDequeue(result)) {
    Array<WorkStealingQueue> queues = WorkStealingQueueList::get_Queues();
    Int32 num = queues->get_Length();
    Int32 num2 = num - 1;
    Int32 num3 = tl->random.Next(num);
    while (num > 0) {
      num3 = ((num3 < num2) ? (num3 + 1) : 0);
      WorkStealingQueue workStealingQueue2 = queues[num3];
      if (workStealingQueue2 != workStealingQueue && workStealingQueue2->get_CanSteal()) {
        result = workStealingQueue2->TrySteal(missedSteal);
        if (result != nullptr) {
          break;
        }
      }
      num--;
    }
  }
  return result;
}

Boolean ThreadPoolWorkQueue___::Dispatch() {
  ThreadPoolWorkQueue s_workQueue = ThreadPool::s_workQueue;
  Int32 tickCount = Environment::get_TickCount();
  s_workQueue->MarkThreadRequestSatisfied();
  s_workQueue->loggingEnabled = FrameworkEventSource::in::Log->IsEnabled(EventLevel::Verbose, (EventKeywords)18);
  Boolean flag = true;
  try {
    ThreadPoolWorkQueue threadPoolWorkQueue = s_workQueue;
    ThreadPoolWorkQueueThreadLocals orCreateThreadLocals = threadPoolWorkQueue->GetOrCreateThreadLocals();
    Thread currentThread = orCreateThreadLocals->currentThread;
    currentThread->_executionContext = nullptr;
    currentThread->_synchronizationContext = nullptr;
    while (ThreadPool::KeepDispatching(tickCount)) {
      Boolean missedSteal = false;
      Object obj = threadPoolWorkQueue->Dequeue(orCreateThreadLocals, missedSteal);
      if (obj == nullptr) {
        flag = missedSteal;
        return true;
      }
      if (threadPoolWorkQueue->loggingEnabled) {
        FrameworkEventSource::in::Log->ThreadPoolDequeueWorkObject(obj);
      }
      threadPoolWorkQueue->EnsureThreadRequested();
      if (ThreadPool::EnableWorkerTracking) {
        Boolean flag2 = false;
        try {
          ThreadPool::ReportThreadStatus(true);
          flag2 = true;
          Task<> task = rt::as<Task<>>(obj);
          if (task != nullptr) {
            task->ExecuteFromThreadPool(currentThread);
          } else {
            Unsafe::As<IThreadPoolWorkItem>(obj)->Execute();
          }
        } catch (...) {
        } finally: {
          if (flag2) {
            ThreadPool::ReportThreadStatus(false);
          }
        }
      } else {
        Task<> task2 = rt::as<Task<>>(obj);
        if (task2 != nullptr) {
          task2->ExecuteFromThreadPool(currentThread);
        } else {
          Unsafe::As<IThreadPoolWorkItem>(obj)->Execute();
        }
      }
      currentThread->ResetThreadPoolThread();
      obj = nullptr;
      ExecutionContext::in::ResetThreadPoolThread(currentThread);
      if (!ThreadPool::NotifyWorkItemComplete()) {
        return false;
      }
    }
    return true;
  } catch (...) {
  } finally: {
    if (flag) {
      s_workQueue->EnsureThreadRequested();
    }
  }
}

} // namespace System::Private::CoreLib::System::Threading::ThreadPoolWorkQueueNamespace
