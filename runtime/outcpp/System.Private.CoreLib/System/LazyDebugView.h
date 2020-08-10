#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
enum class LazyThreadSafetyMode;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Lazy, T1, T2, T3)
FORWARDS_(Nullable, T1, T2)
namespace LazyDebugViewNamespace {
using namespace Threading;
CLASS(LazyDebugView, T) : public Object::in {
  public: Boolean get_IsValueCreated();
  public: T get_Value();
  public: Nullable<LazyThreadSafetyMode> get_Mode();
  public: Boolean get_IsValueFaulted();
  public: void ctor(Lazy<T> lazy);
  private: Lazy<T> _lazy;
};
} // namespace LazyDebugViewNamespace
template <class T>
using LazyDebugView = LazyDebugViewNamespace::LazyDebugView<T>;
} // namespace System::Private::CoreLib::System
