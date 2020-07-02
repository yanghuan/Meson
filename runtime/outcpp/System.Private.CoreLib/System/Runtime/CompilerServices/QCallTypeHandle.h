#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace QCallTypeHandleNamespace {
struct QCallTypeHandle {
  private: IntPtr m_ptr;
  private: IntPtr m_handle;
};
} // namespace QCallTypeHandleNamespace
using QCallTypeHandle = QCallTypeHandleNamespace::QCallTypeHandle;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
