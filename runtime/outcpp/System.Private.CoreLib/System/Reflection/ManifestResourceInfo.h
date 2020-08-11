#pragma once

#include <System.Private.CoreLib/System/Object.h>

namespace System::Private::CoreLib::System {
FORWARD(String)
} // namespace System::Private::CoreLib::System
namespace System::Private::CoreLib::System::Reflection {
enum class ResourceLocation : int32_t;
FORWARD(Assembly)
namespace ManifestResourceInfoNamespace {
CLASS(ManifestResourceInfo) : public Object::in {
  public: Assembly get_ReferencedAssembly();
  public: String get_FileName();
  public: ResourceLocation get_ResourceLocation();
  public: void ctor(Assembly containingAssembly, String containingFileName, ResourceLocation resourceLocation);
  private: Assembly ReferencedAssembly;
  private: String FileName;
  private: ResourceLocation ResourceLocation;
};
} // namespace ManifestResourceInfoNamespace
using ManifestResourceInfo = ManifestResourceInfoNamespace::ManifestResourceInfo;
} // namespace System::Private::CoreLib::System::Reflection
