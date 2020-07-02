#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(Delegate)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Globalization {
FORWARD(CultureInfo)
} // namespace System::Private::CoreLib::System::Globalization
namespace System::Private::CoreLib::System::Threading {
FORWARD(ExecutionContext)
FORWARD_(ContextCallback, T1, T2)
namespace ThreadHelperNamespace {
using namespace ::System::Private::CoreLib::System::Globalization;
CLASS(ThreadHelper) {
  public: void SetExecutionContextHelper(ExecutionContext ec);
  private: static void ThreadStart_Context(Object state);
  private: void InitializeCulture();
  public: void ThreadStart(Object obj);
  public: void ThreadStart();
  private: Delegate _start;
  public: CultureInfo _startCulture;
  public: CultureInfo _startUICulture;
  private: Object _startArg;
  private: ExecutionContext _executionContext;
  public: static ContextCallback<> s_threadStartContextCallback;
};
} // namespace ThreadHelperNamespace
using ThreadHelper = ThreadHelperNamespace::ThreadHelper;
} // namespace System::Private::CoreLib::System::Threading
