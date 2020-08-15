#include "Gen2GcCallback-dep.h"

#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Gen2GcCallback-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandle-dep.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/GCHandleType.h>

namespace System::Private::CoreLib::System::Gen2GcCallbackNamespace {
using namespace System::Runtime::InteropServices;

void Gen2GcCallback___::ctor(Func<Object, Boolean> callback, Object targetObj) {
  _callback1 = callback;
  _weakTargetObj = GCHandle::Alloc(targetObj, GCHandleType::Weak);
}

void Gen2GcCallback___::Register(Func<Object, Boolean> callback, Object targetObj) {
  rt::newobj<Gen2GcCallback>(callback, targetObj);
}

void Gen2GcCallback___::Finalize() {
  if (_weakTargetObj.get_IsAllocated()) {
    Object target = _weakTargetObj.get_Target();
    if (target == nullptr) {
      _weakTargetObj.Free();
      return;
    }
    try{
      if (!_callback1(target)) {
        return;
      }
    } catch (...) {
    }
    goto IL_0054;
  }
  try{
    if (!_callback0()) {
      return;
    }
  } catch (...) {
  }
  goto IL_0054;

IL_0054:
  GC::ReRegisterForFinalize((Gen2GcCallback)this);
}

} // namespace System::Private::CoreLib::System::Gen2GcCallbackNamespace
