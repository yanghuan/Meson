#include "NativeRuntimeEventSource-dep.h"

#include <System.Private.CoreLib/System/Diagnostics/Tracing/EventPipePayloadDecoder-dep.h>
#include <System.Private.CoreLib/System/Diagnostics/Tracing/NativeRuntimeEventSource-dep.h>
#include <System.Private.CoreLib/System/Int32-dep.h>

namespace System::Private::CoreLib::System::Diagnostics::Tracing::NativeRuntimeEventSourceNamespace {
void NativeRuntimeEventSource___::ctor() {
}

void NativeRuntimeEventSource___::ProcessEvent(UInt32 eventID, UInt32 osThreadID, DateTime timeStamp, Guid activityId, Guid childActivityId, ReadOnlySpan<Byte> payload) {
  if (eventID < m_eventData->get_Length()) {
    Array<Object> args = EventPipePayloadDecoder::DecodePayload(m_eventData[eventID], payload);
    WriteToAllListeners((Int32)eventID, &osThreadID, &timeStamp, &activityId, &childActivityId, args);
  }
}

void NativeRuntimeEventSource___::GCStart_V2(UInt32 Count, UInt32 Depth, UInt32 Reason, UInt32 Type, UInt16 ClrInstanceID, UInt64 ClientSequenceNumber) {
  WriteEvent(1, rt::newarr<Array<Object>>(6, Count, Depth, Reason, Type, ClrInstanceID, ClientSequenceNumber));
}

void NativeRuntimeEventSource___::GCEnd_V1(UInt32 Count, UInt32 Depth, UInt16 ClrInstanceID) {
  WriteEvent(2, Count, Depth, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCRestartEEEnd_V1(UInt16 ClrInstanceID) {
  WriteEvent(3, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCHeapStats_V2(UInt64 GenerationSize0, UInt64 TotalPromotedSize0, UInt64 GenerationSize1, UInt64 TotalPromotedSize1, UInt64 GenerationSize2, UInt64 TotalPromotedSize2, UInt64 GenerationSize3, UInt64 TotalPromotedSize3, UInt64 FinalizationPromotedSize, UInt64 FinalizationPromotedCount, UInt32 PinnedObjectCount, UInt32 SinkBlockCount, UInt32 GCHandleCount, UInt16 ClrInstanceID, UInt64 GenerationSize4, UInt64 TotalPromotedSize4) {
  WriteEvent(4, rt::newarr<Array<Object>>(16, GenerationSize0, TotalPromotedSize0, GenerationSize1, TotalPromotedSize1, GenerationSize2, TotalPromotedSize2, GenerationSize3, TotalPromotedSize3, FinalizationPromotedSize, FinalizationPromotedCount, PinnedObjectCount, SinkBlockCount, GCHandleCount, ClrInstanceID, GenerationSize4, TotalPromotedSize4));
}

void NativeRuntimeEventSource___::GCCreateSegment_V1(UInt64 Address, UInt64 Size, UInt32 Type, UInt16 ClrInstanceID) {
  WriteEvent(5, rt::newarr<Array<Object>>(4, Address, Size, Type, ClrInstanceID));
}

void NativeRuntimeEventSource___::GCFreeSegment_V1(UInt64 Address, UInt16 ClrInstanceID) {
  WriteEvent(6, rt::newarr<Array<Object>>(2, Address, ClrInstanceID));
}

void NativeRuntimeEventSource___::GCRestartEEBegin_V1(UInt16 ClrInstanceID) {
  WriteEvent(7, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCSuspendEEEnd_V1(UInt16 ClrInstanceID) {
  WriteEvent(8, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCSuspendEEBegin_V1(UInt32 Reason, UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(9, Reason, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCAllocationTick_V3(UInt32 AllocationAmount, UInt32 AllocationKind, UInt16 ClrInstanceID, UInt64 AllocationAmount64, IntPtr TypeID, String TypeName, UInt32 HeapIndex, IntPtr Address) {
  WriteEvent(10, rt::newarr<Array<Object>>(8, AllocationAmount, AllocationKind, ClrInstanceID, AllocationAmount64, TypeID, TypeName, HeapIndex, Address));
}

void NativeRuntimeEventSource___::GCCreateConcurrentThread_V1(UInt16 ClrInstanceID) {
  WriteEvent(11, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCTerminateConcurrentThread_V1(UInt16 ClrInstanceID) {
  WriteEvent(12, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCFinalizersEnd_V1(UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(13, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCFinalizersBegin_V1(UInt16 ClrInstanceID) {
  WriteEvent(14, ClrInstanceID);
}

void NativeRuntimeEventSource___::BulkType(UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(15, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCBulkRootEdge(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(16, Index, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCBulkRootConditionalWeakTableElementEdge(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(17, Index, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCBulkNode(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(18, Index, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCBulkEdge(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(19, Index, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCSampledObjectAllocationHigh(IntPtr Address, IntPtr TypeID, UInt32 ObjectCountForTypeSample, UInt64 TotalSizeForTypeSample, UInt16 ClrInstanceID) {
  WriteEvent(20, rt::newarr<Array<Object>>(5, Address, TypeID, ObjectCountForTypeSample, TotalSizeForTypeSample, ClrInstanceID));
}

void NativeRuntimeEventSource___::GCBulkSurvivingObjectRanges(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(21, Index, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCBulkMovedObjectRanges(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(22, Index, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCGenerationRange(Byte Generation, IntPtr RangeStart, UInt64 RangeUsedLength, UInt64 RangeReservedLength, UInt16 ClrInstanceID) {
  WriteEvent(23, rt::newarr<Array<Object>>(5, Generation, RangeStart, RangeUsedLength, RangeReservedLength, ClrInstanceID));
}

void NativeRuntimeEventSource___::GCMarkStackRoots(UInt32 HeapNum, UInt16 ClrInstanceID) {
  WriteEvent(25, HeapNum, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCMarkFinalizeQueueRoots(UInt32 HeapNum, UInt16 ClrInstanceID) {
  WriteEvent(26, HeapNum, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCMarkHandles(UInt32 HeapNum, UInt16 ClrInstanceID) {
  WriteEvent(27, HeapNum, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCMarkOlderGenerationRoots(UInt32 HeapNum, UInt16 ClrInstanceID) {
  WriteEvent(28, HeapNum, ClrInstanceID);
}

void NativeRuntimeEventSource___::FinalizeObject(IntPtr TypeID, IntPtr ObjectID, UInt16 ClrInstanceID) {
  WriteEvent(29, rt::newarr<Array<Object>>(3, TypeID, ObjectID, ClrInstanceID));
}

void NativeRuntimeEventSource___::SetGCHandle(IntPtr HandleID, IntPtr ObjectID, UInt32 Kind, UInt32 Generation, UInt64 AppDomainID, UInt16 ClrInstanceID) {
  WriteEvent(30, rt::newarr<Array<Object>>(6, HandleID, ObjectID, Kind, Generation, AppDomainID, ClrInstanceID));
}

void NativeRuntimeEventSource___::DestroyGCHandle(IntPtr HandleID, UInt16 ClrInstanceID) {
  WriteEvent(31, rt::newarr<Array<Object>>(2, HandleID, ClrInstanceID));
}

void NativeRuntimeEventSource___::GCSampledObjectAllocationLow(IntPtr Address, IntPtr TypeID, UInt32 ObjectCountForTypeSample, UInt64 TotalSizeForTypeSample, UInt16 ClrInstanceID) {
  WriteEvent(32, rt::newarr<Array<Object>>(5, Address, TypeID, ObjectCountForTypeSample, TotalSizeForTypeSample, ClrInstanceID));
}

void NativeRuntimeEventSource___::PinObjectAtGCTime(IntPtr HandleID, IntPtr ObjectID, UInt64 ObjectSize, String TypeName, UInt16 ClrInstanceID) {
  WriteEvent(33, rt::newarr<Array<Object>>(5, HandleID, ObjectID, ObjectSize, TypeName, ClrInstanceID));
}

void NativeRuntimeEventSource___::GCTriggered(UInt32 Reason, UInt16 ClrInstanceID) {
  WriteEvent(35, Reason, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCBulkRootCCW(UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(36, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCBulkRCW(UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(37, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::GCBulkRootStaticVar(UInt32 Count, UInt64 AppDomainID, UInt16 ClrInstanceID) {
  WriteEvent(38, rt::newarr<Array<Object>>(3, Count, AppDomainID, ClrInstanceID));
}

void NativeRuntimeEventSource___::GCDynamicEvent(String Name, UInt32 DataSize) {
  WriteEvent(39, Name, DataSize);
}

void NativeRuntimeEventSource___::WorkerThreadCreate(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads) {
  WriteEvent(40, WorkerThreadCount, RetiredWorkerThreads);
}

void NativeRuntimeEventSource___::WorkerThreadTerminate(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads) {
  WriteEvent(41, WorkerThreadCount, RetiredWorkerThreads);
}

void NativeRuntimeEventSource___::WorkerThreadRetire(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads) {
  WriteEvent(42, WorkerThreadCount, RetiredWorkerThreads);
}

void NativeRuntimeEventSource___::WorkerThreadUnretire(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads) {
  WriteEvent(43, WorkerThreadCount, RetiredWorkerThreads);
}

void NativeRuntimeEventSource___::IOThreadCreate_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID) {
  WriteEvent(44, IOThreadCount, RetiredIOThreads, ClrInstanceID);
}

void NativeRuntimeEventSource___::IOThreadTerminate_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID) {
  WriteEvent(45, IOThreadCount, RetiredIOThreads, ClrInstanceID);
}

void NativeRuntimeEventSource___::IOThreadRetire_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID) {
  WriteEvent(46, IOThreadCount, RetiredIOThreads, ClrInstanceID);
}

void NativeRuntimeEventSource___::IOThreadUnretire_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID) {
  WriteEvent(47, IOThreadCount, RetiredIOThreads, ClrInstanceID);
}

void NativeRuntimeEventSource___::ThreadpoolSuspensionSuspendThread(UInt32 ClrThreadID, UInt32 CpuUtilization) {
  WriteEvent(48, ClrThreadID, CpuUtilization);
}

void NativeRuntimeEventSource___::ThreadpoolSuspensionResumeThread(UInt32 ClrThreadID, UInt32 CpuUtilization) {
  WriteEvent(49, ClrThreadID, CpuUtilization);
}

void NativeRuntimeEventSource___::ThreadPoolWorkerThreadStart(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID) {
  WriteEvent(50, ActiveWorkerThreadCount, RetiredWorkerThreadCount, ClrInstanceID);
}

void NativeRuntimeEventSource___::ThreadPoolWorkerThreadStop(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID) {
  WriteEvent(51, ActiveWorkerThreadCount, RetiredWorkerThreadCount, ClrInstanceID);
}

void NativeRuntimeEventSource___::ThreadPoolWorkerThreadRetirementStart(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID) {
  WriteEvent(52, ActiveWorkerThreadCount, RetiredWorkerThreadCount, ClrInstanceID);
}

void NativeRuntimeEventSource___::ThreadPoolWorkerThreadRetirementStop(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID) {
  WriteEvent(53, ActiveWorkerThreadCount, RetiredWorkerThreadCount, ClrInstanceID);
}

void NativeRuntimeEventSource___::ThreadPoolWorkerThreadAdjustmentSample(Double Throughput, UInt16 ClrInstanceID) {
  WriteEvent(54, rt::newarr<Array<Object>>(2, Throughput, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadPoolWorkerThreadAdjustmentAdjustment(Double AverageThroughput, UInt32 NewWorkerThreadCount, UInt32 Reason, UInt16 ClrInstanceID) {
  WriteEvent(55, rt::newarr<Array<Object>>(4, AverageThroughput, NewWorkerThreadCount, Reason, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadPoolWorkerThreadAdjustmentStats(Double Duration, Double Throughput, Double ThreadWave, Double ThroughputWave, Double ThroughputErrorEstimate, Double AverageThroughputErrorEstimate, Double ThroughputRatio, Double Confidence, Double NewControlSetting, UInt16 NewThreadWaveMagnitude, UInt16 ClrInstanceID) {
  WriteEvent(56, rt::newarr<Array<Object>>(11, Duration, Throughput, ThreadWave, ThroughputWave, ThroughputErrorEstimate, AverageThroughputErrorEstimate, ThroughputRatio, Confidence, NewControlSetting, NewThreadWaveMagnitude, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadPoolWorkerThreadWait(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID) {
  WriteEvent(57, ActiveWorkerThreadCount, RetiredWorkerThreadCount, ClrInstanceID);
}

void NativeRuntimeEventSource___::ThreadPoolWorkingThreadCount(UInt32 Count, UInt16 ClrInstanceID) {
  WriteEvent(60, Count, ClrInstanceID);
}

void NativeRuntimeEventSource___::ThreadPoolEnqueue(IntPtr WorkID, UInt16 ClrInstanceID) {
  WriteEvent(61, rt::newarr<Array<Object>>(2, WorkID, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadPoolDequeue(IntPtr WorkID, UInt16 ClrInstanceID) {
  WriteEvent(62, rt::newarr<Array<Object>>(2, WorkID, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadPoolIOEnqueue(IntPtr NativeOverlapped, IntPtr Overlapped, Boolean MultiDequeues, UInt16 ClrInstanceID) {
  WriteEvent(63, rt::newarr<Array<Object>>(4, NativeOverlapped, Overlapped, MultiDequeues, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadPoolIODequeue(IntPtr NativeOverlapped, IntPtr Overlapped, UInt16 ClrInstanceID) {
  WriteEvent(64, rt::newarr<Array<Object>>(3, NativeOverlapped, Overlapped, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadPoolIOPack(IntPtr NativeOverlapped, IntPtr Overlapped, UInt16 ClrInstanceID) {
  WriteEvent(65, rt::newarr<Array<Object>>(3, NativeOverlapped, Overlapped, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadCreating(IntPtr ID, UInt16 ClrInstanceID) {
  WriteEvent(70, rt::newarr<Array<Object>>(2, ID, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadRunning(IntPtr ID, UInt16 ClrInstanceID) {
  WriteEvent(71, rt::newarr<Array<Object>>(2, ID, ClrInstanceID));
}

void NativeRuntimeEventSource___::MethodDetails(UInt64 MethodID, UInt64 TypeID, UInt32 MethodToken, UInt32 TypeParameterCount, UInt64 LoaderModuleID) {
  WriteEvent(72, rt::newarr<Array<Object>>(5, MethodID, TypeID, MethodToken, TypeParameterCount, LoaderModuleID));
}

void NativeRuntimeEventSource___::ExceptionThrown_V1(String ExceptionType, String ExceptionMessage, IntPtr ExceptionEIP, UInt32 ExceptionHRESULT, UInt16 ExceptionFlags, UInt16 ClrInstanceID) {
  WriteEvent(80, rt::newarr<Array<Object>>(6, ExceptionType, ExceptionMessage, ExceptionEIP, ExceptionHRESULT, ExceptionFlags, ClrInstanceID));
}

void NativeRuntimeEventSource___::ExceptionCatchStart(UInt64 EntryEIP, UInt64 MethodID, String MethodName, UInt16 ClrInstanceID) {
  WriteEvent(250, rt::newarr<Array<Object>>(4, EntryEIP, MethodID, MethodName, ClrInstanceID));
}

void NativeRuntimeEventSource___::ExceptionCatchStop() {
  WriteEvent(251);
}

void NativeRuntimeEventSource___::ExceptionFinallyStart(UInt64 EntryEIP, UInt64 MethodID, String MethodName, UInt16 ClrInstanceID) {
  WriteEvent(252, rt::newarr<Array<Object>>(4, EntryEIP, MethodID, MethodName, ClrInstanceID));
}

void NativeRuntimeEventSource___::ExceptionFinallyStop() {
  WriteEvent(253);
}

void NativeRuntimeEventSource___::ExceptionFilterStart(UInt64 EntryEIP, UInt64 MethodID, String MethodName, UInt16 ClrInstanceID) {
  WriteEvent(254, rt::newarr<Array<Object>>(4, EntryEIP, MethodID, MethodName, ClrInstanceID));
}

void NativeRuntimeEventSource___::ExceptionFilterStop() {
  WriteEvent(255);
}

void NativeRuntimeEventSource___::ExceptionThrownStop() {
  WriteEvent(256);
}

void NativeRuntimeEventSource___::ContentionStart_V1(Byte ContentionFlags, UInt16 ClrInstanceID) {
  WriteEvent(81, ContentionFlags, ClrInstanceID);
}

void NativeRuntimeEventSource___::ContentionStop_V1(Byte ContentionFlags, UInt16 ClrInstanceID, Double DurationNs) {
  WriteEvent(91, rt::newarr<Array<Object>>(3, ContentionFlags, ClrInstanceID, DurationNs));
}

void NativeRuntimeEventSource___::CLRStackWalk(UInt16 ClrInstanceID, Byte Reserved1, Byte Reserved2, UInt32 FrameCount) {
  WriteEvent(82, rt::newarr<Array<Object>>(4, ClrInstanceID, Reserved1, Reserved2, FrameCount));
}

void NativeRuntimeEventSource___::AppDomainMemAllocated(UInt64 AppDomainID, UInt64 Allocated, UInt16 ClrInstanceID) {
  WriteEvent(83, rt::newarr<Array<Object>>(3, AppDomainID, Allocated, ClrInstanceID));
}

void NativeRuntimeEventSource___::AppDomainMemSurvived(UInt64 AppDomainID, UInt64 Survived, UInt64 ProcessSurvived, UInt16 ClrInstanceID) {
  WriteEvent(84, rt::newarr<Array<Object>>(4, AppDomainID, Survived, ProcessSurvived, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadCreated(UInt64 ManagedThreadID, UInt64 AppDomainID, UInt32 Flags, UInt32 ManagedThreadIndex, UInt32 OSThreadID, UInt16 ClrInstanceID) {
  WriteEvent(85, rt::newarr<Array<Object>>(6, ManagedThreadID, AppDomainID, Flags, ManagedThreadIndex, OSThreadID, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadTerminated(UInt64 ManagedThreadID, UInt64 AppDomainID, UInt16 ClrInstanceID) {
  WriteEvent(86, rt::newarr<Array<Object>>(3, ManagedThreadID, AppDomainID, ClrInstanceID));
}

void NativeRuntimeEventSource___::ThreadDomainEnter(UInt64 ManagedThreadID, UInt64 AppDomainID, UInt16 ClrInstanceID) {
  WriteEvent(87, rt::newarr<Array<Object>>(3, ManagedThreadID, AppDomainID, ClrInstanceID));
}

void NativeRuntimeEventSource___::ILStubGenerated(UInt16 ClrInstanceID, UInt64 ModuleID, UInt64 StubMethodID, UInt32 StubFlags, UInt32 ManagedInteropMethodToken, String ManagedInteropMethodNamespace, String ManagedInteropMethodName, String ManagedInteropMethodSignature, String NativeMethodSignature, String StubMethodSignature, String StubMethodILCode) {
  WriteEvent(88, rt::newarr<Array<Object>>(11, ClrInstanceID, ModuleID, StubMethodID, StubFlags, ManagedInteropMethodToken, ManagedInteropMethodNamespace, ManagedInteropMethodName, ManagedInteropMethodSignature, NativeMethodSignature, StubMethodSignature, StubMethodILCode));
}

void NativeRuntimeEventSource___::ILStubCacheHit(UInt16 ClrInstanceID, UInt64 ModuleID, UInt64 StubMethodID, UInt32 ManagedInteropMethodToken, String ManagedInteropMethodNamespace, String ManagedInteropMethodName, String ManagedInteropMethodSignature) {
  WriteEvent(89, rt::newarr<Array<Object>>(7, ClrInstanceID, ModuleID, StubMethodID, ManagedInteropMethodToken, ManagedInteropMethodNamespace, ManagedInteropMethodName, ManagedInteropMethodSignature));
}

void NativeRuntimeEventSource___::DCStartCompleteV2() {
  WriteEvent(135);
}

void NativeRuntimeEventSource___::DCEndCompleteV2() {
  WriteEvent(136);
}

void NativeRuntimeEventSource___::MethodDCStartV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags) {
  WriteEvent(137, rt::newarr<Array<Object>>(6, MethodID, ModuleID, MethodStartAddress, MethodSize, MethodToken, MethodFlags));
}

void NativeRuntimeEventSource___::MethodDCEndV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags) {
  WriteEvent(138, rt::newarr<Array<Object>>(6, MethodID, ModuleID, MethodStartAddress, MethodSize, MethodToken, MethodFlags));
}

void NativeRuntimeEventSource___::MethodDCStartVerboseV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature) {
  WriteEvent(139, rt::newarr<Array<Object>>(9, MethodID, ModuleID, MethodStartAddress, MethodSize, MethodToken, MethodFlags, MethodNamespace, MethodName, MethodSignature));
}

void NativeRuntimeEventSource___::MethodDCEndVerboseV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature) {
  WriteEvent(140, rt::newarr<Array<Object>>(9, MethodID, ModuleID, MethodStartAddress, MethodSize, MethodToken, MethodFlags, MethodNamespace, MethodName, MethodSignature));
}

void NativeRuntimeEventSource___::MethodLoad_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, UInt16 ClrInstanceID, UInt64 ReJITID) {
  WriteEvent(141, rt::newarr<Array<Object>>(8, MethodID, ModuleID, MethodStartAddress, MethodSize, MethodToken, MethodFlags, ClrInstanceID, ReJITID));
}

void NativeRuntimeEventSource___::R2RGetEntryPoint(UInt64 MethodID, String MethodNamespace, String MethodName, String MethodSignature, UInt64 EntryPoint, UInt16 ClrInstanceID) {
  WriteEvent(159, rt::newarr<Array<Object>>(6, MethodID, MethodNamespace, MethodName, MethodSignature, EntryPoint, ClrInstanceID));
}

void NativeRuntimeEventSource___::MethodUnload_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, UInt16 ClrInstanceID, UInt64 ReJITID) {
  WriteEvent(142, rt::newarr<Array<Object>>(8, MethodID, ModuleID, MethodStartAddress, MethodSize, MethodToken, MethodFlags, ClrInstanceID, ReJITID));
}

void NativeRuntimeEventSource___::MethodLoadVerbose_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature, UInt16 ClrInstanceID, UInt64 ReJITID) {
  WriteEvent(143, rt::newarr<Array<Object>>(11, MethodID, ModuleID, MethodStartAddress, MethodSize, MethodToken, MethodFlags, MethodNamespace, MethodName, MethodSignature, ClrInstanceID, ReJITID));
}

void NativeRuntimeEventSource___::MethodUnloadVerbose_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature, UInt16 ClrInstanceID, UInt64 ReJITID) {
  WriteEvent(144, rt::newarr<Array<Object>>(11, MethodID, ModuleID, MethodStartAddress, MethodSize, MethodToken, MethodFlags, MethodNamespace, MethodName, MethodSignature, ClrInstanceID, ReJITID));
}

void NativeRuntimeEventSource___::MethodJittingStarted_V1(UInt64 MethodID, UInt64 ModuleID, UInt32 MethodToken, UInt32 MethodILSize, String MethodNamespace, String MethodName, String MethodSignature, UInt16 ClrInstanceID) {
  WriteEvent(145, rt::newarr<Array<Object>>(8, MethodID, ModuleID, MethodToken, MethodILSize, MethodNamespace, MethodName, MethodSignature, ClrInstanceID));
}

void NativeRuntimeEventSource___::MethodJitInliningSucceeded(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String InlinerNamespace, String InlinerName, String InlinerNameSignature, String InlineeNamespace, String InlineeName, String InlineeNameSignature, UInt16 ClrInstanceID) {
  WriteEvent(185, rt::newarr<Array<Object>>(10, MethodBeingCompiledNamespace, MethodBeingCompiledName, MethodBeingCompiledNameSignature, InlinerNamespace, InlinerName, InlinerNameSignature, InlineeNamespace, InlineeName, InlineeNameSignature, ClrInstanceID));
}

void NativeRuntimeEventSource___::MethodJitInliningFailedAnsi(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String InlinerNamespace, String InlinerName, String InlinerNameSignature, String InlineeNamespace, String InlineeName, String InlineeNameSignature, Boolean FailAlways) {
  WriteEvent(186, rt::newarr<Array<Object>>(10, MethodBeingCompiledNamespace, MethodBeingCompiledName, MethodBeingCompiledNameSignature, InlinerNamespace, InlinerName, InlinerNameSignature, InlineeNamespace, InlineeName, InlineeNameSignature, FailAlways));
}

void NativeRuntimeEventSource___::MethodJitTailCallSucceeded(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String CallerNamespace, String CallerName, String CallerNameSignature, String CalleeNamespace, String CalleeName, String CalleeNameSignature, Boolean TailPrefix, UInt32 TailCallType, UInt16 ClrInstanceID) {
  WriteEvent(188, rt::newarr<Array<Object>>(12, MethodBeingCompiledNamespace, MethodBeingCompiledName, MethodBeingCompiledNameSignature, CallerNamespace, CallerName, CallerNameSignature, CalleeNamespace, CalleeName, CalleeNameSignature, TailPrefix, TailCallType, ClrInstanceID));
}

void NativeRuntimeEventSource___::MethodJitTailCallFailedAnsi(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String CallerNamespace, String CallerName, String CallerNameSignature, String CalleeNamespace, String CalleeName, String CalleeNameSignature, Boolean TailPrefix) {
  WriteEvent(189, rt::newarr<Array<Object>>(10, MethodBeingCompiledNamespace, MethodBeingCompiledName, MethodBeingCompiledNameSignature, CallerNamespace, CallerName, CallerNameSignature, CalleeNamespace, CalleeName, CalleeNameSignature, TailPrefix));
}

void NativeRuntimeEventSource___::MethodILToNativeMap(UInt64 MethodID, UInt64 ReJITID, Byte MethodExtent, UInt16 CountOfMapEntries) {
  WriteEvent(190, rt::newarr<Array<Object>>(4, MethodID, ReJITID, MethodExtent, CountOfMapEntries));
}

void NativeRuntimeEventSource___::MethodJitTailCallFailed(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String CallerNamespace, String CallerName, String CallerNameSignature, String CalleeNamespace, String CalleeName, String CalleeNameSignature, Boolean TailPrefix, String FailReason, UInt16 ClrInstanceID) {
  WriteEvent(191, rt::newarr<Array<Object>>(12, MethodBeingCompiledNamespace, MethodBeingCompiledName, MethodBeingCompiledNameSignature, CallerNamespace, CallerName, CallerNameSignature, CalleeNamespace, CalleeName, CalleeNameSignature, TailPrefix, FailReason, ClrInstanceID));
}

void NativeRuntimeEventSource___::MethodJitInliningFailed(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String InlinerNamespace, String InlinerName, String InlinerNameSignature, String InlineeNamespace, String InlineeName, String InlineeNameSignature, Boolean FailAlways, String FailReason, UInt16 ClrInstanceID) {
  WriteEvent(192, rt::newarr<Array<Object>>(12, MethodBeingCompiledNamespace, MethodBeingCompiledName, MethodBeingCompiledNameSignature, InlinerNamespace, InlinerName, InlinerNameSignature, InlineeNamespace, InlineeName, InlineeNameSignature, FailAlways, FailReason, ClrInstanceID));
}

void NativeRuntimeEventSource___::ModuleDCStartV2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath) {
  WriteEvent(149, rt::newarr<Array<Object>>(6, ModuleID, AssemblyID, ModuleFlags, Reserved1, ModuleILPath, ModuleNativePath));
}

void NativeRuntimeEventSource___::ModuleDCEndV2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath) {
  WriteEvent(150, rt::newarr<Array<Object>>(6, ModuleID, AssemblyID, ModuleFlags, Reserved1, ModuleILPath, ModuleNativePath));
}

void NativeRuntimeEventSource___::DomainModuleLoad_V1(UInt64 ModuleID, UInt64 AssemblyID, UInt64 AppDomainID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath, UInt16 ClrInstanceID) {
  WriteEvent(151, rt::newarr<Array<Object>>(8, ModuleID, AssemblyID, AppDomainID, ModuleFlags, Reserved1, ModuleILPath, ModuleNativePath, ClrInstanceID));
}

void NativeRuntimeEventSource___::ModuleLoad_V2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath, UInt16 ClrInstanceID, Guid ManagedPdbSignature, UInt32 ManagedPdbAge, String ManagedPdbBuildPath, Guid NativePdbSignature, UInt32 NativePdbAge, String NativePdbBuildPath) {
  WriteEvent(152, rt::newarr<Array<Object>>(13, ModuleID, AssemblyID, ModuleFlags, Reserved1, ModuleILPath, ModuleNativePath, ClrInstanceID, ManagedPdbSignature, ManagedPdbAge, ManagedPdbBuildPath, NativePdbSignature, NativePdbAge, NativePdbBuildPath));
}

void NativeRuntimeEventSource___::ModuleUnload_V2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath, UInt16 ClrInstanceID, Guid ManagedPdbSignature, UInt32 ManagedPdbAge, String ManagedPdbBuildPath, Guid NativePdbSignature, UInt32 NativePdbAge, String NativePdbBuildPath) {
  WriteEvent(153, rt::newarr<Array<Object>>(13, ModuleID, AssemblyID, ModuleFlags, Reserved1, ModuleILPath, ModuleNativePath, ClrInstanceID, ManagedPdbSignature, ManagedPdbAge, ManagedPdbBuildPath, NativePdbSignature, NativePdbAge, NativePdbBuildPath));
}

void NativeRuntimeEventSource___::AssemblyLoad_V1(UInt64 AssemblyID, UInt64 AppDomainID, UInt64 BindingID, UInt32 AssemblyFlags, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID) {
  WriteEvent(154, rt::newarr<Array<Object>>(6, AssemblyID, AppDomainID, BindingID, AssemblyFlags, FullyQualifiedAssemblyName, ClrInstanceID));
}

void NativeRuntimeEventSource___::AssemblyUnload_V1(UInt64 AssemblyID, UInt64 AppDomainID, UInt64 BindingID, UInt32 AssemblyFlags, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID) {
  WriteEvent(155, rt::newarr<Array<Object>>(6, AssemblyID, AppDomainID, BindingID, AssemblyFlags, FullyQualifiedAssemblyName, ClrInstanceID));
}

void NativeRuntimeEventSource___::AppDomainLoad_V1(UInt64 AppDomainID, UInt32 AppDomainFlags, String AppDomainName, UInt32 AppDomainIndex, UInt16 ClrInstanceID) {
  WriteEvent(156, rt::newarr<Array<Object>>(5, AppDomainID, AppDomainFlags, AppDomainName, AppDomainIndex, ClrInstanceID));
}

void NativeRuntimeEventSource___::AppDomainUnload_V1(UInt64 AppDomainID, UInt32 AppDomainFlags, String AppDomainName, UInt32 AppDomainIndex, UInt16 ClrInstanceID) {
  WriteEvent(157, rt::newarr<Array<Object>>(5, AppDomainID, AppDomainFlags, AppDomainName, AppDomainIndex, ClrInstanceID));
}

void NativeRuntimeEventSource___::ModuleRangeLoad(UInt16 ClrInstanceID, UInt64 ModuleID, UInt32 RangeBegin, UInt32 RangeSize, Byte RangeType) {
  WriteEvent(158, rt::newarr<Array<Object>>(5, ClrInstanceID, ModuleID, RangeBegin, RangeSize, RangeType));
}

void NativeRuntimeEventSource___::StrongNameVerificationStart_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID) {
  WriteEvent(181, rt::newarr<Array<Object>>(4, VerificationFlags, ErrorCode, FullyQualifiedAssemblyName, ClrInstanceID));
}

void NativeRuntimeEventSource___::StrongNameVerificationStop_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID) {
  WriteEvent(182, rt::newarr<Array<Object>>(4, VerificationFlags, ErrorCode, FullyQualifiedAssemblyName, ClrInstanceID));
}

void NativeRuntimeEventSource___::AuthenticodeVerificationStart_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String ModulePath, UInt16 ClrInstanceID) {
  WriteEvent(183, rt::newarr<Array<Object>>(4, VerificationFlags, ErrorCode, ModulePath, ClrInstanceID));
}

void NativeRuntimeEventSource___::AuthenticodeVerificationStop_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String ModulePath, UInt16 ClrInstanceID) {
  WriteEvent(184, rt::newarr<Array<Object>>(4, VerificationFlags, ErrorCode, ModulePath, ClrInstanceID));
}

void NativeRuntimeEventSource___::RuntimeInformationStart(UInt16 ClrInstanceID, UInt16 Sku, UInt16 BclMajorVersion, UInt16 BclMinorVersion, UInt16 BclBuildNumber, UInt16 BclQfeNumber, UInt16 VMMajorVersion, UInt16 VMMinorVersion, UInt16 VMBuildNumber, UInt16 VMQfeNumber, UInt32 StartupFlags, Byte StartupMode, String CommandLine, Guid ComObjectGuid, String RuntimeDllPath) {
  WriteEvent(187, rt::newarr<Array<Object>>(15, ClrInstanceID, Sku, BclMajorVersion, BclMinorVersion, BclBuildNumber, BclQfeNumber, VMMajorVersion, VMMinorVersion, VMBuildNumber, VMQfeNumber, StartupFlags, StartupMode, CommandLine, ComObjectGuid, RuntimeDllPath));
}

void NativeRuntimeEventSource___::IncreaseMemoryPressure(UInt64 BytesAllocated, UInt16 ClrInstanceID) {
  WriteEvent(200, rt::newarr<Array<Object>>(2, BytesAllocated, ClrInstanceID));
}

void NativeRuntimeEventSource___::DecreaseMemoryPressure(UInt64 BytesFreed, UInt16 ClrInstanceID) {
  WriteEvent(201, rt::newarr<Array<Object>>(2, BytesFreed, ClrInstanceID));
}

void NativeRuntimeEventSource___::GCMarkWithType(UInt32 HeapNum, UInt16 ClrInstanceID, UInt32 Type, UInt64 Bytes) {
  WriteEvent(202, rt::newarr<Array<Object>>(4, HeapNum, ClrInstanceID, Type, Bytes));
}

void NativeRuntimeEventSource___::GCJoin_V2(UInt32 Heap, UInt32 JoinTime, UInt32 JoinType, UInt16 ClrInstanceID, UInt32 JoinID) {
  WriteEvent(203, rt::newarr<Array<Object>>(5, Heap, JoinTime, JoinType, ClrInstanceID, JoinID));
}

void NativeRuntimeEventSource___::GCPerHeapHistory_V3(UInt16 ClrInstanceID, IntPtr FreeListAllocated, IntPtr FreeListRejected, IntPtr EndOfSegAllocated, IntPtr CondemnedAllocated, IntPtr PinnedAllocated, IntPtr PinnedAllocatedAdvance, UInt32 RunningFreeListEfficiency, UInt32 CondemnReasons0, UInt32 CondemnReasons1, UInt32 CompactMechanisms, UInt32 ExpandMechanisms, UInt32 HeapIndex, IntPtr ExtraGen0Commit, UInt32 Count) {
  WriteEvent(204, rt::newarr<Array<Object>>(15, ClrInstanceID, FreeListAllocated, FreeListRejected, EndOfSegAllocated, CondemnedAllocated, PinnedAllocated, PinnedAllocatedAdvance, RunningFreeListEfficiency, CondemnReasons0, CondemnReasons1, CompactMechanisms, ExpandMechanisms, HeapIndex, ExtraGen0Commit, Count));
}

void NativeRuntimeEventSource___::GCGlobalHeapHistory_V3(UInt64 FinalYoungestDesired, Int32 NumHeaps, UInt32 CondemnedGeneration, UInt32 Gen0ReductionCount, UInt32 Reason, UInt32 GlobalMechanisms, UInt16 ClrInstanceID, UInt32 PauseMode, UInt32 MemoryPressure, UInt32 CondemnReasons0, UInt32 CondemnReasons1) {
  WriteEvent(205, rt::newarr<Array<Object>>(11, FinalYoungestDesired, NumHeaps, CondemnedGeneration, Gen0ReductionCount, Reason, GlobalMechanisms, ClrInstanceID, PauseMode, MemoryPressure, CondemnReasons0, CondemnReasons1));
}

void NativeRuntimeEventSource___::DebugIPCEventStart() {
  WriteEvent(240);
}

void NativeRuntimeEventSource___::DebugIPCEventEnd() {
  WriteEvent(241);
}

void NativeRuntimeEventSource___::DebugExceptionProcessingStart() {
  WriteEvent(242);
}

void NativeRuntimeEventSource___::DebugExceptionProcessingEnd() {
  WriteEvent(243);
}

void NativeRuntimeEventSource___::CodeSymbols(UInt64 ModuleId, UInt16 TotalChunks, UInt16 ChunkNumber, UInt32 ChunkLength) {
  WriteEvent(260, rt::newarr<Array<Object>>(4, ModuleId, TotalChunks, ChunkNumber, ChunkLength));
}

void NativeRuntimeEventSource___::EventSource(Int32 EventID, String EventName, String EventSourceName, String Payload) {
  WriteEvent(270, rt::newarr<Array<Object>>(4, EventID, EventName, EventSourceName, Payload));
}

void NativeRuntimeEventSource___::TieredCompilationSettings(UInt16 ClrInstanceID, UInt32 Flags) {
  WriteEvent(280, ClrInstanceID, Flags);
}

void NativeRuntimeEventSource___::TieredCompilationPause(UInt16 ClrInstanceID) {
  WriteEvent(281, ClrInstanceID);
}

void NativeRuntimeEventSource___::TieredCompilationResume(UInt16 ClrInstanceID, UInt32 NewMethodCount) {
  WriteEvent(282, ClrInstanceID, NewMethodCount);
}

void NativeRuntimeEventSource___::TieredCompilationBackgroundJitStart(UInt16 ClrInstanceID, UInt32 PendingMethodCount) {
  WriteEvent(283, ClrInstanceID, PendingMethodCount);
}

void NativeRuntimeEventSource___::TieredCompilationBackgroundJitStop(UInt16 ClrInstanceID, UInt32 PendingMethodCount, UInt32 JittedMethodCount) {
  WriteEvent(284, ClrInstanceID, PendingMethodCount, JittedMethodCount);
}

void NativeRuntimeEventSource___::AssemblyLoadStart(UInt16 ClrInstanceID, String AssemblyName, String AssemblyPath, String RequestingAssembly, String AssemblyLoadContext, String RequestingAssemblyLoadContext) {
  WriteEvent(290, rt::newarr<Array<Object>>(6, ClrInstanceID, AssemblyName, AssemblyPath, RequestingAssembly, AssemblyLoadContext, RequestingAssemblyLoadContext));
}

void NativeRuntimeEventSource___::AssemblyLoadStop(UInt16 ClrInstanceID, String AssemblyName, String AssemblyPath, String RequestingAssembly, String AssemblyLoadContext, String RequestingAssemblyLoadContext, Boolean Success, String ResultAssemblyName, String ResultAssemblyPath, Boolean Cached) {
  WriteEvent(291, rt::newarr<Array<Object>>(10, ClrInstanceID, AssemblyName, AssemblyPath, RequestingAssembly, AssemblyLoadContext, RequestingAssemblyLoadContext, Success, ResultAssemblyName, ResultAssemblyPath, Cached));
}

void NativeRuntimeEventSource___::ResolutionAttempted(UInt16 ClrInstanceID, String AssemblyName, UInt16 Stage, String AssemblyLoadContext, UInt16 Result, String ResultAssemblyName, String ResultAssemblyPath, String ErrorMessage) {
  WriteEvent(292, rt::newarr<Array<Object>>(8, ClrInstanceID, AssemblyName, Stage, AssemblyLoadContext, Result, ResultAssemblyName, ResultAssemblyPath, ErrorMessage));
}

void NativeRuntimeEventSource___::AssemblyLoadContextResolvingHandlerInvoked(UInt16 ClrInstanceID, String AssemblyName, String HandlerName, String AssemblyLoadContext, String ResultAssemblyName, String ResultAssemblyPath) {
  WriteEvent(293, rt::newarr<Array<Object>>(6, ClrInstanceID, AssemblyName, HandlerName, AssemblyLoadContext, ResultAssemblyName, ResultAssemblyPath));
}

void NativeRuntimeEventSource___::AppDomainAssemblyResolveHandlerInvoked(UInt16 ClrInstanceID, String AssemblyName, String HandlerName, String ResultAssemblyName, String ResultAssemblyPath) {
  WriteEvent(294, rt::newarr<Array<Object>>(5, ClrInstanceID, AssemblyName, HandlerName, ResultAssemblyName, ResultAssemblyPath));
}

void NativeRuntimeEventSource___::AssemblyLoadFromResolveHandlerInvoked(UInt16 ClrInstanceID, String AssemblyName, Boolean IsTrackedLoad, String RequestingAssemblyPath, String ComputedRequestedAssemblyPath) {
  WriteEvent(295, rt::newarr<Array<Object>>(5, ClrInstanceID, AssemblyName, IsTrackedLoad, RequestingAssemblyPath, ComputedRequestedAssemblyPath));
}

void NativeRuntimeEventSource___::KnownPathProbed(UInt16 ClrInstanceID, String FilePath, UInt16 Source, Int32 Result) {
  WriteEvent(296, rt::newarr<Array<Object>>(4, ClrInstanceID, FilePath, Source, Result));
}

void NativeRuntimeEventSource___::cctor() {
  Log = rt::newobj<NativeRuntimeEventSource>();
}

} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::NativeRuntimeEventSourceNamespace
