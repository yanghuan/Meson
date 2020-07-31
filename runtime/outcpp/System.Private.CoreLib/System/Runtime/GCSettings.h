#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARDS(Boolean)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime {
enum class GCLargeObjectHeapCompactionMode;
enum class GCLatencyMode;
namespace GCSettingsNamespace {
class GCSettings : public Object::in {
  private: enum class SetLatencyModeStatus {
    Succeeded = 0,
    NoGCInProgress = 1,
  };
  public: static Boolean get_IsServerGC();
  public: static GCLatencyMode get_LatencyMode();
  public: static void set_LatencyMode(GCLatencyMode value);
  public: static GCLargeObjectHeapCompactionMode get_LargeObjectHeapCompactionMode();
  public: static void set_LargeObjectHeapCompactionMode(GCLargeObjectHeapCompactionMode value);
  private: static GCLatencyMode GetGCLatencyMode();
  private: static SetLatencyModeStatus SetGCLatencyMode(GCLatencyMode newLatencyMode);
  private: static GCLargeObjectHeapCompactionMode GetLOHCompactionMode();
  private: static void SetLOHCompactionMode(GCLargeObjectHeapCompactionMode newLOHCompactionMode);
};
} // namespace GCSettingsNamespace
using GCSettings = GCSettingsNamespace::GCSettings;
} // namespace System::Private::CoreLib::System::Runtime
