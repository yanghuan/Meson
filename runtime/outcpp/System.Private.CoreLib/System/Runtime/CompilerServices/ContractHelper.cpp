#include "ContractHelper-dep.h"

namespace System::Private::CoreLib::System::Runtime::CompilerServices::ContractHelperNamespace {
String ContractHelper::RaiseContractFailedEvent(ContractFailureKind failureKind, String userMessage, String conditionText, Exception innerException) {
  return nullptr;
}

void ContractHelper::TriggerFailure(ContractFailureKind kind, String displayMessage, String userMessage, String conditionText, Exception innerException) {
}

String ContractHelper::GetFailureMessage(ContractFailureKind failureKind, String conditionText) {
  return nullptr;
}

String ContractHelper::GetDisplayMessage(ContractFailureKind failureKind, String userMessage, String conditionText) {
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::ContractHelperNamespace
