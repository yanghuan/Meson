#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
namespace CLSCompliantAttributeNamespace {
CLASS(CLSCompliantAttribute) : public Attribute::in {
  public: Boolean get_IsCompliant();
  public: void Ctor(Boolean isCompliant);
  private: Boolean _compliant;
};
} // namespace CLSCompliantAttributeNamespace
using CLSCompliantAttribute = CLSCompliantAttributeNamespace::CLSCompliantAttribute;
} // namespace System::Private::CoreLib::System
