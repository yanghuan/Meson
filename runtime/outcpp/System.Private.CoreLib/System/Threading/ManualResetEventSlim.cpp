#include "ManualResetEventSlim-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/ManualResetEvent-dep.h>
#include <System.Private.CoreLib/System/Threading/ManualResetEventSlim-dep.h>
#include <System.Private.CoreLib/System/Threading/Monitor-dep.h>
#include <System.Private.CoreLib/System/Threading/SpinWait-dep.h>
#include <System.Private.CoreLib/System/Threading/TimeoutHelper-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::ManualResetEventSlimNamespace {
WaitHandle ManualResetEventSlim___::get_WaitHandle() {
  ThrowIfDisposed();
  if (m_eventObj == nullptr) {
    LazyInitializeEvent();
  }
  return m_eventObj;
}

Boolean ManualResetEventSlim___::get_IsSet() {
  return ExtractStatePortion(m_combinedState, Int32::MinValue) != 0;
}

void ManualResetEventSlim___::set_IsSet(Boolean value) {
  UpdateStateAtomically((value ? 1 : 0) << 31, Int32::MinValue);
}

Int32 ManualResetEventSlim___::get_SpinCount() {
  return ExtractStatePortionAndShiftRight(m_combinedState, 1073217536, 19);
}

void ManualResetEventSlim___::set_SpinCount(Int32 value) {
  m_combinedState = ((m_combinedState & -1073217537) | (value << 19));
}

Int32 ManualResetEventSlim___::get_Waiters() {
  return ExtractStatePortionAndShiftRight(m_combinedState, 524287, 0);
}

void ManualResetEventSlim___::set_Waiters(Int32 value) {
  if (value >= 524287) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_ManualResetEventSlim_ctor_TooManyWaiters(), 524287));
  }
  UpdateStateAtomically(value, 524287);
}

void ManualResetEventSlim___::ctor() {
}

void ManualResetEventSlim___::ctor(Boolean initialState) {
  Initialize(initialState, SpinWait::SpinCountforSpinBeforeWait);
}

void ManualResetEventSlim___::ctor(Boolean initialState, Int32 spinCount) {
  if (spinCount < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("spinCount");
  }
  if (spinCount > 2047) {
    rt::throw_exception<ArgumentOutOfRangeException>("spinCount", SR::Format(SR::get_ManualResetEventSlim_ctor_SpinCountOutOfRange(), 2047));
  }
  Initialize(initialState, spinCount);
}

void ManualResetEventSlim___::Initialize(Boolean initialState, Int32 spinCount) {
  m_combinedState = (initialState ? Int32::MinValue : 0);
  get_SpinCount((Environment::get_IsSingleProcessor() ? 1 : spinCount));
}

void ManualResetEventSlim___::EnsureLockObjectCreated() {
  if (m_lock == nullptr) {
    Object value = rt::newobj<Object>();
    Interlocked::CompareExchange(m_lock, value, nullptr);
  }
}

void ManualResetEventSlim___::LazyInitializeEvent() {
  Boolean isSet = get_IsSet();
  ManualResetEvent manualResetEvent = rt::newobj<ManualResetEvent>(isSet);
  if (Interlocked::CompareExchange(m_eventObj, manualResetEvent, (ManualResetEvent)nullptr) != nullptr) {
    manualResetEvent->Dispose();
    return;
  }
  Boolean isSet2 = get_IsSet();
  if (isSet2 == isSet) {
    return;
  }
  {
    rt::lock(manualResetEvent);
    if (m_eventObj == manualResetEvent) {
      manualResetEvent->Set();
    }
  }
}

void ManualResetEventSlim___::Set() {
  Set(false);
}

void ManualResetEventSlim___::Set(Boolean duringCancellation) {
  get_IsSet(true);
  if (get_Waiters() > 0) {
    {
      rt::lock(m_lock);
      Monitor::PulseAll(m_lock);
    }
  }
  ManualResetEvent eventObj = m_eventObj;
  if (eventObj == nullptr || duringCancellation) {
    return;
  }
  {
    rt::lock(eventObj);
    if (m_eventObj != nullptr) {
      m_eventObj->Set();
    }
  }
}

void ManualResetEventSlim___::Reset() {
  ThrowIfDisposed();
  if (m_eventObj != nullptr) {
    m_eventObj->Reset();
  }
  get_IsSet(false);
}

void ManualResetEventSlim___::Wait() {
  Wait(-1, CancellationToken::get_None());
}

void ManualResetEventSlim___::Wait(CancellationToken cancellationToken) {
  Wait(-1, cancellationToken);
}

Boolean ManualResetEventSlim___::Wait(TimeSpan timeout) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout");
  }
  return Wait((Int32)num, CancellationToken::get_None());
}

Boolean ManualResetEventSlim___::Wait(TimeSpan timeout, CancellationToken cancellationToken) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout");
  }
  return Wait((Int32)num, cancellationToken);
}

Boolean ManualResetEventSlim___::Wait(Int32 millisecondsTimeout) {
  return Wait(millisecondsTimeout, CancellationToken::get_None());
}

Boolean ManualResetEventSlim___::Wait(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  ThrowIfDisposed();
  cancellationToken.ThrowIfCancellationRequested();
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout");
  }
  if (!get_IsSet()) {
    if (millisecondsTimeout == 0) {
      return false;
    }
    UInt32 startTime = 0u;
    Boolean flag = false;
    Int32 num = millisecondsTimeout;
    if (millisecondsTimeout != -1) {
      startTime = TimeoutHelper::GetTime();
      flag = true;
    }
    Int32 spinCount = get_SpinCount();
    SpinWait spinWait = SpinWait();
    while (spinWait.get_Count() < spinCount) {
      spinWait.SpinOnce(-1);
      if (get_IsSet()) {
        return true;
      }
      if (spinWait.get_Count() >= 100 && spinWait.get_Count() % 10 == 0) {
        cancellationToken.ThrowIfCancellationRequested();
      }
    }
    EnsureLockObjectCreated();
    {
      cancellationToken.UnsafeRegister(s_cancellationTokenCallback, (ManualResetEventSlim)this);
      {
        rt::lock(m_lock);
        while (!get_IsSet()) {
          cancellationToken.ThrowIfCancellationRequested();
          if (flag) {
            num = TimeoutHelper::UpdateTimeOut(startTime, millisecondsTimeout);
            if (num <= 0) {
              return false;
            }
          }
          get_Waiters()++;
          if (get_IsSet()) {
            get_Waiters()--;
            return true;
          }
          try {
            if (!Monitor::Wait(m_lock, num)) {
              return false;
            }
          } catch (...) {
          } finally: {
            get_Waiters()--;
          }
        }
      }
    }
  }
  return true;
}

void ManualResetEventSlim___::Dispose() {
  Dispose(true);
  GC::SuppressFinalize((ManualResetEventSlim)this);
}

void ManualResetEventSlim___::Dispose(Boolean disposing) {
  if ((m_combinedState & 1073741824) != 0) {
    return;
  }
  m_combinedState |= 1073741824;
  if (!disposing) {
    return;
  }
  ManualResetEvent eventObj = m_eventObj;
  if (eventObj != nullptr) {
    {
      rt::lock(eventObj);
      eventObj->Dispose();
      m_eventObj = nullptr;
    }
  }
}

void ManualResetEventSlim___::ThrowIfDisposed() {
  if ((m_combinedState & 1073741824) != 0) {
    rt::throw_exception<ObjectDisposedException>(SR::get_ManualResetEventSlim_Disposed());
  }
}

void ManualResetEventSlim___::CancellationTokenCallback(Object obj) {
  ManualResetEventSlim manualResetEventSlim = (ManualResetEventSlim)obj;
  {
    rt::lock(manualResetEventSlim->m_lock);
    Monitor::PulseAll(manualResetEventSlim->m_lock);
  }
}

void ManualResetEventSlim___::UpdateStateAtomically(Int32 newBits, Int32 updateBitsMask) {
  SpinWait spinWait = SpinWait();
  while (true) {
    Int32 combinedState = m_combinedState;
    Int32 value = (combinedState & ~updateBitsMask) | newBits;
    if (Interlocked::CompareExchange(m_combinedState, value, combinedState) == combinedState) {
      break;
    }
    spinWait.SpinOnce(-1);
  }
}

Int32 ManualResetEventSlim___::ExtractStatePortionAndShiftRight(Int32 state, Int32 mask, Int32 rightBitShiftCount) {
  return (Int32)((UInt32)(state & mask) >> rightBitShiftCount);
}

Int32 ManualResetEventSlim___::ExtractStatePortion(Int32 state, Int32 mask) {
  return state & mask;
}

void ManualResetEventSlim___::cctor() {
  s_cancellationTokenCallback = &CancellationTokenCallback;
}

} // namespace System::Private::CoreLib::System::Threading::ManualResetEventSlimNamespace
