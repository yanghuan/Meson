#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComSourceInterfacesAttributeNamespace {
CLASS(ComSourceInterfacesAttribute) : public Attribute::in {
  public: String get_Value() { return Value; }
  public: void Ctor(String sourceInterfaces);
  public: void Ctor(Type sourceInterface);
  public: void Ctor(Type sourceInterface1, Type sourceInterface2);
  public: void Ctor(Type sourceInterface1, Type sourceInterface2, Type sourceInterface3);
  public: void Ctor(Type sourceInterface1, Type sourceInterface2, Type sourceInterface3, Type sourceInterface4);
  private: String Value;
};
} // namespace ComSourceInterfacesAttributeNamespace
using ComSourceInterfacesAttribute = ComSourceInterfacesAttributeNamespace::ComSourceInterfacesAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
