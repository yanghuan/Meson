#include "Debugger-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Debugger-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::DebuggerNamespace {
void Debugger::CrossThreadDependencyNotification___::ctor() {
}

void Debugger::Break() {
  BreakInternal();
}

Boolean Debugger::Launch() {
  if (!get_IsAttached()) {
    return LaunchInternal();
  }
  return true;
}

void Debugger::NotifyOfCrossThreadDependencySlow() {
  CustomNotification(rt::newobj<CrossThreadDependencyNotification>());
}

void Debugger::NotifyOfCrossThreadDependency() {
  if (get_IsAttached()) {
    NotifyOfCrossThreadDependencySlow();
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::DebuggerNamespace
