#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Type)
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(ParameterInfo)
FORWARD(SignatureType)
FORWARD(MethodInfo)
namespace SignatureTypeExtensionsNamespace {
class SignatureTypeExtensions {
  public: static Boolean MatchesParameterTypeExactly(Type pattern, ParameterInfo parameter);
  public: static Boolean MatchesExactly(SignatureType pattern, Type actual);
  public: static Type TryResolveAgainstGenericMethod(SignatureType signatureType, MethodInfo genericMethod);
  private: static Type TryResolve(SignatureType signatureType, Array<Type> genericMethodParameters);
  private: static Type TryMakeArrayType(Type type);
  private: static Type TryMakeArrayType(Type type, Int32 rank);
  private: static Type TryMakeByRefType(Type type);
  private: static Type TryMakePointerType(Type type);
  private: static Type TryMakeGenericType(Type type, Array<Type> instantiation);
};
} // namespace SignatureTypeExtensionsNamespace
using SignatureTypeExtensions = SignatureTypeExtensionsNamespace::SignatureTypeExtensions;
} // namespace System::Private::CoreLib::System::Reflection
