#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
FORWARD(IEnumerable, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
namespace IDictionaryNamespace {
using Generic::ICollection;
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable1 = Collections::IEnumerable;
CLASS(IDictionary, TKey, TValue) : public Object::in {
  public: using interface = rt::TypeList<ICollection<KeyValuePair<TKey, TValue>>, IEnumerable<KeyValuePair<TKey, TValue>>, IEnumerable1>;
  public: TValue get_Item(TKey key);
  public: void set_Item(TKey key, TValue value);
  public: ICollection<TKey> get_Keys();
  public: ICollection<TValue> get_Values();
  public: Boolean ContainsKey(TKey key);
  public: void Add(TKey key, TValue value);
  public: Boolean Remove(TKey key);
  public: Boolean TryGetValue(TKey key, TValue& value);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IDictionaryNamespace
template <class TKey, class TValue>
using IDictionary = IDictionaryNamespace::IDictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
