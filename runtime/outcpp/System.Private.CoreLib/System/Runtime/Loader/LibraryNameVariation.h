#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::Loader {
namespace LibraryNameVariationNamespace {
using namespace Collections::Generic;
struct LibraryNameVariation {
  public: explicit LibraryNameVariation(String prefix, String suffix);
  public: static IEnumerable<LibraryNameVariation> DetermineLibraryNameVariations(String libName, Boolean isRelativePath, Boolean forOSLoader);
  public: explicit LibraryNameVariation() {}
  public: String Prefix;
  public: String Suffix;
};
} // namespace LibraryNameVariationNamespace
using LibraryNameVariation = LibraryNameVariationNamespace::LibraryNameVariation;
} // namespace System::Private::CoreLib::System::Runtime::Loader
