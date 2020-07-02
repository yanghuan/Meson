#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARDS_(KeyValuePair, T1, T2, T3)
FORWARD(IComparer, T)
FORWARD(IEnumerator, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD(Object)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IKeyValuePair, K, V)
FORWARD(IIterator, T)
FORWARD(IMapView, K, V)
namespace ConstantSplittableMapNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
using System::Collections::Generic::IEnumerator;
CLASS(ConstantSplittableMap, TKey, TValue) {
  private: CLASS(KeyValuePairComparator) {
    public: Int32 Compare(KeyValuePair<TKey, TValue> x, KeyValuePair<TKey, TValue> y);
    private: static IComparer<TKey> keyComparator;
  };
  public: struct IKeyValuePairEnumerator {
    public: IKeyValuePair<TKey, TValue> get_Current();
    private: Object get_CurrentOfIEnumerator();
    public: Boolean MoveNext();
    public: void Dispose();
    private: Array<KeyValuePair<TKey, TValue>> _array;
    private: Int32 _start;
    private: Int32 _end;
    private: Int32 _current;
  };
  public: Int32 get_Count();
  public: UInt32 get_Size();
  private: Array<KeyValuePair<TKey, TValue>> CreateKeyValueArray(Int32 count, IEnumerator<KeyValuePair<TKey, TValue>> data);
  public: TValue Lookup(TKey key);
  public: Boolean HasKey(TKey key);
  public: IIterator<IKeyValuePair<TKey, TValue>> First();
  public: IEnumerator<IKeyValuePair<TKey, TValue>> GetEnumerator();
  public: void Split(IMapView<TKey, TValue>& firstPartition, IMapView<TKey, TValue>& secondPartition);
  public: Boolean TryGetValue(TKey key, TValue& value);
  private: static KeyValuePairComparator keyValuePairComparator;
  private: Array<KeyValuePair<TKey, TValue>> items;
  private: Int32 firstItemIndex;
  private: Int32 lastItemIndex;
};
} // namespace ConstantSplittableMapNamespace
template <class TKey, class TValue>
using ConstantSplittableMap = ConstantSplittableMapNamespace::ConstantSplittableMap<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
