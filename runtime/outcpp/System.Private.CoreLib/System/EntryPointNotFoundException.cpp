#include "EntryPointNotFoundException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::EntryPointNotFoundExceptionNamespace {
void EntryPointNotFoundException___::ctor() {
  Exception::set_HResult = -2146233053;
}

void EntryPointNotFoundException___::ctor(String message) {
  Exception::set_HResult = -2146233053;
}

void EntryPointNotFoundException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2146233053;
}

void EntryPointNotFoundException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::EntryPointNotFoundExceptionNamespace
