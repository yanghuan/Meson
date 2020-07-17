#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace InAttributeNamespace {
CLASS(InAttribute) {
  public: void Ctor();
};
} // namespace InAttributeNamespace
using InAttribute = InAttributeNamespace::InAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
