#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::ComponentModel {
enum class EditorBrowsableState : int32_t {
  Always = 0,
  Never = 1,
  Advanced = 2,
};
} // namespace System::Private::CoreLib::System::ComponentModel
