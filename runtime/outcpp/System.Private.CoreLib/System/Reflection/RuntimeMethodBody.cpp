#include "RuntimeMethodBody-dep.h"

#include <System.Private.CoreLib/System/Array-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeMethodBodyNamespace {
Int32 RuntimeMethodBody___::get_LocalSignatureMetadataToken() {
  return _localSignatureMetadataToken;
}

IList<LocalVariableInfo> RuntimeMethodBody___::get_LocalVariables() {
  return Array<>::in::AsReadOnly(_localVariables);
}

Int32 RuntimeMethodBody___::get_MaxStackSize() {
  return _maxStackSize;
}

Boolean RuntimeMethodBody___::get_InitLocals() {
  return _initLocals;
}

IList<ExceptionHandlingClause> RuntimeMethodBody___::get_ExceptionHandlingClauses() {
  return Array<>::in::AsReadOnly(_exceptionHandlingClauses);
}

void RuntimeMethodBody___::ctor() {
}

Array<Byte> RuntimeMethodBody___::GetILAsByteArray() {
  return _IL;
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeMethodBodyNamespace
