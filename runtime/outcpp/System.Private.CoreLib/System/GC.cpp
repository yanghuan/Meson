#include "GC-dep.h"

#include <System.Private.CoreLib/System/GC-dep.h>

namespace System::Private::CoreLib::System::GCNamespace {
Int32 GC::get_MaxGeneration() {
  return Int32();
};
GCMemoryInfo GC::GetGCMemoryInfo() {
  return GCMemoryInfo();
};
void GC::AddMemoryPressure(Int64 bytesAllocated) {
};
void GC::RemoveMemoryPressure(Int64 bytesAllocated) {
};
void GC::Collect(Int32 generation) {
};
void GC::Collect() {
};
void GC::Collect(Int32 generation, GCCollectionMode mode) {
};
void GC::Collect(Int32 generation, GCCollectionMode mode, Boolean blocking) {
};
void GC::Collect(Int32 generation, GCCollectionMode mode, Boolean blocking, Boolean compacting) {
};
Int32 GC::CollectionCount(Int32 generation) {
  return Int32();
};
void GC::KeepAlive(Object obj) {
};
Int32 GC::GetGeneration(WeakReference<> wo) {
  return Int32();
};
void GC::WaitForPendingFinalizers() {
};
void GC::SuppressFinalize(Object obj) {
};
void GC::ReRegisterForFinalize(Object obj) {
};
Int64 GC::GetTotalMemory(Boolean forceFullCollection) {
  return Int64();
};
void GC::RegisterForFullGCNotification(Int32 maxGenerationThreshold, Int32 largeObjectHeapThreshold) {
};
void GC::CancelFullGCNotification() {
};
GCNotificationStatus GC::WaitForFullGCApproach() {
  return GCNotificationStatus();
};
GCNotificationStatus GC::WaitForFullGCApproach(Int32 millisecondsTimeout) {
  return GCNotificationStatus();
};
GCNotificationStatus GC::WaitForFullGCComplete() {
  return GCNotificationStatus();
};
GCNotificationStatus GC::WaitForFullGCComplete(Int32 millisecondsTimeout) {
  return GCNotificationStatus();
};
Boolean GC::StartNoGCRegionWorker(Int64 totalSize, Boolean hasLohSize, Int64 lohSize, Boolean disallowFullBlockingGC) {
  return Boolean();
};
Boolean GC::TryStartNoGCRegion(Int64 totalSize) {
  return Boolean();
};
Boolean GC::TryStartNoGCRegion(Int64 totalSize, Int64 lohSize) {
  return Boolean();
};
Boolean GC::TryStartNoGCRegion(Int64 totalSize, Boolean disallowFullBlockingGC) {
  return Boolean();
};
Boolean GC::TryStartNoGCRegion(Int64 totalSize, Int64 lohSize, Boolean disallowFullBlockingGC) {
  return Boolean();
};
GC::EndNoGCRegionStatus GC::EndNoGCRegionWorker() {
  return GC::EndNoGCRegionStatus();
};
void GC::EndNoGCRegion() {
};
} // namespace System::Private::CoreLib::System::GCNamespace
