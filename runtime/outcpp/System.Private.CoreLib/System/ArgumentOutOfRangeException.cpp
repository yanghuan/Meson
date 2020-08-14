#include "ArgumentOutOfRangeException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::ArgumentOutOfRangeExceptionNamespace {
String ArgumentOutOfRangeException___::get_Message() {
  String message = ArgumentException::get_Message();
  if (_actualValue != nullptr) {
    String text = SR::Format(SR::get_ArgumentOutOfRange_ActualValue(), _actualValue);
    if (message == nullptr) {
      return text;
    }
    return message + "
" + text;
  }
  return message;
}

Object ArgumentOutOfRangeException___::get_ActualValue() {
  return _actualValue;
}

void ArgumentOutOfRangeException___::ctor() {
  Exception::set_HResult = -2146233086;
}

void ArgumentOutOfRangeException___::ctor(String paramName) {
  Exception::set_HResult = -2146233086;
}

void ArgumentOutOfRangeException___::ctor(String paramName, String message) {
  Exception::set_HResult = -2146233086;
}

void ArgumentOutOfRangeException___::ctor(String message, Exception innerException) {
  Exception::set_HResult = -2146233086;
}

void ArgumentOutOfRangeException___::ctor(String paramName, Object actualValue, String message) {
  _actualValue = actualValue;
  Exception::set_HResult = -2146233086;
}

void ArgumentOutOfRangeException___::ctor(SerializationInfo info, StreamingContext context) {
  _actualValue = info->GetValue("ActualValue", rt::typeof<Object>());
}

void ArgumentOutOfRangeException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  ArgumentException::GetObjectData(info, context);
  info->AddValue("ActualValue", _actualValue, rt::typeof<Object>());
}

} // namespace System::Private::CoreLib::System::ArgumentOutOfRangeExceptionNamespace
