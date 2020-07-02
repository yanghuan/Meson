#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
namespace SignaturePointerTypeNamespace {
CLASS(SignaturePointerType) {
  public: Boolean get_IsSZArray();
  public: Boolean get_IsVariableBoundArray();
  protected: String get_Suffix();
  protected: Boolean IsArrayImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPointerImpl();
  public: Int32 GetArrayRank();
};
} // namespace SignaturePointerTypeNamespace
using SignaturePointerType = SignaturePointerTypeNamespace::SignaturePointerType;
} // namespace System::Private::CoreLib::System::Reflection
