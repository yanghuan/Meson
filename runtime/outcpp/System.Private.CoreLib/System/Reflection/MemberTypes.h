#pragma once

namespace System::Private::CoreLib::System::Reflection {
enum class MemberTypes {
  Constructor = 1,
  Event = 2,
  Field = 4,
  Method = 8,
  Property = 16,
  TypeInfo = 32,
  Custom = 64,
  NestedType = 128,
  All = 191,
};
} // namespace System::Private::CoreLib::System::Reflection
