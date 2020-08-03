#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace DisallowNullAttributeNamespace {
CLASS(DisallowNullAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace DisallowNullAttributeNamespace
using DisallowNullAttribute = DisallowNullAttributeNamespace::DisallowNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
