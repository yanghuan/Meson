#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IReadOnlyCollection, T)
FORWARDS_(KeyValuePair, T1, T2, T3)
namespace IReadOnlyDictionaryNamespace {
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable1 = Collections::IEnumerable;
CLASS(IReadOnlyDictionary, TKey, TValue) : public Object::in {
  public: using interface = rt::TypeList<IReadOnlyCollection<KeyValuePair<TKey, TValue>>, IEnumerable<KeyValuePair<TKey, TValue>>, IEnumerable1>;
  public: TValue get_Item(TKey key);
  public: IEnumerable<TKey> get_Keys();
  public: IEnumerable<TValue> get_Values();
  public: Boolean ContainsKey(TKey key);
  public: Boolean TryGetValue(TKey key, TValue& value);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IReadOnlyDictionaryNamespace
template <class TKey, class TValue>
using IReadOnlyDictionary = IReadOnlyDictionaryNamespace::IReadOnlyDictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
