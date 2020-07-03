#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Console::System {
enum class ConsoleSpecialKey;
namespace ConsoleCancelEventArgsNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(ConsoleCancelEventArgs) {
  public: ConsoleSpecialKey get_SpecialKey();
  private: ConsoleSpecialKey _type;
  private: Boolean Cancel;
};
} // namespace ConsoleCancelEventArgsNamespace
using ConsoleCancelEventArgs = ConsoleCancelEventArgsNamespace::ConsoleCancelEventArgs;
} // namespace System::Console::System
