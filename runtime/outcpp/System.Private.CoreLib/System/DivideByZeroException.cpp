#include "DivideByZeroException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::DivideByZeroExceptionNamespace {
void DivideByZeroException___::ctor() {
  Exception::set_HResult = -2147352558;
}

void DivideByZeroException___::ctor(String message) {
  Exception::set_HResult = -2147352558;
}

void DivideByZeroException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2147352558;
}

void DivideByZeroException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::DivideByZeroExceptionNamespace
