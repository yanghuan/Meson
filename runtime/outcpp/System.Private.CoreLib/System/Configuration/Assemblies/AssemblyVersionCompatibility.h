#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Configuration::Assemblies {
enum class AssemblyVersionCompatibility : int32_t {
  SameMachine = 1,
  SameProcess = 2,
  SameDomain = 3,
};
} // namespace System::Private::CoreLib::System::Configuration::Assemblies
