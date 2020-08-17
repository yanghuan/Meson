#include "TimerHolder-dep.h"

#include <System.Private.CoreLib/System/GC-dep.h>
#include <System.Private.CoreLib/System/Threading/TimerHolder-dep.h>

namespace System::Private::CoreLib::System::Threading::TimerHolderNamespace {
void TimerHolder___::ctor(TimerQueueTimer timer) {
  _timer = timer;
}

void TimerHolder___::Finalize() {
  _timer->Close();
}

void TimerHolder___::Close() {
  _timer->Close();
  GC::SuppressFinalize((TimerHolder)this);
}

Boolean TimerHolder___::Close(WaitHandle notifyObject) {
  Boolean result = _timer->Close(notifyObject);
  GC::SuppressFinalize((TimerHolder)this);
  return result;
}

ValueTask<> TimerHolder___::CloseAsync() {
  ValueTask<> result = _timer->CloseAsync();
  GC::SuppressFinalize((TimerHolder)this);
  return result;
}

} // namespace System::Private::CoreLib::System::Threading::TimerHolderNamespace
