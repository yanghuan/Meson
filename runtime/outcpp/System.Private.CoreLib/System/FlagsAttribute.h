#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
namespace FlagsAttributeNamespace {
CLASS(FlagsAttribute) : public Attribute::in {
  public: void ctor();
};
} // namespace FlagsAttributeNamespace
using FlagsAttribute = FlagsAttributeNamespace::FlagsAttribute;
} // namespace System::Private::CoreLib::System
