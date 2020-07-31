#pragma once

#include <rt/GCObject.h>
#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD_(Array, T1, T2)
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::IO {
namespace DriveInfoInternalNamespace {
class DriveInfoInternal : public Object::in {
  public: static Array<String> GetLogicalDrives();
};
} // namespace DriveInfoInternalNamespace
using DriveInfoInternal = DriveInfoInternalNamespace::DriveInfoInternal;
} // namespace System::Private::CoreLib::System::IO
