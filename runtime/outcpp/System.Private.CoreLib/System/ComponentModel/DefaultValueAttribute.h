#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::ComponentModel {
namespace DefaultValueAttributeNamespace {
CLASS(DefaultValueAttribute) {
  public: Object get_Value();
  public: Boolean Equals(Object obj);
  public: Int32 GetHashCode();
  protected: void SetValue(Object value);
  private: Object _value;
  private: static Object s_convertFromInvariantString;
};
} // namespace DefaultValueAttributeNamespace
using DefaultValueAttribute = DefaultValueAttributeNamespace::DefaultValueAttribute;
} // namespace System::Private::CoreLib::System::ComponentModel
