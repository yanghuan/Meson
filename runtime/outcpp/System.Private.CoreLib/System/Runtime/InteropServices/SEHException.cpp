#include "SEHException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::SEHExceptionNamespace {
void SEHException___::ctor() {
  Exception::in::set_HResult = -2147467259;
}

void SEHException___::ctor(String message) {
  Exception::in::set_HResult = -2147467259;
}

void SEHException___::ctor(String message, Exception inner) {
  Exception::in::set_HResult = -2147467259;
}

void SEHException___::ctor(SerializationInfo info, StreamingContext context) {
}

Boolean SEHException___::CanResume() {
  return false;
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::SEHExceptionNamespace
