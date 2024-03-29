#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
namespace ICollectionDebugViewNamespace {
template <class T>
using ICollection = Generic::ICollection<T>;
CLASS(ICollectionDebugView, T) : public object {
  public: Array<T> get_Items();
  public: void ctor(ICollection<T> collection);
  private: ICollection<T> _collection;
};
} // namespace ICollectionDebugViewNamespace
template <class T>
using ICollectionDebugView = ICollectionDebugViewNamespace::ICollectionDebugView<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
