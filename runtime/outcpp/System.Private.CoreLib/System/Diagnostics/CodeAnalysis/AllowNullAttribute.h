#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace AllowNullAttributeNamespace {
CLASS(AllowNullAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace AllowNullAttributeNamespace
using AllowNullAttribute = AllowNullAttributeNamespace::AllowNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
