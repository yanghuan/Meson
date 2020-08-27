#include "CustomAttributeTypedArgument-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/Boolean-dep.h>
#include <System.Private.CoreLib/System/Byte-dep.h>
#include <System.Private.CoreLib/System/Char-dep.h>
#include <System.Private.CoreLib/System/Collections/Generic/IList.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/Enum-dep.h>
#include <System.Private.CoreLib/System/Int16-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Reflection/CustomAttributeTypedArgument-dep.h>
#include <System.Private.CoreLib/System/RuntimeTypeHandle-dep.h>
#include <System.Private.CoreLib/System/SByte-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/String-dep.h>
#include <System.Private.CoreLib/System/UInt16-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>
#include <System.Private.CoreLib/System/UInt64-dep.h>

namespace System::Private::CoreLib::System::Reflection::CustomAttributeTypedArgumentNamespace {
using namespace System::Collections::Generic;

Type CustomAttributeTypedArgument::get_ArgumentType() {
  return m_argumentType;
}

Object CustomAttributeTypedArgument::get_Value() {
  return m_value;
}

Type CustomAttributeTypedArgument::CustomAttributeEncodingToType(CustomAttributeEncoding encodedType) {
  switch (encodedType) {
    case CustomAttributeEncoding::Enum:
      return typeof<Enum>();
    case CustomAttributeEncoding::Int32:
      return typeof<Int32>();
    case CustomAttributeEncoding::String:
      return typeof<String>();
    case CustomAttributeEncoding::Type:
      return typeof<Type>();
    case CustomAttributeEncoding::Array:
      return typeof<Array<>>();
    case CustomAttributeEncoding::Char:
      return typeof<Char>();
    case CustomAttributeEncoding::Boolean:
      return typeof<Boolean>();
    case CustomAttributeEncoding::SByte:
      return typeof<SByte>();
    case CustomAttributeEncoding::Byte:
      return typeof<Byte>();
    case CustomAttributeEncoding::Int16:
      return typeof<Int16>();
    case CustomAttributeEncoding::UInt16:
      return typeof<UInt16>();
    case CustomAttributeEncoding::UInt32:
      return typeof<UInt32>();
    case CustomAttributeEncoding::Int64:
      return typeof<Int64>();
    case CustomAttributeEncoding::UInt64:
      return typeof<UInt64>();
    case CustomAttributeEncoding::Float:
      return typeof<Single>();
    case CustomAttributeEncoding::Double:
      return typeof<Double>();
    case CustomAttributeEncoding::Object:
      return typeof<Object>();
    default:
      rt::throw_exception<ArgumentException>(SR::Format(SR::get_Arg_EnumIllegalVal(), (Int32)encodedType), "encodedType");
  }
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
  switch (encodedType) {
    case CustomAttributeEncoding::Undefined:
      rt::throw_exception<ArgumentException>(nullptr, "encodedArg");
    case CustomAttributeEncoding::Enum:
      m_argumentType = ResolveType(scope, encodedArg.get_CustomAttributeType().get_EnumName());
      m_value = EncodedValueToRawValue(encodedArg.get_PrimitiveValue(), encodedArg.get_CustomAttributeType().get_EncodedEnumType());
      break;
    case CustomAttributeEncoding::String:
      m_argumentType = typeof<String>();
      m_value = encodedArg.get_StringValue();
      break;
    case CustomAttributeEncoding::Type:
      m_argumentType = typeof<Type>();
      m_value = nullptr;
      if (encodedArg.get_StringValue() != nullptr) {
        m_value = ResolveType(scope, encodedArg.get_StringValue());
      }
      break;
    case CustomAttributeEncoding::Array:
      {
        encodedType = encodedArg.get_CustomAttributeType().get_EncodedArrayType();
        Type type = (encodedType != CustomAttributeEncoding::Enum) ? CustomAttributeEncodingToType(encodedType) : ResolveType(scope, encodedArg.get_CustomAttributeType().get_EnumName());
        m_argumentType = type->MakeArrayType();
        if (encodedArg.get_ArrayValue() == nullptr) {
          m_value = nullptr;
          break;
        }
        Array<CustomAttributeTypedArgument> array = rt::newarr<Array<CustomAttributeTypedArgument>>(encodedArg.get_ArrayValue()->get_Length());
        for (Int32 i = 0; i < array->get_Length(); i++) {
          array[i] = CustomAttributeTypedArgument(scope, encodedArg.get_ArrayValue()[i]);
        }
        m_value = Array<>::in::AsReadOnly(array);
        break;
      }default:
      m_argumentType = CustomAttributeEncodingToType(encodedType);
      m_value = EncodedValueToRawValue(encodedArg.get_PrimitiveValue(), encodedType);
      break;
  }
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
    return ValueType::in::ToString();
  }
  if (get_ArgumentType()->get_IsEnum()) {
    return String::in::Format(typed ? "{0}" : "({1}){0}", get_Value(), get_ArgumentType()->get_FullName());
  }
  if (get_Value() == nullptr) {
    return String::in::Format(typed ? "null" : "({0})null", get_ArgumentType()->get_Name());
  }
  if (get_ArgumentType() == typeof<String>()) {
    return String::in::Format("\"{0}\"", get_Value());
  }
  if (get_ArgumentType() == typeof<Char>()) {
    return String::in::Format("'{0}'", get_Value());
  }
  if (get_ArgumentType() == typeof<Type>()) {
    return String::in::Format("typeof({0})", ((Type)get_Value())->get_FullName());
  }
  if (get_ArgumentType()->get_IsArray()) {
    IList<CustomAttributeTypedArgument> list = (IList<CustomAttributeTypedArgument>)get_Value();
    Type elementType = get_ArgumentType()->GetElementType();
    String str = String::in::Format("new {0}[{1}] {{ ", elementType->get_IsEnum() ? elementType->get_FullName() : elementType->get_Name(), list->get_Count());
    for (Int32 i = 0; i < list->get_Count(); i++) {
      str += String::in::Format((i == 0) ? "{0}" : ", {0}", list[i].ToString(elementType != typeof<Object>()));
    }
    return str + " }";
  }
  return String::in::Format(typed ? "{0}" : "({1}){0}", get_Value(), get_ArgumentType()->get_Name());
}

Int32 CustomAttributeTypedArgument::GetHashCode() {
  return ValueType::in::GetHashCode();
}

Boolean CustomAttributeTypedArgument::Equals(Object obj) {
  return obj == (Object)*this;
}

} // namespace System::Private::CoreLib::System::Reflection::CustomAttributeTypedArgumentNamespace
