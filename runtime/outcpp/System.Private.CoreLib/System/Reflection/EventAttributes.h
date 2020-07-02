#pragma once

namespace System::Private::CoreLib::System::Reflection {
enum class EventAttributes {
  None = 0,
  SpecialName = 512,
  RTSpecialName = 1024,
  ReservedMask = 1024,
};
} // namespace System::Private::CoreLib::System::Reflection
