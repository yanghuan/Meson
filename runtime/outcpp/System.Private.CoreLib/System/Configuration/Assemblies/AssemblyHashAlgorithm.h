#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Configuration::Assemblies {
enum class AssemblyHashAlgorithm : int32_t {
  None = 0,
  MD5 = 32771,
  SHA1 = 32772,
  SHA256 = 32780,
  SHA384 = 32781,
  SHA512 = 32782,
};
} // namespace System::Private::CoreLib::System::Configuration::Assemblies
