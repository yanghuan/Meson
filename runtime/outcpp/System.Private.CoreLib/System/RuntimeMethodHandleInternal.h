#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
namespace RuntimeMethodHandleInternalNamespace {
struct RuntimeMethodHandleInternal {
  public: static RuntimeMethodHandleInternal get_EmptyHandle();
  public: IntPtr get_Value();
  public: Boolean IsNullHandle();
  public: void Ctor(IntPtr value);
  public: void Ctor();
  public: IntPtr m_handle;
};
} // namespace RuntimeMethodHandleInternalNamespace
using RuntimeMethodHandleInternal = RuntimeMethodHandleInternalNamespace::RuntimeMethodHandleInternal;
} // namespace System::Private::CoreLib::System
