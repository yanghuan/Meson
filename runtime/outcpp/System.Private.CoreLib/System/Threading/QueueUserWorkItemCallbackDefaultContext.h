#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitCallback)
namespace QueueUserWorkItemCallbackDefaultContextNamespace {
CLASS_FORWARD(QueueUserWorkItemCallbackDefaultContext, T1, T2)
CLASS_(QueueUserWorkItemCallbackDefaultContext) {
  private: WaitCallback _callback;
  private: Object _state;
};
CLASS_(QueueUserWorkItemCallbackDefaultContext, TState) {
  private: Action<TState> _callback;
  private: TState _state;
};
} // namespace QueueUserWorkItemCallbackDefaultContextNamespace
template <class T1 = void, class T2 = void>
using QueueUserWorkItemCallbackDefaultContext = QueueUserWorkItemCallbackDefaultContextNamespace::QueueUserWorkItemCallbackDefaultContext<T1, T2>;
} // namespace System::Private::CoreLib::System::Threading
