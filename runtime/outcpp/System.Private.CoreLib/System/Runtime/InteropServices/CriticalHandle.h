#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace CriticalHandleNamespace {
CLASS(CriticalHandle) {
  public: Boolean get_IsClosed();
  public: Boolean get_IsInvalid();
  private: void ReleaseHandleFailed();
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
