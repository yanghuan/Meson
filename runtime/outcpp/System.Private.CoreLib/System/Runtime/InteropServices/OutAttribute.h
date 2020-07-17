#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace OutAttributeNamespace {
CLASS(OutAttribute) {
  public: void Ctor();
};
} // namespace OutAttributeNamespace
using OutAttribute = OutAttributeNamespace::OutAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
