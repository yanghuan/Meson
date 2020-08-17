#include "ThreadHelper-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/Threading/ParameterizedThreadStart-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadHelper-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadStart-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadHelperNamespace {
using namespace System::Globalization;

void ThreadHelper___::ctor(Delegate start) {
  _start = start;
}

void ThreadHelper___::SetExecutionContextHelper(ExecutionContext ec) {
  _executionContext = ec;
}

void ThreadHelper___::ThreadStart_Context(Object state) {
  ThreadHelper threadHelper = (ThreadHelper)state;
  threadHelper->InitializeCulture();
  ThreadStart threadStart = rt::as<ThreadStart>(threadHelper->_start);
  if (threadStart != nullptr) {
    threadStart();
  } else {
    ((ParameterizedThreadStart)threadHelper->_start)(threadHelper->_startArg);
  }
}

void ThreadHelper___::InitializeCulture() {
  if (_startCulture != nullptr) {
    CultureInfo::in::set_CurrentCulture(_startCulture);
    _startCulture = nullptr;
  }
  if (_startUICulture != nullptr) {
    CultureInfo::in::set_CurrentUICulture(_startUICulture);
    _startUICulture = nullptr;
  }
}

void ThreadHelper___::ThreadStart(Object obj) {
  _startArg = obj;
  ExecutionContext executionContext = _executionContext;
  if (executionContext != nullptr) {
    ExecutionContext::in::RunInternal(executionContext, s_threadStartContextCallback, (ThreadHelper)this);
    return;
  }
  InitializeCulture();
  ((ParameterizedThreadStart)_start)(obj);
}

void ThreadHelper___::ThreadStart() {
  ExecutionContext executionContext = _executionContext;
  if (executionContext != nullptr) {
    ExecutionContext::in::RunInternal(executionContext, s_threadStartContextCallback, (ThreadHelper)this);
    return;
  }
  InitializeCulture();
  ((ThreadStart)_start)();
}

void ThreadHelper___::cctor() {
  s_threadStartContextCallback = ThreadStart_Context;
}

} // namespace System::Private::CoreLib::System::Threading::ThreadHelperNamespace
