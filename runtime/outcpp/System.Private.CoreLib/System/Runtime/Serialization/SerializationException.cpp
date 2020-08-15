#include "SerializationException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::Runtime::Serialization::SerializationExceptionNamespace {
void SerializationException___::ctor() {
  Exception::in::set_HResult = -2146233076;
}

void SerializationException___::ctor(String message) {
  Exception::in::set_HResult = -2146233076;
}

void SerializationException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2146233076;
}

void SerializationException___::ctor(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Runtime::Serialization::SerializationExceptionNamespace
