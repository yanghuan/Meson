#include "HandleMarshaler-dep.h"

#include <System.Private.CoreLib/Internal/Runtime/CompilerServices/Unsafe-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/StubHelpers/StubHelpers-dep.h>

namespace System::Private::CoreLib::System::StubHelpers::HandleMarshalerNamespace {
using namespace Internal::Runtime::CompilerServices;

IntPtr HandleMarshaler___::ConvertSafeHandleToNative(SafeHandle handle, CleanupWorkListElement& cleanupWorkList) {
  if (Unsafe::IsNullRef(cleanupWorkList)) {
    rt::throw_exception<InvalidOperationException>(SR::get_Interop_Marshal_SafeHandle_InvalidOperation());
  }
  if (handle == nullptr) {
    rt::throw_exception<ArgumentNullException>("handle");
  }
  return StubHelpers::AddToCleanupList(cleanupWorkList, handle);
}

void HandleMarshaler___::ThrowSafeHandleFieldChanged() {
  rt::throw_exception<NotSupportedException>(SR::get_Interop_Marshal_CannotCreateSafeHandleField());
}

void HandleMarshaler___::ThrowCriticalHandleFieldChanged() {
  rt::throw_exception<NotSupportedException>(SR::get_Interop_Marshal_CannotCreateCriticalHandleField());
}

} // namespace System::Private::CoreLib::System::StubHelpers::HandleMarshalerNamespace
