#pragma once

namespace System::Private::CoreLib::System::Configuration::Assemblies {
enum class AssemblyVersionCompatibility {
  SameMachine = 1,
  SameProcess = 2,
  SameDomain = 3,
};
} // namespace System::Private::CoreLib::System::Configuration::Assemblies
