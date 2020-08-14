#include "SwitchExpressionException-dep.h"

#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::SwitchExpressionExceptionNamespace {
String SwitchExpressionException___::get_Message() {
  if (UnmatchedValue == nullptr) {
  }
  String str = SR::Format(SR::get_SwitchExpressionException_UnmatchedValue(), UnmatchedValue);
}

void SwitchExpressionException___::ctor() {
}

void SwitchExpressionException___::ctor(Exception innerException) {
}

void SwitchExpressionException___::ctor(Object unmatchedValue) {
  UnmatchedValue = unmatchedValue;
}

void SwitchExpressionException___::ctor(SerializationInfo info, StreamingContext context) {
}

void SwitchExpressionException___::ctor(String message) {
}

void SwitchExpressionException___::ctor(String message, Exception innerException) {
}

void SwitchExpressionException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::SwitchExpressionExceptionNamespace
