#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
namespace KeyValuePairNamespace {
template <class T1 = void, class T2 = void, class T3 = void>
class KeyValuePair {
};
template <>
class KeyValuePair<> {
};
template <class TKey, class TValue>
struct KeyValuePair<TKey, TValue> {
  private: TKey key;
  private: TValue value;
};
} // namespace KeyValuePairNamespace
template <class T1 = void, class T2 = void, class T3 = void>
using KeyValuePair = KeyValuePairNamespace::KeyValuePair<T1, T2, T3>;
} // namespace System::Private::CoreLib::System::Collections::Generic
