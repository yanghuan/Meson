#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARD(Object)
FORWARD(RuntimeType)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class CustomAttributeEncoding : int32_t;
FORWARDS(CustomAttributeEncodedArgument)
FORWARD(RuntimeModule)
namespace CustomAttributeTypedArgumentNamespace {
struct CustomAttributeTypedArgument : public valueType<CustomAttributeTypedArgument> {
  public: Type get_ArgumentType();
  public: Object get_Value();
  private: static Type CustomAttributeEncodingToType(CustomAttributeEncoding encodedType);
  private: static Object EncodedValueToRawValue(Int64 val, CustomAttributeEncoding encodedType);
  private: static RuntimeType ResolveType(RuntimeModule scope, String typeName);
  private: static Object CanonicalizeValue(Object value);
  public: explicit CustomAttributeTypedArgument(RuntimeModule scope, CustomAttributeEncodedArgument encodedArg);
  public: static Boolean op_Equality(CustomAttributeTypedArgument left, CustomAttributeTypedArgument right);
  public: static Boolean op_Inequality(CustomAttributeTypedArgument left, CustomAttributeTypedArgument right);
  public: explicit CustomAttributeTypedArgument(Type argumentType, Object value);
  public: explicit CustomAttributeTypedArgument(Object value);
  public: String ToString();
  public: String ToString(Boolean typed);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: explicit CustomAttributeTypedArgument() {}
  private: Object m_value;
  private: Type m_argumentType;
};
} // namespace CustomAttributeTypedArgumentNamespace
using CustomAttributeTypedArgument = CustomAttributeTypedArgumentNamespace::CustomAttributeTypedArgument;
} // namespace System::Private::CoreLib::System::Reflection
