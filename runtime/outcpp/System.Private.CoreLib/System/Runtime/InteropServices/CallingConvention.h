#pragma once

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CallingConvention {
  Winapi = 1,
  Cdecl = 2,
  StdCall = 3,
  ThisCall = 4,
  FastCall = 5,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
