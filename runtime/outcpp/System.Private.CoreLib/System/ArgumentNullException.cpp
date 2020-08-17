#include "ArgumentNullException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::ArgumentNullExceptionNamespace {
void ArgumentNullException___::ctor() {
  Exception::in::set_HResult(-2147467261);
}

void ArgumentNullException___::ctor(String paramName) {
  Exception::in::set_HResult(-2147467261);
}

void ArgumentNullException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult(-2147467261);
}

void ArgumentNullException___::ctor(String paramName, String message) {
  Exception::in::set_HResult(-2147467261);
}

void ArgumentNullException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::ArgumentNullExceptionNamespace
