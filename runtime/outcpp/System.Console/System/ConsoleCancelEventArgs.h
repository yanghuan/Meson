#pragma once

#include <rt/GCObject.h>

namespace System::Console::System {
enum class ConsoleSpecialKey;
namespace ConsoleCancelEventArgsNamespace {
CLASS(ConsoleCancelEventArgs) {
  public: ConsoleSpecialKey get_SpecialKey();
  private: ConsoleSpecialKey _type;
};
} // namespace ConsoleCancelEventArgsNamespace
using ConsoleCancelEventArgs = ConsoleCancelEventArgsNamespace::ConsoleCancelEventArgs;
} // namespace System::Console::System
