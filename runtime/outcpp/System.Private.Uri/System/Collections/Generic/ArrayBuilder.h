#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
} // namespace System::Private::CoreLib::System
namespace System::Private::Uri::System::Collections::Generic {
namespace ArrayBuilderNamespace {
using namespace ::System::Private::CoreLib::System;
template <class T>
struct ArrayBuilder : public valueType<ArrayBuilder<T>> {
  public: Int32 get_Capacity();
  public: void Add(T item);
  public: Array<T> ToArray();
  public: void UncheckedAdd(T item);
  private: void EnsureCapacity(Int32 minimum);
  private: Array<T> _array;
  private: Int32 _count;
};
} // namespace ArrayBuilderNamespace
template <class T>
using ArrayBuilder = ArrayBuilderNamespace::ArrayBuilder<T>;
} // namespace System::Private::Uri::System::Collections::Generic
