#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
FORWARD(Assembly)
enum class ResourceLocation;
namespace ManifestResourceInfoNamespace {
CLASS(ManifestResourceInfo) {
  public: Assembly get_ReferencedAssembly();
  public: String get_FileName();
  public: ResourceLocation get_ResourceLocation();
};
} // namespace ManifestResourceInfoNamespace
using ManifestResourceInfo = ManifestResourceInfoNamespace::ManifestResourceInfo;
} // namespace System::Private::CoreLib::System::Reflection
