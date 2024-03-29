#pragma once

#include <System.Private.CoreLib/System/Reflection/SignatureType.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace SignatureConstructedGenericTypeNamespace {
CLASS(SignatureConstructedGenericType) : public SignatureType::in {
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
  public: void ctor(Type genericTypeDefinition, Array<Type> typeArguments);
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
