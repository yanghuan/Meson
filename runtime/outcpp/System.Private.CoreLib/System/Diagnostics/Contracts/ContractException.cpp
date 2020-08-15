#include "ContractException-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractExceptionNamespace {
ContractFailureKind ContractException___::get_Kind() {
  return _kind;
}

String ContractException___::get_Failure() {
  return get_Message();
}

String ContractException___::get_UserMessage() {
  return _userMessage;
}

String ContractException___::get_Condition() {
  return _condition;
}

void ContractException___::ctor() {
  Exception::in::set_HResult = -2146233022;
}

void ContractException___::ctor(ContractFailureKind kind, String failure, String userMessage, String condition, Exception innerException) {
  Exception::in::set_HResult = -2146233022;
  _kind = kind;
  _userMessage = userMessage;
  _condition = condition;
}

void ContractException___::ctor(SerializationInfo info, StreamingContext context) {
  _kind = (ContractFailureKind)info->GetInt32("Kind");
  _userMessage = info->GetString("UserMessage");
  _condition = info->GetString("Condition");
}

void ContractException___::GetObjectData(SerializationInfo info, StreamingContext context) {
  Exception::in::GetObjectData(info, context);
  info->AddValue("Kind", _kind);
  info->AddValue("UserMessage", _userMessage);
  info->AddValue("Condition", _condition);
}

} // namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractExceptionNamespace
