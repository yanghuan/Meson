#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection::Emit {
enum class TypeKind : int32_t {
  IsArray = 1,
  IsPointer = 2,
  IsByRef = 3,
};
} // namespace System::Private::CoreLib::System::Reflection::Emit
