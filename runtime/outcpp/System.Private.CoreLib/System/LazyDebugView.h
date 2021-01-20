#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
enum class LazyThreadSafetyMode : int32_t;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Lazy)
FORWARDS_(Nullable)
namespace LazyDebugViewNamespace {
using namespace System::Threading;
CLASS(LazyDebugView, T) : public object {
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
