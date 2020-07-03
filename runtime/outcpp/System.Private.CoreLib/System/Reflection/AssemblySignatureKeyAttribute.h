#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblySignatureKeyAttributeNamespace {
CLASS(AssemblySignatureKeyAttribute) {
  private: String PublicKey;
  private: String Countersignature;
};
} // namespace AssemblySignatureKeyAttributeNamespace
using AssemblySignatureKeyAttribute = AssemblySignatureKeyAttributeNamespace::AssemblySignatureKeyAttribute;
} // namespace System::Private::CoreLib::System::Reflection
