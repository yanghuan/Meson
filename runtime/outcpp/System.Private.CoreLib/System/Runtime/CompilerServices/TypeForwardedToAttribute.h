#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace TypeForwardedToAttributeNamespace {
CLASS(TypeForwardedToAttribute) : public Attribute::in {
  public: Type get_Destination() { return Destination; }
  public: void Ctor(Type destination);
  private: Type Destination;
};
} // namespace TypeForwardedToAttributeNamespace
using TypeForwardedToAttribute = TypeForwardedToAttributeNamespace::TypeForwardedToAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
