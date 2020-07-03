#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
namespace SatelliteContractVersionAttributeNamespace {
CLASS(SatelliteContractVersionAttribute) {
  private: String Version;
};
} // namespace SatelliteContractVersionAttributeNamespace
using SatelliteContractVersionAttribute = SatelliteContractVersionAttributeNamespace::SatelliteContractVersionAttribute;
} // namespace System::Private::CoreLib::System::Resources
