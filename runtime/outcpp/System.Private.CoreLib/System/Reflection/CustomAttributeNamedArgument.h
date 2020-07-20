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
struct CustomAttributeNamedArgument : public rt::ValueType<CustomAttributeNamedArgument> {
  public: Type get_ArgumentType();
  public: MemberInfo get_MemberInfo();
  public: CustomAttributeTypedArgument get_TypedValue();
  public: String get_MemberName();
  public: Boolean get_IsField();
  public: static Boolean op_Equality(CustomAttributeNamedArgument left, CustomAttributeNamedArgument right);
  public: static Boolean op_Inequality(CustomAttributeNamedArgument left, CustomAttributeNamedArgument right);
  public: void Ctor(MemberInfo memberInfo, Object value);
  public: void Ctor(MemberInfo memberInfo, CustomAttributeTypedArgument typedArgument);
  public: String ToString();
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: void Ctor();
  private: MemberInfo m_memberInfo;
  private: CustomAttributeTypedArgument m_value;
};
} // namespace CustomAttributeNamedArgumentNamespace
using CustomAttributeNamedArgument = CustomAttributeNamedArgumentNamespace::CustomAttributeNamedArgument;
} // namespace System::Private::CoreLib::System::Reflection
