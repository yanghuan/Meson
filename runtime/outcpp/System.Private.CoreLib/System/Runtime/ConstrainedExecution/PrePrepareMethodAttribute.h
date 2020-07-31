#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution {
namespace PrePrepareMethodAttributeNamespace {
CLASS(PrePrepareMethodAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace PrePrepareMethodAttributeNamespace
using PrePrepareMethodAttribute = PrePrepareMethodAttributeNamespace::PrePrepareMethodAttribute;
} // namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution
