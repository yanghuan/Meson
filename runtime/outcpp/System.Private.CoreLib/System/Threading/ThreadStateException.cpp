#include "ThreadStateException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadStateExceptionNamespace {
void ThreadStateException___::ctor() {
  Exception::set_HResult = -2146233056;
}

void ThreadStateException___::ctor(String message) {
  Exception::set_HResult = -2146233056;
}

void ThreadStateException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2146233056;
}

void ThreadStateException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Threading::ThreadStateExceptionNamespace
