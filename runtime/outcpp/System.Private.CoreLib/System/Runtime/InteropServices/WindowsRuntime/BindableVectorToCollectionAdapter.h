#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime {
namespace BindableVectorToCollectionAdapterNamespace {
CLASS(BindableVectorToCollectionAdapter) {
  public: Int32 Count();
  public: Boolean IsSynchronized();
  public: Object SyncRoot();
  public: void CopyTo(Array<> array, Int32 arrayIndex);
};
} // namespace BindableVectorToCollectionAdapterNamespace
using BindableVectorToCollectionAdapter = BindableVectorToCollectionAdapterNamespace::BindableVectorToCollectionAdapter;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime
