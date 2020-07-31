#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
FORWARDS(Int32)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace ProcessorIdCacheNamespace {
class ProcessorIdCache {
  private: static Int32 RefreshCurrentProcessorId();
  public: static Int32 GetCurrentProcessorId();
  public: static Boolean ProcessorNumberSpeedCheck();
  public: static Int32 UninlinedThreadStatic();
  private: static Int32 t_currentProcessorIdCache;
  private: static Int32 s_processorIdRefreshRate;
};
} // namespace ProcessorIdCacheNamespace
using ProcessorIdCache = ProcessorIdCacheNamespace::ProcessorIdCache;
} // namespace System::Private::CoreLib::System::Threading
