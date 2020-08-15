#include "TimeoutException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::TimeoutExceptionNamespace {
void TimeoutException___::ctor() {
  Exception::in::set_HResult = -2146233083;
}

void TimeoutException___::ctor(String message) {
  Exception::in::set_HResult = -2146233083;
}

void TimeoutException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2146233083;
}

void TimeoutException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::TimeoutExceptionNamespace
