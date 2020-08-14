#include "SignatureByRefType-dep.h"

#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::SignatureByRefTypeNamespace {
Boolean SignatureByRefType___::get_IsSZArray() {
  return false;
}

Boolean SignatureByRefType___::get_IsVariableBoundArray() {
  return false;
}

String SignatureByRefType___::get_Suffix() {
  return "&";
}

void SignatureByRefType___::ctor(SignatureType elementType) {
}

Boolean SignatureByRefType___::IsArrayImpl() {
  return false;
}

Boolean SignatureByRefType___::IsByRefImpl() {
  return true;
}

Boolean SignatureByRefType___::IsPointerImpl() {
  return false;
}

Int32 SignatureByRefType___::GetArrayRank() {
  rt::throw_exception<ArgumentException>(SR::get_Argument_HasToBeArrayClass());
}

} // namespace System::Private::CoreLib::System::Reflection::SignatureByRefTypeNamespace
