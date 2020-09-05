#pragma once

#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Reflection/ExceptionHandlingClause.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class ExceptionHandlingClauseOptions : int32_t;
FORWARD(RuntimeMethodBody)
namespace RuntimeExceptionHandlingClauseNamespace {
CLASS(RuntimeExceptionHandlingClause) : public ExceptionHandlingClause::in {
  public: ExceptionHandlingClauseOptions get_Flags();
  public: Int32 get_TryOffset();
  public: Int32 get_TryLength();
  public: Int32 get_HandlerOffset();
  public: Int32 get_HandlerLength();
  public: Int32 get_FilterOffset();
  public: Type get_CatchType();
  public: void ctor();
  public: String ToString();
  private: RuntimeMethodBody _methodBody;
  private: ExceptionHandlingClauseOptions _flags;
  private: Int32 _tryOffset;
  private: Int32 _tryLength;
  private: Int32 _handlerOffset;
  private: Int32 _handlerLength;
  private: Int32 _catchMetadataToken;
  private: Int32 _filterOffset;
};
} // namespace RuntimeExceptionHandlingClauseNamespace
using RuntimeExceptionHandlingClause = RuntimeExceptionHandlingClauseNamespace::RuntimeExceptionHandlingClause;
} // namespace System::Private::CoreLib::System::Reflection
