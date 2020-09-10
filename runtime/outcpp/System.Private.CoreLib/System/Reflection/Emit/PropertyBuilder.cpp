#include "PropertyBuilder-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/NotSupportedException-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodAttributes.h>
#include <System.Private.CoreLib/System/Runtime/CompilerServices/QCallModule-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::Emit::PropertyBuilderNamespace {
using namespace System::Runtime::CompilerServices;

PropertyToken PropertyBuilder___::get_PropertyToken() {
  return m_prToken;
}

Module PropertyBuilder___::get_Module() {
  return m_containingType->get_Module();
}

Type PropertyBuilder___::get_PropertyType() {
  return m_returnType;
}

PropertyAttributes PropertyBuilder___::get_Attributes() {
  return m_attributes;
}

Boolean PropertyBuilder___::get_CanRead() {
  if (m_getMethod != nullptr) {
    return true;
  }
  return false;
}

Boolean PropertyBuilder___::get_CanWrite() {
  if (m_setMethod != nullptr) {
    return true;
  }
  return false;
}

String PropertyBuilder___::get_Name() {
  return m_name;
}

Type PropertyBuilder___::get_DeclaringType() {
  return m_containingType;
}

Type PropertyBuilder___::get_ReflectedType() {
  return m_containingType;
}

void PropertyBuilder___::ctor(ModuleBuilder mod, String name, SignatureHelper sig, PropertyAttributes attr, Type returnType, PropertyToken prToken, TypeBuilder containingType) {
  if (name == nullptr) {
    rt::throw_exception<ArgumentNullException>("name");
  }
  if (name->get_Length() == 0) {
    rt::throw_exception<ArgumentException>(SR::get_Argument_EmptyName(), "name");
  }
  if (name[0] == '\0') {
    rt::throw_exception<ArgumentException>(SR::get_Argument_IllegalName(), "name");
  }
  m_name = name;
  m_moduleBuilder = mod;
  m_signature = sig;
  m_attributes = attr;
  m_returnType = returnType;
  m_prToken = prToken;
  m_tkProperty = prToken.get_Token();
  m_containingType = containingType;
}

void PropertyBuilder___::SetConstant(Object defaultValue) {
  m_containingType->ThrowIfCreated();
  TypeBuilder::in::SetConstantValue(m_moduleBuilder, m_prToken.get_Token(), m_returnType, defaultValue);
}

void PropertyBuilder___::SetMethodSemantics(MethodBuilder mdBuilder, MethodSemanticsAttributes semantics) {
  if (mdBuilder == nullptr) {
    rt::throw_exception<ArgumentNullException>("mdBuilder");
  }
  m_containingType->ThrowIfCreated();
  ModuleBuilder module = m_moduleBuilder;
  TypeBuilder::in::DefineMethodSemantics(QCallModule(module), m_prToken.get_Token(), semantics, mdBuilder->GetToken().get_Token());
}

void PropertyBuilder___::SetGetMethod(MethodBuilder mdBuilder) {
  SetMethodSemantics(mdBuilder, MethodSemanticsAttributes::Getter);
  m_getMethod = mdBuilder;
}

void PropertyBuilder___::SetSetMethod(MethodBuilder mdBuilder) {
  SetMethodSemantics(mdBuilder, MethodSemanticsAttributes::Setter);
  m_setMethod = mdBuilder;
}

void PropertyBuilder___::AddOtherMethod(MethodBuilder mdBuilder) {
  SetMethodSemantics(mdBuilder, MethodSemanticsAttributes::Other);
}

void PropertyBuilder___::SetCustomAttribute(ConstructorInfo con, Array<Byte> binaryAttribute) {
  if (con == nullptr) {
    rt::throw_exception<ArgumentNullException>("con");
  }
  if (binaryAttribute == nullptr) {
    rt::throw_exception<ArgumentNullException>("binaryAttribute");
  }
  m_containingType->ThrowIfCreated();
  TypeBuilder::in::DefineCustomAttribute(m_moduleBuilder, m_prToken.get_Token(), m_moduleBuilder->GetConstructorToken(con).get_Token(), binaryAttribute, false, false);
}

void PropertyBuilder___::SetCustomAttribute(CustomAttributeBuilder customBuilder) {
  if (customBuilder == nullptr) {
    rt::throw_exception<ArgumentNullException>("customBuilder");
  }
  m_containingType->ThrowIfCreated();
  customBuilder->CreateCustomAttribute(m_moduleBuilder, m_prToken.get_Token());
}

Object PropertyBuilder___::GetValue(Object obj, Array<Object> index) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Object PropertyBuilder___::GetValue(Object obj, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

void PropertyBuilder___::SetValue(Object obj, Object value, Array<Object> index) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

void PropertyBuilder___::SetValue(Object obj, Object value, BindingFlags invokeAttr, Binder binder, Array<Object> index, CultureInfo culture) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Array<MethodInfo> PropertyBuilder___::GetAccessors(Boolean nonPublic) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

MethodInfo PropertyBuilder___::GetGetMethod(Boolean nonPublic) {
  if (nonPublic || m_getMethod == nullptr) {
    return m_getMethod;
  }
  if ((m_getMethod->get_Attributes() & MethodAttributes::Public) == MethodAttributes::Public) {
    return m_getMethod;
  }
  return nullptr;
}

MethodInfo PropertyBuilder___::GetSetMethod(Boolean nonPublic) {
  if (nonPublic || m_setMethod == nullptr) {
    return m_setMethod;
  }
  if ((m_setMethod->get_Attributes() & MethodAttributes::Public) == MethodAttributes::Public) {
    return m_setMethod;
  }
  return nullptr;
}

Array<ParameterInfo> PropertyBuilder___::GetIndexParameters() {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Array<Object> PropertyBuilder___::GetCustomAttributes(Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Array<Object> PropertyBuilder___::GetCustomAttributes(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

Boolean PropertyBuilder___::IsDefined(Type attributeType, Boolean inherit) {
  rt::throw_exception<NotSupportedException>(SR::get_NotSupported_DynamicModule());
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::PropertyBuilderNamespace
