#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/Runtime/ConstrainedExecution/CriticalFinalizerObject.h>

namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace CriticalHandleNamespace {
using namespace ConstrainedExecution;
CLASS(CriticalHandle) : public CriticalFinalizerObject::in {
  using interface = rt::TypeList<IDisposable>;
  public: Boolean get_IsClosed();
  public: Boolean get_IsInvalid();
  protected: void Ctor(IntPtr invalidHandleValue);
  protected: void Finalize();
  private: void Cleanup();
  protected: void SetHandle(IntPtr handle);
  public: void Close();
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  public: void SetHandleAsInvalid();
  protected: Boolean ReleaseHandle();
  protected: IntPtr handle;
  private: Boolean _isClosed;
};
} // namespace CriticalHandleNamespace
using CriticalHandle = CriticalHandleNamespace::CriticalHandle;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
