#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyDelaySignAttributeNamespace {
CLASS(AssemblyDelaySignAttribute) : public Attribute::in {
  public: Boolean get_DelaySign() { return DelaySign; }
  public: void ctor(Boolean delaySign);
  private: Boolean DelaySign;
};
} // namespace AssemblyDelaySignAttributeNamespace
using AssemblyDelaySignAttribute = AssemblyDelaySignAttributeNamespace::AssemblyDelaySignAttribute;
} // namespace System::Private::CoreLib::System::Reflection
