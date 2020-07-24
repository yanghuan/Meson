#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARD(RuntimeType)
FORWARDS(RuntimeTypeHandle)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace QCallTypeHandleNamespace {
struct QCallTypeHandle {
  public: explicit QCallTypeHandle(RuntimeType& type);
  public: explicit QCallTypeHandle(RuntimeTypeHandle& rth);
  public: explicit QCallTypeHandle() {}
  private: void* _ptr;
  private: IntPtr _handle;
};
} // namespace QCallTypeHandleNamespace
using QCallTypeHandle = QCallTypeHandleNamespace::QCallTypeHandle;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
