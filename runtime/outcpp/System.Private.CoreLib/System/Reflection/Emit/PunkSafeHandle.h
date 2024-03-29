#pragma once

#include <System.Private.CoreLib/System/MulticastDelegate.h>
#include <System.Private.CoreLib/System/Runtime/InteropServices/SafeHandle.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
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
    public: static constexpr rt::TypeCode code = rt::TypeCode::Delegate;
  };
  public: Boolean get_IsInvalid();
  protected: Boolean ReleaseHandle();
  private: static IntPtr nGetDReleaseTarget();
  public: static void cctor();
  private: static DRelease m_Release;
};
} // namespace PunkSafeHandleNamespace
using PunkSafeHandle = PunkSafeHandleNamespace::PunkSafeHandle;
} // namespace System::Private::CoreLib::System::Reflection::Emit
