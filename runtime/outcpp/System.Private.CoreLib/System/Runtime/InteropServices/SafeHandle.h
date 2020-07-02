#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace SafeHandleNamespace {
CLASS(SafeHandle) {
  public: Boolean get_IsClosed();
  public: Boolean get_IsInvalid();
  protected: void Finalize();
  protected: void SetHandle(IntPtr handle);
  public: IntPtr DangerousGetHandle();
  public: void Close();
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  public: void SetHandleAsInvalid();
  protected: Boolean ReleaseHandle();
  public: void DangerousAddRef(Boolean& success);
  public: void DangerousRelease();
  private: void InternalRelease(Boolean disposeOrFinalizeOperation);
  protected: IntPtr handle;
  private: Int32 _state;
  private: Boolean _ownsHandle;
  private: Boolean _fullyInitialized;
};
} // namespace SafeHandleNamespace
using SafeHandle = SafeHandleNamespace::SafeHandle;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
