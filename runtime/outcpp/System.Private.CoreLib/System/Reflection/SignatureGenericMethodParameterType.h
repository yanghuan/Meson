#pragma once

#include <System.Private.CoreLib/System/Reflection/SignatureGenericParameterType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace SignatureGenericMethodParameterTypeNamespace {
CLASS(SignatureGenericMethodParameterType) : public SignatureGenericParameterType::in {
  public: Boolean get_IsGenericTypeParameter();
  public: Boolean get_IsGenericMethodParameter();
  public: String get_Name();
  public: void Ctor(Int32 position);
};
} // namespace SignatureGenericMethodParameterTypeNamespace
using SignatureGenericMethodParameterType = SignatureGenericMethodParameterTypeNamespace::SignatureGenericMethodParameterType;
} // namespace System::Private::CoreLib::System::Reflection
