#pragma once

#include <System.Private.CoreLib/System/Boolean.h>
#include <System.Private.CoreLib/System/GCGenerationInfo.h>
#include <System.Private.CoreLib/System/Int32.h>
#include <System.Private.CoreLib/System/Int64.h>
#include <System.Private.CoreLib/System/Object.h>
#include <System.Private.CoreLib/System/TimeSpan.h>

namespace System::Private::CoreLib::System {
FORWARDS(ReadOnlySpan, T)
namespace GCMemoryInfoDataNamespace {
CLASS(GCMemoryInfoData) : public object {
  public: ReadOnlySpan<GCGenerationInfo> get_GenerationInfoAsSpan();
  public: ReadOnlySpan<TimeSpan> get_PauseDurationsAsSpan();
  public: void ctor();
  public: Int64 _highMemoryLoadThresholdBytes;
  public: Int64 _totalAvailableMemoryBytes;
  public: Int64 _memoryLoadBytes;
  public: Int64 _heapSizeBytes;
  public: Int64 _fragmentedBytes;
  public: Int64 _totalCommittedBytes;
  public: Int64 _promotedBytes;
  public: Int64 _pinnedObjectsCount;
  public: Int64 _finalizationPendingCount;
  public: Int64 _index;
  public: Int32 _generation;
  public: Int32 _pauseTimePercentage;
  public: Boolean _compacted;
  public: Boolean _concurrent;
  private: GCGenerationInfo _generationInfo0;
  private: GCGenerationInfo _generationInfo1;
  private: GCGenerationInfo _generationInfo2;
  private: GCGenerationInfo _generationInfo3;
  private: GCGenerationInfo _generationInfo4;
  private: TimeSpan _pauseDuration0;
  private: TimeSpan _pauseDuration1;
};
} // namespace GCMemoryInfoDataNamespace
using GCMemoryInfoData = GCMemoryInfoDataNamespace::GCMemoryInfoData;
} // namespace System::Private::CoreLib::System
