#pragma once

#include <System.Private.CoreLib/System/Runtime/ConstrainedExecution/CriticalFinalizerObject.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Func)
FORWARD(Object)
namespace Gen2GcCallbackNamespace {
using namespace System::Runtime::ConstrainedExecution;
using namespace System::Runtime::InteropServices;
CLASS(Gen2GcCallback) : public CriticalFinalizerObject::in {
  public: void ctor(Func<Object, Boolean> callback, Object targetObj);
  public: static void Register(Func<Object, Boolean> callback, Object targetObj);
  protected: void Finalize();
  private: Func<Boolean> _callback0;
  private: Func<Object, Boolean> _callback1;
  private: GCHandle _weakTargetObj;
};
} // namespace Gen2GcCallbackNamespace
using Gen2GcCallback = Gen2GcCallbackNamespace::Gen2GcCallback;
} // namespace System::Private::CoreLib::System
