#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(Object)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections {
namespace ICollectionNamespace {
CLASS(ICollection) {
  public: Int32 get_Count();
  public: Object get_SyncRoot();
  public: Boolean get_IsSynchronized();
  public: void CopyTo(Array<> array, Int32 index);
};
} // namespace ICollectionNamespace
using ICollection = ICollectionNamespace::ICollection;
} // namespace System::Private::CoreLib::System::Collections
