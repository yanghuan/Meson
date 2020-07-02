#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARD(String)
FORWARD(Type)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class ExceptionHandlingClauseOptions;
namespace ExceptionHandlingClauseNamespace {
CLASS(ExceptionHandlingClause) {
  public: ExceptionHandlingClauseOptions get_Flags();
  public: Int32 get_TryOffset();
  public: Int32 get_TryLength();
  public: Int32 get_HandlerOffset();
  public: Int32 get_HandlerLength();
  public: Int32 get_FilterOffset();
  public: Type get_CatchType();
  public: String ToString();
};
} // namespace ExceptionHandlingClauseNamespace
using ExceptionHandlingClause = ExceptionHandlingClauseNamespace::ExceptionHandlingClause;
} // namespace System::Private::CoreLib::System::Reflection
