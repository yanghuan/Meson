#include "ThreadStartException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadStartExceptionNamespace {
void ThreadStartException___::ctor() {
  Exception::set_HResult = -2146233051;
}

void ThreadStartException___::ctor(Exception reason) {
  Exception::set_HResult = -2146233051;
}

void ThreadStartException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Threading::ThreadStartExceptionNamespace
