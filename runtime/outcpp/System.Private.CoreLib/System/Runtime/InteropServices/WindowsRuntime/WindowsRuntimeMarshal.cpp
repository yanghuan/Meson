#include "WindowsRuntimeMarshal-dep.h"

#include <System.Private.CoreLib/System/Runtime/InteropServices/WindowsRuntime/WindowsRuntimeMarshal-dep.h>

namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime::WindowsRuntimeMarshalNamespace {
Boolean WindowsRuntimeMarshal::EventRegistrationTokenList::Push(EventRegistrationToken token) {
  return Boolean();
};
Boolean WindowsRuntimeMarshal::EventRegistrationTokenList::Pop(EventRegistrationToken& token) {
  return Boolean();
};
void WindowsRuntimeMarshal::EventRegistrationTokenList::CopyTo(List<EventRegistrationToken> tokens) {
  return void();
};
Dictionary<Object, WindowsRuntimeMarshal::EventRegistrationTokenList> WindowsRuntimeMarshal::ManagedEventRegistrationImpl::GetEventRegistrationTokenTable(Object instance, Action<EventRegistrationToken> removeMethod) {
  return nullptr;
};
void WindowsRuntimeMarshal::ManagedEventRegistrationImpl::RemoveAllEventHandlers(Action<EventRegistrationToken> removeMethod) {
  return void();
};
String WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::EventCacheKey::ToString() {
  return nullptr;
};
Boolean WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::EventCacheKey::Equals(EventCacheKey other) {
  return Boolean();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::TokenListCount___::Inc() {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::TokenListCount___::Dec() {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::TokenListCount___::CleanupCache() {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::EventRegistrationTokenListWithCount___::Finalize() {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::EventRegistrationTokenListWithCount___::Push(EventRegistrationToken token) {
  return void();
};
Boolean WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::EventRegistrationTokenListWithCount___::Pop(EventRegistrationToken& token) {
  return Boolean();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::EventRegistrationTokenListWithCount___::CopyTo(List<EventRegistrationToken> tokens) {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::MyReaderWriterLock___::AcquireReaderLock(Int32 millisecondsTimeout) {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::MyReaderWriterLock___::AcquireWriterLock(Int32 millisecondsTimeout) {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::MyReaderWriterLock___::ReleaseReaderLock() {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::MyReaderWriterLock___::ReleaseWriterLock() {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::MyReaderWriterLock___::LazyCreateEvent(EventWaitHandle& waitEvent, Boolean makeAutoResetEvent) {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::MyReaderWriterLock___::WaitOnEvent(EventWaitHandle waitEvent, UInt32& numWaiters, Int32 millisecondsTimeout) {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::MyReaderWriterLock___::ExitAndWakeUpAppropriateWaiters() {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::MyReaderWriterLock___::EnterMyLock() {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::MyReaderWriterLock___::EnterMyLockSpin() {
  return void();
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::MyReaderWriterLock___::ExitMyLock() {
  return void();
};
Object WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::GetInstanceKey(Action<EventRegistrationToken> removeMethod) {
  return nullptr;
};
Object WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::FindEquivalentKeyUnsafe(ConditionalWeakTable<Object, EventRegistrationTokenListWithCount> registrationTable, Object handler, EventRegistrationTokenListWithCount& tokens) {
  return nullptr;
};
ConditionalWeakTable<Object, WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::EventRegistrationTokenListWithCount> WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::GetEventRegistrationTokenTableNoCreate(Object instance, Action<EventRegistrationToken> removeMethod, TokenListCount& tokenListCount) {
  return nullptr;
};
ConditionalWeakTable<Object, WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::EventRegistrationTokenListWithCount> WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::GetOrCreateEventRegistrationTokenTable(Object instance, Action<EventRegistrationToken> removeMethod, TokenListCount& tokenListCount) {
  return nullptr;
};
ConditionalWeakTable<Object, WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::EventRegistrationTokenListWithCount> WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::GetEventRegistrationTokenTableInternal(Object instance, Action<EventRegistrationToken> removeMethod, TokenListCount& tokenListCount, Boolean createIfNotFound) {
  return nullptr;
};
void WindowsRuntimeMarshal::NativeOrStaticEventRegistrationImpl::RemoveAllEventHandlers(Action<EventRegistrationToken> removeMethod) {
  return void();
};
void WindowsRuntimeMarshal::RemoveAllEventHandlers(Action<EventRegistrationToken> removeMethod) {
  return void();
};
Int32 WindowsRuntimeMarshal::GetRegistrationTokenCacheSize() {
  return Int32();
};
void WindowsRuntimeMarshal::CallRemoveMethods(Action<EventRegistrationToken> removeMethod, List<EventRegistrationToken> tokensToRemove) {
  return void();
};
String WindowsRuntimeMarshal::HStringToString(IntPtr hstring) {
  return nullptr;
};
Exception WindowsRuntimeMarshal::GetExceptionForHR(Int32 hresult, Exception innerException, String messageResource) {
  return nullptr;
};
Exception WindowsRuntimeMarshal::GetExceptionForHR(Int32 hresult, Exception innerException) {
  return nullptr;
};
Boolean WindowsRuntimeMarshal::RoOriginateLanguageException(Int32 error, String message, IntPtr languageException) {
  return Boolean();
};
void WindowsRuntimeMarshal::RoReportUnhandledError(IRestrictedErrorInfo error) {
  return void();
};
Boolean WindowsRuntimeMarshal::ReportUnhandledError(Exception e) {
  return Boolean();
};
IntPtr WindowsRuntimeMarshal::GetActivationFactoryForType(Type type) {
  return IntPtr();
};
ManagedActivationFactory WindowsRuntimeMarshal::GetManagedActivationFactory(Type type) {
  return nullptr;
};
IActivationFactory WindowsRuntimeMarshal::GetActivationFactory(Type type) {
  return nullptr;
};
IntPtr WindowsRuntimeMarshal::StringToHString(String s) {
  return IntPtr();
};
String WindowsRuntimeMarshal::PtrToStringHString(IntPtr ptr) {
  return nullptr;
};
void WindowsRuntimeMarshal::FreeHString(IntPtr ptr) {
  return void();
};
void WindowsRuntimeMarshal::Log(String s) {
  return void();
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::WindowsRuntime::WindowsRuntimeMarshalNamespace
