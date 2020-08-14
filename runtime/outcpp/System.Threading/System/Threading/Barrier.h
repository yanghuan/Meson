#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD(Exception)
FORWARD(IDisposable)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
FORWARD_(ContextCallback, T1, T2)
FORWARD(ExecutionContext)
FORWARD(ManualResetEventSlim)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Threading::System::Threading {
namespace BarrierNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(Barrier) : public Object::in {
  public: using interface = rt::TypeList<IDisposable>;
  public: Int32 get_ParticipantsRemaining();
  public: Int32 get_ParticipantCount();
  public: Int64 get_CurrentPhaseNumber();
  public: void set_CurrentPhaseNumber(Int64 value);
  public: void ctor(Int32 participantCount);
  public: void ctor(Int32 participantCount, Action<Barrier> postPhaseAction);
  private: void GetCurrentTotal(Int32 currentTotal, Int32& current, Int32& total, Boolean& sense);
  private: Boolean SetCurrentTotal(Int32 currentTotal, Int32 current, Int32 total, Boolean sense);
  public: Int64 AddParticipant();
  public: Int64 AddParticipants(Int32 participantCount);
  public: void RemoveParticipant();
  public: void RemoveParticipants(Int32 participantCount);
  public: void SignalAndWait();
  public: void SignalAndWait(CancellationToken cancellationToken);
  public: Boolean SignalAndWait(TimeSpan timeout);
  public: Boolean SignalAndWait(TimeSpan timeout, CancellationToken cancellationToken);
  public: Boolean SignalAndWait(Int32 millisecondsTimeout);
  public: Boolean SignalAndWait(Int32 millisecondsTimeout, CancellationToken cancellationToken);
  private: void FinishPhase(Boolean observedSense);
  private: static void InvokePostPhaseAction(Object obj);
  private: void SetResetEvents(Boolean observedSense);
  private: void WaitCurrentPhase(ManualResetEventSlim currentPhaseEvent, Int64 observedPhase);
  private: Boolean DiscontinuousWait(ManualResetEventSlim currentPhaseEvent, Int32 totalTimeout, CancellationToken token, Int64 observedPhase);
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  private: void ThrowIfDisposed();
  private: Int32 _currentTotalCount;
  private: Int64 _currentPhase;
  private: Boolean _disposed;
  private: ManualResetEventSlim _oddEvent;
  private: ManualResetEventSlim _evenEvent;
  private: ExecutionContext _ownerThreadContext;
  private: static ContextCallback<> s_invokePostPhaseAction;
  private: Action<Barrier> _postPhaseAction;
  private: Exception _exception;
  private: Int32 _actionCallerID;
};
} // namespace BarrierNamespace
using Barrier = BarrierNamespace::Barrier;
} // namespace System::Threading::System::Threading
