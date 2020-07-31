#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Threading/QueueUserWorkItemCallbackBase.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(ExecutionContext)
FORWARD(WaitCallback)
namespace QueueUserWorkItemCallbackNamespace {
CLASS_FORWARD(QueueUserWorkItemCallback, T1, T2)
CLASS_(QueueUserWorkItemCallback) : public QueueUserWorkItemCallbackBase::in {
  private: WaitCallback _callback;
  private: Object _state;
  private: ExecutionContext _context;
  private: static Action<QueueUserWorkItemCallback<>> s_executionContextShim;
};
CLASS_(QueueUserWorkItemCallback, TState) : public QueueUserWorkItemCallbackBase::in {
  private: Action<TState> _callback;
  private: TState _state;
  private: ExecutionContext _context;
};
} // namespace QueueUserWorkItemCallbackNamespace
template <class T1 = void, class T2 = void>
using QueueUserWorkItemCallback = QueueUserWorkItemCallbackNamespace::QueueUserWorkItemCallback<T1, T2>;
} // namespace System::Private::CoreLib::System::Threading
