#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection {
enum class ResourceLocation : int32_t {
  ContainedInAnotherAssembly = 2,
  ContainedInManifestFile = 4,
  Embedded = 1,
};
} // namespace System::Private::CoreLib::System::Reflection
