#pragma once

#include <System.Private.CoreLib/System/IntPtr.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::InteropServices {
namespace HandleRefNamespace {
struct HandleRef : public valueType<HandleRef> {
  public: Object get_Wrapper();
  public: IntPtr get_Handle();
  public: explicit HandleRef(Object wrapper, IntPtr handle);
  public: static IntPtr op_Explicit(HandleRef value);
  public: static IntPtr ToIntPtr(HandleRef value);
  public: explicit HandleRef() {}
  private: Object _wrapper;
  private: IntPtr _handle;
};
} // namespace HandleRefNamespace
using HandleRef = HandleRefNamespace::HandleRef;
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
