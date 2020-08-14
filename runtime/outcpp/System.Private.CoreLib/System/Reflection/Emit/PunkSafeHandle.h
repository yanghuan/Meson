#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/SafeHandle.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace PunkSafeHandleNamespace {
using namespace System::Runtime::InteropServices;
CLASS(PunkSafeHandle) : public SafeHandle::in {
  private: CLASS(DRelease) : public MulticastDelegate::in {
    public: void ctor(Object object, IntPtr method);
    public: void Invoke(IntPtr punk);
    public: IAsyncResult BeginInvoke(IntPtr punk, AsyncCallback callback, Object object);
    public: void EndInvoke(IAsyncResult result);
  };
  public: Boolean get_IsInvalid();
  protected: Boolean ReleaseHandle();
  private: static IntPtr nGetDReleaseTarget();
  private: static void cctor();
  private: static DRelease m_Release;
};
} // namespace PunkSafeHandleNamespace
using PunkSafeHandle = PunkSafeHandleNamespace::PunkSafeHandle;
} // namespace System::Private::CoreLib::System::Reflection::Emit
