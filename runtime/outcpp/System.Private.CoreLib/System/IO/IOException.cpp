#include "IOException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::IO::IOExceptionNamespace {
void IOException___::ctor() {
  Exception::set_HResult = -2146232800;
}

void IOException___::ctor(String message) {
  Exception::set_HResult = -2146232800;
}

void IOException___::ctor(String message, Int32 hresult) {
  Exception::set_HResult = hresult;
}

void IOException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2146232800;
}

void IOException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::IO::IOExceptionNamespace
