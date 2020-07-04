#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyDelaySignAttributeNamespace {
CLASS(AssemblyDelaySignAttribute) {
  public: Boolean get_DelaySign() { return DelaySign; }
  private: Boolean DelaySign;
};
} // namespace AssemblyDelaySignAttributeNamespace
using AssemblyDelaySignAttribute = AssemblyDelaySignAttributeNamespace::AssemblyDelaySignAttribute;
} // namespace System::Private::CoreLib::System::Reflection
