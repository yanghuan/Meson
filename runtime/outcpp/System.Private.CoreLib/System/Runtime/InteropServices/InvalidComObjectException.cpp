#include "InvalidComObjectException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::InvalidComObjectExceptionNamespace {
void InvalidComObjectException___::ctor() {
  Exception::set_HResult = -2146233049;
}

void InvalidComObjectException___::ctor(String message) {
  Exception::set_HResult = -2146233049;
}

void InvalidComObjectException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233049;
}

void InvalidComObjectException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Runtime::InteropServices::InvalidComObjectExceptionNamespace
