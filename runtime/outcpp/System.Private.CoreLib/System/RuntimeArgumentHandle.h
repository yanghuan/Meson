#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
namespace RuntimeArgumentHandleNamespace {
struct RuntimeArgumentHandle : public valueType<RuntimeArgumentHandle> {
  public: IntPtr get_Value();
  private: IntPtr m_ptr;
};
} // namespace RuntimeArgumentHandleNamespace
using RuntimeArgumentHandle = RuntimeArgumentHandleNamespace::RuntimeArgumentHandle;
} // namespace System::Private::CoreLib::System
