#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace ThreadExceptionEventArgsNamespace {
CLASS(ThreadExceptionEventArgs) {
  public: Exception get_Exception();
  private: Exception m_exception;
};
} // namespace ThreadExceptionEventArgsNamespace
using ThreadExceptionEventArgs = ThreadExceptionEventArgsNamespace::ThreadExceptionEventArgs;
} // namespace System::Private::CoreLib::System::Threading
