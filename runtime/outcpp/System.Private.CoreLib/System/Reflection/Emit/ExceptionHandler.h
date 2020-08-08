#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(IEquatable, T)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class ExceptionHandlingClauseOptions;
} // namespace System::Private::CoreLib::System::Reflection
namespace System::Private::CoreLib::System::Reflection::Emit {
namespace ExceptionHandlerNamespace {
struct ExceptionHandler : public valueType<ExceptionHandler> {
  using interface = rt::TypeList<IEquatable<ExceptionHandler>>;
  public: explicit ExceptionHandler(Int32 tryStartOffset, Int32 tryEndOffset, Int32 filterOffset, Int32 handlerStartOffset, Int32 handlerEndOffset, Int32 kind, Int32 exceptionTypeToken);
  public: Int32 GetHashCode();
  public: Boolean Equals(Object obj);
  public: Boolean Equals(ExceptionHandler other);
  public: explicit ExceptionHandler() {}
  public: Int32 m_exceptionClass;
  public: Int32 m_tryStartOffset;
  public: Int32 m_tryEndOffset;
  public: Int32 m_filterOffset;
  public: Int32 m_handlerStartOffset;
  public: Int32 m_handlerEndOffset;
  public: ExceptionHandlingClauseOptions m_kind;
};
} // namespace ExceptionHandlerNamespace
using ExceptionHandler = ExceptionHandlerNamespace::ExceptionHandler;
} // namespace System::Private::CoreLib::System::Reflection::Emit
