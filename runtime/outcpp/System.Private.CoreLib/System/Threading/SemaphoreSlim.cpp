#include "SemaphoreSlim-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/OperationCanceledException-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/AsyncTaskMethodBuilder-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/StrongBox-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationTokenRegistration-dep.h>
#include <System.Private.CoreLib/System/Threading/ManualResetEvent-dep.h>
#include <System.Private.CoreLib/System/Threading/Monitor-dep.h>
#include <System.Private.CoreLib/System/Threading/SemaphoreFullException-dep.h>
#include <System.Private.CoreLib/System/Threading/SemaphoreSlim-dep.h>
#include <System.Private.CoreLib/System/Threading/SpinWait-dep.h>
#include <System.Private.CoreLib/System/Threading/Tasks/TaskCreationOptions.h>
#include <System.Private.CoreLib/System/Threading/TimeoutHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::SemaphoreSlimNamespace {
using namespace System::Runtime::CompilerServices;
using namespace System::Threading::Tasks;

void SemaphoreSlim___::TaskNode___::ctor() {
}

Int32 SemaphoreSlim___::get_CurrentCount() {
  return m_currentCount;
}

WaitHandle SemaphoreSlim___::get_AvailableWaitHandle() {
  CheckDispose();
  if (m_waitHandle != nullptr) {
    return m_waitHandle;
  }
  {
    rt::lock(m_lockObjAndDisposed);
    if (m_waitHandle == nullptr) {
      m_waitHandle = rt::newobj<ManualResetEvent>(m_currentCount != 0);
    }
  }
  return m_waitHandle;
}

void SemaphoreSlim___::ctor(Int32 initialCount) {
}

void SemaphoreSlim___::ctor(Int32 initialCount, Int32 maxCount) {
  if (initialCount < 0 || initialCount > maxCount) {
    rt::throw_exception<ArgumentOutOfRangeException>("initialCount", initialCount, SR::get_SemaphoreSlim_ctor_InitialCountWrong());
  }
  if (maxCount <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("maxCount", maxCount, SR::get_SemaphoreSlim_ctor_MaxCountWrong());
  }
  m_maxCount = maxCount;
  m_currentCount = initialCount;
  m_lockObjAndDisposed = rt::newobj<StrongBox<Boolean>>();
}

void SemaphoreSlim___::Wait() {
  Wait(-1, CancellationToken::get_None());
}

void SemaphoreSlim___::Wait(CancellationToken cancellationToken) {
  Wait(-1, cancellationToken);
}

Boolean SemaphoreSlim___::Wait(TimeSpan timeout) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", timeout, SR::get_SemaphoreSlim_Wait_TimeoutWrong());
  }
  return Wait((Int32)timeout.get_TotalMilliseconds(), CancellationToken::get_None());
}

Boolean SemaphoreSlim___::Wait(TimeSpan timeout, CancellationToken cancellationToken) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", timeout, SR::get_SemaphoreSlim_Wait_TimeoutWrong());
  }
  return Wait((Int32)timeout.get_TotalMilliseconds(), cancellationToken);
}

Boolean SemaphoreSlim___::Wait(Int32 millisecondsTimeout) {
  return Wait(millisecondsTimeout, CancellationToken::get_None());
}

Boolean SemaphoreSlim___::Wait(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  CheckDispose();
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout", millisecondsTimeout, SR::get_SemaphoreSlim_Wait_TimeoutWrong());
  }
  cancellationToken.ThrowIfCancellationRequested();
  if (millisecondsTimeout == 0 && m_currentCount == 0) {
    return false;
  }
  UInt32 startTime = 0u;
  if (millisecondsTimeout != -1 && millisecondsTimeout > 0) {
    startTime = TimeoutHelper::GetTime();
  }
  Boolean result = false;
  Task<Boolean> task = nullptr;
  Boolean lockTaken = false;
  CancellationTokenRegistration cancellationTokenRegistration = cancellationToken.UnsafeRegister(s_cancellationTokenCanceledEventHandler, (SemaphoreSlim)this);
  try {
    if (m_currentCount == 0) {
      Int32 num = SpinWait::SpinCountforSpinBeforeWait * 4;
      SpinWait spinWait;
      while (spinWait.get_Count() < num) {
        spinWait.SpinOnce(-1);
        if (m_currentCount != 0) {
          break;
        }
      }
    }
    try {
    } catch (...) {
    } finally: {
      Monitor::Enter(m_lockObjAndDisposed, lockTaken);
      if (lockTaken) {
        m_waitCount++;
      }
    }
    if (m_asyncHead != nullptr) {
      task = WaitAsync(millisecondsTimeout, cancellationToken);
    } else {
      OperationCanceledException ex = nullptr;
      if (m_currentCount == 0) {
        if (millisecondsTimeout == 0) {
          return false;
        }
        try {
          result = WaitUntilCountOrTimeout(millisecondsTimeout, startTime, cancellationToken);
        } catch (OperationCanceledException ex2) {
          ex = ex2;
        }
      }
      if (m_currentCount > 0) {
        result = true;
        m_currentCount--;
      } else if (ex != nullptr) {
        rt::throw_exception(ex);
      }

      if (m_waitHandle != nullptr && m_currentCount == 0) {
        m_waitHandle->Reset();
      }
    }
  } catch (...) {
  } finally: {
    if (lockTaken) {
      m_waitCount--;
      Monitor::Exit(m_lockObjAndDisposed);
    }
    cancellationTokenRegistration.Dispose();
  }
  if (task == nullptr) {
    return result;
  }
  return task->GetAwaiter().GetResult();
}

Boolean SemaphoreSlim___::WaitUntilCountOrTimeout(Int32 millisecondsTimeout, UInt32 startTime, CancellationToken cancellationToken) {
  Int32 num = -1;
  while (m_currentCount == 0) {
    cancellationToken.ThrowIfCancellationRequested();
    if (millisecondsTimeout != -1) {
      num = TimeoutHelper::UpdateTimeOut(startTime, millisecondsTimeout);
      if (num <= 0) {
        return false;
      }
    }
    Boolean flag = Monitor::Wait(m_lockObjAndDisposed, num);
    if (m_countOfWaitersPulsedToWake != 0) {
      m_countOfWaitersPulsedToWake--;
    }
    if (!flag) {
      return false;
    }
  }
  return true;
}

Task<> SemaphoreSlim___::WaitAsync() {
  return WaitAsync(-1, rt::default__);
}

Task<> SemaphoreSlim___::WaitAsync(CancellationToken cancellationToken) {
  return WaitAsync(-1, cancellationToken);
}

Task<Boolean> SemaphoreSlim___::WaitAsync(Int32 millisecondsTimeout) {
  return WaitAsync(millisecondsTimeout, rt::default__);
}

Task<Boolean> SemaphoreSlim___::WaitAsync(TimeSpan timeout) {
  return WaitAsync(timeout, rt::default__);
}

Task<Boolean> SemaphoreSlim___::WaitAsync(TimeSpan timeout, CancellationToken cancellationToken) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", timeout, SR::get_SemaphoreSlim_Wait_TimeoutWrong());
  }
  return WaitAsync((Int32)timeout.get_TotalMilliseconds(), cancellationToken);
}

Task<Boolean> SemaphoreSlim___::WaitAsync(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  CheckDispose();
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout", millisecondsTimeout, SR::get_SemaphoreSlim_Wait_TimeoutWrong());
  }
  if (cancellationToken.get_IsCancellationRequested()) {
    return Task<>::in::FromCanceled<Boolean>(cancellationToken);
  }
  {
    rt::lock(m_lockObjAndDisposed);
    if (m_currentCount > 0) {
      m_currentCount--;
      if (m_waitHandle != nullptr && m_currentCount == 0) {
        m_waitHandle->Reset();
      }
      return s_trueTask;
    }
    if (millisecondsTimeout == 0) {
      return s_falseTask;
    }
    TaskNode taskNode = CreateAndAddAsyncWaiter();
    return (millisecondsTimeout == -1 && !cancellationToken.get_CanBeCanceled()) ? taskNode : WaitUntilCountOrTimeoutAsync(taskNode, millisecondsTimeout, cancellationToken);
  }
}

SemaphoreSlim::in::TaskNode SemaphoreSlim___::CreateAndAddAsyncWaiter() {
  TaskNode taskNode = rt::newobj<TaskNode>();
  if (m_asyncHead == nullptr) {
    m_asyncHead = taskNode;
    m_asyncTail = taskNode;
  } else {
    m_asyncTail->Next = taskNode;
    taskNode->Prev = m_asyncTail;
    m_asyncTail = taskNode;
  }
  return taskNode;
}

Boolean SemaphoreSlim___::RemoveAsyncWaiter(TaskNode task) {
  Boolean result = m_asyncHead == task || task->Prev != nullptr;
  if (task->Next != nullptr) {
    task->Next->Prev = task->Prev;
  }
  if (task->Prev != nullptr) {
    task->Prev->Next = task->Next;
  }
  if (m_asyncHead == task) {
    m_asyncHead = task->Next;
  }
  if (m_asyncTail == task) {
    m_asyncTail = task->Prev;
  }
  task->Next = (task->Prev = nullptr);
  return result;
}

Task<Boolean> SemaphoreSlim___::WaitUntilCountOrTimeoutAsync(TaskNode asyncWaiter, Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  <WaitUntilCountOrTimeoutAsync>d__33 stateMachine;
  stateMachine.<>t__builder = AsyncTaskMethodBuilder<Boolean>::Create();
  stateMachine.<>4__this = (SemaphoreSlim)this;
  stateMachine.asyncWaiter = asyncWaiter;
  stateMachine.millisecondsTimeout = millisecondsTimeout;
  stateMachine.cancellationToken = cancellationToken;
  stateMachine.<>1__state = -1;
  stateMachine.<>t__builder.Start(stateMachine);
  return stateMachine.<>t__builder.get_Task();
}

Int32 SemaphoreSlim___::Release() {
  return Release(1);
}

Int32 SemaphoreSlim___::Release(Int32 releaseCount) {
  CheckDispose();
  if (releaseCount < 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("releaseCount", releaseCount, SR::get_SemaphoreSlim_Release_CountWrong());
  }
  {
    rt::lock(m_lockObjAndDisposed);
    Int32 currentCount = m_currentCount;
    Int32 num = currentCount;
    if (m_maxCount - currentCount < releaseCount) {
      rt::throw_exception<SemaphoreFullException>();
    }
    currentCount += releaseCount;
    Int32 waitCount = m_waitCount;
    Int32 num2 = Math::Min(currentCount, waitCount) - m_countOfWaitersPulsedToWake;
    if (num2 > 0) {
      if (num2 > releaseCount) {
        num2 = releaseCount;
      }
      m_countOfWaitersPulsedToWake += num2;
      for (Int32 i = 0; i < num2; i++) {
        Monitor::Pulse(m_lockObjAndDisposed);
      }
    }
    if (m_asyncHead != nullptr) {
      Int32 num3 = currentCount - waitCount;
      while (num3 > 0 && m_asyncHead != nullptr) {
        currentCount--;
        num3--;
        TaskNode asyncHead = m_asyncHead;
        RemoveAsyncWaiter(asyncHead);
        asyncHead->TrySetResult(true);
      }
    }
    m_currentCount = currentCount;
    if (m_waitHandle != nullptr) {
      if (num == 0) {
        if (currentCount > 0) {
          m_waitHandle->Set();
          return num;
        }
        return num;
      }
      return num;
    }
    return num;
  }
}

void SemaphoreSlim___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((SemaphoreSlim)this);
}

void SemaphoreSlim___::Dispose(Boolean disposing) {
  if (disposing) {
    WaitHandle waitHandle = m_waitHandle;
    if (waitHandle != nullptr) {
      waitHandle->Dispose();
      m_waitHandle = nullptr;
    }
    m_lockObjAndDisposed->Value = true;
    m_asyncHead = nullptr;
    m_asyncTail = nullptr;
  }
}

void SemaphoreSlim___::CancellationTokenCanceledEventHandler(Object obj) {
  SemaphoreSlim semaphoreSlim = (SemaphoreSlim)obj;
  {
    rt::lock(semaphoreSlim->m_lockObjAndDisposed);
    Monitor::PulseAll(semaphoreSlim->m_lockObjAndDisposed);
  }
}

void SemaphoreSlim___::CheckDispose() {
  if (m_lockObjAndDisposed->Value) {
    rt::throw_exception<ObjectDisposedException>(nullptr, SR::get_SemaphoreSlim_Disposed());
  }
}

void SemaphoreSlim___::cctor() {
  s_trueTask = rt::newobj<Task<Boolean>>(false, true, (TaskCreationOptions)16384, rt::default__);
  s_falseTask = rt::newobj<Task<Boolean>>(false, false, (TaskCreationOptions)16384, rt::default__);
  s_cancellationTokenCanceledEventHandler = &CancellationTokenCanceledEventHandler;
}

} // namespace System::Private::CoreLib::System::Threading::SemaphoreSlimNamespace
