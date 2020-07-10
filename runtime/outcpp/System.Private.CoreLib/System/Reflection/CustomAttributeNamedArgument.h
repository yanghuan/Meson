#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeTypedArgument.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Object)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MemberInfo)
namespace CustomAttributeNamedArgumentNamespace {
struct CustomAttributeNamedArgument {
  public: Type get_ArgumentType();
  public: MemberInfo get_MemberInfo();
  public: CustomAttributeTypedArgument get_TypedValue();
  public: String get_MemberName();
  public: Boolean get_IsField();
  public: static Boolean op_Equality(CustomAttributeNamedArgument left, CustomAttributeNamedArgument right);
  public: static Boolean op_Inequality(CustomAttributeNamedArgument left, CustomAttributeNamedArgument right);
  public: String ToString();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  private: MemberInfo m_memberInfo;
  private: CustomAttributeTypedArgument m_value;
};
} // namespace CustomAttributeNamedArgumentNamespace
using CustomAttributeNamedArgument = CustomAttributeNamedArgumentNamespace::CustomAttributeNamedArgument;
} // namespace System::Private::CoreLib::System::Reflection
