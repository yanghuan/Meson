#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace KeyValuePairNamespace {
template <class ...T>
class KeyValuePair {
};
template <>
class KeyValuePair<> {
  public: template <class TKey, class TValue>
  static KeyValuePair<TKey, TValue> Create(TKey key, TValue value);
  public: static String PairToString(Object key, Object value);
};
template <class TKey, class TValue>
struct KeyValuePair<TKey, TValue> : public valueType<KeyValuePair<TKey, TValue>> {
  public: TKey get_Key();
  public: TValue get_Value();
  public: explicit KeyValuePair(TKey key, TValue value);
  public: String ToString();
  public: void Deconstruct(TKey& key, TValue& value);
  public: explicit KeyValuePair() {}
  private: TKey key;
  private: TValue value;
};
} // namespace KeyValuePairNamespace
template <class ...T>
using KeyValuePair = KeyValuePairNamespace::KeyValuePair<T...>;
} // namespace System::Private::CoreLib::System::Collections::Generic
