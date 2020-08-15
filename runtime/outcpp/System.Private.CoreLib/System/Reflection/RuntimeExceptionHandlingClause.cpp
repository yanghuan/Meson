#include "RuntimeExceptionHandlingClause-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/Reflection/MetadataToken-dep.h>
#include <System.Private.CoreLib/System/Reflection/MethodInfo-dep.h>
#include <System.Private.CoreLib/System/Reflection/Module-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::RuntimeExceptionHandlingClauseNamespace {
using namespace System::Globalization;

ExceptionHandlingClauseOptions RuntimeExceptionHandlingClause___::get_Flags() {
  return _flags;
}

Int32 RuntimeExceptionHandlingClause___::get_TryOffset() {
  return _tryOffset;
}

Int32 RuntimeExceptionHandlingClause___::get_TryLength() {
  return _tryLength;
}

Int32 RuntimeExceptionHandlingClause___::get_HandlerOffset() {
  return _handlerOffset;
}

Int32 RuntimeExceptionHandlingClause___::get_HandlerLength() {
  return _handlerLength;
}

Int32 RuntimeExceptionHandlingClause___::get_FilterOffset() {
  if (_flags != ExceptionHandlingClauseOptions::Filter) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_EHClauseNotFilter());
  }
  return _filterOffset;
}

Type RuntimeExceptionHandlingClause___::get_CatchType() {
  if (_flags != 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_Arg_EHClauseNotClause());
  }
  Type result = nullptr;
  if (!MetadataToken::IsNullToken(_catchMetadataToken)) {
    Type declaringType = _methodBody->_methodBase->get_DeclaringType();
    Module module = (declaringType == nullptr) ? _methodBody->_methodBase->get_Module() : declaringType->get_Module();
    auto& default = declaringType;
    result = module->ResolveType(_catchMetadataToken, default == nullptr ? nullptr : default->GetGenericArguments(), rt::is<MethodInfo>(_methodBody->_methodBase) ? _methodBody->_methodBase->GetGenericArguments() : nullptr);
  }
  return result;
}

void RuntimeExceptionHandlingClause___::ctor() {
}

String RuntimeExceptionHandlingClause___::ToString() {
  if (get_Flags() == ExceptionHandlingClauseOptions::Clause) {
    return String::in::Format(CultureInfo::in::get_CurrentUICulture(), "Flags={0}, TryOffset={1}, TryLength={2}, HandlerOffset={3}, HandlerLength={4}, CatchType={5}", rt::newarr<Array<Object>>(6, get_Flags(), get_TryOffset(), get_TryLength(), get_HandlerOffset(), get_HandlerLength(), get_CatchType()));
  }
  if (get_Flags() == ExceptionHandlingClauseOptions::Filter) {
    return String::in::Format(CultureInfo::in::get_CurrentUICulture(), "Flags={0}, TryOffset={1}, TryLength={2}, HandlerOffset={3}, HandlerLength={4}, FilterOffset={5}", rt::newarr<Array<Object>>(6, get_Flags(), get_TryOffset(), get_TryLength(), get_HandlerOffset(), get_HandlerLength(), get_FilterOffset()));
  }
  return String::in::Format(CultureInfo::in::get_CurrentUICulture(), "Flags={0}, TryOffset={1}, TryLength={2}, HandlerOffset={3}, HandlerLength={4}", rt::newarr<Array<Object>>(5, get_Flags(), get_TryOffset(), get_TryLength(), get_HandlerOffset(), get_HandlerLength()));
}

} // namespace System::Private::CoreLib::System::Reflection::RuntimeExceptionHandlingClauseNamespace
