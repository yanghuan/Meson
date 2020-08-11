#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/EventArgs.h>

namespace System::Console::System {
enum class ConsoleSpecialKey : int32_t;
namespace ConsoleCancelEventArgsNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(ConsoleCancelEventArgs) : public EventArgs::in {
  public: Boolean get_Cancel() { return Cancel; }
  public: void set_Cancel(Boolean value) { Cancel = value; }
  public: ConsoleSpecialKey get_SpecialKey();
  public: void ctor(ConsoleSpecialKey type);
  private: ConsoleSpecialKey _type;
  private: Boolean Cancel;
};
} // namespace ConsoleCancelEventArgsNamespace
using ConsoleCancelEventArgs = ConsoleCancelEventArgsNamespace::ConsoleCancelEventArgs;
} // namespace System::Console::System
