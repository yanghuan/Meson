#include "GC-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>
#include <System.Private.CoreLib/System/ArgumentOutOfRangeException-dep.h>
#include <System.Private.CoreLib/System/Double-dep.h>
#include <System.Private.CoreLib/System/GCCollectionMode.h>
#include <System.Private.CoreLib/System/Int64-dep.h>
#include <System.Private.CoreLib/System/InvalidOperationException-dep.h>
#include <System.Private.CoreLib/System/Single-dep.h>
#include <System.Private.CoreLib/System/SR-dep.h>

namespace System::Private::CoreLib::System::GCNamespace {
Int32 GC::get_MaxGeneration() {
  return GetMaxGeneration();
}

GCMemoryInfo GC::GetGCMemoryInfo() {
  UInt64 highMemLoadThresholdBytes;
  UInt64 totalAvailableMemoryBytes;
  UInt64 lastRecordedMemLoadBytes;
  UInt32 lastRecordedMemLoadPct;
  UIntPtr lastRecordedHeapSizeBytes;
  UIntPtr lastRecordedFragmentationBytes;
  GetMemoryInfo(highMemLoadThresholdBytes, totalAvailableMemoryBytes, lastRecordedMemLoadBytes, lastRecordedMemLoadPct, lastRecordedHeapSizeBytes, lastRecordedFragmentationBytes);
  return GCMemoryInfo((Int64)highMemLoadThresholdBytes, (Int64)lastRecordedMemLoadBytes, (Int64)totalAvailableMemoryBytes, (Int64)(UInt64)lastRecordedHeapSizeBytes, (Int64)(UInt64)lastRecordedFragmentationBytes);
}

void GC::AddMemoryPressure(Int64 bytesAllocated) {
  if (bytesAllocated <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bytesAllocated", SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  if (4 == IntPtr::get_Size()) {
  }
  _AddMemoryPressure((UInt64)bytesAllocated);
}

void GC::RemoveMemoryPressure(Int64 bytesAllocated) {
  if (bytesAllocated <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("bytesAllocated", SR::get_ArgumentOutOfRange_NeedPosNum());
  }
  if (4 == IntPtr::get_Size()) {
  }
  _RemoveMemoryPressure((UInt64)bytesAllocated);
}

void GC::Collect(Int32 generation) {
  Collect(generation, GCCollectionMode::Default);
}

void GC::Collect() {
  _Collect(-1, 2);
}

void GC::Collect(Int32 generation, GCCollectionMode mode) {
  Collect(generation, mode, true);
}

void GC::Collect(Int32 generation, GCCollectionMode mode, Boolean blocking) {
  Collect(generation, mode, blocking, false);
}

void GC::Collect(Int32 generation, GCCollectionMode mode, Boolean blocking, Boolean compacting) {
  if (generation < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("generation", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  if (mode < GCCollectionMode::Default || mode > GCCollectionMode::Optimized) {
    rt::throw_exception<ArgumentOutOfRangeException>("mode", SR::get_ArgumentOutOfRange_Enum());
  }
  Int32 num = 0;
  if (mode == GCCollectionMode::Optimized) {
    num |= 4;
  }
  if (compacting) {
    num |= 8;
  }
  if (blocking) {
    num |= 2;
  } else if (!compacting) {
    num |= 1;
  }

  _Collect(generation, num);
}

Int32 GC::CollectionCount(Int32 generation) {
  if (generation < 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("generation", SR::get_ArgumentOutOfRange_GenericPositive());
  }
  return _CollectionCount(generation, 0);
}

void GC::KeepAlive(Object obj) {
}

Int32 GC::GetGeneration(WeakReference<> wo) {
  Int32 generationWR = GetGenerationWR(wo->m_handle);
  KeepAlive(wo);
  return generationWR;
}

void GC::WaitForPendingFinalizers() {
  _WaitForPendingFinalizers();
}

void GC::SuppressFinalize(Object obj) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>("obj");
  }
  _SuppressFinalize(obj);
}

void GC::ReRegisterForFinalize(Object obj) {
  if (obj == nullptr) {
    rt::throw_exception<ArgumentNullException>("obj");
  }
  _ReRegisterForFinalize(obj);
}

Int64 GC::GetTotalMemory(Boolean forceFullCollection) {
  Int64 totalMemory = GetTotalMemory();
  if (!forceFullCollection) {
    return totalMemory;
  }
  Int32 num = 20;
  Int64 num2 = totalMemory;
  Single num3;
  do {
    WaitForPendingFinalizers();
    Collect();
    totalMemory = num2;
    num2 = GetTotalMemory();
    num3 = (Single)(num2 - totalMemory) / (Single)totalMemory;
  } while (num-- > 0 && (!(-0.05 < (Double)num3) || !((Double)num3 < 0.05)));
  return num2;
}

void GC::RegisterForFullGCNotification(Int32 maxGenerationThreshold, Int32 largeObjectHeapThreshold) {
  if (maxGenerationThreshold <= 0 || maxGenerationThreshold >= 100) {
    rt::throw_exception<ArgumentOutOfRangeException>("maxGenerationThreshold", SR::Format(SR::get_ArgumentOutOfRange_Bounds_Lower_Upper(), 1, 99));
  }
  if (largeObjectHeapThreshold <= 0 || largeObjectHeapThreshold >= 100) {
    rt::throw_exception<ArgumentOutOfRangeException>("largeObjectHeapThreshold", SR::Format(SR::get_ArgumentOutOfRange_Bounds_Lower_Upper(), 1, 99));
  }
  if (!_RegisterForFullGCNotification(maxGenerationThreshold, largeObjectHeapThreshold)) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotWithConcurrentGC());
  }
}

void GC::CancelFullGCNotification() {
  if (!_CancelFullGCNotification()) {
    rt::throw_exception<InvalidOperationException>(SR::get_InvalidOperation_NotWithConcurrentGC());
  }
}

GCNotificationStatus GC::WaitForFullGCApproach() {
  return (GCNotificationStatus)_WaitForFullGCApproach(-1);
}

GCNotificationStatus GC::WaitForFullGCApproach(Int32 millisecondsTimeout) {
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  return (GCNotificationStatus)_WaitForFullGCApproach(millisecondsTimeout);
}

GCNotificationStatus GC::WaitForFullGCComplete() {
  return (GCNotificationStatus)_WaitForFullGCComplete(-1);
}

GCNotificationStatus GC::WaitForFullGCComplete(Int32 millisecondsTimeout) {
  if (millisecondsTimeout < -1) {
    rt::throw_exception<ArgumentOutOfRangeException>("millisecondsTimeout", SR::get_ArgumentOutOfRange_NeedNonNegOrNegative1());
  }
  return (GCNotificationStatus)_WaitForFullGCComplete(millisecondsTimeout);
}

Boolean GC::StartNoGCRegionWorker(Int64 totalSize, Boolean hasLohSize, Int64 lohSize, Boolean disallowFullBlockingGC) {
  if (totalSize <= 0) {
    rt::throw_exception<ArgumentOutOfRangeException>("totalSize", "totalSize can't be zero or negative");
  }
  if (hasLohSize) {
    if (lohSize <= 0) {
      rt::throw_exception<ArgumentOutOfRangeException>("lohSize", "lohSize can't be zero or negative");
    }
    if (lohSize > totalSize) {
      rt::throw_exception<ArgumentOutOfRangeException>("lohSize", "lohSize can't be greater than totalSize");
    }
  }
}

Boolean GC::TryStartNoGCRegion(Int64 totalSize) {
  return StartNoGCRegionWorker(totalSize, false, 0, false);
}

Boolean GC::TryStartNoGCRegion(Int64 totalSize, Int64 lohSize) {
  return StartNoGCRegionWorker(totalSize, true, lohSize, false);
}

Boolean GC::TryStartNoGCRegion(Int64 totalSize, Boolean disallowFullBlockingGC) {
  return StartNoGCRegionWorker(totalSize, false, 0, disallowFullBlockingGC);
}

Boolean GC::TryStartNoGCRegion(Int64 totalSize, Int64 lohSize, Boolean disallowFullBlockingGC) {
  return StartNoGCRegionWorker(totalSize, true, lohSize, disallowFullBlockingGC);
}

void GC::EndNoGCRegion() {
  switch (_EndNoGCRegion().get()) {
    case 1:
      rt::throw_exception<InvalidOperationException>("NoGCRegion mode must be set");
    case 2:
      rt::throw_exception<InvalidOperationException>("Garbage collection was induced in NoGCRegion mode");
    case 3:
      rt::throw_exception<InvalidOperationException>("Allocated memory exceeds specified memory for NoGCRegion mode");
  }
}

} // namespace System::Private::CoreLib::System::GCNamespace
