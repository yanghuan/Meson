#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARD(Object)
namespace Gen2GcCallbackNamespace {
using namespace Runtime::InteropServices;
CLASS(Gen2GcCallback) {
  public: static void Register(Func<Object, Boolean> callback, Object targetObj);
  protected: void Finalize();
  private: Func<Boolean> _callback0;
  private: Func<Object, Boolean> _callback1;
  private: GCHandle _weakTargetObj;
};
} // namespace Gen2GcCallbackNamespace
using Gen2GcCallback = Gen2GcCallbackNamespace::Gen2GcCallback;
} // namespace System::Private::CoreLib::System
