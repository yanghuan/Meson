#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Comparison, T)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ComparerNamespace {
CLASS(Comparer, T) {
  public: static Comparer<T> Create(Comparison<T> comparison);
  public: Int32 Compare(T x, T y);
};
} // namespace ComparerNamespace
template <class T>
using Comparer = ComparerNamespace::Comparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
