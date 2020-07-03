#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics {
enum class DebuggerBrowsableState;
namespace DebuggerBrowsableAttributeNamespace {
CLASS(DebuggerBrowsableAttribute) {
  private: DebuggerBrowsableState State;
};
} // namespace DebuggerBrowsableAttributeNamespace
using DebuggerBrowsableAttribute = DebuggerBrowsableAttributeNamespace::DebuggerBrowsableAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
