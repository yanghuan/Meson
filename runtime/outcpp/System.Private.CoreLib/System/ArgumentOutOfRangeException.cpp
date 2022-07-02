#include "ArgumentOutOfRangeException-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::ArgumentOutOfRangeExceptionNamespace {
String ArgumentOutOfRangeException___::get_Message() {
  String message = ArgumentException::in::get_Message();
  if (_actualValue != nullptr) {
    String text = SR::Format(SR::get_ArgumentOutOfRange_ActualValue(), _actualValue);
    if (message == nullptr) {
      return text;
    }
    return message + "\r\n" + text;
  }
  return message;
}

Object ArgumentOutOfRangeException___::get_ActualValue() {
  return _actualValue;
}

void ArgumentOutOfRangeException___::ctor() {
  Exception::in::set_HResult(-2146233086);
}

void ArgumentOutOfRangeException___::ctor(String paramName) {
  Exception::in::set_HResult(-2146233086);
}

void ArgumentOutOfRangeException___::ctor(String paramName, String message) {
  Exception::in::set_HResult(-2146233086);
}

void ArgumentOutOfRangeException___::ctor(String message, Exception innerException) {
  Exception::in::set_HResult(-2146233086);
}

void ArgumentOutOfRangeException___::ctor(String paramName, Object actualValue, String message) {
  _actualValue = actualValue;
  Exception::in::set_HResult(-2146233086);
}

void ArgumentOutOfRangeException___::ctor(SerializationInfo info, StreamingContext context) {
  _actualValue = info->GetValue("ActualValue", typeof<Object>());
}

void ArgumentOutOfRangeException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  ArgumentException::in::GetObjectData(info, context);
  info->AddValue("ActualValue", _actualValue, typeof<Object>());
}

} // namespace System::Private::CoreLib::System::ArgumentOutOfRangeExceptionNamespace
