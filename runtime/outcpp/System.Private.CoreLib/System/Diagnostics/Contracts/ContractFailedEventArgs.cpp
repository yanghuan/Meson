#include "ContractFailedEventArgs-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractFailedEventArgsNamespace {
String ContractFailedEventArgs___::get_Message() {
  return _message;
}

String ContractFailedEventArgs___::get_Condition() {
  return _condition;
}

ContractFailureKind ContractFailedEventArgs___::get_FailureKind() {
  return _failureKind;
}

Exception ContractFailedEventArgs___::get_OriginalException() {
  return _originalException;
}

Boolean ContractFailedEventArgs___::get_Handled() {
  return _handled;
}

Boolean ContractFailedEventArgs___::get_Unwind() {
  return _unwind;
}

void ContractFailedEventArgs___::ctor(ContractFailureKind failureKind, String message, String condition, Exception originalException) {
  _failureKind = failureKind;
  _message = message;
  _condition = condition;
  _originalException = originalException;
}

void ContractFailedEventArgs___::SetHandled() {
  _handled = true;
}

void ContractFailedEventArgs___::SetUnwind() {
  _unwind = true;
}

} // namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractFailedEventArgsNamespace
