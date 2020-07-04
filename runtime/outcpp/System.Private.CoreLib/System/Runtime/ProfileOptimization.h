#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Runtime {
namespace ProfileOptimizationNamespace {
class ProfileOptimization {
  public: static void SetProfileRoot(String directoryPath);
  public: static void StartProfile(String profile);
};
} // namespace ProfileOptimizationNamespace
using ProfileOptimization = ProfileOptimizationNamespace::ProfileOptimization;
} // namespace System::Private::CoreLib::System::Runtime
