#include "ExceptionHandler-dep.h"

#include <System.Private.CoreLib/System/Reflection/Emit/ExceptionHandler-dep.h>
#include <System.Private.CoreLib/System/Reflection/ExceptionHandlingClauseOptions.h>

namespace System::Private::CoreLib::System::Reflection::Emit::ExceptionHandlerNamespace {
ExceptionHandler::ExceptionHandler(Int32 tryStartOffset, Int32 tryEndOffset, Int32 filterOffset, Int32 handlerStartOffset, Int32 handlerEndOffset, Int32 kind, Int32 exceptionTypeToken) {
  m_tryStartOffset = tryStartOffset;
  m_tryEndOffset = tryEndOffset;
  m_filterOffset = filterOffset;
  m_handlerStartOffset = handlerStartOffset;
  m_handlerEndOffset = handlerEndOffset;
  m_kind = (ExceptionHandlingClauseOptions)kind;
  m_exceptionClass = exceptionTypeToken;
}

Int32 ExceptionHandler::GetHashCode() {
  return m_exceptionClass ^ m_tryStartOffset ^ m_tryEndOffset ^ m_filterOffset ^ m_handlerStartOffset ^ m_handlerEndOffset ^ (Int32)m_kind;
}

Boolean ExceptionHandler::Equals(Object obj) {
  if (rt::is<ExceptionHandler>(obj)) {
    return Equals((ExceptionHandler)obj);
  }
  return false;
}

Boolean ExceptionHandler::Equals(ExceptionHandler other) {
  if (other.m_exceptionClass == m_exceptionClass && other.m_tryStartOffset == m_tryStartOffset && other.m_tryEndOffset == m_tryEndOffset && other.m_filterOffset == m_filterOffset && other.m_handlerStartOffset == m_handlerStartOffset && other.m_handlerEndOffset == m_handlerEndOffset) {
    return other.m_kind == m_kind;
  }
  return false;
}

} // namespace System::Private::CoreLib::System::Reflection::Emit::ExceptionHandlerNamespace
