#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
namespace RuntimeFieldHandleInternalNamespace {
struct RuntimeFieldHandleInternal : public valueType<RuntimeFieldHandleInternal> {
  public: IntPtr get_Value();
  public: explicit RuntimeFieldHandleInternal(IntPtr value);
  public: explicit RuntimeFieldHandleInternal() {}
  public: IntPtr m_handle;
};
} // namespace RuntimeFieldHandleInternalNamespace
using RuntimeFieldHandleInternal = RuntimeFieldHandleInternalNamespace::RuntimeFieldHandleInternal;
} // namespace System::Private::CoreLib::System
