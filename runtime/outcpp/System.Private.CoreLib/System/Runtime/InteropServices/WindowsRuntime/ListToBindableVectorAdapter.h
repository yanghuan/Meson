#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IBindableVectorView)
namespace ListToBindableVectorAdapterNamespace {
CLASS(ListToBindableVectorAdapter) {
  public: Object GetAt(UInt32 index);
  public: UInt32 Size();
  public: IBindableVectorView GetView();
  public: Boolean IndexOf(Object value, UInt32& index);
  public: void SetAt(UInt32 index, Object value);
  public: void InsertAt(UInt32 index, Object value);
  public: void RemoveAt(UInt32 index);
  public: void Append(Object value);
  public: void RemoveAtEnd();
  public: void Clear();
  private: static void EnsureIndexInt32(UInt32 index, Int32 listCapacity);
};
} // namespace ListToBindableVectorAdapterNamespace
using ListToBindableVectorAdapter = ListToBindableVectorAdapterNamespace::ListToBindableVectorAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
