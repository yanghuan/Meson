#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class LoadHint;
namespace DependencyAttributeNamespace {
CLASS(DependencyAttribute) {
  public: String get_DependentAssembly() { return DependentAssembly; }
  public: LoadHint get_LoadHint() { return LoadHint; }
  private: String DependentAssembly;
  private: LoadHint LoadHint;
};
} // namespace DependencyAttributeNamespace
using DependencyAttribute = DependencyAttributeNamespace::DependencyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
