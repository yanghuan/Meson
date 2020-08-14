#include "HostExecutionContextManager-dep.h"

#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Threading/AsyncLocal-dep.h>
#include <System.Threading/System/SR-dep.h>
#include <System.Threading/System/Threading/HostExecutionContextManager-dep.h>

namespace System::Threading::System::Threading::HostExecutionContextManagerNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading;

void HostExecutionContextManager___::HostExecutionContextSwitcher___::ctor(HostExecutionContext currentContext) {
  _currentContext = currentContext;
  _asyncLocal = rt::newobj<AsyncLocal<Boolean>>();
  _asyncLocal->set_Value = true;
}

HostExecutionContext HostExecutionContextManager___::Capture() {
  return nullptr;
}

Object HostExecutionContextManager___::SetHostExecutionContext(HostExecutionContext hostExecutionContext) {
  if (hostExecutionContext == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_HostExecutionContextManager_InvalidOperation_NotNewCaptureContext());
  }
  HostExecutionContextSwitcher result = rt::newobj<HostExecutionContextSwitcher>(hostExecutionContext);
  t_currentContext = hostExecutionContext;
  return result;
}

void HostExecutionContextManager___::Revert(Object previousState) {
  HostExecutionContextSwitcher hostExecutionContextSwitcher = rt::as<HostExecutionContextSwitcher>(previousState);
  if (hostExecutionContextSwitcher == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::get_HostExecutionContextManager_InvalidOperation_CannotOverrideSetWithoutRevert());
  }
  if (t_currentContext != hostExecutionContextSwitcher->_currentContext || hostExecutionContextSwitcher->_asyncLocal == nullptr || !hostExecutionContextSwitcher->_asyncLocal->get_Value()) {
    rt::throw_exception<InvalidOperationException>(SR::get_HostExecutionContextManager_InvalidOperation_CannotUseSwitcherOtherThread());
  }
  hostExecutionContextSwitcher->_asyncLocal = nullptr;
  t_currentContext = nullptr;
}

void HostExecutionContextManager___::ctor() {
}

} // namespace System::Threading::System::Threading::HostExecutionContextManagerNamespace
