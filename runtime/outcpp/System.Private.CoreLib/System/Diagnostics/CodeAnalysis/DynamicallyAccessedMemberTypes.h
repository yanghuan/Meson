#pragma once

namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis {
enum class DynamicallyAccessedMemberTypes {
  None = 0,
  DefaultConstructor = 1,
  PublicConstructors = 3,
  NonPublicConstructors = 4,
  PublicMethods = 8,
  NonPublicMethods = 16,
  PublicFields = 32,
  NonPublicFields = 64,
  PublicNestedTypes = 128,
  NonPublicNestedTypes = 256,
  PublicProperties = 512,
  NonPublicProperties = 1024,
  PublicEvents = 2048,
  NonPublicEvents = 4096,
  All = -1,
};
} // namespace System::Private::CoreLib::System::Diagnostics::CodeAnalysis
