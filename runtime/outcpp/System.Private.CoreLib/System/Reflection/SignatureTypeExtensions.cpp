#include "SignatureTypeExtensions-dep.h"

namespace System::Private::CoreLib::System::Reflection::SignatureTypeExtensionsNamespace {
Boolean SignatureTypeExtensions::MatchesParameterTypeExactly(Type pattern, ParameterInfo parameter) {
  return Boolean();
};

Boolean SignatureTypeExtensions::MatchesExactly(SignatureType pattern, Type actual) {
  return Boolean();
};

Type SignatureTypeExtensions::TryResolveAgainstGenericMethod(SignatureType signatureType, MethodInfo genericMethod) {
  return nullptr;
};

Type SignatureTypeExtensions::TryResolve(SignatureType signatureType, Array<Type> genericMethodParameters) {
  return nullptr;
};

Type SignatureTypeExtensions::TryMakeArrayType(Type type) {
  return nullptr;
};

Type SignatureTypeExtensions::TryMakeArrayType(Type type, Int32 rank) {
  return nullptr;
};

Type SignatureTypeExtensions::TryMakeByRefType(Type type) {
  return nullptr;
};

Type SignatureTypeExtensions::TryMakePointerType(Type type) {
  return nullptr;
};

Type SignatureTypeExtensions::TryMakeGenericType(Type type, Array<Type> instantiation) {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::Reflection::SignatureTypeExtensionsNamespace
