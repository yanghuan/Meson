#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace SignatureGenericMethodParameterTypeNamespace {
CLASS(SignatureGenericMethodParameterType) {
  public: Boolean get_IsGenericTypeParameter();
  public: Boolean get_IsGenericMethodParameter();
  public: String get_Name();
};
} // namespace SignatureGenericMethodParameterTypeNamespace
using SignatureGenericMethodParameterType = SignatureGenericMethodParameterTypeNamespace::SignatureGenericMethodParameterType;
} // namespace System::Private::CoreLib::System::Reflection
