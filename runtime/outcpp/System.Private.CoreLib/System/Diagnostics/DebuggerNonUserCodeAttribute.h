#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerNonUserCodeAttributeNamespace {
CLASS(DebuggerNonUserCodeAttribute) {
  public: void Ctor();
};
} // namespace DebuggerNonUserCodeAttributeNamespace
using DebuggerNonUserCodeAttribute = DebuggerNonUserCodeAttributeNamespace::DebuggerNonUserCodeAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
