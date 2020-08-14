#include "RuntimeFeature-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeFeatureNamespace {
Boolean RuntimeFeature::get_IsDynamicCodeSupported() {
  return true;
}

Boolean RuntimeFeature::get_IsDynamicCodeCompiled() {
  return true;
}

Boolean RuntimeFeature::IsSupported(String feature) {
  switch (feature.get()) {
    case "PortablePdb":
    case "DefaultImplementationsOfInterfaces":
      return true;
    case "IsDynamicCodeSupported":
      return get_IsDynamicCodeSupported();
    case "IsDynamicCodeCompiled":
      return get_IsDynamicCodeCompiled();
    default:
      return false;
  }
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeFeatureNamespace
