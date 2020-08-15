#include "MethodAccessException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::MethodAccessExceptionNamespace {
void MethodAccessException___::ctor() {
  Exception::in::set_HResult = -2146233072;
}

void MethodAccessException___::ctor(String message) {
  Exception::in::set_HResult = -2146233072;
}

void MethodAccessException___::ctor(String message, Exception inner) {
  Exception::in::set_HResult = -2146233072;
}

void MethodAccessException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::MethodAccessExceptionNamespace
