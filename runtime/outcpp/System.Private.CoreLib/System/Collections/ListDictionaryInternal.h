#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARDS(DictionaryEntry)
FORWARD(ICollection)
FORWARD(IDictionaryEnumerator)
namespace ListDictionaryInternalNamespace {
CLASS(ListDictionaryInternal) : public Object::in {
  private: CLASS(DictionaryNode) : public Object::in {
    public: void Ctor();
    public: Object key;
    public: Object value;
    public: DictionaryNode next;
  };
  private: CLASS(NodeEnumerator) : public Object::in {
    public: Object get_Current();
    public: DictionaryEntry get_Entry();
    public: Object get_Key();
    public: Object get_Value();
    public: void Ctor(ListDictionaryInternal list);
    public: Boolean MoveNext();
    public: void Reset();
    private: ListDictionaryInternal list;
    private: DictionaryNode current;
    private: Int32 version;
    private: Boolean start;
  };
  private: CLASS(NodeKeyValueCollection) : public Object::in {
    private: CLASS(NodeKeyValueEnumerator) : public Object::in {
      public: Object get_Current();
      public: void Ctor(ListDictionaryInternal list, Boolean isKeys);
      public: Boolean MoveNext();
      public: void Reset();
      private: ListDictionaryInternal list;
      private: DictionaryNode current;
      private: Int32 version;
      private: Boolean isKeys;
      private: Boolean start;
    };
    private: Int32 get_CountOfICollection();
    private: Boolean get_IsSynchronizedOfICollection();
    private: Object get_SyncRootOfICollection();
    public: void Ctor(ListDictionaryInternal list, Boolean isKeys);
    private: ListDictionaryInternal list;
    private: Boolean isKeys;
  };
  public: Object get_Item(Object key);
  public: void set_Item(Object key, Object value);
  public: Int32 get_Count();
  public: ICollection get_Keys();
  public: Boolean get_IsReadOnly();
  public: Boolean get_IsFixedSize();
  public: Boolean get_IsSynchronized();
  public: Object get_SyncRoot();
  public: ICollection get_Values();
  public: void Ctor();
  public: void Add(Object key, Object value);
  public: void Clear();
  public: Boolean Contains(Object key);
  public: void CopyTo(Array<> array, Int32 index);
  public: IDictionaryEnumerator GetEnumerator();
  public: void Remove(Object key);
  private: DictionaryNode head;
  private: Int32 version;
  private: Int32 count;
};
} // namespace ListDictionaryInternalNamespace
using ListDictionaryInternal = ListDictionaryInternalNamespace::ListDictionaryInternal;
} // namespace System::Private::CoreLib::System::Collections
