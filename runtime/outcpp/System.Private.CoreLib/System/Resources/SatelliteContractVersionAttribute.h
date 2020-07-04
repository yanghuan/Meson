#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
namespace SatelliteContractVersionAttributeNamespace {
CLASS(SatelliteContractVersionAttribute) {
  public: String get_Version() { return Version; }
  private: String Version;
};
} // namespace SatelliteContractVersionAttributeNamespace
using SatelliteContractVersionAttribute = SatelliteContractVersionAttributeNamespace::SatelliteContractVersionAttribute;
} // namespace System::Private::CoreLib::System::Resources
