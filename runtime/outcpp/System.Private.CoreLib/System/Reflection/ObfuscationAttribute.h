#pragma once

#include <System.Private.CoreLib/System/Attribute.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace ObfuscationAttributeNamespace {
CLASS(ObfuscationAttribute) : public Attribute::in {
  public: Boolean get_StripAfterObfuscation() { return StripAfterObfuscation; }
  public: void set_StripAfterObfuscation(Boolean value) { StripAfterObfuscation = value; }
  public: Boolean get_Exclude() { return Exclude; }
  public: void set_Exclude(Boolean value) { Exclude = value; }
  public: Boolean get_ApplyToMembers() { return ApplyToMembers; }
  public: void set_ApplyToMembers(Boolean value) { ApplyToMembers = value; }
  public: String get_Feature() { return Feature; }
  public: void set_Feature(String value) { Feature = value; }
  public: void Ctor();
  private: Boolean StripAfterObfuscation;
  private: Boolean Exclude;
  private: Boolean ApplyToMembers;
  private: String Feature;
};
} // namespace ObfuscationAttributeNamespace
using ObfuscationAttribute = ObfuscationAttributeNamespace::ObfuscationAttribute;
} // namespace System::Private::CoreLib::System::Reflection
