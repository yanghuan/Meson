#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/DateTime.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/CustomConstantAttribute.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int64)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace DateTimeConstantAttributeNamespace {
CLASS(DateTimeConstantAttribute) : public CustomConstantAttribute::in {
  public: Object get_Value();
  public: void Ctor(Int64 ticks);
  private: DateTime _date;
};
} // namespace DateTimeConstantAttributeNamespace
using DateTimeConstantAttribute = DateTimeConstantAttributeNamespace::DateTimeConstantAttribute;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
