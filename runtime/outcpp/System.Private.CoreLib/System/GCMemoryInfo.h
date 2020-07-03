#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System {
namespace GCMemoryInfoNamespace {
struct GCMemoryInfo {
  private: Int64 HighMemoryLoadThresholdBytes;
  private: Int64 MemoryLoadBytes;
  private: Int64 TotalAvailableMemoryBytes;
  private: Int64 HeapSizeBytes;
  private: Int64 FragmentedBytes;
};
} // namespace GCMemoryInfoNamespace
using GCMemoryInfo = GCMemoryInfoNamespace::GCMemoryInfo;
} // namespace System::Private::CoreLib::System
