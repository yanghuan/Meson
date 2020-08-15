#include "Barrier-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Math-dep.h>
#include <System.Private.CoreLib/System/ObjectDisposedException-dep.h>
#include <System.Private.CoreLib/System/OperationCanceledException-dep.h>
#include <System.Private.CoreLib/System/Threading/CancellationToken-dep.h>
#include <System.Private.CoreLib/System/Threading/ContextCallback-dep.h>
#include <System.Private.CoreLib/System/Threading/ExecutionContext-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/ManualResetEventSlim-dep.h>
#include <System.Private.CoreLib/System/Threading/SpinWait-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Threading/System/SR-dep.h>
#include <System.Threading/System/Threading/Barrier-dep.h>
#include <System.Threading/System/Threading/BarrierPostPhaseException-dep.h>
#include <System.Threading/System/Threading/CdsSyncEtwBCLProvider-dep.h>

namespace System::Threading::System::Threading::BarrierNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading;

Int32 Barrier___::get_ParticipantsRemaining() {
  Int32 currentTotalCount = _currentTotalCount;
  Int32 num = currentTotalCount & 32767;
  Int32 num2 = (currentTotalCount & 2147418112) >> 16;
  return num - num2;
}

Int32 Barrier___::get_ParticipantCount() {
  return _currentTotalCount & 32767;
}

Int64 Barrier___::get_CurrentPhaseNumber() {
  return Volatile::Read(_currentPhase);
}

void Barrier___::set_CurrentPhaseNumber(Int64 value) {
  Volatile::Write(_currentPhase, value);
}

void Barrier___::ctor(Int32 participantCount) {
}

void Barrier___::ctor(Int32 participantCount, Action<Barrier> postPhaseAction) {
  if (participantCount < 0 || participantCount > 32767) {
    rt::throw_exception<ArgumentOutOfRangeException>("participantCount", participantCount, SR::get_Barrier_ctor_ArgumentOutOfRange());
  }
  _currentTotalCount = participantCount;
  _postPhaseAction = postPhaseAction;
  _oddEvent = rt::newobj<ManualResetEventSlim>(true);
  _evenEvent = rt::newobj<ManualResetEventSlim>(false);
  if (postPhaseAction != nullptr) {
    _ownerThreadContext = ExecutionContext::in::Capture();
  }
  _actionCallerID = 0;
}

void Barrier___::GetCurrentTotal(Int32 currentTotal, Int32& current, Int32& total, Boolean& sense) {
  total = (currentTotal & 32767);
  current = (currentTotal & 2147418112) >> 16;
  sense = (((currentTotal & Int32::MinValue) == 0) ? true : false);
}

Boolean Barrier___::SetCurrentTotal(Int32 currentTotal, Int32 current, Int32 total, Boolean sense) {
  Int32 num = (current << 16) | total;
  if (!sense) {
    num |= Int32::MinValue;
  }
  return Interlocked::CompareExchange(_currentTotalCount, num, currentTotal) == currentTotal;
}

Int64 Barrier___::AddParticipant() {
  try {
    return AddParticipants(1);
  } catch (ArgumentOutOfRangeException) {
  }
}

Int64 Barrier___::AddParticipants(Int32 participantCount) {
  ThrowIfDisposed();
  if (participantCount < 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("participantCount", participantCount, SR::get_Barrier_AddParticipants_NonPositive_ArgumentOutOfRange());
  }
  if (participantCount > 32767) {
    rt::throw_exception<ArgumentOutOfRangeException>("participantCount", SR::get_Barrier_AddParticipants_Overflow_ArgumentOutOfRange());
  }
  if (_actionCallerID != 0 && Environment::get_CurrentManagedThreadId() == _actionCallerID) {
    rt::throw_exception<InvalidOperationException>(SR::get_Barrier_InvalidOperation_CalledFromPHA());
  }
  SpinWait spinWait = SpinWait();
  Int64 num = 0;
  Boolean sense;
  while (true) {
    Int32 currentTotalCount = _currentTotalCount;
    Int32 current;
    Int32 total;
    GetCurrentTotal(currentTotalCount, current, total, sense);
    if (participantCount + total > 32767) {
      rt::throw_exception<ArgumentOutOfRangeException>("participantCount", SR::get_Barrier_AddParticipants_Overflow_ArgumentOutOfRange());
    }
    if (SetCurrentTotal(currentTotalCount, current, total + participantCount, sense)) {
      break;
    }
    spinWait.SpinOnce(-1);
  }
  Int64 currentPhaseNumber = get_CurrentPhaseNumber();
  num = ((sense != (currentPhaseNumber % 2 == 0)) ? (currentPhaseNumber + 1) : currentPhaseNumber);
  if (num != currentPhaseNumber) {
    if (sense) {
      _oddEvent->Wait();
    } else {
      _evenEvent->Wait();
    }
  } else if (sense && _evenEvent->get_IsSet()) {
    _evenEvent->Reset();
  } else if (!sense && _oddEvent->get_IsSet()) {
    _oddEvent->Reset();
  }


  return num;
}

void Barrier___::RemoveParticipant() {
  RemoveParticipants(1);
}

void Barrier___::RemoveParticipants(Int32 participantCount) {
  ThrowIfDisposed();
  if (participantCount < 1) {
    rt::throw_exception<ArgumentOutOfRangeException>("participantCount", participantCount, SR::get_Barrier_RemoveParticipants_NonPositive_ArgumentOutOfRange());
  }
  if (_actionCallerID != 0 && Environment::get_CurrentManagedThreadId() == _actionCallerID) {
    rt::throw_exception<InvalidOperationException>(SR::get_Barrier_InvalidOperation_CalledFromPHA());
  }
  SpinWait spinWait = SpinWait();
  while (true) {
    Int32 currentTotalCount = _currentTotalCount;
    Int32 current;
    Int32 total;
    Boolean sense;
    GetCurrentTotal(currentTotalCount, current, total, sense);
    if (total < participantCount) {
      rt::throw_exception<ArgumentOutOfRangeException>("participantCount", SR::get_Barrier_RemoveParticipants_ArgumentOutOfRange());
    }
    if (total - participantCount < current) {
      rt::throw_exception<InvalidOperationException>(SR::get_Barrier_RemoveParticipants_InvalidOperation());
    }
    Int32 num = total - participantCount;
    if (num > 0 && current == num) {
      if (SetCurrentTotal(currentTotalCount, 0, total - participantCount, !sense)) {
        FinishPhase(sense);
        break;
      }
    } else if (SetCurrentTotal(currentTotalCount, current, total - participantCount, sense)) {
      break;
    }

    spinWait.SpinOnce(-1);
  }
}

void Barrier___::SignalAndWait() {
  SignalAndWait(CancellationToken::get_None());
}

void Barrier___::SignalAndWait(CancellationToken cancellationToken) {
  SignalAndWait(-1, cancellationToken);
}

Boolean Barrier___::SignalAndWait(TimeSpan timeout) {
  return SignalAndWait(timeout, CancellationToken::get_None());
}

Boolean Barrier___::SignalAndWait(TimeSpan timeout, CancellationToken cancellationToken) {
  Int64 num = (Int64)timeout.get_TotalMilliseconds();
  if (num < -1 || num > Int32::MaxValue) {
    rt::throw_exception<ArgumentOutOfRangeException>("timeout", timeout, SR::get_Barrier_SignalAndWait_ArgumentOutOfRange());
  }
  return SignalAndWait((Int32)timeout.get_TotalMilliseconds(), cancellationToken);
}

Boolean Barrier___::SignalAndWait(Int32 millisecondsTimeout) {
  return SignalAndWait(millisecondsTimeout, CancellationToken::get_None());
}

Boolean Barrier___::SignalAndWait(Int32 millisecondsTimeout, CancellationToken cancellationToken) {
  ThrowIfDisposed();
  cancellationToken.ThrowIfCancellationRequested();
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout", millisecondsTimeout, SR::get_Barrier_SignalAndWait_ArgumentOutOfRange());
  }
  if (_actionCallerID != 0 && Environment::get_CurrentManagedThreadId() == _actionCallerID) {
    rt::throw_exception<InvalidOperationException>(SR::get_Barrier_InvalidOperation_CalledFromPHA());
  }
  SpinWait spinWait = SpinWait();
  Int32 current;
  Int32 total;
  Boolean sense;
  Int64 currentPhaseNumber;
  while (true) {
    Int32 currentTotalCount = _currentTotalCount;
    GetCurrentTotal(currentTotalCount, current, total, sense);
    currentPhaseNumber = get_CurrentPhaseNumber();
    if (total == 0) {
      rt::throw_exception<InvalidOperationException>(SR::get_Barrier_SignalAndWait_InvalidOperation_ZeroTotal());
    }
    if (current == 0 && sense != (get_CurrentPhaseNumber() % 2 == 0)) {
      rt::throw_exception<InvalidOperationException>(SR::get_Barrier_SignalAndWait_InvalidOperation_ThreadsExceeded());
    }
    if (current + 1 == total) {
      if (SetCurrentTotal(currentTotalCount, 0, total, !sense)) {
        if (CdsSyncEtwBCLProvider::in::Log->IsEnabled()) {
          CdsSyncEtwBCLProvider::in::Log->Barrier_PhaseFinished(sense, get_CurrentPhaseNumber());
        }
        FinishPhase(sense);
        return true;
      }
    } else if (SetCurrentTotal(currentTotalCount, current + 1, total, sense)) {
      break;
    }

    spinWait.SpinOnce(-1);
  }
  ManualResetEventSlim currentPhaseEvent = sense ? _evenEvent : _oddEvent;
  Boolean flag = false;
  Boolean flag2 = false;
  try {
    flag2 = DiscontinuousWait(currentPhaseEvent, millisecondsTimeout, cancellationToken, currentPhaseNumber);
  } catch (OperationCanceledException) {
  } catch (ObjectDisposedException) {
  }
  if (!flag2) {
    spinWait.Reset();
    while (true) {
      Int32 currentTotalCount = _currentTotalCount;
      Boolean sense2;
      GetCurrentTotal(currentTotalCount, current, total, sense2);
      if (currentPhaseNumber < get_CurrentPhaseNumber() || sense != sense2) {
        break;
      }
      if (SetCurrentTotal(currentTotalCount, current - 1, total, sense)) {
        if (flag) {
          rt::throw_exception<OperationCanceledException>(SR::get_Common_OperationCanceled(), cancellationToken);
        }
        return false;
      }
      spinWait.SpinOnce(-1);
    }
    WaitCurrentPhase(currentPhaseEvent, currentPhaseNumber);
  }
  if (_exception != nullptr) {
    rt::throw_exception<BarrierPostPhaseException>(_exception);
  }
  return true;
}

void Barrier___::FinishPhase(Boolean observedSense) {
  if (_postPhaseAction != nullptr) {
    try {
      _actionCallerID = Environment::get_CurrentManagedThreadId();
      if (_ownerThreadContext != nullptr) {
        ContextCallback callback = InvokePostPhaseAction;
        ExecutionContext::in::Run(_ownerThreadContext, callback, (Barrier)this);
      } else {
        _postPhaseAction((Barrier)this);
      }
      _exception = nullptr;
    } catch (Exception exception) {
    } finally: {
      _actionCallerID = 0;
      SetResetEvents(observedSense);
      if (_exception != nullptr) {
        rt::throw_exception<BarrierPostPhaseException>(_exception);
      }
    }
  } else {
    SetResetEvents(observedSense);
  }
}

void Barrier___::InvokePostPhaseAction(Object obj) {
  Barrier barrier = (Barrier)obj;
  barrier->_postPhaseAction(barrier);
}

void Barrier___::SetResetEvents(Boolean observedSense) {
  get_CurrentPhaseNumber()++;
  if (observedSense) {
    _oddEvent->Reset();
    _evenEvent->Set();
  } else {
    _evenEvent->Reset();
    _oddEvent->Set();
  }
}

void Barrier___::WaitCurrentPhase(ManualResetEventSlim currentPhaseEvent, Int64 observedPhase) {
  SpinWait spinWait = SpinWait();
  while (!currentPhaseEvent->get_IsSet() && get_CurrentPhaseNumber() - observedPhase <= 1) {
    spinWait.SpinOnce();
  }
}

Boolean Barrier___::DiscontinuousWait(ManualResetEventSlim currentPhaseEvent, Int32 totalTimeout, CancellationToken token, Int64 observedPhase) {
  Int32 num = 100;
  Int32 num2 = 10000;
  while (observedPhase == get_CurrentPhaseNumber()) {
    Int32 num3 = (totalTimeout == -1) ? num : Math::Min(num, totalTimeout);
    if (currentPhaseEvent->Wait(num3, token)) {
      return true;
    }
    if (totalTimeout != -1) {
      totalTimeout -= num3;
      if (totalTimeout <= 0) {
        return false;
      }
    }
    num = ((num >= num2) ? num2 : Math::Min(num << 1, num2));
  }
  WaitCurrentPhase(currentPhaseEvent, observedPhase);
  return true;
}

void Barrier___::Dispose() {
  if (_actionCallerID != 0 && Environment::get_CurrentManagedThreadId() == _actionCallerID) {
    rt::throw_exception<InvalidOperationException>(SR::get_Barrier_InvalidOperation_CalledFromPHA());
  }
  Dispose(true);
  GC::SuppressFinalize((Barrier)this);
}

void Barrier___::Dispose(Boolean disposing) {
  if (!_disposed) {
    if (disposing) {
      _oddEvent->Dispose();
      _evenEvent->Dispose();
    }
    _disposed = true;
  }
}

void Barrier___::ThrowIfDisposed() {
  if (_disposed) {
    rt::throw_exception<ObjectDisposedException>("Barrier", SR::get_Barrier_Dispose());
  }
}

} // namespace System::Threading::System::Threading::BarrierNamespace
