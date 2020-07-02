#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Exception.h>

namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
namespace ExceptionDispatchInfoNamespace {
CLASS(ExceptionDispatchInfo) {
  public: Exception get_SourceException();
  public: static ExceptionDispatchInfo Capture(Exception source);
  public: void Throw();
  public: static void Throw(Exception source);
  private: Exception _exception;
  private: Exception::in::DispatchState _dispatchState;
};
} // namespace ExceptionDispatchInfoNamespace
using ExceptionDispatchInfo = ExceptionDispatchInfoNamespace::ExceptionDispatchInfo;
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
