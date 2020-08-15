#include "ArithmeticException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::ArithmeticExceptionNamespace {
void ArithmeticException___::ctor() {
  Exception::in::set_HResult = -2147024362;
}

void ArithmeticException___::ctor(String message) {
  Exception::in::set_HResult = -2147024362;
}

void ArithmeticException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2147024362;
}

void ArithmeticException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::ArithmeticExceptionNamespace
