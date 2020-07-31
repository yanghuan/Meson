#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IReadOnlyCollectionNamespace {
CLASS(IReadOnlyCollection, T) : public Object::in {
  public: Int32 get_Count();
};
} // namespace IReadOnlyCollectionNamespace
template <class T>
using IReadOnlyCollection = IReadOnlyCollectionNamespace::IReadOnlyCollection<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
