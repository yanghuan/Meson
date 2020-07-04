#pragma once

namespace System::Private::CoreLib::System::Runtime::Versioning {
enum class ComponentGuaranteesOptions {
  None = 0,
  Exchange = 1,
  Stable = 2,
  SideBySide = 4,
};
} // namespace System::Private::CoreLib::System::Runtime::Versioning
