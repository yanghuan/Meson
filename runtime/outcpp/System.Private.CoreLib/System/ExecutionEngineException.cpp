#include "ExecutionEngineException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::ExecutionEngineExceptionNamespace {
void ExecutionEngineException___::ctor() {
  Exception::in::set_HResult = -2146233082;
}

void ExecutionEngineException___::ctor(String message) {
  Exception::in::set_HResult = -2146233082;
}

void ExecutionEngineException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2146233082;
}

void ExecutionEngineException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::ExecutionEngineExceptionNamespace
