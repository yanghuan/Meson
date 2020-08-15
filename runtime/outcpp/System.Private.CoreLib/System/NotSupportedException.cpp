#include "NotSupportedException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::NotSupportedExceptionNamespace {
void NotSupportedException___::ctor() {
  Exception::in::set_HResult = -2146233067;
}

void NotSupportedException___::ctor(String message) {
  Exception::in::set_HResult = -2146233067;
}

void NotSupportedException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2146233067;
}

void NotSupportedException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::NotSupportedExceptionNamespace
