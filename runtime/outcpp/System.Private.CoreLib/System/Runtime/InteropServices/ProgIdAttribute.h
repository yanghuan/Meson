#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ProgIdAttributeNamespace {
CLASS(ProgIdAttribute) {
  private: String Value;
};
} // namespace ProgIdAttributeNamespace
using ProgIdAttribute = ProgIdAttributeNamespace::ProgIdAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
