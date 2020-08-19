#include "ManifestResourceInfo-dep.h"

namespace System::Private::CoreLib::System::Reflection::ManifestResourceInfoNamespace {
Assembly ManifestResourceInfo___::get_ReferencedAssembly() {
  return ReferencedAssembly;
}

String ManifestResourceInfo___::get_FileName() {
  return FileName;
}

ResourceLocation ManifestResourceInfo___::get_ResourceLocation() {
  return ResourceLocation;
}

void ManifestResourceInfo___::ctor(Assembly containingAssembly, String containingFileName, Reflection::ResourceLocation resourceLocation) {
  get_ReferencedAssembly(containingAssembly);
  get_FileName(containingFileName);
  get_ResourceLocation(resourceLocation);
}

} // namespace System::Private::CoreLib::System::Reflection::ManifestResourceInfoNamespace
