#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Threading {
enum class LazyThreadSafetyMode;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
FORWARD(ExceptionDispatchInfo)
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
namespace System::Private::CoreLib::System {
FORWARDS_(Nullable, T1, T2)
FORWARDS(Boolean)
namespace LazyHelperNamespace {
using namespace ::System::Private::CoreLib::System::Runtime::ExceptionServices;
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(LazyHelper) {
  public: void ThrowException();
  private: LazyThreadSafetyMode GetMode();
  public: static Nullable<LazyThreadSafetyMode> GetMode(LazyHelper state);
  public: static Boolean GetIsValueFaulted(LazyHelper state);
  public: static LazyHelper Create(LazyThreadSafetyMode mode, Boolean useDefaultConstructor);
  public: static LazyThreadSafetyMode GetModeFromIsThreadSafe(Boolean isThreadSafe);
  public: static LazyHelper NoneViaConstructor;
  public: static LazyHelper NoneViaFactory;
  public: static LazyHelper PublicationOnlyViaConstructor;
  public: static LazyHelper PublicationOnlyViaFactory;
  public: static LazyHelper PublicationOnlyWaitForOtherThreadToPublish;
  private: ExceptionDispatchInfo _exceptionDispatch;
};
} // namespace LazyHelperNamespace
using LazyHelper = LazyHelperNamespace::LazyHelper;
} // namespace System::Private::CoreLib::System
