#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(Boolean)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(SignatureType)
namespace SignatureGenericParameterTypeNamespace {
CLASS(SignatureGenericParameterType) {
  public: Boolean get_IsTypeDefinition();
  public: Boolean get_IsGenericTypeDefinition();
  public: Boolean get_IsByRefLike();
  public: Boolean get_IsSZArray();
  public: Boolean get_IsVariableBoundArray();
  public: Boolean get_IsConstructedGenericType();
  public: Boolean get_IsGenericParameter();
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
  private: Int32 _position;
};
} // namespace SignatureGenericParameterTypeNamespace
using SignatureGenericParameterType = SignatureGenericParameterTypeNamespace::SignatureGenericParameterType;
} // namespace System::Private::CoreLib::System::Reflection
