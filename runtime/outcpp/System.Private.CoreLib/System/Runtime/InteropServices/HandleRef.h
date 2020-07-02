#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/IntPtr.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace HandleRefNamespace {
struct HandleRef {
  public: Object get_Wrapper();
  public: IntPtr get_Handle();
  public: static IntPtr ToIntPtr(HandleRef value);
  private: Object _wrapper;
  private: IntPtr _handle;
};
} // namespace HandleRefNamespace
using HandleRef = HandleRefNamespace::HandleRef;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
