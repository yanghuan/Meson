#include "SerializationEntry-dep.h"

namespace System::Private::CoreLib::System::Runtime::Serialization::SerializationEntryNamespace {
Object SerializationEntry::get_Value() {
  return _value;
}

String SerializationEntry::get_Name() {
  return _name;
}

Type SerializationEntry::get_ObjectType() {
  return _type;
}

SerializationEntry::SerializationEntry(String entryName, Object entryValue, Type entryType) {
  _name = entryName;
  _value = entryValue;
  _type = entryType;
}

} // namespace System::Private::CoreLib::System::Runtime::Serialization::SerializationEntryNamespace
