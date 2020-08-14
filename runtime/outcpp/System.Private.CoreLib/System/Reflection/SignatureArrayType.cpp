#include "SignatureArrayType-dep.h"

namespace System::Private::CoreLib::System::Reflection::SignatureArrayTypeNamespace {
Boolean SignatureArrayType___::get_IsSZArray() {
  return !_isMultiDim;
}

Boolean SignatureArrayType___::get_IsVariableBoundArray() {
  return _isMultiDim;
}

String SignatureArrayType___::get_Suffix() {
  if (!_isMultiDim) {
    return "[]";
  }
  if (_rank == 1) {
    return "[*]";
  }
  return "[" + rt::newobj<String>(44, _rank - 1) + "]";
}

void SignatureArrayType___::ctor(SignatureType elementType, Int32 rank, Boolean isMultiDim) {
  _rank = rank;
  _isMultiDim = isMultiDim;
}

Boolean SignatureArrayType___::IsArrayImpl() {
  return true;
}

Boolean SignatureArrayType___::IsByRefImpl() {
  return false;
}

Boolean SignatureArrayType___::IsPointerImpl() {
  return false;
}

Int32 SignatureArrayType___::GetArrayRank() {
  return _rank;
}

} // namespace System::Private::CoreLib::System::Reflection::SignatureArrayTypeNamespace
