#include "MethodAccessException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::MethodAccessExceptionNamespace {
void MethodAccessException___::ctor() {
  Exception::set_HResult = -2146233072;
}

void MethodAccessException___::ctor(String message) {
  Exception::set_HResult = -2146233072;
}

void MethodAccessException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233072;
}

void MethodAccessException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::MethodAccessExceptionNamespace
