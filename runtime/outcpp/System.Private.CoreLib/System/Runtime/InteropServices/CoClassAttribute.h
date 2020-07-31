#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace CoClassAttributeNamespace {
CLASS(CoClassAttribute) : public Attribute::in {
  public: Type get_CoClass() { return CoClass; }
  public: void Ctor(Type coClass);
  private: Type CoClass;
};
} // namespace CoClassAttributeNamespace
using CoClassAttribute = CoClassAttributeNamespace::CoClassAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
