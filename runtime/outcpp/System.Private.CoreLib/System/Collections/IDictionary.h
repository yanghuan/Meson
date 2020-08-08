#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IDictionaryEnumerator)
FORWARD(IEnumerable)
namespace IDictionaryNamespace {
CLASS(IDictionary) : public Object::in {
  using interface = rt::TypeList<ICollection, IEnumerable>;
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
