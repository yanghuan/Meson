#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IDictionary, TKey, TValue)
namespace IDictionaryDebugViewNamespace {
CLASS(IDictionaryDebugView, K, V) {
  private: IDictionary<K, V> _dict;
};
} // namespace IDictionaryDebugViewNamespace
template <class K, class V>
using IDictionaryDebugView = IDictionaryDebugViewNamespace::IDictionaryDebugView<K, V>;
} // namespace System::Private::CoreLib::System::Collections::Generic
