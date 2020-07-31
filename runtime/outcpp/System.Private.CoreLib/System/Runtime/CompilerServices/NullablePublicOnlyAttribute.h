#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace NullablePublicOnlyAttributeNamespace {
CLASS(NullablePublicOnlyAttribute) : public Attribute::in {
  public: void Ctor(Boolean _);
  public: Boolean IncludesInternals;
};
} // namespace NullablePublicOnlyAttributeNamespace
using NullablePublicOnlyAttribute = NullablePublicOnlyAttributeNamespace::NullablePublicOnlyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
