#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
namespace SerializationEntryNamespace {
struct SerializationEntry : public valueType<SerializationEntry> {
  public: Object get_Value();
  public: String get_Name();
  public: Type get_ObjectType();
  public: explicit SerializationEntry(String entryName, Object entryValue, Type entryType);
  public: explicit SerializationEntry() {}
  private: String _name;
  private: Object _value;
  private: Type _type;
};
} // namespace SerializationEntryNamespace
using SerializationEntry = SerializationEntryNamespace::SerializationEntry;
} // namespace System::Private::CoreLib::System::Runtime::Serialization
