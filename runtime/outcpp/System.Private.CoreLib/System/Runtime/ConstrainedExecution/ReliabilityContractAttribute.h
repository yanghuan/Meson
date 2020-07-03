#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution {
enum class Consistency;
enum class Cer;
namespace ReliabilityContractAttributeNamespace {
CLASS(ReliabilityContractAttribute) {
  private: Consistency ConsistencyGuarantee;
  private: Cer Cer;
};
} // namespace ReliabilityContractAttributeNamespace
using ReliabilityContractAttribute = ReliabilityContractAttributeNamespace::ReliabilityContractAttribute;
} // namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution
