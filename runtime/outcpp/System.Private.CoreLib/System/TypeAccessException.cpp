#include "TypeAccessException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::TypeAccessExceptionNamespace {
void TypeAccessException___::ctor() {
  Exception::set_HResult = -2146233021;
}

void TypeAccessException___::ctor(String message) {
  Exception::set_HResult = -2146233021;
}

void TypeAccessException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233021;
}

void TypeAccessException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::TypeAccessExceptionNamespace
