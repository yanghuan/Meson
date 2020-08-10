#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace ComSourceInterfacesAttributeNamespace {
CLASS(ComSourceInterfacesAttribute) : public Attribute::in {
  public: String get_Value() { return Value; }
  public: void ctor(String sourceInterfaces);
  public: void ctor(Type sourceInterface);
  public: void ctor(Type sourceInterface1, Type sourceInterface2);
  public: void ctor(Type sourceInterface1, Type sourceInterface2, Type sourceInterface3);
  public: void ctor(Type sourceInterface1, Type sourceInterface2, Type sourceInterface3, Type sourceInterface4);
  private: String Value;
};
} // namespace ComSourceInterfacesAttributeNamespace
using ComSourceInterfacesAttribute = ComSourceInterfacesAttributeNamespace::ComSourceInterfacesAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
