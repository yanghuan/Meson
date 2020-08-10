#include "ContractFailedEventArgs-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractFailedEventArgsNamespace {
String ContractFailedEventArgs___::get_Message() {
  return nullptr;
}

String ContractFailedEventArgs___::get_Condition() {
  return nullptr;
}

ContractFailureKind ContractFailedEventArgs___::get_FailureKind() {
  return ContractFailureKind::Assume;
}

Exception ContractFailedEventArgs___::get_OriginalException() {
  return nullptr;
}

Boolean ContractFailedEventArgs___::get_Handled() {
  return Boolean();
}

Boolean ContractFailedEventArgs___::get_Unwind() {
  return Boolean();
}

void ContractFailedEventArgs___::ctor(ContractFailureKind failureKind, String message, String condition, Exception originalException) {
}

void ContractFailedEventArgs___::SetHandled() {
}

void ContractFailedEventArgs___::SetUnwind() {
}

} // namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractFailedEventArgsNamespace
