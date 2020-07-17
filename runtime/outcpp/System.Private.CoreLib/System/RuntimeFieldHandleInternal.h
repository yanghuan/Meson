#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
namespace RuntimeFieldHandleInternalNamespace {
struct RuntimeFieldHandleInternal {
  public: IntPtr get_Value();
  public: void Ctor(IntPtr value);
  public: void Ctor();
  public: IntPtr m_handle;
};
} // namespace RuntimeFieldHandleInternalNamespace
using RuntimeFieldHandleInternal = RuntimeFieldHandleInternalNamespace::RuntimeFieldHandleInternal;
} // namespace System::Private::CoreLib::System
