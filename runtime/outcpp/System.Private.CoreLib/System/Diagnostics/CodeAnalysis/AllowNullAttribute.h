#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace AllowNullAttributeNamespace {
CLASS(AllowNullAttribute) {
  public: void Ctor();
};
} // namespace AllowNullAttributeNamespace
using AllowNullAttribute = AllowNullAttributeNamespace::AllowNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
