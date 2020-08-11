#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection {
enum class FieldAttributes : int32_t {
  FieldAccessMask = 7,
  PrivateScope = 0,
  Private = 1,
  FamANDAssem = 2,
  Assembly = 3,
  Family = 4,
  FamORAssem = 5,
  Public = 6,
  Static = 16,
  InitOnly = 32,
  Literal = 64,
  NotSerialized = 128,
  SpecialName = 512,
  PinvokeImpl = 8192,
  RTSpecialName = 1024,
  HasFieldMarshal = 4096,
  HasDefault = 32768,
  HasFieldRVA = 256,
  ReservedMask = 38144,
};
} // namespace System::Private::CoreLib::System::Reflection
