#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerVisualizerAttributeNamespace {
CLASS(DebuggerVisualizerAttribute) {
  public: Type get_Target();
  public: void set_Target(Type value);
  private: Type _target;
};
} // namespace DebuggerVisualizerAttributeNamespace
using DebuggerVisualizerAttribute = DebuggerVisualizerAttributeNamespace::DebuggerVisualizerAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
