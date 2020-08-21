#include "ReflectionTypeLoadException-dep.h"

#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::ReflectionTypeLoadExceptionNamespace {
using namespace System::Text;

String ReflectionTypeLoadException___::get_Message() {
  return CreateString(true);
}

void ReflectionTypeLoadException___::ctor(Array<Type> classes, Array<Exception> exceptions) {
}

void ReflectionTypeLoadException___::ctor(Array<Type> classes, Array<Exception> exceptions, String message) {
  Array<Type> as = classes;
  Types = (as != nullptr ? as : Type::in::EmptyTypes);
  Array<Exception> as = exceptions;
  LoaderExceptions = (as != nullptr ? as : Array<>::in::Empty<Exception>());
  Exception::in::set_HResult(-2146232830);
}

void ReflectionTypeLoadException___::ctor(SerializationInfo info, StreamingContext context) {
  Types = Type::in::EmptyTypes;
  ? as = ((Array<Exception>)info->GetValue("Exceptions", rt::typeof<Array<Exception>>()));
  LoaderExceptions = (as != nullptr ? as : Array<>::in::Empty<Exception>());
}

void ReflectionTypeLoadException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::in::GetObjectData(info, context);
  info->AddValue("Types", nullptr, rt::typeof<Array<Type>>());
  info->AddValue("Exceptions", LoaderExceptions, rt::typeof<Array<Exception>>());
}

String ReflectionTypeLoadException___::ToString() {
  return CreateString(false);
}

String ReflectionTypeLoadException___::CreateString(Boolean isMessage) {
  String text = isMessage ? Exception::in::get_Message() : Exception::in::ToString();
  Array<Exception> loaderExceptions = LoaderExceptions;
  if (loaderExceptions->get_Length() == 0) {
    return text;
  }
  StringBuilder stringBuilder = rt::newobj<StringBuilder>(text);
  Array<Exception> array = loaderExceptions;
}

} // namespace System::Private::CoreLib::System::Reflection::ReflectionTypeLoadExceptionNamespace
