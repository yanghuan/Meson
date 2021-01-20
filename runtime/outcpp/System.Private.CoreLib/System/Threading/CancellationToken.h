#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationTokenRegistration)
FORWARD(CancellationTokenSource)
FORWARD(WaitHandle)
namespace CancellationTokenNamespace {
struct CancellationToken : public valueType<CancellationToken> {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _cctor_b__26_0(Object obj);
    public: static __c __9;
  };
  public: static CancellationToken get_None();
  public: Boolean get_IsCancellationRequested();
  public: Boolean get_CanBeCanceled();
  public: WaitHandle get_WaitHandle();
  public: explicit CancellationToken(CancellationTokenSource source);
  public: explicit CancellationToken(Boolean canceled);
  public: CancellationTokenRegistration Register(Action<> callback);
  public: CancellationTokenRegistration Register(Action<> callback, Boolean useSynchronizationContext);
  public: CancellationTokenRegistration Register(Action<Object> callback, Object state);
  public: CancellationTokenRegistration Register(Action<Object> callback, Object state, Boolean useSynchronizationContext);
  public: CancellationTokenRegistration UnsafeRegister(Action<Object> callback, Object state);
  private: CancellationTokenRegistration Register(Action<Object> callback, Object state, Boolean useSynchronizationContext, Boolean useExecutionContext);
  public: Boolean Equals(CancellationToken other);
  public: Boolean Equals(Object other);
  public: Int32 GetHashCode();
  public: static Boolean op_Equality(CancellationToken left, CancellationToken right);
  public: static Boolean op_Inequality(CancellationToken left, CancellationToken right);
  public: void ThrowIfCancellationRequested();
  private: void ThrowOperationCanceledException();
  public: static void cctor();
  public: explicit CancellationToken() {}
  private: CancellationTokenSource _source;
  private: static Action<Object> s_actionToActionObjShunt;
};
} // namespace CancellationTokenNamespace
using CancellationToken = CancellationTokenNamespace::CancellationToken;
} // namespace System::Private::CoreLib::System::Threading
