#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Collections::Generic {
namespace KeyValuePairNamespace {
template <class T1 = void, class T2 = void, class T3 = void>
class KeyValuePair {
};
template <>
class KeyValuePair<> : public Object::in {
};
template <class TKey, class TValue>
struct KeyValuePair<TKey, TValue> {
  public: TKey get_Key();
  public: TValue get_Value();
  private: TKey key;
  private: TValue value;
};
} // namespace KeyValuePairNamespace
template <class T1 = void, class T2 = void, class T3 = void>
using KeyValuePair = KeyValuePairNamespace::KeyValuePair<T1, T2, T3>;
} // namespace System::Private::CoreLib::System::Collections::Generic
