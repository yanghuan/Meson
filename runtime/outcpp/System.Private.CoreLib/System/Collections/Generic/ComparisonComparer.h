#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Comparison, T)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ComparisonComparerNamespace {
CLASS(ComparisonComparer, T) {
  public: Int32 Compare(T x, T y);
  private: Comparison<T> _comparison;
};
} // namespace ComparisonComparerNamespace
template <class T>
using ComparisonComparer = ComparisonComparerNamespace::ComparisonComparer<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
