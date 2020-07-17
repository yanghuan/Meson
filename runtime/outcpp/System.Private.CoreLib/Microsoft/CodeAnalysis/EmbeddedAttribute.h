#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::Microsoft::CodeAnalysis {
namespace EmbeddedAttributeNamespace {
CLASS(EmbeddedAttribute) {
  public: void Ctor();
};
} // namespace EmbeddedAttributeNamespace
using EmbeddedAttribute = EmbeddedAttributeNamespace::EmbeddedAttribute;
} // namespace System::Private::CoreLib::Microsoft::CodeAnalysis
