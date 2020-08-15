#include "ThreadAbortException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadAbortExceptionNamespace {
Object ThreadAbortException___::get_ExceptionState() {
  return nullptr;
}

void ThreadAbortException___::ctor() {
  Exception::in::set_HResult = -2146233040;
}

void ThreadAbortException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Threading::ThreadAbortExceptionNamespace
