#pragma once

#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallbackBase.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(ExecutionContext)
FORWARD(WaitCallback)
namespace QueueUserWorkItemCallbackNamespace {
CLASS_FORWARD(QueueUserWorkItemCallback)
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
template <class ...T>
using QueueUserWorkItemCallback = QueueUserWorkItemCallbackNamespace::QueueUserWorkItemCallback<T...>;
} // namespace System::Private::CoreLib::System::Threading
