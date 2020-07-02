#pragma once

namespace System::Private::CoreLib::System::Reflection {
enum class MethodSemanticsAttributes {
  Setter = 1,
  Getter = 2,
  Other = 4,
  AddOn = 8,
  RemoveOn = 16,
  Fire = 32,
};
} // namespace System::Private::CoreLib::System::Reflection
