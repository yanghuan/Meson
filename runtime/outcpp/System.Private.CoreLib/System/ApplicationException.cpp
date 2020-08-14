#include "ApplicationException-dep.h"

namespace System::Private::CoreLib::System::ApplicationExceptionNamespace {
void ApplicationException___::ctor() {
  Exception::set_HResult = -2146232832;
}

void ApplicationException___::ctor(String message) {
  Exception::set_HResult = -2146232832;
}

void ApplicationException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2146232832;
}

void ApplicationException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::ApplicationExceptionNamespace
