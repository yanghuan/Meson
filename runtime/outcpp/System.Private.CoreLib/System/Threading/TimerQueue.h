#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/UInt32.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARDS(IntPtr)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(TimerQueueTimer)
namespace TimerQueueNamespace {
CLASS(TimerQueue) {
  private: CLASS(AppDomainTimerSafeHandle) {
    protected: Boolean ReleaseHandle();
  };
  private: static Int64 get_TickCount64();
  private: Boolean SetTimer(UInt32 actualDuration);
  public: static void AppDomainTimerCallback(Int32 id);
  private: static AppDomainTimerSafeHandle CreateAppDomainTimer(UInt32 dueTime, Int32 id);
  private: static Boolean ChangeAppDomainTimer(AppDomainTimerSafeHandle handle, UInt32 dueTime);
  private: static Boolean DeleteAppDomainTimer(IntPtr handle);
  private: static Array<TimerQueue> CreateTimerQueues();
  private: Boolean EnsureTimerFiresBy(UInt32 requestedDuration);
  private: void FireNextTimers();
  public: Boolean UpdateTimer(TimerQueueTimer timer, UInt32 dueTime, UInt32 period);
  public: void MoveTimerToCorrectList(TimerQueueTimer timer, Boolean shortList);
  private: void LinkTimer(TimerQueueTimer timer);
  private: void UnlinkTimer(TimerQueueTimer timer);
  public: void DeleteTimer(TimerQueueTimer timer);
  private: Int32 _id;
  private: AppDomainTimerSafeHandle m_appDomainTimer;
  private: Boolean _isTimerScheduled;
  private: Int64 _currentTimerStartTicks;
  private: UInt32 _currentTimerDuration;
  private: TimerQueueTimer _shortTimers;
  private: TimerQueueTimer _longTimers;
  private: Int64 _currentAbsoluteThreshold;
  private: Int32 _pauseTicks;
};
} // namespace TimerQueueNamespace
using TimerQueue = TimerQueueNamespace::TimerQueue;
} // namespace System::Private::CoreLib::System::Threading