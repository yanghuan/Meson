#include "ArgumentException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::ArgumentExceptionNamespace {
String ArgumentException___::get_Message() {
  SetMessageField();
  String text = Exception::in::get_Message();
  if (!String::in::IsNullOrEmpty(_paramName)) {
    text = text + " " + SR::Format(SR::get_Arg_ParamName_Name(), _paramName);
  }
  return text;
}

String ArgumentException___::get_ParamName() {
  return _paramName;
}

void ArgumentException___::ctor() {
  Exception::in::set_HResult = -2147024809;
}

void ArgumentException___::ctor(String message) {
  Exception::in::set_HResult = -2147024809;
}

void ArgumentException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult = -2147024809;
}

void ArgumentException___::ctor(String message, String paramName, Exception innerException) {
  _paramName = paramName;
  Exception::in::set_HResult = -2147024809;
}

void ArgumentException___::ctor(String message, String paramName) {
  _paramName = paramName;
  Exception::in::set_HResult = -2147024809;
}

void ArgumentException___::ctor(SerializationInfo info, StreamingContext context) {
  _paramName = info->GetString("ParamName");
}

void ArgumentException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::in::GetObjectData(info, context);
  info->AddValue("ParamName", _paramName, rt::typeof<String>());
}

void ArgumentException___::SetMessageField() {
  if (_message == nullptr && Exception::in::get_HResult() == -2147024809) {
    _message = SR::get_Arg_ArgumentException();
  }
}

} // namespace System::Private::CoreLib::System::ArgumentExceptionNamespace
