#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Diagnostics::Contracts {
enum class ContractFailureKind;
FORWARD(ContractFailedEventArgs)
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
namespace System::Private::CoreLib::System {
FORWARD_(EventHandler, T1, T2)
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::CompilerServices {
namespace ContractHelperNamespace {
using namespace Diagnostics::Contracts;
class ContractHelper : public Object::in {
  public: static String RaiseContractFailedEvent(ContractFailureKind failureKind, String userMessage, String conditionText, Exception innerException);
  public: static void TriggerFailure(ContractFailureKind kind, String displayMessage, String userMessage, String conditionText, Exception innerException);
  private: static String GetFailureMessage(ContractFailureKind failureKind, String conditionText);
  private: static String GetDisplayMessage(ContractFailureKind failureKind, String userMessage, String conditionText);
  private: static EventHandler<ContractFailedEventArgs> InternalContractFailed;
};
} // namespace ContractHelperNamespace
using ContractHelper = ContractHelperNamespace::ContractHelper;
} // namespace System::Private::CoreLib::System::Runtime::CompilerServices
