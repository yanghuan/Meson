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
  public: static String PortablePdb;
  public: static String DefaultImplementationsOfInterfaces;
  public: static String CovariantReturnsOfClasses;
};
} // namespace RuntimeFeatureNamespace
using RuntimeFeature = RuntimeFeatureNamespace::RuntimeFeature;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
