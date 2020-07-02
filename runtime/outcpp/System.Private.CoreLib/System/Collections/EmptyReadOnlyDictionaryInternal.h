#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
FORWARD(ICollection)
FORWARD(IDictionaryEnumerator)
namespace EmptyReadOnlyDictionaryInternalNamespace {
CLASS(EmptyReadOnlyDictionaryInternal) {
  private: CLASS(NodeEnumerator) {
    public: Object get_Current();
    public: Object get_Key();
    public: Object get_Value();
    public: DictionaryEntry get_Entry();
    public: Boolean MoveNext();
    public: void Reset();
  };
  public: Int32 get_Count();
  public: Object get_SyncRoot();
  public: Boolean get_IsSynchronized();
  public: Object get_Item(Object key);
  public: void set_Item(Object key, Object value);
  public: ICollection get_Keys();
  public: ICollection get_Values();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: void CopyTo(Array<> array, Int32 index);
  public: Boolean Contains(Object key);
  public: void Add(Object key, Object value);
  public: void Clear();
  public: IDictionaryEnumerator GetEnumerator();
  public: void Remove(Object key);
};
} // namespace EmptyReadOnlyDictionaryInternalNamespace
using EmptyReadOnlyDictionaryInternal = EmptyReadOnlyDictionaryInternalNamespace::EmptyReadOnlyDictionaryInternal;
} // namespace System::Private::CoreLib::System::Collections