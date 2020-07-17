#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace CoClassAttributeNamespace {
CLASS(CoClassAttribute) {
  public: Type get_CoClass() { return CoClass; }
  public: void Ctor(Type coClass);
  private: Type CoClass;
};
} // namespace CoClassAttributeNamespace
using CoClassAttribute = CoClassAttributeNamespace::CoClassAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
