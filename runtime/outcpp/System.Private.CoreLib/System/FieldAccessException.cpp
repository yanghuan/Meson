#include "FieldAccessException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::FieldAccessExceptionNamespace {
void FieldAccessException___::ctor() {
  Exception::set_HResult = -2146233081;
}

void FieldAccessException___::ctor(String message) {
  Exception::set_HResult = -2146233081;
}

void FieldAccessException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233081;
}

void FieldAccessException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::FieldAccessExceptionNamespace
