#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Collections/Generic/KeyValuePair.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/DependentHandle.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARD(Object)
FORWARD(IAsyncResult)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ConditionalWeakTableNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(ConditionalWeakTable, TKey, TValue) {
  private: struct Entry {
    public: DependentHandle depHnd;
    public: Int32 HashCode;
    public: Int32 Next;
  };
  public: CLASS(CreateValueCallback) {
    public: TValue Invoke(TKey key);
    public: IAsyncResult BeginInvoke(TKey key, AsyncCallback callback, Object object);
    public: TValue EndInvoke(IAsyncResult result);
  };
  private: CLASS(Enumerator) {
    public: KeyValuePair<TKey, TValue> get_Current();
    private: Object get_CurrentOfIEnumerator();
    protected: void Finalize();
    public: void Dispose();
    public: Boolean MoveNext();
    public: void Reset();
    private: ConditionalWeakTable<TKey, TValue> _table;
    private: Int32 _maxIndexInclusive;
    private: Int32 _currentIndex;
    private: KeyValuePair<TKey, TValue> _current;
  };
  private: CLASS(Container) {
    public: Boolean get_HasCapacity();
    public: Int32 get_FirstFreeEntry();
    public: void CreateEntryNoResize(TKey key, TValue value);
    public: Boolean TryGetValueWorker(TKey key, TValue& value);
    public: Int32 FindEntry(TKey key, Object& value);
    public: Boolean TryGetEntry(Int32 index, TKey& key, TValue& value);
    public: void RemoveAllKeys();
    public: Boolean Remove(TKey key);
    private: void RemoveIndex(Int32 entryIndex);
    public: void UpdateValue(Int32 entryIndex, TValue newValue);
    public: Container Resize();
    public: Container Resize(Int32 newSize);
    private: void VerifyIntegrity();
    protected: void Finalize();
    private: ConditionalWeakTable<TKey, TValue> _parent;
    private: Array<Int32> _buckets;
    private: Array<Entry> _entries;
    private: Int32 _firstFreeEntry;
    private: Boolean _invalid;
    private: Boolean _finalized;
    private: Object _oldKeepAlive;
  };
  public: Boolean TryGetValue(TKey key, TValue& value);
  public: void Add(TKey key, TValue value);
  public: void AddOrUpdate(TKey key, TValue value);
  public: Boolean Remove(TKey key);
  public: void Clear();
  public: TValue GetValue(TKey key, CreateValueCallback createValueCallback);
  private: TValue GetValueLocked(TKey key, CreateValueCallback createValueCallback);
  public: TValue GetOrCreateValue(TKey key);
  private: void CreateEntry(TKey key, TValue value);
  private: Object _lock;
  private: Container _container;
  private: Int32 _activeEnumeratorRefCount;
};
} // namespace ConditionalWeakTableNamespace
template <class TKey, class TValue>
using ConditionalWeakTable = ConditionalWeakTableNamespace::ConditionalWeakTable<TKey, TValue>;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
