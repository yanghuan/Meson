#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComSourceInterfacesAttributeNamespace {
CLASS(ComSourceInterfacesAttribute) {
  public: String get_Value() { return Value; }
  private: String Value;
};
} // namespace ComSourceInterfacesAttributeNamespace
using ComSourceInterfacesAttribute = ComSourceInterfacesAttributeNamespace::ComSourceInterfacesAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
