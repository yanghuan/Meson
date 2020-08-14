#include "NullReferenceException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::NullReferenceExceptionNamespace {
void NullReferenceException___::ctor() {
  Exception::set_HResult = -2147467261;
}

void NullReferenceException___::ctor(String message) {
  Exception::set_HResult = -2147467261;
}

void NullReferenceException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2147467261;
}

void NullReferenceException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::NullReferenceExceptionNamespace
