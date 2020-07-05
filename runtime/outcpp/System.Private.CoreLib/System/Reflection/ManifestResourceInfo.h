#pragma once

#include <rt/GCObject.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class ResourceLocation;
FORWARD(Assembly)
namespace ManifestResourceInfoNamespace {
CLASS(ManifestResourceInfo) {
  public: Assembly get_ReferencedAssembly();
  public: String get_FileName();
  public: ResourceLocation get_ResourceLocation();
  private: Assembly ReferencedAssembly;
  private: String FileName;
  private: ResourceLocation ResourceLocation;
};
} // namespace ManifestResourceInfoNamespace
using ManifestResourceInfo = ManifestResourceInfoNamespace::ManifestResourceInfo;
} // namespace System::Private::CoreLib::System::Reflection
