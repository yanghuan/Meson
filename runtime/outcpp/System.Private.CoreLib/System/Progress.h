#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(SendOrPostCallback)
FORWARD(SynchronizationContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17)
FORWARD_(EventHandler, T1, T2)
FORWARD(IProgress, T)
namespace ProgressNamespace {
using namespace System::Threading;
CLASS(Progress, T) : public object {
  public: using interface = rt::TypeList<IProgress<T>>;
  public: void ctor();
  public: void ctor(Action<T> handler);
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
