#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerStepThroughAttributeNamespace {
CLASS(DebuggerStepThroughAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace DebuggerStepThroughAttributeNamespace
using DebuggerStepThroughAttribute = DebuggerStepThroughAttributeNamespace::DebuggerStepThroughAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
