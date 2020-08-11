#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection {
enum class MethodSemanticsAttributes : int32_t {
  Setter = 1,
  Getter = 2,
  Other = 4,
  AddOn = 8,
  RemoveOn = 16,
  Fire = 32,
};
} // namespace System::Private::CoreLib::System::Reflection
