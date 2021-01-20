#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections {
FORWARD(IEnumerable)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
FORWARD(IEnumerator, T)
FORWARD(IReadOnlyCollection, T)
FORWARDS_(KeyValuePair)
namespace IReadOnlyDictionaryNamespace {
template <class T>
using IEnumerable = Generic::IEnumerable<T>;
using IEnumerable_ = Collections::IEnumerable;
template <class T>
using IEnumerator = Generic::IEnumerator<T>;
CLASS(IReadOnlyDictionary, TKey, TValue) : public object {
  public: using interface = rt::TypeList<IReadOnlyCollection<KeyValuePair<TKey, TValue>>, IEnumerable<KeyValuePair<TKey, TValue>>, IEnumerable_>;
  public: Int32 get_Count();
  public: TValue get_Item(TKey key);
  public: IEnumerable<TKey> get_Keys();
  public: IEnumerable<TValue> get_Values();
  public: IEnumerator<KeyValuePair<TKey, TValue>> GetEnumerator();
  public: Boolean ContainsKey(TKey key);
  public: Boolean TryGetValue(TKey key, TValue& value);
  public: static constexpr rt::TypeCode code = rt::TypeCode::Interface;
};
} // namespace IReadOnlyDictionaryNamespace
template <class TKey, class TValue>
using IReadOnlyDictionary = IReadOnlyDictionaryNamespace::IReadOnlyDictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
