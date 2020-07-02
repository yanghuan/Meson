#pragma once

namespace System::Private::CoreLib::System::Reflection {
enum class ResourceLocation {
  ContainedInAnotherAssembly = 2,
  ContainedInManifestFile = 4,
  Embedded = 1,
};
} // namespace System::Private::CoreLib::System::Reflection
