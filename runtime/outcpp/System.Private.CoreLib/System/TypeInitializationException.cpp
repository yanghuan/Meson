#include "TypeInitializationException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::TypeInitializationExceptionNamespace {
String TypeInitializationException___::get_TypeName() {
  auto& default = _typeName;
  return default != nullptr ? default : String::in::Empty;
}

void TypeInitializationException___::ctor() {
  Exception::in::set_HResult(-2146233036);
}

void TypeInitializationException___::ctor(String fullTypeName, Exception innerException) {
}

void TypeInitializationException___::ctor(String message) {
  Exception::in::set_HResult(-2146233036);
}

void TypeInitializationException___::ctor(String fullTypeName, String message, Exception innerException) {
  _typeName = fullTypeName;
  Exception::in::set_HResult(-2146233036);
}

void TypeInitializationException___::ctor(SerializationInfo info, StreamingContext context) {
  _typeName = info->GetString("TypeName");
}

void TypeInitializationException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::in::GetObjectData(info, context);
  info->AddValue("TypeName", get_TypeName(), rt::typeof<String>());
}

} // namespace System::Private::CoreLib::System::TypeInitializationExceptionNamespace
