#include "NotImplementedException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::NotImplementedExceptionNamespace {
void NotImplementedException___::ctor() {
  Exception::in::set_HResult = -2147467263;
}

void NotImplementedException___::ctor(String message) {
  Exception::in::set_HResult = -2147467263;
}

void NotImplementedException___::ctor(String message, Exception inner) {
  Exception::in::set_HResult = -2147467263;
}

void NotImplementedException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::NotImplementedExceptionNamespace
