#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
namespace MissingSatelliteAssemblyExceptionNamespace {
CLASS(MissingSatelliteAssemblyException) {
  public: String get_CultureName();
  private: String _cultureName;
};
} // namespace MissingSatelliteAssemblyExceptionNamespace
using MissingSatelliteAssemblyException = MissingSatelliteAssemblyExceptionNamespace::MissingSatelliteAssemblyException;
} // namespace System::Private::CoreLib::System::Resources
