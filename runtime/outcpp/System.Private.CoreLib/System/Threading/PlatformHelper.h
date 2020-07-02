#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARDS(Int32)
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Threading {
namespace PlatformHelperNamespace {
class PlatformHelper {
  public: static Int32 get_ProcessorCount();
  private: static Int32 s_processorCount;
  private: static Int32 s_lastProcessorCountRefreshTicks;
  public: static Boolean IsSingleProcessor;
};
} // namespace PlatformHelperNamespace
using PlatformHelper = PlatformHelperNamespace::PlatformHelper;
} // namespace System::Private::CoreLib::System::Threading
