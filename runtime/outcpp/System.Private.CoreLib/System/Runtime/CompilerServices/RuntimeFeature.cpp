#include "RuntimeFeature-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeFeatureNamespace {
Boolean RuntimeFeature::get_IsDynamicCodeSupported() {
  return true;
}

Boolean RuntimeFeature::get_IsDynamicCodeCompiled() {
  return true;
}

Boolean RuntimeFeature::IsSupported(String feature) {
  if (!(feature == "PortablePdb") && !(feature == "CovariantReturnsOfClasses") && !(feature == "UnmanagedSignatureCallingConvention") && !(feature == "DefaultImplementationsOfInterfaces")) {
    if (!(feature == "IsDynamicCodeSupported")) {
      if (feature == "IsDynamicCodeCompiled") {
        return get_IsDynamicCodeCompiled();
      }
      return false;
    }
    return get_IsDynamicCodeSupported();
  }
  return true;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::RuntimeFeatureNamespace
