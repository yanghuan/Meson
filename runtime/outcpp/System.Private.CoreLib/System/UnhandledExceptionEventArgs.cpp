#include "UnhandledExceptionEventArgs-dep.h"

namespace System::Private::CoreLib::System::UnhandledExceptionEventArgsNamespace {
Object UnhandledExceptionEventArgs___::get_ExceptionObject() {
  return _exception;
}

Boolean UnhandledExceptionEventArgs___::get_IsTerminating() {
  return _isTerminating;
}

void UnhandledExceptionEventArgs___::ctor(Object exception, Boolean isTerminating) {
  _exception = exception;
  _isTerminating = isTerminating;
}

} // namespace System::Private::CoreLib::System::UnhandledExceptionEventArgsNamespace
