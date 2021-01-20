#pragma once

#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallbackBase.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitCallback)
namespace QueueUserWorkItemCallbackDefaultContextNamespace {
CLASS_FORWARD(QueueUserWorkItemCallbackDefaultContext)
CLASS_(QueueUserWorkItemCallbackDefaultContext) : public QueueUserWorkItemCallbackBase::in {
  public: void ctor(WaitCallback callback, Object state);
  public: void Execute();
  private: WaitCallback _callback;
  private: Object _state;
};
CLASS_(QueueUserWorkItemCallbackDefaultContext, TState) : public QueueUserWorkItemCallbackBase::in {
  public: void ctor(Action<TState> callback, TState state);
  public: void Execute();
  private: Action<TState> _callback;
  private: TState _state;
};
} // namespace QueueUserWorkItemCallbackDefaultContextNamespace
template <class ...T>
using QueueUserWorkItemCallbackDefaultContext = QueueUserWorkItemCallbackDefaultContextNamespace::QueueUserWorkItemCallbackDefaultContext<T...>;
} // namespace System::Private::CoreLib::System::Threading
