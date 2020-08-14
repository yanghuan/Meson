#include "SR-dep.h"

#include <System.Private.CoreLib/System/Resources/MissingManifestResourceException-dep.h>

namespace System::Threading::System::SRNamespace {
using namespace ::System::Private::CoreLib::System::Resources;

ResourceManager SR::get_ResourceManager() {
}

String SR::get_CountdownEvent_Increment_AlreadyZero() {
  return GetResourceString("CountdownEvent_Increment_AlreadyZero");
}

String SR::get_CountdownEvent_Increment_AlreadyMax() {
  return GetResourceString("CountdownEvent_Increment_AlreadyMax");
}

String SR::get_CountdownEvent_Decrement_BelowZero() {
  return GetResourceString("CountdownEvent_Decrement_BelowZero");
}

String SR::get_Common_OperationCanceled() {
  return GetResourceString("Common_OperationCanceled");
}

String SR::get_Barrier_Dispose() {
  return GetResourceString("Barrier_Dispose");
}

String SR::get_Barrier_SignalAndWait_InvalidOperation_ZeroTotal() {
  return GetResourceString("Barrier_SignalAndWait_InvalidOperation_ZeroTotal");
}

String SR::get_Barrier_SignalAndWait_ArgumentOutOfRange() {
  return GetResourceString("Barrier_SignalAndWait_ArgumentOutOfRange");
}

String SR::get_Barrier_RemoveParticipants_InvalidOperation() {
  return GetResourceString("Barrier_RemoveParticipants_InvalidOperation");
}

String SR::get_Barrier_RemoveParticipants_ArgumentOutOfRange() {
  return GetResourceString("Barrier_RemoveParticipants_ArgumentOutOfRange");
}

String SR::get_Barrier_RemoveParticipants_NonPositive_ArgumentOutOfRange() {
  return GetResourceString("Barrier_RemoveParticipants_NonPositive_ArgumentOutOfRange");
}

String SR::get_Barrier_InvalidOperation_CalledFromPHA() {
  return GetResourceString("Barrier_InvalidOperation_CalledFromPHA");
}

String SR::get_Barrier_AddParticipants_NonPositive_ArgumentOutOfRange() {
  return GetResourceString("Barrier_AddParticipants_NonPositive_ArgumentOutOfRange");
}

String SR::get_Barrier_SignalAndWait_InvalidOperation_ThreadsExceeded() {
  return GetResourceString("Barrier_SignalAndWait_InvalidOperation_ThreadsExceeded");
}

String SR::get_BarrierPostPhaseException() {
  return GetResourceString("BarrierPostPhaseException");
}

String SR::get_Barrier_ctor_ArgumentOutOfRange() {
  return GetResourceString("Barrier_ctor_ArgumentOutOfRange");
}

String SR::get_Barrier_AddParticipants_Overflow_ArgumentOutOfRange() {
  return GetResourceString("Barrier_AddParticipants_Overflow_ArgumentOutOfRange");
}

String SR::get_Overflow_UInt16() {
  return GetResourceString("Overflow_UInt16");
}

String SR::get_ReaderWriterLock_Timeout() {
  return GetResourceString("ReaderWriterLock_Timeout");
}

String SR::get_ArgumentOutOfRange_TimeoutMilliseconds() {
  return GetResourceString("ArgumentOutOfRange_TimeoutMilliseconds");
}

String SR::get_ReaderWriterLock_NotOwner() {
  return GetResourceString("ReaderWriterLock_NotOwner");
}

String SR::get_ExceptionFromHResult() {
  return GetResourceString("ExceptionFromHResult");
}

String SR::get_ReaderWriterLock_InvalidLockCookie() {
  return GetResourceString("ReaderWriterLock_InvalidLockCookie");
}

String SR::get_ReaderWriterLock_RestoreLockWithOwnedLocks() {
  return GetResourceString("ReaderWriterLock_RestoreLockWithOwnedLocks");
}

String SR::get_HostExecutionContextManager_InvalidOperation_NotNewCaptureContext() {
  return GetResourceString("HostExecutionContextManager_InvalidOperation_NotNewCaptureContext");
}

String SR::get_HostExecutionContextManager_InvalidOperation_CannotOverrideSetWithoutRevert() {
  return GetResourceString("HostExecutionContextManager_InvalidOperation_CannotOverrideSetWithoutRevert");
}

String SR::get_HostExecutionContextManager_InvalidOperation_CannotUseSwitcherOtherThread() {
  return GetResourceString("HostExecutionContextManager_InvalidOperation_CannotUseSwitcherOtherThread");
}

Boolean SR::UsingResourceKeys() {
  return false;
}

String SR::GetResourceString(String resourceKey, String defaultString) {
  if (UsingResourceKeys()) {
  }
  String text = nullptr;
  try{
    text = get_ResourceManager()->GetString(resourceKey);
  } catch (MissingManifestResourceException) {
  }
  if (defaultString != nullptr && resourceKey->Equals(text)) {
    return defaultString;
  }
  return text;
}

String SR::Format(String resourceFormat, Object p1) {
  if (UsingResourceKeys()) {
  }
  return String::in::Format(resourceFormat, p1);
}

} // namespace System::Threading::System::SRNamespace
