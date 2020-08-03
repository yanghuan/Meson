#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics {
namespace DebuggerStepperBoundaryAttributeNamespace {
CLASS(DebuggerStepperBoundaryAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace DebuggerStepperBoundaryAttributeNamespace
using DebuggerStepperBoundaryAttribute = DebuggerStepperBoundaryAttributeNamespace::DebuggerStepperBoundaryAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics
