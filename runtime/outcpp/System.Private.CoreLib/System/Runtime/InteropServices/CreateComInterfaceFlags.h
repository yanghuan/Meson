#pragma once

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class CreateComInterfaceFlags {
  None = 0,
  CallerDefinedIUnknown = 1,
  TrackerSupport = 2,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
