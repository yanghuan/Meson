#include "GCMemoryInfo-dep.h"

namespace System::Private::CoreLib::System::GCMemoryInfoNamespace {
Int64 GCMemoryInfo::get_HighMemoryLoadThresholdBytes() {
  return _data->_highMemoryLoadThresholdBytes;
}

Int64 GCMemoryInfo::get_MemoryLoadBytes() {
  return _data->_memoryLoadBytes;
}

Int64 GCMemoryInfo::get_TotalAvailableMemoryBytes() {
  return _data->_totalAvailableMemoryBytes;
}

Int64 GCMemoryInfo::get_HeapSizeBytes() {
  return _data->_heapSizeBytes;
}

Int64 GCMemoryInfo::get_FragmentedBytes() {
  return _data->_fragmentedBytes;
}

Int64 GCMemoryInfo::get_Index() {
  return _data->_index;
}

Int32 GCMemoryInfo::get_Generation() {
  return _data->_generation;
}

Boolean GCMemoryInfo::get_Compacted() {
  return _data->_compacted;
}

Boolean GCMemoryInfo::get_Concurrent() {
  return _data->_concurrent;
}

Int64 GCMemoryInfo::get_TotalCommittedBytes() {
  return _data->_totalCommittedBytes;
}

Int64 GCMemoryInfo::get_PromotedBytes() {
  return _data->_promotedBytes;
}

Int64 GCMemoryInfo::get_PinnedObjectsCount() {
  return _data->_pinnedObjectsCount;
}

Int64 GCMemoryInfo::get_FinalizationPendingCount() {
  return _data->_finalizationPendingCount;
}

ReadOnlySpan<TimeSpan> GCMemoryInfo::get_PauseDurations() {
  return _data->get_PauseDurationsAsSpan();
}

Double GCMemoryInfo::get_PauseTimePercentage() {
  return (Double)_data->_pauseTimePercentage / 100;
}

ReadOnlySpan<GCGenerationInfo> GCMemoryInfo::get_GenerationInfo() {
  return _data->get_GenerationInfoAsSpan();
}

GCMemoryInfo::GCMemoryInfo(GCMemoryInfoData data) {
  _data = data;
}

} // namespace System::Private::CoreLib::System::GCMemoryInfoNamespace
