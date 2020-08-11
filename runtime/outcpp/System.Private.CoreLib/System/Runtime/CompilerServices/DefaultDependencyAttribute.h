#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class LoadHint : int32_t;
namespace DefaultDependencyAttributeNamespace {
CLASS(DefaultDependencyAttribute) : public Attribute::in {
  public: LoadHint get_LoadHint() { return LoadHint; }
  public: void ctor(LoadHint loadHintArgument);
  private: LoadHint LoadHint;
};
} // namespace DefaultDependencyAttributeNamespace
using DefaultDependencyAttribute = DefaultDependencyAttributeNamespace::DefaultDependencyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
