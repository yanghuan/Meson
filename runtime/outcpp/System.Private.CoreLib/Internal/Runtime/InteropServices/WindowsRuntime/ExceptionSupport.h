#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::Internal::Runtime::InteropServices::WindowsRuntime {
namespace ExceptionSupportNamespace {
using namespace ::System::Private::CoreLib::System;
class ExceptionSupport {
  public: static Exception AttachRestrictedErrorInfo(Exception e);
  public: static Boolean ReportUnhandledError(Exception ex);
};
} // namespace ExceptionSupportNamespace
using ExceptionSupport = ExceptionSupportNamespace::ExceptionSupport;
} // namespace System::Private::CoreLib::Internal::Runtime::InteropServices::WindowsRuntime
