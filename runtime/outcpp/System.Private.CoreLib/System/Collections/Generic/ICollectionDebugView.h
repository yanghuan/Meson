#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(ICollection, T)
namespace ICollectionDebugViewNamespace {
CLASS(ICollectionDebugView, T) {
  private: ICollection<T> _collection;
};
} // namespace ICollectionDebugViewNamespace
template <class T>
using ICollectionDebugView = ICollectionDebugViewNamespace::ICollectionDebugView<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
