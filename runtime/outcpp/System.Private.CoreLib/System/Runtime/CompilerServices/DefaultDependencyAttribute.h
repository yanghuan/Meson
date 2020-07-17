#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class LoadHint;
namespace DefaultDependencyAttributeNamespace {
CLASS(DefaultDependencyAttribute) {
  public: LoadHint get_LoadHint() { return LoadHint; }
  public: void Ctor(LoadHint loadHintArgument);
  private: LoadHint LoadHint;
};
} // namespace DefaultDependencyAttributeNamespace
using DefaultDependencyAttribute = DefaultDependencyAttributeNamespace::DefaultDependencyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
