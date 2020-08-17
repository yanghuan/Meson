#include "AccessViolationException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::AccessViolationExceptionNamespace {
void AccessViolationException___::ctor() {
  Exception::in::set_HResult(-2147467261);
}

void AccessViolationException___::ctor(String message) {
  Exception::in::set_HResult(-2147467261);
}

void AccessViolationException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult(-2147467261);
}

void AccessViolationException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::AccessViolationExceptionNamespace
