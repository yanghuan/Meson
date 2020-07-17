#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace OptionalAttributeNamespace {
CLASS(OptionalAttribute) {
  public: void Ctor();
};
} // namespace OptionalAttributeNamespace
using OptionalAttribute = OptionalAttributeNamespace::OptionalAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
