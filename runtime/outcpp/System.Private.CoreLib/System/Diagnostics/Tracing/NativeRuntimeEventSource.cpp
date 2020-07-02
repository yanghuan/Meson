#include "NativeRuntimeEventSource-dep.h"

namespace System::Private::CoreLib::System::Diagnostics::Tracing::NativeRuntimeEventSourceNamespace {
void NativeRuntimeEventSource___::ProcessEvent(UInt32 eventID, UInt32 osThreadID, DateTime timeStamp, Guid activityId, Guid childActivityId, ReadOnlySpan<Byte> payload) {
  return void();
};
void NativeRuntimeEventSource___::GCStart_V2(UInt32 Count, UInt32 Depth, UInt32 Reason, UInt32 Type, UInt16 ClrInstanceID, UInt64 ClientSequenceNumber) {
  return void();
};
void NativeRuntimeEventSource___::GCEnd_V1(UInt32 Count, UInt32 Depth, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCRestartEEEnd_V1(UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCHeapStats_V1(UInt64 GenerationSize0, UInt64 TotalPromotedSize0, UInt64 GenerationSize1, UInt64 TotalPromotedSize1, UInt64 GenerationSize2, UInt64 TotalPromotedSize2, UInt64 GenerationSize3, UInt64 TotalPromotedSize3, UInt64 FinalizationPromotedSize, UInt64 FinalizationPromotedCount, UInt32 PinnedObjectCount, UInt32 SinkBlockCount, UInt32 GCHandleCount, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCCreateSegment_V1(UInt64 Address, UInt64 Size, UInt32 Type, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCFreeSegment_V1(UInt64 Address, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCRestartEEBegin_V1(UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCSuspendEEEnd_V1(UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCSuspendEEBegin_V1(UInt32 Reason, UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCAllocationTick_V3(UInt32 AllocationAmount, UInt32 AllocationKind, UInt16 ClrInstanceID, UInt64 AllocationAmount64, IntPtr TypeID, String TypeName, UInt32 HeapIndex, IntPtr Address) {
  return void();
};
void NativeRuntimeEventSource___::GCCreateConcurrentThread_V1(UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCTerminateConcurrentThread_V1(UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCFinalizersEnd_V1(UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCFinalizersBegin_V1(UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::BulkType(UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCBulkRootEdge(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCBulkRootConditionalWeakTableElementEdge(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCBulkNode(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCBulkEdge(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCSampledObjectAllocationHigh(IntPtr Address, IntPtr TypeID, UInt32 ObjectCountForTypeSample, UInt64 TotalSizeForTypeSample, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCBulkSurvivingObjectRanges(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCBulkMovedObjectRanges(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCGenerationRange(Byte Generation, IntPtr RangeStart, UInt64 RangeUsedLength, UInt64 RangeReservedLength, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCMarkStackRoots(UInt32 HeapNum, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCMarkFinalizeQueueRoots(UInt32 HeapNum, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCMarkHandles(UInt32 HeapNum, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCMarkOlderGenerationRoots(UInt32 HeapNum, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::FinalizeObject(IntPtr TypeID, IntPtr ObjectID, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::SetGCHandle(IntPtr HandleID, IntPtr ObjectID, UInt32 Kind, UInt32 Generation, UInt64 AppDomainID, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::DestroyGCHandle(IntPtr HandleID, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCSampledObjectAllocationLow(IntPtr Address, IntPtr TypeID, UInt32 ObjectCountForTypeSample, UInt64 TotalSizeForTypeSample, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::PinObjectAtGCTime(IntPtr HandleID, IntPtr ObjectID, UInt64 ObjectSize, String TypeName, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCTriggered(UInt32 Reason, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCBulkRootCCW(UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCBulkRCW(UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCBulkRootStaticVar(UInt32 Count, UInt64 AppDomainID, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCDynamicEvent(String Name, UInt32 DataSize) {
  return void();
};
void NativeRuntimeEventSource___::WorkerThreadCreate(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads) {
  return void();
};
void NativeRuntimeEventSource___::WorkerThreadTerminate(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads) {
  return void();
};
void NativeRuntimeEventSource___::WorkerThreadRetire(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads) {
  return void();
};
void NativeRuntimeEventSource___::WorkerThreadUnretire(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads) {
  return void();
};
void NativeRuntimeEventSource___::IOThreadCreate_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::IOThreadTerminate_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::IOThreadRetire_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::IOThreadUnretire_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadpoolSuspensionSuspendThread(UInt32 ClrThreadID, UInt32 CpuUtilization) {
  return void();
};
void NativeRuntimeEventSource___::ThreadpoolSuspensionResumeThread(UInt32 ClrThreadID, UInt32 CpuUtilization) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolWorkerThreadStart(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolWorkerThreadStop(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolWorkerThreadRetirementStart(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolWorkerThreadRetirementStop(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolWorkerThreadAdjustmentSample(Double Throughput, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolWorkerThreadAdjustmentAdjustment(Double AverageThroughput, UInt32 NewWorkerThreadCount, UInt32 Reason, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolWorkerThreadAdjustmentStats(Double Duration, Double Throughput, Double ThreadWave, Double ThroughputWave, Double ThroughputErrorEstimate, Double AverageThroughputErrorEstimate, Double ThroughputRatio, Double Confidence, Double NewControlSetting, UInt16 NewThreadWaveMagnitude, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolWorkerThreadWait(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolWorkingThreadCount(UInt32 Count, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolEnqueue(IntPtr WorkID, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolDequeue(IntPtr WorkID, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolIOEnqueue(IntPtr NativeOverlapped, IntPtr Overlapped, Boolean MultiDequeues, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolIODequeue(IntPtr NativeOverlapped, IntPtr Overlapped, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadPoolIOPack(IntPtr NativeOverlapped, IntPtr Overlapped, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadCreating(IntPtr ID, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadRunning(IntPtr ID, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ExceptionThrown_V1(String ExceptionType, String ExceptionMessage, IntPtr ExceptionEIP, UInt32 ExceptionHRESULT, UInt16 ExceptionFlags, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ExceptionCatchStart(UInt64 EntryEIP, UInt64 MethodID, String MethodName, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ExceptionCatchStop() {
  return void();
};
void NativeRuntimeEventSource___::ExceptionFinallyStart(UInt64 EntryEIP, UInt64 MethodID, String MethodName, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ExceptionFinallyStop() {
  return void();
};
void NativeRuntimeEventSource___::ExceptionFilterStart(UInt64 EntryEIP, UInt64 MethodID, String MethodName, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ExceptionFilterStop() {
  return void();
};
void NativeRuntimeEventSource___::ExceptionThrownStop() {
  return void();
};
void NativeRuntimeEventSource___::ContentionStart_V1(Byte ContentionFlags, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ContentionStop_V1(Byte ContentionFlags, UInt16 ClrInstanceID, Double DurationNs) {
  return void();
};
void NativeRuntimeEventSource___::CLRStackWalk(UInt16 ClrInstanceID, Byte Reserved1, Byte Reserved2, UInt32 FrameCount) {
  return void();
};
void NativeRuntimeEventSource___::AppDomainMemAllocated(UInt64 AppDomainID, UInt64 Allocated, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::AppDomainMemSurvived(UInt64 AppDomainID, UInt64 Survived, UInt64 ProcessSurvived, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadCreated(UInt64 ManagedThreadID, UInt64 AppDomainID, UInt32 Flags, UInt32 ManagedThreadIndex, UInt32 OSThreadID, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadTerminated(UInt64 ManagedThreadID, UInt64 AppDomainID, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ThreadDomainEnter(UInt64 ManagedThreadID, UInt64 AppDomainID, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ILStubGenerated(UInt16 ClrInstanceID, UInt64 ModuleID, UInt64 StubMethodID, UInt32 StubFlags, UInt32 ManagedInteropMethodToken, String ManagedInteropMethodNamespace, String ManagedInteropMethodName, String ManagedInteropMethodSignature, String NativeMethodSignature, String StubMethodSignature, String StubMethodILCode) {
  return void();
};
void NativeRuntimeEventSource___::ILStubCacheHit(UInt16 ClrInstanceID, UInt64 ModuleID, UInt64 StubMethodID, UInt32 ManagedInteropMethodToken, String ManagedInteropMethodNamespace, String ManagedInteropMethodName, String ManagedInteropMethodSignature) {
  return void();
};
void NativeRuntimeEventSource___::DCStartCompleteV2() {
  return void();
};
void NativeRuntimeEventSource___::DCEndCompleteV2() {
  return void();
};
void NativeRuntimeEventSource___::MethodDCStartV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags) {
  return void();
};
void NativeRuntimeEventSource___::MethodDCEndV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags) {
  return void();
};
void NativeRuntimeEventSource___::MethodDCStartVerboseV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature) {
  return void();
};
void NativeRuntimeEventSource___::MethodDCEndVerboseV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature) {
  return void();
};
void NativeRuntimeEventSource___::MethodLoad_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, UInt16 ClrInstanceID, UInt64 ReJITID) {
  return void();
};
void NativeRuntimeEventSource___::R2RGetEntryPoint(UInt64 MethodID, String MethodNamespace, String MethodName, String MethodSignature, UInt64 EntryPoint, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::MethodUnload_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, UInt16 ClrInstanceID, UInt64 ReJITID) {
  return void();
};
void NativeRuntimeEventSource___::MethodLoadVerbose_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature, UInt16 ClrInstanceID, UInt64 ReJITID) {
  return void();
};
void NativeRuntimeEventSource___::MethodUnloadVerbose_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature, UInt16 ClrInstanceID, UInt64 ReJITID) {
  return void();
};
void NativeRuntimeEventSource___::MethodJittingStarted_V1(UInt64 MethodID, UInt64 ModuleID, UInt32 MethodToken, UInt32 MethodILSize, String MethodNamespace, String MethodName, String MethodSignature, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::MethodJitInliningSucceeded(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String InlinerNamespace, String InlinerName, String InlinerNameSignature, String InlineeNamespace, String InlineeName, String InlineeNameSignature, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::MethodJitInliningFailedAnsi(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String InlinerNamespace, String InlinerName, String InlinerNameSignature, String InlineeNamespace, String InlineeName, String InlineeNameSignature, Boolean FailAlways) {
  return void();
};
void NativeRuntimeEventSource___::MethodJitTailCallSucceeded(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String CallerNamespace, String CallerName, String CallerNameSignature, String CalleeNamespace, String CalleeName, String CalleeNameSignature, Boolean TailPrefix, UInt32 TailCallType, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::MethodJitTailCallFailedAnsi(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String CallerNamespace, String CallerName, String CallerNameSignature, String CalleeNamespace, String CalleeName, String CalleeNameSignature, Boolean TailPrefix) {
  return void();
};
void NativeRuntimeEventSource___::MethodILToNativeMap(UInt64 MethodID, UInt64 ReJITID, Byte MethodExtent, UInt16 CountOfMapEntries) {
  return void();
};
void NativeRuntimeEventSource___::MethodJitTailCallFailed(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String CallerNamespace, String CallerName, String CallerNameSignature, String CalleeNamespace, String CalleeName, String CalleeNameSignature, Boolean TailPrefix, String FailReason, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::MethodJitInliningFailed(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String InlinerNamespace, String InlinerName, String InlinerNameSignature, String InlineeNamespace, String InlineeName, String InlineeNameSignature, Boolean FailAlways, String FailReason, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ModuleDCStartV2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath) {
  return void();
};
void NativeRuntimeEventSource___::ModuleDCEndV2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath) {
  return void();
};
void NativeRuntimeEventSource___::DomainModuleLoad_V1(UInt64 ModuleID, UInt64 AssemblyID, UInt64 AppDomainID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ModuleLoad_V2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath, UInt16 ClrInstanceID, Guid ManagedPdbSignature, UInt32 ManagedPdbAge, String ManagedPdbBuildPath, Guid NativePdbSignature, UInt32 NativePdbAge, String NativePdbBuildPath) {
  return void();
};
void NativeRuntimeEventSource___::ModuleUnload_V2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath, UInt16 ClrInstanceID, Guid ManagedPdbSignature, UInt32 ManagedPdbAge, String ManagedPdbBuildPath, Guid NativePdbSignature, UInt32 NativePdbAge, String NativePdbBuildPath) {
  return void();
};
void NativeRuntimeEventSource___::AssemblyLoad_V1(UInt64 AssemblyID, UInt64 AppDomainID, UInt64 BindingID, UInt32 AssemblyFlags, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::AssemblyUnload_V1(UInt64 AssemblyID, UInt64 AppDomainID, UInt64 BindingID, UInt32 AssemblyFlags, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::AppDomainLoad_V1(UInt64 AppDomainID, UInt32 AppDomainFlags, String AppDomainName, UInt32 AppDomainIndex, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::AppDomainUnload_V1(UInt64 AppDomainID, UInt32 AppDomainFlags, String AppDomainName, UInt32 AppDomainIndex, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::ModuleRangeLoad(UInt16 ClrInstanceID, UInt64 ModuleID, UInt32 RangeBegin, UInt32 RangeSize, Byte RangeType) {
  return void();
};
void NativeRuntimeEventSource___::StrongNameVerificationStart_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::StrongNameVerificationStop_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::AuthenticodeVerificationStart_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String ModulePath, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::AuthenticodeVerificationStop_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String ModulePath, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::RuntimeInformationStart(UInt16 ClrInstanceID, UInt16 Sku, UInt16 BclMajorVersion, UInt16 BclMinorVersion, UInt16 BclBuildNumber, UInt16 BclQfeNumber, UInt16 VMMajorVersion, UInt16 VMMinorVersion, UInt16 VMBuildNumber, UInt16 VMQfeNumber, UInt32 StartupFlags, Byte StartupMode, String CommandLine, Guid ComObjectGuid, String RuntimeDllPath) {
  return void();
};
void NativeRuntimeEventSource___::IncreaseMemoryPressure(UInt64 BytesAllocated, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::DecreaseMemoryPressure(UInt64 BytesFreed, UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::GCMarkWithType(UInt32 HeapNum, UInt16 ClrInstanceID, UInt32 Type, UInt64 Bytes) {
  return void();
};
void NativeRuntimeEventSource___::GCJoin_V2(UInt32 Heap, UInt32 JoinTime, UInt32 JoinType, UInt16 ClrInstanceID, UInt32 JoinID) {
  return void();
};
void NativeRuntimeEventSource___::GCPerHeapHistory_V3(UInt16 ClrInstanceID, IntPtr FreeListAllocated, IntPtr FreeListRejected, IntPtr EndOfSegAllocated, IntPtr CondemnedAllocated, IntPtr PinnedAllocated, IntPtr PinnedAllocatedAdvance, UInt32 RunningFreeListEfficiency, UInt32 CondemnReasons0, UInt32 CondemnReasons1, UInt32 CompactMechanisms, UInt32 ExpandMechanisms, UInt32 HeapIndex, IntPtr ExtraGen0Commit, UInt32 Count) {
  return void();
};
void NativeRuntimeEventSource___::GCGlobalHeapHistory_V2(UInt64 FinalYoungestDesired, Int32 NumHeaps, UInt32 CondemnedGeneration, UInt32 Gen0ReductionCount, UInt32 Reason, UInt32 GlobalMechanisms, UInt16 ClrInstanceID, UInt32 PauseMode, UInt32 MemoryPressure) {
  return void();
};
void NativeRuntimeEventSource___::DebugIPCEventStart() {
  return void();
};
void NativeRuntimeEventSource___::DebugIPCEventEnd() {
  return void();
};
void NativeRuntimeEventSource___::DebugExceptionProcessingStart() {
  return void();
};
void NativeRuntimeEventSource___::DebugExceptionProcessingEnd() {
  return void();
};
void NativeRuntimeEventSource___::CodeSymbols(UInt64 ModuleId, UInt16 TotalChunks, UInt16 ChunkNumber, UInt32 ChunkLength) {
  return void();
};
void NativeRuntimeEventSource___::EventSource(Int32 EventID, String EventName, String EventSourceName, String Payload) {
  return void();
};
void NativeRuntimeEventSource___::TieredCompilationSettings(UInt16 ClrInstanceID, UInt32 Flags) {
  return void();
};
void NativeRuntimeEventSource___::TieredCompilationPause(UInt16 ClrInstanceID) {
  return void();
};
void NativeRuntimeEventSource___::TieredCompilationResume(UInt16 ClrInstanceID, UInt32 NewMethodCount) {
  return void();
};
void NativeRuntimeEventSource___::TieredCompilationBackgroundJitStart(UInt16 ClrInstanceID, UInt32 PendingMethodCount) {
  return void();
};
void NativeRuntimeEventSource___::TieredCompilationBackgroundJitStop(UInt16 ClrInstanceID, UInt32 PendingMethodCount, UInt32 JittedMethodCount) {
  return void();
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing::NativeRuntimeEventSourceNamespace