#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Span.h>

namespace System::Private::CoreLib::System {
FORWARDS(ReadOnlySpan, T)
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ValueListBuilderNamespace {
template <class T>
struct ValueListBuilder {
  public: void Append(T item);
  public: ReadOnlySpan<T> AsSpan();
  public: void Dispose();
  private: void Grow();
  private: Span<T> _span;
  private: Array<T> _arrayFromPool;
  private: Int32 _pos;
};
} // namespace ValueListBuilderNamespace
template <class T>
using ValueListBuilder = ValueListBuilderNamespace::ValueListBuilder<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
