#pragma once

#include <System.Private.CoreLib/System/Exception.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
namespace ExceptionDispatchInfoNamespace {
CLASS(ExceptionDispatchInfo) : public Object::in {
  public: Exception get_SourceException();
  private: void ctor(Exception exception);
  public: static ExceptionDispatchInfo Capture(Exception source);
  public: void Throw();
  public: static void Throw(Exception source);
  public: static Exception SetCurrentStackTrace(Exception source);
  private: Exception _exception;
  private: Exception::in::DispatchState _dispatchState;
};
} // namespace ExceptionDispatchInfoNamespace
using ExceptionDispatchInfo = ExceptionDispatchInfoNamespace::ExceptionDispatchInfo;
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
