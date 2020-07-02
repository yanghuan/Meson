#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::Loader {
namespace LibraryNameVariationNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
struct LibraryNameVariation {
  public: static IEnumerable<LibraryNameVariation> DetermineLibraryNameVariations(String libName, Boolean isRelativePath);
  public: String Prefix;
  public: String Suffix;
};
} // namespace LibraryNameVariationNamespace
using LibraryNameVariation = LibraryNameVariationNamespace::LibraryNameVariation;
} // namespace System::Private::CoreLib::System::Runtime::Loader
