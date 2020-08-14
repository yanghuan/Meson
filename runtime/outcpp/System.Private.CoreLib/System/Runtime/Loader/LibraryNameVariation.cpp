#include "LibraryNameVariation-dep.h"

#include <System.Private.CoreLib/System/Runtime/Loader/LibraryNameVariation-dep.h>

namespace System::Private::CoreLib::System::Runtime::Loader::LibraryNameVariationNamespace {
LibraryNameVariation::LibraryNameVariation(String prefix, String suffix) {
  Prefix = prefix;
  Suffix = suffix;
}

IEnumerable<LibraryNameVariation> LibraryNameVariation::DetermineLibraryNameVariations(String libName, Boolean isRelativePath, Boolean forOSLoader) {
}

} // namespace System::Private::CoreLib::System::Runtime::Loader::LibraryNameVariationNamespace
