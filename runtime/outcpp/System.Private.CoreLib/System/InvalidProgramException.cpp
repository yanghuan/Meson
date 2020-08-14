#include "InvalidProgramException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::InvalidProgramExceptionNamespace {
void InvalidProgramException___::ctor() {
  Exception::set_HResult = -2146233030;
}

void InvalidProgramException___::ctor(String message) {
  Exception::set_HResult = -2146233030;
}

void InvalidProgramException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233030;
}

void InvalidProgramException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::InvalidProgramExceptionNamespace
