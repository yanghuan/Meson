#pragma once

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class ComWrappersScenario {
  Instance = 0,
  TrackerSupportGlobalInstance = 1,
  MarshallingGlobalInstance = 2,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
