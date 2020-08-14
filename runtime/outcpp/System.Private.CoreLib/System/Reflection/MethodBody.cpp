#include "MethodBody-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Reflection::MethodBodyNamespace {
Int32 MethodBody___::get_LocalSignatureMetadataToken() {
  return 0;
}

IList<LocalVariableInfo> MethodBody___::get_LocalVariables() {
  rt::throw_exception<ArgumentNullException>("array");
}

Int32 MethodBody___::get_MaxStackSize() {
  return 0;
}

Boolean MethodBody___::get_InitLocals() {
  return false;
}

IList<ExceptionHandlingClause> MethodBody___::get_ExceptionHandlingClauses() {
  rt::throw_exception<ArgumentNullException>("array");
}

void MethodBody___::ctor() {
}

Array<Byte> MethodBody___::GetILAsByteArray() {
  return nullptr;
}

} // namespace System::Private::CoreLib::System::Reflection::MethodBodyNamespace
