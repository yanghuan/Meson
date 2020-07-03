#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
namespace FirstChanceExceptionEventArgsNamespace {
CLASS(FirstChanceExceptionEventArgs) {
  private: Exception Exception;
};
} // namespace FirstChanceExceptionEventArgsNamespace
using FirstChanceExceptionEventArgs = FirstChanceExceptionEventArgsNamespace::FirstChanceExceptionEventArgs;
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
