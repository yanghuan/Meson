#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
enum class LoadHint : int32_t;
namespace DependencyAttributeNamespace {
CLASS(DependencyAttribute) : public Attribute::in {
  public: String get_DependentAssembly() { return DependentAssembly; }
  public: LoadHint get_LoadHint() { return LoadHint; }
  public: void ctor(String dependentAssemblyArgument, LoadHint loadHintArgument);
  private: String DependentAssembly;
  private: LoadHint LoadHint;
};
} // namespace DependencyAttributeNamespace
using DependencyAttribute = DependencyAttributeNamespace::DependencyAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
