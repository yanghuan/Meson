#include "PathTooLongException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::IO::PathTooLongExceptionNamespace {
void PathTooLongException___::ctor() {
  Exception::set_HResult = -2147024690;
}

void PathTooLongException___::ctor(String message) {
  Exception::set_HResult = -2147024690;
}

void PathTooLongException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2147024690;
}

void PathTooLongException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::IO::PathTooLongExceptionNamespace
