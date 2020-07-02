#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System::Threading {
FORWARD(ThreadLocal, T)
namespace SystemThreading_ThreadLocalDebugViewNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
CLASS(SystemThreading_ThreadLocalDebugView, T) {
  public: Boolean get_IsValueCreated();
  public: T get_Value();
  public: List<T> get_Values();
  private: ThreadLocal<T> _tlocal;
};
} // namespace SystemThreading_ThreadLocalDebugViewNamespace
template <class T>
using SystemThreading_ThreadLocalDebugView = SystemThreading_ThreadLocalDebugViewNamespace::SystemThreading_ThreadLocalDebugView<T>;
} // namespace System::Private::CoreLib::System::Threading