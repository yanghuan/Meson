#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Action)
FORWARD_(Array)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARDS_(ValueTuple)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARD(SendOrPostCallback)
namespace SynchronizationContextNamespace {
CLASS(SynchronizationContext) : public object {
  private: CLASS(__c) : public object {
    public: static void cctor();
    public: void ctor();
    public: void _Post_b__8_0(ValueTuple<SendOrPostCallback, Object> s);
    public: static __c __9;
    public: static Action<ValueTuple<SendOrPostCallback, Object>> __9__8_0;
  };
  public: static SynchronizationContext get_Current();
  private: static Int32 InvokeWaitMethodHelper(SynchronizationContext syncContext, Array<IntPtr> waitHandles, Boolean waitAll, Int32 millisecondsTimeout);
  public: void ctor();
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
  private: Boolean _requireWaitNotification;
};
} // namespace SynchronizationContextNamespace
using SynchronizationContext = SynchronizationContextNamespace::SynchronizationContext;
} // namespace System::Private::CoreLib::System::Threading
