#include "DefaultValueAttribute-dep.h"

#include <System.Private.CoreLib/System/ComponentModel/DefaultValueAttribute-dep.h>

namespace System::Private::CoreLib::System::ComponentModel::DefaultValueAttributeNamespace {
Object DefaultValueAttribute___::get_Value() {
  return _value;
}

void DefaultValueAttribute___::ctor(Type type, String value) {
  if (type == nullptr) {
    return;
  }
  try{
  } catch (...) {
  }
}

void DefaultValueAttribute___::ctor(Char value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Byte value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Int16 value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Int32 value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Int64 value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Single value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Double value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Boolean value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(String value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(Object value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(SByte value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(UInt16 value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(UInt32 value) {
  _value = value;
}

void DefaultValueAttribute___::ctor(UInt64 value) {
  _value = value;
}

Boolean DefaultValueAttribute___::Equals(Object obj) {
  if (obj == (DefaultValueAttribute)this) {
    return true;
  }
  DefaultValueAttribute defaultValueAttribute = rt::as<DefaultValueAttribute>(obj);
  if (defaultValueAttribute == nullptr) {
    return false;
  }
  if (get_Value() == nullptr) {
    return defaultValueAttribute->get_Value() == nullptr;
  }
  return get_Value()->Equals(defaultValueAttribute->get_Value());
}

Int32 DefaultValueAttribute___::GetHashCode() {
}

void DefaultValueAttribute___::SetValue(Object value) {
  _value = value;
}

} // namespace System::Private::CoreLib::System::ComponentModel::DefaultValueAttributeNamespace
