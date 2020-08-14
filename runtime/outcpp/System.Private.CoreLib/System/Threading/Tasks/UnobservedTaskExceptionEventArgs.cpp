#include "UnobservedTaskExceptionEventArgs-dep.h"

namespace System::Private::CoreLib::System::Threading::Tasks::UnobservedTaskExceptionEventArgsNamespace {
Boolean UnobservedTaskExceptionEventArgs___::get_Observed() {
  return m_observed;
}

AggregateException UnobservedTaskExceptionEventArgs___::get_Exception() {
  return m_exception;
}

void UnobservedTaskExceptionEventArgs___::ctor(AggregateException exception) {
  m_exception = exception;
}

void UnobservedTaskExceptionEventArgs___::SetObserved() {
  m_observed = true;
}

} // namespace System::Private::CoreLib::System::Threading::Tasks::UnobservedTaskExceptionEventArgsNamespace
