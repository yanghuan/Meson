#pragma once

#include <cstdint>

namespace System::Private::CoreLib::System::Reflection {
enum class CustomAttributeEncoding : int32_t {
  Undefined = 0,
  Boolean = 2,
  Char = 3,
  SByte = 4,
  Byte = 5,
  Int16 = 6,
  UInt16 = 7,
  Int32 = 8,
  UInt32 = 9,
  Int64 = 10,
  UInt64 = 11,
  Float = 12,
  Double = 13,
  String = 14,
  Array = 29,
  Type = 80,
  Object = 81,
  Field = 83,
  Property = 84,
  Enum = 85,
};
} // namespace System::Private::CoreLib::System::Reflection
