#include "ArgumentOutOfRangeException-dep.h"

namespace System::Private::CoreLib::System::ArgumentOutOfRangeExceptionNamespace {
String ArgumentOutOfRangeException___::get_Message() {
}

Object ArgumentOutOfRangeException___::get_ActualValue() {
  return _actualValue;
}

void ArgumentOutOfRangeException___::ctor() {
}

void ArgumentOutOfRangeException___::ctor(String paramName) {
}

void ArgumentOutOfRangeException___::ctor(String paramName, String message) {
}

void ArgumentOutOfRangeException___::ctor(String message, Exception innerException) {
}

void ArgumentOutOfRangeException___::ctor(String paramName, Object actualValue, String message) {
  _actualValue = actualValue;
}

void ArgumentOutOfRangeException___::ctor(SerializationInfo info, StreamingContext context) {
}

void ArgumentOutOfRangeException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::ArgumentOutOfRangeExceptionNamespace
