#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace MaybeNullAttributeNamespace {
CLASS(MaybeNullAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace MaybeNullAttributeNamespace
using MaybeNullAttribute = MaybeNullAttributeNamespace::MaybeNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
