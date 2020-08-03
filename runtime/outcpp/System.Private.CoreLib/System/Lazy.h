#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
enum class LazyThreadSafetyMode;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(LazyHelper)
FORWARDS_(Nullable, T1, T2)
namespace LazyNamespace {
using namespace Threading;
CLASS_FORWARD(Lazy, T1, T2, T3)
CLASS_(Lazy, T) : public Object::in {
  public: T get_ValueForDebugDisplay();
  public: Nullable<LazyThreadSafetyMode> get_Mode();
  public: Boolean get_IsValueFaulted();
  public: Boolean get_IsValueCreated();
  public: T get_Value();
  private: LazyHelper _state;
  private: Func<T> _factory;
  private: T _value;
};
CLASS_(Lazy, T, TMetadata) : public Lazy<T>::in {
  public: TMetadata get_Metadata();
  private: TMetadata _metadata;
};
} // namespace LazyNamespace
template <class T1 = void, class T2 = void, class T3 = void>
using Lazy = LazyNamespace::Lazy<T1, T2, T3>;
} // namespace System::Private::CoreLib::System
