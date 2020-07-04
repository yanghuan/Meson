#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace TypeForwardedToAttributeNamespace {
CLASS(TypeForwardedToAttribute) {
  public: Type get_Destination() { return Destination; }
  private: Type Destination;
};
} // namespace TypeForwardedToAttributeNamespace
using TypeForwardedToAttribute = TypeForwardedToAttributeNamespace::TypeForwardedToAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
