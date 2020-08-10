#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System::Configuration::Assemblies {
enum class AssemblyHashAlgorithm;
} // namespace System::Private::CoreLib::System::Configuration::Assemblies
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyAlgorithmIdAttributeNamespace {
using namespace Configuration::Assemblies;
CLASS(AssemblyAlgorithmIdAttribute) : public Attribute::in {
  public: UInt32 get_AlgorithmId() { return AlgorithmId; }
  public: void ctor(AssemblyHashAlgorithm algorithmId);
  public: void ctor(UInt32 algorithmId);
  private: UInt32 AlgorithmId;
};
} // namespace AssemblyAlgorithmIdAttributeNamespace
using AssemblyAlgorithmIdAttribute = AssemblyAlgorithmIdAttributeNamespace::AssemblyAlgorithmIdAttribute;
} // namespace System::Private::CoreLib::System::Reflection
