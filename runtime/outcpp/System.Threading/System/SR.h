#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System::Resources {
FORWARD(ResourceManager)
} // namespace System::Private::CoreLib::System::Resources
namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARD(Object)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Threading::System {
namespace SRNamespace {
using namespace ::System::Private::CoreLib::System;
using namespace ::System::Private::CoreLib::System::Resources;
class SR {
  public: static ResourceManager get_ResourceManager();
  public: static String get_CountdownEvent_Increment_AlreadyZero();
  public: static String get_CountdownEvent_Increment_AlreadyMax();
  public: static String get_CountdownEvent_Decrement_BelowZero();
  public: static String get_Common_OperationCanceled();
  public: static String get_Barrier_Dispose();
  public: static String get_Barrier_SignalAndWait_InvalidOperation_ZeroTotal();
  public: static String get_Barrier_SignalAndWait_ArgumentOutOfRange();
  public: static String get_Barrier_RemoveParticipants_InvalidOperation();
  public: static String get_Barrier_RemoveParticipants_ArgumentOutOfRange();
  public: static String get_Barrier_RemoveParticipants_NonPositive_ArgumentOutOfRange();
  public: static String get_Barrier_InvalidOperation_CalledFromPHA();
  public: static String get_Barrier_AddParticipants_NonPositive_ArgumentOutOfRange();
  public: static String get_Barrier_SignalAndWait_InvalidOperation_ThreadsExceeded();
  public: static String get_BarrierPostPhaseException();
  public: static String get_Barrier_ctor_ArgumentOutOfRange();
  public: static String get_Barrier_AddParticipants_Overflow_ArgumentOutOfRange();
  public: static String get_Overflow_UInt16();
  public: static String get_ReaderWriterLock_Timeout();
  public: static String get_ArgumentOutOfRange_TimeoutMilliseconds();
  public: static String get_ReaderWriterLock_NotOwner();
  public: static String get_ExceptionFromHResult();
  public: static String get_ReaderWriterLock_InvalidLockCookie();
  public: static String get_ReaderWriterLock_RestoreLockWithOwnedLocks();
  public: static String get_HostExecutionContextManager_InvalidOperation_NotNewCaptureContext();
  public: static String get_HostExecutionContextManager_InvalidOperation_CannotOverrideSetWithoutRevert();
  public: static String get_HostExecutionContextManager_InvalidOperation_CannotUseSwitcherOtherThread();
  private: static Boolean UsingResourceKeys();
  public: static String GetResourceString(String resourceKey, String defaultString);
  public: static String Format(String resourceFormat, Object p1);
  private: static ResourceManager s_resourceManager;
};
} // namespace SRNamespace
using SR = SRNamespace::SR;
} // namespace System::Threading::System
