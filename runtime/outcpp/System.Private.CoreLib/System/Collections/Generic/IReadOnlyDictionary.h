#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IReadOnlyDictionaryNamespace {
CLASS(IReadOnlyDictionary, TKey, TValue) {
  public: Boolean ContainsKey(TKey key);
  public: Boolean TryGetValue(TKey key, TValue& value);
};
} // namespace IReadOnlyDictionaryNamespace
template <class TKey, class TValue>
using IReadOnlyDictionary = IReadOnlyDictionaryNamespace::IReadOnlyDictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
