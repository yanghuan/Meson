#include "DllNotFoundException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::DllNotFoundExceptionNamespace {
void DllNotFoundException___::ctor() {
  Exception::in::set_HResult(-2146233052);
}

void DllNotFoundException___::ctor(String message) {
  Exception::in::set_HResult(-2146233052);
}

void DllNotFoundException___::ctor(String message, Exception inner) {
  Exception::in::set_HResult(-2146233052);
}

void DllNotFoundException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::DllNotFoundExceptionNamespace
