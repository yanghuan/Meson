#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARDS(Boolean)
FORWARD(IDisposable)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
FORWARD(ManualResetEvent)
FORWARD(WaitHandle)
namespace ManualResetEventSlimNamespace {
CLASS(ManualResetEventSlim) : public object {
  public: using interface = rt::TypeList<IDisposable>;
  public: WaitHandle get_WaitHandle();
  public: Boolean get_IsSet();
  private: void set_IsSet(Boolean value);
  public: Int32 get_SpinCount();
  private: void set_SpinCount(Int32 value);
  private: Int32 get_Waiters();
  private: void set_Waiters(Int32 value);
  public: void ctor();
  public: void ctor(Boolean initialState);
  public: void ctor(Boolean initialState, Int32 spinCount);
  private: void Initialize(Boolean initialState, Int32 spinCount);
  private: void EnsureLockObjectCreated();
  private: void LazyInitializeEvent();
  public: void Set();
  private: void Set(Boolean duringCancellation);
  public: void Reset();
  public: void Wait();
  public: void Wait(CancellationToken cancellationToken);
  public: Boolean Wait(TimeSpan timeout);
  public: Boolean Wait(TimeSpan timeout, CancellationToken cancellationToken);
  public: Boolean Wait(Int32 millisecondsTimeout);
  public: Boolean Wait(Int32 millisecondsTimeout, CancellationToken cancellationToken);
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  private: void ThrowIfDisposed();
  private: static void CancellationTokenCallback(Object obj);
  private: void UpdateStateAtomically(Int32 newBits, Int32 updateBitsMask);
  private: static Int32 ExtractStatePortionAndShiftRight(Int32 state, Int32 mask, Int32 rightBitShiftCount);
  private: static Int32 ExtractStatePortion(Int32 state, Int32 mask);
  public: static void cctor();
  private: Object m_lock;
  private: ManualResetEvent m_eventObj;
  private: Int32 m_combinedState;
  private: static Action<Object> s_cancellationTokenCallback;
};
} // namespace ManualResetEventSlimNamespace
using ManualResetEventSlim = ManualResetEventSlimNamespace::ManualResetEventSlim;
} // namespace System::Private::CoreLib::System::Threading
