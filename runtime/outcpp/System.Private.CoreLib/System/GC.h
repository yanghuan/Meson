#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Single.h>

namespace System::Private::CoreLib::System::Collections::Generic {
FORWARD(List, T)
} // namespace System::Private::CoreLib::System::Collections::Generic
namespace System::Private::CoreLib::System {
FORWARD_(Action, T1, T2, T3, T4, T5, T6, T7, T8, T9)
FORWARDS(Int32)
FORWARDS(UInt64)
FORWARDS(UInt32)
FORWARDS(UIntPtr)
FORWARDS(GCMemoryInfo)
FORWARDS(Int64)
FORWARDS(Boolean)
FORWARDS(IntPtr)
FORWARD_(Array, T1, T2)
FORWARD(Object)
enum class GCCollectionMode;
FORWARD_(WeakReference, T1, T2)
enum class GCNotificationStatus;
namespace GCNamespace {
using namespace ::System::Private::CoreLib::System::Collections::Generic;
class GC {
  private: enum class StartNoGCRegionStatus {
    Succeeded = 0,
    NotEnoughMemory = 1,
    AmountTooLarge = 2,
    AlreadyInProgress = 3,
  };
  private: enum class EndNoGCRegionStatus {
    Succeeded = 0,
    NotInProgress = 1,
    GCInduced = 2,
    AllocationExceeded = 3,
  };
  private: struct MemoryLoadChangeNotification {
    private: Single LowMemoryPercent;
    private: Single HighMemoryPercent;
    private: Action<> Notification;
  };
  public: static Int32 get_MaxGeneration();
  public: static void GetMemoryInfo(UInt64& highMemLoadThresholdBytes, UInt64& totalAvailableMemoryBytes, UInt64& lastRecordedMemLoadBytes, UInt32& lastRecordedMemLoadPct, UIntPtr& lastRecordedHeapSizeBytes, UIntPtr& lastRecordedFragmentationBytes);
  public: static GCMemoryInfo GetGCMemoryInfo();
  public: static Int32 _StartNoGCRegion(Int64 totalSize, Boolean lohSizeKnown, Int64 lohSize, Boolean disallowFullBlockingGC);
  public: static Int32 _EndNoGCRegion();
  public: static Array<> AllocateNewArray(IntPtr typeHandle, Int32 length, Boolean zeroingOptional);
  private: static Int32 GetGenerationWR(IntPtr handle);
  private: static Int64 GetTotalMemory();
  private: static void _Collect(Int32 generation, Int32 mode);
  private: static Int32 GetMaxGeneration();
  private: static Int32 _CollectionCount(Int32 generation, Int32 getSpecialGCCount);
  public: static UInt64 GetSegmentSize();
  public: static Int32 GetLastGCPercentTimeInGC();
  public: static UInt64 GetGenerationSize(Int32 gen);
  private: static void _AddMemoryPressure(UInt64 bytesAllocated);
  private: static void _RemoveMemoryPressure(UInt64 bytesAllocated);
  public: static void AddMemoryPressure(Int64 bytesAllocated);
  public: static void RemoveMemoryPressure(Int64 bytesAllocated);
  public: static Int32 GetGeneration(Object obj);
  public: static void Collect(Int32 generation);
  public: static void Collect();
  public: static void Collect(Int32 generation, GCCollectionMode mode);
  public: static void Collect(Int32 generation, GCCollectionMode mode, Boolean blocking);
  public: static void Collect(Int32 generation, GCCollectionMode mode, Boolean blocking, Boolean compacting);
  public: static Int32 CollectionCount(Int32 generation);
  public: static void KeepAlive(Object obj);
  public: static Int32 GetGeneration(WeakReference<> wo);
  private: static void _WaitForPendingFinalizers();
  public: static void WaitForPendingFinalizers();
  private: static void _SuppressFinalize(Object o);
  public: static void SuppressFinalize(Object obj);
  private: static void _ReRegisterForFinalize(Object o);
  public: static void ReRegisterForFinalize(Object obj);
  public: static Int64 GetTotalMemory(Boolean forceFullCollection);
  private: static IntPtr _RegisterFrozenSegment(IntPtr sectionAddress, IntPtr sectionSize);
  private: static void _UnregisterFrozenSegment(IntPtr segmentHandle);
  public: static Int64 GetAllocatedBytesForCurrentThread();
  public: static Int64 GetTotalAllocatedBytes(Boolean precise);
  private: static Boolean _RegisterForFullGCNotification(Int32 maxGenerationPercentage, Int32 largeObjectHeapPercentage);
  private: static Boolean _CancelFullGCNotification();
  private: static Int32 _WaitForFullGCApproach(Int32 millisecondsTimeout);
  private: static Int32 _WaitForFullGCComplete(Int32 millisecondsTimeout);
  public: static void RegisterForFullGCNotification(Int32 maxGenerationThreshold, Int32 largeObjectHeapThreshold);
  public: static void CancelFullGCNotification();
  public: static GCNotificationStatus WaitForFullGCApproach();
  public: static GCNotificationStatus WaitForFullGCApproach(Int32 millisecondsTimeout);
  public: static GCNotificationStatus WaitForFullGCComplete();
  public: static GCNotificationStatus WaitForFullGCComplete(Int32 millisecondsTimeout);
  private: static Boolean StartNoGCRegionWorker(Int64 totalSize, Boolean hasLohSize, Int64 lohSize, Boolean disallowFullBlockingGC);
  public: static Boolean TryStartNoGCRegion(Int64 totalSize);
  public: static Boolean TryStartNoGCRegion(Int64 totalSize, Int64 lohSize);
  public: static Boolean TryStartNoGCRegion(Int64 totalSize, Boolean disallowFullBlockingGC);
  public: static Boolean TryStartNoGCRegion(Int64 totalSize, Int64 lohSize, Boolean disallowFullBlockingGC);
  private: static EndNoGCRegionStatus EndNoGCRegionWorker();
  public: static void EndNoGCRegion();
  private: static List<MemoryLoadChangeNotification> s_notifications;
  private: static Single s_previousMemoryLoad;
};
} // namespace GCNamespace
using GC = GCNamespace::GC;
} // namespace System::Private::CoreLib::System
