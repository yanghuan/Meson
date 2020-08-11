#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Text {
enum class NormalizationForm : int32_t {
  FormC = 1,
  FormD = 2,
  FormKC = 5,
  FormKD = 6,
};
} // namespace System::Private::CoreLib::System::Text
