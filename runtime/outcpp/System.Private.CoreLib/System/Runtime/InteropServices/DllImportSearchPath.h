#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class DllImportSearchPath : int32_t {
  UseDllDirectoryForDependencies = 256,
  ApplicationDirectory = 512,
  UserDirectories = 1024,
  System32 = 2048,
  SafeDirectories = 4096,
  AssemblyDirectory = 2,
  LegacyBehavior = 0,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
