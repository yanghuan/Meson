#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
enum class LazyThreadSafetyMode;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS_(Nullable, T1, T2)
FORWARD_(Lazy, T1, T2, T3)
namespace LazyDebugViewNamespace {
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(LazyDebugView, T) {
  public: Boolean get_IsValueCreated();
  public: T get_Value();
  public: Nullable<LazyThreadSafetyMode> get_Mode();
  public: Boolean get_IsValueFaulted();
  private: Lazy<T> _lazy;
};
} // namespace LazyDebugViewNamespace
template <class T>
using LazyDebugView = LazyDebugViewNamespace::LazyDebugView<T>;
} // namespace System::Private::CoreLib::System
