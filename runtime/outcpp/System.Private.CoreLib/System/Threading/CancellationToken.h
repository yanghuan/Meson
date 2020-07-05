#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationTokenRegistration)
FORWARD(CancellationTokenSource)
FORWARD(WaitHandle)
namespace CancellationTokenNamespace {
struct CancellationToken {
  public: static CancellationToken get_None();
  public: Boolean get_IsCancellationRequested();
  public: Boolean get_CanBeCanceled();
  public: WaitHandle get_WaitHandle();
  public: CancellationTokenRegistration Register(Action<> callback);
  public: CancellationTokenRegistration Register(Action<> callback, Boolean useSynchronizationContext);
  public: CancellationTokenRegistration Register(Action<Object> callback, Object state);
  public: CancellationTokenRegistration Register(Action<Object> callback, Object state, Boolean useSynchronizationContext);
  public: CancellationTokenRegistration UnsafeRegister(Action<Object> callback, Object state);
  private: CancellationTokenRegistration Register(Action<Object> callback, Object state, Boolean useSynchronizationContext, Boolean useExecutionContext);
  public: Boolean Equals(CancellationToken other);
  public: Boolean Equals(Object other);
  public: Int32 GetHashCode();
  public: void ThrowIfCancellationRequested();
  private: void ThrowOperationCanceledException();
  private: CancellationTokenSource _source;
  private: static Action<Object> s_actionToActionObjShunt;
};
} // namespace CancellationTokenNamespace
using CancellationToken = CancellationTokenNamespace::CancellationToken;
} // namespace System::Private::CoreLib::System::Threading
