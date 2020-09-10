#include "SymbolType-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Array-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/SymbolType-dep.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeKind.h>
#include <System.Private.CoreLib/System/Reflection/Emit/TypeNameBuilder-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Type-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::SymbolTypeNamespace {
Boolean SymbolType___::get_IsTypeDefinition() {
  return false;
}

Boolean SymbolType___::get_IsSZArray() {
  if (m_cRank <= 1) {
    return m_isSzArray;
  }
  return false;
}

Guid SymbolType___::get_GUID() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Module SymbolType___::get_Module() {
  Type baseType = m_baseType;
  while (rt::is<SymbolType>(baseType)) {
    baseType = ((SymbolType)baseType)->m_baseType;
  }
  return baseType->get_Module();
}

Assembly SymbolType___::get_Assembly() {
  Type baseType = m_baseType;
  while (rt::is<SymbolType>(baseType)) {
    baseType = ((SymbolType)baseType)->m_baseType;
  }
  return baseType->get_Assembly();
}

RuntimeTypeHandle SymbolType___::get_TypeHandle() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

String SymbolType___::get_Name() {
  String str = m_format;
  Type baseType = m_baseType;
  while (rt::is<SymbolType>(baseType)) {
    str = ((SymbolType)baseType)->m_format + str;
    baseType = ((SymbolType)baseType)->m_baseType;
  }
  return baseType->get_Name() + str;
}

String SymbolType___::get_FullName() {
  return TypeNameBuilder::in::ToString((SymbolType)this, TypeNameBuilder::in::Format::FullName);
}

String SymbolType___::get_AssemblyQualifiedName() {
  return TypeNameBuilder::in::ToString((SymbolType)this, TypeNameBuilder::in::Format::AssemblyQualifiedName);
}

String SymbolType___::get_Namespace() {
  return m_baseType->get_Namespace();
}

Type SymbolType___::get_BaseType() {
  return typeof<Array<>>();
}

Boolean SymbolType___::get_IsConstructedGenericType() {
  return false;
}

Type SymbolType___::get_UnderlyingSystemType() {
  return (SymbolType)this;
}

Boolean SymbolType___::IsAssignableFrom(TypeInfo typeInfo) {
  if (typeInfo == nullptr) {
    return false;
  }
  return IsAssignableFrom(typeInfo->AsType());
}

Type SymbolType___::FormCompoundType(String format, Type baseType, Int32 curIndex) {
  if (format == nullptr || curIndex == format->get_Length()) {
    return baseType;
  }
  if (format[curIndex] == '&') {
    SymbolType symbolType = rt::newobj<SymbolType>(TypeKind::IsByRef);
    symbolType->SetFormat(format, curIndex, 1);
    curIndex++;
    if (curIndex != format->get_Length()) {
      rt::throw_exception<ArgumentException>(SR::get_Argument_BadSigFormat());
    }
    symbolType->SetElementType(baseType);
    return symbolType;
  }
  if (format[curIndex] == '[') {
    SymbolType symbolType = rt::newobj<SymbolType>(TypeKind::IsArray);
    Int32 num = curIndex;
    curIndex++;
    Int32 num2 = 0;
    Int32 num3 = -1;
    while (format[curIndex] != ']') {
      if (format[curIndex] == '*') {
        symbolType->m_isSzArray = false;
        curIndex++;
      }
      if ((format[curIndex] >= '0' && format[curIndex] <= '9') || format[curIndex] == '-') {
        Boolean flag = false;
        if (format[curIndex] == '-') {
          flag = true;
          curIndex++;
        }
        while (format[curIndex] >= '0' && format[curIndex] <= '9') {
          num2 *= 10;
          num2 += format[curIndex] - 48;
          curIndex++;
        }
        if (flag) {
          num2 = -num2;
        }
        num3 = num2 - 1;
      }
      if (format[curIndex] == '.') {
        curIndex++;
        if (format[curIndex] != '.') {
          rt::throw_exception<ArgumentException>(SR::get_Argument_BadSigFormat());
        }
        curIndex++;
        if ((format[curIndex] >= '0' && format[curIndex] <= '9') || format[curIndex] == '-') {
          Boolean flag2 = false;
          num3 = 0;
          if (format[curIndex] == '-') {
            flag2 = true;
            curIndex++;
          }
          while (format[curIndex] >= '0' && format[curIndex] <= '9') {
            num3 *= 10;
            num3 += format[curIndex] - 48;
            curIndex++;
          }
          if (flag2) {
            num3 = -num3;
          }
          if (num3 < num2) {
            rt::throw_exception<ArgumentException>(SR::get_Argument_BadSigFormat());
          }
        }
      }
      if (format[curIndex] == ',') {
        curIndex++;
        symbolType->SetBounds(num2, num3);
        num2 = 0;
        num3 = -1;
      } else if (format[curIndex] != ']') {
        rt::throw_exception<ArgumentException>(SR::get_Argument_BadSigFormat());
      }

    }
    symbolType->SetBounds(num2, num3);
    curIndex++;
    symbolType->SetFormat(format, num, curIndex - num);
    symbolType->SetElementType(baseType);
    return FormCompoundType(format, symbolType, curIndex);
  }
  if (format[curIndex] == '*') {
    SymbolType symbolType = rt::newobj<SymbolType>(TypeKind::IsPointer);
    symbolType->SetFormat(format, curIndex, 1);
    curIndex++;
    symbolType->SetElementType(baseType);
    return FormCompoundType(format, symbolType, curIndex);
  }
  return nullptr;
}

void SymbolType___::ctor(TypeKind typeKind) {
  m_isSzArray = true;
  TypeInfo::in::ctor();
  m_typeKind = typeKind;
  m_iaLowerBound = rt::newarr<Array<Int32>>(4);
  m_iaUpperBound = rt::newarr<Array<Int32>>(4);
}

void SymbolType___::SetElementType(Type baseType) {
  if ((Object)baseType == nullptr) {
    rt::throw_exception<ArgumentNullException>("baseType");
  }
  m_baseType = baseType;
}

void SymbolType___::SetBounds(Int32 lower, Int32 upper) {
  if (lower != 0 || upper != -1) {
    m_isSzArray = false;
  }
  if (m_iaLowerBound->get_Length() <= m_cRank) {
    Array<Int32> array = rt::newarr<Array<Int32>>(m_cRank * 2);
    Array<>::in::Copy(m_iaLowerBound, array, m_cRank);
    m_iaLowerBound = array;
    Array<>::in::Copy(m_iaUpperBound, array, m_cRank);
    m_iaUpperBound = array;
  }
  m_iaLowerBound[m_cRank] = lower;
  m_iaUpperBound[m_cRank] = upper;
  m_cRank++;
}

void SymbolType___::SetFormat(String format, Int32 curIndex, Int32 length) {
  m_format = format->Substring(curIndex, length);
}

Type SymbolType___::MakePointerType() {
  return FormCompoundType(m_format + "*", m_baseType, 0);
}

Type SymbolType___::MakeByRefType() {
  return FormCompoundType(m_format + "&", m_baseType, 0);
}

Type SymbolType___::MakeArrayType() {
  return FormCompoundType(m_format + "[]", m_baseType, 0);
}

Type SymbolType___::MakeArrayType(Int32 rank) {
  String rankString = TypeInfo::in::GetRankString(rank);
  return rt::as<SymbolType>(FormCompoundType(m_format + rankString, m_baseType, 0));
}

Int32 SymbolType___::GetArrayRank() {
  if (!Type::in::get_IsArray()) {
    rt::throw_exception<NotSupportedException>(SR::get_NotSupported_SubclassOverride());
  }
  return m_cRank;
}

Object SymbolType___::InvokeMember(String name, BindingFlags invokeAttr, Binder binder, Object target, Array<Object> args, Array<ParameterModifier> modifiers, CultureInfo culture, Array<String> namedParameters) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

String SymbolType___::ToString() {
  return TypeNameBuilder::in::ToString((SymbolType)this, TypeNameBuilder::in::Format::ToString);
}

ConstructorInfo SymbolType___::GetConstructorImpl(BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Array<ConstructorInfo> SymbolType___::GetConstructors(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

MethodInfo SymbolType___::GetMethodImpl(String name, BindingFlags bindingAttr, Binder binder, CallingConventions callConvention, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Array<MethodInfo> SymbolType___::GetMethods(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

FieldInfo SymbolType___::GetField(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Array<FieldInfo> SymbolType___::GetFields(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Type SymbolType___::GetInterface(String name, Boolean ignoreCase) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Array<Type> SymbolType___::GetInterfaces() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

EventInfo SymbolType___::GetEvent(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Array<EventInfo> SymbolType___::GetEvents() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

PropertyInfo SymbolType___::GetPropertyImpl(String name, BindingFlags bindingAttr, Binder binder, Type returnType, Array<Type> types, Array<ParameterModifier> modifiers) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Array<PropertyInfo> SymbolType___::GetProperties(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Array<Type> SymbolType___::GetNestedTypes(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Type SymbolType___::GetNestedType(String name, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Array<MemberInfo> SymbolType___::GetMember(String name, MemberTypes type, BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Array<MemberInfo> SymbolType___::GetMembers(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

InterfaceMapping SymbolType___::GetInterfaceMap(Type interfaceType) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Array<EventInfo> SymbolType___::GetEvents(BindingFlags bindingAttr) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

TypeAttributes SymbolType___::GetAttributeFlagsImpl() {
  Type baseType = m_baseType;
  while (rt::is<SymbolType>(baseType)) {
    baseType = ((SymbolType)baseType)->m_baseType;
  }
  return baseType->get_Attributes();
}

Boolean SymbolType___::IsArrayImpl() {
  return m_typeKind == TypeKind::IsArray;
}

Boolean SymbolType___::IsPointerImpl() {
  return m_typeKind == TypeKind::IsPointer;
}

Boolean SymbolType___::IsByRefImpl() {
  return m_typeKind == TypeKind::IsByRef;
}

Boolean SymbolType___::IsPrimitiveImpl() {
  return false;
}

Boolean SymbolType___::IsValueTypeImpl() {
  return false;
}

Boolean SymbolType___::IsCOMObjectImpl() {
  return false;
}

Type SymbolType___::GetElementType() {
  return m_baseType;
}

Boolean SymbolType___::HasElementTypeImpl() {
  return m_baseType != nullptr;
}

Array<Object> SymbolType___::GetCustomAttributes(Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Array<Object> SymbolType___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

Boolean SymbolType___::IsDefined(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_NonReflectedType());
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::SymbolTypeNamespace
