#pragma once

namespace System::Private::CoreLib::System::Threading {
enum class ApartmentState {
  STA = 0,
  MTA = 1,
  Unknown = 2,
};
} // namespace System::Private::CoreLib::System::Threading
