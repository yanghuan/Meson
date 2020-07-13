#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace RuntimeFeatureNamespace {
class RuntimeFeature {
  public: static Boolean get_IsDynamicCodeSupported();
  public: static Boolean get_IsDynamicCodeCompiled();
  public: static Boolean IsSupported(String feature);
  public: static constexpr String PortablePdb = "PortablePdb";
  public: static constexpr String DefaultImplementationsOfInterfaces = "DefaultImplementationsOfInterfaces";
  public: static constexpr String CovariantReturnsOfClasses = "CovariantReturnsOfClasses";
};
} // namespace RuntimeFeatureNamespace
using RuntimeFeature = RuntimeFeatureNamespace::RuntimeFeature;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
