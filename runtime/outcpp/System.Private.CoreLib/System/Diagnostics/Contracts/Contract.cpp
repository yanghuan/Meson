#include "Contract-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Contracts/Contract-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Contracts/ContractFailureKind.h>
#include <System.Private.CoreLib/System/Diagnostics/StackTrace-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/Assembly-dep.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/ContractHelper-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractNamespace {
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;

void Contract::Assume(Boolean condition) {
  if (!condition) {
    ReportFailure(ContractFailureKind::Assume, nullptr, nullptr, nullptr);
  }
}

void Contract::Assume(Boolean condition, String userMessage) {
  if (!condition) {
    ReportFailure(ContractFailureKind::Assume, userMessage, nullptr, nullptr);
  }
}

void Contract::Assert(Boolean condition) {
  if (!condition) {
    ReportFailure(ContractFailureKind::Assert, nullptr, nullptr, nullptr);
  }
}

void Contract::Assert(Boolean condition, String userMessage) {
  if (!condition) {
    ReportFailure(ContractFailureKind::Assert, userMessage, nullptr, nullptr);
  }
}

void Contract::Requires(Boolean condition) {
  AssertMustUseRewriter(ContractFailureKind::Precondition, "Requires");
}

void Contract::Requires(Boolean condition, String userMessage) {
  AssertMustUseRewriter(ContractFailureKind::Precondition, "Requires");
}

void Contract::Ensures(Boolean condition) {
  AssertMustUseRewriter(ContractFailureKind::Postcondition, "Ensures");
}

void Contract::Ensures(Boolean condition, String userMessage) {
  AssertMustUseRewriter(ContractFailureKind::Postcondition, "Ensures");
}

void Contract::Invariant(Boolean condition) {
  AssertMustUseRewriter(ContractFailureKind::Invariant, "Invariant");
}

void Contract::Invariant(Boolean condition, String userMessage) {
  AssertMustUseRewriter(ContractFailureKind::Invariant, "Invariant");
}

Boolean Contract::ForAll(Int32 fromInclusive, Int32 toExclusive, Predicate<Int32> predicate) {
  if (fromInclusive > toExclusive) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ToExclusiveLessThanFromExclusive());
  }
  if (predicate == nullptr) {
    rt::throw_exception<ArgumentNullException>("predicate");
  }
  for (Int32 i = fromInclusive; i < toExclusive; i++) {
    if (!predicate(i)) {
      return false;
    }
  }
  return true;
}

Boolean Contract::Exists(Int32 fromInclusive, Int32 toExclusive, Predicate<Int32> predicate) {
  if (fromInclusive > toExclusive) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_ToExclusiveLessThanFromExclusive());
  }
  if (predicate == nullptr) {
    rt::throw_exception<ArgumentNullException>("predicate");
  }
  for (Int32 i = fromInclusive; i < toExclusive; i++) {
    if (predicate(i)) {
      return true;
    }
  }
  return false;
}

void Contract::EndContractBlock() {
}

void Contract::AssertMustUseRewriter(ContractFailureKind kind, String contractKind) {
  Assembly assembly = rt::typeof<Contract>()->get_Assembly();
  StackTrace stackTrace = rt::newobj<StackTrace>();
  Assembly assembly2 = nullptr;
  for (Int32 i = 0; i < stackTrace->get_FrameCount(); i++) {
    auto& as = stackTrace->GetFrame(i)->GetMethod();
    Assembly assembly3 = (as == nullptr ? nullptr : as->get_DeclaringType())->get_Assembly();
    if (assembly3 != nullptr && assembly3 != assembly) {
      assembly2 = assembly3;
      break;
    }
  }
  if ((Object)assembly2 == nullptr) {
    assembly2 = assembly;
  }
  String name = assembly2->GetName()->get_Name();
  ContractHelper::TriggerFailure(kind, SR::Format(SR::get_MustUseCCRewrite(), contractKind, name), nullptr, nullptr, nullptr);
}

void Contract::ReportFailure(ContractFailureKind failureKind, String userMessage, String conditionText, Exception innerException) {
  if (failureKind < ContractFailureKind::Precondition || failureKind > ContractFailureKind::Assume) {
    rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumIllegalVal(), failureKind), "failureKind");
  }
  String text = ContractHelper::RaiseContractFailedEvent(failureKind, userMessage, conditionText, innerException);
  if (text != nullptr) {
    ContractHelper::TriggerFailure(failureKind, text, userMessage, conditionText, innerException);
  }
}

} // namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractNamespace
