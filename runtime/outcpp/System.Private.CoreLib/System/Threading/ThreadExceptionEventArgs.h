#pragma once

#include <System.Private.CoreLib/System/EventArgs.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace ThreadExceptionEventArgsNamespace {
CLASS(ThreadExceptionEventArgs) : public EventArgs::in {
  public: Exception get_Exception();
  public: void ctor(Exception t);
  private: Exception m_exception;
};
} // namespace ThreadExceptionEventArgsNamespace
using ThreadExceptionEventArgs = ThreadExceptionEventArgsNamespace::ThreadExceptionEventArgs;
} // namespace System::Private::CoreLib::System::Threading
