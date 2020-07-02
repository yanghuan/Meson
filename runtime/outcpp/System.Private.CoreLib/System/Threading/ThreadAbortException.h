#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace ThreadAbortExceptionNamespace {
CLASS(ThreadAbortException) {
  public: Object get_ExceptionState();
};
} // namespace ThreadAbortExceptionNamespace
using ThreadAbortException = ThreadAbortExceptionNamespace::ThreadAbortException;
} // namespace System::Private::CoreLib::System::Threading
