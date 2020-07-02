#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
namespace SpanDebugViewNamespace {
CLASS(SpanDebugView, T) {
  public: Array<T> get_Items();
  private: Array<T> _array;
};
} // namespace SpanDebugViewNamespace
template <class T>
using SpanDebugView = SpanDebugViewNamespace::SpanDebugView<T>;
} // namespace System::Private::CoreLib::System
