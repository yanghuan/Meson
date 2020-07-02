#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IBindableVector)
namespace BindableVectorToListAdapterNamespace {
CLASS(BindableVectorToListAdapter) {
  public: Object Indexer_Get(Int32 index);
  public: void Indexer_Set(Int32 index, Object value);
  public: Int32 Add(Object value);
  public: Boolean Contains(Object item);
  public: void Clear();
  public: Boolean IsFixedSize();
  public: Boolean IsReadOnly();
  public: Int32 IndexOf(Object item);
  public: void Insert(Int32 index, Object item);
  public: void Remove(Object item);
  public: void RemoveAt(Int32 index);
  private: static Object GetAt(IBindableVector _this, UInt32 index);
  private: static void SetAt(IBindableVector _this, UInt32 index, Object value);
  private: static void InsertAtHelper(IBindableVector _this, UInt32 index, Object item);
  private: static void RemoveAtHelper(IBindableVector _this, UInt32 index);
};
} // namespace BindableVectorToListAdapterNamespace
using BindableVectorToListAdapter = BindableVectorToListAdapterNamespace::BindableVectorToListAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
