#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution {
enum class Cer;
enum class Consistency;
namespace ReliabilityContractAttributeNamespace {
CLASS(ReliabilityContractAttribute) : public Attribute::in {
  public: Consistency get_ConsistencyGuarantee() { return ConsistencyGuarantee; }
  public: Cer get_Cer() { return Cer; }
  public: void Ctor(Consistency consistencyGuarantee, Cer cer);
  private: Consistency ConsistencyGuarantee;
  private: Cer Cer;
};
} // namespace ReliabilityContractAttributeNamespace
using ReliabilityContractAttribute = ReliabilityContractAttributeNamespace::ReliabilityContractAttribute;
} // namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution
