#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IEnumerable, T)
namespace IReadOnlyDictionaryNamespace {
CLASS(IReadOnlyDictionary, TKey, TValue) {
  public: TValue get_Item(TKey key);
  public: IEnumerable<TKey> get_Keys();
  public: IEnumerable<TValue> get_Values();
  public: Boolean ContainsKey(TKey key);
  public: Boolean TryGetValue(TKey key, TValue& value);
};
} // namespace IReadOnlyDictionaryNamespace
template <class TKey, class TValue>
using IReadOnlyDictionary = IReadOnlyDictionaryNamespace::IReadOnlyDictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
