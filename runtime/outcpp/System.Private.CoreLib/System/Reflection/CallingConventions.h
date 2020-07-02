#pragma once

namespace System::Private::CoreLib::System::Reflection {
enum class CallingConventions {
  Standard = 1,
  VarArgs = 2,
  Any = 3,
  HasThis = 32,
  ExplicitThis = 64,
};
} // namespace System::Private::CoreLib::System::Reflection
