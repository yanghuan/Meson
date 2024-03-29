#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARD(TimerQueueTimer)
FORWARD(WaitHandle)
namespace TimerHolderNamespace {
using namespace System::Threading::Tasks;
CLASS(TimerHolder) : public object {
  public: void ctor(TimerQueueTimer timer);
  protected: void Finalize();
  public: void Close();
  public: Boolean Close(WaitHandle notifyObject);
  public: ValueTask<> CloseAsync();
  public: TimerQueueTimer _timer;
};
} // namespace TimerHolderNamespace
using TimerHolder = TimerHolderNamespace::TimerHolder;
} // namespace System::Private::CoreLib::System::Threading
