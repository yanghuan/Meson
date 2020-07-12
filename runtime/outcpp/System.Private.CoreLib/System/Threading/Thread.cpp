#include "Thread-dep.h"

#include <System.Private.CoreLib/System/Threading/Thread-dep.h>

namespace System::Private::CoreLib::System::Threading::ThreadNamespace {
LocalDataStoreSlot Thread___::LocalDataStore::AllocateSlot() {
  return nullptr;
};

Dictionary<String, LocalDataStoreSlot> Thread___::LocalDataStore::EnsureNameToSlotMap() {
  return nullptr;
};

LocalDataStoreSlot Thread___::LocalDataStore::AllocateNamedSlot(String name) {
  return nullptr;
};

LocalDataStoreSlot Thread___::LocalDataStore::GetNamedSlot(String name) {
  return nullptr;
};

void Thread___::LocalDataStore::FreeNamedSlot(String name) {
};

ThreadLocal<Object> Thread___::LocalDataStore::GetThreadLocal(LocalDataStoreSlot slot) {
  return nullptr;
};

Object Thread___::LocalDataStore::GetData(LocalDataStoreSlot slot) {
  return nullptr;
};

void Thread___::LocalDataStore::SetData(LocalDataStoreSlot slot, Object value) {
};

Boolean Thread___::get_IsBackground() {
  return Boolean();
};

void Thread___::set_IsBackground(Boolean value) {
};

ThreadPriority Thread___::get_Priority() {
  return ThreadPriority::Highest;
};

void Thread___::set_Priority(ThreadPriority value) {
};

UInt64 Thread___::get_CurrentOSThreadId() {
  return UInt64();
};

ThreadState Thread___::get_ThreadState() {
  return ThreadState::Aborted;
};

Int32 Thread___::get_OptimalMaxSpinWaitsPerSpinIteration() {
  return Int32();
};

CultureInfo Thread___::get_CurrentCulture() {
  return nullptr;
};

void Thread___::set_CurrentCulture(CultureInfo value) {
};

CultureInfo Thread___::get_CurrentUICulture() {
  return nullptr;
};

void Thread___::set_CurrentUICulture(CultureInfo value) {
};

IPrincipal Thread___::get_CurrentPrincipal() {
  return nullptr;
};

void Thread___::set_CurrentPrincipal(IPrincipal value) {
};

Thread Thread___::get_CurrentThread() {
  return nullptr;
};

ExecutionContext Thread___::get_ExecutionContext() {
  return nullptr;
};

String Thread___::get_Name() {
  return nullptr;
};

void Thread___::set_Name(String value) {
};

ApartmentState Thread___::get_ApartmentState() {
  return ApartmentState::Unknown;
};

void Thread___::set_ApartmentState(ApartmentState value) {
};

void Thread___::Create(ThreadStart start) {
};

void Thread___::Create(ThreadStart start, Int32 maxStackSize) {
};

void Thread___::Create(ParameterizedThreadStart start) {
};

void Thread___::Create(ParameterizedThreadStart start, Int32 maxStackSize) {
};

ThreadHandle Thread___::GetNativeHandle() {
  return ThreadHandle();
};

void Thread___::Start(Object parameter) {
};

void Thread___::Start() {
};

void Thread___::SetCultureOnUnstartedThreadNoCheck(CultureInfo value, Boolean uiCulture) {
};

void Thread___::Sleep(Int32 millisecondsTimeout) {
};

void Thread___::SpinWait(Int32 iterations) {
};

Boolean Thread___::Yield() {
  return Boolean();
};

Thread Thread___::InitializeCurrentThread() {
  return nullptr;
};

void Thread___::SetStartHelper(Delegate start, Int32 maxStackSize) {
};

void Thread___::Finalize() {
};

ApartmentState Thread___::GetApartmentState() {
  return ApartmentState::Unknown;
};

Boolean Thread___::TrySetApartmentStateUnchecked(ApartmentState state) {
  return Boolean();
};

Boolean Thread___::SetApartmentStateHelper(ApartmentState state, Boolean fireMDAOnMismatch) {
  return Boolean();
};

Int32 Thread___::CalculateOptimalMaxSpinWaitsPerSpinIteration() {
  return Int32();
};

Int32 Thread___::GetCurrentProcessorId() {
  return Int32();
};

void Thread___::ResetThreadPoolThread() {
};

void Thread___::RequireCurrentThread() {
};

void Thread___::SetCultureOnUnstartedThread(CultureInfo value, Boolean uiCulture) {
};

void Thread___::ThreadNameChanged(String value) {
};

void Thread___::Abort() {
};

void Thread___::Abort(Object stateInfo) {
};

void Thread___::ResetAbort() {
};

void Thread___::Suspend() {
};

void Thread___::Resume() {
};

void Thread___::BeginCriticalRegion() {
};

void Thread___::EndCriticalRegion() {
};

void Thread___::BeginThreadAffinity() {
};

void Thread___::EndThreadAffinity() {
};

LocalDataStoreSlot Thread___::AllocateDataSlot() {
  return nullptr;
};

LocalDataStoreSlot Thread___::AllocateNamedDataSlot(String name) {
  return nullptr;
};

LocalDataStoreSlot Thread___::GetNamedDataSlot(String name) {
  return nullptr;
};

void Thread___::FreeNamedDataSlot(String name) {
};

Object Thread___::GetData(LocalDataStoreSlot slot) {
  return nullptr;
};

void Thread___::SetData(LocalDataStoreSlot slot, Object data) {
};

void Thread___::SetApartmentState(ApartmentState state) {
};

Boolean Thread___::TrySetApartmentState(ApartmentState state) {
  return Boolean();
};

CompressedStack Thread___::GetCompressedStack() {
  return nullptr;
};

void Thread___::SetCompressedStack(CompressedStack stack) {
};

AppDomain Thread___::GetDomain() {
  return nullptr;
};

Int32 Thread___::GetDomainID() {
  return Int32();
};

Int32 Thread___::GetHashCode() {
  return Int32();
};

void Thread___::Join() {
};

Boolean Thread___::Join(TimeSpan timeout) {
  return Boolean();
};

void Thread___::MemoryBarrier() {
};

void Thread___::Sleep(TimeSpan timeout) {
};

Byte Thread___::VolatileRead(Byte& address) {
  return Byte();
};

Double Thread___::VolatileRead(Double& address) {
  return Double();
};

Int16 Thread___::VolatileRead(Int16& address) {
  return Int16();
};

Int32 Thread___::VolatileRead(Int32& address) {
  return Int32();
};

Int64 Thread___::VolatileRead(Int64& address) {
  return Int64();
};

IntPtr Thread___::VolatileRead(IntPtr& address) {
  return IntPtr();
};

Object Thread___::VolatileRead(Object& address) {
  return nullptr;
};

SByte Thread___::VolatileRead(SByte& address) {
  return SByte();
};

Single Thread___::VolatileRead(Single& address) {
  return Single();
};

UInt16 Thread___::VolatileRead(UInt16& address) {
  return UInt16();
};

UInt32 Thread___::VolatileRead(UInt32& address) {
  return UInt32();
};

UInt64 Thread___::VolatileRead(UInt64& address) {
  return UInt64();
};

UIntPtr Thread___::VolatileRead(UIntPtr& address) {
  return UIntPtr();
};

void Thread___::VolatileWrite(Byte& address, Byte value) {
};

void Thread___::VolatileWrite(Double& address, Double value) {
};

void Thread___::VolatileWrite(Int16& address, Int16 value) {
};

void Thread___::VolatileWrite(Int32& address, Int32 value) {
};

void Thread___::VolatileWrite(Int64& address, Int64 value) {
};

void Thread___::VolatileWrite(IntPtr& address, IntPtr value) {
};

void Thread___::VolatileWrite(Object& address, Object value) {
};

void Thread___::VolatileWrite(SByte& address, SByte value) {
};

void Thread___::VolatileWrite(Single& address, Single value) {
};

void Thread___::VolatileWrite(UInt16& address, UInt16 value) {
};

void Thread___::VolatileWrite(UInt32& address, UInt32 value) {
};

void Thread___::VolatileWrite(UInt64& address, UInt64 value) {
};

void Thread___::VolatileWrite(UIntPtr& address, UIntPtr value) {
};

Exception Thread___::GetApartmentStateChangeFailedException() {
  return nullptr;
};

} // namespace System::Private::CoreLib::System::Threading::ThreadNamespace
