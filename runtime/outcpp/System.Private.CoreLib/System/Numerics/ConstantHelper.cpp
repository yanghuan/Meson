#include "ConstantHelper-dep.h"

namespace System::Private::CoreLib::System::Numerics::ConstantHelperNamespace {
Byte ConstantHelper::GetByteWithAllBitsSet() {
  Byte result = 0;
  result = Byte::MaxValue();
  return result;
}

SByte ConstantHelper::GetSByteWithAllBitsSet() {
  SByte result = 0;
  result = -1;
  return result;
}

UInt16 ConstantHelper::GetUInt16WithAllBitsSet() {
  UInt16 result = 0;
  result = UInt16::MaxValue();
  return result;
}

Int16 ConstantHelper::GetInt16WithAllBitsSet() {
  Int16 result = 0;
  result = -1;
  return result;
}

UInt32 ConstantHelper::GetUInt32WithAllBitsSet() {
  UInt32 result = 0u;
  result = UInt32::MaxValue();
  return result;
}

Int32 ConstantHelper::GetInt32WithAllBitsSet() {
  Int32 result = 0;
  result = -1;
  return result;
}

UInt64 ConstantHelper::GetUInt64WithAllBitsSet() {
  UInt64 result = 0;
  result = UInt64::MaxValue();
  return result;
}

Int64 ConstantHelper::GetInt64WithAllBitsSet() {
  Int64 result = 0;
  result = -1;
  return result;
}

Single ConstantHelper::GetSingleWithAllBitsSet() {
  Single result = 0;
  *(Int32*)(&result) = -1;
  return result;
}

Double ConstantHelper::GetDoubleWithAllBitsSet() {
  Double result = 0;
  *(Int64*)(&result) = -1;
  return result;
}

} // namespace System::Private::CoreLib::System::Numerics::ConstantHelperNamespace
