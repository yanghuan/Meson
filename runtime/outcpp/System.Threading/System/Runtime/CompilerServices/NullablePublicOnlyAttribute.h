#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Threading::System::Runtime::CompilerServices {
namespace NullablePublicOnlyAttributeNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(NullablePublicOnlyAttribute) : public Attribute::in {
  public: void ctor(Boolean _);
  public: Boolean IncludesInternals;
};
} // namespace NullablePublicOnlyAttributeNamespace
using NullablePublicOnlyAttribute = NullablePublicOnlyAttributeNamespace::NullablePublicOnlyAttribute;
} // namespace System::Threading::System::Runtime::CompilerServices
