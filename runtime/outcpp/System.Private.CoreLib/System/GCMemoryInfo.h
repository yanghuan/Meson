#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Int64.h>

namespace System::Private::CoreLib::System {
namespace GCMemoryInfoNamespace {
struct GCMemoryInfo {
  public: Int64 get_HighMemoryLoadThresholdBytes() { return HighMemoryLoadThresholdBytes; }
  public: Int64 get_MemoryLoadBytes() { return MemoryLoadBytes; }
  public: Int64 get_TotalAvailableMemoryBytes() { return TotalAvailableMemoryBytes; }
  public: Int64 get_HeapSizeBytes() { return HeapSizeBytes; }
  public: Int64 get_FragmentedBytes() { return FragmentedBytes; }
  public: explicit GCMemoryInfo(Int64 highMemoryLoadThresholdBytes, Int64 memoryLoadBytes, Int64 totalAvailableMemoryBytes, Int64 heapSizeBytes, Int64 fragmentedBytes);
  public: explicit GCMemoryInfo() {}
  private: Int64 HighMemoryLoadThresholdBytes;
  private: Int64 MemoryLoadBytes;
  private: Int64 TotalAvailableMemoryBytes;
  private: Int64 HeapSizeBytes;
  private: Int64 FragmentedBytes;
};
} // namespace GCMemoryInfoNamespace
using GCMemoryInfo = GCMemoryInfoNamespace::GCMemoryInfo;
} // namespace System::Private::CoreLib::System
