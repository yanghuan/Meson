#pragma once

#include <System.Private.CoreLib/System/Reflection/SignatureHasElementType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(SignatureType)
namespace SignatureByRefTypeNamespace {
CLASS(SignatureByRefType) : public SignatureHasElementType::in {
  public: Boolean get_IsSZArray();
  public: Boolean get_IsVariableBoundArray();
  protected: String get_Suffix();
  public: void ctor(SignatureType elementType);
  protected: Boolean IsArrayImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPointerImpl();
  public: Int32 GetArrayRank();
};
} // namespace SignatureByRefTypeNamespace
using SignatureByRefType = SignatureByRefTypeNamespace::SignatureByRefType;
} // namespace System::Private::CoreLib::System::Reflection
