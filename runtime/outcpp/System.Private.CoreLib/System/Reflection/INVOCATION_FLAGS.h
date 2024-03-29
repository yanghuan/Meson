#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection {
enum class INVOCATION_FLAGS : uint32_t {
  INVOCATION_FLAGS_UNKNOWN = 0,
  INVOCATION_FLAGS_INITIALIZED = 1,
  INVOCATION_FLAGS_NO_INVOKE = 2,
  INVOCATION_FLAGS_RUN_CLASS_CONSTRUCTOR = 4,
  INVOCATION_FLAGS_NO_CTOR_INVOKE = 8,
  INVOCATION_FLAGS_IS_CTOR = 16,
  INVOCATION_FLAGS_IS_DELEGATE_CTOR = 128,
  INVOCATION_FLAGS_CONTAINS_STACK_POINTERS = 256,
  INVOCATION_FLAGS_SPECIAL_FIELD = 16,
  INVOCATION_FLAGS_FIELD_SPECIAL_CAST = 32,
  INVOCATION_FLAGS_CONSTRUCTOR_INVOKE = 268435456,
};
} // namespace System::Private::CoreLib::System::Reflection
