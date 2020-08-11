#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection::Emit {
enum class OpCodeType : int32_t {
  Annotation = 0,
  Macro = 1,
  Nternal = 2,
  Objmodel = 3,
  Prefix = 4,
  Primitive = 5,
};
} // namespace System::Private::CoreLib::System::Reflection::Emit
