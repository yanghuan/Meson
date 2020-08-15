#include "SystemException-dep.h"

namespace System::Private::CoreLib::System::SystemExceptionNamespace {
void SystemException___::ctor() {
  Exception::in::set_HResult = -2146233087;
}

void SystemException___::ctor(String message) {
  Exception::in::set_HResult = -2146233087;
}

void SystemException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2146233087;
}

void SystemException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::SystemExceptionNamespace
