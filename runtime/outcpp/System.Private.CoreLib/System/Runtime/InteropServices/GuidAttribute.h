#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace GuidAttributeNamespace {
CLASS(GuidAttribute) {
  private: String Value;
};
} // namespace GuidAttributeNamespace
using GuidAttribute = GuidAttributeNamespace::GuidAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
