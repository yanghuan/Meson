#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/EventArgs.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
namespace FirstChanceExceptionEventArgsNamespace {
CLASS(FirstChanceExceptionEventArgs) : public EventArgs::in {
  public: Exception get_Exception() { return Exception; }
  public: void Ctor(Exception exception);
  private: Exception Exception;
};
} // namespace FirstChanceExceptionEventArgsNamespace
using FirstChanceExceptionEventArgs = FirstChanceExceptionEventArgsNamespace::FirstChanceExceptionEventArgs;
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
