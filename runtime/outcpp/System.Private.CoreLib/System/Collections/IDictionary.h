#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(ICollection)
FORWARD(IDictionaryEnumerator)
FORWARD(IEnumerable)
FORWARD(IEnumerator)
namespace IDictionaryNamespace {
CLASS(IDictionary) : public object {
  public: using interface = rt::TypeList<ICollection, IEnumerable>;
  public: Int32 get_Count();
  public: Object get_SyncRoot();
  public: Boolean get_IsSynchronized();
  public: Object get_Item(Object key);
  public: void set_Item(Object key, Object value);
  public: ICollection get_Keys();
  public: ICollection get_Values();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: IEnumerator GetEnumerator();
  public: void CopyTo(Array<> array, Int32 index);
  public: Boolean Contains(Object key);
  public: void Add(Object key, Object value);
  public: void Clear();
  public: IDictionaryEnumerator GetEnumerator();
  public: void Remove(Object key);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IDictionaryNamespace
using IDictionary = IDictionaryNamespace::IDictionary;
} // namespace System::Private::CoreLib::System::Collections
