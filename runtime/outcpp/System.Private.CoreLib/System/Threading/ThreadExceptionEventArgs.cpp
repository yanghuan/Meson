#include "ThreadExceptionEventArgs-dep.h"

namespace System::Private::CoreLib::System::Threading::ThreadExceptionEventArgsNamespace {
Exception ThreadExceptionEventArgs___::get_Exception() {
  return m_exception;
}

void ThreadExceptionEventArgs___::ctor(Exception t) {
  m_exception = t;
}

} // namespace System::Private::CoreLib::System::Threading::ThreadExceptionEventArgsNamespace
