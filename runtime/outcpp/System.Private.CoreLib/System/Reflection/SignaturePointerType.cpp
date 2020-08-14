#include "SignaturePointerType-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::SignaturePointerTypeNamespace {
Boolean SignaturePointerType___::get_IsSZArray() {
  return false;
}

Boolean SignaturePointerType___::get_IsVariableBoundArray() {
  return false;
}

String SignaturePointerType___::get_Suffix() {
  return "*";
}

void SignaturePointerType___::ctor(SignatureType elementType) {
}

Boolean SignaturePointerType___::IsArrayImpl() {
  return false;
}

Boolean SignaturePointerType___::IsByRefImpl() {
  return false;
}

Boolean SignaturePointerType___::IsPointerImpl() {
  return true;
}

Int32 SignaturePointerType___::GetArrayRank() {
  rt::throw_exception<ArgumentException>(SR::get_Argument_HasToBeArrayClass());
}

} // namespace System::Private::CoreLib::System::Reflection::SignaturePointerTypeNamespace
