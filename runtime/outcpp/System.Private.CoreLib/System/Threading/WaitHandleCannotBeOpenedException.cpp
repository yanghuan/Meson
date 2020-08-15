#include "WaitHandleCannotBeOpenedException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Threading::WaitHandleCannotBeOpenedExceptionNamespace {
void WaitHandleCannotBeOpenedException___::ctor() {
  Exception::in::set_HResult = -2146233044;
}

void WaitHandleCannotBeOpenedException___::ctor(String message) {
  Exception::in::set_HResult = -2146233044;
}

void WaitHandleCannotBeOpenedException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2146233044;
}

void WaitHandleCannotBeOpenedException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Threading::WaitHandleCannotBeOpenedExceptionNamespace
