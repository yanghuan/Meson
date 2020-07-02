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
  return void();
};
ThreadLocal<Object> Thread___::LocalDataStore::GetThreadLocal(LocalDataStoreSlot slot) {
  return nullptr;
};
Object Thread___::LocalDataStore::GetData(LocalDataStoreSlot slot) {
  return nullptr;
};
void Thread___::LocalDataStore::SetData(LocalDataStoreSlot slot, Object value) {
  return void();
};
Boolean Thread___::get_IsBackground() {
  return Boolean();
};
void Thread___::set_IsBackground(Boolean value) {
  return void();
};
ThreadPriority Thread___::get_Priority() {
  return ThreadPriority();
};
void Thread___::set_Priority(ThreadPriority value) {
  return void();
};
UInt64 Thread___::get_CurrentOSThreadId() {
  return UInt64();
};
ThreadState Thread___::get_ThreadState() {
  return ThreadState();
};
Int32 Thread___::get_OptimalMaxSpinWaitsPerSpinIteration() {
  return Int32();
};
CultureInfo Thread___::get_CurrentCulture() {
  return nullptr;
};
void Thread___::set_CurrentCulture(CultureInfo value) {
  return void();
};
CultureInfo Thread___::get_CurrentUICulture() {
  return nullptr;
};
void Thread___::set_CurrentUICulture(CultureInfo value) {
  return void();
};
IPrincipal Thread___::get_CurrentPrincipal() {
  return nullptr;
};
void Thread___::set_CurrentPrincipal(IPrincipal value) {
  return void();
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
  return void();
};
ApartmentState Thread___::get_ApartmentState() {
  return ApartmentState();
};
void Thread___::set_ApartmentState(ApartmentState value) {
  return void();
};
void Thread___::Create(ThreadStart start) {
  return void();
};
void Thread___::Create(ThreadStart start, Int32 maxStackSize) {
  return void();
};
void Thread___::Create(ParameterizedThreadStart start) {
  return void();
};
void Thread___::Create(ParameterizedThreadStart start, Int32 maxStackSize) {
  return void();
};
ThreadHandle Thread___::GetNativeHandle() {
  return ThreadHandle();
};
void Thread___::Start(Object parameter) {
  return void();
};
void Thread___::Start() {
  return void();
};
void Thread___::SetCultureOnUnstartedThreadNoCheck(CultureInfo value, Boolean uiCulture) {
  return void();
};
void Thread___::Sleep(Int32 millisecondsTimeout) {
  return void();
};
void Thread___::SpinWait(Int32 iterations) {
  return void();
};
Boolean Thread___::Yield() {
  return Boolean();
};
Thread Thread___::InitializeCurrentThread() {
  return nullptr;
};
void Thread___::SetStartHelper(Delegate start, Int32 maxStackSize) {
  return void();
};
void Thread___::Finalize() {
  return void();
};
ApartmentState Thread___::GetApartmentState() {
  return ApartmentState();
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
Int32 Thread___::RefreshCurrentProcessorId() {
  return Int32();
};
Int32 Thread___::GetCurrentProcessorId() {
  return Int32();
};
void Thread___::ResetThreadPoolThread() {
  return void();
};
void Thread___::RequireCurrentThread() {
  return void();
};
void Thread___::SetCultureOnUnstartedThread(CultureInfo value, Boolean uiCulture) {
  return void();
};
void Thread___::ThreadNameChanged(String value) {
  return void();
};
void Thread___::Abort() {
  return void();
};
void Thread___::Abort(Object stateInfo) {
  return void();
};
void Thread___::ResetAbort() {
  return void();
};
void Thread___::Suspend() {
  return void();
};
void Thread___::Resume() {
  return void();
};
void Thread___::BeginCriticalRegion() {
  return void();
};
void Thread___::EndCriticalRegion() {
  return void();
};
void Thread___::BeginThreadAffinity() {
  return void();
};
void Thread___::EndThreadAffinity() {
  return void();
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
  return void();
};
Object Thread___::GetData(LocalDataStoreSlot slot) {
  return nullptr;
};
void Thread___::SetData(LocalDataStoreSlot slot, Object data) {
  return void();
};
void Thread___::SetApartmentState(ApartmentState state) {
  return void();
};
Boolean Thread___::TrySetApartmentState(ApartmentState state) {
  return Boolean();
};
CompressedStack Thread___::GetCompressedStack() {
  return nullptr;
};
void Thread___::SetCompressedStack(CompressedStack stack) {
  return void();
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
  return void();
};
Boolean Thread___::Join(TimeSpan timeout) {
  return Boolean();
};
void Thread___::MemoryBarrier() {
  return void();
};
void Thread___::Sleep(TimeSpan timeout) {
  return void();
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
  return void();
};
void Thread___::VolatileWrite(Double& address, Double value) {
  return void();
};
void Thread___::VolatileWrite(Int16& address, Int16 value) {
  return void();
};
void Thread___::VolatileWrite(Int32& address, Int32 value) {
  return void();
};
void Thread___::VolatileWrite(Int64& address, Int64 value) {
  return void();
};
void Thread___::VolatileWrite(IntPtr& address, IntPtr value) {
  return void();
};
void Thread___::VolatileWrite(Object& address, Object value) {
  return void();
};
void Thread___::VolatileWrite(SByte& address, SByte value) {
  return void();
};
void Thread___::VolatileWrite(Single& address, Single value) {
  return void();
};
void Thread___::VolatileWrite(UInt16& address, UInt16 value) {
  return void();
};
void Thread___::VolatileWrite(UInt32& address, UInt32 value) {
  return void();
};
void Thread___::VolatileWrite(UInt64& address, UInt64 value) {
  return void();
};
void Thread___::VolatileWrite(UIntPtr& address, UIntPtr value) {
  return void();
};
Exception Thread___::GetApartmentStateChangeFailedException() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Threading::ThreadNamespace
