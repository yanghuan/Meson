#pragma once

namespace System::Private::CoreLib::System::Runtime::InteropServices {
enum class GCHandleType {
  Weak = 0,
  WeakTrackResurrection = 1,
  Normal = 2,
  Pinned = 3,
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices
