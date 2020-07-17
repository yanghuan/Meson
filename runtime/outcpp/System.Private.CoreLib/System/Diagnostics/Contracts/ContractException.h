#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Exception)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
enum class ContractFailureKind;
namespace ContractExceptionNamespace {
using namespace Runtime::Serialization;
CLASS(ContractException) {
  public: ContractFailureKind get_Kind();
  public: String get_Failure();
  public: String get_UserMessage();
  public: String get_Condition();
  private: void Ctor();
  public: void Ctor(ContractFailureKind kind, String failure, String userMessage, String condition, Exception innerException);
  private: void Ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: ContractFailureKind _kind;
  private: String _userMessage;
  private: String _condition;
};
} // namespace ContractExceptionNamespace
using ContractException = ContractExceptionNamespace::ContractException;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
