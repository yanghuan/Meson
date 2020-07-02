#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt32)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IVectorView, T)
namespace IVector_RawNamespace {
CLASS(IVector_Raw, T) {
  public: UInt32 get_Size();
  public: T GetAt(UInt32 index);
  public: IVectorView<T> GetView();
  public: Boolean IndexOf(T value, UInt32& index);
  public: void SetAt(UInt32 index, T value);
  public: void InsertAt(UInt32 index, T value);
  public: void RemoveAt(UInt32 index);
  public: void Append(T value);
  public: void RemoveAtEnd();
  public: void Clear();
};
} // namespace IVector_RawNamespace
template <class T>
using IVector_Raw = IVector_RawNamespace::IVector_Raw<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
