#include "Exception-dep.h"

#include <System.Private.CoreLib/System/Exception-dep.h>

namespace System::Private::CoreLib::System::ExceptionNamespace {
Object Exception___::__RestrictedErrorObject___::get_RealErrorObject() {
  return nullptr;
};
MethodBase Exception___::get_TargetSite() {
  return nullptr;
};
String Exception___::get_StackTrace() {
  return nullptr;
};
String Exception___::get_SerializationRemoteStackTraceString() {
  return nullptr;
};
Object Exception___::get_SerializationWatsonBuckets() {
  return nullptr;
};
String Exception___::get_SerializationStackTraceString() {
  return nullptr;
};
String Exception___::get_Message() {
  return nullptr;
};
IDictionary Exception___::get_Data() {
  return nullptr;
};
Exception Exception___::get_InnerException() {
  return nullptr;
};
String Exception___::get_HelpLink() {
  return nullptr;
};
void Exception___::set_HelpLink(String value) {
  return void();
};
String Exception___::get_Source() {
  return nullptr;
};
void Exception___::set_Source(String value) {
  return void();
};
Int32 Exception___::get_HResult() {
  return Int32();
};
void Exception___::set_HResult(Int32 value) {
  return void();
};
IDictionary Exception___::CreateDataContainer() {
  return nullptr;
};
void Exception___::AddExceptionDataForRestrictedErrorInfo(String restrictedError, String restrictedErrorReference, String restrictedCapabilitySid, Object restrictedErrorObject, Boolean hasrestrictedLanguageErrorObject) {
  return void();
};
Boolean Exception___::TryGetRestrictedLanguageErrorObject(Object& restrictedErrorObject) {
  return Boolean();
};
MethodBase Exception___::GetExceptionMethodFromStackTrace() {
  return nullptr;
};
String Exception___::GetStackTrace(Exception e) {
  return nullptr;
};
String Exception___::CreateSourceName() {
  return nullptr;
};
void Exception___::OnDeserialized(StreamingContext context) {
  return void();
};
void Exception___::InternalPreserveStackTrace() {
  return void();
};
Object Exception___::DeepCopyStackTrace(Object currentStackTrace) {
  return nullptr;
};
Object Exception___::DeepCopyDynamicMethods(Object currentDynamicMethods) {
  return nullptr;
};
void Exception___::RestoreDispatchState(DispatchState& dispatchState) {
  return void();
};
String Exception___::GetMessageFromNativeResources(ExceptionMessageKind kind) {
  return nullptr;
};
Exception::in::DispatchState Exception___::CaptureDispatchState() {
  return Exception::in::DispatchState();
};
String Exception___::GetClassName() {
  return nullptr;
};
Exception Exception___::GetBaseException() {
  return nullptr;
};
void Exception___::GetObjectData(SerializationInfo info, StreamingContext context) {
  return void();
};
String Exception___::ToString() {
  return nullptr;
};
Type Exception___::GetType() {
  return nullptr;
};
void Exception___::RestoreRemoteStackTrace(SerializationInfo info, StreamingContext context) {
  return void();
};
} // namespace System::Private::CoreLib::System::ExceptionNamespace