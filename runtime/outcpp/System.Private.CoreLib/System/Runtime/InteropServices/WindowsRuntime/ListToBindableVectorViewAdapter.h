#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt32)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
FORWARD(IList)
} // namespace System::Private::CoreLib::System::Collections
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IBindableIterator)
namespace ListToBindableVectorViewAdapterNamespace {
using namespace ::System::Private::CoreLib::System::Collections;
CLASS(ListToBindableVectorViewAdapter) {
  public: UInt32 get_Size();
  private: static void EnsureIndexInt32(UInt32 index, Int32 listCapacity);
  public: IBindableIterator First();
  public: Object GetAt(UInt32 index);
  public: Boolean IndexOf(Object value, UInt32& index);
  private: IList list;
};
} // namespace ListToBindableVectorViewAdapterNamespace
using ListToBindableVectorViewAdapter = ListToBindableVectorViewAdapterNamespace::ListToBindableVectorViewAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
