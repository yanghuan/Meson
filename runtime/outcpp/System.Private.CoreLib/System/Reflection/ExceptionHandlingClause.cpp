#include "ExceptionHandlingClause-dep.h"

#include <System.Private.CoreLib/System/Globalization/CultureInfo-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::Reflection::ExceptionHandlingClauseNamespace {
using namespace System::Globalization;

ExceptionHandlingClauseOptions ExceptionHandlingClause___::get_Flags() {
  return ExceptionHandlingClauseOptions::Clause;
}

Int32 ExceptionHandlingClause___::get_TryOffset() {
  return 0;
}

Int32 ExceptionHandlingClause___::get_TryLength() {
  return 0;
}

Int32 ExceptionHandlingClause___::get_HandlerOffset() {
  return 0;
}

Int32 ExceptionHandlingClause___::get_HandlerLength() {
  return 0;
}

Int32 ExceptionHandlingClause___::get_FilterOffset() {
  rt::throw_exception<InvalidOperationException>(SR::get_Arg_EHClauseNotFilter());
}

Type ExceptionHandlingClause___::get_CatchType() {
  return nullptr;
}

void ExceptionHandlingClause___::ctor() {
}

String ExceptionHandlingClause___::ToString() {
  return String::in::Format(CultureInfo::in::get_CurrentUICulture(), "Flags={0}, TryOffset={1}, TryLength={2}, HandlerOffset={3}, HandlerLength={4}, CatchType={5}", rt::newarr<Array<Object>>(6, get_Flags(), get_TryOffset(), get_TryLength(), get_HandlerOffset(), get_HandlerLength(), get_CatchType()));
}

} // namespace System::Private::CoreLib::System::Reflection::ExceptionHandlingClauseNamespace
