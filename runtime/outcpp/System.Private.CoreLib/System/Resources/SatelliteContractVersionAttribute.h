#pragma once

#include <System.Private.CoreLib/System/Attribute.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Resources {
namespace SatelliteContractVersionAttributeNamespace {
CLASS(SatelliteContractVersionAttribute) : public Attribute::in {
  public: String get_Version() { return Version; }
  public: void Ctor(String version);
  private: String Version;
};
} // namespace SatelliteContractVersionAttributeNamespace
using SatelliteContractVersionAttribute = SatelliteContractVersionAttributeNamespace::SatelliteContractVersionAttribute;
} // namespace System::Private::CoreLib::System::Resources
