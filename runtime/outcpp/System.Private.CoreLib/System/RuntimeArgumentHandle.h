#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
namespace RuntimeArgumentHandleNamespace {
struct RuntimeArgumentHandle {
  public: IntPtr get_Value();
  public: void Ctor();
  private: IntPtr m_ptr;
};
} // namespace RuntimeArgumentHandleNamespace
using RuntimeArgumentHandle = RuntimeArgumentHandleNamespace::RuntimeArgumentHandle;
} // namespace System::Private::CoreLib::System
