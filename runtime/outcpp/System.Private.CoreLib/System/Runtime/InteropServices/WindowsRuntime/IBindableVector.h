#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
FORWARDS(UInt32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
FORWARD(IBindableVectorView)
namespace IBindableVectorNamespace {
CLASS(IBindableVector) {
  public: UInt32 get_Size();
  public: Object GetAt(UInt32 index);
  public: IBindableVectorView GetView();
  public: Boolean IndexOf(Object value, UInt32& index);
  public: void SetAt(UInt32 index, Object value);
  public: void InsertAt(UInt32 index, Object value);
  public: void RemoveAt(UInt32 index);
  public: void Append(Object value);
  public: void RemoveAtEnd();
  public: void Clear();
};
} // namespace IBindableVectorNamespace
using IBindableVector = IBindableVectorNamespace::IBindableVector;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
