#pragma once

namespace System::Private::CoreLib::System::Reflection {
enum class AssemblyNameFlags {
  None = 0,
  PublicKey = 1,
  EnableJITcompileOptimizer = 16384,
  EnableJITcompileTracking = 32768,
  Retargetable = 256,
};
} // namespace System::Private::CoreLib::System::Reflection
