#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/DateTime.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace DateTimeConstantAttributeNamespace {
CLASS(DateTimeConstantAttribute) {
  public: Object get_Value();
  private: DateTime _date;
};
} // namespace DateTimeConstantAttributeNamespace
using DateTimeConstantAttribute = DateTimeConstantAttributeNamespace::DateTimeConstantAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
