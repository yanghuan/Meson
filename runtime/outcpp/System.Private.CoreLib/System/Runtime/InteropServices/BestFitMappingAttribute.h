#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace BestFitMappingAttributeNamespace {
CLASS(BestFitMappingAttribute) : public Attribute::in {
  public: Boolean get_BestFitMapping() { return BestFitMapping; }
  public: void ctor(Boolean BestFitMapping);
  private: Boolean BestFitMapping;
  public: Boolean ThrowOnUnmappableChar;
};
} // namespace BestFitMappingAttributeNamespace
using BestFitMappingAttribute = BestFitMappingAttributeNamespace::BestFitMappingAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
