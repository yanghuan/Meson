#include "OutOfMemoryException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::OutOfMemoryExceptionNamespace {
void OutOfMemoryException___::ctor() {
  Exception::in::set_HResult(-2147024882);
}

void OutOfMemoryException___::ctor(String message) {
  Exception::in::set_HResult(-2147024882);
}

void OutOfMemoryException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult(-2147024882);
}

void OutOfMemoryException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::OutOfMemoryExceptionNamespace
