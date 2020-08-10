#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/StubHelpers/CleanupWorkListElement.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
namespace SafeHandleCleanupWorkListElementNamespace {
using namespace Runtime::InteropServices;
CLASS(SafeHandleCleanupWorkListElement) : public CleanupWorkListElement::in {
  public: void ctor(SafeHandle handle);
  protected: void DestroyCore();
  public: IntPtr AddRef();
  private: SafeHandle m_handle;
  private: Boolean m_owned;
};
} // namespace SafeHandleCleanupWorkListElementNamespace
using SafeHandleCleanupWorkListElement = SafeHandleCleanupWorkListElementNamespace::SafeHandleCleanupWorkListElement;
} // namespace System::Private::CoreLib::System::StubHelpers
