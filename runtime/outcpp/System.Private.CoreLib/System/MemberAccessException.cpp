#include "MemberAccessException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::MemberAccessExceptionNamespace {
void MemberAccessException___::ctor() {
  Exception::set_HResult = -2146233062;
}

void MemberAccessException___::ctor(String message) {
  Exception::set_HResult = -2146233062;
}

void MemberAccessException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233062;
}

void MemberAccessException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::MemberAccessExceptionNamespace
