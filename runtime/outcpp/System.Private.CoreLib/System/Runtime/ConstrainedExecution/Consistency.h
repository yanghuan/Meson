#pragma once

namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution {
enum class Consistency {
  MayCorruptProcess = 0,
  MayCorruptAppDomain = 1,
  MayCorruptInstance = 2,
  WillNotCorruptState = 3,
};
} // namespace System::Private::CoreLib::System::Runtime::ConstrainedExecution
