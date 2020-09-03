#include "GCMemoryInfo-dep.h"

namespace System::Private::CoreLib::System::GCMemoryInfoNamespace {
GCMemoryInfo::GCMemoryInfo(Int64 highMemoryLoadThresholdBytes, Int64 memoryLoadBytes, Int64 totalAvailableMemoryBytes, Int64 heapSizeBytes, Int64 fragmentedBytes) {
  HighMemoryLoadThresholdBytes = highMemoryLoadThresholdBytes;
  MemoryLoadBytes = memoryLoadBytes;
  TotalAvailableMemoryBytes = totalAvailableMemoryBytes;
  HeapSizeBytes = heapSizeBytes;
  FragmentedBytes = fragmentedBytes;
}

} // namespace System::Private::CoreLib::System::GCMemoryInfoNamespace
