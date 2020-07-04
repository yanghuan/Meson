#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
enum class DynamicallyAccessedMemberTypes;
namespace DynamicDependencyAttributeNamespace {
CLASS(DynamicDependencyAttribute) {
  public: String get_MemberSignature() { return MemberSignature; }
  public: DynamicallyAccessedMemberTypes get_MemberTypes() { return MemberTypes; }
  public: Type get_Type() { return Type; }
  public: String get_TypeName() { return TypeName; }
  public: String get_AssemblyName() { return AssemblyName; }
  public: String get_Condition() { return Condition; }
  public: void set_Condition(String value) { Condition = value; }
  private: String MemberSignature;
  private: DynamicallyAccessedMemberTypes MemberTypes;
  private: Type Type;
  private: String TypeName;
  private: String AssemblyName;
  private: String Condition;
};
} // namespace DynamicDependencyAttributeNamespace
using DynamicDependencyAttribute = DynamicDependencyAttributeNamespace::DynamicDependencyAttribute;
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
