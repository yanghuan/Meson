#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace DefaultParameterValueAttributeNamespace {
CLASS(DefaultParameterValueAttribute) : public Attribute::in {
  public: Object get_Value() { return Value; }
  public: void ctor(Object value);
  private: Object Value;
};
} // namespace DefaultParameterValueAttributeNamespace
using DefaultParameterValueAttribute = DefaultParameterValueAttributeNamespace::DefaultParameterValueAttribute;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
