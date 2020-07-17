#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(ReadOnlySpan, T)
FORWARDS(Span, T)
namespace SpanDebugViewNamespace {
CLASS(SpanDebugView, T) {
  public: Array<T> get_Items();
  public: void Ctor(Span<T> span);
  public: void Ctor(ReadOnlySpan<T> span);
  private: Array<T> _array;
};
} // namespace SpanDebugViewNamespace
template <class T>
using SpanDebugView = SpanDebugViewNamespace::SpanDebugView<T>;
} // namespace System::Private::CoreLib::System
