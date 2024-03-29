#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Span.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(ReadOnlySpan, T)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
namespace ValueListBuilderNamespace {
template <class T>
struct ValueListBuilder : public valueType<ValueListBuilder<T>> {
  public: Int32 get_Length();
  public: explicit ValueListBuilder(Span<T> initialSpan);
  public: void Append(T item);
  public: ReadOnlySpan<T> AsSpan();
  public: void Dispose();
  private: void Grow();
  public: explicit ValueListBuilder() {}
  private: Span<T> _span;
  private: Array<T> _arrayFromPool;
  private: Int32 _pos;
};
} // namespace ValueListBuilderNamespace
template <class T>
using ValueListBuilder = ValueListBuilderNamespace::ValueListBuilder<T>;
} // namespace System::Private::CoreLib::System::Collections::Generic
