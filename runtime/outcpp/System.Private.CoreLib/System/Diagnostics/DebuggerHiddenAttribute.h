#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerHiddenAttributeNamespace {
CLASS(DebuggerHiddenAttribute) {
  public: void Ctor();
};
} // namespace DebuggerHiddenAttributeNamespace
using DebuggerHiddenAttribute = DebuggerHiddenAttributeNamespace::DebuggerHiddenAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
