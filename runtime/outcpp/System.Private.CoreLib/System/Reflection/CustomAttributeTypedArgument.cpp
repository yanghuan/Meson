#include "CustomAttributeTypedArgument-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Reflection::CustomAttributeTypedArgumentNamespace {
Type CustomAttributeTypedArgument::get_ArgumentType() {
  return m_argumentType;
}

Object CustomAttributeTypedArgument::get_Value() {
  return m_value;
}

Type CustomAttributeTypedArgument::CustomAttributeEncodingToType(CustomAttributeEncoding encodedType) {
}

Object CustomAttributeTypedArgument::EncodedValueToRawValue(Int64 val, CustomAttributeEncoding encodedType) {
  switch (encodedType) {
    case CustomAttributeEncoding::Boolean:
      return (Byte)val != 0;
    case CustomAttributeEncoding::Char:
      return (Char)val;
    case CustomAttributeEncoding::Byte:
      return (Byte)val;
    case CustomAttributeEncoding::SByte:
      return (SByte)val;
    case CustomAttributeEncoding::Int16:
      return (Int16)val;
    case CustomAttributeEncoding::UInt16:
      return (UInt16)val;
    case CustomAttributeEncoding::Int32:
      return (Int32)val;
    case CustomAttributeEncoding::UInt32:
      return (UInt32)val;
    case CustomAttributeEncoding::Int64:
      return val;
    case CustomAttributeEncoding::UInt64:
      return (UInt64)val;
    case CustomAttributeEncoding::Float:
      return *(Single*)(&val);
    case CustomAttributeEncoding::Double:
      return *(Double*)(&val);
    default:
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumIllegalVal(), (Int32)val), "val");
  }
}

RuntimeType CustomAttributeTypedArgument::ResolveType(RuntimeModule scope, String typeName) {
  RuntimeType typeByNameUsingCARules = RuntimeTypeHandle::GetTypeByNameUsingCARules(typeName, scope);
  if (typeByNameUsingCARules == nullptr) {
    rt::throw_exception<InvalidOperationException>(SR::Format(SR::get_Arg_CATypeResolutionFailed(), typeName));
  }
  return typeByNameUsingCARules;
}

Object CustomAttributeTypedArgument::CanonicalizeValue(Object value) {
  if (value->GetType()->get_IsEnum()) {
    return ((Enum)value)->GetValue();
  }
  return value;
}

CustomAttributeTypedArgument::CustomAttributeTypedArgument(RuntimeModule scope, CustomAttributeEncodedArgument encodedArg) {
  CustomAttributeEncoding encodedType = encodedArg.get_CustomAttributeType().get_EncodedType();
}

Boolean CustomAttributeTypedArgument::op_Equality(CustomAttributeTypedArgument left, CustomAttributeTypedArgument right) {
  return left.Equals(right);
}

Boolean CustomAttributeTypedArgument::op_Inequality(CustomAttributeTypedArgument left, CustomAttributeTypedArgument right) {
  return !left.Equals(right);
}

CustomAttributeTypedArgument::CustomAttributeTypedArgument(Type argumentType, Object value) {
  if (argumentType == nullptr) {
    rt::throw_exception<ArgumentNullException>("argumentType");
  }
  m_value = ((value == nullptr) ? nullptr : CanonicalizeValue(value));
  m_argumentType = argumentType;
}

CustomAttributeTypedArgument::CustomAttributeTypedArgument(Object value) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  m_value = CanonicalizeValue(value);
  m_argumentType = value->GetType();
}

String CustomAttributeTypedArgument::ToString() {
  return ToString(false);
}

String CustomAttributeTypedArgument::ToString(Boolean typed) {
  if (m_argumentType == nullptr) {
  }
  if (get_ArgumentType()->get_IsEnum()) {
    return String::in::Format(typed ? "{0}" : "({1}){0}", get_Value(), get_ArgumentType()->get_FullName());
  }
  if (get_Value() == nullptr) {
    return String::in::Format(typed ? "null" : "({0})null", get_ArgumentType()->get_Name());
  }
}

Int32 CustomAttributeTypedArgument::GetHashCode() {
}

Boolean CustomAttributeTypedArgument::Equals(Object obj) {
  return obj == (Object)*this;
}

} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeTypedArgumentNamespace
