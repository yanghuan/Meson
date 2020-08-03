#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/EventArgs.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
namespace UnhandledExceptionEventArgsNamespace {
CLASS(UnhandledExceptionEventArgs) : public EventArgs::in {
  public: Object get_ExceptionObject();
  public: Boolean get_IsTerminating();
  public: void Ctor(Object exception, Boolean isTerminating);
  private: Object _exception;
  private: Boolean _isTerminating;
};
} // namespace UnhandledExceptionEventArgsNamespace
using UnhandledExceptionEventArgs = UnhandledExceptionEventArgsNamespace::UnhandledExceptionEventArgs;
} // namespace System::Private::CoreLib::System
