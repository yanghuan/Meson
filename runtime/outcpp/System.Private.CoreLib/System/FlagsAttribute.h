#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
namespace FlagsAttributeNamespace {
CLASS(FlagsAttribute) {
  public: void Ctor();
};
} // namespace FlagsAttributeNamespace
using FlagsAttribute = FlagsAttributeNamespace::FlagsAttribute;
} // namespace System::Private::CoreLib::System
