#include "IndexOutOfRangeException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::IndexOutOfRangeExceptionNamespace {
void IndexOutOfRangeException___::ctor() {
  Exception::in::set_HResult = -2146233080;
}

void IndexOutOfRangeException___::ctor(String message) {
  Exception::in::set_HResult = -2146233080;
}

void IndexOutOfRangeException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2146233080;
}

void IndexOutOfRangeException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::IndexOutOfRangeExceptionNamespace
