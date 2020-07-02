#pragma once

namespace System::Private::CoreLib::System::Diagnostics::Tracing {
enum class EventFieldFormat {
  Default = 0,
  String = 2,
  Boolean = 3,
  Hexadecimal = 4,
  Xml = 11,
  Json = 12,
  HResult = 15,
};
} // namespace System::Private::CoreLib::System::Diagnostics::Tracing
