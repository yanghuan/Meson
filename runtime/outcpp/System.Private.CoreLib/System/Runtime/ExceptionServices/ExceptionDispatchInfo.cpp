#include "ExceptionDispatchInfo-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Runtime/ExceptionServices/ExceptionDispatchInfo-dep.h>

namespace System::Private::CoreLib::System::Runtime::ExceptionServices::ExceptionDispatchInfoNamespace {
Exception ExceptionDispatchInfo___::get_SourceException() {
  return _exception;
}

void ExceptionDispatchInfo___::ctor(Exception exception) {
  _exception = exception;
  _dispatchState = exception->CaptureDispatchState();
}

ExceptionDispatchInfo ExceptionDispatchInfo___::Capture(Exception source) {
  if (source == nullptr) {
    rt::throw_exception<ArgumentNullException>("source");
  }
  return rt::newobj<ExceptionDispatchInfo>(source);
}

void ExceptionDispatchInfo___::Throw() {
  _exception->RestoreDispatchState(_dispatchState);
  rt::throw_exception(_exception);
}

void ExceptionDispatchInfo___::Throw(Exception source) {
  Capture(source)->Throw();
}

Exception ExceptionDispatchInfo___::SetCurrentStackTrace(Exception source) {
  if (source == nullptr) {
    rt::throw_exception<ArgumentNullException>("source");
  }
  source->SetCurrentStackTrace();
  return source;
}

} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices::ExceptionDispatchInfoNamespace
