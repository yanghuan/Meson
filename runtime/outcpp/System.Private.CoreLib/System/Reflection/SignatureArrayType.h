#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(SignatureType)
namespace SignatureArrayTypeNamespace {
CLASS(SignatureArrayType) {
  public: Boolean get_IsSZArray();
  public: Boolean get_IsVariableBoundArray();
  protected: String get_Suffix();
  public: void Ctor(SignatureType elementType, Int32 rank, Boolean isMultiDim);
  protected: Boolean IsArrayImpl();
  protected: Boolean IsByRefImpl();
  protected: Boolean IsPointerImpl();
  public: Int32 GetArrayRank();
  private: Int32 _rank;
  private: Boolean _isMultiDim;
};
} // namespace SignatureArrayTypeNamespace
using SignatureArrayType = SignatureArrayTypeNamespace::SignatureArrayType;
} // namespace System::Private::CoreLib::System::Reflection
