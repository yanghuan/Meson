#include "StackOverflowException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::StackOverflowExceptionNamespace {
void StackOverflowException___::ctor() {
  Exception::set_HResult = -2147023895;
}

void StackOverflowException___::ctor(String message) {
  Exception::set_HResult = -2147023895;
}

void StackOverflowException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2147023895;
}

void StackOverflowException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::StackOverflowExceptionNamespace
