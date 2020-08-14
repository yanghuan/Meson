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
}

void ContractException___::ctor(ContractFailureKind kind, String failure, String userMessage, String condition, Exception innerException) {
}

void ContractException___::ctor(SerializationInfo info, StreamingContext context) {
  _kind = (ContractFailureKind)info->GetInt32("Kind");
  _userMessage = info->GetString("UserMessage");
  _condition = info->GetString("Condition");
}

void ContractException___::GetObjectData(SerializationInfo info, StreamingContext context) {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractExceptionNamespace
