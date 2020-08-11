#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Diagnostics {
enum class DebuggerBrowsableState : int32_t {
  Never = 0,
  Collapsed = 2,
  RootHidden = 3,
};
} // namespace System::Private::CoreLib::System::Diagnostics
