#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(IDisposable)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
FORWARDS(CancellationToken)
FORWARD(ManualResetEventSlim)
FORWARD(WaitHandle)
} // namespace System::Private::CoreLib::System::Threading
namespace System::Threading::System::Threading {
namespace CountdownEventNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Threading;
CLASS(CountdownEvent) : public Object::in {
  public: using interface = rt::TypeList<IDisposable>;
  public: Int32 get_CurrentCount();
  public: Int32 get_InitialCount();
  public: Boolean get_IsSet();
  public: WaitHandle get_WaitHandle();
  public: void ctor(Int32 initialCount);
  public: void Dispose();
  protected: void Dispose(Boolean disposing);
  public: Boolean Signal();
  public: Boolean Signal(Int32 signalCount);
  public: void AddCount();
  public: Boolean TryAddCount();
  public: void AddCount(Int32 signalCount);
  public: Boolean TryAddCount(Int32 signalCount);
  public: void Reset();
  public: void Reset(Int32 count);
  public: void Wait();
  public: void Wait(CancellationToken cancellationToken);
  public: Boolean Wait(TimeSpan timeout);
  public: Boolean Wait(TimeSpan timeout, CancellationToken cancellationToken);
  public: Boolean Wait(Int32 millisecondsTimeout);
  public: Boolean Wait(Int32 millisecondsTimeout, CancellationToken cancellationToken);
  private: void ThrowIfDisposed();
  private: Int32 _initialCount;
  private: Int32 _currentCount;
  private: ManualResetEventSlim _event;
  private: Boolean _disposed;
};
} // namespace CountdownEventNamespace
using CountdownEvent = CountdownEventNamespace::CountdownEvent;
} // namespace System::Threading::System::Threading
