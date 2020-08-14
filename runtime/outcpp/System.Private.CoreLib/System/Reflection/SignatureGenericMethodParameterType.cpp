#include "SignatureGenericMethodParameterType-dep.h"

namespace System::Private::CoreLib::System::Reflection::SignatureGenericMethodParameterTypeNamespace {
Boolean SignatureGenericMethodParameterType___::get_IsGenericTypeParameter() {
  return false;
}

Boolean SignatureGenericMethodParameterType___::get_IsGenericMethodParameter() {
  return true;
}

String SignatureGenericMethodParameterType___::get_Name() {
  return "!!" + get_GenericParameterPosition();
}

void SignatureGenericMethodParameterType___::ctor(Int32 position) {
}

} // namespace System::Private::CoreLib::System::Reflection::SignatureGenericMethodParameterTypeNamespace
