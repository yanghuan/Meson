#include "DebuggerVisualizerAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::DebuggerVisualizerAttributeNamespace {
Type DebuggerVisualizerAttribute___::get_Target() {
  return _target;
}

void DebuggerVisualizerAttribute___::set_Target(Type value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  TargetTypeName = value->get_AssemblyQualifiedName();
  _target = value;
}

void DebuggerVisualizerAttribute___::ctor(String visualizerTypeName) {
  VisualizerTypeName = visualizerTypeName;
}

void DebuggerVisualizerAttribute___::ctor(String visualizerTypeName, String visualizerObjectSourceTypeName) {
  VisualizerTypeName = visualizerTypeName;
  VisualizerObjectSourceTypeName = visualizerObjectSourceTypeName;
}

void DebuggerVisualizerAttribute___::ctor(String visualizerTypeName, Type visualizerObjectSource) {
  if (visualizerObjectSource == nullptr) {
    rt::throw_exception<ArgumentNullException>("visualizerObjectSource");
  }
  VisualizerTypeName = visualizerTypeName;
  VisualizerObjectSourceTypeName = visualizerObjectSource->get_AssemblyQualifiedName();
}

void DebuggerVisualizerAttribute___::ctor(Type visualizer) {
  if (visualizer == nullptr) {
    rt::throw_exception<ArgumentNullException>("visualizer");
  }
  VisualizerTypeName = visualizer->get_AssemblyQualifiedName();
}

void DebuggerVisualizerAttribute___::ctor(Type visualizer, Type visualizerObjectSource) {
  if (visualizer == nullptr) {
    rt::throw_exception<ArgumentNullException>("visualizer");
  }
  if (visualizerObjectSource == nullptr) {
    rt::throw_exception<ArgumentNullException>("visualizerObjectSource");
  }
  VisualizerTypeName = visualizer->get_AssemblyQualifiedName();
  VisualizerObjectSourceTypeName = visualizerObjectSource->get_AssemblyQualifiedName();
}

void DebuggerVisualizerAttribute___::ctor(Type visualizer, String visualizerObjectSourceTypeName) {
  if (visualizer == nullptr) {
    rt::throw_exception<ArgumentNullException>("visualizer");
  }
  VisualizerTypeName = visualizer->get_AssemblyQualifiedName();
  VisualizerObjectSourceTypeName = visualizerObjectSourceTypeName;
}

} // namespace System::Private::CoreLib::System::Diagnostics::DebuggerVisualizerAttributeNamespace
