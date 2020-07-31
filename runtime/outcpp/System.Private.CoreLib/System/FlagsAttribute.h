#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
namespace FlagsAttributeNamespace {
CLASS(FlagsAttribute) : public Attribute::in {
  public: void Ctor();
};
} // namespace FlagsAttributeNamespace
using FlagsAttribute = FlagsAttributeNamespace::FlagsAttribute;
} // namespace System::Private::CoreLib::System
