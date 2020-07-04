#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace DefaultParameterValueAttributeNamespace {
CLASS(DefaultParameterValueAttribute) {
  public: Object get_Value() { return Value; }
  private: Object Value;
};
} // namespace DefaultParameterValueAttributeNamespace
using DefaultParameterValueAttribute = DefaultParameterValueAttributeNamespace::DefaultParameterValueAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
