#pragma once

namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes {
enum class FUNCKIND {
  FUNC_VIRTUAL = 0,
  FUNC_PUREVIRTUAL = 1,
  FUNC_NONVIRTUAL = 2,
  FUNC_STATIC = 3,
  FUNC_DISPATCH = 4,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::ComTypes
