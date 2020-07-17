#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace NotNullAttributeNamespace {
CLASS(NotNullAttribute) {
  public: void Ctor();
};
} // namespace NotNullAttributeNamespace
using NotNullAttribute = NotNullAttributeNamespace::NotNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
