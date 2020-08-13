#include "LazyHelper-dep.h"

#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/LazyHelper-dep.h>
#include <System.Private.CoreLib/System/Runtime/ExceptionServices/ExceptionDispatchInfo-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::LazyHelperNamespace {
using namespace System::Runtime::ExceptionServices;

void LazyHelper___::ctor(LazyState state) {
  State = state;
}

void LazyHelper___::ctor(LazyThreadSafetyMode mode, Exception exception) {
  switch (mode) {
    case LazyThreadSafetyMode::ExecutionAndPublication:
      State = LazyState::ExecutionAndPublicationException;
      break;
    case LazyThreadSafetyMode::None:
      State = LazyState::NoneException;
      break;
    case LazyThreadSafetyMode::PublicationOnly:
      State = LazyState::PublicationOnlyException;
      break;
  }
  _exceptionDispatch = ExceptionDispatchInfo::in::Capture(exception);
}

void LazyHelper___::ThrowException() {
  _exceptionDispatch->Throw();
}

LazyThreadSafetyMode LazyHelper___::GetMode() {
  switch (State) {
    case LazyState::NoneViaConstructor:
    case LazyState::NoneViaFactory:
    case LazyState::NoneException:
      return LazyThreadSafetyMode::None;
    case LazyState::PublicationOnlyViaConstructor:
    case LazyState::PublicationOnlyViaFactory:
    case LazyState::PublicationOnlyWait:
    case LazyState::PublicationOnlyException:
      return LazyThreadSafetyMode::PublicationOnly;
    case LazyState::ExecutionAndPublicationViaConstructor:
    case LazyState::ExecutionAndPublicationViaFactory:
    case LazyState::ExecutionAndPublicationException:
      return LazyThreadSafetyMode::ExecutionAndPublication;
    default:
      return LazyThreadSafetyMode::None;
  }
}

Nullable<LazyThreadSafetyMode> LazyHelper___::GetMode(LazyHelper state) {
}

Boolean LazyHelper___::GetIsValueFaulted(LazyHelper state) {
}

LazyHelper LazyHelper___::Create(LazyThreadSafetyMode mode, Boolean useDefaultConstructor) {
  switch (mode) {
    case LazyThreadSafetyMode::None:
      if (!useDefaultConstructor) {
        return NoneViaFactory;
      }
      return NoneViaConstructor;
    case LazyThreadSafetyMode::PublicationOnly:
      if (!useDefaultConstructor) {
        return PublicationOnlyViaFactory;
      }
      return PublicationOnlyViaConstructor;
    case LazyThreadSafetyMode::ExecutionAndPublication:
      {
        LazyState state = useDefaultConstructor ? LazyState::ExecutionAndPublicationViaConstructor : LazyState::ExecutionAndPublicationViaFactory;
        return rt::newobj<LazyHelper>(state);
      }default:
      rt::throw_exception<ArgumentOutOfRangeException>("mode", SR::get_Lazy_ctor_ModeInvalid());
  }
}

LazyThreadSafetyMode LazyHelper___::GetModeFromIsThreadSafe(Boolean isThreadSafe) {
  if (!isThreadSafe) {
    return LazyThreadSafetyMode::None;
  }
  return LazyThreadSafetyMode::ExecutionAndPublication;
}

void LazyHelper___::cctor() {
  NoneViaConstructor = rt::newobj<LazyHelper>(LazyState::NoneViaConstructor);
  NoneViaFactory = rt::newobj<LazyHelper>(LazyState::NoneViaFactory);
  PublicationOnlyViaConstructor = rt::newobj<LazyHelper>(LazyState::PublicationOnlyViaConstructor);
  PublicationOnlyViaFactory = rt::newobj<LazyHelper>(LazyState::PublicationOnlyViaFactory);
  PublicationOnlyWaitForOtherThreadToPublish = rt::newobj<LazyHelper>(LazyState::PublicationOnlyWait);
}

} // namespace System::Private::CoreLib::System::LazyHelperNamespace
