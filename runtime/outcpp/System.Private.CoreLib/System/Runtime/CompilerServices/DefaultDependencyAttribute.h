#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class LoadHint;
namespace DefaultDependencyAttributeNamespace {
CLASS(DefaultDependencyAttribute) {
  private: LoadHint LoadHint;
};
} // namespace DefaultDependencyAttributeNamespace
using DefaultDependencyAttribute = DefaultDependencyAttributeNamespace::DefaultDependencyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
