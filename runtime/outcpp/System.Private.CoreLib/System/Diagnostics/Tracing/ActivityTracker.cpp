#include "ActivityTracker-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/ActivityTracker-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::ActivityTrackerNamespace {
Guid ActivityTracker___::ActivityInfo___::get_ActivityId() {
  return Guid();
};
String ActivityTracker___::ActivityInfo___::Path(ActivityInfo activityInfo) {
  return nullptr;
};
String ActivityTracker___::ActivityInfo___::ToString() {
  return nullptr;
};
String ActivityTracker___::ActivityInfo___::LiveActivities(ActivityInfo list) {
  return nullptr;
};
Boolean ActivityTracker___::ActivityInfo___::CanBeOrphan() {
  return Boolean();
};
void ActivityTracker___::ActivityInfo___::CreateActivityPathGuid(Guid& idRet, Int32& activityPathGuidOffset) {
};
void ActivityTracker___::ActivityInfo___::CreateOverflowGuid(Guid* outPtr) {
};
Int32 ActivityTracker___::ActivityInfo___::AddIdToGuid(Guid* outPtr, Int32 whereToAddId, UInt32 id, Boolean overflow) {
  return Int32();
};
void ActivityTracker___::ActivityInfo___::WriteNibble(Byte*& ptr, Byte* endPtr, UInt32 value) {
};
ActivityTracker ActivityTracker___::get_Instance() {
  return nullptr;
};
void ActivityTracker___::OnStart(String providerName, String activityName, Int32 task, Guid& activityId, Guid& relatedActivityId, EventActivityOptions options, Boolean useTplSource) {
};
void ActivityTracker___::OnStop(String providerName, String activityName, Int32 task, Guid& activityId, Boolean useTplSource) {
};
void ActivityTracker___::Enable() {
};
ActivityTracker::in::ActivityInfo ActivityTracker___::FindActiveActivity(String name, ActivityInfo startLocation) {
  return nullptr;
};
String ActivityTracker___::NormalizeActivityName(String providerName, String activityName, Int32 task) {
  return nullptr;
};
void ActivityTracker___::ActivityChanging(AsyncLocalValueChangedArgs<ActivityInfo> args) {
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::ActivityTrackerNamespace
