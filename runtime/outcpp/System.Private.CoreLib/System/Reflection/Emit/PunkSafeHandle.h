#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(AsyncCallback)
FORWARDS(Boolean)
FORWARD(IAsyncResult)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace PunkSafeHandleNamespace {
CLASS(PunkSafeHandle) {
  private: CLASS(DRelease) {
    public: void Ctor(Object object, IntPtr method);
    public: void Invoke(IntPtr punk);
    public: IAsyncResult BeginInvoke(IntPtr punk, AsyncCallback callback, Object object);
    public: void EndInvoke(IAsyncResult result);
  };
  public: Boolean get_IsInvalid();
  protected: Boolean ReleaseHandle();
  private: static IntPtr nGetDReleaseTarget();
  private: static void SCtor();
  private: static DRelease m_Release;
};
} // namespace PunkSafeHandleNamespace
using PunkSafeHandle = PunkSafeHandleNamespace::PunkSafeHandle;
} // namespace System::Private::CoreLib::System::Reflection::Emit
