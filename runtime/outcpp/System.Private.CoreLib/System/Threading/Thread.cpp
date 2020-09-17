#include "Thread-dep.h"

#include <System.Private.CoreLib/System/AppDomain-dep.h>
#include <System.Private.CoreLib/System/ArgumentException-dep.h>
#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/IntPtr-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Object-dep.h>
#include <System.Private.CoreLib/System/PlatformNotSupportedException-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>
#include <System.Private.CoreLib/System/Threading/AsyncLocal-dep.h>
#include <System.Private.CoreLib/System/Threading/Interlocked-dep.h>
#include <System.Private.CoreLib/System/Threading/ProcessorIdCache-dep.h>
#include <System.Private.CoreLib/System/Threading/Thread-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadHelper-dep.h>
#include <System.Private.CoreLib/System/Threading/ThreadLocal-dep.h>
#include <System.Private.CoreLib/System/Threading/Volatile-dep.h>
#include <System.Private.CoreLib/System/Threading/WaitHandle-dep.h>
#include <System.Private.CoreLib/System/UInt32-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadNamespace {
LocalDataStoreSlot Thread___::LocalDataStore::AllocateSlot() {
  return rt::newobj<LocalDataStoreSlot>(rt::newobj<ThreadLocal<Object>>());
}

Dictionary<String, LocalDataStoreSlot> Thread___::LocalDataStore::EnsureNameToSlotMap() {
  Dictionary<String, LocalDataStoreSlot> dictionary = s_nameToSlotMap;
  if (dictionary != nullptr) {
    return dictionary;
  }
  dictionary = rt::newobj<Dictionary<String, LocalDataStoreSlot>>();
  Dictionary<String, LocalDataStoreSlot> as = Interlocked::CompareExchange(s_nameToSlotMap, dictionary, (Dictionary<String, LocalDataStoreSlot>)nullptr);
  return as != nullptr ? as : dictionary;
}

LocalDataStoreSlot Thread___::LocalDataStore::AllocateNamedSlot(String name) {
  LocalDataStoreSlot localDataStoreSlot = AllocateSlot();
  Dictionary<String, LocalDataStoreSlot> dictionary = EnsureNameToSlotMap();
  {
    rt::lock(dictionary);
    dictionary->Add(name, localDataStoreSlot);
    return localDataStoreSlot;
  }
}

LocalDataStoreSlot Thread___::LocalDataStore::GetNamedSlot(String name) {
  Dictionary<String, LocalDataStoreSlot> dictionary = EnsureNameToSlotMap();
  {
    rt::lock(dictionary);
    LocalDataStoreSlot value;
    if (!dictionary->TryGetValue(name, value)) {
      value = (dictionary[name] = AllocateSlot());
    }
    return value;
  }
}

void Thread___::LocalDataStore::FreeNamedSlot(String name) {
  Dictionary<String, LocalDataStoreSlot> dictionary = EnsureNameToSlotMap();
  {
    rt::lock(dictionary);
    dictionary->Remove(name);
  }
}

ThreadLocal<Object> Thread___::LocalDataStore::GetThreadLocal(LocalDataStoreSlot slot) {
  if (slot == nullptr) {
    rt::throw_exception<ArgumentNullException>("slot");
  }
  return slot->get_Data();
}

Object Thread___::LocalDataStore::GetData(LocalDataStoreSlot slot) {
  return GetThreadLocal(slot)->get_Value();
}

void Thread___::LocalDataStore::SetData(LocalDataStoreSlot slot, Object value) {
  GetThreadLocal(slot)->set_Value(value);
}

Boolean Thread___::get_IsBackground() {
  return IsBackgroundNative();
}

void Thread___::set_IsBackground(Boolean value) {
  SetBackgroundNative(value);
}

ThreadPriority Thread___::get_Priority() {
  return (ThreadPriority)GetPriorityNative();
}

void Thread___::set_Priority(ThreadPriority value) {
  SetPriorityNative((Int32)value);
}

UInt64 Thread___::get_CurrentOSThreadId() {
  return GetCurrentOSThreadId();
}

ThreadState Thread___::get_ThreadState() {
  return (ThreadState)GetThreadStateNative();
}

Int32 Thread___::get_OptimalMaxSpinWaitsPerSpinIteration() {
  Int32 num = s_optimalMaxSpinWaitsPerSpinIteration;
  if (num == 0) {
    return CalculateOptimalMaxSpinWaitsPerSpinIteration();
  }
  return num;
}

CultureInfo Thread___::get_CurrentCulture() {
  RequireCurrentThread();
  return CultureInfo::in::get_CurrentCulture();
}

void Thread___::set_CurrentCulture(CultureInfo value) {
  if ((Thread)this != get_CurrentThread()) {
    SetCultureOnUnstartedThread(value, false);
  } else {
    CultureInfo::in::set_CurrentCulture(value);
  }
}

CultureInfo Thread___::get_CurrentUICulture() {
  RequireCurrentThread();
  return CultureInfo::in::get_CurrentUICulture();
}

void Thread___::set_CurrentUICulture(CultureInfo value) {
  if ((Thread)this != get_CurrentThread()) {
    SetCultureOnUnstartedThread(value, true);
  } else {
    CultureInfo::in::set_CurrentUICulture(value);
  }
}

IPrincipal Thread___::get_CurrentPrincipal() {
  AsyncLocal<IPrincipal> asyncLocal = s_asyncLocalPrincipal;
  IPrincipal principal = (asyncLocal != nullptr) ? asyncLocal->get_Value() : nullptr;
  if (principal == nullptr) {
    principal = (get_CurrentPrincipal(AppDomain::in::get_CurrentDomain()->GetThreadPrincipal()));
  }
  return principal;
}

void Thread___::set_CurrentPrincipal(IPrincipal value) {
  if (s_asyncLocalPrincipal == nullptr) {
    if (value == nullptr) {
      return;
    }
    Interlocked::CompareExchange(s_asyncLocalPrincipal, rt::newobj<AsyncLocal<IPrincipal>>(), (AsyncLocal<IPrincipal>)nullptr);
  }
  s_asyncLocalPrincipal->set_Value(value);
}

Thread Thread___::get_CurrentThread() {
  Thread as = t_currentThread;
  return as != nullptr ? as : InitializeCurrentThread();
}

ExecutionContext Thread___::get_ExecutionContext() {
  return ExecutionContext::in::Capture();
}

String Thread___::get_Name() {
  return _name;
}

void Thread___::set_Name(String value) {
  {
    rt::lock((Thread)this);
    if (_name != nullptr) {
      rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_WriteOnce());
    }
    _name = value;
    ThreadNameChanged(value);
  }
}

ApartmentState Thread___::get_ApartmentState() {
  return GetApartmentState();
}

void Thread___::set_ApartmentState(ApartmentState value) {
  TrySetApartmentState(value);
}

void Thread___::ctor() {
}

void Thread___::Create(ThreadStart start) {
  SetStartHelper(start, 0);
}

void Thread___::Create(ThreadStart start, Int32 maxStackSize) {
  SetStartHelper(start, maxStackSize);
}

void Thread___::Create(ParameterizedThreadStart start) {
  SetStartHelper(start, 0);
}

void Thread___::Create(ParameterizedThreadStart start, Int32 maxStackSize) {
  SetStartHelper(start, maxStackSize);
}

ThreadHandle Thread___::GetNativeHandle() {
  IntPtr dONT_USE_InternalThread = _DONT_USE_InternalThread;
  if (dONT_USE_InternalThread == IntPtr::Zero) {
    rt::throw_exception<ArgumentException>(nullptr, SR::get_Argument_InvalidHandle());
  }
  return ThreadHandle(dONT_USE_InternalThread);
}

void Thread___::Start(Object parameter) {
  if (rt::is<ThreadStart>(_delegate)) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_ThreadWrongThreadStart());
  }
  _threadStartArg = parameter;
  Start();
}

void Thread___::Start() {
  StartupSetApartmentStateInternal();
  if ((Object)_delegate != nullptr) {
    ThreadHelper threadHelper = (ThreadHelper)_delegate->get_Target();
    ExecutionContext executionContextHelper = ExecutionContext::in::Capture();
    threadHelper->SetExecutionContextHelper(executionContextHelper);
  }
  StartInternal();
}

void Thread___::SetCultureOnUnstartedThreadNoCheck(CultureInfo value, Boolean uiCulture) {
  ThreadHelper threadHelper = (ThreadHelper)_delegate->get_Target();
  if (uiCulture) {
    threadHelper->_startUICulture = value;
  } else {
    threadHelper->_startCulture = value;
  }
}

void Thread___::Sleep(Int32 millisecondsTimeout) {
  SleepInternal(millisecondsTimeout);
}

void Thread___::SpinWait(Int32 iterations) {
  SpinWaitInternal(iterations);
}

Boolean Thread___::Yield() {
  return YieldInternal() != Interop::BOOL::FALSE;
}

Thread Thread___::InitializeCurrentThread() {
  return t_currentThread = GetCurrentThreadNative();
}

void Thread___::SetStartHelper(Delegate start, Int32 maxStackSize) {
  ThreadHelper object = rt::newobj<ThreadHelper>(start);
  if (rt::is<ThreadStart>(start)) {
    SetStart({object, &ThreadHelper::in::ThreadStart}, maxStackSize);
  } else {
    SetStart({object, &ThreadHelper::in::ThreadStart}, maxStackSize);
  }
}

void Thread___::Finalize() {
  InternalFinalize();
}

ApartmentState Thread___::GetApartmentState() {
  return (ApartmentState)GetApartmentStateNative();
}

Boolean Thread___::TrySetApartmentStateUnchecked(ApartmentState state) {
  ApartmentState apartmentState = (ApartmentState)SetApartmentStateNative((Int32)state);
  if (state == ApartmentState::Unknown && apartmentState == ApartmentState::MTA) {
    return true;
  }
  if (apartmentState != state) {
    return false;
  }
  return true;
}

Int32 Thread___::CalculateOptimalMaxSpinWaitsPerSpinIteration() {
  s_optimalMaxSpinWaitsPerSpinIteration = GetOptimalMaxSpinWaitsPerSpinIterationInternal();
  return s_optimalMaxSpinWaitsPerSpinIteration;
}

Int32 Thread___::GetCurrentProcessorId() {
  if (s_isProcessorNumberReallyFast) {
    return GetCurrentProcessorNumber();
  }
  return ProcessorIdCache::GetCurrentProcessorId();
}

void Thread___::ResetThreadPoolThread() {
}

void Thread___::ctor(ThreadStart start) {
  if (start == nullptr) {
    rt::throw_exception<ArgumentNullException>("start");
  }
  Create(start);
}

void Thread___::ctor(ThreadStart start, Int32 maxStackSize) {
  if (start == nullptr) {
    rt::throw_exception<ArgumentNullException>("start");
  }
  if (maxStackSize < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("maxStackSize", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Create(start, maxStackSize);
}

void Thread___::ctor(ParameterizedThreadStart start) {
  if (start == nullptr) {
    rt::throw_exception<ArgumentNullException>("start");
  }
  Create(start);
}

void Thread___::ctor(ParameterizedThreadStart start, Int32 maxStackSize) {
  if (start == nullptr) {
    rt::throw_exception<ArgumentNullException>("start");
  }
  if (maxStackSize < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("maxStackSize", SR::get_ArgumentOutOfRange_NeedNonNegNum());
  }
  Create(start, maxStackSize);
}

void Thread___::RequireCurrentThread() {
  if ((Thread)this != get_CurrentThread()) {
    rt::throw_exception<InvalidOperationException>(SR::get_Thread_Operation_RequiresCurrentThread());
  }
}

void Thread___::SetCultureOnUnstartedThread(CultureInfo value, Boolean uiCulture) {
  if (value == nullptr) {
    rt::throw_exception<ArgumentNullException>("value");
  }
  if ((get_ThreadState() & ThreadState::Unstarted) == 0) {
    rt::throw_exception<InvalidOperationException>(SR::get_Thread_Operation_RequiresCurrentThread());
  }
  SetCultureOnUnstartedThreadNoCheck(value, uiCulture);
}

void Thread___::ThreadNameChanged(String value) {
  InformThreadNameChange(GetNativeHandle(), value, (value != nullptr) ? value->get_Length() : 0);
}

void Thread___::Abort() {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_ThreadAbort());
}

void Thread___::Abort(Object stateInfo) {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_ThreadAbort());
}

void Thread___::ResetAbort() {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_ThreadAbort());
}

void Thread___::Suspend() {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_ThreadSuspend());
}

void Thread___::Resume() {
  rt::throw_exception<PlatformNotSupportedException>(SR::get_PlatformNotSupported_ThreadSuspend());
}

void Thread___::BeginCriticalRegion() {
}

void Thread___::EndCriticalRegion() {
}

void Thread___::BeginThreadAffinity() {
}

void Thread___::EndThreadAffinity() {
}

LocalDataStoreSlot Thread___::AllocateDataSlot() {
  return LocalDataStore::AllocateSlot();
}

LocalDataStoreSlot Thread___::AllocateNamedDataSlot(String name) {
  return LocalDataStore::AllocateNamedSlot(name);
}

LocalDataStoreSlot Thread___::GetNamedDataSlot(String name) {
  return LocalDataStore::GetNamedSlot(name);
}

void Thread___::FreeNamedDataSlot(String name) {
  LocalDataStore::FreeNamedSlot(name);
}

Object Thread___::GetData(LocalDataStoreSlot slot) {
  return LocalDataStore::GetData(slot);
}

void Thread___::SetData(LocalDataStoreSlot slot, Object data) {
  LocalDataStore::SetData(slot, data);
}

void Thread___::SetApartmentState(ApartmentState state) {
  if (!TrySetApartmentState(state)) {
    rt::throw_exception(GetApartmentStateChangeFailedException());
  }
}

Boolean Thread___::TrySetApartmentState(ApartmentState state) {
  if ((UInt32)state > 2u) {
    rt::throw_exception<ArgumentOutOfRangeException>("state", SR::get_ArgumentOutOfRange_Enum());
  }
  return TrySetApartmentStateUnchecked(state);
}

CompressedStack Thread___::GetCompressedStack() {
  rt::throw_exception<InvalidOperationException>(SR::get_Thread_GetSetCompressedStack_NotSupported());
}

void Thread___::SetCompressedStack(CompressedStack stack) {
  rt::throw_exception<InvalidOperationException>(SR::get_Thread_GetSetCompressedStack_NotSupported());
}

AppDomain Thread___::GetDomain() {
  return AppDomain::in::get_CurrentDomain();
}

Int32 Thread___::GetDomainID() {
  return 1;
}

Int32 Thread___::GetHashCode() {
  return get_ManagedThreadId();
}

void Thread___::Join() {
  Join(-1);
}

Boolean Thread___::Join(TimeSpan timeout) {
  return Join(WaitHandle::in::ToTimeoutMilliseconds(timeout));
}

void Thread___::MemoryBarrier() {
  Interlocked::MemoryBarrier();
}

void Thread___::Sleep(TimeSpan timeout) {
  Sleep(WaitHandle::in::ToTimeoutMilliseconds(timeout));
}

Byte Thread___::VolatileRead(Byte& address) {
  return Volatile::Read(address);
}

Double Thread___::VolatileRead(Double& address) {
  return Volatile::Read(address);
}

Int16 Thread___::VolatileRead(Int16& address) {
  return Volatile::Read(address);
}

Int32 Thread___::VolatileRead(Int32& address) {
  return Volatile::Read(address);
}

Int64 Thread___::VolatileRead(Int64& address) {
  return Volatile::Read(address);
}

IntPtr Thread___::VolatileRead(IntPtr& address) {
  return Volatile::Read(address);
}

Object Thread___::VolatileRead(Object& address) {
  return Volatile::Read(address);
}

SByte Thread___::VolatileRead(SByte& address) {
  return Volatile::Read(address);
}

Single Thread___::VolatileRead(Single& address) {
  return Volatile::Read(address);
}

UInt16 Thread___::VolatileRead(UInt16& address) {
  return Volatile::Read(address);
}

UInt32 Thread___::VolatileRead(UInt32& address) {
  return Volatile::Read(address);
}

UInt64 Thread___::VolatileRead(UInt64& address) {
  return Volatile::Read(address);
}

UIntPtr Thread___::VolatileRead(UIntPtr& address) {
  return Volatile::Read(address);
}

void Thread___::VolatileWrite(Byte& address, Byte value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(Double& address, Double value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(Int16& address, Int16 value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(Int32& address, Int32 value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(Int64& address, Int64 value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(IntPtr& address, IntPtr value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(Object& address, Object value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(SByte& address, SByte value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(Single& address, Single value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(UInt16& address, UInt16 value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(UInt32& address, UInt32 value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(UInt64& address, UInt64 value) {
  Volatile::Write(address, value);
}

void Thread___::VolatileWrite(UIntPtr& address, UIntPtr value) {
  Volatile::Write(address, value);
}

Exception Thread___::GetApartmentStateChangeFailedException() {
  return rt::newobj<InvalidOperationException>(SR::get_Thread_ApartmentState_ChangeFailed());
}

void Thread___::cctor() {
  s_isProcessorNumberReallyFast = ProcessorIdCache::ProcessorNumberSpeedCheck();
}

} // namespace System::Private::CoreLib::System::Threading::ThreadNamespace
