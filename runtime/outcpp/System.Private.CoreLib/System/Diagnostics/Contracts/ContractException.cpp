#include "ContractException-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractExceptionNamespace {
ContractFailureKind ContractException___::get_Kind() {
  return ContractFailureKind::Assume;
};

String ContractException___::get_Failure() {
  return nullptr;
};

String ContractException___::get_UserMessage() {
  return nullptr;
};

String ContractException___::get_Condition() {
  return nullptr;
};

void ContractException___::GetObjectData(SerializationInfo info, StreamingContext context) {
};

} // namespace System::Private::CoreLib::System::Diagnostics::Contracts::ContractExceptionNamespace
