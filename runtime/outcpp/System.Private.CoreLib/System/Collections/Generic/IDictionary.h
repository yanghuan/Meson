#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IDictionaryNamespace {
CLASS(IDictionary, TKey, TValue) {
  public: Boolean ContainsKey(TKey key);
  public: void Add(TKey key, TValue value);
  public: Boolean Remove(TKey key);
  public: Boolean TryGetValue(TKey key, TValue& value);
};
} // namespace IDictionaryNamespace
template <class TKey, class TValue>
using IDictionary = IDictionaryNamespace::IDictionary<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Collections::Generic
