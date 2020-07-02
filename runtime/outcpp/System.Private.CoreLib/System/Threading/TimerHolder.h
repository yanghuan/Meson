#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARD(WaitHandle)
FORWARD(TimerQueueTimer)
namespace TimerHolderNamespace {
using namespace ::System::Private::CoreLib::System::Threading::Tasks;
CLASS(TimerHolder) {
  protected: void Finalize();
  public: void Close();
  public: Boolean Close(WaitHandle notifyObject);
  public: ValueTask<> CloseAsync();
  public: TimerQueueTimer _timer;
};
} // namespace TimerHolderNamespace
using TimerHolder = TimerHolderNamespace::TimerHolder;
} // namespace System::Private::CoreLib::System::Threading
