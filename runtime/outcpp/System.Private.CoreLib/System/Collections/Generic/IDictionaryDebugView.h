#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IDictionary, TKey, TValue)
FORWARDS_(KeyValuePair, T1, T2, T3)
namespace IDictionaryDebugViewNamespace {
template <class TKey, class TValue>
using IDictionary = Generic::IDictionary<TKey, TValue>;
CLASS(IDictionaryDebugView, K, V) : public object {
  public: Array<KeyValuePair<K, V>> get_Items();
  public: void ctor(IDictionary<K, V> dictionary);
  private: IDictionary<K, V> _dict;
};
} // namespace IDictionaryDebugViewNamespace
template <class K, class V>
using IDictionaryDebugView = IDictionaryDebugViewNamespace::IDictionaryDebugView<K, V>;
} // namespace System::Private::CoreLib::System::Collections::Generic
