#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace Test::Microsoft::CodeAnalysis {
namespace EmbeddedAttributeNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(EmbeddedAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace EmbeddedAttributeNamespace
using EmbeddedAttribute = EmbeddedAttributeNamespace::EmbeddedAttribute;
} // namespace Test::Microsoft::CodeAnalysis
