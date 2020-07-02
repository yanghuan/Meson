#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Boolean)
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(ThreadPoolWorkQueue)
namespace ThreadPoolGlobalsNamespace {
class ThreadPoolGlobals {
  public: static Int32 processorCount;
  public: static Boolean threadPoolInitialized;
  public: static Boolean enableWorkerTracking;
  public: static ThreadPoolWorkQueue workQueue;
  public: static Action<Object> s_invokeAsyncStateMachineBox;
};
} // namespace ThreadPoolGlobalsNamespace
using ThreadPoolGlobals = ThreadPoolGlobalsNamespace::ThreadPoolGlobals;
} // namespace System::Private::CoreLib::System::Threading
