#include "SatelliteContractVersionAttribute-dep.h"

#include <System.Private.CoreLib/System/ArgumentNullException-dep.h>

namespace System::Private::CoreLib::System::Resources::SatelliteContractVersionAttributeNamespace {
void SatelliteContractVersionAttribute___::ctor(String version) {
  if (version == nullptr) {
    rt::throw_exception<ArgumentNullException>("version");
  }
  Version = version;
}

} // namespace System::Private::CoreLib::System::Resources::SatelliteContractVersionAttributeNamespace
