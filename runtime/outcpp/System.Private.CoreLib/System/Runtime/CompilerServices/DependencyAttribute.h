#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class LoadHint;
namespace DependencyAttributeNamespace {
CLASS(DependencyAttribute) {
  private: String DependentAssembly;
  private: LoadHint LoadHint;
};
} // namespace DependencyAttributeNamespace
using DependencyAttribute = DependencyAttributeNamespace::DependencyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
