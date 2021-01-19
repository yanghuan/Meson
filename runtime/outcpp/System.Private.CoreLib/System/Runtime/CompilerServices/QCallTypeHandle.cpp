#include "QCallTypeHandle-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::QCallTypeHandleNamespace {
using namespace Internal::Runtime::CompilerServices;

QCallTypeHandle::QCallTypeHandle(RuntimeType& type) {
  _ptr = Unsafe::AsPointer(type);
  if (type != nullptr) {
    _handle = type->GetUnderlyingNativeHandle();
  } else {
    _handle = IntPtr::Zero;
  }
}

QCallTypeHandle::QCallTypeHandle(RuntimeTypeHandle& rth) {
  _ptr = Unsafe::AsPointer(rth);
  _handle = rth.get_Value();
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::QCallTypeHandleNamespace
