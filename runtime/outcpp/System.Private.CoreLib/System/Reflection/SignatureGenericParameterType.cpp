#include "SignatureGenericParameterType-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::SignatureGenericParameterTypeNamespace {
Boolean SignatureGenericParameterType___::get_IsTypeDefinition() {
  return false;
}

Boolean SignatureGenericParameterType___::get_IsGenericTypeDefinition() {
  return false;
}

Boolean SignatureGenericParameterType___::get_IsByRefLike() {
  return false;
}

Boolean SignatureGenericParameterType___::get_IsSZArray() {
  return false;
}

Boolean SignatureGenericParameterType___::get_IsVariableBoundArray() {
  return false;
}

Boolean SignatureGenericParameterType___::get_IsConstructedGenericType() {
  return false;
}

Boolean SignatureGenericParameterType___::get_IsGenericParameter() {
  return true;
}

Boolean SignatureGenericParameterType___::get_ContainsGenericParameters() {
  return true;
}

SignatureType SignatureGenericParameterType___::get_ElementType() {
  return nullptr;
}

Array<Type> SignatureGenericParameterType___::get_GenericTypeArguments() {
  return Array<>::in::Empty<Type>();
}

Int32 SignatureGenericParameterType___::get_GenericParameterPosition() {
  return _position;
}

String SignatureGenericParameterType___::get_Namespace() {
  return nullptr;
}

void SignatureGenericParameterType___::ctor(Int32 position) {
  _position = position;
}

Boolean SignatureGenericParameterType___::HasElementTypeImpl() {
  return false;
}

Boolean SignatureGenericParameterType___::IsArrayImpl() {
  return false;
}

Boolean SignatureGenericParameterType___::IsByRefImpl() {
  return false;
}

Boolean SignatureGenericParameterType___::IsPointerImpl() {
  return false;
}

Int32 SignatureGenericParameterType___::GetArrayRank() {
  rt::throw_exception<ArgumentException>(SR::get_Argument_HasToBeArrayClass());
}

Type SignatureGenericParameterType___::GetGenericTypeDefinition() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotGenericType());
}

Array<Type> SignatureGenericParameterType___::GetGenericArguments() {
  return Array<>::in::Empty<Type>();
}

String SignatureGenericParameterType___::ToString() {
  return get_Name();
}

} // namespace System::Private::CoreLib::System::Reflection::SignatureGenericParameterTypeNamespace
