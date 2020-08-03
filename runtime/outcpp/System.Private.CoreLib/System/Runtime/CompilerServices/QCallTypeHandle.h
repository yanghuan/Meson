#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(RuntimeType)
FORWARDS(RuntimeTypeHandle)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace QCallTypeHandleNamespace {
struct QCallTypeHandle : public valueType<QCallTypeHandle> {
  public: explicit QCallTypeHandle(RuntimeType& type);
  public: explicit QCallTypeHandle(RuntimeTypeHandle& rth);
  public: explicit QCallTypeHandle() {}
  private: void* _ptr;
  private: IntPtr _handle;
};
} // namespace QCallTypeHandleNamespace
using QCallTypeHandle = QCallTypeHandleNamespace::QCallTypeHandle;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
