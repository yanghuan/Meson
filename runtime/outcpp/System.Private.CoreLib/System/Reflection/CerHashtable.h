#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace CerHashtableNamespace {
template <class K, class V>
struct CerHashtable : public valueType<CerHashtable<K, V>> {
  private: CLASS(Table) : public object {
    public: void ctor(Int32 size);
    public: void Insert(K key, V value);
    public: Array<K> m_keys;
    public: Array<V> m_values;
    public: Int32 m_count;
  };
  public: V get_Item(K key);
  public: void set_Item(K key, V value);
  private: static Int32 GetHashCodeHelper(K key);
  private: void Rehash(Int32 newSize);
  private: Table m_Table;
};
} // namespace CerHashtableNamespace
template <class K, class V>
using CerHashtable = CerHashtableNamespace::CerHashtable<K, V>;
} // namespace System::Private::CoreLib::System::Reflection
