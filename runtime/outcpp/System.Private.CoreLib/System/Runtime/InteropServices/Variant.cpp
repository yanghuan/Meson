#include "Variant-dep.h"

namespace System::Private::CoreLib::System::Runtime::InteropServices::VariantNamespace {
VarEnum Variant::get_VariantType() {
  return VarEnum::VT_BYREF;
};
Boolean Variant::get_IsEmpty() {
  return Boolean();
};
Boolean Variant::get_IsByRef() {
  return Boolean();
};
SByte Variant::get_AsI1() {
  return SByte();
};
Int16 Variant::get_AsI2() {
  return Int16();
};
Int32 Variant::get_AsI4() {
  return Int32();
};
Int64 Variant::get_AsI8() {
  return Int64();
};
Byte Variant::get_AsUi1() {
  return Byte();
};
UInt16 Variant::get_AsUi2() {
  return UInt16();
};
UInt32 Variant::get_AsUi4() {
  return UInt32();
};
UInt64 Variant::get_AsUi8() {
  return UInt64();
};
Int32 Variant::get_AsInt() {
  return Int32();
};
UInt32 Variant::get_AsUint() {
  return UInt32();
};
Boolean Variant::get_AsBool() {
  return Boolean();
};
Int32 Variant::get_AsError() {
  return Int32();
};
Single Variant::get_AsR4() {
  return Single();
};
Double Variant::get_AsR8() {
  return Double();
};
Decimal Variant::get_AsDecimal() {
  return Decimal();
};
Decimal Variant::get_AsCy() {
  return Decimal();
};
DateTime Variant::get_AsDate() {
  return DateTime();
};
String Variant::get_AsBstr() {
  return nullptr;
};
Object Variant::get_AsUnknown() {
  return nullptr;
};
Object Variant::get_AsDispatch() {
  return nullptr;
};
IntPtr Variant::get_AsByRefVariant() {
  return IntPtr();
};
void Variant::CopyFromIndirect(Object value) {
};
Object Variant::ToObject() {
  return nullptr;
};
} // namespace System::Private::CoreLib::System::Runtime::InteropServices::VariantNamespace
