#include "ThreadInterruptedException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadInterruptedExceptionNamespace {
void ThreadInterruptedException___::ctor() {
  Exception::in::set_HResult = -2146233063;
}

void ThreadInterruptedException___::ctor(String message) {
  Exception::in::set_HResult = -2146233063;
}

void ThreadInterruptedException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2146233063;
}

void ThreadInterruptedException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Threading::ThreadInterruptedExceptionNamespace
