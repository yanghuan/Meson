#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Console::System::Runtime::CompilerServices {
namespace NullablePublicOnlyAttributeNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(NullablePublicOnlyAttribute) {
  public: void Ctor(Boolean _);
  public: Boolean IncludesInternals;
};
} // namespace NullablePublicOnlyAttributeNamespace
using NullablePublicOnlyAttribute = NullablePublicOnlyAttributeNamespace::NullablePublicOnlyAttribute;
} // namespace System::Console::System::Runtime::CompilerServices
