#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading::Tasks {
FORWARDS_(ValueTask, T1, T2)
} // namespace System::Private::CoreLib::System::Threading::Tasks
namespace System::Private::CoreLib::System::Threading {
FORWARD(TimerQueueTimer)
FORWARD(WaitHandle)
namespace TimerHolderNamespace {
using namespace Tasks;
CLASS(TimerHolder) : public Object::in {
  public: void Ctor(TimerQueueTimer timer);
  protected: void Finalize();
  public: void Close();
  public: Boolean Close(WaitHandle notifyObject);
  public: ValueTask<> CloseAsync();
  public: TimerQueueTimer _timer;
};
} // namespace TimerHolderNamespace
using TimerHolder = TimerHolderNamespace::TimerHolder;
} // namespace System::Private::CoreLib::System::Threading
