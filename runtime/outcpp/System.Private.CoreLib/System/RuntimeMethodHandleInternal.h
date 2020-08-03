#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
namespace RuntimeMethodHandleInternalNamespace {
struct RuntimeMethodHandleInternal : public valueType<RuntimeMethodHandleInternal> {
  public: static RuntimeMethodHandleInternal get_EmptyHandle();
  public: IntPtr get_Value();
  public: Boolean IsNullHandle();
  public: explicit RuntimeMethodHandleInternal(IntPtr value);
  public: explicit RuntimeMethodHandleInternal() {}
  public: IntPtr m_handle;
};
} // namespace RuntimeMethodHandleInternalNamespace
using RuntimeMethodHandleInternal = RuntimeMethodHandleInternalNamespace::RuntimeMethodHandleInternal;
} // namespace System::Private::CoreLib::System
