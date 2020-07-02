#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt32)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(IReadOnlyDictionary, TKey, TValue)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IMapNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(IMap, K, V) {
  public: UInt32 get_Size();
  public: V Lookup(K key);
  public: Boolean HasKey(K key);
  public: IReadOnlyDictionary<K, V> GetView();
  public: Boolean Insert(K key, V value);
  public: void Remove(K key);
  public: void Clear();
};
} // namespace IMapNamespace
template <class K, class V>
using IMap = IMapNamespace::IMap<K, V>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
