#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Boolean.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD_(Func, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARD(Object)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(SendOrPostCallback)
namespace SynchronizationContextNamespace {
CLASS(SynchronizationContext) {
  public: static SynchronizationContext get_Current();
  private: static Int32 InvokeWaitMethodHelper(SynchronizationContext syncContext, Array<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout);
  private: static SynchronizationContext GetWinRTContext();
  private: static SynchronizationContext GetWinRTSynchronizationContext(Object dispatcher);
  private: static Object GetWinRTDispatcherForCurrentThread();
  protected: void SetWaitNotificationRequired();
  public: Boolean IsWaitNotificationRequired();
  public: void Send(SendOrPostCallback d, Object state);
  public: void Post(SendOrPostCallback d, Object state);
  public: void OperationStarted();
  public: void OperationCompleted();
  public: Int32 Wait(Array<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout);
  protected: static Int32 WaitHelper(Array<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout);
  public: static void SetSynchronizationContext(SynchronizationContext syncContext);
  public: SynchronizationContext CreateCopy();
  private: static Func<Object, SynchronizationContext> s_createSynchronizationContextDelegate;
  private: Boolean _requireWaitNotification;
};
} // namespace SynchronizationContextNamespace
using SynchronizationContext = SynchronizationContextNamespace::SynchronizationContext;
} // namespace System::Private::CoreLib::System::Threading
