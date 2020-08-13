#include "TypeInitializationException-dep.h"

namespace System::Private::CoreLib::System::TypeInitializationExceptionNamespace {
String TypeInitializationException___::get_TypeName() {
}

void TypeInitializationException___::ctor() {
}

void TypeInitializationException___::ctor(String fullTypeName, Exception innerException) {
}

void TypeInitializationException___::ctor(String message) {
}

void TypeInitializationException___::ctor(String fullTypeName, String message, Exception innerException) {
  _typeName = fullTypeName;
}

void TypeInitializationException___::ctor(SerializationInfo info, StreamingContext context) {
  _typeName = info->GetString("TypeName");
}

void TypeInitializationException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::TypeInitializationExceptionNamespace
