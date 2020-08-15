#include "InsufficientMemoryException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::InsufficientMemoryExceptionNamespace {
void InsufficientMemoryException___::ctor() {
  Exception::in::set_HResult = -2146233027;
}

void InsufficientMemoryException___::ctor(String message) {
  Exception::in::set_HResult = -2146233027;
}

void InsufficientMemoryException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2146233027;
}

void InsufficientMemoryException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::InsufficientMemoryExceptionNamespace
