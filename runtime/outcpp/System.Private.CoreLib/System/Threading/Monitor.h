#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(TimeSpan)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace MonitorNamespace {
class Monitor : public Object::in {
  public: static Int64 get_LockContentionCount();
  public: static void Enter(Object obj);
  public: static void Enter(Object obj, Boolean& lockTaken);
  private: static void ThrowLockTakenException();
  private: static void ReliableEnter(Object obj, Boolean& lockTaken);
  public: static void Exit(Object obj);
  public: static Boolean TryEnter(Object obj);
  public: static void TryEnter(Object obj, Boolean& lockTaken);
  public: static Boolean TryEnter(Object obj, Int32 millisecondsTimeout);
  private: static Int32 MillisecondsTimeoutFromTimeSpan(TimeSpan timeout);
  public: static Boolean TryEnter(Object obj, TimeSpan timeout);
  public: static void TryEnter(Object obj, Int32 millisecondsTimeout, Boolean& lockTaken);
  public: static void TryEnter(Object obj, TimeSpan timeout, Boolean& lockTaken);
  private: static void ReliableEnterTimeout(Object obj, Int32 timeout, Boolean& lockTaken);
  public: static Boolean IsEntered(Object obj);
  private: static Boolean IsEnteredNative(Object obj);
  private: static Boolean ObjWait(Boolean exitContext, Int32 millisecondsTimeout, Object obj);
  public: static Boolean Wait(Object obj, Int32 millisecondsTimeout, Boolean exitContext);
  public: static Boolean Wait(Object obj, TimeSpan timeout, Boolean exitContext);
  public: static Boolean Wait(Object obj, Int32 millisecondsTimeout);
  public: static Boolean Wait(Object obj, TimeSpan timeout);
  public: static Boolean Wait(Object obj);
  private: static void ObjPulse(Object obj);
  public: static void Pulse(Object obj);
  private: static void ObjPulseAll(Object obj);
  public: static void PulseAll(Object obj);
  private: static Int64 GetLockContentionCount();
};
} // namespace MonitorNamespace
using Monitor = MonitorNamespace::Monitor;
} // namespace System::Private::CoreLib::System::Threading
