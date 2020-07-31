#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
namespace ICollectionDebugViewNamespace {
CLASS(ICollectionDebugView, T) : public Object::in {
  public: Array<T> get_Items();
  public: void Ctor(ICollection<T> collection);
  private: ICollection<T> _collection;
};
} // namespace ICollectionDebugViewNamespace
template <class T>
using ICollectionDebugView = ICollectionDebugViewNamespace::ICollectionDebugView<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
