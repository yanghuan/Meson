#include "ArgumentNullException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::ArgumentNullExceptionNamespace {
void ArgumentNullException___::ctor() {
  Exception::set_HResult = -2147467261;
}

void ArgumentNullException___::ctor(String paramName) {
  Exception::set_HResult = -2147467261;
}

void ArgumentNullException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2147467261;
}

void ArgumentNullException___::ctor(String paramName, String message) {
  Exception::set_HResult = -2147467261;
}

void ArgumentNullException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::ArgumentNullExceptionNamespace
