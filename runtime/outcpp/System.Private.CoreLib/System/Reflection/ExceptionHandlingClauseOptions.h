#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection {
enum class ExceptionHandlingClauseOptions : int32_t {
  Clause = 0,
  Filter = 1,
  Finally = 2,
  Fault = 4,
};
} // namespace System::Private::CoreLib::System::Reflection
