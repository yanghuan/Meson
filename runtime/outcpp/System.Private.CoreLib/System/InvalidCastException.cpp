#include "InvalidCastException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::InvalidCastExceptionNamespace {
void InvalidCastException___::ctor() {
  Exception::set_HResult = -2147467262;
}

void InvalidCastException___::ctor(String message) {
  Exception::set_HResult = -2147467262;
}

void InvalidCastException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2147467262;
}

void InvalidCastException___::ctor(String message, Int32 errorCode) {
  Exception::set_HResult = errorCode;
}

void InvalidCastException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::InvalidCastExceptionNamespace
