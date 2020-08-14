#include "SwitchExpressionException-dep.h"

#include <System.Private.CoreLib/System/Environment-dep.h>
#include <System.Private.CoreLib/System/Exception-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::SwitchExpressionExceptionNamespace {
String SwitchExpressionException___::get_Message() {
  if (UnmatchedValue == nullptr) {
    return Exception::get_Message();
  }
  String str = SR::Format(SR::get_SwitchExpressionException_UnmatchedValue(), UnmatchedValue);
  return Exception::get_Message() + Environment::get_NewLine() + str;
}

void SwitchExpressionException___::ctor() {
}

void SwitchExpressionException___::ctor(Exception innerException) {
}

void SwitchExpressionException___::ctor(Object unmatchedValue) {
  UnmatchedValue = unmatchedValue;
}

void SwitchExpressionException___::ctor(SerializationInfo info, StreamingContext context) {
  UnmatchedValue = info->GetValue("UnmatchedValue", rt::typeof<Object>());
}

void SwitchExpressionException___::ctor(String message) {
}

void SwitchExpressionException___::ctor(String message, Exception innerException) {
}

void SwitchExpressionException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::GetObjectData(info, context);
  info->AddValue("UnmatchedValue", UnmatchedValue, rt::typeof<Object>());
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::SwitchExpressionExceptionNamespace
