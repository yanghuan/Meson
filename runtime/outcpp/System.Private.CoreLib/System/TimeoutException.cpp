#include "TimeoutException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::TimeoutExceptionNamespace {
void TimeoutException___::ctor() {
  Exception::set_HResult = -2146233083;
}

void TimeoutException___::ctor(String message) {
  Exception::set_HResult = -2146233083;
}

void TimeoutException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2146233083;
}

void TimeoutException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::TimeoutExceptionNamespace
