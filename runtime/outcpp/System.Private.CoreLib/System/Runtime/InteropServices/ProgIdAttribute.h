#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ProgIdAttributeNamespace {
CLASS(ProgIdAttribute) {
  public: String get_Value() { return Value; }
  private: String Value;
};
} // namespace ProgIdAttributeNamespace
using ProgIdAttribute = ProgIdAttributeNamespace::ProgIdAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
