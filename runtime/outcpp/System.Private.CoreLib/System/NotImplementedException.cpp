#include "NotImplementedException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::NotImplementedExceptionNamespace {
void NotImplementedException___::ctor() {
  Exception::set_HResult = -2147467263;
}

void NotImplementedException___::ctor(String message) {
  Exception::set_HResult = -2147467263;
}

void NotImplementedException___::ctor(String message, Exception inner) {
  Exception::set_HResult = -2147467263;
}

void NotImplementedException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::NotImplementedExceptionNamespace
