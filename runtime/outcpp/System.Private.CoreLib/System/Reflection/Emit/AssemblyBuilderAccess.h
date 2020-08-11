#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection::Emit {
enum class AssemblyBuilderAccess : int32_t {
  Run = 1,
  RunAndCollect = 9,
};
} // namespace System::Private::CoreLib::System::Reflection::Emit
