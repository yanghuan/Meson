#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerStepThroughAttributeNamespace {
CLASS(DebuggerStepThroughAttribute) {
  public: void Ctor();
};
} // namespace DebuggerStepThroughAttributeNamespace
using DebuggerStepThroughAttribute = DebuggerStepThroughAttributeNamespace::DebuggerStepThroughAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
