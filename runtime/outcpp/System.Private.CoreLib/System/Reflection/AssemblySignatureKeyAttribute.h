#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace AssemblySignatureKeyAttributeNamespace {
CLASS(AssemblySignatureKeyAttribute) : public Attribute::in {
  public: String get_PublicKey() { return PublicKey; }
  public: String get_Countersignature() { return Countersignature; }
  public: void Ctor(String publicKey, String countersignature);
  private: String PublicKey;
  private: String Countersignature;
};
} // namespace AssemblySignatureKeyAttributeNamespace
using AssemblySignatureKeyAttribute = AssemblySignatureKeyAttributeNamespace::AssemblySignatureKeyAttribute;
} // namespace System::Private::CoreLib::System::Reflection
