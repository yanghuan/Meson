#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
namespace DisallowNullAttributeNamespace {
CLASS(DisallowNullAttribute) {
  public: void Ctor();
};
} // namespace DisallowNullAttributeNamespace
using DisallowNullAttribute = DisallowNullAttributeNamespace::DisallowNullAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
