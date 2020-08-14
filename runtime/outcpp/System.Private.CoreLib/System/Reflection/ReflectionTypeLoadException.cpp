#include "ReflectionTypeLoadException-dep.h"

namespace System::Private::CoreLib::System::Reflection::ReflectionTypeLoadExceptionNamespace {
String ReflectionTypeLoadException___::get_Message() {
  return CreateString(true);
}

void ReflectionTypeLoadException___::ctor(Array<Type> classes, Array<Exception> exceptions) {
}

void ReflectionTypeLoadException___::ctor(Array<Type> classes, Array<Exception> exceptions, String message) {
}

void ReflectionTypeLoadException___::ctor(SerializationInfo info, StreamingContext context) {
  Types = Type::in::EmptyTypes;
}

void ReflectionTypeLoadException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

String ReflectionTypeLoadException___::ToString() {
  return CreateString(false);
}

String ReflectionTypeLoadException___::CreateString(Boolean isMessage) {
}

} // namespace System::Private::CoreLib::System::Reflection::ReflectionTypeLoadExceptionNamespace
