#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
namespace CLSCompliantAttributeNamespace {
CLASS(CLSCompliantAttribute) {
  public: Boolean get_IsCompliant();
  public: void Ctor(Boolean isCompliant);
  private: Boolean _compliant;
};
} // namespace CLSCompliantAttributeNamespace
using CLSCompliantAttribute = CLSCompliantAttributeNamespace::CLSCompliantAttribute;
} // namespace System::Private::CoreLib::System
