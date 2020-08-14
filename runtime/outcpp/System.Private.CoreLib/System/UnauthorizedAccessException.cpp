#include "UnauthorizedAccessException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::UnauthorizedAccessExceptionNamespace {
void UnauthorizedAccessException___::ctor() {
  Exception::set_HResult = -2147024891;
}

void UnauthorizedAccessException___::ctor(String message) {
  Exception::set_HResult = -2147024891;
}

void UnauthorizedAccessException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2147024891;
}

void UnauthorizedAccessException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::UnauthorizedAccessExceptionNamespace
