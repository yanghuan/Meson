#include "DirectoryNotFoundException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::IO::DirectoryNotFoundExceptionNamespace {
void DirectoryNotFoundException___::ctor() {
  Exception::set_HResult = -2147024893;
}

void DirectoryNotFoundException___::ctor(String message) {
  Exception::set_HResult = -2147024893;
}

void DirectoryNotFoundException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2147024893;
}

void DirectoryNotFoundException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::IO::DirectoryNotFoundExceptionNamespace
