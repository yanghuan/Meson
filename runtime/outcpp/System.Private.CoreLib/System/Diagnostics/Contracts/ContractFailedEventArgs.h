#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/EventArgs.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
enum class ContractFailureKind;
namespace ContractFailedEventArgsNamespace {
CLASS(ContractFailedEventArgs) : public EventArgs::in {
  public: String get_Message();
  public: String get_Condition();
  public: ContractFailureKind get_FailureKind();
  public: Exception get_OriginalException();
  public: Boolean get_Handled();
  public: Boolean get_Unwind();
  public: void Ctor(ContractFailureKind failureKind, String message, String condition, Exception originalException);
  public: void SetHandled();
  public: void SetUnwind();
  private: ContractFailureKind _failureKind;
  private: String _message;
  private: String _condition;
  private: Exception _originalException;
  private: Boolean _handled;
  private: Boolean _unwind;
  public: Exception thrownDuringHandler;
};
} // namespace ContractFailedEventArgsNamespace
using ContractFailedEventArgs = ContractFailedEventArgsNamespace::ContractFailedEventArgs;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
