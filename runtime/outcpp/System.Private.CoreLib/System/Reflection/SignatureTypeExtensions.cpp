#include "SignatureTypeExtensions-dep.h"

#include <System.Private.CoreLib/System/Int32-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureType-dep.h>
#include <System.Private.CoreLib/System/Reflection/SignatureTypeExtensions-dep.h>

namespace System::Private::CoreLib::System::Reflection::SignatureTypeExtensionsNamespace {
Boolean SignatureTypeExtensions::MatchesParameterTypeExactly(Type pattern, ParameterInfo parameter) {
  auto& default = (rt::as<SignatureType>(pattern));
  auto& extern = SignatureTypeExtensions::MatchesExactly(default == nullptr ? nullptr : default, parameter->get_ParameterType());
  return extern != nullptr ? extern : ((Object)pattern == parameter->get_ParameterType());
}

Boolean SignatureTypeExtensions::MatchesExactly(SignatureType pattern, Type actual) {
  if (pattern->get_IsSZArray()) {
    if (actual->get_IsSZArray()) {
      return SignatureTypeExtensions::MatchesExactly(pattern->get_ElementType(), actual->GetElementType());
    }
    return false;
  }
  if (pattern->get_IsVariableBoundArray()) {
    if (actual->get_IsVariableBoundArray() && pattern->GetArrayRank() == actual->GetArrayRank()) {
      return SignatureTypeExtensions::MatchesExactly(pattern->get_ElementType(), actual->GetElementType());
    }
    return false;
  }
  if (pattern->get_IsByRef()) {
    if (actual->get_IsByRef()) {
      return SignatureTypeExtensions::MatchesExactly(pattern->get_ElementType(), actual->GetElementType());
    }
    return false;
  }
  if (pattern->get_IsPointer()) {
    if (actual->get_IsPointer()) {
      return SignatureTypeExtensions::MatchesExactly(pattern->get_ElementType(), actual->GetElementType());
    }
    return false;
  }
  if (pattern->get_IsConstructedGenericType()) {
    if (!actual->get_IsConstructedGenericType()) {
      return false;
    }
    if (!(pattern->GetGenericTypeDefinition() == actual->GetGenericTypeDefinition())) {
      return false;
    }
    Array<Type> genericTypeArguments = pattern->get_GenericTypeArguments();
    Array<Type> genericTypeArguments2 = actual->get_GenericTypeArguments();
    Int32 num = genericTypeArguments->get_Length();
    if (num != genericTypeArguments2->get_Length()) {
      return false;
    }
    for (Int32 i = 0; i < num; i++) {
      Type type = genericTypeArguments[i];
      SignatureType signatureType = rt::as<SignatureType>(type);
      if ((Object)signatureType != nullptr) {
        if (!SignatureTypeExtensions::MatchesExactly(signatureType, genericTypeArguments2[i])) {
          return false;
        }
      } else if (type != genericTypeArguments2[i]) {
        return false;
      }

    }
    return true;
  }
  if (pattern->get_IsGenericMethodParameter()) {
    if (!actual->get_IsGenericMethodParameter()) {
      return false;
    }
    if (pattern->get_GenericParameterPosition() != actual->get_GenericParameterPosition()) {
      return false;
    }
    return true;
  }
  return false;
}

Type SignatureTypeExtensions::TryResolveAgainstGenericMethod(SignatureType signatureType, MethodInfo genericMethod) {
  return SignatureTypeExtensions::TryResolve(signatureType, genericMethod->GetGenericArguments());
}

Type SignatureTypeExtensions::TryResolve(SignatureType signatureType, Array<Type> genericMethodParameters) {
  if (signatureType->get_IsSZArray()) {
    Type type = SignatureTypeExtensions::TryResolve(signatureType->get_ElementType(), genericMethodParameters);
    if ((Object)type == nullptr) {
      return nullptr;
    }
    return SignatureTypeExtensions::TryMakeArrayType(type);
  }
  if (signatureType->get_IsVariableBoundArray()) {
    Type type2 = SignatureTypeExtensions::TryResolve(signatureType->get_ElementType(), genericMethodParameters);
    if ((Object)type2 == nullptr) {
      return nullptr;
    }
    return SignatureTypeExtensions::TryMakeArrayType(type2, signatureType->GetArrayRank());
  }
  if (signatureType->get_IsByRef()) {
    Type type3 = SignatureTypeExtensions::TryResolve(signatureType->get_ElementType(), genericMethodParameters);
    if ((Object)type3 == nullptr) {
      return nullptr;
    }
    return SignatureTypeExtensions::TryMakeByRefType(type3);
  }
  if (signatureType->get_IsPointer()) {
    Type type4 = SignatureTypeExtensions::TryResolve(signatureType->get_ElementType(), genericMethodParameters);
    if ((Object)type4 == nullptr) {
      return nullptr;
    }
    return SignatureTypeExtensions::TryMakePointerType(type4);
  }
  if (signatureType->get_IsConstructedGenericType()) {
    Array<Type> genericTypeArguments = signatureType->get_GenericTypeArguments();
    Int32 num = genericTypeArguments->get_Length();
    Array<Type> array = rt::newarr<Array<Type>>(num);
    for (Int32 i = 0; i < num; i++) {
      Type type5 = genericTypeArguments[i];
      SignatureType signatureType2 = rt::as<SignatureType>(type5);
      if ((Object)signatureType2 != nullptr) {
        array[i] = SignatureTypeExtensions::TryResolve(signatureType2, genericMethodParameters);
        if (array[i] == nullptr) {
          return nullptr;
        }
      } else {
        array[i] = type5;
      }
    }
    return SignatureTypeExtensions::TryMakeGenericType(signatureType->GetGenericTypeDefinition(), array);
  }
  if (signatureType->get_IsGenericMethodParameter()) {
    Int32 genericParameterPosition = signatureType->get_GenericParameterPosition();
    if (genericParameterPosition >= genericMethodParameters->get_Length()) {
      return nullptr;
    }
    return genericMethodParameters[genericParameterPosition];
  }
  return nullptr;
}

Type SignatureTypeExtensions::TryMakeArrayType(Type type) {
  try{
    return type->MakeArrayType();
  } catch (...) {
  }
}

Type SignatureTypeExtensions::TryMakeArrayType(Type type, Int32 rank) {
  try{
    return type->MakeArrayType(rank);
  } catch (...) {
  }
}

Type SignatureTypeExtensions::TryMakeByRefType(Type type) {
  try{
    return type->MakeByRefType();
  } catch (...) {
  }
}

Type SignatureTypeExtensions::TryMakePointerType(Type type) {
  try{
    return type->MakePointerType();
  } catch (...) {
  }
}

Type SignatureTypeExtensions::TryMakeGenericType(Type type, Array<Type> instantiation) {
  try{
    return type->MakeGenericType(rt::newarr<Array<Type>>(1, instantiation));
  } catch (...) {
  }
}

} // namespace System::Private::CoreLib::System::Reflection::SignatureTypeExtensionsNamespace
