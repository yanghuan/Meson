#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
namespace DriveInfoInternalNamespace {
class DriveInfoInternal {
  public: static Array<String> GetLogicalDrives();
};
} // namespace DriveInfoInternalNamespace
using DriveInfoInternal = DriveInfoInternalNamespace::DriveInfoInternal;
} // namespace System::Private::CoreLib::System::IO
