#pragma once

#include <System.Private.CoreLib/System/ValueType.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Double)
FORWARDS(GCGenerationInfo)
FORWARD(GCMemoryInfoData)
FORWARDS(Int32)
FORWARDS(Int64)
FORWARDS(ReadOnlySpan, T)
FORWARDS(TimeSpan)
namespace GCMemoryInfoNamespace {
struct GCMemoryInfo : public valueType<GCMemoryInfo> {
  public: Int64 get_HighMemoryLoadThresholdBytes();
  public: Int64 get_MemoryLoadBytes();
  public: Int64 get_TotalAvailableMemoryBytes();
  public: Int64 get_HeapSizeBytes();
  public: Int64 get_FragmentedBytes();
  public: Int64 get_Index();
  public: Int32 get_Generation();
  public: Boolean get_Compacted();
  public: Boolean get_Concurrent();
  public: Int64 get_TotalCommittedBytes();
  public: Int64 get_PromotedBytes();
  public: Int64 get_PinnedObjectsCount();
  public: Int64 get_FinalizationPendingCount();
  public: ReadOnlySpan<TimeSpan> get_PauseDurations();
  public: Double get_PauseTimePercentage();
  public: ReadOnlySpan<GCGenerationInfo> get_GenerationInfo();
  public: explicit GCMemoryInfo(GCMemoryInfoData data);
  public: explicit GCMemoryInfo() {}
  private: GCMemoryInfoData _data;
};
} // namespace GCMemoryInfoNamespace
using GCMemoryInfo = GCMemoryInfoNamespace::GCMemoryInfo;
} // namespace System::Private::CoreLib::System
