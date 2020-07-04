#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComEventInterfaceAttributeNamespace {
CLASS(ComEventInterfaceAttribute) {
  public: Type get_SourceInterface() { return SourceInterface; }
  public: Type get_EventProvider() { return EventProvider; }
  private: Type SourceInterface;
  private: Type EventProvider;
};
} // namespace ComEventInterfaceAttributeNamespace
using ComEventInterfaceAttribute = ComEventInterfaceAttributeNamespace::ComEventInterfaceAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
