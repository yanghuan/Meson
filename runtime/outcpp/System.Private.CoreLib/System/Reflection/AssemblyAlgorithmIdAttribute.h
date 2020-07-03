#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System::Reflection {
namespace AssemblyAlgorithmIdAttributeNamespace {
CLASS(AssemblyAlgorithmIdAttribute) {
  private: UInt32 AlgorithmId;
};
} // namespace AssemblyAlgorithmIdAttributeNamespace
using AssemblyAlgorithmIdAttribute = AssemblyAlgorithmIdAttributeNamespace::AssemblyAlgorithmIdAttribute;
} // namespace System::Private::CoreLib::System::Reflection
