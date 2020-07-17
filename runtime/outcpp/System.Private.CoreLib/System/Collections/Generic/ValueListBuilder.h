#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Span.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(ReadOnlySpan, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ValueListBuilderNamespace {
template <class T>
struct ValueListBuilder {
  public: Int32 get_Length();
  public: void Ctor(Span<T> initialSpan);
  public: void Append(T item);
  public: ReadOnlySpan<T> AsSpan();
  public: void Dispose();
  private: void Grow();
  public: void Ctor();
  private: Span<T> _span;
  private: Array<T> _arrayFromPool;
  private: Int32 _pos;
};
} // namespace ValueListBuilderNamespace
template <class T>
using ValueListBuilder = ValueListBuilderNamespace::ValueListBuilder<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
