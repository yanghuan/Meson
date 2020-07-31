#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(MethodInfo)
FORWARD(ParameterInfo)
FORWARD(SignatureType)
namespace SignatureTypeExtensionsNamespace {
class SignatureTypeExtensions : public Object::in {
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
