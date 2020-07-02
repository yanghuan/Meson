#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt32)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IVectorViewNamespace {
CLASS(IVectorView, T) {
  public: UInt32 get_Size();
  public: T GetAt(UInt32 index);
  public: Boolean IndexOf(T value, UInt32& index);
  public: UInt32 GetMany(UInt32 startIndex, Array<T> items);
};
} // namespace IVectorViewNamespace
template <class T>
using IVectorView = IVectorViewNamespace::IVectorView<T>;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
