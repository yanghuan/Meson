#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace SafeHandleCleanupWorkListElementNamespace {
using namespace Runtime::InteropServices;
CLASS(SafeHandleCleanupWorkListElement) {
  public: void Ctor(SafeHandle handle);
  protected: void DestroyCore();
  public: IntPtr AddRef();
  private: SafeHandle m_handle;
  private: Boolean m_owned;
};
} // namespace SafeHandleCleanupWorkListElementNamespace
using SafeHandleCleanupWorkListElement = SafeHandleCleanupWorkListElementNamespace::SafeHandleCleanupWorkListElement;
} // namespace System::Private::CoreLib::System::StubHelpers
