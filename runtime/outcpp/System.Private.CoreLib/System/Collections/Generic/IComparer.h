#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace IComparerNamespace {
CLASS(IComparer, T) {
  public: Int32 Compare(T x, T y);
};
} // namespace IComparerNamespace
template <class T>
using IComparer = IComparerNamespace::IComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
