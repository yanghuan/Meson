#include "InvalidOperationException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::InvalidOperationExceptionNamespace {
void InvalidOperationException___::ctor() {
  Exception::set_HResult = -2146233079;
}

void InvalidOperationException___::ctor(String message) {
  Exception::set_HResult = -2146233079;
}

void InvalidOperationException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2146233079;
}

void InvalidOperationException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::InvalidOperationExceptionNamespace
