#include "EndOfStreamException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::IO::EndOfStreamExceptionNamespace {
void EndOfStreamException___::ctor() {
  Exception::set_HResult = -2147024858;
}

void EndOfStreamException___::ctor(String message) {
  Exception::set_HResult = -2147024858;
}

void EndOfStreamException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2147024858;
}

void EndOfStreamException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::IO::EndOfStreamExceptionNamespace
