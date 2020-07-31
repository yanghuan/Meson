#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::Microsoft::CodeAnalysis {
namespace EmbeddedAttributeNamespace {
using namespace ::System::Private::CoreLib::System;
CLASS(EmbeddedAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace EmbeddedAttributeNamespace
using EmbeddedAttribute = EmbeddedAttributeNamespace::EmbeddedAttribute;
} // namespace System::Private::CoreLib::Microsoft::CodeAnalysis
