#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System::Threading {
enum class LazyThreadSafetyMode : int32_t;
} // namespace System::Private::CoreLib::System::Threading
namespace System::Private::CoreLib::System::Runtime::ExceptionServices {
FORWARD(ExceptionDispatchInfo)
} // namespace System::Private::CoreLib::System::Runtime::ExceptionServices
namespace System::Private::CoreLib::System {
enum class LazyState : int32_t;
FORWARDS(Boolean)
FORWARD(Exception)
FORWARDS_(Nullable, T1, T2)
namespace LazyHelperNamespace {
using namespace System::Runtime::ExceptionServices;
using namespace System::Threading;
CLASS(LazyHelper) : public Object::in {
  public: LazyState get_State() { return State; }
  public: void ctor(LazyState state);
  public: void ctor(LazyThreadSafetyMode mode, Exception exception);
  public: void ThrowException();
  private: LazyThreadSafetyMode GetMode();
  public: static Nullable<LazyThreadSafetyMode> GetMode(LazyHelper state);
  public: static Boolean GetIsValueFaulted(LazyHelper state);
  public: static LazyHelper Create(LazyThreadSafetyMode mode, Boolean useDefaultConstructor);
  public: template <class T>
  static T CreateViaDefaultConstructor();
  public: static LazyThreadSafetyMode GetModeFromIsThreadSafe(Boolean isThreadSafe);
  private: static void ctor_static();
  public: static LazyHelper NoneViaConstructor;
  public: static LazyHelper NoneViaFactory;
  public: static LazyHelper PublicationOnlyViaConstructor;
  public: static LazyHelper PublicationOnlyViaFactory;
  public: static LazyHelper PublicationOnlyWaitForOtherThreadToPublish;
  private: LazyState State;
  private: ExceptionDispatchInfo _exceptionDispatch;
};
} // namespace LazyHelperNamespace
using LazyHelper = LazyHelperNamespace::LazyHelper;
} // namespace System::Private::CoreLib::System
