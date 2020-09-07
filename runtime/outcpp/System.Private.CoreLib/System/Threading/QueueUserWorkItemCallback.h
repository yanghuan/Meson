#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallbackBase.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(ExecutionContext)
FORWARD(WaitCallback)
namespace QueueUserWorkItemCallbackNamespace {
CLASS_FORWARD(QueueUserWorkItemCallback, T1, T2)
CLASS_(QueueUserWorkItemCallback) : public QueueUserWorkItemCallbackBase::in {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _cctor_b__6_0(QueueUserWorkItemCallback<> quwi);
    public: static __c __9;
  };
  public: void ctor(WaitCallback callback, Object state, ExecutionContext context);
  public: void Execute();
  public: static void cctor();
  private: WaitCallback _callback;
  private: Object _state;
  private: ExecutionContext _context;
  private: static Action<QueueUserWorkItemCallback<>> s_executionContextShim;
};
CLASS_(QueueUserWorkItemCallback, TState) : public QueueUserWorkItemCallbackBase::in {
  public: void ctor(Action<TState> callback, TState state, ExecutionContext context);
  public: void Execute();
  private: Action<TState> _callback;
  private: TState _state;
  private: ExecutionContext _context;
};
} // namespace QueueUserWorkItemCallbackNamespace
template <class T1 = void, class T2 = void>
using QueueUserWorkItemCallback = QueueUserWorkItemCallbackNamespace::QueueUserWorkItemCallback<T1, T2>;
} // namespace System::Private::CoreLib::System::Threading
