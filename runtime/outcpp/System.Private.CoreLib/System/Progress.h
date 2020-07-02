#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(SynchronizationContext)
FORWARD(SendOrPostCallback)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
FORWARD_(EventHandler, T1, T2)
namespace ProgressNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(Progress, T) {
  protected: void OnReport(T value);
  private: void InvokeHandlers(Object state);
  private: SynchronizationContext _synchronizationContext;
  private: Action<T> _handler;
  private: SendOrPostCallback _invokeHandlers;
  private: EventHandler<T> ProgressChanged;
};
} // namespace ProgressNamespace
template <class T>
using Progress = ProgressNamespace::Progress<T>;
} // namespace System::Private::CoreLib::System
