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
  public: void Ctor(RuntimeType& type);
  public: void Ctor(RuntimeTypeHandle& rth);
  public: void Ctor();
  private: void* _ptr;
  private: IntPtr _handle;
};
} // namespace QCallTypeHandleNamespace
using QCallTypeHandle = QCallTypeHandleNamespace::QCallTypeHandle;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
