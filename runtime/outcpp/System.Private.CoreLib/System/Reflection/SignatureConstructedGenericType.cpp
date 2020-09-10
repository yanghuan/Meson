#include "SignatureConstructedGenericType-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Text/StringBuilder-dep.h>

namespace System::Private::CoreLib::System::Reflection::SignatureConstructedGenericTypeNamespace {
using namespace System::Text;

Boolean SignatureConstructedGenericType___::get_IsTypeDefinition() {
  return false;
}

Boolean SignatureConstructedGenericType___::get_IsGenericTypeDefinition() {
  return false;
}

Boolean SignatureConstructedGenericType___::get_IsByRefLike() {
  return _genericTypeDefinition->get_IsByRefLike();
}

Boolean SignatureConstructedGenericType___::get_IsSZArray() {
  return false;
}

Boolean SignatureConstructedGenericType___::get_IsVariableBoundArray() {
  return false;
}

Boolean SignatureConstructedGenericType___::get_IsConstructedGenericType() {
  return true;
}

Boolean SignatureConstructedGenericType___::get_IsGenericParameter() {
  return false;
}

Boolean SignatureConstructedGenericType___::get_IsGenericTypeParameter() {
  return false;
}

Boolean SignatureConstructedGenericType___::get_IsGenericMethodParameter() {
  return false;
}

Boolean SignatureConstructedGenericType___::get_ContainsGenericParameters() {
  for (Int32 i = 0; i < _genericTypeArguments->get_Length(); i++) {
    if (_genericTypeArguments[i]->get_ContainsGenericParameters()) {
      return true;
    }
  }
  return false;
}

SignatureType SignatureConstructedGenericType___::get_ElementType() {
  return nullptr;
}

Array<Type> SignatureConstructedGenericType___::get_GenericTypeArguments() {
  return (Array<Type>)_genericTypeArguments->Clone();
}

Int32 SignatureConstructedGenericType___::get_GenericParameterPosition() {
  rt::throw_exception<InvalidOperationException>(SR::get_Arg_NotGenericParameter());
}

String SignatureConstructedGenericType___::get_Name() {
  return _genericTypeDefinition->get_Name();
}

String SignatureConstructedGenericType___::get_Namespace() {
  return _genericTypeDefinition->get_Namespace();
}

void SignatureConstructedGenericType___::ctor(Type genericTypeDefinition, Array<Type> typeArguments) {
  if ((Object)genericTypeDefinition == nullptr) {
    rt::throw_exception<ArgumentNullException>("genericTypeDefinition");
  }
  if (typeArguments == nullptr) {
    rt::throw_exception<ArgumentNullException>("typeArguments");
  }
  typeArguments = (Array<Type>)typeArguments->Clone();
  for (Int32 i = 0; i < typeArguments->get_Length(); i++) {
    if ((Object)typeArguments[i] == nullptr) {
      rt::throw_exception<ArgumentNullException>("typeArguments");
    }
  }
  _genericTypeDefinition = genericTypeDefinition;
  _genericTypeArguments = typeArguments;
}

Boolean SignatureConstructedGenericType___::HasElementTypeImpl() {
  return false;
}

Boolean SignatureConstructedGenericType___::IsArrayImpl() {
  return false;
}

Boolean SignatureConstructedGenericType___::IsByRefImpl() {
  return false;
}

Boolean SignatureConstructedGenericType___::IsPointerImpl() {
  return false;
}

Int32 SignatureConstructedGenericType___::GetArrayRank() {
  rt::throw_exception<ArgumentException>(SR::get_Argument_HasToBeArrayClass());
}

Type SignatureConstructedGenericType___::GetGenericTypeDefinition() {
  return _genericTypeDefinition;
}

Array<Type> SignatureConstructedGenericType___::GetGenericArguments() {
  return get_GenericTypeArguments();
}

String SignatureConstructedGenericType___::ToString() {
  StringBuilder stringBuilder = rt::newobj<StringBuilder>();
  stringBuilder->Append(_genericTypeDefinition->ToString());
  stringBuilder->Append('[');
  for (Int32 i = 0; i < _genericTypeArguments->get_Length(); i++) {
    if (i != 0) {
      stringBuilder->Append(',');
    }
    stringBuilder->Append(_genericTypeArguments[i]->ToString());
  }
  stringBuilder->Append(']');
  return stringBuilder->ToString();
}

} // namespace System::Private::CoreLib::System::Reflection::SignatureConstructedGenericTypeNamespace
