#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD_(Array, T1, T2)
FORWARD(Type)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(SignatureType)
namespace SignatureConstructedGenericTypeNamespace {
CLASS(SignatureConstructedGenericType) {
  public: Boolean get_IsTypeDefinition();
  public: Boolean get_IsGenericTypeDefinition();
  public: Boolean get_IsByRefLike();
  public: Boolean get_IsSZArray();
  public: Boolean get_IsVariableBoundArray();
  public: Boolean get_IsConstructedGenericType();
  public: Boolean get_IsGenericParameter();
  public: Boolean get_IsGenericTypeParameter();
  public: Boolean get_IsGenericMethodParameter();
  public: Boolean get_ContainsGenericParameters();
  public: SignatureType get_ElementType();
  public: Array<Type> get_GenericTypeArguments();
  public: Int32 get_GenericParameterPosition();
  public: String get_Name();
  public: String get_Namespace();
  protected: Boolean HasElementTypeImpl();
  protected: Boolean IsArrayImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPointerImpl();
  public: Int32 GetArrayRank();
  public: Type GetGenericTypeDefinition();
  public: Array<Type> GetGenericArguments();
  public: String ToString();
  private: Type _genericTypeDefinition;
  private: Array<Type> _genericTypeArguments;
};
} // namespace SignatureConstructedGenericTypeNamespace
using SignatureConstructedGenericType = SignatureConstructedGenericTypeNamespace::SignatureConstructedGenericType;
} // namespace System::Private::CoreLib::System::Reflection
