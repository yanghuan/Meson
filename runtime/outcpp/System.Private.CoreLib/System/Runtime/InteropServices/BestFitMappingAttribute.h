#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace BestFitMappingAttributeNamespace {
CLASS(BestFitMappingAttribute) {
  public: Boolean ThrowOnUnmappableChar;
};
} // namespace BestFitMappingAttributeNamespace
using BestFitMappingAttribute = BestFitMappingAttributeNamespace::BestFitMappingAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
