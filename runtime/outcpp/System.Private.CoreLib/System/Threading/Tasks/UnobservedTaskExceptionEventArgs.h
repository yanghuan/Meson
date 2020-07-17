#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(AggregateException)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
namespace UnobservedTaskExceptionEventArgsNamespace {
CLASS(UnobservedTaskExceptionEventArgs) {
  public: Boolean get_Observed();
  public: AggregateException get_Exception();
  public: void Ctor(AggregateException exception);
  public: void SetObserved();
  private: AggregateException m_exception;
  public: Boolean m_observed;
};
} // namespace UnobservedTaskExceptionEventArgsNamespace
using UnobservedTaskExceptionEventArgs = UnobservedTaskExceptionEventArgsNamespace::UnobservedTaskExceptionEventArgs;
} // namespace System::Private::CoreLib::System::Threading::Tasks
