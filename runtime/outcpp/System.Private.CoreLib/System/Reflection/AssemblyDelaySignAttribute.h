#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyDelaySignAttributeNamespace {
CLASS(AssemblyDelaySignAttribute) {
  private: Boolean DelaySign;
};
} // namespace AssemblyDelaySignAttributeNamespace
using AssemblyDelaySignAttribute = AssemblyDelaySignAttributeNamespace::AssemblyDelaySignAttribute;
} // namespace System::Private::CoreLib::System::Reflection
