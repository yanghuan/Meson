#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IDictionaryEnumerator)
namespace IDictionaryNamespace {
CLASS(IDictionary) {
  public: Object get_Item(Object key);
  public: void set_Item(Object key, Object value);
  public: ICollection get_Keys();
  public: ICollection get_Values();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: Boolean Contains(Object key);
  public: void Add(Object key, Object value);
  public: void Clear();
  public: IDictionaryEnumerator GetEnumerator();
  public: void Remove(Object key);
};
} // namespace IDictionaryNamespace
using IDictionary = IDictionaryNamespace::IDictionary;
} // namespace System::Private::CoreLib::System::Collections