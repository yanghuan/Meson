#include "ArgumentException-dep.h"

namespace System::Private::CoreLib::System::ArgumentExceptionNamespace {
String ArgumentException___::get_Message() {
  SetMessageField();
}

String ArgumentException___::get_ParamName() {
  return _paramName;
}

void ArgumentException___::ctor() {
}

void ArgumentException___::ctor(String message) {
}

void ArgumentException___::ctor(String message, Exception innerException) {
}

void ArgumentException___::ctor(String message, String paramName, Exception innerException) {
  _paramName = paramName;
}

void ArgumentException___::ctor(String message, String paramName) {
  _paramName = paramName;
}

void ArgumentException___::ctor(SerializationInfo info, StreamingContext context) {
  _paramName = info->GetString("ParamName");
}

void ArgumentException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

void ArgumentException___::SetMessageField() {
}

} // namespace System::Private::CoreLib::System::ArgumentExceptionNamespace
