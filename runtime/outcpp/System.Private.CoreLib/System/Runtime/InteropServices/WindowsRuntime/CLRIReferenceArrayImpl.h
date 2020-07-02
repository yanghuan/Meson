#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IList)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace CLRIReferenceArrayImplNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
CLASS(CLRIReferenceArrayImpl, T) {
  public: Array<T> get_Value();
  private: Object get_ItemOfIList(Int32 index);
  private: void set_ItemOfIList(Int32 index, Object value);
  private: Boolean get_IsReadOnlyOfIList();
  private: Boolean get_IsFixedSizeOfIList();
  private: Int32 get_CountOfICollection();
  private: Object get_SyncRootOfICollection();
  private: Boolean get_IsSynchronizedOfICollection();
  public: String ToString();
  public: static Object UnboxHelper(Object wrapper);
  private: Array<T> _value;
  private: IList _list;
};
} // namespace CLRIReferenceArrayImplNamespace
template <class T>
using CLRIReferenceArrayImpl = CLRIReferenceArrayImplNamespace::CLRIReferenceArrayImpl<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
