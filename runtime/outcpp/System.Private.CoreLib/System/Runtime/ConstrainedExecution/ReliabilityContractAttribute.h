#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution {
enum class Cer : int32_t;
enum class Consistency : int32_t;
namespace ReliabilityContractAttributeNamespace {
CLASS(ReliabilityContractAttribute) : public Attribute::in {
  public: Consistency get_ConsistencyGuarantee() { return ConsistencyGuarantee; }
  public: Cer get_Cer() { return Cer; }
  public: void ctor(Consistency consistencyGuarantee, Cer cer);
  private: Consistency ConsistencyGuarantee;
  private: Cer Cer;
};
} // namespace ReliabilityContractAttributeNamespace
using ReliabilityContractAttribute = ReliabilityContractAttributeNamespace::ReliabilityContractAttribute;
} // namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution
