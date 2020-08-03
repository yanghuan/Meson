#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
namespace DictionaryEntryNamespace {
struct DictionaryEntry : public valueType<DictionaryEntry> {
  public: Object get_Key();
  public: void set_Key(Object value);
  public: Object get_Value();
  public: void set_Value(Object value);
  public: explicit DictionaryEntry(Object key, Object value);
  public: void Deconstruct(Object& key, Object& value);
  public: explicit DictionaryEntry() {}
  private: Object _key;
  private: Object _value;
};
} // namespace DictionaryEntryNamespace
using DictionaryEntry = DictionaryEntryNamespace::DictionaryEntry;
} // namespace System::Private::CoreLib::System::Collections
