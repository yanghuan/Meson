#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics {
enum class DebuggerBrowsableState;
namespace DebuggerBrowsableAttributeNamespace {
CLASS(DebuggerBrowsableAttribute) {
  public: DebuggerBrowsableState get_State() { return State; }
  public: void Ctor(DebuggerBrowsableState state);
  private: DebuggerBrowsableState State;
};
} // namespace DebuggerBrowsableAttributeNamespace
using DebuggerBrowsableAttribute = DebuggerBrowsableAttributeNamespace::DebuggerBrowsableAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
