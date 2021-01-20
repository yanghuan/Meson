#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
FORWARD(SendOrPostCallback)
FORWARD(SynchronizationContext)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARD_(EventHandler)
FORWARD(IProgress, T)
namespace ProgressNamespace {
using namespace System::Threading;
CLASS(Progress, T) : public object {
  public: using interface = rt::TypeList<IProgress<T>>;
  public: void ctor();
  public: void ctor(Action<T> handler);
  protected: void OnReport(T value);
  private: void ReportOfIProgressT(T value);
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
