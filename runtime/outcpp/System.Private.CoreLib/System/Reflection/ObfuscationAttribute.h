#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace ObfuscationAttributeNamespace {
CLASS(ObfuscationAttribute) {
  private: Boolean StripAfterObfuscation;
  private: Boolean Exclude;
  private: Boolean ApplyToMembers;
  private: String Feature;
};
} // namespace ObfuscationAttributeNamespace
using ObfuscationAttribute = ObfuscationAttributeNamespace::ObfuscationAttribute;
} // namespace System::Private::CoreLib::System::Reflection
