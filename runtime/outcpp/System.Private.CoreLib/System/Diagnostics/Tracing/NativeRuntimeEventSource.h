#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Byte)
FORWARDS(DateTime)
FORWARDS(Double)
FORWARDS(Guid)
FORWARDS(Int32)
FORWARDS(IntPtr)
FORWARDS(ReadOnlySpan, T)
FORWARD(String)
FORWARDS(UInt16)
FORWARDS(UInt32)
FORWARDS(UInt64)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventKeywords : int64_t;
namespace NativeRuntimeEventSourceNamespace {
CLASS(NativeRuntimeEventSource) {
  public: CLASS(Keywords) {
    public: static EventKeywords GCKeyword;
    public: static EventKeywords GCHandleKeyword;
    public: static EventKeywords AssemblyLoaderKeyword;
    public: static EventKeywords LoaderKeyword;
    public: static EventKeywords JitKeyword;
    public: static EventKeywords NGenKeyword;
    public: static EventKeywords StartEnumerationKeyword;
    public: static EventKeywords EndEnumerationKeyword;
    public: static EventKeywords SecurityKeyword;
    public: static EventKeywords AppDomainResourceManagementKeyword;
    public: static EventKeywords JitTracingKeyword;
    public: static EventKeywords InteropKeyword;
    public: static EventKeywords ContentionKeyword;
    public: static EventKeywords ExceptionKeyword;
    public: static EventKeywords ThreadingKeyword;
    public: static EventKeywords JittedMethodILToNativeMapKeyword;
    public: static EventKeywords OverrideAndSuppressNGenEventsKeyword;
    public: static EventKeywords TypeKeyword;
    public: static EventKeywords GCHeapDumpKeyword;
    public: static EventKeywords GCSampledObjectAllocationHighKeyword;
    public: static EventKeywords GCHeapSurvivalAndMovementKeyword;
    public: static EventKeywords GCHeapCollectKeyword;
    public: static EventKeywords GCHeapAndTypeNamesKeyword;
    public: static EventKeywords GCSampledObjectAllocationLowKeyword;
    public: static EventKeywords PerfTrackKeyword;
    public: static EventKeywords StackKeyword;
    public: static EventKeywords ThreadTransferKeyword;
    public: static EventKeywords DebuggerKeyword;
    public: static EventKeywords MonitoringKeyword;
    public: static EventKeywords CodeSymbolsKeyword;
    public: static EventKeywords EventSourceKeyword;
    public: static EventKeywords CompilationKeyword;
    public: static EventKeywords CompilationDiagnosticKeyword;
    public: static EventKeywords MethodDiagnosticKeyword;
  };
  public: void ProcessEvent(UInt32 eventID, UInt32 osThreadID, DateTime timeStamp, Guid activityId, Guid childActivityId, ReadOnlySpan<Byte> payload);
  private: void GCStart_V2(UInt32 Count, UInt32 Depth, UInt32 Reason, UInt32 Type, UInt16 ClrInstanceID, UInt64 ClientSequenceNumber);
  private: void GCEnd_V1(UInt32 Count, UInt32 Depth, UInt16 ClrInstanceID);
  private: void GCRestartEEEnd_V1(UInt16 ClrInstanceID);
  private: void GCHeapStats_V1(UInt64 GenerationSize0, UInt64 TotalPromotedSize0, UInt64 GenerationSize1, UInt64 TotalPromotedSize1, UInt64 GenerationSize2, UInt64 TotalPromotedSize2, UInt64 GenerationSize3, UInt64 TotalPromotedSize3, UInt64 FinalizationPromotedSize, UInt64 FinalizationPromotedCount, UInt32 PinnedObjectCount, UInt32 SinkBlockCount, UInt32 GCHandleCount, UInt16 ClrInstanceID);
  private: void GCCreateSegment_V1(UInt64 Address, UInt64 Size, UInt32 Type, UInt16 ClrInstanceID);
  private: void GCFreeSegment_V1(UInt64 Address, UInt16 ClrInstanceID);
  private: void GCRestartEEBegin_V1(UInt16 ClrInstanceID);
  private: void GCSuspendEEEnd_V1(UInt16 ClrInstanceID);
  private: void GCSuspendEEBegin_V1(UInt32 Reason, UInt32 Count, UInt16 ClrInstanceID);
  private: void GCAllocationTick_V3(UInt32 AllocationAmount, UInt32 AllocationKind, UInt16 ClrInstanceID, UInt64 AllocationAmount64, IntPtr TypeID, String TypeName, UInt32 HeapIndex, IntPtr Address);
  private: void GCCreateConcurrentThread_V1(UInt16 ClrInstanceID);
  private: void GCTerminateConcurrentThread_V1(UInt16 ClrInstanceID);
  private: void GCFinalizersEnd_V1(UInt32 Count, UInt16 ClrInstanceID);
  private: void GCFinalizersBegin_V1(UInt16 ClrInstanceID);
  private: void BulkType(UInt32 Count, UInt16 ClrInstanceID);
  private: void GCBulkRootEdge(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID);
  private: void GCBulkRootConditionalWeakTableElementEdge(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID);
  private: void GCBulkNode(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID);
  private: void GCBulkEdge(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID);
  private: void GCSampledObjectAllocationHigh(IntPtr Address, IntPtr TypeID, UInt32 ObjectCountForTypeSample, UInt64 TotalSizeForTypeSample, UInt16 ClrInstanceID);
  private: void GCBulkSurvivingObjectRanges(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID);
  private: void GCBulkMovedObjectRanges(UInt32 Index, UInt32 Count, UInt16 ClrInstanceID);
  private: void GCGenerationRange(Byte Generation, IntPtr RangeStart, UInt64 RangeUsedLength, UInt64 RangeReservedLength, UInt16 ClrInstanceID);
  private: void GCMarkStackRoots(UInt32 HeapNum, UInt16 ClrInstanceID);
  private: void GCMarkFinalizeQueueRoots(UInt32 HeapNum, UInt16 ClrInstanceID);
  private: void GCMarkHandles(UInt32 HeapNum, UInt16 ClrInstanceID);
  private: void GCMarkOlderGenerationRoots(UInt32 HeapNum, UInt16 ClrInstanceID);
  private: void FinalizeObject(IntPtr TypeID, IntPtr ObjectID, UInt16 ClrInstanceID);
  private: void SetGCHandle(IntPtr HandleID, IntPtr ObjectID, UInt32 Kind, UInt32 Generation, UInt64 AppDomainID, UInt16 ClrInstanceID);
  private: void DestroyGCHandle(IntPtr HandleID, UInt16 ClrInstanceID);
  private: void GCSampledObjectAllocationLow(IntPtr Address, IntPtr TypeID, UInt32 ObjectCountForTypeSample, UInt64 TotalSizeForTypeSample, UInt16 ClrInstanceID);
  private: void PinObjectAtGCTime(IntPtr HandleID, IntPtr ObjectID, UInt64 ObjectSize, String TypeName, UInt16 ClrInstanceID);
  private: void GCTriggered(UInt32 Reason, UInt16 ClrInstanceID);
  private: void GCBulkRootCCW(UInt32 Count, UInt16 ClrInstanceID);
  private: void GCBulkRCW(UInt32 Count, UInt16 ClrInstanceID);
  private: void GCBulkRootStaticVar(UInt32 Count, UInt64 AppDomainID, UInt16 ClrInstanceID);
  private: void GCDynamicEvent(String Name, UInt32 DataSize);
  private: void WorkerThreadCreate(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads);
  private: void WorkerThreadTerminate(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads);
  private: void WorkerThreadRetire(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads);
  private: void WorkerThreadUnretire(UInt32 WorkerThreadCount, UInt32 RetiredWorkerThreads);
  private: void IOThreadCreate_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID);
  private: void IOThreadTerminate_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID);
  private: void IOThreadRetire_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID);
  private: void IOThreadUnretire_V1(UInt32 IOThreadCount, UInt32 RetiredIOThreads, UInt16 ClrInstanceID);
  private: void ThreadpoolSuspensionSuspendThread(UInt32 ClrThreadID, UInt32 CpuUtilization);
  private: void ThreadpoolSuspensionResumeThread(UInt32 ClrThreadID, UInt32 CpuUtilization);
  private: void ThreadPoolWorkerThreadStart(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID);
  private: void ThreadPoolWorkerThreadStop(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID);
  private: void ThreadPoolWorkerThreadRetirementStart(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID);
  private: void ThreadPoolWorkerThreadRetirementStop(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID);
  private: void ThreadPoolWorkerThreadAdjustmentSample(Double Throughput, UInt16 ClrInstanceID);
  private: void ThreadPoolWorkerThreadAdjustmentAdjustment(Double AverageThroughput, UInt32 NewWorkerThreadCount, UInt32 Reason, UInt16 ClrInstanceID);
  private: void ThreadPoolWorkerThreadAdjustmentStats(Double Duration, Double Throughput, Double ThreadWave, Double ThroughputWave, Double ThroughputErrorEstimate, Double AverageThroughputErrorEstimate, Double ThroughputRatio, Double Confidence, Double NewControlSetting, UInt16 NewThreadWaveMagnitude, UInt16 ClrInstanceID);
  private: void ThreadPoolWorkerThreadWait(UInt32 ActiveWorkerThreadCount, UInt32 RetiredWorkerThreadCount, UInt16 ClrInstanceID);
  private: void ThreadPoolWorkingThreadCount(UInt32 Count, UInt16 ClrInstanceID);
  private: void ThreadPoolEnqueue(IntPtr WorkID, UInt16 ClrInstanceID);
  private: void ThreadPoolDequeue(IntPtr WorkID, UInt16 ClrInstanceID);
  private: void ThreadPoolIOEnqueue(IntPtr NativeOverlapped, IntPtr Overlapped, Boolean MultiDequeues, UInt16 ClrInstanceID);
  private: void ThreadPoolIODequeue(IntPtr NativeOverlapped, IntPtr Overlapped, UInt16 ClrInstanceID);
  private: void ThreadPoolIOPack(IntPtr NativeOverlapped, IntPtr Overlapped, UInt16 ClrInstanceID);
  private: void ThreadCreating(IntPtr ID, UInt16 ClrInstanceID);
  private: void ThreadRunning(IntPtr ID, UInt16 ClrInstanceID);
  private: void MethodDetails(UInt64 MethodID, UInt64 TypeID, UInt32 MethodToken, UInt32 TypeParameterCount, UInt64 LoaderModuleID);
  private: void ExceptionThrown_V1(String ExceptionType, String ExceptionMessage, IntPtr ExceptionEIP, UInt32 ExceptionHRESULT, UInt16 ExceptionFlags, UInt16 ClrInstanceID);
  private: void ExceptionCatchStart(UInt64 EntryEIP, UInt64 MethodID, String MethodName, UInt16 ClrInstanceID);
  private: void ExceptionCatchStop();
  private: void ExceptionFinallyStart(UInt64 EntryEIP, UInt64 MethodID, String MethodName, UInt16 ClrInstanceID);
  private: void ExceptionFinallyStop();
  private: void ExceptionFilterStart(UInt64 EntryEIP, UInt64 MethodID, String MethodName, UInt16 ClrInstanceID);
  private: void ExceptionFilterStop();
  private: void ExceptionThrownStop();
  private: void ContentionStart_V1(Byte ContentionFlags, UInt16 ClrInstanceID);
  private: void ContentionStop_V1(Byte ContentionFlags, UInt16 ClrInstanceID, Double DurationNs);
  private: void CLRStackWalk(UInt16 ClrInstanceID, Byte Reserved1, Byte Reserved2, UInt32 FrameCount);
  private: void AppDomainMemAllocated(UInt64 AppDomainID, UInt64 Allocated, UInt16 ClrInstanceID);
  private: void AppDomainMemSurvived(UInt64 AppDomainID, UInt64 Survived, UInt64 ProcessSurvived, UInt16 ClrInstanceID);
  private: void ThreadCreated(UInt64 ManagedThreadID, UInt64 AppDomainID, UInt32 Flags, UInt32 ManagedThreadIndex, UInt32 OSThreadID, UInt16 ClrInstanceID);
  private: void ThreadTerminated(UInt64 ManagedThreadID, UInt64 AppDomainID, UInt16 ClrInstanceID);
  private: void ThreadDomainEnter(UInt64 ManagedThreadID, UInt64 AppDomainID, UInt16 ClrInstanceID);
  private: void ILStubGenerated(UInt16 ClrInstanceID, UInt64 ModuleID, UInt64 StubMethodID, UInt32 StubFlags, UInt32 ManagedInteropMethodToken, String ManagedInteropMethodNamespace, String ManagedInteropMethodName, String ManagedInteropMethodSignature, String NativeMethodSignature, String StubMethodSignature, String StubMethodILCode);
  private: void ILStubCacheHit(UInt16 ClrInstanceID, UInt64 ModuleID, UInt64 StubMethodID, UInt32 ManagedInteropMethodToken, String ManagedInteropMethodNamespace, String ManagedInteropMethodName, String ManagedInteropMethodSignature);
  private: void DCStartCompleteV2();
  private: void DCEndCompleteV2();
  private: void MethodDCStartV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags);
  private: void MethodDCEndV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags);
  private: void MethodDCStartVerboseV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature);
  private: void MethodDCEndVerboseV2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature);
  private: void MethodLoad_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, UInt16 ClrInstanceID, UInt64 ReJITID);
  private: void R2RGetEntryPoint(UInt64 MethodID, String MethodNamespace, String MethodName, String MethodSignature, UInt64 EntryPoint, UInt16 ClrInstanceID);
  private: void MethodUnload_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, UInt16 ClrInstanceID, UInt64 ReJITID);
  private: void MethodLoadVerbose_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature, UInt16 ClrInstanceID, UInt64 ReJITID);
  private: void MethodUnloadVerbose_V2(UInt64 MethodID, UInt64 ModuleID, UInt64 MethodStartAddress, UInt32 MethodSize, UInt32 MethodToken, UInt32 MethodFlags, String MethodNamespace, String MethodName, String MethodSignature, UInt16 ClrInstanceID, UInt64 ReJITID);
  private: void MethodJittingStarted_V1(UInt64 MethodID, UInt64 ModuleID, UInt32 MethodToken, UInt32 MethodILSize, String MethodNamespace, String MethodName, String MethodSignature, UInt16 ClrInstanceID);
  private: void MethodJitInliningSucceeded(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String InlinerNamespace, String InlinerName, String InlinerNameSignature, String InlineeNamespace, String InlineeName, String InlineeNameSignature, UInt16 ClrInstanceID);
  private: void MethodJitInliningFailedAnsi(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String InlinerNamespace, String InlinerName, String InlinerNameSignature, String InlineeNamespace, String InlineeName, String InlineeNameSignature, Boolean FailAlways);
  private: void MethodJitTailCallSucceeded(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String CallerNamespace, String CallerName, String CallerNameSignature, String CalleeNamespace, String CalleeName, String CalleeNameSignature, Boolean TailPrefix, UInt32 TailCallType, UInt16 ClrInstanceID);
  private: void MethodJitTailCallFailedAnsi(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String CallerNamespace, String CallerName, String CallerNameSignature, String CalleeNamespace, String CalleeName, String CalleeNameSignature, Boolean TailPrefix);
  private: void MethodILToNativeMap(UInt64 MethodID, UInt64 ReJITID, Byte MethodExtent, UInt16 CountOfMapEntries);
  private: void MethodJitTailCallFailed(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String CallerNamespace, String CallerName, String CallerNameSignature, String CalleeNamespace, String CalleeName, String CalleeNameSignature, Boolean TailPrefix, String FailReason, UInt16 ClrInstanceID);
  private: void MethodJitInliningFailed(String MethodBeingCompiledNamespace, String MethodBeingCompiledName, String MethodBeingCompiledNameSignature, String InlinerNamespace, String InlinerName, String InlinerNameSignature, String InlineeNamespace, String InlineeName, String InlineeNameSignature, Boolean FailAlways, String FailReason, UInt16 ClrInstanceID);
  private: void ModuleDCStartV2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath);
  private: void ModuleDCEndV2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath);
  private: void DomainModuleLoad_V1(UInt64 ModuleID, UInt64 AssemblyID, UInt64 AppDomainID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath, UInt16 ClrInstanceID);
  private: void ModuleLoad_V2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath, UInt16 ClrInstanceID, Guid ManagedPdbSignature, UInt32 ManagedPdbAge, String ManagedPdbBuildPath, Guid NativePdbSignature, UInt32 NativePdbAge, String NativePdbBuildPath);
  private: void ModuleUnload_V2(UInt64 ModuleID, UInt64 AssemblyID, UInt32 ModuleFlags, UInt32 Reserved1, String ModuleILPath, String ModuleNativePath, UInt16 ClrInstanceID, Guid ManagedPdbSignature, UInt32 ManagedPdbAge, String ManagedPdbBuildPath, Guid NativePdbSignature, UInt32 NativePdbAge, String NativePdbBuildPath);
  private: void AssemblyLoad_V1(UInt64 AssemblyID, UInt64 AppDomainID, UInt64 BindingID, UInt32 AssemblyFlags, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID);
  private: void AssemblyUnload_V1(UInt64 AssemblyID, UInt64 AppDomainID, UInt64 BindingID, UInt32 AssemblyFlags, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID);
  private: void AppDomainLoad_V1(UInt64 AppDomainID, UInt32 AppDomainFlags, String AppDomainName, UInt32 AppDomainIndex, UInt16 ClrInstanceID);
  private: void AppDomainUnload_V1(UInt64 AppDomainID, UInt32 AppDomainFlags, String AppDomainName, UInt32 AppDomainIndex, UInt16 ClrInstanceID);
  private: void ModuleRangeLoad(UInt16 ClrInstanceID, UInt64 ModuleID, UInt32 RangeBegin, UInt32 RangeSize, Byte RangeType);
  private: void StrongNameVerificationStart_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID);
  private: void StrongNameVerificationStop_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String FullyQualifiedAssemblyName, UInt16 ClrInstanceID);
  private: void AuthenticodeVerificationStart_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String ModulePath, UInt16 ClrInstanceID);
  private: void AuthenticodeVerificationStop_V1(UInt32 VerificationFlags, UInt32 ErrorCode, String ModulePath, UInt16 ClrInstanceID);
  private: void RuntimeInformationStart(UInt16 ClrInstanceID, UInt16 Sku, UInt16 BclMajorVersion, UInt16 BclMinorVersion, UInt16 BclBuildNumber, UInt16 BclQfeNumber, UInt16 VMMajorVersion, UInt16 VMMinorVersion, UInt16 VMBuildNumber, UInt16 VMQfeNumber, UInt32 StartupFlags, Byte StartupMode, String CommandLine, Guid ComObjectGuid, String RuntimeDllPath);
  private: void IncreaseMemoryPressure(UInt64 BytesAllocated, UInt16 ClrInstanceID);
  private: void DecreaseMemoryPressure(UInt64 BytesFreed, UInt16 ClrInstanceID);
  private: void GCMarkWithType(UInt32 HeapNum, UInt16 ClrInstanceID, UInt32 Type, UInt64 Bytes);
  private: void GCJoin_V2(UInt32 Heap, UInt32 JoinTime, UInt32 JoinType, UInt16 ClrInstanceID, UInt32 JoinID);
  private: void GCPerHeapHistory_V3(UInt16 ClrInstanceID, IntPtr FreeListAllocated, IntPtr FreeListRejected, IntPtr EndOfSegAllocated, IntPtr CondemnedAllocated, IntPtr PinnedAllocated, IntPtr PinnedAllocatedAdvance, UInt32 RunningFreeListEfficiency, UInt32 CondemnReasons0, UInt32 CondemnReasons1, UInt32 CompactMechanisms, UInt32 ExpandMechanisms, UInt32 HeapIndex, IntPtr ExtraGen0Commit, UInt32 Count);
  private: void GCGlobalHeapHistory_V3(UInt64 FinalYoungestDesired, Int32 NumHeaps, UInt32 CondemnedGeneration, UInt32 Gen0ReductionCount, UInt32 Reason, UInt32 GlobalMechanisms, UInt16 ClrInstanceID, UInt32 PauseMode, UInt32 MemoryPressure, UInt32 CondemnReasons0, UInt32 CondemnReasons1);
  private: void DebugIPCEventStart();
  private: void DebugIPCEventEnd();
  private: void DebugExceptionProcessingStart();
  private: void DebugExceptionProcessingEnd();
  private: void CodeSymbols(UInt64 ModuleId, UInt16 TotalChunks, UInt16 ChunkNumber, UInt32 ChunkLength);
  private: void EventSource(Int32 EventID, String EventName, String EventSourceName, String Payload);
  private: void TieredCompilationSettings(UInt16 ClrInstanceID, UInt32 Flags);
  private: void TieredCompilationPause(UInt16 ClrInstanceID);
  private: void TieredCompilationResume(UInt16 ClrInstanceID, UInt32 NewMethodCount);
  private: void TieredCompilationBackgroundJitStart(UInt16 ClrInstanceID, UInt32 PendingMethodCount);
  private: void TieredCompilationBackgroundJitStop(UInt16 ClrInstanceID, UInt32 PendingMethodCount, UInt32 JittedMethodCount);
  private: void AssemblyLoadStart(UInt16 ClrInstanceID, String AssemblyName, String AssemblyPath, String RequestingAssembly, String AssemblyLoadContext, String RequestingAssemblyLoadContext);
  private: void AssemblyLoadStop(UInt16 ClrInstanceID, String AssemblyName, String AssemblyPath, String RequestingAssembly, String AssemblyLoadContext, String RequestingAssemblyLoadContext, Boolean Success, String ResultAssemblyName, String ResultAssemblyPath, Boolean Cached);
  private: void ResolutionAttempted(UInt16 ClrInstanceID, String AssemblyName, UInt16 Stage, String AssemblyLoadContext, UInt16 Result, String ResultAssemblyName, String ResultAssemblyPath, String ErrorMessage);
  private: void AssemblyLoadContextResolvingHandlerInvoked(UInt16 ClrInstanceID, String AssemblyName, String HandlerName, String AssemblyLoadContext, String ResultAssemblyName, String ResultAssemblyPath);
  private: void AppDomainAssemblyResolveHandlerInvoked(UInt16 ClrInstanceID, String AssemblyName, String HandlerName, String ResultAssemblyName, String ResultAssemblyPath);
  private: void AssemblyLoadFromResolveHandlerInvoked(UInt16 ClrInstanceID, String AssemblyName, Boolean IsTrackedLoad, String RequestingAssemblyPath, String ComputedRequestedAssemblyPath);
  private: void KnownPathProbed(UInt16 ClrInstanceID, String FilePath, UInt16 Source, Int32 Result);
  public: static String EventSourceName;
  public: static NativeRuntimeEventSource Log;
};
} // namespace NativeRuntimeEventSourceNamespace
using NativeRuntimeEventSource = NativeRuntimeEventSourceNamespace::NativeRuntimeEventSource;
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
