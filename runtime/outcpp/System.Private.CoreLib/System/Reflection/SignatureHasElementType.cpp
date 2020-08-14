#include "SignatureHasElementType-dep.h"

#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::SignatureHasElementTypeNamespace {
Boolean SignatureHasElementType___::get_IsTypeDefinition() {
  return false;
}

Boolean SignatureHasElementType___::get_IsGenericTypeDefinition() {
  return false;
}

Boolean SignatureHasElementType___::get_IsByRefLike() {
  return false;
}

Boolean SignatureHasElementType___::get_IsConstructedGenericType() {
  return false;
}

Boolean SignatureHasElementType___::get_IsGenericParameter() {
  return false;
}

Boolean SignatureHasElementType___::get_IsGenericTypeParameter() {
  return false;
}

Boolean SignatureHasElementType___::get_IsGenericMethodParameter() {
  return false;
}

Boolean SignatureHasElementType___::get_ContainsGenericParameters() {
  return _elementType->get_ContainsGenericParameters();
}

SignatureType SignatureHasElementType___::get_ElementType() {
  return _elementType;
}

Array<Type> SignatureHasElementType___::get_GenericTypeArguments() {
  return Array<>::in::Empty<Type>();
}

Int32 SignatureHasElementType___::get_GenericParameterPosition() {
  rt::throw_exception<InvalidOperationException>(SR::get_Arg_NotGenericParameter());
}

String SignatureHasElementType___::get_Name() {
  return _elementType->get_Name() + get_Suffix();
}

String SignatureHasElementType___::get_Namespace() {
  return _elementType->get_Namespace();
}

void SignatureHasElementType___::ctor(SignatureType elementType) {
  _elementType = elementType;
}

Boolean SignatureHasElementType___::HasElementTypeImpl() {
  return true;
}

Type SignatureHasElementType___::GetGenericTypeDefinition() {
  rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotGenericType());
}

Array<Type> SignatureHasElementType___::GetGenericArguments() {
  return Array<>::in::Empty<Type>();
}

String SignatureHasElementType___::ToString() {
  return _elementType->ToString() + get_Suffix();
}

} // namespace System::Private::CoreLib::System::Reflection::SignatureHasElementTypeNamespace
