#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(UInt32)
FORWARD(Object)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace IBindableVectorViewNamespace {
CLASS(IBindableVectorView) {
  public: UInt32 get_Size();
  public: Object GetAt(UInt32 index);
  public: Boolean IndexOf(Object value, UInt32& index);
};
} // namespace IBindableVectorViewNamespace
using IBindableVectorView = IBindableVectorViewNamespace::IBindableVectorView;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
