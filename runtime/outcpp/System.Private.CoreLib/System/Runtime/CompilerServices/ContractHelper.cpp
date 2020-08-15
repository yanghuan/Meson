#include "ContractHelper-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Contracts/Contract-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Contracts/ContractFailedEventArgs-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Debug-dep.h>
#include <System.Private.CoreLib/System/EventHandler-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ContractHelper-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Runtime::CompilerServices::ContractHelperNamespace {
using namespace System::Diagnostics;
using namespace System::Diagnostics::Contracts;

String ContractHelper::RaiseContractFailedEvent(ContractFailureKind failureKind, String userMessage, String conditionText, Exception innerException) {
  if (failureKind < ContractFailureKind::Precondition || failureKind > ContractFailureKind::Assume) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumIllegalVal(), failureKind), "failureKind");
  }
  String text = "contract failed.";
  ContractFailedEventArgs contractFailedEventArgs = nullptr;
  String result;
  try {
    text = GetDisplayMessage(failureKind, userMessage, conditionText);
  } catch (...) {
  } finally: {
    result = ((contractFailedEventArgs == nullptr || !contractFailedEventArgs->get_Handled()) ? text : nullptr);
  }
  return result;
}

void ContractHelper::TriggerFailure(ContractFailureKind kind, String displayMessage, String userMessage, String conditionText, Exception innerException) {
  if (String::in::IsNullOrEmpty(displayMessage)) {
    displayMessage = GetDisplayMessage(kind, userMessage, conditionText);
  }
  Debug::ContractFailure(displayMessage, String::in::Empty, GetFailureMessage(kind, nullptr));
}

String ContractHelper::GetFailureMessage(ContractFailureKind failureKind, String conditionText) {
  Boolean flag = !String::in::IsNullOrEmpty(conditionText);
  switch (failureKind) {
    case ContractFailureKind::Assert:
      if (!flag) {
        return SR::get_AssertionFailed();
      }
      return SR::Format(SR::get_AssertionFailed_Cnd(), conditionText);
    case ContractFailureKind::Assume:
      if (!flag) {
        return SR::get_AssumptionFailed();
      }
      return SR::Format(SR::get_AssumptionFailed_Cnd(), conditionText);
    case ContractFailureKind::Precondition:
      if (!flag) {
        return SR::get_PreconditionFailed();
      }
      return SR::Format(SR::get_PreconditionFailed_Cnd(), conditionText);
    case ContractFailureKind::Postcondition:
      if (!flag) {
        return SR::get_PostconditionFailed();
      }
      return SR::Format(SR::get_PostconditionFailed_Cnd(), conditionText);
    case ContractFailureKind::Invariant:
      if (!flag) {
        return SR::get_InvariantFailed();
      }
      return SR::Format(SR::get_InvariantFailed_Cnd(), conditionText);
    case ContractFailureKind::PostconditionOnException:
      if (!flag) {
        return SR::get_PostconditionOnExceptionFailed();
      }
      return SR::Format(SR::get_PostconditionOnExceptionFailed_Cnd(), conditionText);
    default:
      Contract::Assume(false, "Unreachable code");
      return SR::get_AssumptionFailed();
  }
}

String ContractHelper::GetDisplayMessage(ContractFailureKind failureKind, String userMessage, String conditionText) {
  String text = String::in::IsNullOrEmpty(conditionText) ? "" : GetFailureMessage(failureKind, conditionText);
  if (!String::in::IsNullOrEmpty(userMessage)) {
    return text + "  " + userMessage;
  }
  return text;
}

} // namespace System::Private::CoreLib::System::Runtime::CompilerServices::ContractHelperNamespace
