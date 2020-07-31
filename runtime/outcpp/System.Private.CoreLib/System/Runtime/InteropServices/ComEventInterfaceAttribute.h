#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComEventInterfaceAttributeNamespace {
CLASS(ComEventInterfaceAttribute) : public Attribute::in {
  public: Type get_SourceInterface() { return SourceInterface; }
  public: Type get_EventProvider() { return EventProvider; }
  public: void Ctor(Type SourceInterface, Type EventProvider);
  private: Type SourceInterface;
  private: Type EventProvider;
};
} // namespace ComEventInterfaceAttributeNamespace
using ComEventInterfaceAttribute = ComEventInterfaceAttributeNamespace::ComEventInterfaceAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
