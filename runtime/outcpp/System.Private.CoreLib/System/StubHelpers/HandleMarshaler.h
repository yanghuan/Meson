#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
FORWARD(SafeHandle)
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
namespace System::Private::CoreLib::System {
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::StubHelpers {
FORWARD(CleanupWorkListElement)
namespace HandleMarshalerNamespace {
using namespace System::Runtime::InteropServices;
CLASS(HandleMarshaler) : public object {
  public: static IntPtr ConvertSafeHandleToNative(SafeHandle handle, CleanupWorkListElement& cleanupWorkList);
  public: static void ThrowSafeHandleFieldChanged();
  public: static void ThrowCriticalHandleFieldChanged();
};
} // namespace HandleMarshalerNamespace
using HandleMarshaler = HandleMarshalerNamespace::HandleMarshaler;
} // namespace System::Private::CoreLib::System::StubHelpers
