#pragma once

#include <System.Private.CoreLib/System/Exception.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime::Serialization {
FORWARD(SerializationInfo)
FORWARDS(StreamingContext)
} // namespace System::Private::CoreLib::System::Runtime::Serialization
namespace System::Private::CoreLib::System::Diagnostics::Contracts {
enum class ContractFailureKind : int32_t;
namespace ContractExceptionNamespace {
using namespace System::Runtime::Serialization;
CLASS(ContractException) : public Exception::in {
  public: ContractFailureKind get_Kind();
  public: String get_Failure();
  public: String get_UserMessage();
  public: String get_Condition();
  private: void ctor();
  public: void ctor(ContractFailureKind kind, String failure, String userMessage, String condition, Exception innerException);
  private: void ctor(SerializationInfo info, StreamingContext context);
  public: void GetObjectData(SerializationInfo info, StreamingContext context);
  private: ContractFailureKind _kind;
  private: String _userMessage;
  private: String _condition;
};
} // namespace ContractExceptionNamespace
using ContractException = ContractExceptionNamespace::ContractException;
} // namespace System::Private::CoreLib::System::Diagnostics::Contracts
